#include<stdio.h>
#include<algorithm>
using namespace std;
int ans[10000] ;
int bitcnt(int x)
{
    if(!x) return 0;
    return x%2 ? (1+bitcnt(x/2)) : bitcnt(x/2) ;
}

bool jump(int n,int pos,int type)
{
    if((n & (1<<pos)) ==0) return 0 ;
    if(type==1)
    {
        if( (n&(1<<(pos-1))) && ((n&(1<<(pos-2)))==0) ) return 1;
        else return 0 ;
    }
    if(type==-1)
    {
        if( (n&(1<<(pos+1))) && ((n&(1<<(pos+2)))==0) ) return 1;
        else return 0;
    }
}

main()
{
    for(int i=1;i<(1<<12);i++) ans[i]=12 ;
    ans[0]=0 ;
    for(int i=1;i<12;i++) for(int j=1;j<(1<<12);j++)
    {
        if(bitcnt(j)!=i) continue ;
        if(i==1) {ans[j]=1 ; continue ;}
        ans[j]=i ;
        for(int k=0;k<=9;k++) if(jump(j,k,-1))
            ans[j]=min(ans[j],ans[j+(1<<k)]);
        for(int k=11;k>=2;k--) if(jump(j,k,1))
            ans[j]=min(ans[j],ans[j-(1<<k)-(1<<(k-1))+(1<<(k-2))]);
    }
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        char s[20] ;
        scanf("%s",s) ;
        int n=0 ;
        for(int i=0;i<12;i++)
        {
            n*=2 ;
            if(s[i]=='o') n++ ;
        }
        printf("%d\n",ans[n]) ;
    }
}
