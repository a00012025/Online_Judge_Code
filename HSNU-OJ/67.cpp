#include<bits/stdc++.h>
using namespace std;
const int maxn=100001 ;
struct P{int x,y;};
bool cmp(const P &a,const P &b)
{
    if(a.x!=b.x) return a.x<b.x ;
    else return a.y>b.y ;
}

vector<int> ans0 ;
int fa[maxn] ;
void get_ans(int x)
{
    if(x==-1) return ;
    get_ans(fa[x]) ;
    ans0.push_back(x) ;
}

vector<P> v ;
int head[maxn],dp[maxn] ;
vector<int> ans ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        if(x>i) continue ;
        v.push_back((P){x,i-x}) ;
    }
    sort(v.begin(),v.end(),cmp) ;
    dp[0]=0 ; head[0]=-1 ; int num=0 ;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].y >= dp[num])
        {
            fa[i]=head[num] ;
            head[num+1]=i ;
            dp[num+1]=v[i].y ;
            num++ ; continue ;
        }
        int id=upper_bound(dp,dp+num+1,v[i].y) - dp ;
        dp[id]=min(dp[id],v[i].y) ;
        fa[i]=head[id-1] ; head[id]=i ;
    }
    get_ans(head[num]) ;
    int now=0 ;
    for(int i=0;i<ans0.size();i++)
    {
        int num=v[ans0[i]].y-now ;
        for(int j=1;j<=num;j++) ans.push_back(v[ans0[i]].x+v[ans0[i]].y-j) ;
        now=v[ans0[i]].y ;
    }
    sort(ans.begin(),ans.end()) ;
    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]) ;
}
