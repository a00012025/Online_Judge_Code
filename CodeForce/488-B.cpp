#include<bits/stdc++.h>
using namespace std;

int a[5] ;
bool check()
{
    return a[1]>=1 && a[4]==3*a[1] && a[2]+a[3]==4*a[1] &&
            a[1]<=a[2] && a[2]<=a[3] && a[3]<=a[4] ;
}
bool solve()
{
    if(a[1]&&!a[4]) a[4]=3*a[1] ;
    if(a[4]&&!a[1]) a[1]=a[4]/3 ;
    if(a[2]&&a[3]&&!a[1]) a[1]=(a[2]+a[3])/4 ;
    if(a[2]&&!a[3]&&a[1]) a[3]=4*a[1]-a[2] ;
    if(!a[2]&&a[3]&&a[1]) a[2]=4*a[1]-a[3] ;
    return check() ;
}
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    if(n==0){printf("YES\n1\n2\n2\n3\n") ; return 0 ;}
    if(n==1){printf("YES\n%d\n%d\n%d\n",2*a[1],2*a[1],3*a[1]) ; return 0 ;}
    if(n==2)
    {
        int x=a[1],y=a[2] ;
        if(x>y) swap(x,y) ;
        for(int i=1;i<=4;i++) for(int j=i+1;j<=4;j++)
        {
            fill(a,a+5,0) ;
            a[i]=x ; a[j]=y ;
            if(solve())
            {
                printf("YES\n") ;
                for(int k=1;k<=4;k++) if(k!=i&&k!=j)
                    printf("%d\n",a[k]) ;
                return 0 ;
            }
        }
        printf("NO\n") ;
    }
    if(n==3)
    {
        sort(a+1,a+4) ;
        int b[4]={0,a[1],a[2],a[3]} ;
        for(int i=1;i<=4;i++)
        {
            for(int j=1,k=1;j<=4;j++)
                a[j]= j==i?0:b[k++] ;
            if(solve()){printf("YES\n%d\n",a[i]) ; return 0 ;}
        }
        printf("NO\n") ;
    }
    if(n==4)
    {
        sort(a+1,a+5) ;
        printf("%s\n",check()?"YES":"NO") ;
    }
}
