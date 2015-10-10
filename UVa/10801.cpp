#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
typedef struct {int id,ed,w ;} P ;
vector<P> v[101] ;
vector<int> floor ;
queue<int> q ;
bool inqueue[200] ;
main()
{
    int n,k,time[101] ;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=0;i<=100;i++) v[i].clear() ;
        while(!q.empty()) q.pop();
        for(int i=1;i<=n;i++) scanf("%d",&time[i]) ;
        for(int x=1;x<=n;x++)
        {
            char s[500] ;
            gets(s) ;
            while(s[0]>'9' || s[0]<'0') gets(s) ;
            floor.clear() ;
            for(int i=0;i<strlen(s);)
            {
                int a ;
                sscanf(&s[i],"%d",&a) ;
                floor.push_back(a) ;
                while(i<strlen(s) && s[i]!=' ') i++ ;
                i++ ;
            }
            int len=floor.size() ;
            for(int i=0;i<len;i++) for(int j=0;j<len;j++)
            {
                if(i==j) continue ;
                int f1=floor[i] , f2=floor[j] ;
                int t= f1>f2 ? (f1-f2)*time[x] : (f2-f1)*time[x] ;
                v[f1].push_back((P){x,f2,t}) ;
            }
        }
        int ans[200],last[200]={0} ;
        for(int i=0;i<200;i++) ans[i]=200000000 ;
        ans[0]=0 ; q.push(0) ;
        for(int i=0;i<200;i++) inqueue[i]=0 ; inqueue[0]=1 ;
        while(!q.empty())
        {
            int a=q.front() ; q.pop() ; inqueue[a]=0 ;
            for(int i=0;i<v[a].size();i++)
            {
                if(last[a]==v[a][i].id) continue ;
                int add = last[a]==0 ? 0 : 60 ;
                if(ans[a]+add+v[a][i].w < ans[v[a][i].ed])
                {
                    ans[v[a][i].ed] = ans[a]+add+v[a][i].w ;
                    last[v[a][i].ed]=v[a][i].id ;
                    if(!inqueue[v[a][i].ed])q.push(v[a][i].ed) ;
                    inqueue[v[a][i].ed]=1 ;
                        //printf("ans[%d] = %d\n",v[a][i].ed,ans[v[a][i].ed]);
                }
            }
        }
        if(ans[k]==200000000) printf("IMPOSSIBLE\n");
        else printf("%d\n",ans[k]);
    }
}
