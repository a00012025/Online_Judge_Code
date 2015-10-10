/********************************************************
	已重新定義 + - * / % >= > <= < == 之運算子
	+ - * / % 不支援四則運算
	函數解說:
	建立大數 bigN x;
	傳回x的長度 x.size();
	把long long型態轉成大數 x(n);
	把c字串轉成大數 x(s);
	找出第k(0~x.size()-1)位的數字(找不到return -1) x[k];
	歸 0 x.clear();
	輸出 x.printf(is) is=1印出'\n'; is=0不換行;
	將x乘以10 x.mul_10();
********************************************************/
#include<bits/stdc++.h>
using namespace std;
#define MAXN 5000
#define LEN 100000000
struct bigN{
	long long d[MAXN];
	int len;
	short tag;//1正數 -1負數
	bigN(){
		memset(d,0,sizeof(d));
		len=1;
		tag=1;
	}
	inline void operator () (long long n){//long long 轉bigN
		memset(d,0,sizeof(d));
		len=0;
		if(n<0)tag=-1,n*=-1;
		else tag=1;
		while(n){
			d[len++]=n%LEN;
			n/=LEN;
		}
		if(!len)len++;
	}
	inline void operator () (char *s){//字串轉bigN
		memset(d,0,sizeof(d));
		long long a=0,b=1;
		int i=0,j=strlen(s);len=0;
		if(s[0]=='-')tag=-1,i++;
		else tag=1;
		for(j--;j>=i;j--){
			a=a+(s[j]-'0')*b;
			b*=10;
			if(b>LEN){
				d[len++]=a%LEN;
				a/=LEN;
				b=10;
			}
		}
		if(a)d[len++]=a;
		if(!len)len++;
	}
	inline int size(){
		long long a=d[len-1];
		int tmd=0;
		while(a)a/=10,tmd++;
		return (len-1)*8+tmd;
	}
	inline int operator[](int x){
		if(x>=size())return -1;
		int l=x/8;x%=8;
		int tmd=1;
		for(int i=0;i<x;i++)tmd*=10;
		long long a=d[l]/tmd;
		return (int)a%10;
	}
	inline void modify(int x,int y){
		if(y>10||y<0)return;
		int l=x/8,k;x%=8;
		if(len<l+1)len=l+1;
		long long tmd=1;
		while(x--)tmd*=10;
		k=(d[l]/tmd)%10;
		d[l]-=k*tmd;
		d[l]+=y*tmd;
	}
	inline void clear(){
		memset(d,0,sizeof(d));
		len=tag=1;
	}
	inline short cmp(bigN &a,bigN &b,bool is){
		if(is){
			if(a.tag>b.tag)return 1;
			if(a.tag<b.tag)return -1;
		}
		if(a.tag>0||is==0){
			if(a.len>b.len)return 1;
			if(a.len<b.len)return -1;
			for(int i=a.len-1;i>=0;i--){
				if(a.d[i]>b.d[i])return 1;
				if(a.d[i]<b.d[i])return -1;
			}
		}else{
			if(a.len>b.len)return -1;
			if(a.len<b.len)return 1;
			for(int i=a.len-1;i>=0;i--){
				if(a.d[i]>b.d[i])return -1;
				if(a.d[i]<b.d[i])return 1;
			}
		}
		return 0;
	}
	inline friend bool operator < (bigN a,bigN b){
		if(a.cmp(a,b,1)==-1)return 1;
		return 0;
	}
	inline friend bool operator <= (bigN a,bigN b){
		short tmd=a.cmp(a,b,1);
		if(tmd==-1||!tmd)return 1;
		return 0;
	}
	inline friend bool operator > (bigN a,bigN b){
		if(a.cmp(a,b,1)==1)return 1;
		return 0;
	}
	inline friend bool operator >= (bigN a,bigN b){
		short tmd=a.cmp(a,b,1);
		if(tmd==1||!tmd)return 1;
		return 0;
	}
	inline friend bool operator == (bigN a,bigN b){
		if(!a.cmp(a,b,1))return 1;
		return 0;
	}
	inline void print(bool is){
		if(tag<0)putchar('-');
		printf("%lld",d[len-1]);
		for(int i=len-2;i>=0;i--){
			printf("%08lld",d[i]);
		}
		if(is)puts("");
	}
	inline bigN ADD(bigN &a,bigN &b){
		bigN c;
		c.len=max(a.len,b.len);
		for(int i=0;i<c.len;i++){
			c.d[i]+=a.d[i]+b.d[i];
			if(c.d[i]>=LEN){
				c.d[i+1]++;
				c.d[i]-=LEN;
			}
		}
		if(c.d[c.len])c.len++;
		return c;
	}
	inline bigN SUB(bigN &a,bigN &b){
		bigN c;
		int is=0;
		int tmd=cmp(a,b,0);
		if(tmd==-1)is=1;
		if(!tmd)return c;
		c.len=max(a.len,b.len);
		for(int i=0;i<c.len;i++){
			if(is)c.d[i]+=b.d[i]-a.d[i];
			else c.d[i]+=a.d[i]-b.d[i];
			if(c.d[i]<0){
				c.d[i]+=LEN;
				c.d[i+1]--;
			}
		}
		while(c.d[c.len-1]==0&&c.len>1)c.len--;
    	return c;
	}
	inline void mul_10(){
		for(int i=0;i<len;i++)d[i]*=10;
		for(int i=0;i<len;i++)d[i+1]+=d[i]/LEN,d[i]%=LEN;
		if(d[len])len++;
	}
	inline void div(bigN &a,bigN &b,bigN &c,bigN &f){
		c.clear();f.clear();
		int tmd=cmp(a,b,0);
		if(tmd<0){f=a;return;}
		if(!tmd){c.d[0]=1;return;}
		int siz=a.size();
		for(int i=siz-1;i>=0;i--){
			f.mul_10();f.d[0]+=a[i];
			tmd=1;
			while(cmp(f,b,0)>=0){
				f=f.SUB(f,b);
				c.modify(i,tmd++);
			}
		}
		while(c.len>1 &&c.d[c.len-1]==0)c.len--;
		c.tag=a.tag*b.tag;f.tag=a.tag;
		if(f.len==1&&!f.d[0])f.tag=1;
	}
	inline friend bigN operator / (bigN &a,bigN &b){
		bigN c,f;
		c.div(a,b,c,f);
		return c;
	}
};
bigN a,b;
char x[100],y[100],d[5];
int main()
{
	scanf("%s%s",x,y) ;
    a(x);b(y);
	(a/b).print(1);
}
