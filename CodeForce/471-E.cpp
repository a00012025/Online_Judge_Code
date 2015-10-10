#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200000+10 ;

int fa[maxn] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}
inline void join(int x,int y){fa[getfa(x)]=getfa(y);}

struct node
{
    node *l,*r ;
    int id,size,val,fix,tag ;
    node(int _v,int _id)
    {
        l=r=NULL ;
        val=_v ; id=_id ;
        fix=rand() ; tag=0 ; size=1 ;
    }
};

inline int size(node *u){return u ? u->size : 0 ;}
inline void pull(node *u){if(u) u->size=size(u->l)+size(u->r)+1 ;}
void push(node *u)
{
    if(!u->tag) return ;
    if(u->l)
    {
        if(u->l->tag) join(u->tag,u->l->tag) ;
        else u->l->tag=u->tag , join(u->tag,u->l->id) ;
    }
    if(u->r)
    {
        if(u->r->tag) join(u->tag,u->r->tag) ;
        else u->r->tag=u->tag , join(u->tag,u->r->id) ;
    }
    u->tag=0 ;
}

node *merge(node *a,node *b)
{
    if(!a||!b) return a ? a : b ;
    if(a->fix<b->fix)
    {
        push(a) ;
        a->r=merge(a->r,b) ;
        pull(a) ;
        return a ;
    }
    else
    {
        push(b) ;
        b->l=merge(a,b->l) ;
        pull(b) ;
        return b ;
    }
}

void split(node *u,node *&a,node *&b,int k) /// a : <=k , b : >k
{
    if(!u){a=b=NULL ; return ;}
    push(u) ;
    if(u->val<=k)
    {
        a=u ;
        split(u->r,a->r,b,k) ;
        pull(a) ;
    }
    else
    {
        b=u ;
        split(u->l,a,b->l,k) ;
        pull(b) ;
    }
}

node *root=NULL ;
void erase(int val)
{
    node *a,*b,*c ;
    split(root,a,b,val-1) ;
    split(b,b,c,val) ;
    root=merge(a,c) ;
}

void insert(int val,int id)
{
    node *a,*b ;
    split(root,a,b,val) ;
    root=merge(merge(a,new node(val,id)),b) ;
}

struct P
{
    int x1,y1,x2,y2,id ;
    void scan(int _id)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
        id=_id ;
        if(x1>x2||y1>y2) swap(x1,x2) , swap(y1,y2) ;
    }
    bool operator < (const P &rhs) const
    {
        if(x1==x2) return x1==rhs.x1 ? y1<rhs.y1 : x1<rhs.x1 ;
        else return y1==rhs.y1 ? x1<rhs.x1 : y1<rhs.y1 ;
    }
};

inline void norm(vector<int> &v)
{
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
}
inline int ID(vector<int> &v,int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin() ;
}

vector<int> corx,cory ; /// coordinate
vector<P> segx,segy ;
void delete_seg(vector<P> &v,int t)
{
    sort(v.begin(),v.end()) ;
    int j=1 ;
    for(int i=1;i<v.size();i++)
    {
        if(!t&&v[j-1].x1!=v[i].x1){v[j++]=v[i] ; continue ;}
        if(t &&v[j-1].y1!=v[i].y1){v[j++]=v[i] ; continue ;}
        if(!t&&v[i].y1<=v[j-1].y2)
            v[j-1].y2=max(v[j-1].y2,v[i].y2) ;
        else if(t &&v[i].x1<=v[j-1].x2)
            v[j-1].x2=max(v[j-1].x2,v[i].x2) ;
        else v[j++]=v[i] ;
    }
    v.resize(j) ;
}

void precal()
{
    for(auto i : segx)
        corx.push_back(i.x1) ,
        cory.push_back(i.y1) , cory.push_back(i.y2) ;
    for(auto i : segy)
        cory.push_back(i.y1) ,
        corx.push_back(i.x1) , corx.push_back(i.x2) ;
    norm(corx) ; norm(cory) ;
    for(auto &i : segx)
        i.x1=i.x2=ID(corx,i.x1) ,
        i.y1=ID(cory,i.y1) , i.y2=ID(cory,i.y2) ;
    for(auto &i : segy)
        i.y1=i.y2=ID(cory,i.y1) ,
        i.x1=ID(corx,i.x1) , i.x2=ID(corx,i.x2) ;
    delete_seg(segx,0) ;
    delete_seg(segy,1) ;
}

struct event
{
    int x,y,id,type ;
    bool operator < (const event &rhs) const
    {
        return y==rhs.y ? type<rhs.type : y<rhs.y ;
    }
}ev[2*maxn];

inline void process_event(const event &e)
{
    if(e.type==0) insert(e.x,e.id) ;
    else erase(e.x) ;
}

int cover[maxn] ;
LL num[maxn],ans ;
main()
{
    srand(time(NULL)) ;
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        P p ; p.scan(i) ;
        if(p.x1==p.x2) segx.push_back(p) ;
        else segy.push_back(p) ;
    }
    precal() ;
    for(auto i : segx) ans=max(ans,(LL)cory[i.y2]-cory[i.y1]) ;
    for(auto i : segy) ans=max(ans,(LL)corx[i.x2]-corx[i.x1]) ;

    for(int i=1;i<=n;i++) fa[i]=i ;
    int ecnt=0 ;
    for(auto i : segx)
        ev[ecnt++]=(event){i.x1,i.y1,i.id,0} ,
        ev[ecnt++]=(event){i.x1,i.y2,i.id,1} ;
    sort(ev,ev+ecnt) ;

    node *a,*b,*c ;
    int j=0 ;
    for(int i=0;i<segy.size();i++)
    {
        int nowy=segy[i].y1 ;
        while(j<ecnt &&
            (ev[j].y<nowy || (ev[j].y==nowy && !ev[j].type)))
            process_event(ev[j++]) ;

        split(root,a,b,segy[i].x1-1) ;
        split(b,b,c,segy[i].x2) ;
        cover[segy[i].id]=size(b) ;
        if(b)
        {
            if(b->tag) join(b->tag,segy[i].id) ;
            else b->tag=segy[i].id , join(b->id,b->tag) ;
        }
        root=merge(merge(a,b),c) ;
    }
    while(j<ecnt) process_event(ev[j++]) ;

    for(auto i : segx) num[getfa(i.id)]+=cory[i.y2]-cory[i.y1]+1 ;
    for(auto i : segy) num[getfa(i.id)]+=corx[i.x2]-corx[i.x1]+1-cover[i.id] ;
    for(int i=1;i<=n;i++) ans=max(ans,num[i]-1) ;
    printf("%lld\n",ans) ;
}
