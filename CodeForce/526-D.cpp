#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=1000000+10 ;

int Z[maxn] ;
char s[maxn] ;
vector<pii> v,v2 ;
main()
{
    int n,k ; scanf("%d%d%s",&n,&k,s+1) ;
    if(k==1)
    {
        for(int i=1;i<=n;i++) printf("1") ;
        printf("\n") ; return 0 ;
    }

    Z[1]=0 ;
    for(int i=2,L=-1,R=-1;i<=n;i++)
    {
        int i2=i-L+1 ;
        if(R<i)
        {
            for(R=i;R<=n && s[R]==s[R-i+1];R++) ;
            R-- ; L=i ;
            Z[i]=R-L+1 ;
        }
        else if(i+Z[i2]-1 < R) Z[i]=Z[i2] ;
        else
        {
            for(;R<=n && s[R]==s[R-i+1];R++) ;
            R-- ; L=i ;
            Z[i]=R-L+1 ;
        }
        if(Z[i]>=(LL)(k-1)*(i-1)) v.push_back((pii){k*(i-1),min(i+Z[i]-1,(k+1)*(i-1))}) ;
    }

    sort(v.begin(),v.end()) ;
    for(int i=0,last=-1,now=-1;i<v.size();i++)
    {
        if(v[i].F>now)
        {
            if(last!=-1) v2.push_back((pii){last,now}) ;
            last=v[i].F ; now=v[i].S ;
        }
        else now=max(now,v[i].S) ;
        if(i+1==v.size()) v2.push_back((pii){last,now}) ;
    }

    for(int i=1,j=0;i<=n;i++)
    {
        while(j<v2.size() && v2[j].S<i) j++ ;
        if(j<v2.size() && v2[j].F<=i) printf("1") ;
        else printf("0") ;
    }
    printf("\n") ;
}
