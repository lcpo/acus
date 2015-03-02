#include "libs.h"

#ifdef __i386__
asm(
"sysrun:\n" 
"pushl %ebp\n" 
"pushl %edi\n" 
"pushl %esi\n" 
"pushl %ebx\n"
"mov  (0+5)*4(%esp),%eax\n"
"mov  (1+5)*4(%esp),%ebx\n"
"mov  (2+5)*4(%esp),%ecx\n"
"mov  (3+5)*4(%esp),%edx\n"
"mov  (4+5)*4(%esp),%esi\n"
"mov  (5+5)*4(%esp),%edi\n"
"mov  (6+5)*4(%esp),%ebp\n"
"int $0x80\n"
"popl %ebx\n"
"popl %esi\n" 
"popl %edi\n" 
"popl %ebp\n" 
"ret"
);
#endif
///------------------------------------------------------------
#ifdef __x86_64__
asm(
"sysrun:\n" 
"movq %rdi,%rax\n"
"movq %rsi,%rdi\n"
"movq %rdx,%rsi\n"
"movq %rcx,%rdx\n"
"movq %r8,%r10\n"
"movq %r9,%r8\n"
"movq 8(%rsp),%r9\n"
"call\n" 
"ret\n" 
);
#endif

inline long sysrun(long ns, long a, long b, long c, long d, long e, long f, long g);

