#include<bits/stdc++.h>
#define CASE_T int __T ; scanf("%d",&__T) ; while(__T--)
using namespace std;
const int maxn=1000+10 ;

int dp[maxn][maxn] ;
int a[maxn],cnt ;

struct node
{
    node *nxt ;
    int val ;
    node(int _val)
    {
        nxt=NULL ;
        val=_val ;
    }
};

bool better(node *x,node *y,int num)
{
    while(num--)
    {
        if(x->val != y->val) return x->val < y->val ;
        x=x->nxt ; y=y->nxt ;
    }
    return 1 ;
}


node *st[maxn][maxn] ;
main()
{
    CASE_T
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;

        for(int i=n;i>=1;i--) for(int j=i;j<=n;j++)
        {
            if(i==j)
            {
                dp[i][j]=1 ;
                st[i][j]=new node(a[i]) ;
                continue ;
            }

            if(a[i]==a[j])
            {
                dp[i][j]=dp[i+1][j-1]+2 ;
                st[i][j]=new node(a[i]) ;
                if(j>i+1) st[i][j]->nxt = st[i+1][j-1] ;
                continue ;
            }

            if(dp[i+1][j]!=dp[i][j-1])
            {
                if(dp[i+1][j]>dp[i][j-1])
                    st[i][j]=st[i+1][j] , dp[i][j]=dp[i+1][j] ;
                else
                    st[i][j]=st[i][j-1] , dp[i][j]=dp[i][j-1] ;
                continue ;
            }

            if(better(st[i+1][j],st[i][j-1],(dp[i][j-1]+1)/2))
                st[i][j]=st[i+1][j] , dp[i][j]=dp[i+1][j] ;
            else
                st[i][j]=st[i][j-1] , dp[i][j]=dp[i][j-1] ;
        }
//        printf("XD\n") ;
        if(dp[1][n]==1) { printf("%d\n",st[1][n]->val) ; continue ; }
        node *now=st[1][n] ;
        vector<int> ans ;
        while(now) ans.push_back(now->val) , now=now->nxt ;
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]) ;
        if(dp[1][n]%2)
            for(int i=ans.size()-2;i>=0;i--) printf("%d%c",ans[i],i?' ':'\n') ;
        else
            for(int i=ans.size()-1;i>=0;i--) printf("%d%c",ans[i],i?' ':'\n') ;
    }
}
