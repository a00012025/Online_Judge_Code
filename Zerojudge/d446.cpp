#include<stdio.h>
#include<algorithm>
#define LL long long
#define ULL unsigned long long
using namespace std;
bool a[50001] ;
int p[6000]={0},fac[6000],num[6000],pfac[6000]={0},cnt2,cnt3 ;
void dfs(int i,int now)
{
    if(i==cnt2) fac[++cnt3]=now ;
    else
    {
        int m=1 ;
        for(int j=0;j<=num[i+1];j++)
        {
            dfs(i+1,now*m) ;
            m=m*pfac[i+1] ;
        }
    }
}
main()
{
    a[1]=0 ;
    for(int i=2;i<=50000;i++) a[i]=1 ;
    for(int i=2;i<=50000;i++)
    {
        if(!a[i])continue ;
        for(int j=2;i*j<=50000;j++) a[i*j]=0 ;
    }
    int cnt=1 ;
    for(int i=1;i<=50000;i++)
    {
        if(!a[i])continue ;
        p[cnt++]=i ;
    }   // 5133
    int n ;
    while(scanf("%d",&n)!=EOF){
    cnt2=0 ; int m=n ;
    for(int i=1;p[i]!=0;i++)
    {
        if(m%p[i]) continue ;
        cnt=0 ;
        for(;!(m%p[i]);m=m/p[i]) cnt++ ;
        cnt2++ ; pfac[cnt2]=p[i] ; num[cnt2]=cnt ;
    }
    if(m!=1){cnt2++ ; pfac[cnt2]=m ; num[cnt2]=1 ;}
    cnt3=0 ;
    dfs(0,1) ;
    sort(fac+1,fac+cnt3+1) ;
    for(int i=1;i<=cnt3;i++) printf("%d ",fac[i]);
    printf("\n");
}
}

