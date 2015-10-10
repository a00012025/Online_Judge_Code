#include<stdio.h>
#include<algorithm>
#include<vector>
#define INF 1000000001
using namespace std;
const int maxn=100000+5 ;
int left[20*maxn],right[20*maxn],root[maxn],ROOT[maxn] ;
int llen[20*maxn],rlen[20*maxn],len[20*maxn] ;
int cnt ;

int a[maxn] ;
vector<int> tmp ;

int find_in_v(int x)
{
    int l=0,r=tmp.size() ;
    if(tmp[0]>=x) return 0 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(tmp[mid]>=x) r=mid ;
        else l=mid ;
    }
    return r ;
}

void build_ST(int l,int r,int id)
{
    if(l==r) {llen[id]=rlen[id]=len[id]=0 ; return ; }
    int mid=(l+r)/2 ;
    left[id]=++cnt ; right[id]=++cnt ;
    build_ST(l,mid,left[id]) ;
    build_ST(mid+1,r,right[id]) ;
    llen[id]=rlen[id]=len[id]=0 ;
}

void tree_insert(int l,int r,int old,int newp,int pos)
{
    if(l==r) {llen[newp]=rlen[newp]=len[newp]=1 ; return ; }
    int mid=(l+r)/2 ;
    if(pos<=mid)
    {
        left[newp]=++cnt ; right[newp]=right[old] ;
        tree_insert(l,mid,left[old],left[newp],pos) ;
    }
    else
    {
        right[newp]=++cnt ; left[newp]=left[old] ;
        tree_insert(mid+1,r,right[old],right[newp],pos) ;
    }
    llen[newp]= llen[left[newp]]==mid-l+1 ? mid-l+1+llen[right[newp]] : llen[left[newp]] ;
    rlen[newp]= rlen[right[newp]]==r-mid ? r-mid+rlen[left[newp]] : rlen[right[newp]] ;
    len[newp]= max( max(len[left[newp]],len[right[newp]]) ,
                    rlen[left[newp]]+llen[right[newp]] ) ;
}

vector<int> tmp2[maxn] ;
int n,sum[maxn] ;
void pre_cal()
{
    sort(tmp.begin(),tmp.end()) ;
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin()) ;
    int m=tmp.size() ;
    for(int i=1;i<=n;i++) a[i]=find_in_v(a[i]) ;

    for(int i=1;i<=n;i++) tmp2[a[i]].push_back(i) ;

    root[0]=cnt++ ; ROOT[tmp.size()]=root[0] ;
    build_ST(1,n,root[0]) ;
    int mod_num=0 ;
    for(int i=tmp.size()-1;i>=0;i--)
    {
        for(int j=0;j<tmp2[i].size();j++)
        {
            mod_num++ ;
            root[mod_num]=++cnt ;
            tree_insert(1,n,root[mod_num-1],root[mod_num],tmp2[i][j]) ;
        }
        ROOT[i]=root[mod_num] ;
    }
}

int query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return len[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,left[id]) ;
    else if(l>mid) return query(l,r,mid+1,R,right[id]) ;
    else
    {
        int ret=max(query(l,mid,L,mid,left[id]),query(mid+1,r,mid+1,R,right[id])) ;
        int l_len= mid-rlen[left[id]]+1<l ? mid-l+1 : rlen[left[id]] ;
        int r_len= mid+1+llen[right[id]]-1>r ? r-mid : llen[right[id]] ;
        ret=max(ret,l_len+r_len) ;
        return ret ;
    }
}

main()
{
    scanf("%d",&n) ;
    cnt=0 ; tmp.clear() ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , tmp.push_back(a[i]) ;
    pre_cal() ;

    int m ; scanf("%d",&m) ;
    while(m--)
    {
        int L,R,W ; scanf("%d%d%d",&L,&R,&W) ;
        int l=0 , r=INF ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            int id=find_in_v(mid) ;
            int maxlen=query(L,R,1,n,ROOT[id]) ;
            if(maxlen>=W) l=mid ;
            else r=mid ;
        }
        printf("%d\n",l) ;
    }
}
