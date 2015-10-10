#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;

vector<int> ans ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        bool ok=1 ;
        for(int j=1;j<=n;j++)
        {
            int x ; scanf("%d",&x) ;
            if(x==1 || x==3) ok=0 ;
        }
        if(ok) ans.push_back(i) ;
    }
    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++) printf("%d%c",ans[i],i+1==ans.size()?'\n':' ') ;
}
