#include<stdio.h>
#include<string.h>
int dx[12]={0,1,2,3,4,3,4,6,7,8,7,8} ;
int dy[12]={3,4,3,4,5,7,8,7,8,9,10,11} ;
int bit[10001]={0} ;
bool fir[10001] ;
int bitcount(int n)
{
    if(n==0) return 0 ;
    if(bit[n]!=0) return bit[n] ;
    bit[n]=bitcount(n/2)+(n&1) ;
    return bit[n] ;
}
main()
{
    for(int i=0;i<12;i++)
    {
        fir[(1<<i)]=0 ;
        for(int j=0;j<12;j++)
        {
            if(j==i) continue ;
            fir[(1<<j)+(1<<i)]=1 ;
        }
    }
    for(int i=3;i<=12;i++)
    {
        for(int j=1;j<(1<<12);j++)
        {
            if(bitcount(j)!=i) continue ;
            int pos[13]={0},ans=0 ; int num=0 ;
            for(int k=0;k<12;k++) if(j&(1<<k)){num++ ; pos[num]=k ;}
            for(int k=1;k<=i;k++) if(fir[j-(1<<pos[k])]==0) ans=1 ;
            if(ans==1) {fir[j]=1 ; continue ;}
            for(int k=0;k<12;k++)
            {
                int p,q ;
                for(p=1;p<=i && pos[p]!=dx[k];p++) ;
                for(q=1;q<=i && pos[q]!=dy[k];q++) ;
                if(p!=(i+1) && q!=(i+1))
                {
                    if(fir[j-(1<<pos[p])-(1<<pos[q])]==0) ans=1 ;
                }
            }
            if(ans==1) fir[j]=1 ;
            else fir[j]=0 ;
        }
    }
    int n;
    scanf("%d",&n) ;
    while(n--)
    {
        int num=0 ;
        char s[20] ;
        gets(s) ; while(strlen(s)<11) gets(s) ;
        for(int i=0;i<12;i++) num=(num*2)+s[i]-'0' ;
        if(fir[num]) printf("1") ;
        else printf("0") ;
    }
    printf("\n") ;
}
