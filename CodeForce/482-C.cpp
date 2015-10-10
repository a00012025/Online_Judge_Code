#include<bits/stdc++.h>
#define DB double
using namespace std;
char s[60][30] ;
DB d[1<<20] ;
int n,m,num[1<<20] ;

void find_num()
{
    string str[60] ;
    num[0]=0 ;
    for(int i=1;i<(1<<m);i++)
    {
        bool ok=0 ;
        for(int x=0;x<m;x++) if((i&(1<<x)) && num[i-(1<<x)]==n) {ok=1 ; break ;}
        if(ok) {num[i]=n ; continue ; }
        for(int j=0;j<n;j++) str[j].clear() ;
        for(int j=0;j<n;j++) for(int x=0;x<m;x++) if(i&(1<<x))
            str[j].push_back(s[j][x]) ;
        sort(str,str+n) ;
        num[i]=0 ;
        for(int j=0;j<n;j++)
        {
            if(j>=1 && str[j]==str[j-1]) continue ;
            if(j<n-1 && str[j]==str[j+1]) continue ;
            num[i]++ ;
        }
        //if(i<=100)printf("num[%d]=%d\n",i,num[i]) ;
    }
}

DB dp(int x)
{
    if(d[x]>=0) return d[x] ;
    int k=num[x] ;
    if(k==n) return 0.0 ;
    DB &ans=d[x] ; ans=0.0 ;
    int cnt=0 ;
    for(int i=0;i<m;i++) if(!(x & (1<<i)))
        {ans += dp(x+(1<<i)) ; cnt++ ;}
    ans /= cnt ; ans+=1.0 ; ans *= (n-k) ; ans /= n ;
    return ans ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%s",s[i]) ;
    m=strlen(s[0]) ;
    find_num() ;
    memset(d,-1,sizeof(d)) ;
    printf("%.15lf\n",dp(0)) ;
}
