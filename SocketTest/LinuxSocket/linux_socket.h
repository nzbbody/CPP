/*
* 文件功能： linux 下套接字简化操作函数
* 文件名称： linux_socket.h
* 建立时间： 2007 年 07 月 19 号
* 创建作者： wlzqi
* 使用语言： C 或 C++ 语言
* 使用环境： Linux + Windows
* 函数要求： 
*    + 函数相对比较底层
*    + 只使用系统ＡＰＩ和Ｃ库，不能使用任何第三方库
*    + 不可以用全局变量
*    + 使用比较频繁
*    + 具有模块化（函数不要嵌套）
*    +   要有足够强壮性和高效
*    +   要经过一定强度的本地测试
*    + 尽量不使用动态分配内存（特殊情况可慎重添加）
*    + 所有变量必须字节对齐
* 代码要求：
*    + 尽量减少临时变量
*    + 算法要精炼
*    + 临时变量名要使用英文或英文缩写或英文词组单词首字母，并且英文要准确（不要超过１２个字母）
*    + 函数名要求将函数功能描述清楚，单词之间要用 _ 连接。例如：analyze_string 分解字符串、
*    　execute_sql 执行ＳＱＬ语句、get_database_field_name 得到数据库字段名称.....等
*    + 所有函数均使用小写字母拼写
*    + 符号 ,和; 后要有一空格、符号 & * 要紧挨右边的变量、符号++ 要紧挨左边的变量、所有运算符
*     两边都要留有空格
*    + if 和 for 、where 等要和紧挨的 '(' 符号间留有一空格
*    + 合理运用空行使代码清晰易读
* 注释风格：
*    + 注释要得当风格要统一
*    + 注释只能在代码之上
*    + 如果注释和代码同行，则要求必须空出两个 Tab 键
*    + 注释内容和注释符之间要有一空格
*    + 如果注释要分行写则要求具有以下样子

	  *    + 函数功能注释必须有：函数说明、参数说明、返回说明、注意事项、使用举例
	  * 注意事项：
	  *    + 如遇本文件中的函数与系统函数功能相同时，因优先考虑使用本文件中的函数
	  *    + '必须'保证编译时不出现警告信息
	  *   + 缺省情况下，给一个已经断开连接（非法断开）的地址发送数据程序会退出，所以建议不要使用默认的
	  *    缺省设置。建议应用根据需要处理 SIGPIPE 信号，至少不要用系统缺省的处理方式处理这个信号
	  *    ，系统缺省的处理方式是退出进程，这样你的应用就很难查处处理进程为什么退出。
	  *    如果调用 signal(SIGPIPE, SIG_IGN); 那么程序在对方已断开的情况下发送数据就会返回 -1，errno 号为 EPIPE(32)
	  *    如果调用 signal(SIGPIPE, function_name); 那么程序在对方已断开的情况下发送数据首先会 SIGPIPE 响应函数，然后返回 -1，errno 号为 EPIPE(32)
	  *    如果在发送数据中对方断开，那么发送端会先返回已发送的数据字节数，在下次再调用发送时返回 -1，errno 号为 ECONNRESET(104) 
	  *    建议使用 signal 处理信号，避免进程莫名退出和描述符泄露和死连接
	  * 已加模块：
	  *    + socket_format_err   格式化 socket 错误信息
	  *   + socket_format_herr 自定义格式化 socket 错误信息
	  *    + socket_create     创建 Socket
	  *    + socket_connect    连接 Socket
	  *   + socket_bind      邦定本地端口
	  *   + socket_listen     监听本地端口描述符
	  *   + socket_accept     接受 Socket 连线
	  *    + socket_send      发送数据包
	  *    + socket_recv      接收数据包
	  *    + socket_send_pack   打包发送数据包
	  *    + socket_recv_pack   接收打包的数据包
	  *    + close_socket     关闭套接字
	  * */

#ifndef LINUX_SOCKET_H_
#define LINUX_SOCKET_H_


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
	  /*---------------------------------------------------------------------------*/
	  /*---------------------------------------------------------------------------*/

	  /* 定义 SOCKET 变量 */
	  typedef int SOCKET;

#ifndef boolean
#define boolean
	  /* 定义布尔型变量 */
#endif

#ifndef FALSE
#define FALSE   (0) 
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

	  /* 定义布尔型变量 */
