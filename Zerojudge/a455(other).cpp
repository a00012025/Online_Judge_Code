#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int M,N,box[50],item[1000];
bool IDDFS(int n, int prev_b) {
    if(n == -1)
        return 1;
    int anchor=0;
    if(n != N-1 && item[n] == item[n+1]) // N : item small -> big
        anchor = prev_b;                // M : box
    for(int i=anchor; i<M; i++) {
        if(box[i] >= item[n]) {
            if(i != 0 && box[i] == box[i-1])
                continue;
            box[i] -= item[n];
            bool result=IDDFS(n-1, i);
            box[i] += item[n];
            if(result)
                return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &M, &N);
    for(int i=0; i<M; i++)
        scanf("%d", &box[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &item[i]);
    sort(box, box+M, greater<int>());
    sort(item, item+N);
    int sum_b=0,sum_i=0;
    for(int i=0; i<M; i++)
        sum_b += box[i];
    int ans=0;
    for(int depth=1; depth<=N; depth++) {
        sum_i += item[depth-1];
        if(sum_i > sum_b)
            break;
        if(!IDDFS(depth-1, -1))
            break;
        ans = depth;
    }
    printf("%d\n", ans);
    return 0;
}
