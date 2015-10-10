#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+10;
vector<int>e[SIZE];
int an,qq[SIZE],n,S,K,la[SIZE],nxt[SIZE];
bool used[SIZE];
priority_queue<pair<int,int> >H;
int L[SIZE][21],R[SIZE][21];
void dfs(int x,int h){
    if(h)la[x]=qq[h-1];
    if(qq[h])nxt[qq[h]]=x;
    qq[h]=x;
    for(int i=0;i<=min(h,K);i++){
        if(!L[qq[h-i]][i])L[qq[h-i]][i]=x;
        R[qq[h-i]][i]=x;
    }
    H.push(make_pair(h,x));
    for(int i=0;i<e[x].size();i++){
        int y=e[x][i];
        if(h&&qq[h-1]==y)continue;
        dfs(y,h+1);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&S,&K);
        an=0;
        memset(used,0,sizeof(used));
        memset(qq,0,sizeof(qq));
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        for(int i=1;i<=n;i++)e[i].clear();
        la[1]=1;
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        dfs(1,0);
        while(!H.empty()){
            pair<int,int> me=H.top();H.pop();
            if(used[me.second])continue;
            while(!used[me.second])
            {
                int now=me.second;
                for(int i=0;i<K;i++)now=la[now];
                int r=S;
                an++;
                for(int i=0;i<=K&&r;i++,now=la[now]){
                    for(int j=0;j<2;j++){
                        if(i+j>K)break;
                        int &you=L[now][K-i-j];
                        while(r&&you){
                            if(!used[you]){
                                used[you]=1;
                                r--;
                            }
                            if(you!=R[now][K-i-j])you=nxt[you];
                            else you=0;
                        }
                    }
                }
            }
        }
        printf("%d\n",an);
    }
    return 0;
}
