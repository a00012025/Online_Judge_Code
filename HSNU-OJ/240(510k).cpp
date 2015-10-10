#include<bits/stdc++.h>
using namespace std;
vector<string> arr[10];
char s[10];
int dic[1005][26],ch[26];
int dfs(int len,int cnt,vector<int> S){
    if(cnt==len+1) return 1;
    if(S.size()<=1) return 0;
    for(int i=0;i<26;i++){
        if(ch[i]) continue;
        ch[i]=1;
        int tmp=0;
        vector<int> U[8];
        for(int j=0;j<S.size();j++){
            int u=S[j];
            if(dic[u][i]==-1) U[len].push_back(u);
            else U[dic[u][i]].push_back(u);
        }
        if(U[len].size()==S.size()){
            ch[i]=0;
            continue;
        }
        for(int j=0;j<len;j++){
            if(U[j].size()) tmp|=dfs(len,cnt,U[j]);
        }
        tmp|=dfs(len,cnt+1,U[len]);
        ch[i]=0;
        if(tmp==0) return 0;
    }
    return 1;
}
int main(){
    int t,n,m,i,j,k,x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<7;i++)
            arr[i].clear();
        while(n--){
            scanf("%s",s);
            arr[strlen(s)].push_back(string(s));
        }
        int flag=0;
        for(i=1;i<7;i++){
            memset(ch,0,sizeof(ch));
            memset(dic,-1,sizeof(dic));
            vector<int> S;
            for(j=0;j<arr[i].size();j++){
                S.push_back(j);
                for(k=0;k<i;k++){
                    dic[j][arr[i][j][k]-'A']=k;
                }
            }
            if(S.size()) flag|=dfs(i,0,S);
            if(flag) break;
        }
        if(flag) puts("Yes");
        else puts("No");
    }
}
