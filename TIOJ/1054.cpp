#include<bits/stdc++.h>
using namespace std;

map<string,int> mp ;
string s[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"} ;

main()
{
    for(int i=0;i<7;i++) mp[s[i]]=i ;
    string t ; int n ;
    cin >> t >> n ;
    cout << s[(mp[t]+n)%7] << endl ;
}
