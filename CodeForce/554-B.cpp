#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
main()
{
    string s ;
    int n ; scanf("%d",&n) ;
    while(n--) cin >> s , mp[s]++ ;
    int ans=0 ;
    for(auto i : mp) ans=max(ans,i.second) ;
    printf("%d\n",ans) ;
}
