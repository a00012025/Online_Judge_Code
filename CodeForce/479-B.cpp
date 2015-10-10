#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=100+10 ;

set<pii> s ;
vector<pii> ans ;
int a[maxn] ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , s.insert(pii(a[i],i)) ;
    if(n==1){printf("0 0\n") ; return 0 ;}
    while(k--)
    {
        if((--s.end())->F==s.begin()->F) break ;
        pii p=*s.begin() ; s.erase(p) ;
        pii q=*(--s.end()) ; s.erase(q) ;
        a[p.S]++ ; a[q.S]-- ;
        ans.push_back(pii(q.S,p.S)) ;
        s.insert(pii(a[p.S],p.S)) ;
        s.insert(pii(a[q.S],q.S)) ;
    }
    printf("%d %d\n",(--s.end())->F-s.begin()->F,ans.size()) ;
    for(auto i : ans) printf("%d %d\n",i.F,i.S) ;
}
