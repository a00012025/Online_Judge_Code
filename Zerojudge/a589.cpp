#include<stdio.h>
#include<string.h>
char s[2000][4201],c[1000] ;
int l[5101],r[5101] ;
bool non[4201] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n ;
        memset(s,0,sizeof(s)) ;
        memset(l,0,sizeof(l)) ;
        memset(r,0,sizeof(r)) ;
        memset(non,0,sizeof(non)) ;
        l[0]=2005,r[0]=2005 ;
        scanf("%d",&n) ;
        for(int i=0;i<n;i++)
        {
            gets(c) ;
            while(c[0]!='p' && c[0]!='u') gets(c) ;
            if(c[0]=='u')
            {
                int modify ;
                sscanf(&c[5],"%d",&modify) ;
                if(i!=modify && !non[i-modify-1])
                {
                    memcpy(s[i],s[i-modify-1],sizeof(s[i-modify-1])) ;
                    l[i]=l[i-modify-1] ; r[i]=r[i-modify-1] ;
                }
                else  non[i]=1 ;
            }
            else if(c[4]=='f')
            {
                if(i==0 || non[i-1])
                    {s[i][2005]=c[10] ; non[i]=0 ; l[i]=2005 ; r[i]=2005;}
                else
                {
                    memcpy(s[i],s[i-1],sizeof(s[i-1])) ;
                    l[i]=l[i-1]-1 ; r[i]=r[i-1] ; s[i][l[i]]=c[10] ;
                }
            }
            else if(c[4]=='b')
            {
                if(i==0 || non[i-1])
                    {s[i][2005]=c[9] ; l[i]=2005 ; r[i]=2005 ;}
                else
                {
                    memcpy(s[i],s[i-1],sizeof(s[i-1])) ;
                    r[i]=r[i-1]+1 ; l[i]=l[i-1] ; s[i][r[i]]=c[9] ;
                }
            }
            if(!non[i]) for(int j=l[i];j<=r[i];j++) printf("%c",s[i][j]);
            printf("\n") ;
        }
    }
}
