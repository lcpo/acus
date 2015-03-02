///------------------------------------------------------------
#ifdef __i386__
#define __NR_UN_socket      1
#define __NR_UN_bind        2
#define __NR_UN_connect     3
#define __NR_UN_listen      4
#define __NR_UN_accept      5
#define __NR_UN_getsockname 6
#define __NR_UN_getpeername 7
#define __NR_UN_socketpair  8
#define __NR_UN_send        9
#define __NR_UN_recv        10
#define __NR_UN_sendto      11
#define __NR_UN_recvfrom    12
#define __NR_UN_shutdown    13
#define __NR_UN_setsockopt  14
#define __NR_UN_getsockopt  15
#define __NR_UN_sendmsg     16
#define __NR_UN_recvmsg     17
#define socketcall(nr, a, b, c, d, e, f) sysrun(__NR_socketcall, __NR_UN_##nr, ((long [6]){ (long)a, (long)b, (long)c, (long)d, (long)e, (long)f }),0,0,0,0,0)
#endif

#ifdef __x86_64__
#define socketcall(nr,a,b,c,d,e,f) sysrun(__NR_##nr,a,b,c,d,e,f,0)
#endif
