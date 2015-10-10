#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const unsigned max_n = 100000;
const unsigned max_k = 20;
const unsigned no_parent_node = max_n;

unsigned n, s, k;
vector<unsigned> adjlist[max_n];

unsigned req[max_n][max_k + 1]; // requirement
unsigned exc[max_n][max_k + 1]; // excess

unsigned dfs(unsigned node, unsigned parent){
    unsigned used = 0;
    for(unsigned i = 0; i < adjlist[node].size(); i++){
        unsigned child = adjlist[node][i];
        if(child != parent){
            used += dfs(child, node);
            for(unsigned j = 0; j < k; j++)
                req[node][j + 1] += req[child][j];
            for(unsigned j = 0; j < k; j++)
                exc[node][j] += exc[child][j + 1];
        }
    }
    req[node][0] = 1;
    exc[node][k] = (req[node][k] + s - 1) / s * s;
    used += (req[node][k] + s - 1) / s;
    if(parent == no_parent_node){
        // used up what can be used
        for(unsigned i = 0; i <= k; i++){
            for(unsigned j = 0; j <= i; j++){
                unsigned c = min(req[node][j], exc[node][i]);
                req[node][j] -= c;
                exc[node][i] -= c;
            }
        }
        // need to provide more
        unsigned still = 0;
        for(unsigned i = 0; i <= k; i++){
            still += req[node][i];
        }
        used += (still + s - 1) / s;
    } else {
        // used up what must be used
        for(unsigned i = 0; i <= k; i++){
            unsigned c = min(req[node][i], exc[node][i]);
            req[node][i] -= c;
            exc[node][i] -= c;
        }
        for(unsigned i = 0; i + 1 <= k; i++){
            unsigned c = min(req[node][i], exc[node][i + 1]);
            req[node][i] -= c;
            exc[node][i + 1] -= c;
        }
        // procrastination
    }
//    cerr << node << " " << parent << " " << used << endl;
    return used;
}

int main(){
    cin >> n >> s >> k;
    for(unsigned i = 0; i < n - 1; i++){
        unsigned x, y;
        cin >> x >> y;
        x--;
        y--;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    cout << dfs(0, no_parent_node) << endl;
}
