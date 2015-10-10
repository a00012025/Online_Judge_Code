#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100100];
int fa[100100];
int anc[100100];
int chd[100100];
int nodest[100100];
int nodeed[100100];
bool used[100100];
bool notroot[100100];
int cnt;

int dfs1(int s)
{
    used[s] = 1;
    int sz = 1;
    int maxs = 0;
    chd[s] = s;
    fa[s] = s;
    for(int i = 0; i < edge[s].size(); i++)
    {
        int ss = edge[s][i];
        if(!used[ss])
        {
            int temp = dfs1(ss);
            fa[ss] = s;
            sz += temp;
            if(temp > maxs)
            {
                maxs = temp;
                chd[s] = ss;
            }
        }
    }
    return sz;
}

void dfs2(int s, int ld)
{
    nodest[s] = cnt++;
    used[s] = 1;
    anc[s] = ld;
    if(chd[s] != s) dfs2(chd[s], ld);
    for(int i = 0; i < edge[s].size(); i++)
    {
        int ss = edge[s][i];
        if(ss == chd[s]) continue;
        if(!used[ss]) dfs2(ss, ss);
    }
    nodeed[s] = cnt;
}

struct seg_t
{
    struct node
    {
        int st,ed;
        node *l,*r;
        int v, tag;
        node(int a, int b):st(a),ed(b),l(0),r(0),v(0),tag(0){};
    } *root;

    void init(node* s)
    {
        if(s->ed - s->st == 1) return;
        int mid = (s->st + s->ed)/2;
        s->l = new node(s->st, mid);
        s->r = new node(mid, s->ed);
        init(s->l); init(s->r);
    }

    seg_t(int n)
    {
        root = new node(0, n); init(root);
    }

    void modify(int lw, int up, node* s)
    {
        if((lw == s->st)&&(up == s->ed))
        {
            s->tag++;
            return;
        }
        s->l->tag += s->tag;
        s->r->tag += s->tag;
        s->v += s->tag*(s->ed - s->st);
        s->tag = 0;
        if(lw < s->l->ed)
        {
            if(up <= s->l->ed)
            {
                modify(lw, up, s->l);
                return;
            }
            modify(lw, s->l->ed, s->l);
            modify(s->r->st, up, s->r);
            return;
        }
        modify(lw, up, s->r);
    }

    int query(int lw, int up, node* s)
    {
        if((lw == s->st)&&(up == s->ed))
        {
            return (s->ed - s->st)*s->tag + s->v;
        }
        s->l->tag += s->tag;
        s->r->tag += s->tag;
        s->v += s->tag*(s->ed - s->st);
        s->tag = 0;
        if(lw < s->l->ed)
        {
            if(up <= s->l->ed) return query(lw, up, s->l);
            return query(lw, s->l->ed, s->l) + query(s->r->st, up, s->r);
        }
        return query(lw, up, s->r);
    }
} tree(1);

inline bool isp(int a, int b)
{
    return ((nodest[a] <= nodest[b])&&(nodeed[a] > nodest[b]));
}

void put(int a, int b)
{
    if(a==b) return;
    if(anc[a] == anc[b])
    {
        tree.modify(min(nodest[a], nodest[b]), max(nodest[a], nodest[b]), tree.root);
        return;
    }
    if(isp(anc[a], b))
    {
        put(b, a);
        return;
    }
    tree.modify(nodest[anc[a]], nodest[a]+1, tree.root);
    put(fa[anc[a]], b);
}

int query(int a, int b)
{
    if(a==b) return 0;
    if(anc[a] == anc[b]) return tree.query(min(nodest[a], nodest[b]), max(nodest[a], nodest[b]), tree.root);
    if(isp(anc[a],b)) return query(b,a);
    return tree.query(nodest[anc[a]], nodest[a]+1, tree.root) + query(fa[anc[a]], b);
}

int main()
{
    int n,q;
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    cin>>n>>q;
    tree = seg_t(n);
    for(int i = 0; i < n - 1; i++)
    {
        int a,b;
        cin>>a>>b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i = 0 ; i < n; i++) used[i] = 0;
    dfs1(0);
    for(int i = 0 ; i < n; i++) used[i] = 0;
    dfs2(0,0);
    while(q--)
    {
        char c;
        int a,b;
        cin>>c>>a>>b;
        a--;
        b--;
        if(c == 'P') put(a,b);
        else cout<<query(a,b)<<endl;
    }
    return 0;
}
