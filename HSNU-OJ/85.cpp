#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;
struct P{int x,y ;}a[3*maxn];
struct Q{int sz ; LL val ; }ST[8*maxn];
bool cmp(const P &a,const P &b)
{
    if(a.y!=b.y) return a.y<b.y ;
    else return a.x<b.x ;
}

int num[maxn] ;

void build(int l,int r,int id)
{
    if(l==r) { ST[id].sz=num[l] ; ST[id].val=((LL)num[l])*((LL)l) ; return ; }
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
    ST[id].sz=ST[2*id].sz+ST[2*id+1].sz ;
    ST[id].val=ST[2*id].val+ST[2*id+1].val ;
}

void modify(int l,int r,int id,int pos)
{
    if(l==r) { ST[id].sz-- ; ST[id].val-=l ; return ; }
    int mid=(l+r)/2 ;
    if(pos<=mid) modify(l,mid,2*id,pos) ;
    else modify(mid+1,r,2*id+1,pos) ;
    ST[id].sz=ST[2*id].sz+ST[2*id+1].sz ;
    ST[id].val=ST[2*id].val+ST[2*id+1].val ;
}

void search(int l,int r,int id,int res,int &now,LL nowval)
{
    if(l==r)
    {
        int lo=0 , hi=ST[id].sz ;
        if(nowval + ((LL)hi)*((LL)l) <= ((LL)res)*((LL)now+hi) )
        {
            now+=hi ; return ;
        }
        while(hi-lo>1)
        {
            int mid=(hi+lo)/2 ;
            if(nowval + ((LL)mid)*((LL)l) <= ((LL)res)*((LL)now+mid) )
                lo=mid ;
            else hi=mid ;
        }
        now+=lo ; return ;
    }
    int mid=(l+r)/2 ;
    if(nowval+ST[2*id].val <= ((LL)now+ST[2*id].sz)*((LL)res) )
    {
        now+=ST[2*id].sz ;
        nowval+=ST[2*id].val ;
        search(mid+1,r,2*id+1,res,now,nowval) ;
    }
    else search(l,mid,2*id,res,now,nowval) ;
}

main()
{
    memset(num,0,sizeof(num)) ;
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y) ;
        num[a[i].x]++ ;
    }
    sort(a+1,a+n+1,cmp) ;
    build(1,maxn,1) ;
    int ans=0 ;
    for(int i=1;i<=n;)
    {
        int ans2=0 ;
        search(1,maxn,1,a[i].y,ans2,0LL) ;
        ans=max(ans,ans2) ;
        int tmp=a[i].y ;
        for(;i<=n && a[i].y==tmp;i++) modify(1,maxn,1,a[i].x) ;
    }
    printf("%d\n",ans) ;
}
