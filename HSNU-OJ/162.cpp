#include<bits/stdc++.h>
#define LL long long
#define F first
#define S second
using namespace std;
const int maxn=1000000+10 ;
bool vis[maxn] ;
int p[100000],pcnt=0 ;
void make_prime()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i)
            vis[j]=1 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++pcnt]=i ;
}

LL a[700] ;
map<LL,int> mp ;
main()
{
    make_prime() ;
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=pcnt;j++)
        while(a[i]%p[j]==0) a[i]/=p[j] , mp[p[j]]++ ;

    int n2=0 ;
    for(int i=1;i<=n;i++) if(a[i]!=1) a[++n2]=a[i] ; n=n2 ;

    for(int i=1;i<=n;i++)
    {
        LL sq=(LL)sqrt(a[i]+0.5) ;
        if(sq*sq == a[i]) mp[sq]+=2 , a[i]=1LL ;
    }

    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
    {
        LL d=__gcd(a[i],a[j]) ;
        if(d!=1LL)
        {
            mp[d]+=2 ;
            if(a[i]!=d) mp[a[i]/d]++ ;
            if(a[j]!=d) mp[a[j]/d]++ ;
            a[i]=1 ; a[j]=1 ;
        }
    }



    int k=-1,num=0 ;
    for(auto it : mp)
    {
        if(it.S > k) k=it.S , num=1 ;
        else if(it.S == k) num++ ;
    }
    printf("%d\n%I64u\n",k,(1ULL<<num)-1) ;
}
