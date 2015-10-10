#include<bits/stdc++.h>
using namespace std;

int a[20] ;
set<int> st ;
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
        st.clear() ;
        for(int i=1;i<(1<<n);i++)
        {
            int sum=0 ;
            for(int j=0;j<n;j++) if(i&(1<<j)) sum+=a[j] ;
            st.insert(sum) ;
        }
        printf("%d\n",st.size()) ;
    }
}
