#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;
inline void L(){printf("L") ;}
inline void R(){printf("R") ;}
int n ;
char s[maxn] ;
deque<char> v ;
main()
{
    scanf("%d%s",&n,s) ;
    for(int i=0;i<n;i++)
    {
        if(v.empty()){v.push_back(s[i]) ; R() ; continue ;}
        if(s[i]==v.front()) v.pop_front() , L() ;
        else if(s[i]==v.back()) v.pop_back() , R() ;
        else if(v.size()==1) v.push_back(s[i]) , R() ;
        else if(i==n-1 || (i!=n-1 && s[i+1]==s[i]))
            v.push_back(s[i]) , R() ;
        else if(s[i+1]==v.back()) v.push_front(s[i]) , L() ;
        else v.push_back(s[i]) , R() ;
    }
    printf("\n") ;
}
