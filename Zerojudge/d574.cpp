#include<stdio.h>
#include<stdlib.h>
#include<string> 
using namespace std; 
int t[10000001],z,i,z0,j;
char s[10000001],u[10000001];
main()
{
 int n,m,i,ord,ord1,ord2;
 char plus; 
 string q; 
 while(scanf("%d",&n)==1)
 {
 scanf("%c",&s[0]) ;
 m=1;
 z=0;
 for(i=0;i<n;i++) scanf("%c",&s[i]);
 for(i=1;i<n;i++)
    {
    if(s[i]==s[i-1]) m+=1;
    else
        {
        t[z]=m;
        u[z]=s[i-1];
        z+=1;
        m=1;
        }
    if((i==n-1)&&(s[i]!=s[i-1]))
        {
        t[z]=1;
        u[z]=s[i];
        }
    else if((i==n-1)&&(s[i]==s[i-1]))
        {
        t[z]=m;
        u[z]=s[i-1]; 
        } 
    }
 q.clear(); 
 for(i=0;t[i]!=0;i++)
    {
    ord=0; 
    for(m=1;t[i]>=m;m=m*10) ord+=1;
    m=m/10;
    while(t[i]!=0)
        {
        ord1=0; 
        for(m=1;t[i]>=m;m=m*10) ord1+=1; //ord1=4 
        m=m/10 ;
        plus='0'+(t[i]/m);
        q+=plus;
        t[i]-=t[i]/m*m ;
        ord2=0; 
        for(m=1;t[i]>=m;m=m*10) ord2+=1;
        if(ord2<ord1-1&&ord2!=0)
            {
            for(j=1;j<=ord1-ord2-1;j++) q+='0' ;
            m=m/10;
            } 
        else if(ord2==0&&ord1>1)
            {
            for(j=1;j<=ord1-1;j++) q+='0' ; 
            } 
        }
    q+=u[i];
    } 
 if(q.size()<n) printf("%s\n",q.c_str());
 else
    { 
    for(i=0;i<n;i++)printf("%c",s[i]); 
    printf("\n");
    } 
 }
}
