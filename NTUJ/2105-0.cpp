#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100+10 ;

char s[maxn],t[maxn] ;
int a[26],b[26] ;
bool check(int x,int y,int l)
{
    memset(a,-1,sizeof(a)) ;
    memset(b,-1,sizeof(b)) ;
    for(int i=0;i<l;i++)
    {
        int p=s[x+i]-'a' , q=t[y+i]-'a' ;
        if(a[p]!=-1 && a[p]!=q) return 0 ;
        if(b[q]!=-1 && b[q]!=p) return 0 ;
        a[p]=q ; b[q]=p ;
    }
    return 1;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s%s",s,t) ;
        int n=strlen(s) , m=strlen(t) ;
        LL ans=0LL ;
        for(int i=1;i<=min(n,m);i++) for(int j=0;j<=n-i;j++) for(int k=0;k<=m-i;k++)
            if(!check(j,k,i))
        {
            ans+=i ;
            printf("find : ") ;
            for(int z=0;z<i;z++) printf("%c",s[j+z]) ; printf(" , ") ;
            for(int z=0;z<i;z++) printf("%c",t[k+z]) ; printf("\n") ;
        }
        printf("%lld\n",ans) ;
    }
}
