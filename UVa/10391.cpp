#include<stdio.h>
#include<set>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
string s[130000] ;
set<string> st ;
char c[10000] ;
main()
{
    int n ;
    for(n=1;;n++)
    {
        if(scanf("%s",c)==EOF) break ;
        for(int j=0;j<strlen(c);j++) s[n].push_back(c[j]) ;
        st.insert(s[n]) ;
    }
    for(int i=1;i<=n;i++)
    {
        bool yes=0 ;
        for(int j=1;j<s[i].size();j++)
        {
            string s1,s2 ;
            s1.append(s[i].begin(),s[i].begin()+j) ;
            s2.append(s[i].begin()+j,s[i].end()) ;
                //cout << s1 << ',' << s2 << '\n' ;
            if(st.count(s1) && st.count(s2)) {yes=1 ; break ;}
        }
        if(yes)
        {
            for(int j=0;j<s[i].size();j++) printf("%c",s[i][j]) ;
            printf("\n") ;
        }
    }
}
