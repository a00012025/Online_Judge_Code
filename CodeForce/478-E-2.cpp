#include<bits/stdc++.h>
#define LL long long
#define F first
#define S second
using namespace std;
const int maxn=10000000 ;

int tmp[30],cnt ;
bool check(int x)
{
    cnt=0 ; int y=x ;
    while(y) tmp[cnt++]=y%10 , y/=10 ;
    if(cnt==1) return 1 ;
    if(tmp[0]==tmp[1]) return 0 ;
    if(tmp[0]>tmp[1])
    {
        for(int i=0;i<cnt-1;i+=2) if(tmp[i+1]>=tmp[i]) return 0 ;
        for(int i=1;i<cnt-1;i+=2) if(tmp[i+1]<=tmp[i]) return 0 ;
    }
    else
    {
        for(int i=0;i<cnt-1;i+=2) if(tmp[i+1]<=tmp[i]) return 0 ;
        for(int i=1;i<cnt-1;i+=2) if(tmp[i+1]>=tmp[i]) return 0 ;
    }
    return 1 ;
}

int v[830169],vcnt ;
unordered_map<int,vector<int> > mp[10][2] ;
main()
{
    LL n,k ; cin >> n >> k ;
    for(int i=0;i<maxn;i++) if(check(i))
    {
        v[vcnt++]=i ;
        if(i%n==0 && !(--k)){cout << i ; ; return 0 ;}
        if(i<100000) continue ;
        if(i<1000000)
        {
            if(tmp[cnt-1]<tmp[cnt-2]) continue ;
            tmp[cnt++]=0 ;
        }
        int d=(tmp[cnt-1]>tmp[cnt-2]) ;
        mp[tmp[cnt-1]][d][i%n].push_back(i) ;
    }

    LL mul=10000000 ;
    for(auto i : v)
    {
        int x=i%10 , y=(i/10)%10 ;
        LL val=(-mul*i)%n ; if(val<0) val+=n ;
        if(val>=maxn) continue ;
        if(i<10 || y<x) for(int j=0;j<x;j++)
        {
            auto it=mp[j][0].find(val) ;
            if(it==mp[j][0].end()) continue ;
            if(k>it->S.size()) k-=it->S.size() ;
            else {cout << i*mul+it->S[k-1] ; return 0 ;}
        }
        if(i<10 || x<y) for(int j=x+1;j<10;j++)
        {
            auto it=mp[j][1].find(val) ;
            if(it==mp[j][1].end()) continue ;
            if(k>it->S.size()) k-=it->S.size() ;
            else {cout << i*mul+it->S[k-1] ; return 0 ;}
        }
    }
    printf("-1\n") ;
}
