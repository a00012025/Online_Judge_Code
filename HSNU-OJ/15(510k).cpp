#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
struct P{
    int v,c;
};
vector<int> arr;
vector<P> s[105],r;
int ma[105][105]={0},is[105]={0},ans=-1;
int dfs(int u,int fa){
    int i,j,x,y;
    r.clear();
    for(i=0;i<s[u].size();i++){
        int v=s[u][i].v;
        if(is[v]){
            r.push_back(s[u][i]);
        }
    }
    for(i=0;i<r.size();i++){
        for(j=0;j<r.size();j++){
            if(i==j) continue;
            if(r[i].c+r[j].c+ma[r[i].v][r[j].v]<ans || ans==-1)
                ans=r[i].c+r[j].c+ma[r[i].v][r[j].v];
        }
    }
    for(i=0;i<arr.size();i++){
        for(j=0;j<arr.size();j++){
            x=arr[i],y=arr[j];
            if(i==j) continue;
            if(ma[y][x] && ma[x][u] && (ma[y][x]+ma[x][u]<ma[y][u] || ma[y][u]==0))
                ma[y][u]=ma[u][y]=ma[y][x]+ma[x][u];
        }
    }
    for(i=0;i<arr.size();i++){
        for(j=0;j<arr.size();j++){
            x=arr[i],y=arr[j];
            if(i==j) continue;
            if(ma[x][u] && ma[u][y] && (ma[x][u]+ma[u][y]<ma[x][y] || ma[x][y]==0))
                ma[x][y]=ma[y][x]=ma[x][u]+ma[y][u];
        }
    }
    arr.push_back(u);
    for(i=0;i<s[u].size();i++){
        int v=s[u][i].v;
        if(is[v]==0){
            is[v]=1;
            dfs(v,u);
        }
    }
}
int main(){
    int n,m,i,j,x,y,z;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&z);
        if(ma[x][y]==0 || z<ma[x][y]){
            ma[x][y]=ma[y][x]=z;
        }
    }
    //return 0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(ma[i][j]){
                s[i].push_back((P){j,ma[i][j]});
            }
        }
    }
    for(i=1;i<=n;i++){
        if(is[i]==0){
            is[i]=1;
            dfs(i,-1);
        }
    }
    if(ans==-1) puts("No solution.");
    else printf("%d\n",ans);
}
