#include<stdio.h>
int n,h,a[2001],ans ;
bool check()
{
 for(int i=1;i<=n;i++) if(a[i]<h) return 0;
 return 1;
}

void dfs(int l,int r)
{
 if(check()) {ans+=1 ; ans=ans%1000000007 ; return ;}
 for(;(a[l+1]==h)&&(l<=n-1);l++) ;
 if((r==n)||(a[l+1]+1<h)) return ;
 int newr ;
 for(newr=l+1;(a[newr]<h)&&(newr<=n);newr++) ;
 if(newr<=r+1) return ;
 for(int i=r+1;i<newr;i++)
    {
    for(int j=l+1 ; j<=i ; j++) a[j]++ ;    
            for(int z=1;z<=n;z++) printf("%d,",a[z]);
            printf("\n");
    dfs(l+1,i) ;
    for(int j=l+1 ; j<=i ; j++) a[j]-- ;
    }
}

main()
{
 while(scanf("%d %d",&n,&h)==2)
 {
 bool no=0 ;
 for(int i=1;i<=n;i++) 
    {
    scanf("%d",&a[i]) ;
    if(i<=n-i+1 && a[i]+i<h) no=1 ;
    if(i>n-i+1 && a[i]+n-i+1<h) no=1 ;
    if(a[i]>h) no=1 ;
    }
 if(no==1) {printf("0\n") ; continue ;}
 int l,r ;
 for(l=1;a[l]==h && l<=n;l++) ;
 if(l==n+1) {printf("1\n") ; continue ;}
 r=l ; ans=0 ;
 dfs(r-1,l-1) ;
 printf("%d\n",ans) ;
 }
}
