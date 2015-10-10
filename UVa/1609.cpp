#include<stdio.h>
#include<string.h>
char G[1029][1029] ;
int now[1029],type[1029],now2[1029];
bool vis[1029] ;

void solve(int n)
{
    if(n==1) return ;
    type[1]=4 ;
    for(int i=1;i<=n;i++) if(now[i]!=1)
        type[now[i]]= G[1][now[i]] ? 1 : 3 ;
    for(int i=1;i<=n;i++) if(type[now[i]]==1)
        for(int j=1;j<=n;j++)
            if(type[now[j]]==3 && G[now[i]][now[j]])
                {type[now[i]]=2 ; break ;}

    memset(vis,0,sizeof(vis)) ;
    int cnt=1 ;

    for(int i=1;i<=n;i++) if(type[now[i]]==2)
    {
        int j;
        for(j=1;j<=n && !(!vis[now[j]]&&type[now[j]]==3&&G[now[i]][now[j]]);j++);
        if(j==n+1) continue ;
        printf("%d %d\n",now[i],now[j]) ; vis[now[i]]=vis[now[j]]=1 ;
        now2[cnt++]=now[i] ;
    }

    for(int i=1;i<=n;i++) if(!vis[now[i]] && G[1][now[i]])
    {
        printf("1 %d\n",now[i]) ;
        vis[now[i]]=vis[1]=1 ;
        now2[cnt++]=1 ;
        break ;
    }

    for(int i=1;i<=n;i++) if(!vis[now[i]] && type[now[i]]==3)
    {
        int j;
        for(j=i+1;j<=n && (vis[now[j]] || type[now[j]]!=3);j++) ;
        if(j==n+1) break ;
        printf("%d %d\n",now[i],now[j]) ; vis[now[i]]=vis[now[j]]=1 ;
        now2[cnt++]= (G[now[i]][now[j]] ? now[i] : now[j]) ;
    }

    for(int i=1;i<=n;i++) if(!vis[now[i]])
    {
        int j;
        for(j=i+1;j<=n && vis[now[j]];j++) ;
        if(j==n+1) break ;
        printf("%d %d\n",now[i],now[j]) ; vis[now[i]]=vis[now[j]]=1 ;
        now2[cnt++]= G[now[i]][now[j]] ? now[i] : now[j] ;
    }

    for(int i=1;i<=n/2;i++) now[i]=now2[i] ;
    solve(n/2) ;
}

main()
{
    int n;
    char c[2025] ;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%s",c+1) ;
            for(int j=1;j<=n;j++)
                G[i][j]= (c[j]=='1' ? 1 : 0) ;
        }
        for(int i=1;i<=n;i++) now[i]=i ;
        solve(n) ;
    }
}
