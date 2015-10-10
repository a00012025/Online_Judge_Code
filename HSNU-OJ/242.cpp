#include<bits/stdc++.h>
#define pii pair<int,int>
#define MKP(x,y) make_pair(x,y)
#define F first
#define S second
using namespace std;
const int maxn=100000+10 ;

bool ST[8*maxn] ;
void modify(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) { ST[id]=1 ; return ; }
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,2*id) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1) ;
    else
    {
        modify(l,mid,L,mid,2*id) ;
        modify(mid+1,r,mid+1,R,2*id+1) ;
    }
}

bool query(int L,int R,int id,int pos)
{
    if(ST[id] || L==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(pos<=mid) return query(L,mid,2*id,pos) ;
    else return query(mid+1,R,2*id+1,pos) ;
}

pii a[maxn],st[maxn] ;
int cor[maxn],L[maxn],R[maxn],need1[maxn],need2[maxn] ;

main()
{
    int n,k,m ; scanf("%d%d%d",&n,&k,&m) ;
    int cnt=0 ;
    while(m--)
    {
        int l,r,c ; scanf("%d%d%d",&l,&r,&c) ;
        if(c==0) modify(l,r,1,n,1) ;
        else a[cnt++]=MKP(l,r) ;
    }

    int num=0 ;
    for(int i=1;i<=n;i++) if(!query(1,n,1,i)) cor[num++]=i ;
    if(num==k)
    {
        for(int i=0;i<num;i++) printf("%d\n",cor[i]) ;
        return 0 ;
    }

    int cnt2=0 ;
    for(int i=0;i<cnt;i++)
    {
        int l=lower_bound(cor,cor+num,a[i].F) - cor ;
        int r=upper_bound(cor,cor+num,a[i].S) - cor - 1 ;
        if(l!=num && l<=r) a[cnt2++]=MKP(l,r) ;
    }

    sort(a,a+cnt2) ;
    int cnt3=0 ;
    for(int i=0;i<cnt2;i++)
    {
        if(cnt3 && st[cnt3-1].F==a[i].F) continue ;
        while(cnt3 && st[cnt3-1].S>=a[i].S) cnt3-- ;
        st[cnt3++]=a[i] ;
    }
    for(int i=0;i<cnt3;i++) a[i]=st[i] , L[i]=a[i].F , R[i]=a[i].S ;

    need1[0]=1 ;
    for(int i=1;i<cnt3;i++)
    {
        int id=lower_bound(R,R+cnt3,a[i].F) - R - 1 ;
        need1[i]= id==-1 ? 1 : need1[id]+1 ;
    }

    need2[cnt3]=0 ;
    for(int i=cnt3-1;i>=0;i--)
    {
        int id= upper_bound(L,L+cnt3,a[i].S) - L ;
        need2[i]=need2[id]+1 ;
    }

    int nowl=-1 , nowr=0 , nowid=0 ;
    bool found=0 ;
    for(int i=0;i<num;i++)
    {
        while(nowl<cnt3-1 && a[nowl+1].S < i) nowl++ ;
        while(nowr<cnt3 && a[nowr].F<=i) nowr++ ;
        int need= nowl==-1 ? need2[nowr] : need1[nowl]+need2[nowr] ;
        while(need<k && nowid<cnt3 && i>=a[nowid].F && i<=a[nowid].S)
        {
            if(i==a[nowid].S) printf("%d\n",cor[i]) , found=1 ;
            nowid++ ;
        }
    }
    if(!found) printf("-1\n") ;
}
