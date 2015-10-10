#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;

struct E
{
    ll t, c;
    E(ll _t, ll _c){ t = _t; c = _c; }
};

vector<E> v[1000001];
bool visit[1000001]; bool is_br[1000001];
stack<E> stk; vector<E> br;
ll mx; ll Ans = 0; bool OK;

ll N, M;

void DFS(ll O, ll P, ll D)
{
    visit[O] = true;

    bool sec = false;

    for(ll vi = 0, vn = v[O].size(); vi < vn; vi++)
    {
        ll t = v[O][vi].t;
        ll c = v[O][vi].c;

        if( t == P && D == c && !sec )
        {
            sec = true;
            continue;
        }

        if( visit[t] )
        {
            if( OK ) continue;
            OK = true;
            br.push_back(v[O][vi] );
            is_br[t] = true;

            while( !stk.empty() && stk.top().t != t )
            {
                br.push_back(stk.top() );
                is_br[stk.top().t] = true;
                stk.pop();
            }
        }
        else stk.push(v[O][vi] ), DFS(t, O, c);
    }

    if( !OK ) stk.pop();
}

ll DP(ll O, ll P)
{
    ll re = 0;

    for(ll vi = 0, vn = v[O].size(); vi < vn; vi++)
    {
        ll t = v[O][vi].t;
        ll c = v[O][vi].c;

        if( is_br[t] || t == P ) continue;

        ll p = DP(t, O)+c;

        mx = max(mx, re+p);
        re = max(re, p);
    }

    return re;
}

void process()
{
    mx = 0;
    ll dis_clk = 0;

    deque<E> deq;

    for(ll bi = 0, bn = br.size(); bi < bn*2; bi++)
    {
        ll dep = DP(br[bi%bn].t, br[bi%bn].t);
        ll dis = dis_clk;
        //printf("d d %lld %lld", dep, dis); puts("");
        dis_clk += br[bi%bn].c;

        while( !deq.empty() && bi-deq.front().t >= bn ) deq.pop_front();

        ll p = 0;
        if( deq.empty() )
        {
            p = dep;
        }
        else
        {
            p = dep+dis+deq.front().c;
        }

        mx = max(mx, p);

        while( !deq.empty() )
        {
            if( deq.back().c > dep-dis ) break;
            else deq.pop_back();
        }

        deq.push_back(E(bi, dep-dis) );
    }

    //Ans += mx;
}

int main()
{
    scanf("%lld", &N);

    for(ll Ni = 1; Ni <= N; Ni++)
    {
        ll x, l;
        scanf("%lld %lld", &x, &l);

        v[Ni].push_back(E(x, l) );
        v[x].push_back(E(Ni, l) );
    }

    fill(visit, visit+1000001, false);
    fill(is_br, is_br+1000001, false);

    for(ll Ni = 1; Ni <= N; Ni++)
    {
        if( !visit[Ni] )
        {
            while( !stk.empty() ) stk.pop();
            stk.push(E(Ni, 0) );
            OK = false;

            br.clear();
            DFS(Ni, Ni, 0);
            process();
        }
    }

    printf("%lld", Ans); puts("");
}
