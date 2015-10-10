#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
int ans[2000] ;
map<int,int> item ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,m ;
        char s[50000] ; item.clear() ; memset(ans,0,sizeof(ans)) ;
        scanf("%d %d",&n,&m) ;
        for(int i=1;i<=n;i++)
        {
            int a,b ; gets(s) ; while(s[0]!='i') gets(s) ;
            sscanf(s,"item%d $%d",&a,&b) ;
            item[a]=b ;
        }
        int cnt=0 ;
        for(int i=1;i<=m;i++)
        {
            gets(s) ; while(s[0]!='f') gets(s) ;
            int id,sell,j,no=0 ;
            long long cost=(long long)0 ;
            sscanf(s,"food%d $%d",&id,&sell) ;
            for(j=0;s[j]!=' ';j++) ; j=j+1 ;
            for(;s[j]!=' ';j++) ; j=j+3 ;
            while(j<strlen(s))
            {
                int a,b ;
                sscanf(s+j,"%d item%d",&a,&b) ;
                if(item.count(b)) cost+=(long long)a*item[b] ;
                else no=1 ;
                while(j<strlen(s) && s[j]!='m') j++ ;
                while(j<strlen(s) && s[j]!=' ') j++ ;
            }
            if(cost<(long long)sell && no==0) ans[++cnt]=id ;
        }
        sort(ans+1,ans+cnt+1) ;
        if(!cnt) printf("no such recipe.") ;
        for(int i=1;i<=cnt;i++)
        {
            if(i!=1) printf("/") ;
            printf("food%d",ans[i]) ;
        }
        printf("\n") ;
    }
}
