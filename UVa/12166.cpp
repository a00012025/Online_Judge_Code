#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<stdlib.h>
#define LL long long
using namespace std;
map<LL,int> mp ;
char s[1048576] ;
int now,cnt,len ;

void build(int dep)
{
    if(s[now]!='[')
    {
        LL val=0 ;
        for(;s[now]>='0'&&s[now]<='9';now++)
        {
            val *= (LL)10 ;
            val += (LL)s[now]-'0' ;
        }
        mp[(LL)val<<dep]++ ;
        while(now<len && s[now]!=',') now++ ;
    }
    else
    {
        now++ ;
        build(dep+1) ;
        now++ ;
        build(dep+1) ;
    }
}

main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s",s) ; len=strlen(s) ;
        now=0 ; cnt=0 ; mp.clear() ; build(0) ;
        int ans=0 ;
        for(map<LL,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            int num=it->second ;
            cnt += num ;
            ans=max(ans,num) ;
        }
        printf("%d\n",cnt-ans) ;
    }
}
