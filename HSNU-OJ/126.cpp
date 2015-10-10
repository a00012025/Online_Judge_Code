#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;
vector<int> v[27] ;

int a[maxn],b[maxn],id[27] ;
char s[maxn],t[maxn] ;
LL ans=0LL ;

void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ;
    mer(mid+1,r) ;
    int i=l , j=mid+1 , cnt=l ;
    while(i<=mid || j<=r)
    {
        if(i==mid+1 || (j<=r && a[j]<a[i]))
            b[cnt++]=a[j++] , ans+=mid-i+1 ;
        else b[cnt++]=a[i++] ;
    }
    for(i=l;i<=r;i++) a[i]=b[i] ;
}

main()
{
    int n ; scanf("%d%s%s",&n,s,t) ;
    for(int i=0;i<n;i++) v[t[i]-'A'].push_back(i) ;
    memset(id,0,sizeof(id)) ;
    for(int i=0;i<n;i++) a[v[s[i]-'A'][id[s[i]-'A']++]]=i ;
    mer(0,n-1) ;
    printf("%lld\n",ans) ;
}
