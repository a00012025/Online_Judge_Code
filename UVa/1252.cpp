#include<stdio.h>
#include<algorithm>
#define INF 1000000
using namespace std;
int item[150],s,n ;
int num[2048][2048],dp[2048][2048] ;

int solve()
{
    for(int s1=(1<<s)-1 ; s1>=0 ; s1--)
        for(int s2=s1;;s2=(s2-1)&s1)
    {
        dp[s1][s2]=INF ;
        if(num[s1][s2]<=1 || s1==((1<<s)-1))
        {
            if(num[s1][s2]==1 || s1==((1<<s)-1)) dp[s1][s2]=0 ;
            if(s2==0) break ;
            else continue ;
        }

        int &ans=dp[s1][s2] ;
        for(int j=0;j<s;j++) if((s1&(1<<j))==0)
        {
            int new_ans=0 ;
            if(dp[s1+(1<<j)][s2]<INF) new_ans=dp[s1+(1<<j)][s2] ;
            if(dp[s1+(1<<j)][s2+(1<<j)]<INF)
                new_ans=max(new_ans,dp[s1+(1<<j)][s2+(1<<j)]) ;
            ans=min(ans,new_ans) ;
        }
        ans++ ;
            //printf("dp[%d][%d]=%d\n",s1,s2,dp[s1][s2]) ;
        if(s2==0) break ;
    }
    return dp[0][0] ;
}

main()
{
    char t[100] ;
    while(scanf("%d%d",&s,&n)==2 && s+n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%s",t) ; item[i]=0 ;
            for(int j=0;j<s;j++) {item[i]*=2 ; item[i]+=t[j]-'0' ;}
                //printf("item[%d]=%d\n",i,item[i]) ;
        }
        for(int s1=0;s1<(1<<s);s1++)
            for(int s2=s1;;s2=(s2-1)&s1)
        {
            num[s1][s2]=0 ;
            if(s2==0) break ;
        }
        for(int i=1;i<=n;i++) for(int j=0;j<(1<<s);j++)
            num[j][item[i]&j]++ ;
        printf("%d\n",solve()) ;
    }
}
