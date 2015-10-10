#include <vector>
#include <list>
#include <map>
#include <string>
#include <set>
#include <cstring>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef unsigned long long LL;
#define MAXD 1000 + 10
int maxd;
LL v[MAXD];
LL ans[MAXD];
vector<LL>vis;
int Case = 1;
LL gcd(LL x,LL y){
    return y == 0 ? x : gcd(y , x % y);
}
LL get_first(LL a,LL b){  /*求出最小的C，使得 1 / c < a / b */
    for(LL c = 1; ; c++){
        if(a * c >= b)
            return c;
    }
}
bool better(int d){
    int cnt = 0;
    for(int i = d ; i >= 0 ; i--)
        if(ans[i] == -1)        return true;
        else {
            if(ans[i] < v[i]) return false;
            else
            if(ans[i] > v[i])
            return true;
        }
}
bool dfs(int d,LL from,LL aa,LL bb){
    if(d == maxd){
        if(bb % aa)   return false;
        v[d] = bb / aa;
        if(better(d)) memcpy(ans,v,sizeof(LL)* (d + 1));
        return true;
    }
    from = max(from,get_first(aa,bb));
    int ok = 0;
    for(LL i = from ; ; i++){
        if(aa * i >= bb * (maxd - d + 1)) break;
        if(find(vis.begin(),vis.end(),i) != vis.end())
            continue;
        v[d] = i;
        LL a2 = aa * i - bb;
        LL b2 = bb * i;
        LL g  = gcd(a2,b2);
        if(dfs(d + 1,i + 1,a2 / g,b2 / g))
            ok = 1;
    }
    return  ok;
}
void solve(LL a,LL b){
    for(maxd = 0; ; maxd ++){
        memset(ans,-1,sizeof(ans));
        int ok = dfs(0,get_first(a,b),a,b);
        if(ok)
            break;
    }
    printf("Case %d: ",Case++);
    printf("%I64d/%I64d=",a,b);
    for(int i = 0 ; i <= maxd ; i++){
        printf("1/%I64d",ans[i]);
        if(i < maxd)
            printf("+");
    }
    printf("\n");
}
int main(){
    int a,b;
    int T;
    scanf("%d",&T);
    while(T--){
        LL a,b;
        vis.clear();
        int k;
        scanf("%I64d%I64d%d",&a,&b,&k);
        for(int i = 0 ; i < k ; i++){
            LL x;
            scanf("%I64d",&x);
            vis.push_back(x);
        }
        solve(a,b);
    }
    return 0;
}
