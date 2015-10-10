#include<stdio.h>
#include<string.h>
char ch[30][5]={"I","II","III","IV","V","VI","VII","VIII","IX","X",
    "XX","XXX","XL","L","LX","LXX","LXXX","XC","C","CC","CCC","CD",
    "D","DC","DCC","DCCC","CM","M","MM","MMM"} ;
int len[30]={1,2,3,2,1,2,3,4,2,1,2,3,2,1,2,3,4,2,1,2,3,2,1,
             2,3,4,2,1,2,3} ;
int val[30]={1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,
             200,300,400,500,600,700,800,900,1000,2000,3000} ;
int inv[5000] ;
int roman(char *s,int L)
{
    int ret=0,add ;
    for(int i=0;i<L;)
    {
        for(int j=29;j>=0;j--)
        {
            if(i+len[j]>L) continue ;
            int k ;
            for(k=0;k<len[j];k++) if(ch[j][k]!=(*(s+i+k))) break ;
            if(k==len[j])
                {ret+=val[j] ; i+=len[j] ; break ;}
        }
    }
    return ret ;
}

main()
{
    for(int i=0;i<30;i++) inv[val[i]]=i ;
    char s[100] ;
    while(scanf("%s",s))
    {
        if(s[0]=='#') break ;
        int a,b,ans,now ;
        a=roman(s,strlen(s)) ;
        scanf("%s",s) ;
        b=roman(s,strlen(s)) ;
        ans=(a>b) ? a-b : b-a ;
        if(ans==0) {printf("ZERO\n") ; continue ;}
        while(ans>=1000) {printf("M") ; ans-=1000 ;}
        now=(ans/100)*100 ;
        if(now) printf("%s",ch[inv[now]]) ;
        ans-=now ;
        now=(ans/10)*10 ;
        if(now) printf("%s",ch[inv[now]]) ;
        ans-=now ;
        now=ans ;
        if(now) printf("%s",ch[inv[now]]) ;
        ans-=now ;
        printf("\n") ;
    }
}
