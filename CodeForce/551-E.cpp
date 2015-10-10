#include<bits/stdc++.h>
#define INF 1000000000
#define F first
#define S second
using namespace std;
const int maxn=500000+10,maxsq=2000 ;
bool exc[maxn] ;

struct P
{
    map<int,vector<int>> mp ;
    int l,r,tag ;
    bool exc ;
    P(){tag=0 ; exc=0 ;}
    void build() ;
    void add(int L,int R,int val) ;
    void query(int &L,int &R,int val)
    {
        auto it=mp.find(val-tag) ;
        if(it==mp.end()){L=R=-1 ; return ;}
        L=maxn , R=-1 ;
        for(auto i : it->S) L=min(L,i) , R=max(R,i) ;
    }
};

int a[maxn] ;
void P::build()
{
    mp.clear() ;
    for(int i=l;i<=r;i++) if(!::exc[i])
    {
        if(INF-tag<a[i]){::exc[i]=1 ; continue ;}
        a[i]+=tag ;
        mp[a[i]].push_back(i) ;
    }
    tag=0 ;
}
void P::add(int L,int R,int val)
{
    if(this->exc) return ;
    if(l==L && r==R)
    {
        tag+=val ;
        if(tag>INF) this->exc=1 ;
        return ;
    }
    for(int i=L;i<=R;i++) if(!::exc[i])
        a[i]+=val ;
    this->build() ;
}

P p[maxsq] ;
main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    int sq=int(sqrt(n+0.5)) ;
    for(int i=0;i<n;i+=sq)
    {
        p[i/sq].l=i , p[i/sq].r=min(i+sq-1,n-1) ;
        p[i/sq].build() ;
    }
    while(Q--)
    {
        int op ; scanf("%d",&op) ;
        if(op==1)
        {
            int x,y,val ; scanf("%d%d%d",&x,&y,&val) ;
            x-- ; y-- ;
            int lb=x/sq , rb=y/sq ;
            for(int i=lb;i<=rb;i++)
                p[i].add(max(i*sq,x),min(i*sq+sq-1,y),val) ;
        }
        else
        {
            int x ; scanf("%d",&x) ;
            int ansl=-1 , ansr=-1 ;
            for(int i=0,j=0;j<n;i++,j+=sq)
            {
                int L,R ; p[i].query(L,R,x) ;
                if(L!=-1){ansl=L ; break ;}
            }
            if(ansl==-1){printf("-1\n") ; continue ;}
            for(int i=(n-1)/sq;i>=0;i--)
            {
                int L,R ; p[i].query(L,R,x) ;
                if(R!=-1){ansr=R ; break ;}
            }
            printf("%d\n",ansr-ansl) ;
        }
    }
}
