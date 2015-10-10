#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct son{int id;char type;};
vector<son> v[300] ;
map<int,int> mp ;
int cnt ;

int id(int x)
{
    if(mp.count(x)) return mp[x] ;
    cnt++ ; mp[x]=cnt ; return cnt ;
}

int dp1[400],dp2[400],root ;
bool in[400] ;
const int INF=3000 ;

bool cmp(int x,int y)
{
    return dp1[x]<dp1[y] ;
}

void dfs(int n,int res)
{
    if(v[n].empty()) {dp1[n]=dp2[n]=0 ; return ; }
    dp1[n]=dp2[n]=0 ;
    int tmp[300] , cnt2=0 ;
    for(int i=0;i<v[n].size();i++)
    {
        dfs(v[n][i].id,res) ;
        if(dp1[v[n][i].id]==INF) {dp1[n]=dp2[n]=INF ; return ;}
        if(v[n][i].type=='u') dp1[n]=max(dp1[n],dp1[v[n][i].id]+1) ;
        if(v[n][i].type=='d') dp2[n]=max(dp2[n],dp2[v[n][i].id]+1) ;
        if(v[n][i].type=='n') tmp[cnt2++]=v[n][i].id ;
    }
    if(dp1[n]+dp2[n]>res) {dp1[n]=dp2[n]=INF ; return ;}
    if(!cnt2) return ;
    sort(tmp,tmp+cnt2,cmp) ;
    int M1=INF , M2=INF ;
    //if(n==3) printf("tmp : %d,%d\n",tmp[0],tmp[1]) ;
    for(int i=0;i<=cnt2;i++)
    {
        int m1=dp1[n] , m2=dp2[n] ;
        for(int j=0;j<i;j++) m1=max(m1,dp1[tmp[j]]+1) ;
        for(int j=i;j<cnt2;j++) m2=max(m2,dp2[tmp[j]]+1) ;
        if(m1+m2<=res) {M1=min(M1,m1) ; M2=min(M2,m2) ;}
        //if(n==3) printf("%d , %d , %d\n",i,m1,m2) ;
    }
    if(M1+M2>res) {dp1[n]=dp2[n]=INF ; return ;}
    dp1[n]=M1 ; dp2[n]=M2 ;
    //printf("dp1[%d]=%d , dp2[%d]=%d\n",n,dp1[n],n,dp2[n]) ;
}

bool check(int x)
{
    dfs(root,x) ;
    //printf("x=%d\n",x) ;
    //for(int i=1;i<=cnt;i++) printf("dp1[%d]=%d , dp2[%d]=%d\n",i,dp1[i],i,dp2[i]) ;
    if(dp1[root]==INF) return 0 ;
    else return 1 ;
}

main()
{
    int x ;
    while(scanf("%d",&x)==1 && x)
    {
        for(int i=1;i<=201;i++) v[i].clear() ;
        memset(in,0,sizeof(in)) ;
        bool fir=1 ; cnt=0 ; mp.clear() ;
        while(1)
        {
            if(fir) fir=0 ;
            else scanf("%d",&x) ;
            if(!x) break ;
            x=id(x) ;
            while(1)
            {
                char t[100] ;
                scanf("%s",t) ; if(t[0]=='0') break ;
                int y ; sscanf(t,"%d",&y) ; y=id(y) ;
                int i ; for(i=0;t[i]>='0' && t[i]<='9';i++) ;
                char type ;
                type= t[i]=='\0' ? 'n' : t[i] ;
                v[x].push_back((son){y,type}) ; in[y]=1 ;
                //printf("%d : %d , %c\n",x,y,type) ;
            }
        }
        for(root=1;root<=cnt && in[root];root++) ;
        int l=0 , r=cnt ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(check(mid)) r=mid ;
            else l=mid ;
        }
        printf("%d\n",r+1) ;
    }
}
