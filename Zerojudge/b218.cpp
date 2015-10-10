#include<bits/stdc++.h>
using namespace std;
vector<int> v[30000] ;
bool vis[30000] ;
int n,ans[30000] ;

int dfs(int x)
{
    vis[x]=1 ;
    if(x!=1 && v[x].size()==1) return 1 ;
    int sum=0 , sqs=0 ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]])
    {
        int add=dfs(v[x][i]) ;
        sum+=add , sqs+=add*add ;
    }
    sqs += (n-1-sum)*(n-1-sum) ;
    ans[x]=((n-1)*(n-1)-sqs)/2 ;
    return sum+1 ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    dfs(1) ;
    int ANS=0,ansid ;
    for(int i=1;i<=n;i++) if(ans[i]>ANS) ANS=ans[ansid=i] ;
    printf("%d %d\n",ansid,ANS) ;
}
