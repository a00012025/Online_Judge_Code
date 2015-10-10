#include<stdio.h>
#include<queue>
#include<math.h> 
using namespace std; 
main()
{
 int n,i,j,a,b,bb,x,z[9],k,l,M,N,po;
 queue<int>q; 
 while(scanf("%d",&n)) 
 {
  for(i=1;i<=n;i++)
  {
    N=1;

    printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");

    scanf("%d %d",&a,&b) ; 
    bb=1;
    for(po=1;po<=8-b;po++) bb*=10; 
    q.push(a*bb);
   while(q.empty()==0)
        {
        x=q.front() ;
        q.pop(); 
        z[7]=x/10000000;
        z[6]=x/1000000-x/10000000*10;
        z[5]=x/100000-x/1000000*10;
        z[4]=x/10000-x/100000*10;
        z[3]=x/1000-x/10000*10;
        z[2]=x/100-x/1000*10;
        z[1]=x/10-x/100*10 ;
        z[0]=x-x/10*10 ; 
        /*for(po=7;po>=1;po--) printf("%d,",z[po]);
        printf("\n"); */ 
        for(j=7;(j!=-1)&&(z[j]!=0);j--); 
        if(j==-1)
            { 
            printf(" %d      %d %d %d %d %d %d %d %d\n",N,z[7],z[6],z[5],z[4],z[3],z[2],z[1],z[0]) ;
            N+=1;
            } 
        else           /*j=6*/ 
            {
            for(k=1;k<=8;k++)
                {
                M=1; 
                for(l=7;l>=0;l--)
                    {
                    if((l==j)&&(l==0)) break; 
                    if((z[l]==0)&&(l==0)) break; 
                    if(l==j) continue; 
                    if(z[l]==0) continue;
                    if((k==z[l])||(j-k==l-z[l])||(j+k==l+z[l]))
                        {
                        M=0;
                        break; 
                        }
                    } 
                if (M==1) 
                    { 
                    bb=1;
                    for(po=1;po<=j;po++) bb*=10; 
                    q.push(x+k*bb);
                    } 
                } 
            }
        }
  printf("\n"); 
  }
 } 
 
} 