#ifndef BOOLLEAN
#define BOOLLEAN
	  typedef int BOOL;
#endif

	  /* 定义NULL字符 */
#ifndef NULL
#define NULL 0
#endif

	  /*---------------------------------------------------------------------------*/
	  /* 函数功能： 格式化 socket 错误信息
	  * 参数说明： 无
	  * 返回说明： 返回错误描述信息文本
	  * 注意事项： 
	  * 使用举例：

	  * */
	  char * socket_format_err()
	  {
		  return (char *)hstrerror(h_errno);
	  }

	  /*---------------------------------------------------------------------------*/
	  /* 函数功能： 自定义格式化 socket 错误信息
	  * 参数说明： pszErr 要在系统错误信息描述前添加的自己的文字
	  * 返回说明： 无
	  * 注意事项： 
	  * 使用举例： socket_format_herr("Warning");
	  *     输出 Warning: xxxx.....

	  * */
	  void socket_format_herr(const char * pszErr)
	  {
		  herror(pszErr);
	  }
	  /*---------------------------------------------------------------------------*/
	  /* 函数功能： 创建 Socket
	  * 参数说明： nTimeR   接收超时（秒），0表示不受限
	  *       nTimeS   发送超时（秒），0表示不受限
	  * 返回说明： 返回-1表示失败。否则返回被创建的socket
	  * 注意事项： 函数内使用了端口重新绑定
	  * 使用举例： 1． socket_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, 10, 10) TCP
	  *       2． socket_create(AF_INET, SOCK_DGRAM, IPPROTO_IP, 0, 0)     UDP 
	  * */
	  SOCKET socket_create(const int nAf, const int nType, const int nProtocol, const int nTimeS, const int nTimeR)
	  {
		  static SOCKET m_sock;

#ifndef WIN32
		  struct timeval tv;
#endif

		  m_sock = -1;
		  m_sock = socket(nAf, nType, nProtocol);
		  if (m_sock == -1) return -1;


#ifdef WIN32

		  nTimeS *= 1000;
		  nTimeR *= 1000;
		  /* 发送时限 */
		  if (setsockopt(m_sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&nTimeS, sizeof(int)) < 0)
			  return -1;
		  /* 接收时限 */
		  if (setsockopt(m_sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&nTimeR, sizeof(int)) < 0)
			  return -1;
#else
		  tv.tv_usec = 0;
		  tv.tv_sec = nTimeS;
		  /* 发送时限 */
		  if (setsockopt(m_sock, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv)) < 0)
			  return -1;
		  tv.tv_sec = nTimeR;
		  /* 接收时限 */
		  if (setsockopt(m_sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0)
			  return -1;
#endif

		  return m_sock;
	  }
	  /*---------------------------------------------------------------------------*/
	  /* 函数功能： 连接 Socket
	  * 参数说明： socket   套接字
	  *        pcszIp   IP
	  *        nPort    端口
	  * 返回说明： 返回 false 表示失败。
	  * 注意事项： 
	  * 使用举例： 1． SOCKET socke;
	  *      if ((socke = socket_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0)) == -1) {
	  *  
	  *       return false;
	  *      }
	  *      if (socket_connect(socke, "192.168.12.111", 9000) == false) return false;
	  * */
	  bool socket_connect(const SOCKET socket, const char * pcszIp, const unsigned nPort)
	  {
		  struct sockaddr_in svraddr;

		  svraddr.sin_family = AF_INET;
		  svraddr.sin_addr.s_addr = inet_addr(pcszIp);
		  svraddr.sin_port = htons(nPort);
		  if (connect(socket, (struct sockaddr *)&svraddr, sizeof(svraddr)) == -1) return false;
		  return true;
	  }
	  /*---------------------------------------------------------------------------*/
	  /* 函数功能：邦定本地端口到描述符
	  * 参数说明：nPort 需要邦定的本地端口
	  * 返回说明：返回 false 表示失败。
	  * 注意事项：
	  * 使用举例：
	  *     if ((socke = socket_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0)) == -1) {
	  *  
	  *       return false;
	  *      }
	  *     if (socket_bind(socke, 9000) == false) return false;
	  * */
	  bool socket_bind(const SOCKET socket, const unsigned nPort)
	  {
		  int nOpt = 1;
		  struct sockaddr_in svraddr;

		  svraddr.sin_family = AF_INET;
		  svraddr.sin_addr.s_addr = INADDR_ANY;
		  svraddr.sin_port = htons(nPort);

		  if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char*)&nOpt, sizeof(nOpt)) < 0) return false;
		  if (bind(socket, (struct sockaddr*)&svraddr, sizeof(svraddr)) == -1) return false;

		  return true;
	  }
	  /*---------------------------------------------------------------------------*/
	  /* 函数功能：监听本地端口描述符
	  * 参数说明：nBacklog 设置请求排队的最大长度，常用量为 5
	  * 返回说明：返回 false 表示失败。
	  * 注意事项：
	  * 使用举例：
	  *     if ((socke = socket_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0)) == -1) {
	  *  
	  *       return false;
	  *      }
	  *     if (socket_bind(socke, 9000) == false) return false;
	  *     if (socket_listen(socke, 5) == false) return false;
	  * */
	  bool socket_listen(const SOCKET socket, const int nBacklog)
	  {
		  if (listen(socket, nBacklog) == -1) return false;
		  return true;
	  }
	  /*---------------------------------------------------------------------------*/
	  /* 函数功能：接受 Socket 连线 
	  * 参数说明：pszCliIp [OUT] 对方IP地址
	  * 返回说明：成功返回客户 socket 描述符，否则返回 -1。
	  * 注意事项：
	  * 使用举例：
	  *     SOCKET m_sock;
	  *     char szCliIP[16];
	  *     if ((socke = socket_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0)) == -1) {
	  *  
	  *       return false;
	  *      }
	  *     if (socket_bind(socke, 9000) == false) return false;
	  *     if (socket_listen(socke, 5) == false) return false;
	  *     memset(szCliIP, 0, 16);
	  *     m_sock = socket_accept(socke, szCliIP);
	  * */
	  SOCKET socket_accept(const SOCKET socket, char * pszCliIp)
	  {
		  static SOCKET m_sock;
		  struct sockaddr_in cliaddr;

		  socklen_t addrlen = sizeof(cliaddr);
		  m_sock = accept(socket, (struct sockaddr*)&cliaddr, &addrlen);
		  if (m_sock == -1) return -1;

		  if (pszCliIp != NULL) sprintf(pszCliIp, "%s", inet_ntoa(cliaddr.sin_addr));
		  return m_sock;
	  }
	  /*---------------------------------------------------------------------------*/
	  /* 函数功能： 发送 Socket 包
	  * 参数说明： socket   套接字
	  *        pszBuff   待发送缓冲区
	  *        nLen   待发送包长度
	  * 返回说明： 返回-1表示失败。否则返回实际已发送的字节数
	  * 注意事项： nFlags一般取 0
	  * 使用举例： 1． SOCKET socke;
	  *      char szBuff[512];
	  *      memset(szBuff, 0, 512);
	  *
	  *      if ((socke = socket_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0)) == -1) {
	  *  
	  *       return false;
	  *      }
	  *      if (socket_connect(socke, "192.168.12.111", 9000) == false) return false;
	  *      // 拷贝待发送字节到缓冲区
	  *      socket_send(socke, szBuff, strlen(szBuff), 0);
	  * */
	  int socket_send(const SOCKET socket, const char * pszBuff, const int nLen, const int nFlags)
	  {
		  int nBytes = 0;
		  int nCount = 0;

		  while (nCount < nLen) {

			  nBytes = send(socket, pszBuff + nCount, nLen - nCount, nFlags);
			  if (nBytes <= 0) {

				  return -1;
			  }
			  nCount += nBytes;
		  }

		  return nCount;
	  }
	  /*---------------------------------------------------------------------------*/
	  /* 函数功能： 接收 Socket 包
	  * 参数说明： socket   套接字
	  *     pszBuff   待接收缓冲区
	  *     nLen   待接收包长度
	  * 返回说明： 返回-1表示失败。否则返回实际接收的字节数
	  * 注意事项： nFlags一般取 0
	  * 使用举例： 1． SOCKET socke;
	  *      char szBuff[512];
	  *      memset(szBuff, 0, 512);

	  *      if ((socke = socket_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, 10)) == -1) {
	  *  
	  *       return false;
	  *      }
	  *      if (socket_connect(socke, "192.168.12.111", 9000) == false) return false;
	  *      // 拷贝待发送字节到缓冲区
	  *      socket_send(socke, szBuff, strlen(szBuff), 0);
	  *      socket_recv(socke, szBuff, strlen(szBuff), 0);
	  * */
	  int socket_recv(const SOCKET socket, char * pszBuff, const int nLen, const int nFlags)
	  {
		  return recv(socket, pszBuff, nLen, nFlags);
	  }
	  /*---------------------------------------------------------------------------*/
	  /* 函数功能： 打包发送 Socket 包
	  * 参数说明： socket   套接字
	  *     pszBuff   待发送缓冲区
	  *     nLength_all 待发送包总长度
	  *     unPack_Size 一次发送的字节数
	  * 返回说明： 返回-1表示失败。否则返回实际发送的字节数
	  * 注意事项： 
	  * 使用举例： 1． SOCKET socke;
	  *      char szBuff[512];
	  *      memset(szBuff, 0, 512);

	  *      if ((socke = socket_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, 10)) == -1) {
	  *  
	  *       return false;
	  *      }
	  *      if (socket_connect(socke, "192.168.12.111", 9000) == false) return false;
	  *      // 拷贝待发送字节到缓冲区
	  *      socket_send_pack(socke, szBuff, strlen(szBuff), 512);
	  * */
	  unsigned long socket_send_pack(const SOCKET socket, const char * pszBuff, const unsigned long nLength_all, const unsigned unPack_Size)
	  {
		  int nLength = 0;
		  long nAddLengths = 0;

		  while(nAddLengths < nLength_all) {

			  if ((nLength = socket_send(socket, pszBuff + nAddLengths, unPack_Size, 0)) < 0) {

				  break;
			  }
			  nAddLengths += nLength;
		  }
		  return nAddLengths;
	  }
	  /*---------------------------------------------------------------------------*/
	  /* 函数功能： 接收打包 Socket 包
	  * 参数说明： socket   套接字
	  *     pszBuff   待接收缓冲区
	  *     nLength_all 待接收包总长度
	  *     unPack_Size 一次接收的字节数
	  * 返回说明： 返回-1表示失败。否则返回实际接收的字节数
	  * 注意事项： 
	  * 使用举例： 1． SOCKET socke;
	  *      char szBuff[512];
	  *      memset(szBuff, 0, 512);

	  *      if ((socke = socket_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, 10)) == -1) {
	  *  
	  *       return false;
	  *      }
	  *      if (socket_connect(socke, "192.168.12.111", 9000) == false) return false;
	  *      // 拷贝待发送字节到缓冲区
	  *      socket_send_pack(socke, szBuff, strlen(szBuff), 512);
	  *      socket_recv_pack(socke, szBuff, 2048, 512);
	  * */
	  int socket_recv_pack(const SOCKET socket, char *pszBuff, const unsigned long nLength_all, const unsigned unPack_Size)
	  {

		  int nLength = 0;
		  unsigned long nAddLengths;
		  nAddLengths = 0;

		  while (nAddLengths < nLength_all) {

			  if ((nLength = socket_recv(socket, pszBuff + nAddLengths, unPack_Size, 0)) < 0) {

				  break;
			  }
			  nAddLengths += nLength;
		  }
		  return nAddLengths;
	  }
	  /*---------------------------------------------------------------------------*/
	  /* 函数功能： 关闭 Socket
	  * 参数说明： socket   套接字
	  * 返回说明： 返回false表示失败。否则返回实际接收的字节数
	  * 注意事项： 
	  * 使用举例： 1． SOCKET socke;
	  *      char szBuff[512];
	  *      memset(szBuff, 0, 512);
	  * 
	  *      if ((socke = socket_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, 10)) == -1) {
	  *  
	  *       return false;
	  *      }
	  *      if (socket_connect(socke, "192.168.12.111", 9000) == false) return false;
	  *      // 拷贝待发送字节到缓冲区
	  *      socket_send_pack(socke, szBuff, strlen(szBuff), 512);
	  *      socket_recv_pack(socke, szBuff, 2048, 512);
	  *      socket_close(socke);
	  * */
	  bool socket_close(const SOCKET socket)
	  {
		  return close(socket) == 0 ? true : false;
	  }
	  /*---------------------------------------------------------------------------*/
	  /*---------------------------------------------------------------------------*/

#endif /*LINUX_SOCKET_H_*/
