#include<stdio.h>
#include<string.h>
int next[101001] ;
char s[101001] ;
main()
{
    while(scanf("%s",s)==1)
    {
        int last=0 , cur=0 , n=strlen(s) ;
        next[0]=0 ;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[') cur=0 ;
            else if(s[i]==']') cur=last ;
            else
            {
                if(cur==last) last=i+1 ;
                next[i+1]=next[cur] ;
                next[cur]=i+1 ;
                cur=i+1 ;
            }
        }
        for(int i=next[0];i!=0;i=next[i])
        {
            printf("%c",s[i-1]) ;
            //if(i==last) {printf("\n");break ;}
        }
        printf("\n");
    }
}
