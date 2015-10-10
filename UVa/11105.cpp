#include<bits/stdc++.h>
using namespace std;
const int maxn=1000100 ;
bool h[maxn],vis[maxn] ;
int cnt,ans[maxn] ;
vector<int> hsp ;
void pre_cal()
{
    for(int i=1;4*i+1<maxn;i++) h[4*i+1]=1 ;
    for(int i=5;i*i<maxn;i+=4) for(int j=i;i*j<maxn;j+=4)
        h[i*j]=0 ;
    hsp.clear() ;
    for(int i=5;i*i<maxn;i+=4) if(h[i])
    for(int j=i;i*j<maxn;j+=4) if(h[j])
        hsp.push_back(i*j) ;
    sort(hsp.begin(),hsp.end()) ;
    hsp.resize(unique(hsp.begin(),hsp.end())-hsp.begin()) ;
    memset(ans,0,sizeof(ans)) ;
    for(int i=0;i<hsp.size();i++) ans[hsp[i]]=1 ;
    for(int i=1;i<maxn;i++) ans[i]+=ans[i-1] ;
}

main()
{
    pre_cal() ;
    int n ;
    while(scanf("%d",&n)==1 && n) printf("%d %d\n",n,ans[n]) ;
}
