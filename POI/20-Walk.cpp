#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int C=110000 ;

set<LL> s,st1,st2 ;
queue<LL> q ;

bool check()
{
//    for(set<LL>::iterator it=st1.begin();it!=st1.end();it++)
//        if(st2.find(*it)!=st2.end()) return 1 ;
    if(st1.size()<=C || st2.size()<=C) return 0 ;
    return 1 ;
}

void getll(LL &x)
{
    char c=getchar() ;
    while(c!='0' && c!='1') c=getchar() ;
    x=0LL ;
    while(1)
    {
        x=2*x+(c-'0') ;
        c=getchar() ;
        if(c!='0' && c!='1') return ;
    }
}

main()
{
    int n,k ; LL st,ed ;
    scanf("%d%d",&n,&k) ;
    getll(st) ; getll(ed) ;
    while(k--)
    {
        LL x ; getll(x) ;
        s.insert(x) ;
    }

    st1.insert(st) ; q.push(st) ;
    while(!q.empty() && st1.size()<=C)
    {
        LL u=q.front() ; q.pop() ;
        for(int i=0;i<n;i++)
        {
            LL v=(u^(1LL<<i)) ;
            if(st1.find(v)==st1.end() && s.find(v)==s.end() && st1.size()<=C)
                st1.insert(v) , q.push(v) ;
        }
    }

    while(!q.empty()) q.pop() ;

    st2.insert(ed) ; q.push(ed) ;
    while(!q.empty() && st2.size()<=C)
    {
        LL u=q.front() ; q.pop() ;
        if(st1.find(u)!=st1.end()) { printf("TAK\n") ; return 0 ; }
        for(int i=0;i<n;i++)
        {
            LL v=(u^(1LL<<i)) ;
            if(st2.find(v)==st2.end() && s.find(v)==s.end() && st2.size()<=C)
                st2.insert(v) , q.push(v) ;
        }
    }

    if(check()) printf("TAK\n") ;
    else printf("NIE\n") ;
}
