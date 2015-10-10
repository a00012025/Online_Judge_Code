#include<bits/stdc++.h>
#define LL long long
#define F first
#define S second
#define MOD 2000000099
using namespace std;
const int maxn=2000000+10,X=79 ;

struct manacher
{
    char *s ;
    int n , *Z ;
    int extl(int l,int r)
    {
        int i=1 ;
        for(;l-i+1>=0 && r+i-1<=2*n-2 && s[l-i+1]==s[r+i-1];i++) ;
        return i-1 ;
    }
    void init(char *t)
    {
        n=strlen(t) ;
        s=new char[2*n+2] ;
        Z=new int[2*n+2] ;
        for(int i=0;i<2*n-1;i++) s[i]=(i%2 ? '$' : t[i/2]) ;
        for(int i=0,L=-1,R=-1;s[i];i++)
        {
            int i2=L+R-i ;
            if(R<i) Z[i]=extl(i,i) ;
            else if(Z[i2]!=R-i+1) Z[i]=min(Z[i2],R-i+1) ;
            else Z[i]=extl(2*i-R,R)+(R-i) ;
            if(i+Z[i]-1>=R) L=i-Z[i]+1 , R=i+Z[i]-1 ;
        }
    }
    bool check(int l,int r)
    {
        assert(0<=l && l<=r && r<n) ;
        return Z[r+l]>=r-l+1 ;
    }
    int getlen(int sum)
    {
        return Z[sum] ;
    }
}man[maxn];

bool cmp(int x,int y){return man[x].n>man[y].n ;}

char *s[maxn] ;
LL val[maxn] ;
map<LL,int> mp ;
vector<int> now ;
main()
{
//    freopen("pal5b.in","r",stdin) ;
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++)
    {
        int m ; scanf("%d",&m) ;
        s[i]=new char[m+5] ; scanf("%s",s[i]) ;
        man[i].init(s[i]) ;
    }
    LL ans=0 ;
    now.resize(n) ;
    for(int i=0;i<n;i++) now[i]=i ;
//    sort(now.begin(),now.end(),cmp) ;

    for(int i=0;!now.empty();i++)
    {
        mp.clear() ;
        for(int j=0;j<now.size();j++)
        {
            val[now[j]]=(val[now[j]]*X+(s[now[j]][i]-'a'+1))%MOD ;
            if(man[now[j]].n==i+1) mp[val[now[j]]]++ ;
        }
        for(int j=0;j<now.size();j++) if(man[now[j]].n!=i+1)
        {
            map<LL,int>::iterator it=mp.find(val[now[j]]) ;
            if(it==mp.end()) continue ;
            ans+=2*it->S*(man[now[j]].check(0,man[now[j]].n-i-2) ? 1 : 0) ;
        }
        for(int j=0;j<now.size();j++) if(man[now[j]].n==i+1)
        {
            map<LL,int>::iterator it=mp.find(val[now[j]]) ;
            ans+=2*it->S ;
            it->S-- ;
            swap(now[j],now.back()) ;
            now.pop_back() ;
            j-- ;
        }
    }
    printf("%lld\n",ans-n) ;
}
