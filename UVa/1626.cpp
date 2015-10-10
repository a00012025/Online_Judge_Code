#include<stdio.h>
#include<string.h>
int dp[101][101],num[101][101],n ;
char s[101] ;

bool ok(char c1,char c2)
{
    if(c1=='[' && c2==']') return 1;
    if(c1=='(' && c2==')') return 1;
    return 0;
}

int d(int l,int r)
{
    if(l>r) return 0;
    if(l==r) return 1;
    if(dp[l][r]!=-1) return dp[l][r] ;
    dp[l][r]=200 ;
    if(ok(s[l],s[r])) {dp[l][r]=d(l+1,r-1) ; num[l][r]=-1 ;}
    for(int i=l;i<r;i++)
    {
        int ret=d(l,i)+d(i+1,r) ;
        if(ret<dp[l][r]) {dp[l][r]=ret ; num[l][r]=i ;}
    }
    return dp[l][r] ;
}

void print_ans(int l,int r)
{
        //printf("%d,%d\n",l,r) ;
    if(l>r || l>=n || r>=n) return ;
    if(l==r)
    {
        if(s[l]=='(' || s[l]==')') printf("()") ;
        else printf("[]") ;
        return ;
    }
    if(num[l][r]==-1)
    {
        printf("%c",s[l]) ;
        print_ans(l+1,r-1) ;
        printf("%c",s[r]) ;
    }
    else
    {
        print_ans(l,num[l][r]) ;
        print_ans(num[l][r]+1,r) ;
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    fgets(s,200,stdin) ;
    while(T--)
    {
        fgets(s,200,stdin) ;
        fgets(s,200,stdin) ;
        n=strlen(s) ;
        if(s[n-1]=='\n') {s[n-1]='\0' ; n-- ;}
        memset(dp,-1,sizeof(dp)) ;
        d(0,n-1) ;
        print_ans(0,n-1) ;
        printf("\n") ;
        if(T) printf("\n") ;
    }
}
