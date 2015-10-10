#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

char s[maxn] ;
set<int> s1,s2 ;
main()
{
    int n ; scanf("%s",s) ;
    n=strlen(s) ;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='A' && s[i+1]=='B') s1.insert(i) ;
        if(s[i]=='B' && s[i+1]=='A') s2.insert(i) ;
    }
    for(auto i : s2)
    {
        auto it=s1.lower_bound(i+2) ;
        if(it!=s1.end()){printf("YES\n") ; return 0 ;}
        it=s1.lower_bound(i-1) ;
        if(it!=s1.begin()){printf("YES\n") ; return 0 ;}
    }
    printf("NO\n") ;
}
