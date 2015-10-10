#include<stdio.h>
#include<algorithm>
using namespace std;
int ans ;

bool check(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
        //if(x1==1 && y1==1)
        //printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n",x1,y1,x2,y2,x3,y3,x4,y4);
    if(x1==x2 && y1==y2) return false;
    int nx1=x2+y1-y2 , ny1=y2+x2-x1 , nx2=x1+y1-y2 , ny2=y1+x2-x1 ;
    int nx3=x2-y1+y2 , ny3=y2-x2+x1 , nx4=x1-y1+y2 , ny4=y1-x2+x1 ;
    int nx5=x1+x2+y1-y2 , ny5=x2-x1+y1+y2 ;
    int nx6=x1+x2-y1+y2 , ny6=x1-x2+y1+y2 ;
    if(x3==nx1&&y3==ny1&&x4==nx2&&y4==ny2) return true ;
    if(x4==nx1&&y4==ny1&&x3==nx2&&y3==ny2) return true ;
    if(x3==nx3&&y3==ny3&&x4==nx4&&y4==ny4) return true ;
    if(x4==nx3&&y4==ny3&&x3==nx4&&y3==ny4) return true ;
    if(2*x3==nx5&&2*y3==ny5&&2*x4==nx6&&2*y4==ny6) return true ;
    if(2*x4==nx5&&2*y4==ny5&&2*x3==nx6&&2*y3==ny6) return true ;
    return false ;
}

main()
{
    int T,x[50],y[50],a[50],b[50],nx[50],ny[50];
    scanf("%d",&T);
    /*while(T--)
    {
        int p,q,r,s,t,u,v,w;
        scanf("%d%d%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u,&v,&w);
        printf("%d\n",check(p,q,r,s,t,u,v,w)) ;
    }*/
    while(T--)
    {
        ans=100000000 ;
        for(int i=1;i<=4;i++) scanf("%d%d%d%d",&x[i],&y[i],&a[i],&b[i]);
        for(int i=0;i<=511;i++)
        {
            int need=0 ;
            for(int j=0;j<=6;j=j+2)
            {
                int z=0 ;
                if(i&((1<<(j+1)))) z+=2 ;
                if(i&(1<<(j))) z+=1 ;
                if(z==0)
                {
                    nx[(j/2)+1]=x[(j/2)+1];
                    ny[(j/2)+1]=y[(j/2)+1];
                }
                else if(z==1)
                {
                    nx[(j/2)+1]=y[(j/2)+1]-b[(j/2)+1]+a[(j/2)+1] ;
                    ny[(j/2)+1]=a[(j/2)+1]-x[(j/2)+1]+b[(j/2)+1] ;
                    need+=3 ;
                }
                else if(z==2)
                {
                    nx[(j/2)+1]=2*a[(j/2)+1]-x[(j/2)+1] ;
                    ny[(j/2)+1]=2*b[(j/2)+1]-y[(j/2)+1] ;
                    need+=2 ;
                }
                else if(z==3)
                {
                    nx[(j/2)+1]=-y[(j/2)+1]+b[(j/2)+1]+a[(j/2)+1] ;
                    ny[(j/2)+1]=-a[(j/2)+1]+x[(j/2)+1]+b[(j/2)+1] ;
                    need+=1 ;
                }
            }
                //if(i==12)
                    //printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n",nx[1],ny[1],nx[2],ny[2],nx[3],ny[3],nx[4],ny[4]);
            if(check(nx[1],ny[1],nx[2],ny[2],nx[3],ny[3],nx[4],ny[4]))
                {
                    ans=min(ans,need) ;
                    //if(ans==3)
                    //printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n",nx[1],ny[1],nx[2],ny[2],nx[3],ny[3],nx[4],ny[4]);
                }
        }
        if(ans==100000000) printf("-1\n") ;
        else printf("%d\n",ans) ;
    }
}
