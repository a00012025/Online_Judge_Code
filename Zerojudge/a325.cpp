#include<stdio.h>
#include<string.h>
int n,st,ed  ;
char s[100] ;

int check(int l,int r)
{
        //printf("check %d,%d\n",l,r) ;
    if(l>=r) return 0 ;
    int i , cnt=0 ;
    for(i=l;i<=r;i++)
    {
        if(s[i]=='(') cnt++ ;
        if(s[i]==')') cnt-- ;
        if(cnt==0 && i<=r-2 && s[i+2]=='+') return 0 ;
    }
    return 1 ;
}

int solve(int l,int r,int tp)
{
        //printf("%d,%d,%d\n",l,r,tp) ;
    if(tp==1)
    {
        if(l>=r) return 0 ;
        int cnt=0,i,j ;
        for(i=l;i<=r;i++)
        {
            if(s[i]=='(') cnt++ ;
            if(s[i]==')') cnt-- ;
            if(cnt==0 && i<=r-2 && s[i+2]=='+') break ;
        }
        cnt=0 ;
        for(j=l;j<=r;j++)
        {
            if(s[j]=='(') cnt++ ;
            if(s[j]==')') cnt-- ;
            if(cnt==0 && j<=r-2 && s[j+2]=='*') break ;
        }

        if(i==r+1 && j==r+1) return solve(l+1,r-1,1)+1 ;

        if(i!=r+1) return solve(l,i,1)+solve(i+4,r,1) ;

        if(j!=r+1)
        {
            int ans=0 ;
            if(check(l+1,j-1)) ans += 1+solve(l+1,j-1,0) ;
            else ans += solve(l+1,j-1,1) ;
            ans += solve(j+4,r,0) ;
            return ans ;
        }
    }
    else
    {
        int cnt=0 , i ;
        for(i=l;i<=r;i++)
        {
            if(s[i]=='(') cnt++ ;
            if(s[i]==')') cnt-- ;
            if(cnt==0 && i+2<=r && s[i+2]=='*') break ;
        }
        if(i==r+1 && check(l+1,r-1)) return solve(l+1,r-1,0)+1 ;
        else if(i==r+1) return solve(l+1,r-1,1) ;
        int ans=0 ;
        if(check(l+1,i-1)) ans += 1+solve(l+1,i-1,0) ;
        else ans += solve(l+1,i-1,1) ;
        ans += solve(i+4,r,0) ;
        return ans ;
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    fgets(s,100,stdin) ;
    while(T--)
    {
        fgets(s,100,stdin) ;
        int cnt=0 ;
        for(st=0;cnt<2;st++) if(s[st]==' ') cnt++ ;
        st++ ;
        for(ed=(int)(strlen(s))-1;s[ed]!=')';ed--) ;
        ed-- ;
        printf("%d\n",solve(st,ed,1)) ;
    }
}
