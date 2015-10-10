#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define N 90
#define V 20
#define EPS 1e-8
using namespace std;
struct point{
    double x,y;
    bool operator!=(point another){
        return fabs(another.x-x)>EPS||fabs(another.y-y)>EPS;
    }
}p[N][V],q[N][V],temp[V];
int v[N],w[N];
bool found[N];
bool cmp(point a,point b){
    if(fabs(a.x-b.x)<EPS)return a.y<b.y;
    return a.x<b.x;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        bool sad=1;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",v+i);
            for(int j=0;j<v[i];j++)scanf("%lf%lf",&p[i][j].x,&p[i][j].y);
            for(int j=1;j<v[i];j++){
                p[i][j].x-=p[i][0].x;
                p[i][j].y-=p[i][0].y;
            }
            p[i][0].x=p[i][0].y=0;
            double dx=p[i][1].x,dy=p[i][1].y;
            double r=hypot(dx,dy);
            double COS=dx/r,SIN=dy/r;
            for(int j=0;j<v[i];j++){
                double x=p[i][j].x,y=p[i][j].y;
                p[i][j].x=(x*COS+y*SIN)/r;
                p[i][j].y=(-x*SIN+y*COS)/r;
            }
            sort(p[i],p[i]+v[i],cmp);
        }
        memset(found,0,sizeof(found));
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",w+i);
            for(int j=0;j<w[i];j++)scanf("%lf%lf",&q[i][j].x,&q[i][j].y);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)if(v[i]==w[j]){
                bool found2=0;
                for(int k=0;k<w[j];k++){
                    bool found3=0;
                    for(int l=0;l<w[j];l++)if(k!=l){
                        for(int i2=0;i2<w[j];i2++){
                            temp[i2].x=q[j][i2].x-q[j][k].x;
                            temp[i2].y=q[j][i2].y-q[j][k].y;
                        }
                        bool found4=1;
                        double dx=q[j][l].x-q[j][k].x,dy=q[j][l].y-q[j][k].y;
                        double r=hypot(dx,dy);
                        double COS=dx/r,SIN=dy/r;
                        for(int i2=0;i2<w[j];i2++){
                            double x=temp[i2].x,y=temp[i2].y;
                            temp[i2].x=(COS*x+SIN*y)/r;
                            temp[i2].y=(-SIN*x+COS*y)/r;
                        }
                        sort(temp,temp+w[j],cmp);
                        for(int i2=0;i2<w[j];i2++)if(p[i][i2]!=temp[i2]){
                            found4=0;break;
                        }
                        if(found4){
                            found3=1;break;
                        }
                    }
                    if(found3){
                        found2=1;break;
                    }
                }
                if(found2){
                    found[i]=1;break;
                }
            }
        }
        for(int i=0;i<n;i++)if(found[i]){
            if(sad){
                printf("%d",i+1);
                sad=0;
            }
            else printf(" %d",i+1);
        }
        if(sad)puts("so sad");
        else putchar('\n');
    }
    return 0;
}

