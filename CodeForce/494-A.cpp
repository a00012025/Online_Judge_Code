#include<bits/stdc++.h>
using namespace std;

char s[110000],t[300000] ;

bool check()
{
    int num1=0,num2=0 ;
    int len=strlen(t) ;
    for(int i=0;i<len;i++)
    {
        if(t[i]=='(') num1++ ;
        else num2++ ;
        if(num1<num2) return 0 ;
    }
    return 1 ;
}

main()
{
    scanf("%s",s) ;
    int len=strlen(s) ;
    int dif=0 ;
    for(int i=0;i<len;i++) { if(s[i]=='(') dif++ ; else dif-- ; }
    if(dif<0) {printf("-1\n") ; return 0 ; }

    int last ;
    for(last=len-1;last>=0 && s[last]!='#';last--) ;
    for(int i=0;i<last;i++) t[i]= s[i]=='#' ? ')' : s[i] ;
    for(int i=last;i<=last+dif-1;i++) t[i]=')' ;
    for(int i=last+dif ; i-dif<len ; i++) t[i]=s[i-dif] ;
    t[len+dif]='\0' ;
    if(!check()) printf("-1\n") ;
    else
    {
        int num=0 ;
        for(int i=0;i<len;i++) if(s[i]=='#') num++ ;
        for(int i=1;i<num;i++) printf("1\n") ;
        printf("%d\n",dif+1) ;
    }

}
