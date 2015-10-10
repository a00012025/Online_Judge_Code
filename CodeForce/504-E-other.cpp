#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
const int LOG = 1000;

namespace suf_array {
    static const int MAXLEN = MAXN * 2;
    static const int LOG = 20;
    char s[MAXLEN + 1];
    int n;
    int sa[MAXLEN];
    int lcp[MAXLEN];
    int logTable[MAXLEN];
    int rank[MAXLEN];
    int rmq[LOG + 1][MAXLEN];
    int order[MAXLEN];
    int r[MAXLEN];
    int cnt[MAXLEN];
    int st[MAXLEN];

    bool cmp(int i, int j)  {
        return s[i] < s[j];
    }

    void process()
    {
        for (int i = 0; i < n; i++)
            order[i] = n - 1 - i;

        stable_sort(order, order + n, cmp);

        for (int i = 0; i < n; i++) {
            sa[i] = order[i];
            rank[i] = s[i];
        }

        for (int len = 1; len < n; len <<= 1) {
            memcpy(r, rank, n * sizeof(int));
            for (int i = 0; i < n; i++) {
                rank[sa[i]] = (i > 0 && r[sa[i - 1]] == r[sa[i]] &&
                        sa[i - 1] + len < n && r[sa[i - 1] + len / 2] == r[sa[i] + len / 2])
                        ? rank[sa[i - 1]]
                        : i;
            }
            for (int i = 0; i < n; i++)
                cnt[i] = i;

            memcpy(st, sa, sizeof(int) * n);
            for (int i = 0; i < n; i++) {
                int s1 = st[i] - len;
                if (s1 >= 0)
                    sa[cnt[rank[s1]]++] = s1;
            }
        }
    }

    void calc_lcp() {
        for (int i = 0; i < n; i++)
            rank[sa[i]] = i;
        for (int i = 0, h = 0; i < n; i++) {
            if (rank[i] < n - 1) {
                int j = sa[rank[i] + 1];
                while(max(i, j) + h < n && s[i + h] == s[j + h])
                    ++h;
                lcp[rank[i] + 1] = h;
                if (h > 0)
                    --h;
            }
        }

        logTable[0] = 0;
        logTable[1] = 0;
        for (int i = 2; i < n; i++)
            logTable[i] = logTable[i >> 1] + 1;

        for (int i = 0; i < n; ++i)
            rmq[0][i] = lcp[i];

        for (int k = 1; (1 << k) < n; ++k) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                int x = rmq[k - 1][i];
                int y = rmq[k - 1][i + (1 << k - 1)];
                rmq[k][i] = min(x, y);
            }
        }
    }

    int get_lcp(int l, int r) {
        l = rank[l];
        r = rank[r];
        if (l > r) {
            swap(l, r);
        }
        if (l == r) {
            return n - sa[l];
        }
        ++l;
        int k = logTable[r - l];
        int x = rmq[k][l];
        int y = rmq[k][r - (1 << k) + 1];
        return min(x, y);
    }
};


namespace hld {
    vector <int> g[MAXN];
    int sz[MAXN];
    int p[MAXN];

    int pos_up[MAXN];
    int pos_down[MAXN];

    int r[MAXN];
    int root[MAXN];
    int rt[MAXN];

    int tin[MAXN];
    int tout[MAXN];
    int timer = 0;

    int pos[MAXN];

    vector <int> c[MAXN];

    int pathCount = 0;

    void dfs(int v, int par) {
        p[v] = par;
        sz[v] = 1;
        tin[v] = timer++;
        for (int i = 0; i < (int)g[v].size(); ++i) {
            int to = g[v][i];
            if (to == par) {
                continue;
            }
            dfs(to, v);
            sz[v] += sz[to];
        }
        tout[v] = timer++;
    }

    void decomp(int v, int par, int k) {
        pos[v] = c[k].size();
        c[k].push_back(v);
        root[v] = rt[k];
        r[v] = k;

        int x = 0, y = -1;
        for (int i = 0; i < (int)g[v].size(); ++i) {
            int to = g[v][i];
            if (to == par)
                continue;
            if (sz[to] > x) {
                x = sz[to];
                y = to;
            }
        }
        if (y != -1) decomp(y, v, k);

        for (int i = 0; i < (int)g[v].size(); ++i) {
            int to = g[v][i];
            if (to != par && to != y) {
                rt[pathCount] = to;
                decomp(to, v, pathCount++);
            }
        }
    }
    void initSA(char * s, char * data) {
        int len = 0;
        for (int i = 0; i < pathCount; ++i) {
            for (int j = 0; j < (int)c[i].size(); ++j) {
                int v = c[i][j];
                s[pos_down[v] = len++] = data[v];
            }
            for (int j = (int)c[i].size() - 1; j >= 0; --j) {
                int v = c[i][j];
                s[pos_up[v] = len++] = data[v];
            }
        }
    }

    inline bool upper(int a, int b) {
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    }
    pair <int, int> up[LOG];
    pair <int, int> down[LOG];

    int getHeavySegments(int a, int b, pair <int, int> * res) {
        int sup = 0;
        int sdown = 0;

        while (!upper(root[a], b)) {
            up[sup++] = make_pair(pos_up[a], pos_up[root[a]]);
            a = p[root[a]];
        }
        while (!upper(root[b], a)) {
            down[sdown++] = make_pair(pos_down[root[b]], pos_down[b]);
            b = p[root[b]];
        }
        assert(r[a] == r[b]);
        if (upper(a, b)) {
            down[sdown++] = make_pair(pos_down[a], pos_down[b]);
        } else {
            up[sup++] = make_pair(pos_up[a], pos_up[b]);
        }
        for (int i = 0; i < sup; ++i) {
            *res++ = up[i];
        }
        for (int i = sdown - 1; i >= 0; --i) {
            *res++ = down[i];
        }
        return sup + sdown;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else

#endif
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    char data[n + 1];
    scanf("%s", data);

    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        hld::g[a].push_back(b);
        hld::g[b].push_back(a);
    }

    hld::dfs(0, -1);
    hld::decomp(0, -1, hld::pathCount++);
    hld::initSA(suf_array::s, data);

    suf_array::n = 2 * n;
    suf_array::process();
    suf_array::calc_lcp();

    int m;
    scanf("%d", &m);

    pair <int, int> segsL[LOG];
    pair <int, int> segsR[LOG];

    while (m--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        --a, --b, --c, --d;

        int lsize = hld::getHeavySegments(a, b, segsL);

        int rsize = hld::getHeavySegments(c, d, segsR);

        int i = 0, j = 0;
       int len = 0;
       while (i < lsize && j < rsize) {
           int lcp = suf_array::get_lcp(segsL[i].first, segsR[j].first);
           lcp = min(lcp, segsL[i].second - segsL[i].first + 1);
           lcp = min(lcp, segsR[j].second - segsR[j].first + 1);
           len += lcp;
           segsL[i].first += lcp;
           segsR[j].first += lcp;

           bool ok = false;

           if (segsL[i].first > segsL[i].second) {
               ++i;
               ok = true;
           }

           if (segsR[j].first > segsR[j].second) {
               ++j;
               ok = true;
           }

           if (!ok) {
               break;
           }
       }
        printf("%d\n", len);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms.\n";
#endif // LOCAL
    return 0;
}
