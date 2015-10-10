#include<bits/stdc++.h>
using namespace std;
int num1[10],num2[10] ;
int pw[]={1,10,100,1000,10000,100000,1000000,10000000,100000000} ;

void add(int num,int len,int *a)
{
    //printf("%d,%d\n",num,len) ;
    if(num==0)
    {
        if(!len) a[0]++ ;
        else for(int i=0;i<=9;i++) a[i]+=len*pw[len-1] ;
        return ;
    }
    int p[10] ; memset(p,0,sizeof(p)) ;
    while(num)
    {
        p[num%10]++ ;
        num/=10 ;
    }
    for(int i=0;i<=9;i++) a[i]+=pw[len]*p[i] ;
    if(len) for(int i=0;i<=9;i++) a[i]+=len*pw[len-1] ;
}

void solve(int l,int r,int *a)
{
    //printf("solve(%d,%d)\n",l,r) ;
    if(l>r) return ;
    int num=0,tmp=l ;
    while(tmp%10==0) {num++ ; tmp/=10 ; if(!tmp) break ;}
    for(int i=num;i>=0;i--)
    {
        if(l+pw[i]>r) continue ;
        add(l/pw[i],i,a) ;
        solve(l+pw[i],r,a) ;
        break ;
    }
    if(l==r) add(l,0,a) ;
}

main()
{
    int a,b ;
    while(scanf("%d%d",&a,&b)==2 && a+b)
    {
        memset(num1,0,sizeof(num1)) ;
        memset(num2,0,sizeof(num2)) ;
        solve(0,min(a,b)-1,num1) ;
        solve(0,max(a,b),num2) ;
        for(int i=0;i<=9;i++) printf("%d%c",num2[i]-num1[i],i==9?'\n':' ') ;
    }
}
