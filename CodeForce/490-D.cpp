#include<bits/stdc++.h>
#define LL long long
using namespace std;

map<LL,int> mp ;

void dfs1(LL x,int d,bool two)
{
    if(mp.count(x)) return ;
    mp[x]=d ;
    if(!two && x%3==0) dfs1((x/3)*2,d+1,0) ;
    if(x%2==0) dfs1(x/2,d+1,1) ;
}

LL area ;
int ans=-1 ;

void dfs2(LL x,int d,bool two)
{
    if(mp.count(x))
    {
        int val=mp[x] ;
        if( ans==-1 || val+d < ans )
        {
            ans=val+d ;
            area=x ;
        }
    }
    if(!two && x%3==0) dfs2(x*2/3,d+1,0) ;
    if(x%2==0) dfs2(x/2,d+1,1) ;
}

main()
{
    LL a1,b1,a2,b2 ; scanf("%I64d%I64d%I64d%I64d",&a1,&b1,&a2,&b2) ;
    dfs1(a1*b1,0,0) ;
    dfs2(a2*b2,0,0) ;
    printf("%d\n",ans) ;
    if(ans==-1) return 0 ;

    int cnt=0,cnt1=0,cnt2=0 ; LL tmp ;
    tmp=area ; while(tmp%3==0) cnt++ , tmp/=3 ;
    tmp=a1*b1 ; while(tmp%3==0) cnt1++ , tmp/=3 ;
    tmp=a2*b2 ; while(tmp%3==0) cnt2++ , tmp/=3 ;

    for(int i=cnt1;i>cnt;i--)
    {
        if(a1%3==0) a1=a1*2/3 ;
        else b1=b1*2/3 ;
    }
    while(a1*b1!=area) { if(a1%2) b1/=2 ; else a1/=2 ; }
    printf("%I64d %I64d\n",a1,b1) ;

    for(int i=cnt2;i>cnt;i--)
    {
        if(a2%3==0) a2=a2*2/3 ;
        else b2=b2*2/3 ;
    }
    while(a2*b2!=area) { if(a2%2) b2/=2 ; else a2/=2 ; }
    printf("%I64d %I64d\n",a2,b2) ;
}
