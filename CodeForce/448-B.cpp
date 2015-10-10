#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;

string str[]={"automaton","array","both","need tree"} ;
char s[maxn],t[maxn] ;
int c1[maxn],c2[maxn] ;
int solve()
{
    int n=strlen(s) , m=strlen(t) ;
    for(int i=0;i<n;i++) c1[s[i]-'a']++ ;
    for(int i=0;i<m;i++) c2[t[i]-'a']++ ;
    int j=0 ;
    for(int i=0;i<n && j<m;i++) if(s[i]==t[j]) j++ ;
    if(j==m) return 0 ;

    bool ok=1 ;
    for(int i=0;i<26;i++)
    {
        if(c1[i]<c2[i]) return 3 ;
        else if(c1[i]>c2[i]) ok=0 ;
    }
    return ok ? 1 : 2 ;
}
main()
{
    scanf("%s%s",s,t) ;
    cout << str[solve()] << endl ;
}
