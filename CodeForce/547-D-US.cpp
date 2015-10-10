#include <bits/stdc++.h>
using namespace std;

int x[2][300000];
vector<int> p[2][300000];
bool nocircle[2][300000];
int used[300000];
int pos[300000];
int color[300000];
int n;
int dfsid = 1;
int tempd;

int dfs(int s, int d)
{
    if(color[s])
    {
        return -1;
    }
    if(nocircle[d][s])
    {
        return -1;
    }
    used[s] = dfsid;
    pos[s] = d;
    for(int i = 0; i < p[d][x[d][s]].size(); i++)
    {
        int k = p[d][x[d][s]][i];
        if(k==s)
        {
            continue;
        }
        if(used[k] == dfsid)
        {
            color[s] = 1+d;
            tempd = d;
            used[s] = 0;
            return x[d][s];
        }
    }
    for(int i = 0; i < p[d][x[d][s]].size(); i++)
    {
        int k = p[d][x[d][s]][i];
        if(k==s)
        {
            continue;
        }
        int ans = dfs(k,1-d);
        if(ans == x[tempd][s])
        {
            color[s] = 1+d;
            used[s] = 0;
            return -1;
        }
        else if(ans >= 0)
        {
            color[s] = 1+d;
            used[s] = 0;
            return ans;
        }
    }
    nocircle[d][s] = 1;
    return -1;
}

void paint_color(int s, int d, int c)
{
    color[s] = c;
    int nowc = 3-c;
    for(int i = 0; i < p[d][x[d][s]].size(); i++)
    {
        int k = p[d][x[d][s]][i];
        if(color[k])
        {
            continue;
        }
        paint_color(k,1-d,nowc);
        nowc = 3-nowc;
    }
}

map<int,int> mx,my ;
int main()
{
    if(fopen("in","r"))
        freopen("in","r",stdin) ;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d",&x[0][i],&x[1][i]);
        p[0][x[0][i]].push_back(i);
        p[1][x[1][i]].push_back(i);
    }
    int nowind = 0;
    while(1)
    {
        while((nowind < n)&&(color[nowind]))
        {
            nowind++;
        }
        if(nowind >= n)
        {
            break;
        }
        if(dfs(nowind,0) == -1)
        {
            dfsid++;
            if(dfs(nowind,1) == -1)
            {
                if(!color[nowind])
                {
                    paint_color(nowind,0,1);
                    paint_color(nowind,1,1);
                }
            }
        }
        dfsid++;
    }

    for(int i=0;i<n;i++)
    {
        mx[x[0][i]]+=(color[i]==1 ? 1 : -1) ;
        my[x[1][i]]+=(color[i]==1 ? 1 : -1) ;
    }
    for(auto it : mx) if(it.second>1 || it.second<-1)
    {
        printf("%d\n",n) ;
        for(int i=0;i<n;i++) printf("%d %d\n",x[0][i],x[1][i]) ;
    }
    for(auto it : my) if(it.second>1 || it.second<-1)
    {
        printf("%d\n",n) ;
        for(int i=0;i<n;i++) printf("%d %d\n",x[0][i],x[1][i]) ;
    }
    return 0 ;

    for(int i = 0; i < n; i++)
    {
        printf("%c",(color[i]==1?'r':'b'));
    }
    return 0;
}
