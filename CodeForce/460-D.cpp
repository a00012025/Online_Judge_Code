#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL ans ;
vector<LL> v ;

LL l,r ; int k ;

bool get3(LL &a,LL &b,LL &c)
{
    for(int i=0;i<60;i++)
    {
        a=(1LL<<(i+1))+(1LL<<i) ;
        b=a-1 ;
        c=(1LL<<(i+1))-1 ;
        if(a>=l && a<=r && b>=l && b<=r && c>=l && c<=r)
            return 1 ;
    }
    return 0 ;
}

void solve()
{
    if(r-l+1 <= 10)
    {
        ans=r+1 ;
        int len=r-l+1 ;
        for(int i=1;i<(1<<len);i++)
        {
            LL num=0LL ;
            int cnt=0 ;
            for(int j=0;j<len;j++) if(i&(1<<j))
                cnt++ , num^=(l+j) ;
            if(cnt<=k && num<ans)
            {
                ans=num ;
                v.clear() ;
                for(int j=0;j<len;j++) if(i&(1<<j))
                    v.push_back(l+j) ;
            }
        }
        return ;
    }
    if(k==1) { ans=l ; v.push_back(l) ; return ; }
    if(k==2)
    {
        ans=1 ; v.push_back(l+1) ;
        if(l%2==0) v.push_back(l) ;
        else v.push_back(l+2) ;
        return ;
    }
    if(k>=4)
    {
        while(l%4) l++ ;
        ans=0 ;
        for(int i=0;i<4;i++) v.push_back(l+i) ;
        return ;
    }

    ans=1 ; v.push_back(l+1) ;
    if(l%2==0) v.push_back(l) ;
    else v.push_back(l+2) ;
    LL a,b,c ;
    if(get3(a,b,c))
    {
        ans=0 , v.clear() ;
        v.push_back(a) ;
        v.push_back(b) ;
        v.push_back(c) ;
    }
}

main()
{
    scanf("%I64d%I64d%d",&l,&r,&k) ;
    solve() ;
    printf("%I64d\n%d\n",ans,v.size()) ;
    for(int i=0;i<v.size();i++)
        printf("%I64d%c",v[i],i+1==v.size()?'\n':' ') ;
}
