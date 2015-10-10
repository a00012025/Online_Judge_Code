#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std; 
main()
{
 int x1,y1,x2,y2,x,y; 
 char a[10] ;
 int vis[10][10] ;
 int step[10][10] ; 
 queue<int>q ;
 while(gets(a))
    {
    memset(vis,0,sizeof(vis)) ; 
    memset(step,-1,sizeof(step)) ; 
    x1=a[0]-'a'+1;
    y1=a[1]-'1'+1;
    x2=a[3]-'a'+1;
    y2=a[4]-'1'+1; 
    vis[x1][y1]=1;
    step[x1][y1]=0; 
    q.push(x1);
    q.push(y1);
    while(step[x2][y2]==-1) 
        {
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        if((x+2<=8)&&(y+1<=8)&&(vis[x+2][y+1]==0))
            {
            vis[x+2][y+1]=1;
            q.push(x+2);
            q.push(y+1); 
            step[x+2][y+1]=step[x][y]+1; 
            }
        if((x+1<=8)&&(y+2<=8)&&(vis[x+1][y+2]==0))
            {
            vis[x+1][y+2]=1;
            q.push(x+1);
            q.push(y+2); 
            step[x+1][y+2]=step[x][y]+1;  
            }
        if((x-1>=1)&&(y+2<=8)&&(vis[x-1][y+2]==0))
            {
            vis[x-1][y+2]=1;
            q.push(x-1);
            q.push(y+2); 
            step[x-1][y+2]=step[x][y]+1;  
            }
        if((x-2>=1)&&(y+1<=8)&&(vis[x-2][y+1]==0))
            {
            vis[x-2][y+1]=1;
            q.push(x-2);
            q.push(y+1); 
            step[x-2][y+1]=step[x][y]+1;  
            }
        if((x-2>=1)&&(y-1>=1)&&(vis[x-2][y-1]==0))
            {
            vis[x-2][y-1]=1;
            q.push(x-2);
            q.push(y-1); 
            step[x-2][y-1]=step[x][y]+1;  
            }
        if((x-1>=1)&&(y-2>=1)&&(vis[x-1][y-2]==0))
            {
            vis[x-1][y-2]=1;
            q.push(x-1);
            q.push(y-2); 
            step[x-1][y-2]=step[x][y]+1;  
            }
        if((x+1<=8)&&(y-2>=1)&&(vis[x+1][y-2]==0))
            {
            vis[x+1][y-2]=1;
            q.push(x+1);
            q.push(y-2); 
            step[x+1][y-2]=step[x][y]+1;  
            }
        if((x+2<=8)&&(y-1>=1)&&(vis[x+2][y-1]==0))
            {
            vis[x+2][y-1]=1;
            q.push(x+2);
            q.push(y-1); 
            step[x+2][y-1]=step[x][y]+1;  
            }
        }
    printf("To get from %c%c to %c%c takes %d knight moves.\n",a[0],a[1],a[3],a[4],step[x2][y2]);
    while(q.empty()==0) q.pop(); 
    }
} 
