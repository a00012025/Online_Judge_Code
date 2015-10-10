#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
pair<int,int> a[1000000] ;
main()
{
    freopen("1.txt","r",stdin) ;
    int n ; scanf("%d",&n) ;
    bool f=0 ;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S) ;
    }
    f=1 ;
    while(f)
    {
        f=0 ;
        for(int i=0;i<n;i++) if(a[i].F==1)
        {
            f=1 ;
            a[a[i].S].F-- ;
            a[a[i].S].S ^=i ;
            a[i].F=0 ;
            break ;
        }
    }
}
