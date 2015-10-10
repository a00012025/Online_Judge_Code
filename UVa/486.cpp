#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<map>
using namespace std;
map<string,int> mp ;
char s[10000] ;
char con[10][30]={"million","thousand","hundred"} ;
int solve(int l,int r)
{
    if(l>r || l<0 || r<0) return 0;
    for(int i=0;i<3;i++)
    {
        for(int j=l;j+strlen(con[i])-1<=r;j++)
        {
            int no=0 ;
            for(int k=0;k<strlen(con[i]);k++) if(s[j+k]!=con[i][k]) no=1 ;
            if(no==0)
            {
                int newl,newr ;
                for(newl=j+strlen(con[i]);newl<=r && s[newl]==' ';newl++) ;
                for(newr=j-1;newr>=0 && s[newr]==' ';newr--) ;
                return mp[con[i]]*solve(l,newr)+solve(newl,r) ;
            }
        }
    }
    char t[1000] ;
    int i ;
    for(i=l;i<=r && s[i]!=' ';i++) {t[i-l]=s[i] ; t[i-l+1]='\0' ;}
    for(;i<=r && s[i]==' ';i++) ;
    return mp[t]+solve(i,r) ;
}

main()
{
        //freopen("1.txt","r",stdin);
        //freopen("2.txt","w",stdout);
    mp=
    {
        {"negative",-1} , {"zero",0} , {"one",1} , {"two",2} , {"three",3} ,
        {"four",4} , {"five",5} , {"six",6} , {"seven",7} , {"eight",8} ,
        {"nine",9} , {"ten",10} , {"eleven",11} , {"twelve",12} ,
        {"thirteen",13} , {"fourteen",14} , {"fifteen",15} , {"sixteen",16} ,
        {"seventeen",17} , {"eighteen",18} , {"nineteen",19} , {"twenty",20} ,
        {"thirty",30} , {"forty",40} , {"fifty",50} , {"sixty",60} ,
        {"seventy",70} , {"eighty",80} , {"ninety",90} , {"hundred",100} ,
        {"thousand",1000} , {"million",1000000}
    } ;

    while(fgets(s,10000,stdin))
    {
        int i,j;
        for(i=0;s[i]<'a'||s[i]>'z';i++) ;
        for(j=strlen(s)-1;s[j]<'a'||s[j]>'z';j--) ;
        if(s[i]=='n' && s[i+1]=='e')
        {
            int k ;
            for(k=i+8;s[k]==' ';k++) ;
            printf("%d\n",(-1)*solve(k,j)) ;
        }
        else printf("%d\n",solve(i,j)) ;
    }

}
