#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct{int id,dif ;} P ;

bool comp(int x,int y)
{
    return x>y ;
}

bool comp2(P x,P y)
{
    return x.dif<y.dif ;
}
main()
{
    P p[2001] ;
    int num[2101]={0} ;
    int n;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a) ;
        p[i]=(P){i,a} ;
        num[a]++ ;
    }
    sort(num+1,num+2001,comp) ;
    sort(p+1,p+n+1,comp2) ;
    if(n<=2) printf("NO\n") ;
    else if(num[1]==1 || (num[1]==2 && num[2]==1)) printf("NO\n") ;
    else
    {
        printf("YES\n") ;
        for(int i=1;i<=n;i++) printf("%d ",p[i].id) ;
        printf("\n") ;
        int i,j ;
        for(i=1;i<=n && p[i].dif!=p[i+1].dif;i++) ;
        for(j=i+1;j<=n && p[j].dif!=p[j+1].dif;j++) ;
        for(int k=1;k<=n;k++)
        {
            if(k==i) printf("%d ",p[i+1].id) ;
            else if(k==i+1) printf("%d ",p[i].id) ;
            else printf("%d ",p[k].id) ;
        }
        printf("\n") ;
        for(int k=1;k<=n;k++)
        {
            if(k==j) printf("%d ",p[j+1].id) ;
            else if(k==j+1) printf("%d ",p[j].id) ;
            else printf("%d ",p[k].id) ;
        }
        printf("\n") ;
    }

}
