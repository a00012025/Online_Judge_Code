#include<stdio.h>
#include<algorithm> 
#include<string.h> 
int a[10001][51][2]; 
main()
{
 int x,y,i,j,k,M,N,P,ans,zz;
 while(scanf("%d %d %d",&M,&N,&P)==3)
 {
 memset(a,0,sizeof(a)); 
 for(i=1;i<=N;i++)
    {
    for(j=0;j<=10000;j++) a[j][i][0]=a[j][i-1][0];
    for(j=1;j<=P;j++)
        {                       
        scanf("%d %d",&x,&y);  //i=j=1,x=1,y=2 
        //for(zz=1;zz<=50;zz++) printf("%d,",a[zz][i][0]); printf("\n"); 
        for (k=10000;k>=x;k--)
            {
            if((a[k-x][i][0]!=0)||(k==x))
                {
                if(x==2&&y==5&&k==8) printf("x=2,y=5,k=8,%d>%d+%d?\n",a[k][i][0],a[k-x][i][0],y); 
                if(a[k][i][0]>a[k-x][i][0]+y) continue;
                //x=2,y=5,i=3,k=8; 
                if(x==2&&y==5&&k==8) printf("%d=%d?\n",a[k-x][i][1],i); 
                 
                if(a[k-x][i][1]==i)
                    {
                    //if(x==2&&y==6) printf("a[8][i][2]=%d\n",a[8][i][2]); 
             //if(x==2&&y==6&&k==8) printf("%d+%d>%d?\n",a[k-x][i][2],y,a[k][i][0]) ;      
                    if((a[k-x][i][2]+y>a[k][i][0])&&(a[k-x][i][2]!=0))
                        {
/*a[8][3][1]=0 !?*/     a[k][i][2]=a[k-x][i][2]; 
                        a[k][i][0]=a[k-x][i][2]+y; 
                        a[k][i][1]=i ;
                        continue; 
                        } 
                    else continue; 
                    }
                //if(k==8) printf("a[%d][%d][0]=%d\n",k,i,a[k][i][0]); 
                a[k][i][2]=a[k][i][0]; //a[1][1][2]=0;
                a[k][i][0]=a[k-x][i][0]+y; //a[1][1][0]=2 
                //printf("a[%d][%d][0]=a[%d][%d][0]+%d\n",k,i,k-x,i,y); 
                a[k][i][1]=i; //a[1][1][1]=1 
                //if(x==2&&y==5&&k==8) printf("a[k][i][1]=%d",a[k][i][1]); 
                }
            } 
        //for(zz=1;zz<=10;zz++) printf("%d,",a[zz][i][0]);printf("\n"); 
        } 
    } 
 ans=0; 
 for(i=M;i>=1;i--)
    {
    if(a[i][N][0]>ans) ans=a[i][N][0]; 
    } 
 printf("%d\n",ans);
 } 
} 
/*10000 2 3
1000 2 1000 3 10000 5
10000 3 5000 6 3000 5
 */
