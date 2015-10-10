#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<stdlib.h>
#define LL long long
using namespace std;
map<LL,int> mp ;
char s[1048576] ;
int now,cnt ;

void build(int l,int r,int dep)
{
    if(s[l]=='[')
    {
        int num=0 ;
        for(int i=l+1;i<=r-1;i++)
        {
            if(s[i]=='[') num++ ;
            else if(s[i]==']') num-- ;
            if(s[i]==',' && num==0)
            {
                build(l+1,i-1,dep+1) ;
                build(i+1,r-1,dep+1) ;
            }
        }
    }
    else
    {
        int val ;
        s[r+1]='\0' ;
        sscanf(&s[l],"%d",&val) ;
        mp[(LL)val<<dep]++ ;
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
        scanf("%s",s) ;
        now=0 ; cnt=0 ; mp.clear() ; build(0,strlen(s)-1,0) ;
        int ans=0 ;
        for(map<LL,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            int num=it->second ;
            cnt+=num ;
            ans=max(ans,num) ;
        }
        printf("%d\n",cnt-ans) ;
    }
}
