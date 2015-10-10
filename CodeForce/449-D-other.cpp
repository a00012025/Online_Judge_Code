#include <cstdio>
#include <bitset>
using namespace std;

constexpr int module = 1000000007;

int p2[1000000];
int dp[21][1048576];

int main(){
    int n;
    scanf("%d", &n);
    p2[0] = 1;
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        dp[0][a]++;
        p2[i + 1] = (p2[i] << 1) % module;
    }
    int add = 0, minu = 0;
    for(int i = 1048575; i >= 0; i--) {
        for(int d = 0; d < 20; d++) {
            if((i >> d) & 1)
                dp[d + 1][i] = dp[d][i];
            else
                dp[d + 1][i] = (dp[d][i] + dp[d][i + (1 << d)]) % module;
        }
        if(i<8) for(int d=0;d<20;d++) printf("dp[%d][%d]=%d\n",d,i,dp[d][i]) ;
        if(bitset<20>(i).count() & 1) {
            minu = (minu + p2[dp[20][i]]) % module;
        } else {
            add = (add + p2[dp[20][i]]) % module;
        }
    }
    add -= minu;
    if(add < 0)
        add += module;
    printf("%d\n", add);
}
