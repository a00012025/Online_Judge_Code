#include <cstdio>
#include <algorithm>
using namespace std;

int data[2][128 * 1024];
int left[17][128 * 1024];

/**
 *  Precondition:  data[17 % 2] is b
 *  Postcondition: left is properly filled
 *                 data[0] is b sorted (though unused)
 *                 data[1][i] = upper_bound(data[0], data[0] + 128 * 1024, i)
 */
void preprocess() {
    for(int d = 16, g = 2; d >= 0; d--, g <<= 1) {
        for(int l = 0; l < 128 * 1024; l += g) {
            int r = l + g, m = (l + r) / 2;
            merge(data[(d + 1) % 2] + l, data[(d + 1) % 2] + m,
                  data[(d + 1) % 2] + m, data[(d + 1) % 2] + r, data[d % 2] + l);
            for(int i = l, j = l; i < r; i++) {
                while(data[(d + 1) % 2][j] <= data[d % 2][i] && j < m)
                    j++;
                left[d][i] = j - l;
            }
        }
    }
    for(int i = 0, j = 0; i < 128 * 1024; i++) {
        while(data[0][j] <= i && j < 128 * 1024)
            j++;
        data[1][i] = j;
    }
}

int query(int hint, int l, int r, int d = 0, int nl = 0, int nr = 128 * 1024) {
    if(l <= nl && nr <= r) {
        return hint;
    } else if(!(r <= nl || nr <= l)) {
        if(hint == 0)
            return 0;
        int lhint = left[d][nl + hint - 1];
        int rhint = hint - lhint;
        return query(lhint, l, r, d + 1, nl, (nl + nr) / 2) +
               query(rhint, l, r, d + 1, (nl + nr) / 2, nr);
    } else {
        return 0;
    }
}

bool ok(int n, int p, int k, int s) {
    return query(data[1][s], max(p - s, 0), min(p + s + 1, n)) >= k;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", data[17 % 2] + i);
    fill(data[17 % 2] + n, data[17 % 2] + 128 * 1024, 1048576);
    preprocess();
    for(int i = 0; i < m; i++) {
        int p, k;
        scanf("%d %d", &p, &k);
        int l = 0, r = n;
        while(l < r) {
            int s = (l + r) / 2;
            ok(n, p, k, s) ? (r = s) : (l = s + 1);
        }
        printf("%d\n", r);
    }
}
