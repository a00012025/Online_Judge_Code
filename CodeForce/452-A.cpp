#include<bits/stdc++.h>
using namespace std;

string s[]={"vaporeon", "jolteon", "flareon", "espeon",
"umbreon", "leafeon", "glaceon", "sylveon"};

main()
{
    int n ; scanf("%d",&n) ;
    string t ; cin >> t ;
    for(int i=0;i<8;i++) if(s[i].size()==t.size())
    {
        bool ok=1 ;
        for(int j=0;j<t.size();j++)
            if(t[j]!='.' && t[j]!=s[i][j]) ok=0 ;
        if(ok){cout << s[i] ; return 0 ;}
    }
}
