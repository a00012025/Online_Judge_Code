#include<bits/stdc++.h>
using namespace std;

map<int,int> mp ;
main()
{
    int n;
    int num=0 , ans ;
    while(scanf("%d",&n)==1 && n)
    {
        int val=(++mp[n]) ;
        if(val > num || (val==num && n<ans))
            ans=n , num=val ;
        printf("%d %d\n",num,ans) ;
    }
}
