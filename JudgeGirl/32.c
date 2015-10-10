#include<stdio.h>
int a[200],isp[200][200],ansl,ansr ;
int check(int l,int r)
{
    for(int i=l;i<=r;i++) if(a[i]!=a[l+r-i]) return 0 ;
    return 1 ;
}
int check2(int l,int r)
{
    for(int i=l;i<r;i++) if(isp[l][i] && isp[i+1][r]) return 1 ;
    return 0 ;
}
main()
{
    int n=0 ;
    while(scanf("%d",&a[n++])!=EOF) ; n-- ;
    for(int i=0;i<n;i++) for(int j=i;j<n;j++) isp[i][j]=check(i,j) ;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(check2(i,j) && j-i>=ansr-ansl)
        ansl=i , ansr=j ;
    for(int i=ansl;i<=ansr;i++) printf("%d%c",a[i],i==ansr?'\n':' ') ;
}