///------------------------------------------------------------
sys_t libs(sys_t sys){
//!------------------------------------------------------------
#ifndef __NO_LIBS_CALL
long call(long ns, ...){
	void* atr;
	long  a,b,c,d,e,f,g;
	va_start(atr, ns);
	a=(long)va_arg(atr, long);
	b=(long)va_arg(atr, long);
	c=(long)va_arg(atr, long);
	d=(long)va_arg(atr, long);
	e=(long)va_arg(atr, long);
	f=(long)va_arg(atr, long);
	g=(long)va_arg(atr, long);
	va_end(atr);
	return (long)(sysrun(ns,a,b,c,d,e,f,g));
}
sys.call=call;
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_OPEN
int open(char * filename, int flags, int mode) {return call(__NR_open,filename,flags,mode);}
sys.open=open;
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_CLOSE
int close(int fd) {return call(__NR_close,fd);}
sys.close=close;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_STAT
int stat(char * filename, struct stat_f *buf) {return call(__NR_stat,filename,buf);}
sys.stat=stat;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_FSTAT
int fstat(int fd, stat_f *buf) {return call(__NR_fstat,fd,buf);}
sys.fstat=fstat;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_LSTAT
int lstat(char * filename, struct stat_f *buf) {return call(__NR_lstat,filename,buf);}
sys.lstat=lstat;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_BRK
int brk(void* brkv) {return call(__NR_brk,brkv);}
sys.brk=brk;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_EXIT
int exit(int error_code){return call(__NR_exit,error_code); }
sys.exit=exit;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_GETPID
int getpid(void){return call(__NR_getpid);}
sys.getpid=getpid;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_FORK
int fork(void){return call(__NR_fork);}
sys.fork=fork;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_VFORK
int vfork(void){return call(__NR_vfork);}
sys.vfork=vfork;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_READ
int read(int fd, char * buf, int count) {return call(__NR_read,fd,buf,count);}
sys.read=read;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_LSEEK
int lseek (int fd, int offset, int against){return call(__NR_lseek,fd,offset,against);}
sys.lseek=lseek;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_KILL
int kill(int pid, int sig){return call(__NR_kill,pid,sig);}
sys.kill=kill;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_DUP2
int dup2(int oldfd, uni newfd){return call(__NR_dup2,oldfd,newfd);}
sys.dup2=dup2;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_DUP
int dup(int oldfd){return call(__NR_dup,oldfd);}
sys.dup=dup;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_ALARM
int alarm(int seconds){return call(__NR_alarm,seconds);}
sys.alarm=alarm;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_PIPE
int pipe(int* filedes){return call(__NR_pipe,filedes);}
sys.pipe=pipe;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_TIME
long time(long tloc){return call(__NR_time,tloc);}
sys.time=time; 
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_UNLINK
int unlink(char* filename){return call(__NR_unlink,filename);}
sys.unlink=unlink;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_NANOSLEEP
int nanosleep(int rqtp, int rmtp){return call(__NR_nanosleep,rqtp,rmtp);}
sys.nanosleep=nanosleep;
#endif

//!------------------------------------------------------------
#ifndef __NO_LIBS_READLINK
int readlink(char* path, char * buf, int bufsize){return call(__NR_readlink,path,buf,bufsize);}
sys.readlink=readlink;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_IOCTL
int ioctl(unsigned int fd, unsigned int cmd, void* arg){return call(__NR_ioctl,fd,cmd,arg);}
sys.ioctl=ioctl;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_SOCKET
int socket(int domain, int type, int protocol){return socketcall(socket,domain, type, protocol, 0, 0, 0);}
sys.socket=socket;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_BIND
int bind(int fd, const struct sockaddr *addr, unsigned int len){return socketcall(bind, fd, addr, len, 0, 0, 0);}
sys.bind=bind;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_ACCEPT
int accept(int fd, struct sockaddr *addr, unsigned int *len){int ret=-1;ret = socketcall(accept, fd, addr, len, 0, 0, 0);return ret;}
sys.accept=accept;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_CONNECT
int connect(int fd, const struct sockaddr *addr, unsigned int len){int ret=-1;ret = socketcall(connect, fd, addr, len, 0, 0, 0);	return ret;}
sys.connect=connect;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_LISTEN
int listen(int fd, int backlog){return socketcall(listen, fd, backlog, 0, 0, 0, 0);}
sys.listen=listen;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_GETSOCKNAME
int getsockname(int fd, struct sockaddr *addr, unsigned int *len){	return socketcall(getsockname, fd, addr, len, 0, 0, 0);}
sys.getsockname=getsockname;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_SETSOCKOPT
int setsockopt(int fd, int level, int optname, void *optval, unsigned int optlen){return socketcall(setsockopt, fd, level, optname, optval, optlen, 0);}
sys.setsockopt=setsockopt;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_GETSOCKOPT
int getsockopt(int fd, int level, int optname, void *optval, unsigned int *optlen){return socketcall(getsockopt, fd, level, optname, optval, optlen, 0);}
sys.getsockopt=getsockopt;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_SENDTO
int sendto(int fd, const void *buf, size_t len, int flags, const struct sockaddr *addr, unsigned int alen){return socketcall(sendto, fd, buf, len, flags, addr, alen);}
sys.sendto=sendto;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_SEND
int send(int fd, const void *buf, size_t len, int flags){return sendto(fd, buf, len, flags, 0, 0);}
sys.send=send;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_RECVFROM
int recvfrom(int fd, void *buf, int len, int flags, struct sockaddr *addr, unsigned int *alen){return socketcall(recvfrom, fd, buf, len, flags, addr, alen);}
sys.recvfrom=recvfrom;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_RECV
int recv(int fd, void *buf, int len, int flags){return recvfrom(fd, buf, len, flags, 0, 0);}
sys.recv=recv;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_VMSPLICE
long vmsplice(int fd, iovec *iov, unsigned long nr_segs, unsigned int flags){
	//vmsplice - splice user pages into a pipe
	long r=-1;
	r = call(__NR_vmsplice, fd, iov, nr_segs, flags);
	return r;
	}
sys.vmsplice=vmsplice;
#endif


//!------------------------------------------------------------	
#ifndef __NO_LIBS_TEE
long tee(int fd_in, int fd_out, size_t len, unsigned int flags){	
//tee - duplicating pipe content
int r=-1;
	r = call(__NR_tee,fd_in,fd_out,len,flags);
	return r;
}
sys.tee=tee;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_SPLICE
long splice(int fd_in, long *off_in, int fd_out,long *off_out, size_t len, unsigned int flags){ 
	//splice data to/from a pipe
	return call(__NR_splice, fd_in, off_in, fd_out, off_out, len, flags);	
	}
sys.splice=splice;
#endif	


//!------------------------------------------------------------
#ifndef __NO_LIBS_SENDFILE
int sendfile(int out_fd, int in_fd, long *offset, size_t count){ //file to socket
//sendfile - производит обмен данными между описателями файлов  
int r=-1;
	r = call(__NR_sendfile,out_fd,in_fd,offset,count);
	return r;
}
sys.sendfile=sendfile;
#endif	

//!------------------------------------------------------------
#ifndef __NO_LIBS_WAITPID
int waitpid(int pid, int *status, int options){
	int r=-1;
	r = call(__NR_wait4, pid, status, options, 0);
	return r;
}
sys.waitpid=waitpid;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_WAITID
int waitid(long type, long id, siginfo_t *info, int options){int r = call(__NR_waitid, type, id, info, options, 0);return r;}
sys.waitid=waitid;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_WAIT2
int wait2(int pid,void *status){return waitpid(pid, status, 0);}
sys.wait2=wait2;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_WAIT
int wait(void *status){return waitpid((int)-1, status, 0);}
sys.wait=wait;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_CLONE
int clone(int (*fn)(void *), void *child_stack, long flags, void *arg){
	int r=-1;
	r = call(__NR_clone,flags,child_stack);
	fn(arg);
	return r;
	}
sys.clone=clone;
#endif	


//!------------------------------------------------------------	
#ifndef __NO_LIBS_SELECT
int select(int n, fd_set *rfds, fd_set *wfds, fd_set *efds, timeval *tv){
	int r=-1;
	#ifdef __NR__newselect
	r = call(__NR__newselect, n, rfds, wfds, efds, tv);
	#else
	r = call(__NR_select, n, rfds, wfds, efds, tv);
	#endif
	return r;
}
sys.select=select;
#endif


//!------------------------------------------------------------
#ifndef __NO_LIBS_FCNTL
int fcntl(int fd, int cmd, ...){int r;	long arg;void* ap;va_start(ap, cmd);arg = va_arg(ap, long);va_end(ap);	r = call(__NR_fcntl, fd, cmd, arg);return r;}
sys.fcntl=fcntl;
#endif


///------------------------------------------------------------
#ifndef __NO_LIBS_EXECVE
int execve(const char* filename, char * const argv[], char *const envp[]){return call(__NR_execve,filename,argv,envp);}
sys.execve=execve;
#endif


///------------------------------------------------------------
#ifndef __NO_LIBS_WRITE
int write(int fd, void* buf, size_t count) {return call(__NR_write,fd,buf,count);}
sys.write=write;
#endif


///------------------------------------------------------------
#ifndef __NO_LIBS_MPROTECT
int mprotect(void* start, size_t len, long prot) {return call(__NR_mprotect,start,len,prot);}
sys.mprotect=mprotect;
#endif


///------------------------------------------------------------
#ifndef __NO_LIBS_MUNMAP
int munmap(void *addr, size_t len) {return call(__NR_munmap,addr,len);}
sys.munmap=munmap;
#endif

///------------------------------------------------------------
#ifndef __NO_LIBS_MMAP
void *mmap(void *start, size_t len, int prot, int flags, int fd, long int off){

#ifdef __NR_mmap2
	return call(__NR_mmap2, start, len, prot, flags, fd, off>>16);
#else
	return call(__NR_mmap, start, len, prot, flags, fd, off);
#endif
}
sys.mmap=mmap;
#endif


///------------------------------------------------------------
#ifndef __NO_LIBS_SBRK
void *sbrk(long inc){
	long br=call(__NR_brk, 0);
	return call(__NR_brk, br+inc);
	}
sys.sbrk=sbrk;
#endif


///------------------------------------------------------------
#ifndef __NO_LIBS_MREMAP
void *mremap(void *old_addr, size_t old_len, size_t new_len, int flags, ...){
	void* ap;
	void *new_addr;
	va_start(ap, flags);
	new_addr = va_arg(ap, void *);
	va_end(ap);

	return call(__NR_mremap, old_addr, old_len, new_len, flags, new_addr);
}
sys.mremap=mremap;
#endif


///------------------------------------------------------------
#ifndef __NO_LIBS_MADVISE
int madvise(void *addr, size_t len, int advice){return call(__NR_madvise, addr, len, advice);}
sys.madvise=madvise;
#endif
///------------------------------------------------------------
																		
return sys;
}

static sys_t s;

