#include<stdio.h>
#include<string.h>
double p[50][50] ;
main()
{
    p[0][0]=1.0 ; p[1][0]=0.0 ; p[1][1]=0.5 ;
    for(int i=2;i<=40;i++) for(int j=0;j<=i;j++)
    {
        if(j==0) p[i][0]=p[i-1][1] ;
        else p[i][j]=(p[i-1][j-1]+p[i-1][j+1])/2 ;
    }
    char s[20],t[20] ;
    scanf("%s %s",s,t) ;
    int fin=0 ;
    for(int i=0;i<strlen(s);i++) fin+= (s[i]=='+' ? 1 : -1) ;
    int k=0 , now=0 ;
    for(int i=0;i<strlen(t);i++)
    {
        if(t[i]=='+') now++ ;
        else if(t[i]=='-') now-- ;
        else k++ ;
    }
    int dis= (now>fin ? now-fin : fin-now) ;
    printf("%.12lf\n",p[k][dis]) ;
}
