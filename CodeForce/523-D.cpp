#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=500000+10 ;

multiset<LL> st ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=k;i++) st.insert(0) ;
    while(n--)
    {
        LL s,m ; scanf("%I64d%I64d",&s,&m) ;
        LL val=*st.begin() ; st.erase(st.begin()) ;
        val=max(s,val)+m ;
        printf("%I64d\n",val) ;
        st.insert(val) ;
    }
}
