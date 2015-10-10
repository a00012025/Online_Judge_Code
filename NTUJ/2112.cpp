#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
const int maxn=400000+10 ;

char s[maxn] ;
int extl(int l,int r,int n)
{
    if(s[l]!=s[r]) return 0 ;
    int i=1 ;
    for(;l-i+1>=0 && r+i-1<n && s[l-i+1]==s[r+i-1];i++) ;
    return i-1 ;
}

int Z[maxn] ;
void getz(int n)
{
//    s[n]=0 ; printf("%s\n",s) ;
    Z[0]=1 ;
    for(int i=1,L=0,R=0;i<n;i++)
    {
        int i2=R+L-i ;
        if(R<i)
        {
            Z[i]=extl(i,i,n) ;
            L=i-Z[i]+1 ; R=i+Z[i]-1 ;
        }
        else if(Z[i2]>R-i+1) Z[i]=R-i+1 ;
        else if(Z[i2]<R-i+1) Z[i]=Z[i2] ;
        else
        {
            Z[i]=R-i+1 + extl(2*i-R,R,n) - 1 ;
            L=i-Z[i]+1 ; R=i+Z[i]-1 ;
        }
//        printf("Z[%d]=%d\n",i,Z[i]) ;
    }
}

int bit[maxn],all=0 ;
void setmax(int x,int n,int val)
{
    if(x==0) all=max(all,val) ;
    else for(;x<=n;x+=lowbit(x)) bit[x]=max(bit[x],val) ;
}
int query(int x)
{
    int ret=all ;
    for(;x;x-=lowbit(x)) ret=max(ret,bit[x]) ;
    return ret ;
}

int ri[maxn],dp[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s",s) ;
        int n=strlen(s) ;
        fill(bit,bit+n,0) ; all=0 ;

        for(int i=n-1;i>=0;i--) s[2*i]=s[i] , s[2*i+1]='@' ;
        getz(2*n-1) ;
        for(int i=2*n-2;i>=0;i--)
        {
            int L=(i-Z[i]+1+1)/2 ;
            setmax(L,n,i/2) ;
            if(i%2==0) ri[i/2]=query(i/2) ;
        }
        dp[n]=0 ;
        for(int i=n-1;i>=0;i--) dp[i]=dp[ri[i]+1]+1 ;
        printf("%d\n",dp[0]) ;
    }
}
