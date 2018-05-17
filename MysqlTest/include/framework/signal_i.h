



#ifndef _SIGNAL_I_H
#define _SIGNAL_I_H

#include <data_types.h>
#include <signal.h>
#include <os/os_signal_i.h>
#define SIGMAX	64

//typedef void (*SignalHandler)(int,siginfo_t*,void*);
//typedef void (*SignalHandlerV)(int,siginfo_t*,void*);
class signalSet
{
public:
	signalSet(void);
	signalSet(sigset_t* sigset);
	~signalSet(void);
	int empty_set(void);
	int fill_set(void);
	int sig_add(int signum);
	int sig_del(int signum);
	int sig_ismember(int signum) const;
	void dump(void) const;
private:
	sigset_t *sigset_;
};

class sigAction
{
public:
	sigAction(void);
	~sigAction(void);
	t_int32 set(OS_sigaction* );
	OS_sigaction* get(void);			//  	这个可有可无
	t_int32 set_flags(t_ulong);
	t_int32 get_flags(t_ulong &);					//		这个可有可无
	t_int32 empty(void);
	t_int32 set_mask(sigset_t *);
	t_int32 get_mask(sigset_t*);				//		这个可有可无
	t_int32 set_handle(OS_SIGNAL::SignalHandler);
	t_int32 get_handle(OS_SIGNAL::SignalHandler);		//		这个可有可无

private:
	OS_sigaction *sa_;
};

t_int32 register_action(int signum, sigAction* act,sigAction* oldact );

t_int32 sigsend(int,int ,OS_sigval );

#endif


