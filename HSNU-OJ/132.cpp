#include<bits/stdc++.h>
using namespace std;

set<int> st ;
int a[40] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    int n1=(n/2) , n2=n-n1 ; /// 0~n1-1 , n1~n1+n2-1
    for(int i=1;i<(1<<n1);i++)
    {
        int s=0 ;
        for(int j=0;j<n1;j++) if(i&(1<<j)) s+=a[j] ;
        if(s==0) { printf("yes\n") ; return 0 ; }
        st.insert(s) ;
    }
    for(int i=1;i<(1<<n2);i++)
    {
        int s=0 ;
        for(int j=0;j<n2;j++) if(i&(1<<j)) s+=a[n1+j] ;
        if(s==0 || st.count(-s)) { printf("yes\n") ; return 0 ; }
    }
    printf("no\n") ;
}
