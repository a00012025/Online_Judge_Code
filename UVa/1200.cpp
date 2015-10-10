#include<stdio.h>
#include<string.h>
#include<math.h>

bool yes(char c)
{
    if(c<='9' && c>='0') return 1 ;
    return 0 ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char s[500] ;
        scanf("%s",s) ;
        int a=0 , b=0 , inv=1 ;
        for(int i=0;i<strlen(s);)
        {
                //printf("%d,%d\n",i,inv) ;
            if(s[i]=='=') {inv=-1 ; i++ ; continue ;}
            if(s[i]=='+' && s[i+1]=='x') {i+=2 ; a+=inv ; continue ;}
            if(s[i]=='-' && s[i+1]=='x') {i+=2 ; a+=-1*inv ; continue ;}
            if(s[i]=='x') {i++ ; a+=inv ; continue ;}

            int t ;
            if(s[i]=='+') sscanf(&s[i+1],"%d",&t) ;
            else if(s[i]=='-') {sscanf(&s[i+1],"%d",&t) ; t=-t ;}
            else sscanf(&s[i],"%d",&t) ;
            if(!yes(s[i]))i++ ;
            while(i<strlen(s) && yes(s[i])) i++ ;
            if(i<strlen(s) && s[i]=='x') {a+=t*inv ; i++ ;}
            else b+=t*inv ;
                //printf("%d,%d\n",a,b);
        }
        b=-b ;
        if(a==0 && b==0) printf("IDENTITY\n");
        else if(a==0) printf("IMPOSSIBLE\n") ;
        else
        {
            double d=(((double)b)/((double)a)) ;
            int ans=floor(d) ;
            ans+=10 ;
            while(ans>d) ans-- ;
            printf("%d\n",ans) ;
        }
    }
}
