#include<bits/stdc++.h>
using namespace std;

int a[50][50],s[50][50] ;

main()
{
    int n ;
    while(scanf("%d%d",&n,&a[1][1])!=EOF)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            if(i>1 || j>1)
        {
            a[i][j]= j==1 ? a[1][1]+i : (a[i][j-1]*17)%103 ;
            if(j!=1 && ((i+j)%2)) a[i][j]=-a[i][j] ;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j] ;
        int ans=-1000000 ;
        for(int i=0;i<n;i++) for(int j=i+1;j<=n;j++)
            for(int k=0;k<n;k++) for(int l=k+1;l<=n;l++)
            ans=max(ans,s[j][l]-s[j][k]-s[i][l]+s[i][k]) ;
        printf("%d\n",ans) ;
    }
}
