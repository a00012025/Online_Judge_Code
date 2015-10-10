#include<stdio.h>
#include<string.h>
char s[111000],t[100100] ;
int fail[100100] ;

bool no(char k)
{
    if((k<'A' || k>'Z') && (k<'a' || k>'z')) return 1 ;
    return 0 ;
}

main()
{
    int T;
    gets(s) ;
    sscanf(s,"%d",&T) ;
    T=9 ;
    while(T--)
    {
        int len1=0 , len2 , Q ;
        while(1)
        {
            s[len1]=getchar() ;
            if(len1==0 && no(s[len1])) continue ;
            if(no(s[len1])) break ;
            len1++ ;
        }
                //for(int i=0;i<len1;i++)printf("%d,",s[i]);
                //printf("\n");
        gets(t) ; while(t[0]<'0' || t[0]>'9') gets(t);
        sscanf(t,"%d",&Q) ;
        while(Q--)
        {
            len2=0 ;
            while(1)
            {
                t[len2]=getchar() ;
                if(len2==0 && no(t[len2])) continue ;
                if(no(t[len2])) break ;
                len2++ ;
            }
                //for(int i=0;i<len2;i++)printf("%d,",t[i]);
                //printf("\n");
            fail[0]=-1 ;
            int now=-1 , ans=0 , k=-1 ;
            for(int i=1;i<len2;i++)
            {
                while(k>=0 && t[i]!=t[k+1]) k=fail[k] ;
                if(t[i]==t[k+1]) k++ ;
                fail[i]=k ;
            }
            for(int i=0;i<len1;i++)
            {
                while(now>=0 && s[i]!=t[now+1]) now=fail[now] ;
                if(s[i]==t[now+1]) now++ ;
                if(now==len2-1) {ans=1 ; break ;}
            }
            if(ans) printf("y\n");
            else printf("n\n");
        }
    }
}

