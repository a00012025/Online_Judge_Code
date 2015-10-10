#include<bits/stdc++.h>
#define LL long long
using namespace std;
char s[20000] ;

LL solve(int l,int r)
{
    bool ok=1 ;
    for(int i=l+1;i<r;i++) if(s[i]=='['||s[i]==']')
        {ok=0 ; break ; }
    if(ok)
    {
        LL ret=0 ;
        for(int i=l+1;i<r;i++) ret=ret*10+s[i]-'0' ;
        return (ret+1)/2 ;
    }

    vector<LL> tmp ;
    int num=0 , L=l+1 ;
    for(int i=l+1;i<r;i++)
    {
        if(s[i]=='[') num++ ;
        if(s[i]==']') num-- ;
        if(!num) tmp.push_back(solve(L,i)) , L=i+1 ;
    }
    sort(tmp.begin(),tmp.end()) ; int sz=tmp.size() ;
    LL ret=0LL ;
    for(int i=0;2*i<sz;i++) ret+=tmp[i] ;
    return ret ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s",s) ; int len=strlen(s) ;
        printf("%lld\n",solve(0,len-1)) ;
    }
}
