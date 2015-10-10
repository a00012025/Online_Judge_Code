#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

string s,t,ans ;
main()
{
    int n ; scanf("%d",&n) ;
    cin >> s ; ans=s ;
    for(int i=0;i<n;i++)
    {
        t=s.substr(i,n)+s.substr(0,i) ;
        int x=10-(t[0]-'0') ;
        for(int j=0;j<n;j++)
        {
            int nx=(t[j]-'0'+x)%10 ;
            t[j]=nx+'0' ;
        }
        ans=min(ans,t) ;
    }
    cout << ans << endl ;
}
