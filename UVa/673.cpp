#include<stdio.h>
#include<string.h>
char s[200] ;

bool solve(int l,int r)
{
    if(l>r) return true ;
    int i,num=0 ;
    for(i=l;i<=r;i++)
    {
        if(s[i]=='(' || s[i]=='[') num++ ;
        else num-- ;
        if(num<0) return false ;
        if(num==0) break ;
    }
    if(i==r && num) return false ;
    else if(i==r)
    {
        if(s[l]=='[' && s[r]==']') return solve(l+1,r-1) ;
        else if(s[l]=='(' && s[r]==')') return solve(l+1,r-1) ;
        else return false ;
    }
    else return solve(l,i) && solve(i+1,r) ;
}

main()
{
    int n;
    scanf("%d",&n) ;
    gets(s) ;
    while(n--)
    {
        gets(s) ;
        if(solve(0,strlen(s)-1)) printf("Yes\n") ;
        else printf("No\n") ;
    }
}
