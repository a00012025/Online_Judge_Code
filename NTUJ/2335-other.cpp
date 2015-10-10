#include<bits/stdc++.h>
#define DB double
#define LL long long
using namespace std;
const int maxn=4000+10 ;

const DB eps=1e-12 ;
struct P{
    LL x,y ; DB tan;
    void get(){tan=atan2(y,x);}
}s[maxn];

P operator + (const P &a,const P &b){return (P){a.x+b.x,a.y+b.y,0} ;}
P operator - (const P &a,const P &b){return (P){a.x-b.x,a.y-b.y,0} ;}
LL cross(P a,P b){
    return a.x*b.y-a.y*b.x;
}
LL dot(const P &a,const P &b){return a.x*b.x+a.y*b.y ;}
LL cmp(P p1,P p2){
    return p1.tan<p2.tan;
}
P arr[maxn] ;
int main(){
    int t,n,x,y,i,j,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld%lld",&s[i].x,&s[i].y);
        }
        DB ans=0,n1=1.0/n;
        for(i=0;i<n;i++){
            int cnt=0 ;
            for(j=0;j<n;j++) if(i!=j){
                P np=s[j]-s[i] ;
                np.get() ; arr[cnt++]=np ;
            }
            int sz=cnt ;
            sort(arr,arr+cnt,cmp);
            for(j=0;j<sz;j++) arr[cnt++]=arr[j] ;
            for(int l=0,r=0;l<sz;)
            {
                int l2=l+1 ;
                while(l2<sz && !cross(arr[l],arr[l2])
                      && dot(arr[l],arr[l2])>0) l2++ ;
                for(r=max(r,l2);cross(arr[l],arr[r])>0;r++) ;
                for(;l<l2;l++)
                    ans+=(r-l2)*n1*cross(s[i],s[i]+arr[l]) ;
            }
        }
        printf("%.15f\n",ans/(n-1)/(n-2)*3);
    }
}
