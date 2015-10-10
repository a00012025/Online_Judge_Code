#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> > st ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    bool no=0 ;
    int x,y ;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if(x==y) no=1 ;
        if(no) break ;
        if(x>y) swap(x,y) ;
        if(st.count(make_pair(x,y))) no=1 ;
        else st.insert(make_pair(x,y)) ;
    }
    if(no) printf("Yes\n") ;
    else printf("yes\n") ;
}
