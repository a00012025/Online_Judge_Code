#include<bits/stdc++.h>
using namespace std;

main()
{
    string s,t ;
    cin >> s >> t ;
    int len=s.size() ;
    s[len-1]++ ;
    for(int i=len-1;i>=0 && s[i]=='z'+1;i--)
    {
        s[i]='a' ;
        if(i) s[i-1]++ ;
        else { printf("No such string\n") ; return 0 ; }
    }
    if(s<t) cout << s << endl ;
    else printf("No such string\n") ;
}
