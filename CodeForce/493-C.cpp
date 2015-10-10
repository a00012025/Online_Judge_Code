#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+5 ;
int a[maxn],b[maxn] ;
vector<int> v ;
int num1[2*maxn]={0},num2[2*maxn]={0} ;
int ans1,ans2 ;

int find_in_v(int x)
{
    int l=0 , r=v.size()-1 ;
    if(v[l]==x) return l ;
    if(v[r]==x) return r ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(v[mid]==x) return mid ;
        if(v[mid]>x) r=mid ;
        else l=mid ;
    }
}

bool better(int x,int y)
{
    if(x-y != ans1-ans2) return x-y > ans1-ans2 ;
    else return x>ans1 ;
}

main()
{
    int n,m ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , v.push_back(a[i]) ;
    scanf("%d",&m) ;
    for(int i=1;i<=m;i++) scanf("%d",&b[i]) , v.push_back(b[i]) ;
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
    for(int i=1;i<=n;i++) a[i]=find_in_v(a[i]) , num1[a[i]]++ ;
    for(int i=1;i<=m;i++) b[i]=find_in_v(b[i]) , num2[b[i]]++ ;
    int pt1=2*n,pt2=2*m ; ans1=2*n , ans2=2*m ;
    for(int i=n+m+1;i>=0;i--) if(num1[i] || num2[i])
    {
        pt1 += num1[i] ;
        pt2 += num2[i] ;
        if(better(pt1,pt2)) ans1=pt1 , ans2=pt2 ;
    }
    pt1=3*n , pt2=3*m ;
    if(better(pt1,pt2)) ans1=pt1 , ans2=pt2 ;
    printf("%d:%d\n",ans1,ans2) ;
}
