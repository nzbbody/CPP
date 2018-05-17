#ifndef _OS_SIGNAL_I_H
#define _OS_SIGNAL_I_H

#include <data_types.h>
#include <signal.h>
#include <errno/error_i.h>

#ifdef WIN32
typedef t_uint32 sigset_t;
//typedef t_uint32 sigaction;
#endif

#ifdef WIN32
typedef t_uint32 OS_sigaction;
typedef t_uint32 OS_sigval;
#else
//#error "==================="
typedef struct sigaction OS_sigaction;
typedef union sigval OS_sigval;
#endif


namespace OS_SIGNAL {

#ifdef WIN32
	typedef void (__cdecl *SignalHandler)(int);
	typedef void (__cdecl *SignalHandlerV)(int);
#else 
	typedef void (*SignalHandler)(int,siginfo_t*,void*);
	typedef void (*SignalHandlerV)(int,siginfo_t*,void*);
#endif

#if 0 
#ifdef WIN32
	#ifndef _sigfillset(ptr)
	#define _sigfillset(ptr) (ptr = ~(sigset_t)0,0)


	
	#endif

#else
	//#error "xxxxxxxxxxxxxxxxxxxxx"
	#define _sigfillset(ptr) sigfillset(ptr)
	
#endif
#endif



int sigfillset(sigset_t *ptr);



int sigemptyset (sigset_t *s);


int sigaddset(sigset_t* s,int signum);

int sigdelset (sigset_t *s, int signum);

int sigismember (sigset_t *s, int signum);

int regsigaction (int signum, OS_sigaction *nsa,OS_sigaction *osa);

int sigsend (int pid, int sig,OS_sigval sigval);

void sigAction(OS_sigaction* tmp,SignalHandler handler, sigset_t* sigmask, int flags);

t_int32 set_flags(OS_sigaction *tmp,t_ulong flags);

t_int32 get_flags(OS_sigaction* tmp,t_ulong &flags);

};


#endif
