#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
string s[1001] ;
char ch[10000],u[10000],v[10000],u2[10000] ;
char ans[10000] ;

bool ok()
{
    int i;
    for(i=0;v[i]!='\0' && u2[i]!='\0';i++)
        if(u2[i]!=v[i]) return u2[i]<v[i] ;
    if(v[i]=='\0' && u[i]=='\0') return 0;
    else if(v[i]=='\0') return 0;
    else return 1;
}

void solve()
{
    int k;
    for(k=0;u[k]!='\0';k++) ans[k]=u[k] ;
    ans[k]='\0' ;
    for(int i=0;i<strlen(u)-1;i++)
    {
        for(int j=0;j<=i;j++) u2[j]=u[j] ;
        u2[i+1]='\0' ;
        u2[i]++ ;
        for(int j=i;j>=1 && u2[j]>'Z';j--) {u2[j]='A' ; u2[j-1]++ ;}
        if(u2[0]!='Z'+1 && ok())
        {
            for(int j=0;j<=i+1;j++) ans[j]=u2[j] ;
            break ;
        }
    }
    for(int i=0;ans[i]!='\0';i++) printf("%c",ans[i]) ;
    printf("\n") ;
}

main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%s",ch) ;
            s[i].clear() ;
            for(int j=0;j<strlen(ch);j++) s[i].push_back(ch[j]) ;
        }
        sort(s+1,s+n+1) ;
        for(int i=0;i<s[n/2].size();i++) {u[i]=s[n/2][i] ; u[i+1]='\0' ;}
        for(int i=0;i<s[(n/2)+1].size();i++) {v[i]=s[(n/2)+1][i] ; v[i+1]='\0' ;}
        solve() ;
    }
}
