#include<bits/stdc++.h>
using namespace std;
char s[100001][10] ;
int n,ans[100001] ;

int cal(char *t)
{
    int len=strlen(t) ;
    int ret=0 ;
    for(int i=0;i<len;i++) ret*=10 , ret+=t[i]-'0' ;
    return ret ;
}

bool solve()
{
    ans[0]=0 ;
    for(int i=1;i<=n;i++)
    {
        vector<int> tmp ;
        int len=strlen(s[i]) ;
        for(int j=0;j<len;j++) if(s[i][j]=='?') s[i][j]='9' , tmp.push_back(j) ;
        if(cal(s[i])<=ans[i-1]) return 0 ;
        for(int j=0;j<tmp.size();j++)
        {
            int x=tmp[j] ;
            while(s[i][x]!='0' && cal(s[i])>ans[i-1]) s[i][x]-- ;
            if(cal(s[i])<=ans[i-1]) s[i][x]++ ;
            if(s[i][0]=='0') s[i][0]++ ;
        }
        ans[i]=cal(s[i]) ;
    }
    printf("YES\n") ;
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]) ;
    return 1 ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%s",s[i]) ;
    s[0][0]='0' ; s[0][1]='\0' ;
    if(!solve()) printf("NO\n") ;
}
