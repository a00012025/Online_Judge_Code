#include<bits/stdc++.h>
using namespace std;
const int maxn=100 ;
bool ok(const string &t)
{
    for(int i=0;i<t.size();i++) if(t[i]!=t[t.size()-1-i]) return 0 ;
    return 1 ;
}
string s;
main()
{
    cin >> s ;
    for(int i=0;i<=s.size();i++) for(int j=0;j<26;j++)
    {
        string t=s.substr(0,i)+char(j+'a')+s.substr(i,s.size()) ;
        if(ok(t)){cout << t << endl ; return 0 ;}
    }
    printf("NA\n") ;
}
