#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;
typedef pair<int,int> pii;
vector<pii> edge[100];
vector<pii> dp[300];
int deg[100];
int num[300];
int ch[300][2];
int ds[300][2];
bool used[300];
int m;

struct mycmp
{
    bool operator()(const pii& x, const pii& y){return ((x.second == y.second)?(x.first > y.first):x.second>y.second);}
} Cmp;

void build_dfs(int s)
{
    used[s] = 1;
    ch[s][0] = ch[s][1] = -1;
    if(!deg[num[s]]) return;
    pii temp;
    for(int i = 0; i < edge[num[s]].size(); i++)
        if(!used[edge[num[s]][i].first])
    {
        temp = edge[num[s]][i];
        break;
    }
    deg[num[s]]--; deg[temp.first]--;
    ch[s][0] = temp.first, ds[s][0] = temp.second;
    build_dfs(ch[s][0]);
    if(!deg[num[s]]) return;
    ch[s][1] = n;
    num[n] = num[s];
    n++;
    build_dfs(ch[s][1]);
}

int mlw(const vector<pii>& vp, int a, int i)
{
    if(i == 1) return lower_bound(vp.begin(), vp.end(), pii(a,-2147483648))-vp.begin();
    return lower_bound(vp.begin(), vp.end(), pii(2147483647,a), Cmp)-vp.begin();
}

int mup(const vector<pii>& vp, int a, int i)
{
    if(i == 1) return upper_bound(vp.begin(), vp.end(), pii(a,2147483647))-vp.begin();
    return upper_bound(vp.begin(), vp.end(), pii(-2147483648,a), Cmp)-vp.begin();
}

bool dp_dfs(int s)
{
    dp[s].clear();
    if(ch[s][0] == -1)
    {
        dp[s].push_back(pii(0,0));
        return 1;
    }
    if(!dp_dfs(ch[s][0])) return 0;
    if(ch[s][1] == -1)
    {
        for(int i = 0; i < dp[ch[s][0]].size(); i++)
        {
            pii ii = dp[ch[s][0]][i];
            int lw = max(ds[s][0]/60, (-m+ii.first+ds[s][0]+59)/60);
            int up = min((ds[s][0]+59)/60, (m-ii.second+ds[s][0])/60);
            for(int j = lw; j <= up; j++) dp[s].push_back(pii(max(0,ii.first+ds[s][0]-j*60), max(0,ii.second+j*60-ds[s][0])));
        }
    }
    else
    {
        if(!dp_dfs(ch[s][1])) return 0;
        int ilw = ds[s][0]/60, iup = (ds[s][0]+59)/60, jlw = ds[s][1]/60, jup = (ds[s][1]+59)/60;
        for(int i = ilw; i <= iup; i++) for(int j = jlw; j <= jup; j++)
        {
            int de[2];
            de[0] = i*60 - ds[s][0], de[1] = j*60 - ds[s][1];
            for(int k = 0; k < 2; k++)
            {
                int kk = (k+1)%2;
                for(int t = 0; t < dp[ch[s][k]].size(); t++)
                {
                    pii tt = dp[ch[s][k]][t];
                    if((-tt.first + de[k] < -m)||(tt.second + de[k] > m)) continue;
                    int up = mup(dp[ch[s][kk]], min(tt.first+de[kk]-de[k],min(de[kk]+m,m-tt.first+de[0]+de[1])), 1);
                    int lw = mlw(dp[ch[s][kk]], min(m-de[kk], m-tt.second-de[0]-de[1]), 2);
                    if(up <= lw) continue;
                    pii res = dp[ch[s][kk]][up-1];
                    if((abs(-res.first-tt.first+de[0]+de[1])>m)||(abs(res.second+tt.second+de[0]+de[1])>m))continue;
                if((abs(-res.first+de[kk])>m)||(abs(res.second+de[kk])>m)||(abs(-tt.first+de[k])>m)||(abs(tt.second+de[k])>m))continue;
                    dp[s].push_back(pii(max(0,max(tt.first-de[k],res.first-de[kk])), max(0,max(tt.second+de[k], res.second+de[kk]))));
                }
            }
        }
    }
    if(dp[s].empty()) return 0;
    sort(dp[s].begin(), dp[s].end());
    vector<bool> tag(dp[s].size(), 0);
    for(int i = 0; i < dp[s].size(); i++)
        if((i>0) && (dp[s][i].second >= dp[s][i-1].second)) tag[i] = 1;
    for(int i = 0; i < dp[s].size(); i++) if(tag[i])
    {
        swap(dp[s][i], dp[s].back());
        dp[s].pop_back();
        swap(tag[i], tag[dp[s].size()]);
        i--;
    }
    sort(dp[s].begin(), dp[s].end());
    return 1;
}

bool check(int mt)
{
    m = mt;
    return dp_dfs(0);
}

int bs(int lw, int up)
{
    if(up-lw == 1) return lw;
    int mid = (lw+up)/2;
    if(check(mid-1)) return bs(lw, mid);
    return bs(mid, up);
}

int main()
{
    freopen("tree","r",stdin) ;
//    freopen("out2","w",stdout) ;
    while(1)
    {
        cin>>n;
        cnt++;
        if(n == 0) return 0;
        for(int i = 0; i < n; i++) edge[i].clear(), used[i] = deg[i] = 0;
        for(int i = 0; i < n-1; i++)
        {
            int a,b,t;
            cin>>a>>b>>t;
            a--; b--;
            edge[a].push_back(pii(b,t));
            edge[b].push_back(pii(a,t));
            deg[a]++, deg[b]++;
        }
        for(int i = 0; i < n; i++) num[i] = i;
        build_dfs(0);
        cout<<"Case "<<cnt<<": "<<bs(0, 6010)<<endl;
    }
    return 0;
}
