#include<bits/stdc++.h>
using namespace std;
int G[1100][30],n,len[1100] ;
char s[1100][10] ;
bool now[1100],asked[30] ;

bool solve(int x)
{
    if(x==-1) return 1 ;
    int num=0 ;
    for(int i=1;i<=n;i++) if(now[i]) num++ ;
    if(num<=1) return 0 ;
    vector<int> tmp ;
    set<int> st ;
    for(int i=0;i<26;i++) if(!asked[i])
    {
        asked[i]=1 ;
        for(int j=1;j<=n;j++) if(now[j] && G[j][i])
            now[j]=0 , tmp.push_back(j) , st.insert(G[j][i]) ;
        if(st.empty()) { asked[i]=0 ; continue ; }
        bool ok=(tmp.size() && solve(x-1)) ;
        for(int j=0;j<tmp.size();j++) now[tmp[j]]=1 ;
        if(ok) { asked[i]=0 ; continue ;}

        bool ok2=0 ;
        for(set<int>::iterator it=st.begin();it!=st.end();it++)
        {
            tmp.clear() ;
            int val=*it ;
            for(int j=1;j<=n;j++) if(now[j] && G[j][i]!=val)
                now[j]=0 , tmp.push_back(j) ;
            ok2=(!tmp.size() || solve(x)) ;
            for(int j=0;j<tmp.size();j++) now[tmp[j]]=1 ;
            if(ok2) break ;
        }
        asked[i]=0 ;
        if(!ok2) return 0 ;
    }
    return 1 ;
}

main()
{
    int T; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        memset(G,0,sizeof(G)) ;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s[i]) ; len[i]=strlen(s[i]) ;
            for(int j=0;j<len[i];j++) G[i][s[i][j]-'A'] |= (1<<(len[i]-1-j)) ;
        }
        bool ok=0 ;
        for(int i=1;i<=6;i++)
        {
            memset(now,0,sizeof(now)) ;
            memset(asked,0,sizeof(asked)) ;
            for(int j=1;j<=n;j++) if(len[j]==i) now[j]=1 ;
            if(solve(i)) { printf("Yes\n") ; ok=1 ; break ; }
        }
        if(!ok) printf("No\n") ;
    }
}
