#include<bits/stdc++.h>
using namespace std;

string s[]={"zero","one","two","three","four","five","six","seven",
"eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen"
,"sixteen","seventeen","eighteen","nineteen"} ;
string t[]={"","","twenty","thirty","forty","fifty","sixty","seventy",
"eighty","ninety"} ;

main()
{
    int n ; scanf("%d",&n) ;
    string ans ;
    if(n<20) ans=s[n] ;
    else if(n%10) ans=t[n/10]+"-"+s[n%10] ;
    else ans=t[n/10] ;
    cout << ans ;
}
