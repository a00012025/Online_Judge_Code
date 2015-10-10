#include<bits/stdc++.h>
#include "interactive/363.h"
using namespace std;

vector<int> s,l ;
main()
{
    int n=Ramen() ;
    if(n==1) Answer(0,0) ;
    for(int i=0;i+1<n;i+=2)
    {
        if(Compare(i,i+1)==1) l.push_back(i) , s.push_back(i+1) ;
        else s.push_back(i) , l.push_back(i+1) ;
    }
    if(n%2)
    {
        if(Compare(0,n-1)==1) s.push_back(n-1) ;
        else l.push_back(n-1) ;
    }
    int M=l[0] , m=s[0] ;
    for(int i=1;i<l.size();i++) if(Compare(l[i],M)==1) M=l[i] ;
    for(int i=1;i<s.size();i++) if(Compare(m,s[i])==1) m=s[i] ;
    Answer(m,M) ;
}
