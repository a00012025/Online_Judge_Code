#include<bits/stdc++.h>
using namespace std;

stack<int> st1,st2 ;
int a[2000] ;
bool in[2000] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;

    int now=0 ;
    for(int i=1;i<=n;i++)
    {
        while(!in[a[i]]) st1.push(++now) , in[now]=1 ;
        while(st1.top()!=a[i] && st2.size()<m)
            st2.push(st1.top()) , st1.pop() ;
        if(st1.top()!=a[i]) { printf("no\n") ; return 0 ; }
        st1.pop() ;
        while(!st2.empty()) st1.push(st2.top()) , st2.pop() ;
    }
    printf("yes\n") ;
}
