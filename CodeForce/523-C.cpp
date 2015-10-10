#include<bits/stdc++.h>
using namespace std;

string s,t;
int n,m ;
int cal()
{
    for(int i=0,j=0;i<m;i++)
        if(t[i]==s[j]&& (++j==n))
        return i ;
    return -1 ;
}
main()
{
    cin >> s >> t ;
    n=s.size() ; m=t.size() ;
    int x=cal() ;
    reverse(s.begin(),s.end()) ;
    reverse(t.begin(),t.end()) ;
    int y=m-1-cal() ;
    printf("%d\n",(x==-1||y==m+2||x>y) ? 0 : y-x) ;
}
