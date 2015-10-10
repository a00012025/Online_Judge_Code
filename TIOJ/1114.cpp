#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

inline bool ok(char c)
{
    return c>='a' && c<='z' ;
}

map<string,int> mp1,mp2 ;
set<string> st1,st2 ;
char s[maxn],t[maxn] ;

main()
{
    while(gets(s))
    {
        gets(t) ;
        int n=strlen(s) , m=strlen(t) ;
        mp1.clear() ; mp2.clear() ;
        st1.clear() ; st2.clear() ;
        for(int i=0;i<n;i++) if(s[i]>='A'&&s[i]<='Z')
            s[i]+='a'-'A' ;
        for(int i=0;i<m;i++) if(t[i]>='A'&&t[i]<='Z')
            t[i]+='a'-'A' ;
        for(int i=0;i<n;)
        {
            while(i<n && !ok(s[i])) i++ ;
            if(i>=n) break ;
            int i2=i ;
            while(i2<n && ok(s[i2])) i2++ ;
            string tmp(s+i,s+i2) ;
            if((mp1[tmp]++)==1) st1.insert(tmp) ;
            i=i2 ;
        }

        for(int i=0;i<m;)
        {
            while(i<m && !ok(t[i])) i++ ;
            if(i>=m) break ;
            int i2=i ;
            while(i2<m && ok(t[i2])) i2++ ;
            string tmp(t+i,t+i2) ;
            if((mp2[tmp]++)==1) st2.insert(tmp) ;
            i=i2 ;
        }

        bool found=0 ;
        for(auto i : st1) if(st2.count(i))
            found=1 , cout << i << endl ;
        if(!found) printf("<NONE>\n") ;
        printf("\n") ;
    }
}
