#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int max_n = 100000;
constexpr int max_k = 20;

int n, s, k;
vector<int> adj[max_n];

int supply[max_n][max_k + 1];
int demand[max_n][max_k + 1];

int dfs(int x, int p) {
    int extinguisher = 0;
    for(int c : adj[x]) {
        if(c != p) {
            extinguisher += dfs(c, x);
            for(int i = 0; i < k; i++) {
                supply[x][i] += supply[c][i + 1];
                demand[x][i + 1] += demand[c][i];
            }
        }
    }
    demand[x][0] = 1;
    supply[x][k] = (demand[x][k] + s - 1) / s * s;
    extinguisher += (demand[x][k] + s - 1) / s;

    for(int i = 0; i <= k; i++) {
        int c = min(supply[x][i], demand[x][i]);
        supply[x][i] -= c;
        demand[x][i] -= c;
    }
    for(int i = 0; i < k; i++) {
        int c = min(supply[x][i + 1], demand[x][i]);
        supply[x][i + 1] -= c;
        demand[x][i] -= c;
    }

    return extinguisher;
}

int main(){
    scanf("%d %d %d", &n, &s, &k);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int extinguisher = dfs(0, -1);
    for(int i = 0; i <= k; i++)
        for(int j = 0; j <= i; j++) {
            int c = min(supply[0][i], demand[0][j]);
            supply[0][i] -= c;
            demand[0][j] -= c;
        }

    extinguisher += (accumulate(demand[0], demand[0] + k + 1, 0) + s - 1) / s;
    printf("%d\n", extinguisher);
}

