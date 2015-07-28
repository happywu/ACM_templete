inline void RD(int &ret) {  
    char a ;  
    do {  
        a = getchar() ;  
    } while(a < '0' || a > '9') ;  
    ret = a - '0' ;  
    while((a = getchar()) && a >= '0' && a <= '9') {  
        ret = ret * 10 + a - '0' ;  
    }  
}  

inline int read(){
	static int r, sign;
	static char c;
	r = 0, sign = 1;
	do c = getchar(); while(c != '-' && (c < '0' || c > '9'));
	if( c == '-')sign = -1, c = getchar();
	while( c >= '0' && c <='9') r = r*10 +(int)(c - '0'), c = getchar();
	return sign * r;
}

int buf[10];// 声明成全局变量可以减小开销
inline void writeint(int i){
	int p = 0;bool sign=0;
	if(i<0){sign=1;i=-i;}
	if(i==0)p++;//特殊情况 i=0的时候需要输出0，而不是什么都不输出
	else while(i){buf[p++]=i%10;i/=10;}
	if(sign)putchar('-');
	for(int j=p-1;j>=0;j--)putchar('0'+buf[j]);
}


inline int fastabs(int x){
	int y = x >> 31;
	return (x+y) ^ y;
}

inline int fastmax(int x,int y)
{
	int m = (x-y) >> 31;
	return y & m | x& ~m;
}
