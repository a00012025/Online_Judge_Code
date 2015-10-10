#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct {string s;int id;} P ;
bool cmp(P x,P y)
{
    return x.s<y.s ;
}
P p[300000];
string q[300000];
main()
{
    int n ;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        string s ;
        char c[100] ;
        scanf("%s",c) ;
        p[2*i-1].s=c ; p[2*i-1].id=i ;
        scanf("%s",c) ;
        p[2*i].s=c ; p[2*i].id=i ;
    }
    sort(p+1,p+2*n+1,cmp) ;
    int a[100100] ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int num=0 ;
    for(int i=1;i<=2*n;i++)
    {
        if(p[i].id!=a[num+1]) continue ;
        num++ ;
    }
    if(num==n) printf("YES\n");
    else printf("NO\n");
}
