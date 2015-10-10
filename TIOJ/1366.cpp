#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

struct P
{
    LL val ; int id ;
    bool operator < (const P &rhs) const
    {
        return val==rhs.val ? id<rhs.id : val<rhs.val ;
    }
}a[maxn];
string s[maxn] ;

LL cal(const string &x)
{
    LL ret=0LL ;
    for(int i=0;i<x.size();i++) ret+=x[i]-'0' ;
    return ret ;
}

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            cin >> s[i] ,
            a[i].val=cal(s[i]) ,
            a[i].id=i ;
        sort(a+1,a+n+1) ;
        for(int i=1;i<=n;i++)
        {
            cout << s[a[i].id] ;
            printf("%c",i==n?'\n':' ') ;
        }
    }
}
