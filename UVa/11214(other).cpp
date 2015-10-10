#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 12;
int n,m,num;
char maze[maxn][maxn];
bool vis1[maxn*2],vis2[maxn*2],visi[maxn],visj[maxn];
bool dfs(int d,int st,int maxd){
if(maxd==d){
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++){
        if(maze[i][j]=='X'){
            if(!visi[i]&&!visj[j]&&!vis1[i+j]&&!vis2[i-j+10]) return false;
        }
    }
    printf("%d\n",maxd);
    return true;
}
for(int j=st;j<=n;j++){
    for(int i=1;i<=n;i++){
    if(!visi[i]||!visj[j]||!vis1[i+j]||!vis2[i-j+10]){
        int f1=0,f2=0,f3=0,f4=0;
        if(!visi[i]) {visi[i]=1; f1=1;}
        if(!visj[j]) {visj[j]=1; f2=1;}
        if(!vis1[i+j]){vis1[i+j]=1; f3=1;}
        if(!vis2[i-j+10]){vis2[i-j+10]=1; f4=1;}
        if(dfs(d+1,j+1,maxd)) return true;
        if(f1) visi[i]=0;
        if(f2) visj[j]=0;
        if(f3) vis1[i+j]=0;
        if(f4) vis2[i-j+10]=0;
    }
    }
}
return false;
}
int main()
{
    int kase=1;
    while(scanf("%d %d",&n,&m)==2){
        num=0;
        for(int i=1;i<=n;i++){
            scanf("%s",maze[i]);
            for(int j=m;j>0;j--) {
                maze[i][j]=maze[i][j-1];
                //printf
                if(maze[i][j]=='X') num++;
            }
        }
        //printf("%d\n",num);
        printf("Case %d: ",kase++);
        if(num==0) {
            printf("0\n"); continue;
        }
        for(int maxd=1;;maxd++){
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        memset(visi,0,sizeof(visi));
        memset(visj,0,sizeof(visj));
            if(dfs(0,1,maxd)) break;
        }
    }
return 0;
}

