#include<bits/stdc++.h>
using namespace std;
char a[10][31000],b[10][31000],c[10][31000] ;
int fail[10][31000],n ;
int cnt[31000],len[10],max_len ;

void get_fail(int x)
{
    fail[x][1]=0 ;
    int j=0 ;
    for(int i=2;i<=len[x];i++)
    {
        while(j && b[x][j+1]!=b[x][i]) j=fail[x][j] ;
        if(b[x][j+1]==b[x][i]) j++ ;
        fail[x][i]=j ;
    }
}

void KMP(int x)
{
    int j=0 ;
    for(int i=1;i<=len[x];i++)
    {
        while(j && b[x][j+1]!=c[x][i]) j=fail[x][j] ;
        if(b[x][j+1]==c[x][i]) j++ ;
    }
    //printf("x=%d , j=%d\n",x,j) ;
    for(;j;j=fail[x][j]) cnt[len[x]-j]++ ;
    for(int i=len[x];i<=max_len;i++) cnt[i]++ ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) {scanf("%s%s",a[i]+1,b[i]+1) ; len[i]=strlen(a[i]+1) ; }
        for(int i=1;i<=n;i++) for(int j=1;j<=len[i];j++)
            {c[i][j]='A'+b[i][j]-a[i][j] ; if(c[i][j]<'A') c[i][j]+=26 ;}
        for(max_len=1;;max_len++)
        {
            bool ok=1 ;
            int fir ;
            for(fir=1;fir<=n && len[fir]<max_len;fir++) ;
            if(fir==n+1) break ;
            for(int i=1;i<=n;i++) if(len[i]>=max_len && c[i][max_len]!=c[fir][max_len])
                {ok=0 ; break ;}
            if(!ok) break ;
        }
        max_len-- ; //printf("%d\n",max_len) ;
        for(int i=1;i<=n;i++) get_fail(i) ;
        memset(cnt,0,sizeof(cnt)) ;
        for(int i=1;i<=n;i++) KMP(i) ;
        int ans ;
        for(ans=1;ans<=max_len;ans++)
        {
            if(cnt[ans]==n)
            {
                int fir=1 ; for(fir=1;fir<=n && len[fir]<ans;fir++) ;
                for(int i=1;i<=ans;i++) printf("%c",c[fir][i]) ;
                break ;
            }
        }
        if(ans==max_len+1) printf("-") ;
        printf("\n") ;
    }
}
