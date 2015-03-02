#include "acus.c"
void __stack_chk_fail(){return;}
int main(int argc, char** argv,char** env){
	sys_t sys;
	st_t st;
	sys=libs(sys);
	st=libc(st);
int i=0;

char* test=st.malloc(7);
st.strcpy(test,"123456\n");
sys.write(0,test,st.strlen(test));
st.free(test);

i++;


return 0;	
	}
