#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#define INF 1000000000.0
using namespace std;
map<vector<int>,int > mp ;
vector<vector<int> > state ;
double start,price[9][105],dp[105][15000] ;
int n,m,RES,res[10] ;
char name[9][105] ;

void dfs(vector<int> &v,int x,int num)
{
    if(x==m)
    {
        int sz=state.size() ;
        mp[v]=sz ; state.push_back(v) ; return ;
    }
    for(int i=0;i<=res[x] && num+i<=RES;i++)
    {
        v[x]=i ;
        dfs(v,x+1,num+i) ;
    }
}

void find_state()
{
    vector<int> v(m) ;
    dfs(v,0,0) ;
}

int buy_next[15000][9],sell_next[15000][9] ;
void init()
{
    state.clear() ; mp.clear() ;
    find_state() ;
    for(int i=0;i<state.size();i++)
    {
        int now_num=0 ;
        for(int k=0;k<m;k++) now_num+=state[i][k] ;
        for(int j=0;j<m;j++)
        {
            buy_next[i][j]=sell_next[i][j]=-1 ;
            if(state[i][j]<res[j] && now_num<RES)
            {
                vector<int> v=state[i] ; v[j]++ ;
                buy_next[i][j]=mp[v] ;
            }
            if(state[i][j]>0)
            {
                vector<int> v=state[i] ; v[j]-- ;
                sell_next[i][j]=mp[v] ;
            }
        }
    }
}

int fa[105][15000],type[105][15000] ;
void update_ans(int i,int s1,int s2,double new_val,int tp)
{
    if(new_val <= dp[i+1][s2]) return ;
    dp[i+1][s2]=new_val ;
    fa[i+1][s2]=s1 ; type[i+1][s2]=tp ;
}

void print_ans(int x,int s)
{
    if(x==0) return ;
        //printf("fa[%d][%d]=%d\n",x,s,fa[x][s]) ;
    print_ans(x-1,fa[x][s]) ;
    if(type[x][s]==0) printf("HOLD\n") ;
    else if(type[x][s]>0) printf("BUY %s\n",name[type[x][s]-1]) ;
    else printf("SELL %s\n",name[-type[x][s]-1]) ;
}

main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;
    bool fir=1 ;
    while(scanf("%lf%d%d%d",&start,&n,&m,&RES)!=EOF)
    {
        for(int i=0;i<m;i++)
        {
            double mul ;
            scanf("%s%lf%d",name[i],&mul,&res[i]) ;
            for(int j=0;j<n;j++)
            {
                scanf("%lf",&price[i][j]) ;
                price[i][j] *= mul ;
            }
        }
        init() ;
        for(int i=0;i<=n;i++) for(int j=0;j<state.size();j++)
            dp[i][j]=-INF ;
        dp[0][0]=start ;
        for(int i=0;i<n;i++) for(int j=0;j<state.size();j++)
        {
            if(dp[i][j] < -1) continue ;
            update_ans(i,j,j,dp[i][j],0) ;
            for(int k=0;k<m;k++)
            {
                if(dp[i][j]>=price[k][i]-(1e-3) && buy_next[j][k]>=0)
                    update_ans(i,j,buy_next[j][k],dp[i][j]-price[k][i],k+1) ;

                if(sell_next[j][k]>=0)
                    update_ans(i,j,sell_next[j][k],dp[i][j]+price[k][i],-k-1) ;
            }
        }
        if(fir) fir=0 ;
        else printf("\n") ;
            printf("%d\n",state.size()) ;
        printf("%.2lf\n",dp[n][0]) ;
        print_ans(n,0) ;
    }
}
