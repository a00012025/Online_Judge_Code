#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=200001 ;
LL ST[8*maxn],tag1[8*maxn],tag2[8*maxn] ;
LL tag[8*maxn] ;

void build(int l,int r,int id)
{
    ST[id]=0LL ;
    tag1[id]=tag2[id]=-INF ;
    if(l==r) return ;
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
}

vector<LL> v ;
void push_down1(int L,int R,int id)
{
    int mid=(L+R)/2 ;
    ST[2*id]= max( tag1[id]*v[L]+tag2[id] , tag1[id]*v[mid]+tag2[id] ) ;
    ST[2*id+1]= max( tag1[id]*v[mid+1]+tag2[id] , tag1[id]*v[R]+tag2[id] ) ;
    tag1[2*id]=tag1[2*id+1]=tag1[id] ;
    tag2[2*id]=tag2[2*id+1]=tag2[id] ;
    tag1[id]=tag2[id]=-INF ;
    tag[2*id]=tag[2*id+1]=0 ;
}

void push_down2(int L,int R,int id)
{
    ST[2*id]+=tag[id] ;
    ST[2*id+1]+=tag[id] ;
    tag[2*id]+=tag[id] ;
    tag[2*id+1]+=tag[id] ;
    tag[id]=0 ;
}

void add(int l,int r,int L,int R,int id,LL val)
{
    if(l==L && r==R)
    {
        if(tag1[id]!=-INF) tag2[id]+=val ;
        else tag[id]+=val ;
        ST[id]+=val ;
        return ;
    }
    if(tag1[id]!=-INF) push_down1(L,R,id) ;
    if(tag[id]) push_down2(L,R,id) ;

    int mid=(L+R)/2 ;
    if(r<=mid) add(l,r,L,mid,2*id,val) ;
    else if(l>mid) add(l,r,mid+1,R,2*id+1,val) ;
    else
    {
        add(l,mid,L,mid,2*id,val) ;
        add(mid+1,r,mid+1,R,2*id+1,val) ;
    }
    ST[id]=max(ST[2*id],ST[2*id+1]) ;
}

LL query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id] ;
    if(tag1[id]!=-INF) push_down1(L,R,id) ;
    if(tag[id]) push_down2(L,R,id) ;

    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    else return max(query(l,mid,L,mid,2*id),query(mid+1,r,mid+1,R,2*id+1)) ;
}

void set_linear(int l,int r,int L,int R,int id,LL a,LL b)
{
    if(l==L && r==R)
    {
        tag1[id]=a ;
        tag2[id]=b ;
        tag[id]=0 ;
        ST[id]= max( tag1[id]*v[L]+tag2[id] , tag1[id]*v[R]+tag2[id] ) ;
        return ;
    }
    if(tag1[id]!=-INF) push_down1(L,R,id) ;
    if(tag[id]) push_down2(L,R,id) ;

    int mid=(L+R)/2 ;
    if(r<=mid) set_linear(l,r,L,mid,2*id,a,b) ;
    else if(l>mid) set_linear(l,r,mid+1,R,2*id+1,a,b) ;
    else
    {
        set_linear(l,mid,L,mid,2*id,a,b) ;
        set_linear(mid+1,r,mid+1,R,2*id+1,a,b) ;
    }
    ST[id]=max(ST[2*id],ST[2*id+1]) ;
}

struct event{int type,l,r ; LL x ;}; /// type=1 : Q , type=2 : modify
vector<event> Q ;

int search_in_v(LL val)
{
    int l=0 , r=v.size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(v[mid]>val) r=mid ;
        else l=mid ;
    }
    return l ;
}

main()
{
    int n ; char c[3] ;
    scanf("%d",&n) ;
    while(scanf("%s",c)==1 && c[0]!='E')
    {
        if(c[0]=='Q')
        {
            LL x ; scanf("%I64d",&x) ;
            Q.push_back((event){1,0,0,x}) ;
        }
        else
        {
            int l,r ; LL x ; scanf("%d%d%I64d",&l,&r,&x) ;
            Q.push_back((event){2,l,r,x}) ;
            v.push_back((LL)l-1) ;
            v.push_back((LL)r) ;
        }
    }

    v.push_back((LL)n) ;
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
    for(int i=0;i<Q.size();i++) if(Q[i].type==2)
        Q[i].l = search_in_v((LL)(Q[i].l)-1) ,
        Q[i].r = search_in_v((LL)Q[i].r) ;
    int num=((int)v.size())-1 ; /// 0 ~ num
    build(0,num,1) ;
    for(int i=0;i<Q.size();i++)
    {
        event &u=Q[i] ;
        if(u.type==1)
        {
            int l=0 , r=num+1 ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ;
                if(query(0,mid,0,num,1)<=u.x) l=mid ;
                else r=mid ;
            }
            if(l==num) { printf("%d\n",n) ; continue ; }

            LL h1=query(l,l,0,num,1) , h2=query(r,r,0,num,1) ;
            LL t = (h2-h1) / (v[r]-v[l]) ;
            printf("%I64d\n", v[l] + ((u.x-h1)/t) ) ;
        }
        else
        {
            LL h1=query(u.l,u.l,0,num,1) ;
            LL h2=query(u.r,u.r,0,num,1) ;
            LL newh= h1+(v[u.r]-v[u.l])*u.x ;
            debugf("h1=%I64d , h2=%I64d , newh=%I64d\n",h1,h2,newh) ;
            add(u.r,num,0,num,1,newh-h2) ;
            set_linear(u.l,u.r,0,num,1,u.x,h1-v[u.l]*u.x) ;
        }
    }
}
