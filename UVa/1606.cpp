#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
struct P {int x,y,type;}p[1101],q[1101];
int n;

bool cmp(P a,P b)
{
    P c=a , d=b ;
    if(c.y<0) {c.x=-c.x ; c.y=-c.y ;}
    if(d.y<0) {d.x=-d.x ; d.y=-d.y ;}
    if(c.x<0 && c.y==0) c.x=-c.x ;
    if(d.x<0 && d.y==0) d.x=-d.x ;
    if(c.x==d.x && c.y==d.y) return 1;
    if(c.x<0 && d.x>=0) return 0;
    if(c.x>=0 && d.x<0) return 1;
    if(c.x<0 && d.x<0) return c.x*d.y > c.y*d.x ;
    if(c.x>=0 && d.x>=0) return c.x*d.y > c.y*d.x ;
}

int gcd(int a,int b)
{
    if(a<0) a=-a ;
    if(b<0) b=-b ;
    return b==0 ? a : gcd(b,a%b) ;
}

void find_angle(int x0,int y0)
{
    int cnt=0 ;
    for(int i=0;i<n;i++)
    {
        if(p[i].x==x0 && p[i].y==y0) continue ;
        int x1=p[i].x-x0 , y1=p[i].y-y0 , g=gcd(x1,y1) ;
        q[cnt++]=(P){x1/g,y1/g,p[i].type} ;
    }
    sort(q,q+n-1,cmp) ;
}

int process(int x)
{
    int ans=0 ;
    find_angle(p[x].x,p[x].y) ;
    int lb=0,lw=0,rb=0,rw=0 , lb2,lw2,rb2,rw2 ;
    for(int i=0;i<n-1;i++)
    {
            //printf("%d,%d\n",q[i].x,q[i].y) ;
        if(q[i].y>0 && q[i].type==1) lb++ ;
        if(q[i].y>0 && q[i].type==0) lw++ ;
        if(q[i].y<0 && q[i].type==1) rb++ ;
        if(q[i].y<0 && q[i].type==0) rw++ ;
    }
        //printf("%d,%d,%d,%d\n",lb,lw,rb,rw) ;
    for(int i=0;i<n-1;)
    {
        int j;
        lb2 = lw2 = rb2 = rw2 = 0 ;
        for(j=i; j<n-1 && q[j].x*q[i].y == q[j].y*q[i].x ;j++)
        {
            if(q[j].y!=0)
            {
                if(q[j].y>0 && q[j].type==1) rb2++ ;
                if(q[j].y>0 && q[j].type==0) rw2++ ;
                if(q[j].y<0 && q[j].type==1) lb2++ ;
                if(q[j].y<0 && q[j].type==0) lw2++ ;
            }
            else
            {
                if(q[j].x>0 && q[j].type==1) rb2++ ;
                if(q[j].x>0 && q[j].type==0) rw2++ ;
                if(q[j].x<0 && q[j].type==1) lb2++ ;
                if(q[j].x<0 && q[j].type==0) lw2++ ;
            }
        }
        if(i || q[i].y!=0)
        {
            lb -= rb2 ; lw -= rw2 ;
            rb -= lb2 ; rw -= lw2 ;
        }
        //printf("%d,%d,%d,%d,%d,%d,%d,%d\n",lb,lw,rb,rw,lb2,lw2,rb2,rw2);
        //system("pause") ;
        ans=max(ans,lb+rw+lb2+lw2+rb2+rw2+1) ;
        ans=max(ans,lw+rb+lb2+lw2+rb2+rw2+1) ;
        lb += lb2 ; lw += lw2 ;
        rb += rb2 ; rw += rw2 ;
        i=j ;
    }
    return ans ;
}

main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++) scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].type) ;
        int ans=0 ;
        for(int i=0;i<n;i++) ans=max(ans,process(i)) ;
        printf("%d\n",ans) ;
    }
}
