#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;

map<int,vector<int> > mp ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x  ; scanf("%d",&x) ;
        mp[x].push_back(i) ;
    }
    int mi=n ;
    for(auto i : mp) for(int j=0;j<(int)i.S.size()-1;j++)
        mi=min(mi,i.S[j+1]-i.S[j]) ;
    printf("%d\n",n-mi) ;
}
