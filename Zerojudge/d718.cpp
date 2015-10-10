#include<stdio.h>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
int grou[1000000];
main()
{
 int n,m,line=0,i,j,x,y,a;
 char s[20];
 queue<int> Q,q[1001];
 while(1)
 {
 if((scanf("%d",&n))==EOF) break;
 line+=1;
 printf("Line #%d\n",line);
 memset(grou,0,sizeof(grou));
 while(Q.empty()==0) Q.pop();
 for(i=0;i<=n;i++) while(q[i].empty()==0) q[i].pop();
 for(i=1;i<=n;i++)
    {
    scanf("%d",&m);
    for(j=1;j<=m;j++)
        {
        scanf("%d",&x);
        grou[x]=i;
        }
    }
 while(1)
    {
    gets(s);
    if(s[0]=='\0') continue;
    if(s[0]=='S') break;
    else if(s[0]=='E')
        {
        a=0;
        for(i=8;i<strlen(s);i++)
            {
            a=a*10;
            a=a+s[i]-'0';
            }
        if((q[grou[a]].empty()==1)&&(grou[a]!=0))
            {
            q[grou[a]].push(a);
            Q.push(grou[a]);
            }
        else if((q[grou[a]].empty()==0)&&(grou[a]!=0))
            {
            q[grou[a]].push(a);
            }
        else if(grou[a]==0)
            {
            q[0].push(a);
            Q.push(0);
            }
        }
    else if(s[0]=='D')
        {
        x=Q.front();
        y=q[x].front();
        q[x].pop();
        printf("%d\n",y);
        if(x==0) Q.pop();
        else if(q[x].empty()==1) Q.pop();
        }
    }
 }
}
