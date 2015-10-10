#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

vector<int> v[maxn] ;
int ma[maxn][2] , mi[maxn][2] ; /// 0 : fir , 1 : sec
int num[maxn] ;
void dfs(int x)
{
    if(v[x].empty())
    {
        ma[x][0]=ma[x][1]=mi[x][0]=mi[x][1]=1 ;
        num[x]=1 ; return ;
    }
    for(auto i :v[x]) dfs(i) , num[x]+=num[i] ;

    int sum1=0,sum2=0 ;
    mi[x][1]=maxn ;
    for(auto i :v[x])
    {
        ma[x][0]=max(ma[x][0],num[x]-(num[i]-ma[i][1])) ;
        sum1+=num[i]-ma[i][0]+1 ;
        sum2+=mi[i][1] ;
        mi[x][1]=min(mi[x][1],mi[i][0]) ;
    }
    ma[x][1]=num[x]-sum1+1 ;
    mi[x][0]=sum2 ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
    }
    dfs(1) ;
    printf("%d %d\n",ma[1][0],mi[1][0]) ;
}
