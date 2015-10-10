#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;

int l[maxn],r[maxn] ;
int a[maxn],dif ;

void add(int x,int *arr,int val)
{
    int b0= (((bool)l[x])==((bool)r[x])) ;
    arr[x]+=val ;
    int b1= (((bool)l[x])==((bool)r[x])) ;
    if(b0 && !b1) dif++ ;
    if(!b0 && b1) dif-- ;
}

vector<int> v ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , v.push_back(a[i]) ;
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin() ;
    int ans=0 ;
    for(int i=1;i<n;i++)
    {
        memset(l,0,sizeof(l)) ;
        memset(r,0,sizeof(r)) ;
        dif=0 ;
        for(int j=i+1;j<=n;j+=2)
        {
            add(a[j-1],r,1) ; add(a[j],r,1) ;
            add(a[(j+i)/2],l,1) ;
            add(a[(j+i)/2],r,-1) ;
            if(dif==0) ans=max(ans,j-i+1) ;
        }
    }
    printf("%d\n",ans) ;
}
