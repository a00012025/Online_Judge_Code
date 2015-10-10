#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;

char s[maxn],t[maxn][maxn] ;
bool used[maxn] ;
main()
{
    int n,k,cnt=0 ; scanf("%d%s",&k,s+1) ;
    n=strlen(s+1) ;
    for(int i=1,last=0;i<=n+1;i++)
    {
        if(i!=1 && !used[s[i]])
        {
            for(int j=last+1;j<i;j++) t[cnt][j-last-1]=s[j] ;
            last=i-1 ; cnt++ ;
            if(i==n+1) break ;
        }
        used[s[i]]=1 ;
    }

    if(cnt<k) {printf("NO\n") ; return 0 ;}
    printf("YES\n") ;
    for(int i=0;i<k-1;i++) printf("%s\n",t[i]) ;
    for(int i=k-1;i<cnt;i++) printf("%s",t[i]) ;
    printf("\n") ;
}
