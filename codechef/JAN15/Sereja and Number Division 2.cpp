#include<bits/stdc++.h>
#define LL long long
using namespace std;
char s[1005] ;
int a[101],n,power[101][1001] ;

void pre_cal(int len)
{
    for(int i=1;i<=n;i++) for(int j=0;j<=len;j++)
        power[i][j]= j==0 ? 1 : ((power[i][j-1]*10) % a[i]) ;
}

int now[101],now2[101],tot ;
int getval(int len)
{
    memset(now,0,sizeof(now)) ;
    for(int i=1;i<=len;i++) for(int j=1;j<=n;j++)
        now[j]=(now[j]*10+s[i]-'0')%a[j] ;
    int ret=0 ;
    for(int i=1;i<=n;i++) ret+=now[i] ;
    return ret ;
}

main()
{
    srand(time(NULL)) ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s%d",s+1,&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        int len=strlen(s+1) ;

        bool same=1 ;
        for(int i=2;i<=len;i++) if(s[i]!=s[i-1]) { same=0 ; break ; }
        if(same) { printf("%s\n",s+1) ; continue ; }

        pre_cal(len) ;

        int times1=1 ;
        while(times1--)
        {
            random_shuffle(s+1,s+len+1) ;
            tot=getval(len) ;
            int times2=50500 ;
            while(times2--)
            {
                int x,y ;
                while(1)
                {
                    x=(rand()%len)+1 , y=(rand()%len)+1 ;
                    if(s[x]!=s[y]) break ;
                }
                int dif= s[y]-s[x] , tot2=0 ;
                for(int i=1;i<=n;i++)
                {
                    int &val = now2[i] ;
                    val = now[i]+dif*power[i][len-x]-dif*power[i][len-y] ,
                    val = ((val%a[i])+a[i])%a[i] ,
                    tot2 += val ;
                }
                if(tot2<=tot)
                {
                    tot=tot2 ;
                    for(int i=1;i<=n;i++) now[i]=now2[i] ;
                    swap(s[x],s[y]) ;
                }
            }
        }
        printf("%s\n",s+1) ;
    }
}
