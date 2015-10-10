#include<bits/stdc++.h>
#define DB double
#define LL long long
#define MAXN 100
#define LEN 100000000
using namespace std;
const int maxn=500000+10 ;

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
	inline friend bigN operator + (bigN &a,bigN &b){
		bigN c;
		if(a.tag!=b.tag)c=a.SUB(a,b);
		if(a.tag>b.tag){
			if(a.cmp(a,b,0)==1){
				c.tag=1;
			}else{
				c.tag=-1;
			}
			if(c.len==1&&!c.d[0])c.tag=1;
			return c;
		}
		if(a.tag<b.tag){
			if(a.cmp(a,b,0)==-1){
				c.tag=1;
			}else{
				c.tag=-1;
			}
			if(c.len==1&&!c.d[0])c.tag=1;
			return c;
		}
		c=a.ADD(a,b);
		c.tag=a.tag;
		if(c.len==1&&!c.d[0])c.tag=1;
		return c;
	}
	inline friend bigN operator - (bigN &a,bigN &b){
		bigN c;
		b.tag*=-1;
		c=a+b;
		b.tag*=-1;
		return c;
	}
	inline friend bigN operator * (bigN &a,bigN &b){
		bigN c;
		c.tag=a.tag*b.tag;
		for(int i=0;i<a.len;i++)
		for(int j=0;j<b.len;j++)
			c.d[i+j]+=a.d[i]*b.d[j];
		for(int i=0;i<a.len+b.len;i++){
			c.d[i+1]+=c.d[i]/LEN;
			c.d[i]%=LEN;
		}
		c.len = a.len+b.len-1;
	    while(c.d[c.len] == 0 && c.len > 1)c.len--;
		if(c.d[c.len])c.len++;
		if(c.len==1&&!c.d[0])c.tag=1;
	    return c;
	}
};

LL a[maxn] ;
LL dp[maxn],s[maxn],A[maxn],B[maxn] ;
LL dq[maxn] ;

main()
{
    freopen("1.txt","r",stdin) ;
    int T=1 ;
    scanf("%d",&T) ;
    while(T--)
{
    int n,k ;
    scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%I64d",&a[n+1-i]) ;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i] ;
    dp[0]=0LL ; A[0]=B[0]=0LL ;
    int l=0 , r=1 ; dq[0]=0 ;
    for(LL i=1;i<=n;i++)
    {
        while(dq[l]+k<i) l++ ;
        while(l+1<r)
        {
            LL a0=dp[dq[l]]+s[dq[l]],b0=(dq[l]-i)*(dq[l]-i) ;
            LL c0=dp[dq[l+1]]+s[dq[l+1]],d0=(dq[l+1]-i)*(dq[l+1]-i) ;
            bigN a1,b1,c1,d1 ;
            a1(a0) ; b1(b0) ;
            c1(c0) ; d1(d0) ;
            if(a1+b1<=c1+d1) l++ ;
            else break ;
        }
        dp[i]=-i*i+A[dq[l]]*i+B[dq[l]] ;
        A[i]=2*i ; B[i]=dp[i]+s[i]-i*i ;
        while(l+1<r)
        {
            LL a0=B[dq[r-1]]-B[i],b0=A[i]-A[dq[r-2]] ;
            LL c0=B[dq[r-2]]-B[i],d0=A[i]-A[dq[r-1]] ;
            bigN a1,b1,c1,d1 ;
            a1(a0) ; b1(b0) ;
            c1(c0) ; d1(d0) ;
            if(a1*b1<=c1*d1) r-- ;
            else break ;
        }
        dq[r++]=i ;
    }
    printf("%I64d\n",dp[n]) ;
}
}
