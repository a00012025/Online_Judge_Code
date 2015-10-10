#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory>

using namespace std;

using ull = unsigned long long;

ull gcd(ull a, ull b){ return b ? gcd(b, a % b) : a; }

struct Tree2 {
    int c1, c2;
    Tree2 *lc, *rc;
    ull gcd;
    Tree2(int cc1, int cc2) : c1(cc1), c2(cc2), lc(nullptr), rc(nullptr), gcd(0) {}

    static void ensure(Tree2*& t, int x, int c1, int c2) {
        if(!t) {
            t = new Tree2(x, x + 1);
        } else if(x < t->c1 || t->c2 <= x) {
            while((x < (c1 + c2) / 2) == (t->c1 < (c1 + c2) / 2))
                ((x < (c1 + c2) / 2) ? c2 : c1) = (c1 + c2) / 2;
            Tree2 * t2 = new Tree2(c1, c2);
            ((t->c1 < (c1 + c2) / 2) ? t2->lc : t2->rc) = t;
            t2->gcd = t->gcd;
            t = t2;
        }
    }

    void update(int q, ull k) {
        if(c1 + 1 == c2) {
            gcd = k;
        } else {
            if(q < (c1 + c2) / 2) {
                ensure(lc, q, c1, (c1 + c2) / 2);
                lc->update(q, k);
            } else {
                ensure(rc, q, (c1 + c2) / 2, c2);
                rc->update(q, k);
            }
            gcd = 0;
            if(lc) gcd = ::gcd(gcd, lc->gcd);
            if(rc) gcd = ::gcd(gcd, rc->gcd);
        }
    }

    ull query(int q, int v) {
        if(q <= c1 && c2 <= v) {
            return gcd;
        } else if(!(v <= c1 || c2 <= q)){
            ull ans = 0;
            if(lc) ans = ::gcd(ans, lc->query(q, v));
            if(rc) ans = ::gcd(ans, rc->query(q, v));
            return ans;
        } else {
            return 0;
        }
    }

    Tree2* copy() {
        Tree2 * that = new Tree2(c1, c2);
        if(lc) that->lc = lc->copy();
        if(rc) that->rc = rc->copy();
        that->gcd = gcd;
        return that;
    }
};

struct Tree {
    int r1, c1, r2, c2;
    Tree *lc, *rc;
    Tree2 t2;
    Tree(int rr1, int cc1, int rr2, int cc2) : r1(rr1), c1(cc1), r2(rr2), c2(cc2), lc(nullptr), rc(nullptr), t2(c1, c2) {}

    static void ensure(Tree*& t, int x, int r1, int c1, int r2, int c2) {
        if(!t) {
            t = new Tree(x, c1, x + 1, c2);
        } else if(x < t->r1 || t->r2 <= x) {
            while((x < (r1 + r2) / 2) == (t->r1 < (r1 + r2) / 2))
                ((x < (r1 + r2) / 2) ? r2 : r1) = (r1 + r2) / 2;
            Tree * t2 = new Tree(r1, c1, r2, c2);
            ((t->r1 < (r1 + r2) / 2) ? t2->lc : t2->rc) = t;
            t2->t2 = *unique_ptr<Tree2>(t->t2.copy());
            t = t2;
        }
    }

    void update(int p, int q, ull k) {
        if(r1 + 1 == r2) {
            t2.update(q, k);
        } else {
            if(p < (r1 + r2) / 2) {
                ensure(lc, p, r1, c1, (r1 + r2) / 2, c2);
                lc->update(p, q, k);
            } else {
                ensure(rc, p, (r1 + r2) / 2, c1, r2, c2);
                rc->update(p, q, k);
            }
            ull gcd = 0;
            if(lc) gcd = ::gcd(gcd, lc->t2.query(q, q + 1));
            if(rc) gcd = ::gcd(gcd, rc->t2.query(q, q + 1));
            t2.update(q, gcd);
        }
    }

    ull query(int p, int q, int u, int v) {
        if(p <= r1 && r2 <= u) {
            return t2.query(q, v);
        } else if(!(u <= r1 || r2 <= p)){
            ull ans = 0;
            if(lc) ans = ::gcd(ans, lc->query(p, q, u, v));
            if(rc) ans = ::gcd(ans, rc->query(p, q, u, v));
            return ans;
        } else {
            return 0;
        }
    }
};

int main(){
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);

    Tree tree(0, 0, r, c);

    while(n--){
        int cmd;
        scanf("%d", &cmd);
        if(cmd == 1) {
            int p, q; ull k;
            scanf("%d %d %llu", &p, &q, &k);
            tree.update(p, q, k);
        } else if(cmd == 2) {
            int p, q, u, v;
            scanf("%d %d %d %d", &p, &q, &u, &v);
            u++, v++;
            printf("%llu\n", tree.query(p, q, u, v));
        }
    }
}
