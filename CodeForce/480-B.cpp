#include<stdio.h>
#include<set>
using namespace std;
set<int> s ;
int a[200001] ;
main()
{
    int n,l,x,y ;
    scanf("%d%d%d%d",&n,&l,&x,&y) ;
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]) ; s.insert(a[i]) ;}
    int ans=-1 ;
    bool ok1=0,ok2=0 ;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=x && s.count(a[i]-x)) ok1=1 ;
        if(a[i]<=l-x && s.count(a[i]+x)) ok1=1 ;
        if(a[i]>=y && s.count(a[i]-y)) ok2=1 ;
        if(a[i]<=l-y && s.count(a[i]+y)) ok2=1 ;
    }
    if(ok1 && ok2) printf("0\n") ;
    else if(ok1 || ok2) printf("1\n%d\n",ok1==1 ? y : x) ;
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=x+y && s.count(a[i]-x-y)) {ans=a[i]-x ; break ;}
            if(a[i]>=x && a[i]-x+y<=l && s.count(a[i]-x+y)) {ans=a[i]-x ; break ;}
            if(a[i]+x+y<=l && s.count(a[i]+x+y)) {ans=a[i]+y ; break ;}
            if(a[i]+x<=l && a[i]+x-y>=0 && s.count(a[i]+x-y)) {ans=a[i]+x ; break ;}
        }
        if(ans!=-1) printf("1\n%d\n",ans) ;
        else printf("2\n%d %d\n",x,y) ;
    }
}
