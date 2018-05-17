#include <Winsock2.h>
#include <stdio.h>
#include<string>
#include<cstring>
#include<windows.h>
#include<Winbase.h>
#include <fcntl.h>
#pragma comment(lib,"ws2_32")
 
struct CMD
{
    char cmdbuffer[50];
}cmd[20];
int i=0;
char buffer[10240]; //执行结果
char command[50];   //命令接收数组
void ShuJu()
{
    FILE   *pPipe;
 
        /* Run DIR so that it writes its output to a pipe. Open this
         * pipe with read text attribute so that we can read it 
         * like a text file. 
         */
 
   if( (pPipe = _popen(command, "rt" )) == NULL )
      exit( 1 );
 
   /* Read pipe until end of file, or an error occurs. */
    memset(buffer,0,10240);   
   char psBuffer[1000]=" ";
   while(fgets(psBuffer,1000, pPipe))
   {
      strcat(buffer,psBuffer);
      strcat(buffer,"\r");
   }
    printf(buffer);
   /* Close pipe and print return value of pPipe. */
   if (feof( pPipe))
   {
     printf( "\nProcess returned %d\n", _pclose( pPipe ) );
   }
   else
   {
     printf( "Error: Failed to read the pipe to the end.\n");
   }
}
 
/*主函数*/
void main()
{   
    /*创建套接字*/
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;   
    wVersionRequested = MAKEWORD(1,1);   
    err = WSAStartup(wVersionRequested,&wsaData);
    if (err != 0)
    {
        return;
    }
    if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) 
    {
        WSACleanup();
        return; 
    }
    SOCKET socSrv;
    socSrv = socket(AF_INET,SOCK_STREAM,0);   
    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(6000);
 
    bind(socSrv,(SOCKADDR*)&addrSrv,sizeof(addrSrv));   
    listen(socSrv,50);
    SOCKADDR_IN addrClient;
    int addrLen = sizeof(SOCKADDR_IN);
    SOCKET socClient = accept(socSrv,(SOCKADDR*)&addrClient,&addrLen);
 
    /*身份认证！！接收客户端申请，然后对客户端发送命令输入提示，打开客户端回显*/   
    char SS[10],S1[10],S2[10];
    recv(socClient,SS,10,0);
    char ZH[10]="zte";char MM[10]="123";
 
    do{   
        send(socClient,"请输入登录账号>",sizeof("请输入登录账号>"),0);
        char *r;
        r=S1;
        while(1)
        {           
            recv(socClient,r,sizeof(r),0);
            if(*r=='\r')break;
            if(*r=='\b')
            { char BS1[3];
                 BS1[0]=46;
                 BS1[1]=8;
                 BS1[2]='\0';
                 send(socClient,BS1,sizeof(BS1),0);
                 r--;
            }
            else r++;
        }
        *r='\0';    /*末尾补\0*/
        send(socClient,"请输入密码>",sizeof("请输入密码>"),0);   
        char *t;
        t=S2;
        while(1)
        {           
            recv(socClient,t,sizeof(t),0);
            char hx[4];
                 hx[0]=46;
                 hx[1]=8;
                 hx[2]=8;                 
                 hx[3]='*';                  
            send(socClient,hx,sizeof(hx),0);
            if(*t=='\r')
            {char hx1[1];hx1[0]=8;send(socClient,hx1,sizeof(hx1),0);break;}
            if(*t=='\b')
            { char BS2[3];
                 BS2[0]=8;
                 BS2[1]=46;
                 BS2[2]='\0';
                 send(socClient,BS2,sizeof(BS2),0);
                 t--;
            }
            else t++;
        }
        *t='\0';    /*末尾补\0*/
    }while(strcmp(ZH,S1)!=0||strcmp(MM,S2)!=0);
    send(socClient,"身份验证通过！",sizeof("身份验证通过！"),0);
 
     
    /*程序主体，实现远程操作及维护*/
    send(socClient,"\r\n请输入命令>",sizeof("\r\n请输入命令>"),0);
 
 
    while(1)
    {   
        memset(command,0,50);
        strcpy(command,"Cmd.exe /C ");   
        char fx[50];memset(fx,0,50);
        char recvbuf[50]=" ";
        char *p;
        p=recvbuf;
   
            recv(socClient,fx,sizeof(fx),0);
            if(fx[0]==27&&fx[1]==91)
            {   
                switch(fx[2])
                {
                    case 65:   
                        i--;
                        printf("数组fx为：%s",fx);
                        send(socClient,cmd[i].cmdbuffer,sizeof(cmd[i].cmdbuffer),0);
                        strcat(command,cmd[i].cmdbuffer);                       
                        break;
                    case 66:
                        i++;
                        send(socClient,cmd[i].cmdbuffer,sizeof(cmd[i].cmdbuffer),0);
                        strcat(command,cmd[i].cmdbuffer);
                        break;
                    case 67:
                        printf("数组fx为：%s",fx);
                        send(socClient,"判断出是向右键！\r\n继续输入命令>",sizeof("判断出是向右键！\r\n继续输入命令>"),0);
                        break;
                    case 68:
                        printf("数组fx为：%s",fx);
                        send(socClient,"判断出是向左键！\r\n继续输入命令>",sizeof("判断出是向左键！\r\n继续输入命令>"),0);
                        break;
                }
                send(socClient,"\r\n",sizeof("\r\n"),0);
                Sleep(1000);       
                ShuJu();
                printf("打印command:%s",command);
                send(socClient,buffer,sizeof(buffer),0);
                send(socClient,"指令执行完毕！\r\n请继续输入命令>",sizeof("指令执行完毕！\r\n请继续输入命令>"),0);
                continue;
            }   
            recvbuf[0]=fx[0];
            p++;
        /*接收客户端发来的命令*/
        while(1)
        {
            recv(socClient,p,sizeof(p),0);           
            if(*p=='\r')break;
            else if(*p=='\b')
            { char BS[3];
                 BS[0]=46;
                 BS[1]=8;
                 BS[2]='\0';                
              send(socClient,BS,sizeof(BS),0);
                 p--;
            }
            else p++;
            int STRLEN=strlen(recvbuf);
            printf("数组buf为：%s;数组长度为：%d.\n",recvbuf,STRLEN);
        }
        *p='\0';         /*末尾补'\0'，命令接受完毕！*/           
         
        /*对命令解析，执行并返回结果*/
        /*调用windows的API函数执行一些Dos操作*/
         
         
        /*help命令*/
        if(strcmp(recvbuf,"?")==0||strcmp(recvbuf,"help")==0)
        {
            strcat(command,recvbuf);
            ShuJu();printf("打印command:%s",command);   
            send(socClient,buffer,sizeof(buffer),0);
            send(socClient,"指令执行完毕！\r\n请继续输入命令>",sizeof("指令执行完毕！\r\n请继续输入命令>"),0);
        }
        /*ipconfig命令*/
        else if(strcmp(recvbuf,"ipconfig")==0)
        {   
            strcat(command,recvbuf);
            ShuJu();printf("打印command:%s",command);
            send(socClient,buffer,sizeof(buffer),0);
            send(socClient,"指令执行完毕！\r\n请继续输入命令>",sizeof("指令执行完毕！\r\n请继续输入命令>"),0);
        }
        /*ipconfig /all命令*/
        else if(strcmp(recvbuf,"ipconfig /all")==0)
        {   
            strcat(command,recvbuf);
            ShuJu();
            printf("打印command:%s",command);
            send(socClient,buffer,sizeof(buffer),0);
        send(socClient,"指令执行完毕！\r\n请继续输入命令>",sizeof("指令执行完毕！\r\n请继续输入命令>"),0);
        }
        /*cd ..命令*/
        else if(strcmp(recvbuf,"cd ..")==0)
        {   
            strcat(command,recvbuf);
            send(socClient,buffer,sizeof(buffer),0);
            send(socClient,"指令执行完毕！\r\n请继续输入命令>",sizeof("指令执行完毕！\r\n请继续输入命令>"),0);
             
        }
        /*telnet命令*/
        else if(strcmp(recvbuf,"telnet")==0)
        {   
            strcat(command,recvbuf);
            ShuJu();
            printf("打印command:%s",command);
            send(socClient,buffer,sizeof(buffer),0);
            send(socClient,"指令执行完毕！\r\n请继续输入命令>",sizeof("指令执行完毕！\r\n请继续输入命令>"),0);
        }
        /*ver命令*/
        else if(strcmp(recvbuf,"ver")==0)
        {   
            strcat(command,recvbuf);
            ShuJu();
            printf("打印command:%s",command);
            send(socClient,buffer,sizeof(buffer),0);
        send(socClient,"指令执行完毕！\r\n请继续输入命令>",sizeof("指令执行完毕！\r\n请继续输入命令>"),0);
        }
        /*dir命令*/
        else if(strcmp(recvbuf,"dir")==0)
        {   
            strcat(command,recvbuf);
            ShuJu();
            printf("打印command:%s",command);
            send(socClient,buffer,sizeof(buffer),0);
        send(socClient,"指令执行完毕！\r\n请继续输入命令>",sizeof("指令执行完毕！\r\n请继续输入命令>"),0);
        }
        /*quit命令*/
        else if(strcmp(recvbuf,"quit")==0)
        {   
            strcat(command,recvbuf);
            ShuJu();
            printf("打印command:%s",command);
            send(socClient,buffer,sizeof(buffer),0);
        send(socClient,"指令执行完毕！\r\n请继续输入命令>",sizeof("指令执行完毕！\r\n请继续输入命令>"),0);
        }
        /*date命令*/
        else if(strcmp(recvbuf,"date")==0)
        {   
            strcat(command,recvbuf);
            ShuJu();
            printf("打印command:%s",command);
            send(socClient,buffer,sizeof(buffer),0);
        send(socClient,"指令执行完毕！\r\n请继续输入命令>",sizeof("指令执行完毕！\r\n请继续输入命令>"),0);
        }
        /*mem命令*/
        else if(strcmp(recvbuf,"mem")==0)
        {   
            strcat(command,recvbuf);
            ShuJu();
            printf("打印command:%s",command);
            send(socClient,buffer,sizeof(buffer),0);
			send(socClient,"指令执行完毕！\r\n请继续输入命令>",sizeof("指令执行完毕！\r\n请继续输入命令>"),0);
        }
        /*exit命令*/
        else if(strcmp(recvbuf,"exit")==0)
        {   
            strcat(command,recvbuf);
            ShuJu();
            printf("打印command:%s",command);
            send(socClient,buffer,sizeof(buffer),0);
            send(socClient,"指令执行完毕！\r\n请继续输入命令>",sizeof("指令执行完毕！\r\n请继续输入命令>"),0);
        }
        else 
		{
			send(socClient,"指令错误，请重新输入>",sizeof("指令错误，请重新输入>")+1,0);
		}
        if(i==20)i=0;
        memset(cmd[i].cmdbuffer,0,50);
        strcpy(cmd[i].cmdbuffer,recvbuf);
        i++;   
    }
    closesocket(socClient);
    closesocket(socSrv);
    WSACleanup();
}
/*程序结束*/