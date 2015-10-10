#include<stdio.h>
#include<map>
#include<string.h>
using namespace std;
int a[200001],left[200001],right[200001],n ;

void pre_cal()
{
    map<int,int> mp ;
    for(int i=1;i<=n;i++)
    {
        if(!mp.count(a[i])) {mp[a[i]]=i ; left[i]=0 ;}
        else
        {
            left[i]=mp[a[i]] ;
            mp[a[i]]=i ;
        }
    }
    mp.clear() ;
    for(int i=n;i>=1;i--)
    {
        if(!mp.count(a[i])) {mp[a[i]]=i ; right[i]=n+1 ;}
        else
        {
            right[i]=mp[a[i]] ;
            mp[a[i]]=i ;
        }
    }
}

bool Uni(int id,int l,int r)
{
    return (left[id]<l) && (right[id]>r) ;
}

bool solve(int l,int r)
{
    if(r-l+1 <= 1) return 1;
    for(int i=1;i<=r-l+1;i++)
    {
        if(i%2)
        {
            if(Uni(l+(i/2),l,r))
                return solve(l,l+(i/2)-1) && solve(l+(i/2)+1,r) ;
        }
        else
        {
            if(Uni(r+1-(i/2),l,r))
                return solve(l,r-(i/2)) && solve(r-(i/2)+2,r) ;
        }
    }
    return 0;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        pre_cal() ;
        if(solve(1,n)) printf("non-boring\n") ;
        else printf("boring\n") ;
    }
}
