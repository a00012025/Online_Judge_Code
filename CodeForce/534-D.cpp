#include<bits/stdc++.h>
using namespace std;
const int maxn=200000 ;

vector<int> v[maxn] ;
int id[maxn],ans[maxn] ;

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        v[x].push_back(i) ;
    }
    for(int i=1,num=0;i<=n;i++,num++)
    {
        while(num>=0 && v[num].size()==id[num]) num-=3 ;
        if(num<0) { printf("Impossible\n") ; return 0 ; }
        ans[i]=v[num][id[num]++] ;
    }
    printf("Possible\n") ;
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
}
