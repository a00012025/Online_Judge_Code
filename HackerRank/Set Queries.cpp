#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000009
using namespace std;
const int maxn=100000+10 , maxk=350+10 ;
inline void up(LL &a,LL b){a=(a+b)%MOD ;}

int sq ;
LL bls[maxk],bltag[maxn] ; /// block sum , block tag
LL a[maxn] ;
void modify0(int l,int r,LL ad,int id)
{
    int L=id*sq , R=L+sq-1 ;
    if(l==L && r==R)
    {
        up(bltag[id],ad) ;
        up(bls[id],ad*(R-L+1)) ;
        return ;
    }
    for(int i=l;i<=r;i++) up(a[i],ad) ;
    up(bls[id],ad*(r-l+1)) ;
}

void modify(int l,int r,LL ad)
{
    l-- ; r-- ;
    int lb=l/sq , rb=r/sq ;
    for(int i=lb;i<=rb;i++) modify0(max(i*sq,l),min((i+1)*sq-1,r),ad,i) ;
}

LL query0(int l,int r,int id)
{
    int L=id*sq , R=L+sq-1 ;
    if(l==L && r==R) return bls[id] ;
    LL ret=bltag[id]*(r-l+1) ;
    for(int i=l;i<=r;i++) up(ret,a[i]) ;
    return ret ;
}

LL query(int l,int r)
{
    l-- ; r-- ;
    int lb=l/sq , rb=r/sq ;
    LL ret=0 ;
    for(int i=lb;i<=rb;i++) up(ret,query0(max(i*sq,l),min((i+1)*sq-1,r),i)) ;
    return ret ;
}

int sum[maxk][maxn] ;
inline int getnum(int l,int r,int id)
{
    return sum[id][r]-sum[id][l-1] ;
}

int inter[maxn][maxk] ;
LL val[maxk],ans[maxk] ;
vector<int> v[maxn] ; /// small , big
vector<int> big ;
int sid[maxn] ;
int cnt[maxn] ;

int main()
{
//    freopen("in","r",stdin) ;
//    freopen("out","w",stdout) ;
    int n,S,Q ; scanf("%d%d%d",&n,&S,&Q) ;
    sq=int(sqrt(n+0.5)) ;
    int cnt1=0 , cnt2=0 ;
    for(int i=1;i<=S;i++)
    {
        int x,y ; scanf("%d",&x) ;
        while(x--) scanf("%d",&y) , v[i].push_back(y) ;
        sort(v[i].begin(),v[i].end()) ;
        sid[i]=(v[i].size()>=sq ? cnt1++ : cnt2++) ;
        if(v[i].size()>=sq)
        {
            big.push_back(i) ;
            for(auto j : v[i]) sum[cnt1-1][j]++ ;
            for(int j=1;j<=n;j++) sum[cnt1-1][j]+=sum[cnt1-1][j-1] ;
        }
    }

    for(int i=1;i<=S;i++) if(v[i].size()>=sq)
    {
        fill(cnt+1,cnt+n+1,0) ;
        int id=sid[i] ;
        for(auto j : v[i]) cnt[j]=1 ;
        for(int j=1;j<=S;j++) for(auto k : v[j])
            inter[j][id]+=cnt[k] ;
    }

    while(Q--)
    {
        int op,x,l,r ; LL t ; scanf("%d",&op) ;
        if(op==1)
        {
            scanf("%d%lld",&x,&t) ;
            if(v[x].size()>=sq) up(val[sid[x]],t) ;
            else for(auto i : v[x]) modify(i,i,t) ;
            for(auto i : big) up(ans[sid[i]],t*inter[x][sid[i]]) ;
        }
        else if(op==2)
        {
            scanf("%d",&x) ;
            if(v[x].size()>=sq){printf("%lld\n",ans[sid[x]]) ; continue ;}
            LL ANS=0 ;
            for(auto i : v[x]) up(ANS,query(i,i)) ;
            for(int i=0;i<cnt1;i++) up(ANS,val[i]*inter[x][i]) ;
            printf("%lld\n",ANS) ;
        }
        else if(op==3)
        {
            scanf("%d%d%lld",&l,&r,&t) ;
            modify(l,r,t) ;
            for(auto i : big) up(ans[sid[i]],getnum(l,r,sid[i])*t) ;
        }
        else
        {
            scanf("%d%d",&l,&r) ;
            LL ANS=query(l,r) ;
            for(auto i : big) up(ANS,getnum(l,r,sid[i])*val[sid[i]]) ;
            printf("%lld\n",ANS) ;
        }
    }
}
