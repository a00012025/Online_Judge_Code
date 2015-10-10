#include<bits/stdc++.h>
using namespace std;
long long int s[1005],n,m,ans;
void dfs(long long int u,long long int add){
    if(u==n){
        if(ans==-1 || add^m>ans) ans=add^m;
        return;
    }
    dfs(u+1,add);
    dfs(u+1,add^s[u]);
}
int main(){
    long long int t,i,j,x,y;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        ans=-1;
        for(i=0;i<n;i++){
            scanf("%lld",&s[i]);
        }
        if(n>20) continue;
        dfs(0,0);
        printf("%lld\n",ans);
    }
}
