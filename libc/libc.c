#include "libc.h"

st_t libc(st_t st){


//ctype	
///---------------------------------------------------------------------
int isalpha(int ch){
	return ((unsigned)ch|32)-'a' < 26;
}
st.isalpha=isalpha;
///---------------------------------------------------------------------
int isalnum(int ch){
	return isalpha(ch) || isdigit(ch);
}
st.isalnum=isalnum;
///---------------------------------------------------------------------
int iscntrl(int ch){
	return (unsigned)ch < 0x20 || ch == 0x7f;
}
st.iscntrl=iscntrl;
///---------------------------------------------------------------------
int isdigit(int ch){
	return (unsigned)ch-'0' < 10;
}
st.isdigit=isdigit;
///---------------------------------------------------------------------
int isgraph(int ch){
	return (unsigned)ch-0x21 < 0x5e;
}
st.isgraph=isgraph;
///---------------------------------------------------------------------
int islower(int ch){
	return (unsigned)ch-'a' < 26;
}
st.islower=islower;
///---------------------------------------------------------------------
int isprint(int ch){
	return (unsigned)ch-0x20 < 0x5f;
}
st.isprint=isprint;
///---------------------------------------------------------------------
int ispunct(int ch){
	return isgraph(ch) && !isalnum(ch);
}
st.ispunct=ispunct;
///---------------------------------------------------------------------
int isspace(int ch){
	return ch == ' ' || (unsigned)ch-'\t' < 5;
}
st.isspace=isspace;
//!---------------------------------------------------------------------
int isupper(int ch){
	return (unsigned)ch-'A' < 26;
}
st.isupper=isupper;
//!---------------------------------------------------------------------
int isxdigit(int ch){
	return isdigit(ch) || ((unsigned)ch|32)-'a' < 6;
}
st.isxdigit=isxdigit;
//!---------------------------------------------------------------------
int tolower(int ch){
	if (isupper(ch)){ return (ch | 32);}
	return ch;
}
st.tolower=tolower;
//!---------------------------------------------------------------------
int toupper(int ch){
	if (islower(ch)){ return (ch & 95);}
	return ch;
}
st.toupper=toupper;
///---------------------------------------------------------------------
//string
///---------------------------------------------------------------------
size_t strlen(char *str){
	int n=0;
	if (!str){return n;}
	for (; *str; str++){n++;}
	return n;
}
st.strlen=strlen;
///---------------------------------------------------------------------
char * strcpy( char *to,char *from){
	char *save = to;
	for (; (*to = *from) != '\0'; ++from, ++to);
	return(save);
}
st.strcpy=strcpy;
///---------------------------------------------------------------------
char * strncpy( char *to,char *from, int nom){
	char *save = to; int i=0;
	for (; (*to = *from) != '\0' && nom>i; ++from, ++to, ++i);
	return(save);
}
st.strncpy=strncpy;
///---------------------------------------------------------------------
char* strcat ( char* des, char* so ){
while (*des) ++des;
while ((*des++ = *so++) != '\0') ;
return des;
}
st.strcat=strcat;
///---------------------------------------------------------------------
char* strncat(char* dst, char * src, size_t n){
	if (n != 0) {
		char *d = dst;
		char *s = src;

		while (*d != 0)
			d++;
		do {
			if ((*d = *s++) == 0)
				break;
			d++;
		} while (--n != 0);
		*d = '\0';
	}
	return dst;
}
st.strncat=strncat;
///---------------------------------------------------------------------
int strcmp(char *l, char *r){
int i=0,ll=strlen(l), lr=strlen(r);
if(ll!=lr){return ll - lr;}
while(l[i]!='\0'){
if(l[i]!=r[i]){return (unsigned int)l[i] - (unsigned int)r[i];}
	i++;}	
								  }
st.strcmp=strcmp;								  
///---------------------------------------------------------------------
int strncmp(char* l, char* r, size_t num){
int i=0;
if (num == 0){return 0;}
do {
if(l[i]!=r[i]){return (unsigned int)l[i]-(unsigned int)r[i];}
if (l[i] == 0){break;}
i++;
} while (--num != 0);
return 0; 
} 
st.strncmp=strncmp;
///---------------------------------------------------------------------
char *strchr(char *s, int c){
    char ch = c;
    for ( ; *s != ch; s++){
        if (*s == '\0'){return 0;}
        }
    return (char *)s;
}
st.strchr=strchr;
///---------------------------------------------------------------------
char* strrchr(char *cp, int ch){
    char *save; char c;
    for (save = (char *)0; (c = *cp); cp++) {
	if (c == ch)
	    save = (char *) cp;
    }
    return save;
}
st.strrchr=strrchr;
///---------------------------------------------------------------------
int strspn(char *p, char *s){
	int i=0, j=0;
	for (; p[i]; i++) {
		for (; s[j]; j++) {
			if (s[j] == p[i]){break;}
		}
		if (!s[j]){	break;}
	}
	return i;
}
st.strspn=strspn;
///---------------------------------------------------------------------
int strcspn (char *p,char *s){
	int i=0, j=0;

	for (; p[i]; i++) {
		for (; s[j]; j++) {
			if (s[j] == p[i]){break;}
		}
		if (s[j]){break;}
	}
	return i;
}
st.strcspn=strcspn;
///---------------------------------------------------------------------
char * strpbrk(char *s1, char *s2){
	for (; *s1; s1++) {
		if (strchr (s2, *s1) != 0)
			return ((char *)s1);
	}
	return 0;
}
st.strpbrk=strpbrk;
///---------------------------------------------------------------------
char * strstr(char *string, char *substring){
char c, sc;
size_t len;
if ((c = *substring++) != 0) {
len = strlen(substring);
	do {
		do {
		if ((sc = *string++) == 0){	return NULL;}
			} while (sc != c);
		
	} while (strncmp(string, substring, len) != 0);
	string--;
	}
return ((char *) string);
}
st.strstr=strstr;
///---------------------------------------------------------------------
//strerror(n) TODO
///---------------------------------------------------------------------
char * strtok(char *p, char *tok){
char *t; char *r; int n;

	if (p){t = p;}
	r = t + strspn(t, tok);
	if (!(n = strcspn(r, tok))){return 0;}
	t = r + n;
	if (*t){*t++ = 0;}
	return r;
}
st.strtok=strtok;
///---------------------------------------------------------------------
void *memcpy (void *dest, void *src, size_t n){
        char *r1 = dest;
        const char *r2 = src;
 
        while (n) {
                *r1++ = *r2++;
                --n;
        }
 
        return dest;
}
st.memcpy=memcpy;
///---------------------------------------------------------------------

//memcat TODO

///---------------------------------------------------------------------
void *memmove(char *dest, char *src, size_t n)
{
	char *d = dest;
	const char *s = src;
	if (d==s) return d;
	if ((size_t)(d-s) < n) {
		while (n--) d[n] = s[n];
		return dest;
	}
	return memcpy((char*)d, (char*)s, (size_t)n);
}
st.memmove=memmove;
///---------------------------------------------------------------------
int memcmp( void *s1,  void *s2, size_t n) {
     if (n) {
         unsigned char *p1 = s1, *p2 = s2;
 
        do {
            if (*p1++ != *p2++) {
                return (*--p1 - *--p2);
            }
        } while (--n);
     }
     return 0;
}
st.memcmp=memcmp;
///---------------------------------------------------------------------
void *memchr( void *s, int c, size_t n){
    if (n) { unsigned char *p = s;
        do {
             if (*p++ == (unsigned char) c) {
                return (void *) (p - 1);
             }
         } while (--n);
     }
     return 0;
 }
st.memchr=memchr;
///---------------------------------------------------------------------
void *memset(void *s, int c, size_t n)
{
        unsigned char *p = (unsigned char *) s;
 
        while (n) {
                *p++ = (unsigned char) c;
                --n;
        }
 
        return s;
}
st.memset=memset;
///---------------------------------------------------------------------
//array
size_t count(void** v) {
    size_t i=0;
    while (v[i]!=NULL) {
        ++i;
    }
    return i;
}
st.count=count;
///---------------------------------------------------------------------
void* end(void** arr){
long pos=count(arr);
return arr[pos];	
					 }
st.end=end;
///---------------------------------------------------------------------
//memory alloc
uni getptrid(void *ptr, mhope hope){
uni i=0,z=0,n=-1;
while(i<hope.i){
if(((uni)ptr)==hope.a[i]){z=hope.z[i];n=i;break;}	
	i++;
	}
return n;		
						}
//-------------------------------------
uni getptrsize(void *ptr, mhope hope){
uni i=0,z=0,n=-1;
while(i<hope.i){
if(((uni)ptr)==hope.a[i]){z=hope.z[i];n=i;break;}	
	i++;
	}
return z;		
						}
//-------------------------------------
void dropptr(void* ptr, mhope hope){
uni id=getptrid(ptr,hope);
hope.a[id]=-1; 
hope.z[id]=-1;
void hope_sort(mhope hope){
uni i=0,j=0,z=0,min=0,max=0,nom=hope.i+1;
uni a=0;	
    for(i = 0 ; i < nom ; i++) { 
       for(j = 0 ; j < nom - i - 1 ; j++) {  
           if(hope.a[j] < hope.a[j+1]) {           
              a = hope.a[j]; 
              hope.a[j] = hope.a[j+1] ; 
              hope.a[j+1] = a; 
              
              z = hope.z[j]; 
              hope.z[j] = hope.z[j+1] ; 
              hope.z[j+1] = z;
           }
        }
    }
if(hope.i>0){hope.i--;}    	
				}
hope_sort(hope);
						}
//-------------------------------------

void free_ptr(void* ptr){
sys_t sys=libs(sys);
if (ptr == NULL){sys.write(0,"ptr=NULL\n",9);return;}
uni id=getptrid(ptr,hope),o=-1;
if(id==-1){sys.write(0,"ptr no id in hope array!\n",25);return;}
if(hope.z[id]>0){
	o=sys.munmap(ptr, hope.z[id]);
if(o == -1){sys.write(0,"munmap failed!\n",15);	}	
dropptr(ptr,hope);
}else{
sys.write(0,"ptr no mmaped\n",14);	
	}
return;		 
						}
st.free_ptr=free_ptr;						

//-------------------------------------

void free(void* ptr){
if (ptr == NULL){return;}
int id=getptrid(ptr,hope),pco=strlen((char*)ptr),sco=count((void**)ptr);
if(id==-1){return;}
if(sco>0 && pco==0){
	void** bf=ptr;
	while(sco>0){sco--;if(count((void**)bf[sco])>0){free(bf[sco]);}else{free_ptr(bf[sco]);}}
					}
free_ptr(ptr);

return;	
					}
st.free=free;
//-------------------------------------
void *malloc(size_t size){
	sys_t sys=libs(sys);
if(size<=0){size=1;}
void *result=sys.mmap(0, size , PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
if (result == -1){sys.write(0,"mmap failed!\n",13);return NULL;}
if(!hope.i){hope.i=0;}
hope.a[hope.i]=(uni)result;
hope.z[hope.i]=size;
hope.i++;
return result;
						}
st.malloc=malloc;
//-------------------------------------
void *realloc(void *ptr, size_t size){
	sys_t sys=libs(sys);
uni i=0,z=0,id=getptrid(ptr,hope);
        if (!ptr){return malloc(size);}
        if (!size) {free(ptr);return malloc(1);}
          void *newptr = malloc(size);
        if (newptr) {
				 memcpy(newptr, ptr, hope.z[id]);
                free(ptr);
        }else{sys.write(0,"mmap failed!\n",13);return NULL;}
        return newptr;
}
st.realloc=realloc;
//-------------------------------------
///------------------------------------------------------------
//-------------------------------------
uni lgetptrid(void *ptr, mween ween){
uni i=0,z=0,n=-1;
while(i<ween.i){
if(((uni)ptr)==ween.a[i]){z=ween.z[i];n=i;break;}	
	i++;
	}
return n;		
						}
//-------------------------------------
uni lgetptrsize(void *ptr, mhope ween){
uni i=0,z=0,n=-1;
while(i<ween.i){
if(((uni)ptr)==ween.a[i]){z=ween.z[i];n=i;break;}	
	i++;
	}
return z;		
						}
//-------------------------------------
void ldropptr(void* ptr, mween ween){
uni id=lgetptrid(ptr,ween);
ween.a[id]=-1; 
ween.z[id]=-1;
ween.o[id]=-1;
void ween_sort(mween ween){
uni i=0,j=0,z=0,o=0,min=0,max=0,nom=ween.i+1;
uni a=0;	
    for(i = 0 ; i < nom ; i++) { 
       for(j = 0 ; j < nom - i - 1 ; j++) {  
           if(ween.a[j] < ween.a[j+1]) {           
              a = ween.a[j]; 
              ween.a[j] = ween.a[j+1] ; 
              ween.a[j+1] = a; 
              
              z = ween.z[j]; 
              ween.z[j] = ween.z[j+1] ; 
              ween.z[j+1] = z;
              
              o = ween.o[j]; 
              ween.o[j] = ween.o[j+1] ; 
              ween.o[j+1] = o;
           }
        }
    }
if(ween.i>0){ween.i--;}    	
				}
ween_sort(ween);
						}
//-------------------------------------
void *lmalloc(size_t size){
	sys_t sys=libs(sys);
if(size<=0){size=1;}
void *result;

result=sys.sbrk(size);

if (result == -1){sys.write(0,"sbrk failed!\n",13);return NULL;}
if(!ween.i){ween.i=0;}
ween.a[ween.i]=(uni)result;
ween.o[ween.i]=(uni)result-size;
ween.z[ween.i]=size;
ween.i++;
return result;
						  }			
st.lmalloc=lmalloc;
//-------------------------------------
void lfree_ptr(void* ptr){
sys_t sys=libs(sys);
if (ptr == NULL){sys.write(0,"ptr=NULL\n",9);return;}
uni id=lgetptrid(ptr,ween);
if(id==-1){sys.write(0,"ptr no id in hope array!\n",25);return;}
uni pt=ween.a[id];

if(ween.z[id]>0){
ptr = sys.brk(ween.o[id]);
ldropptr(pt,ween);
ptr=NULL;
}else{
sys.write(0,"ptr no mmaped\n",14);	
	}
return;		 
						}
st.lfree_ptr=lfree_ptr;						
//-------------------------------------
void lfree(void* ptr){
if (ptr == NULL){return;}
int id=lgetptrid(ptr,ween),pco=strlen((char*)ptr),sco=count((void**)ptr);
if(id==-1){return;}
if(sco>0 && pco==0){
	void** bf=ptr;
	while(sco>0){sco--;if(count((void**)bf[sco])>0){lfree(bf[sco]);}else{lfree_ptr(bf[sco]);}}
					}
lfree_ptr(ptr);
return;	
					}
st.lfree=lfree;
//-------------------------------------
void *lrealloc(void *ptr, size_t size){
	sys_t sys=libs(sys);
uni i=0,z=0,id=lgetptrid(ptr,ween);
        if (!ptr){return lmalloc(size);}
        if (!size) {lfree(ptr);return lmalloc(1);}
          void *newptr = lmalloc(size);
        if (newptr) {
				 memcpy(newptr, ptr, ween.z[id]);
                lfree(ptr);
        }else{sys.write(0,"sbrk failed!\n",13);return NULL;}
        return newptr;
}
st.lrealloc=lrealloc;
//-------------------------------------
///------------------------------------------------------------
//additional string

uni strpos(char *haystack, char *needle){
   char *p = strstr(haystack, needle);
   if (p){return p - haystack;}else{return -1;}  
}
st.strpos=strpos; 
//!------------------------------------------------------------
uni chrpos(char *haystack, char needle){
   char *p = strchr(haystack, needle);
   if (p){return p - haystack;}else{return -1;}  
}
st.chrpos=chrpos;
//!------------------------------------------------------------ 
uni	sch(char* str, char ch) {//присутствует ли символ в строке
    uni i=0;
    while (str[i] != '\0') {
        if (str[i] == ch) {
            return 1;
        }
        ++i;
    }
    return 0;
}
st.sch=sch;
//!------------------------------------------------------------
//усложненная проверка сравнения срок, сравнение по длине и вхожденнии
int scmp(char* str1, char* str2){
uni si1=strlen(str1); 
uni si2=strlen(str2);
if(si1>si2){return -1;}
if(si2>si1){return -2;}
if(si1==si2){
uni i;
for(i=0;i<si1;i++){
if(str1[i]!=str2[i]){return 0;}
				  }
			}
return 1;
										}
st.scmp=scmp;

//!------------------------------------------------------------
uni strnpos(char* str, char* sub, int ot) {
    int pFind = 0, pos = 0;
    str=str+ot;
    if (strstr(str,sub)) {
        pFind=strlen(strstr(str, sub));
        pos =strlen(str+pFind);
    }
    return pos;
}
//!------------------------------------------------------------
long substr_count(char* str_s, char* sub_s) {
    long count_sub=0;
    str_s = strstr(str_s,sub_s);
    while (str_s!=0) {
        str_s=str_s+strlen(sub_s);
        str_s = strstr(str_s,sub_s);
        count_sub++;
    }
    return count_sub;
}

//!------------------------------------------------------------
long subchr_count(char* str_s, char sub_c) {
    long count_sub=0;
    str_s = strchr(str_s,sub_c);
    while (str_s!=0) {
        str_s=str_s+1;
        str_s = strchr(str_s,sub_c);
        count_sub++;
    }
    return count_sub;
}
//!------------------------------------------------------------

return st;
	}
