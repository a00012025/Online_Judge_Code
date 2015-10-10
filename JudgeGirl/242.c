#include<stdio.h>
#define ABS(x) ((x)>0?(x):(-(x)))
int x[3],y[3],r[3] ;
int in_cir(int x0,int y0,int id)
{
    int dx=abs(x[id]-x0) , dy=abs(y[id]-y0) ;
    return dx<=r[id] && dy<=r[id] && dx*dx+dy*dy<=r[id]*r[id] ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        for(int i=0;i<3;i++) scanf("%d%d%d",&x[i],&y[i],&r[i]) ;
        int ans=0 ;
        for(int i=0;i<3;i++) for(int j=-r[i];j<=r[i];j++) for(int k=-r[i];k<=r[i];k++)
        {
            int ok=1,nx=x[i]+j,ny=y[i]+k ;
            for(int id=0;id<i;id++) if(abs(nx-x[id])<=r[id] && abs(ny-y[id])<=r[id])
                {ok=0 ; break ;}
            if(!ok) continue ;

            int cnt=0 ;
            for(int id=0;id<3;id++) if(in_cir(nx,ny,id)) cnt++ ;
            ans+=cnt%2 ;
        }
        printf("%d\n",ans) ;
    }
}
