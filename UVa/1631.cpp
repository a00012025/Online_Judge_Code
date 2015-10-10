#include<bits/stdc++.h>
using namespace std;
const int INF=100000000 ;
char s[1050],t[1050] ;
int dp[1050][120],n ;
int turn(int num,int type,int times)
{
    if(!times) return num ;
    if(type==1)
    {
        int k=num%10 ; k+=times ; k%=10 ;
        return (num/10)*10+k ;
    }
    if(type==2)
    {
        int j=(num/10)%10 , k=num%10 ;
        j+=times ; k+=times ;
        j%=10 ; k%=10 ;
        return ((num/100)*100)+(j*10)+k ;
    }
}
void dp_prep()
{
    for(int i=0;i<=n+1;i++) for(int j=0;j<100;j++) dp[i][j]=INF ;
    int st=10*(s[0]-'0')+(s[1]-'0') ;
    for(int i=0;i<=9;i++) for(int j=0;j<=9;j++)
    {
        int st2=st , cnt=0  ;
        st2=turn(st2,2,i) ;
        cnt+= (i>5 ? 10-i : i) ;
        st2=turn(st2,1,j) ;
        cnt+= (j>5 ? 10-j : j) ;
        dp[2][st2]=min(dp[2][st2],cnt) ;
        //printf("%d , i=%d,j=%d -> %d\n",st,i,j,st2) ;
    }
    for(int i=0;i<=9;i++) for(int j=0;j<=9;j++)
    {
        int st2=st , st3=st , cnt=0  ;
        st2=turn(st2,2,i) ; st3=turn(st3,1,i) ;
        cnt+= (i>5 ? 10-i : i) ;
        int tmp1=st2 , tmp2=st3 ;
        st2=turn(tmp1/10,1,j)*10+tmp1%10 ;
        st3=turn(tmp2/10,1,j)*10+tmp2%10 ;
        cnt+= (j>5 ? 10-j : j) ;
        dp[2][st2]=min(dp[2][st2],cnt) ;
        dp[2][st3]=min(dp[2][st3],cnt) ;
    }
    //for(int i=0;i<100;i++) printf("dp[2][%d]=%d\n",i,dp[2][i]) ;
    //system("pause") ;
}
main()
{
    while(scanf("%s%s",s,t)!=EOF)
    {
        n=strlen(s) ;
        if(n==1)
        {
            int n1=s[0]-'0' , n2=t[0]-'0' ;
            printf("%d\n",min(abs(n1-n2),min(n1+10-n2,n2+10-n1))) ;
            continue ;
        }
        dp_prep() ;
        for(int i=2;i<n;i++) for(int num=0;num<100;num++)
        {
            //printf("dp[%d][%d]=%d\n",i,num,dp[i][num]) ;
            //if(num==99) system("pause") ;
            int x=num/10 , y=num%10 ;
            int times ;
            if(x+'0'>t[i-2]) times=10-(x+'0')+t[i-2] ;
            else times=t[i-2]-x-'0' ;
            int num2=10*y+(s[i]-'0') ;
            num2=turn(num2,2,times) ;
            for(int j=0;j<=9;j++) for(int k=0;k<=9;k++)
            {
                int tmp=num2 , cnt=times>5 ? 10-times : times ;
                tmp=turn(tmp,2,j) ; cnt+= (j>5 ? 10-j : j) ;
                tmp=turn(tmp,1,k) ; cnt+= (k>5 ? 10-k : k) ;
                dp[i+1][tmp]=min(dp[i+1][tmp],dp[i][num]+cnt) ;
            //if(dp[3][16]==5) {printf("%d,%d,%d,%d\n",j,k,num2,tmp) ; system("pause") ;}
            }
        }
        int goal=10*(t[n-2]-'0')+(t[n-1]-'0') ;
        printf("%d\n",dp[n][goal]) ;
    }
}
