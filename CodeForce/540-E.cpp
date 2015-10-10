#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200000+10 ;

struct P{int x,y;}a[maxn];
vector<int> v ;

int b[maxn],b2[maxn],tmp[maxn] ;
LL ans=0LL ;
void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ; mer(mid+1,r) ;
    for(int i=l,j=mid+1,cnt=l;cnt<=r;)
    {
        if(i==mid+1 || (j!=r+1 && b[j]<b[i]))
            tmp[cnt++]=b[j++] ,
            ans+=mid+1-i ;
        else tmp[cnt++]=b[i++] ;
    }
    for(int i=l;i<=r;i++) b[i]=tmp[i] ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y) ;
        v.push_back(a[i].x) ;
        v.push_back(a[i].y) ;
    }
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
    int sz=v.size() ;

    for(int i=0;i<sz;i++) b[i]=i ;
    for(int i=0;i<n;i++)
    {
        int x=lower_bound(v.begin(),v.end(),a[i].x)-v.begin() ;
        int y=lower_bound(v.begin(),v.end(),a[i].y)-v.begin() ;
        swap(b[x],b[y]) ;
    }
    for(int i=0;i<sz;i++) b2[i]=b[i] ;
    mer(0,sz-1) ;

    for(int i=0;i<sz;i++)
    {
        int id=lower_bound(v.begin(),v.end(),v[b2[i]])-v.begin() ;
        if(id>i) ans+=(v[b2[i]]-v[i]+1)-(id-i+1) ;
        else ans+=(v[i]-v[b2[i]]+1)-(i-id+1) ;
    }
    printf("%I64d\n",ans) ;
}
