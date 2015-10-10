#include<stdio.h>
#define LL long long
char ans[20] ;
int n ;

LL iint(int r,int l)
{
    LL ret=0 ;
    for(int i=r;i<=l;i++)
    {
        ret *= (i<10 ? 10 : 100) ;
        ret+=i ;
    }
    return ret ;
}

LL calculate()
{
    LL val=0 ;
    for(int i=0;i<n;)
    {
        int j ;
        for(j=i+1;j<n && ans[j]==' ' ; j++) ;
        if(i==0 || ans[i]=='+') {
            val+= iint(i+1,j) ;
            //printf(" +%d\n",iint(i+1,j));
            }
        else {
            val-= iint(i+1,j) ;
            //printf("-%d\n",iint(i+1,j)) ;
            }
        i=j ;
    }
    return val ;
}

void dfs(int num,int ques)
{
    if(num==n-1)
    {
        if(calculate()==ques)
            for(int i=1;i<=n;i++) printf("%d%c",i,i==n? '\n' : ans[i]) ;
        return ;
    }
    ans[num+1]=' ' ; dfs(num+1,ques) ;
    ans[num+1]='+' ; dfs(num+1,ques) ;
    ans[num+1]='-' ; dfs(num+1,ques) ;
}

main()
{
    //for(int i=0;i<10;i++) ans[i]='+';
    //n=7 ;
    //printf("%I64d\n",calculate()) ;
    while(scanf("%d",&n)!=EOF)
    {
            dfs(0,0) ;
    }
}
