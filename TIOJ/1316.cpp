#include<bits/stdc++.h>
using namespace std;
const int maxn=8000+10 ;

int a[maxn] ;
int l[maxn],r[maxn],num[maxn] ;
bool used[maxn] ;

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=2*n;i++)
    {
        scanf("%d",&a[i]) ;
        if(!l[a[i]]) l[a[i]]=i ;
        else r[a[i]]=i ;
    }

    int now=2 ;
    for(int i=1;i<=2*n;i++)
    {
        if(i==l[a[i]]) now-- ;
        num[i]=now ;
        if(i==r[a[i]]) now++ ;
    }

    int ans=n ;
    for(int i=1;i<=2*n;i++) while(num[i]<0)
    {
        int M=0 , id ;
        for(int j=1;j<=i;j++)
            if(!used[a[j]] && j==l[a[j]] && r[a[j]]>M)
            M=r[id=a[j]] ;
        used[id]=1 ;
        for(int j=l[id];j<=r[id];j++) num[j]++ ;
        ans-- ;
    }
    printf("%d\n",ans) ;
}
