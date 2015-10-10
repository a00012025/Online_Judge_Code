#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

int getint()
{
    char c=getchar() ;
    while(c<'0'||c>'9') c=getchar() ;
    int x=0 ;
    while(1)
    {
        x=x*10+(c-'0') ;
        c=getchar() ;
        if(c<'0'||c>'9') return x ;
    }
}

int a[maxn],num[maxn],cnt=0 ;
int tmp[maxn];

void add(int x,int val)
{
    bool b1=(num[x]==0) ;
    num[x]-=val ;
    bool b2=(num[x]==0) ;
    if(b1 && !b2) cnt-- ;
    if(!b1 && b2) cnt++ ;
}

main()
{
    int n=getint(),m=getint() ; LL k=0LL ;
    for(int i=1;i<=m;i++) tmp[i]=getint() , k+=tmp[i] ;
    for(int i=1;i<=m;i++)
    {
        int x=getint() ;
        num[x]=tmp[i] ;
    }
    for(int i=1;i<=n;i++) a[i]=getint() ;

    if(k>n) { printf("0\n") ; return 0 ; }

    int ans=0 ;
    for(int i=1;i<k;i++) add(a[i],1) ;
    for(int i=k;i<=n;i++)
    {
        add(a[i],1) ;
        if(cnt==m) ans++ ;
        add(a[i-k+1],-1) ;
    }
    printf("%d\n",ans) ;
}
