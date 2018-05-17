/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */


#ifndef _COMMON_INC_H
#define _COMMON_INC_H


#ifdef WIN32
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN
#include <sys/locking.h>
#include <process.h>
#include <hash_map>
#include <time.h>

#else
#include <sys/socket.h>
#include <signal.h>
#include <sys/resource.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <termios.h>
#include <netinet/tcp.h>
#include <netinet/ip_icmp.h>
#include <linux/sockios.h>
#include <net/if_arp.h>
#include <net/if.h>
#include <net/route.h>
#include <linux/if_ether.h>
#include <netinet/ip.h>
#include <linux/udp.h>
#include <linux/if_packet.h>
#include <sys/ioctl.h>
#include <signal.h> /*! signal set */
#include <sys/time.h> /*! itimerval */
#include <sys/vfs.h>
#include <mntent.h>
#include <sys/mount.h>
#include <execinfo.h>
#include <sys/time.h>
#include <dirent.h>
#endif


#include <sys/types.h>



#include <fcntl.h>

#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <malloc.h>


#include <fcntl.h>
#include <string.h>

#include <sys/stat.h>
#include <vector>
#ifndef WIN32
	#define _tmain main
#else
	#define snprintf	_snprintf
#endif

//#ifdef WIN32
//#ifdef _DEBUG
//#include <vld.h>
//#endif
//#endif

#endif

