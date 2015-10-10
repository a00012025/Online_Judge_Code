#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define x first
#define y second
#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)
#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))

using namespace std;

template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

typedef long double ld; typedef unsigned int uint; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR;

typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

const int MAXN = 1000001;
const int LOG = 20;

int n;

long long mod = 1000000007;
long long p = 31;
long long revP = 129032259;
long long powers[MAXN + 1];
long long rpowers[MAXN + 1];


void initHashes() {
    powers[0] = rpowers[0] = 1;
    for (int j = 0; j <= n; ++j) {
        powers[j + 1] = powers[j] * p % mod;
        rpowers[j + 1] = rpowers[j] * revP % mod;
    }
}

int up[LOG][MAXN];

vector <int> g[MAXN];

long long UP[MAXN];
long long DOWN[MAXN];

char str[MAXN + 1];

int tin[MAXN];
int tout[MAXN];
int h[MAXN];

int timer = 0;

void dfs(int v, int par) {
    tin[v] = timer++;
    up[0][v] = par;
    for (int i = 1; i < LOG; ++i) {
        up[i][v] = up[i - 1][up[i - 1][v]];
    }
    for (int i = 0; i < (int)g[v].size(); ++i) {
        int to = g[v][i];
        if (to == par) continue;
        h[to] = h[v] + 1;
        UP[to] = (UP[v] + (str[to] - 'a' + 1) * powers[h[to] - 1]) % mod;
        DOWN[to] = (DOWN[v] * p + str[to] - 'a' + 1) % mod;

        dfs(to, v);
    }
    tout[v] = timer++;
}

inline long long getUp(int v1, int v2) {
    long long res;
    res = (UP[v1] - UP[up[0][v2]] + mod) * rpowers[h[v2] - 1];

    if (res >= mod) {
        res %= mod;
    }

    return res;
}

inline long long getDown(int v1, int v2) {
    long long res = DOWN[v2] - DOWN[v1] * powers[h[v2] - h[v1]] % mod + mod;

    if (res >= mod) {
        res -= mod;
    }
    return res;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
    if (upper(a, b)) {
        return a;
    }
    if (upper(b, a)) {
        return b;
    }
    for (int i = LOG - 1; i >= 0; --i) {
        if (!upper(up[i][a], b)) {
            a = up[i][a];
        }
    }
    return up[0][a];
}

int get(int v, int k) {
    for (int i = 0; i < LOG; ++i) {
        if (k & (1 << i)) {
            v = up[i][v];
        }
    }
    return v;
}
/*
long long getHash(int a, int b, int l, int cnt) {
    int len = h[a] + h[b] - 2 * h[l] + 1;
    if (cnt > h[a] - h[l] + 1) {
        long long h1 = getUp(a, l);
        int v = get(b, len - cnt);
        long long h2 = getDown(l, v);
        h2 -= (str[l] - 'a' + 1) * powers[h[v] - h[l]] % mod;
        if (h2 < 0) {
            h2 += mod;
        }
        return (h1 * powers[h[v] - h[l]] + h2) % mod;
    } else {
        int v = get(a, cnt - 1);
        return getUp(a, v);
    }
}
*/
const int M = 1000000;

int a[M][2], b[M][2], lc[M][2], res[M * 2], needH[M * 2], l[M], r[M], len[M][2];

long long hashToLca[M][2];

int * queries[MAXN];

int sz[MAXN];

int cnt[MAXN];

int pos = 0;

int st[MAXN];
int ptr[MAXN];
char used[MAXN];

inline void dfsQ(int v, int par) {
    st[pos] = v;
    ptr[pos] = 0;
    ++pos;

    while (pos) {
        v = st[pos - 1];
        int & i = ptr[pos - 1];

        if (i == 0) {
            used[v] = 1;
            for (int j = 0; j < sz[v]; ++j) {
                int q = queries[v][j];
                res[q] = st[pos - needH[q] - 1];
            }
            sz[v] = 0;
        }

        if (i < (int)g[v].size()) {
            int to = g[v][i++];
            if (!used[to]) {
                st[pos] = to;
                ptr[pos] = 0;
                ++pos;
            }
        } else {
            used[v] = 0;
            --pos;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else

#endif
    ios_base::sync_with_stdio(false);

    scanf("%d", &n);
    initHashes();

    scanf("%s", str);

    for (int i = 0; i + 1 < n; ++i) {
        int s, t;
        scanf("%d%d", &s, &t);
        --s, --t;
        g[s].push_back(t);
        g[t].push_back(s);
    }

    g[n].push_back(0);

    dfs(n, n);

    int q;
    scanf("%d", &q);

    //cerr << getlong long(0, 2, 0, 3).h[0] << endl;

    //cerr << 31 * 31 * 1 + 31 * 2 + 2 << endl;

    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d%d", &a[i][j], &b[i][j]);
            --a[i][j], --b[i][j];
            int A = a[i][j];
            int B = b[i][j];
            cnt[A]++;
            cnt[B]++;
            int C = lc[i][j] = lca(A, B);
            len[i][j] = h[A] + h[B] - 2 * h[C] + 1;
            hashToLca[i][j] = getUp(A, C) - DOWN[C];
            if (hashToLca[i][j] < 0) {
                hashToLca[i][j] += mod;
            }
        }
        l[i] = 0;
        r[i] = min(len[i][0], len[i][1]);
    }

    for (int i = 0; i < n; ++i) {
        queries[i] = new int[cnt[i]];
    }

    while (true) {
        bool ok = true;
        for (int i = 0; i < q; ++i) {
            if (l[i] == r[i]) {
                continue;
            }
            ok = false;
            int m = (l[i] + r[i] + 1) >> 1;
            for (int j = 0; j < 2; ++j) {
                if (m > h[a[i][j]] - h[lc[i][j]]) {
                    needH[i * 2 + j] = len[i][j] - m;
                    queries[b[i][j]][sz[b[i][j]]++] = i * 2 + j;
                } else {
                    needH[i * 2 + j] = m;
                    queries[a[i][j]][sz[a[i][j]]++] = i * 2 + j;
                }
            }
        }
        if (ok) {
            break;
        }

        dfsQ(0, 0);

        for (int i = 0; i < q; ++i) {
            if (l[i] == r[i]) {
                continue;
            }
            int m = (l[i] + r[i] + 1) >> 1;
            long long ha[2];
            for (int j = 0; j < 2; ++j) {
                if (m > h[a[i][j]] - h[lc[i][j]]) {
                    int v = res[i * 2 + j];
                    ha[j] = hashToLca[i][j] * powers[h[v] - h[lc[i][j]]] + DOWN[v];
                } else {
                    int v = res[i * 2 + j];
                    ha[j] = (UP[a[i][j]] - UP[v] + mod) * rpowers[h[v]];
                }
            }
            if ((ha[0] - ha[1]) % mod == 0) {
                l[i] = m;
            } else {
                r[i] = m - 1;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        printf("%d\n", l[i]);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms.\n";
#endif // LOCAL
    return 0;
}
