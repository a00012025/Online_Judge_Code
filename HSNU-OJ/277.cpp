#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=3000 ;

DB C[maxn][maxn] ;
DB cal(int n,int p,int q)
{
    DB a=0,b=0 ;
    for(int i=max(q,p-n);i<=min(n,p);i++) a+=C[p][i] ;
    for(int i=max(0,p-n);i<=min(n,p);i++) b+=C[p][i] ;
    return a/b ;
}

main()
{
    C[0][0]=1 ;
    for(int i=1;i<maxn;i++) for(int j=0;j<=i;j++)
        C[i][j]=((j==0||j==i) ? C[i-1][0]*0.5 : (C[i-1][j-1]+C[i-1][j])*0.5) ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,x,y ; scanf("%d%d%d",&n,&x,&y) ;
        if((x+y)%2){printf("0.0\n") ; continue ;}
        int k=((x>0?x:-x)+y)/2+1 ;
        if(n>=k*(2*k-1)){printf("1.0\n") ; continue ;}
        if(n<=(k-1)*(2*k-3)){printf("0.0\n") ; continue ;}
        if(x==0){printf("0.0\n") ; continue ;}
        double ans=cal(2*(k-1),n-(k-1)*(2*k-3),y+1) ;
        printf("%.10f\n",fabs(ans)) ;
    }
}
