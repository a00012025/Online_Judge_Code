#include<stdio.h>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
const int INF=100000000 ;
using namespace std;
queue<int> q ;
map<char,int> mp ;
vector<int> v[100] ;
int cnt,num[100],wake[5],day[100] ;

int id(char c)
{
    if(mp.count(c)) return mp[c] ;
    cnt++ ; mp[c]=cnt ; v[cnt].clear() ;
    return cnt ;
}

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0 ; mp.clear() ;
        for(int i=1;i<=n;i++) {v[i].clear() ; num[i]=0 ; day[i]=INF ;}
        int m ; scanf("%d",&m) ;
        char s[100] ; scanf("%s",s) ;
        for(int i=0;i<3;i++)
            {wake[i]=id(s[i]) ; num[wake[i]]=3 ; day[wake[i]]=0 ;}
        while(m--)
        {
            scanf("%s",s) ;
            v[id(s[0])].push_back(id(s[1])) ;
            v[id(s[1])].push_back(id(s[0])) ;
        }
        while(!q.empty()) q.pop() ;
        int rem=n-3 ;
        for(int i=0;i<3;i++) for(int j=0;j<v[wake[i]].size();j++)
        {
            int a=v[wake[i]][j] ;
            num[a]++ ;
            if(num[a]==3) {q.push(a) ; day[a]=1 ; rem-- ;}
        }
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ;
            for(int i=0;i<v[u].size();i++)
            {
                int a=v[u][i] ; num[a]++ ;
                if(num[a]==3) {day[a]=day[u]+1 ; q.push(a) ; rem-- ;}
            }
        }
        int ans=0 ;
        for(int i=1;i<=n;i++) ans=max(ans,day[i]) ;
        if(rem || ans==INF) printf("THIS BRAIN NEVER WAKES UP\n") ;
        else printf("WAKE UP IN, %d, YEARS\n",ans) ;
    }
}
