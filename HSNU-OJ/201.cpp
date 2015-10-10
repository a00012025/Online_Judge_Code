#include<bits/stdc++.h>
using namespace std;
const int maxn=300000+10 ;

int n,k ;
int a[maxn],num[maxn] ;
bool can[maxn],have[maxn] ;
void mark(int x,int dir)
{
    int las=(have[x] ? x : -1) ;
    for(int i=x+dir;i>=1 && i<=n && a[i]<a[i-dir];i+=dir)
        if(have[i]) las=i ;
    if(las==-1) return ;
    for(int i=las;;i-=dir)
    {
        can[i]=1 ;
        if(i==x) break ;
    }
}

int getnum(int x,int dir)
{
    int ret=(can[x] ? 0 : num[x]) ;
    for(int i=x+dir;i>=1 && i<=n && a[i]<a[i-dir];i+=dir)
        ret+=(can[i] ? 0 : num[i]) ;
    return ret ;
}

char s[maxn] ;
main()
{
    scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    scanf("%s",s+1) ;

    int n2=0 , k2 ;
    for(int i=1;i<=n;i++)
    {
        if(!n2 || a[i]!=a[n2]) a[++n2]=a[i] ;
        num[n2]++ ;
        if(i==k) k2=n2 ;
        if(s[i]=='T') have[n2]=1 ;
    }
    if(n2==1){printf("%d\n",n) ; return 0 ;}
    n=n2 ; k=k2 ;

    int lnum=num[k] , rnum=num[k] , found=have[k] ;
    for(int i=k+1;!found && i<=n && a[i]<a[i-1];i++)
    {
        if(have[i]) found=1 ;
        rnum+=num[i] ;
    }
    for(int i=k-1;!found && i>=1 && a[i]<a[i+1];i--)
    {
        if(have[i]) found=1 ;
        lnum+=num[i] ;
    }
    if(!found){printf("%d\n",max(lnum,rnum)) ; return 0 ;}

    mark(1,1) ; mark(n,-1) ;
    for(int i=2;i<n;i++) if(a[i]>a[i-1] && a[i]>a[i+1])
        mark(i,1) , mark(i,-1) ;

    int ans=0 , ma=0 ;
    for(int i=1;i<=n;i++) if(can[i]) ans+=num[i] ;
    ma=max(ma,getnum(1,1)) ;
    ma=max(ma,getnum(n,-1)) ;
    for(int i=2;i<n;i++) if(a[i]>a[i-1] && a[i]>a[i+1])
        ma=max(ma,max(getnum(i,1),getnum(i,-1))) ;
    printf("%d\n",ans+ma) ;
}
