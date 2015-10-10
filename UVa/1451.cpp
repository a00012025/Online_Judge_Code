#include<stdio.h>
struct P {int x,y;};
char s[100100] ;
P a[100100] ;
int st[100100],ans_l,ans_r ;

bool better(int i,int j)
{
    if(ans_l==-1) return 1;
    int x1=a[ans_r].x - a[ans_l].x ;
    int y1=a[ans_r].y - a[ans_l].y ;
    int x2=a[j].x - a[i].x ;
    int y2=a[j].y - a[i].y ;
    if( x1*y2 != x2*y1 ) return x1*y2 > x2*y1 ;
    else if(ans_r-ans_l != j-i) return ans_r-ans_l > j-i ;
    else return 0 ;
}

bool convex(int i,int j,int k)
{
    int x1=a[j].x-a[i].x ;
    int y1=a[j].y-a[i].y ;
    int x2=a[k].x-a[j].x ;
    int y2=a[k].y-a[j].y ;
    return x1*y2  <=  x2*y1 ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,L ;
        scanf("%d%d",&n,&L) ;
        for(int i=0;i<n;i++)
        {
            char c ; c=getchar() ;
            while(c!='0' && c!='1') c=getchar() ;
            s[i]=c ;
        }
        a[0].x=a[0].y=0 ; ans_l=ans_r=-1 ;
        for(int i=0;i<n;i++)
        {
            a[i+1].x=i+1 ;
            a[i+1].y=a[i].y+s[i]-'0' ;
        }
        int top=1 ; st[0]=0 ;
        int last=0 ;
        for(int i=L;i<=n;i++)
        {
            while(last+1<top)
            {
                int x1=a[i].x-a[st[last]].x ;
                int y1=a[i].y-a[st[last]].y ;
                int x2=a[i].x-a[st[last+1]].x ;
                int y2=a[i].y-a[st[last+1]].y ;
                if(x2*y1 > x1*y2) break ;
                last++ ;
            }
            if(better(st[last],i)) ans_l=st[last] , ans_r=i ;
            int newi=i-L+1 ;
            while(top>=2 && convex(st[top-2],st[top-1],newi)) top-- ;
            if(last>=top) last=top-1 ;
            st[top]=newi ; top++ ;
        }
        printf("%d %d\n",ans_l+1,ans_r) ;
    }
}
