#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=200000+10 ;

pii p[maxn] ;
set<int> st ;
multiset<int,greater<int> > st2 ;
int ans[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&p[i].F) , p[i].S=i ;
    sort(p+1,p+n+1) ;
    st.insert(0) ; st.insert(n+1) ; st2.insert(n) ;
    for(int i=1;i<=n;i++)
    {
        int last=*st2.begin(),x,y ;
        st.insert(p[i].S) ; auto it=st.find(p[i].S) ;
        it-- ; x=*it ; it++ ;
        it++ ; y=*it ;
        st2.erase(st2.find(y-x-1)) ;
        st2.insert(p[i].S-x-1) ;
        st2.insert(y-p[i].S-1) ;
        for(int j=last;j>*st2.begin();j--) ans[j]=p[i].F ;
    }
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
}
