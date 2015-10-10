#include<bits/stdc++.h>
using namespace std;
map<string,string> mp ;
main()
{
    int n ; scanf("%d",&n) ;
    while(n--)
    {
        string s,t ; cin >> s >> t ;
        if(mp.find(s)==mp.end()) mp[t]=s ;
        else
        {
            string s2=mp[s] ;
            mp.erase(s) ;
            mp[t]=s2 ;
        }
    }
    printf("%d\n",mp.size()) ;
    for(auto i : mp) cout << i.second << " " << i.first << endl ;
}
