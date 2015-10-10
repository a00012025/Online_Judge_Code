#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
struct iiint{
    int first;
    int second;
    int third;
    };
main()
{
 int n,a,b,c,i;
 int block[100][100],vis[100][100];
 int begin1,begin2,end1,end2;
 struct iiint A;
 queue<iiint> q;
 while(scanf("%d",&n)==1)
 {
 memset(vis,0,sizeof(vis));
 memset(block,0,sizeof(block));
 for(i=1;i<=n;i++) 
    {
    scanf("%d %d",&a,&b);
    block[a][b]=1;
    }
 scanf("%d %d",&begin1,&begin2);
 scanf("%d %d",&end1,&end2);
 vis[begin1][begin2]=1;
 A.first=begin1;
 A.second=begin2;
 A.third=0;
 q.push(A);
 while(q.empty()==0)
    {
    A=q.front();
    q.pop();
    a=A.first;
    b=A.second;
    c=A.third;
    if((a+1<=99)&&(b+3<=99)&&(block[a][b+1]==0)&&(block[a+1][b+3]==0)&&(vis[a+1][b+3]==0))
        {
        A.first=a+1;
        A.second=b+3;
        A.third=c+1;
        if((A.first==end1)&&(A.second==end2)) break;
        q.push(A);
        vis[a+1][b+3]=1;
        }
    if((a-1>=0)&&(b+3<=99)&&(block[a][b+1]==0)&&(block[a-1][b+3]==0)&&(vis[a-1][b+3]==0))
        {
        A.first=a-1;
        A.second=b+3;
        A.third=c+1;
        if((A.first==end1)&&(A.second==end2)) break;
        q.push(A);
        vis[a-1][b+3]=1;
        }
    if((a-3>=0)&&(b+1<=99)&&(block[a-1][b]==0)&&(block[a-3][b+1]==0)&&(vis[a-3][b+1]==0))
        {
        A.first=a-3;
        A.second=b+1;
        A.third=c+1;
        if((A.first==end1)&&(A.second==end2)) break;
        q.push(A);
        vis[a-3][b+1]=1;
        }
    if((a-3>=0)&&(b-1>=0)&&(block[a-1][b]==0)&&(block[a-3][b-1]==0)&&(vis[a-3][b-1]==0))
        {
        A.first=a-3;
        A.second=b-1;
        A.third=c+1;
        if((A.first==end1)&&(A.second==end2)) break;
        q.push(A);
        vis[a-3][b-1]=1;
        }
    if((a-1>=0)&&(b-3>=0)&&(block[a][b-1]==0)&&(block[a-1][b-3]==0)&&(vis[a-1][b-3]==0))
        {
        A.first=a-1;
        A.second=b-3;
        A.third=c+1;
        if((A.first==end1)&&(A.second==end2)) break;
        q.push(A);
        vis[a-1][b-3]=1;
        }
    if((a+1<=99)&&(b-3>=0)&&(block[a][b-1]==0)&&(block[a+1][b-3]==0)&&(vis[a+1][b-3]==0))
        {
        A.first=a+1;
        A.second=b-3;
        A.third=c+1;
        if((A.first==end1)&&(A.second==end2)) break;
        q.push(A);
        vis[a+1][b-3]=1;
        }
    if((a+3<=99)&&(b-1>=0)&&(block[a+1][b]==0)&&(block[a+3][b-1]==0)&&(vis[a+3][b-1]==0))
        {
        A.first=a+3;
        A.second=b-1;
        A.third=c+1;
        if((A.first==end1)&&(A.second==end2)) break;
        q.push(A);
        vis[a+3][b-1]=1;
        }
    if((a+3<=99)&&(b+1<=99)&&(block[a+1][b]==0)&&(block[a+3][b+1]==0)&&(vis[a+3][b+1]==0))
        {
        A.first=a+3;
        A.second=b+1;
        A.third=c+1;
        if((A.first==end1)&&(A.second==end2)) break;
        q.push(A);
        vis[a+3][b+1]=1;
        }
    }
 if((A.first==end1)&&(A.second==end2)) printf("%d\n",A.third);
 else printf("impossible\n");
 }
}
