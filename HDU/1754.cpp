#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
const int maxn=1400000 ;
int left[maxn],right[maxn],val[maxn],fix[maxn] ;
int weight[maxn],cnt,root[1200005] ;
int ST[1100005] ;

int newnode(int value)
{
    int u=++cnt ; right[u]=left[u]=0 ;
    val[u]=value ; fix[u]=rand() ; weight[u]=1 ;
    return u ;
}

struct Treap
{
    void right_rotate(int &u)
    {
        int v=left[u] ;
        left[u]=right[v] ;
        right[v]=u ;
        u=v ;
    }

    void left_rotate(int &u)
    {
        int v=right[u] ;
        right[u]=left[v] ;
        left[v]=u ;
        u=v ;
    }

    void insert(int &u,int value)
    {
        if(!u) u=newnode(value) ;
        else if(val[u]>value)
        {
            insert(left[u],value) ;
            if(fix[left[u]]<fix[u]) right_rotate(u) ;
        }
        else if(val[u]<value)
        {
            insert(right[u],value) ;
            if(fix[right[u]]<fix[u]) left_rotate(u) ;
        }
        else weight[u]++ ;
    }

    void erase(int &u,int value)
    {
        if(!u) return ;
        if(val[u]==value)
        {
            if(!left[u]) {weight[u]-- ; if(!weight[u]) u=right[u] ; }
            else if(!right[u]) {weight[u]-- ; if(!weight[u]) u=left[u] ; }
            else
            {
                if(fix[left[u]]<fix[right[u]])
                {
                    right_rotate(u) ;
                    erase(right[u],value) ;
                }
                else
                {
                    left_rotate(u) ;
                    erase(left[u],value) ;
                }
            }
        }
        else if(val[u]>value) erase(left[u],value) ;
        else erase(right[u],value) ;
    }

    int find_max(int &u) {return right[u] ? find_max(right[u]) : val[u] ; }
}trp[maxn];

int a[200001] ;
void build_ST(int l,int r,int id)
{
    if(l!=r)
    {
        int mid=(l+r)/2 ;
        build_ST(l,mid,2*id) ;
        build_ST(mid+1,r,2*id+1) ;
    }
    root[id]=0 ;
    for(int i=l;i<=r;i++) trp[id].insert(root[id],a[i]) ;
}

void modify(int l,int r,int id,int pos,int newval)
{
    trp[id].erase(root[id],a[pos]) ;
    trp[id].insert(root[id],newval) ;
    if(l==r) return ;
    int mid=(l+r)/2 ;
    if(pos<=mid) modify(l,mid,2*id,pos,newval) ;
    else modify(mid+1,r,2*id+1,pos,newval) ;
}

int query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return trp[id].find_max(root[id]) ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    else return std::max(query(l,mid,L,mid,2*id),query(mid+1,r,mid+1,R,2*id+1)) ;
}

main()
{
    srand(time(NULL)) ;
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cnt=0 ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        build_ST(1,n,1) ;
        while(m--)
        {
            char c[3] ; int x,y ;
            scanf("%s%d%d",c,&x,&y) ;
            if(c[0]=='U')
            {
                modify(1,n,1,x,y) ;
                a[x]=y ;
            }
            else printf("%d\n",query(x,y,1,n,1)) ;
        }
    }
}
