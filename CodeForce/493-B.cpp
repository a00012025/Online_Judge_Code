#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200000+10 ;

int a[maxn],b[maxn],c[maxn] ;
main()
{
    int n,p=0,q=0 ; scanf("%d",&n) ;
    LL s=0LL ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]) ; s+=a[i] ;
        if(a[i]>0) b[p++]=a[i] ;
        else c[q++]=-a[i] ;
    }
    if(s)
    {
        printf("%s\n",s>0?"first":"second") ;
        return 0 ;
    }

    int ans=0 ;
    for(int i=0;i<max(p,q);i++)
    {
        if(i>=q || b[i]>c[i]){ans=1 ; break ;}
        if(i>=p || b[i]<c[i]){ans=2 ; break ;}
    }
    if(!ans) ans=(a[n]>0 ? 1 : 2) ;
    printf("%s\n",ans==1?"first":"second") ;
}
