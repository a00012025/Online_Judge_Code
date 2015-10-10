#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
const int maxn=100000+100 ;

int ST[20*maxn],left[20*maxn],right[20*maxn] ;
int cnt,a[maxn],root[maxn] ;

void build_tree(int l,int r,int id)
{
    if(l==r) {ST[id]=0 ; return ; }
    left[id]=++cnt , right[id]=++cnt ;
    int mid=(l+r)/2 ;
    build_tree(l,mid,left[id]) ;
    build_tree(mid+1,r,right[id]) ;
    ST[id]=0 ;
}

vector<int> tmp ;

int find_in_v(int x)
{
    int l=0 , r=tmp.size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(tmp[mid]>x) r=mid ;
        else l=mid ;
    }
    return l ;
}

void tree_insert(int l,int r,int old,int newp,int val)
{
    //debugf("insert %d,%d\n",l,r) ;
    if(l==r) { ST[newp]=ST[old]+1 ; return ; }
    int mid=(l+r)/2 ;
    if(val<=mid)
    {
        left[newp]=++cnt ; right[newp]=right[old] ;
        tree_insert(l,mid,left[old],left[newp],val) ;
        ST[newp]=ST[left[newp]]+ST[right[newp]] ;
    }
    else
    {
        right[newp]=++cnt ; left[newp]=left[old] ;
        tree_insert(mid+1,r,right[old],right[newp],val) ;
        ST[newp]=ST[left[newp]]+ST[right[newp]] ;
    }
}

int query(int l,int r,int k,int id1,int id2)
{
    if(l==r) return l ;
    int mid=(l+r)/2 ;
    if(ST[left[id2]]-ST[left[id1]]>=k) return query(l,mid,k,left[id1],left[id2]) ;
    else return query(mid+1,r,k-(ST[left[id2]]-ST[left[id1]]),right[id1],right[id2]) ;
}

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) , tmp.push_back(a[i]) ;
        sort(tmp.begin(),tmp.end()) ;
        tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin()) ;
        for(int i=1;i<=n;i++) a[i]=find_in_v(a[i]) , debugf("a[%d]=%d\n",i,a[i]) ;
        int n2=tmp.size() ; debugf("n2=%d\n",n2) ;
        root[0]=1 ; cnt=1 ;
        build_tree(0,n2-1,1) ;
        for(int i=1;i<=n;i++)
        {
            root[i]=++cnt ;
            tree_insert(0,n2-1,root[i-1],root[i],a[i]) ;
            debugf("size = %d\n",ST[root[i]]) ;
        }
        while(m--)
        {
            int l,r,k ; scanf("%d%d%d",&l,&r,&k) ;
            printf("%d\n",tmp[query(0,n2-1,k,root[l-1],root[r])]) ;
        }
    }
}

