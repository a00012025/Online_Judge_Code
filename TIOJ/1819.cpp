#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

int l[maxn],r[maxn] ;
vector<int> v ;

int ST[12*maxn] ;
int tag[12*maxn],le[12*maxn],ri[12*maxn] ;

inline void pushdown(int id)
{
    if(!tag[id]) return ;
    ST[2*id]+=1-le[2*id]-ri[2*id] ;
    tag[2*id]^=1 ;
    le[2*id]^=1 , ri[2*id]^=1 ;

    ST[2*id+1]+=1-le[2*id+1]-ri[2*id+1] ;
    tag[2*id+1]^=1 ;
    le[2*id+1]^=1 , ri[2*id+1]^=1 ;

    tag[id]=0 ;
}

void modify(int l,int r,int L,int R,int id)
{
    if(l==L && r==R)
    {
        ST[id]+=1-le[id]-ri[id] ;
        tag[id]^=1 ;
        le[id]^=1 , ri[id]^=1 ;
        return ;
    }
    pushdown(id) ;

    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,2*id) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1) ;
    else
    {
        modify(l,mid,L,mid,2*id) ;
        modify(mid+1,r,mid+1,R,2*id+1) ;
    }

    ST[id]=ST[2*id]+ST[2*id+1] ;
    le[id]=le[2*id] ; ri[id]=ri[2*id+1] ;
    if(ri[2*id] && le[2*id+1]) ST[id]-- ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    v.push_back(m) ; v.push_back(1) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]) ,
        v.push_back(l[i]) , v.push_back(r[i]) ;
        if(l[i]>r[i]) swap(l[i],r[i]) ;
        if(l[i]!=1) v.push_back(l[i]-1) ;
        if(r[i]!=m) v.push_back(r[i]+1) ;
    }
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
    m=v.size()-1 ;
    for(int i=1;i<=n;i++)
        l[i]=lower_bound(v.begin(),v.end(),l[i])-v.begin() ,
        r[i]=lower_bound(v.begin(),v.end(),r[i])-v.begin() ;

    int ans=0 ;
    for(int i=1;i<=n;i++)
    {
        modify(l[i],r[i],0,m,1) ;
        ans=max(ans,ST[1]) ;
//        printf("now = %d\n",ST[1]) ;
    }
    printf("%d\n",ans) ;
}
