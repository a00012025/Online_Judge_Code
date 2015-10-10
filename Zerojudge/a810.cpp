#include<stdio.h>
long long gcd(long long x,long long y)
{
 while((x%y!=0)&&(y%x!=0))
    {
    if(y>x) y=y%x ; 
    if(x>y) x=x%y ;
    }
 if(x==0) return y;
 else return x ;
}
long long abs(long long x)
{
 if(x<0) return -x;
 else return x;
}
main()
{
 long long a,b,x,y,ax,bx,ay,by,axy,bxy,ans1,ans2,ans3,g ;
 while(scanf("%lld %lld %lld %lld",&a,&b,&x,&y)==4)
 {
 x=abs(x) ; y=abs(y) ;
 if((x==0)&&(y==0))
    {
    if((a<=0)&&(b>=0)) printf("1\n") ;
    else printf("0\n") ;
    }
 else if((x==0)||(y==0))
    {
    if(y==0) y=x ;
    if(a==0) ay=0 ;
    else if(a>0) ay=((a-1)/y)+1 ;
    else if(a<0) ay=-((-a)/y) ;
    if(b==0) by=0 ;
    else if(b>0) by=(b/y) ; 
    else if(b<0) by=((-b-1)/y)+1 ;
    printf("%lld\n",(by-ay)+1) ;
    }
 else
    {
    g=gcd(x,y) ; long long l ; int yes=1 ;
    if((y/g>abs(a)/x)&&(y/g>abs(b)/x))
        {
        yes=0 ;
        if((a<=0)&&(b>=0)) ans3=1 ;
        else ans3=0 ;
        }
    if(yes==1) l=x*y/g ;
    else l=2147483647 ;
    if(a==0) {ax=0 ; ay=0 ; axy=0 ;}
    else if(a>0) {
        ax=((a-1)/x)+1 ; ay=((a-1)/y)+1 ; 
        axy=((a-1)/l)+1 ;
        }
    else if(a<0) {
        ax=-((-a)/x) ; ay=-((-a)/y) ; 
        axy=-((-a)/l) ;
        }
    if(b==0) {bx=0 ; by=0 ; bxy=0 ;}
    else if(b>0) {
        bx=(b/x) ; by=(b/y) ; 
        bxy=(b/l) ;
        }
    else if(b<0) {
        bx=((-b-1)/x)+1 ; by=((-b-1)/y)+1 ;
        bxy=((-b-1)/l)+1 ;
        }
    ans1=bx-ax+1 ; ans2=by-ay+1 ; 
    if(yes==1) ans3=bxy-axy+1 ;
    printf("%lld\n",ans1+ans2-ans3) ;
    }
 }
}
