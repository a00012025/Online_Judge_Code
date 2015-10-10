#include<stdio.h>
#include<string.h>
char s[3][10],t[3][10] ;
char u[10] ;
int add[]={0,0,0,200,1000,4000,10000,40000,200000} ;
main()
{
    for(int i=0;i<3;i++) scanf("%s",s[i]) ;
    for(int i=0;i<3;i++) scanf("%s",t[i]) ;
    int ans=0 ;
    while(scanf("%s",u)!=EOF)
    {
        int ok=0 ;
        for(int i=0;i<3;i++) if(!strcmp(s[i],u))
           {ok=1 ; break ;}
        if(ok){ans+=2000000 ; continue ;}
        int num=0 ;
        for(;num<9;num++)
        {
            ok=0 ;
            for(int i=0;i<3;i++) if(!strcmp(t[i]+8-num,u+8-num))
                {ok=1 ; break ;}
           if(!ok) break ; 
        }
        ans+=add[num-1] ;
    }
    printf("%d\n",ans) ;
}
