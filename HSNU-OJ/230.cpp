#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
struct P{int x,y;};
vector<P> v[10001] ;
int dp[10001][16][16] ;
int num[10001][32] ;

int check(int id,int val)
{
    int ret=0 ;
    for(int i=0;i<v[id].size();i++)
    {
        int ok ;
        if(v[id][i].x & val) ok=1 ;
        else if( ( v[id][i].y & val ) == v[id][i].y ) ok=0 ;
        else ok=1 ;
        ret+=ok ;
    }
    return ret ;
}

int n ;
void pre_cal()
{
    for(int i=1;i<=n;i++) for(int j=0;j<32;j++) num[i][j]=check(i,j) ;
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int st,num1,num2 ; scanf("%d%d%d",&st,&num1,&num2) ;
        int x=0 , y=0 ;
        while(num1--)
        {
            int a ; scanf("%d",&a) ;
            a= (a>=st ? a-st : a-st+n) ;
            x |= (1<<(4-a)) ;
        }
        while(num2--)
        {
            int a ; scanf("%d",&a) ;
            a= (a>=st ? a-st : a-st+n) ;
            y |= (1<<(4-a)) ;
        }
        v[st].push_back((P){x,y}) ;
    }
    pre_cal() ;
    for(int i=1;i<=n-3;i++) for(int j=0;j<16;j++) for(int k=0;k<16;k++)
    {
        if(i<=4)
        {
            int x= k^(j<<(i-1)) ;
            for(int z=3;z>=i-1;z--) if(x&(1<<z)) { dp[i][j][k]=-INF ; break ; }
            if(i==1 || dp[i][j][k]==-INF) continue ;

            x= ( k | (j<<(i-1)) ) ;
            for(int z=0;z<=i-2;z++)
            {
                int val= x/(1<<z) ;
                val &= 31 ;
                dp[i][j][k]+=num[i-1-z][val] ;
            }
            continue ;
        }

        int &ans=dp[i][j][k] ;
        for(int k2=0;k2<16;k2++) if(dp[i-4][j][k2]!=-INF)
        {
            int add=0 ;
            int x=(k2<<4)+k ;
            for(int z=3;z>=0;z--)
            {
                int val= x/(1<<z) ;
                val &= 31 ;
                add+=num[i-1-z][val] ;
            }
            ans=max(ans,dp[i-4][j][k2]+add) ;
        }
    }
    int ans=0 ;
    for(int i=0;i<16;i++) for(int j=0;j<16;j++)
    {
        int add=0 ;
        int x=(j<<4)+i ;
        for(int z=3;z>=0;z--)
        {
            int val= x/(1<<z) ;
            val &= 31 ;
            add+=num[n-z][val] ;
        }
        ans=max(ans,dp[n-3][i][j]+add) ;
    }
    printf("%d\n",ans) ;
}
