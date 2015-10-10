#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;
inline void NO(){printf("NO\n") ; exit(0) ;}

char s[maxn] ;
int n,p ;
bool solve(int x)
{
    int i=-1 ;
    for(int j=s[x]-'a'+1;j<p;j++)
    {
        if(s[x-1]==j+'a') continue ;
        if(x>1 && s[x-2]==j+'a') continue ;
        i=j ; break ;
    }
    if(i==-1) return 0 ;
    s[x]=i+'a' ;
    for(int j=x+1;j<=n;j++)
    {
        s[j]='a' ;
        while(s[j]==s[j-1]||s[j]==s[j-2]) s[j]++ ;
    }
    return 1 ;
}

main()
{
    scanf("%d%d%s",&n,&p,s+1) ;
    if(p==1) NO() ;
    if(p==2)
    {
        if(n>2) NO() ;
        if(s[1]=='b') NO() ;
        if(n==1) printf("b\n") ;
        else printf("ba\n") ;
        return 0 ;
    }
    int st=1 ;
    for(;st<n && s[st]!=s[st-2] && s[st]!=s[st-1];st++) ;
    for(int i=st;i>=1;i--) if(solve(i))
        {printf("%s\n",s+1) ; return 0 ;}
    NO() ;
}
