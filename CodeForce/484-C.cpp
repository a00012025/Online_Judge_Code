#define NDEBUG
#include<bits/stdc++.h>
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) fprintf(stderr, __VA_ARGS__)
#endif
#define INF 100000000
using namespace std;
char s[1000001] ;
int k,d ;
int P[1000001],Q[21][1000001] ;

void find_P_and_Q()
{
    int cnt=0 ;
    for(int r=0;r<d;r++) for(int i=r;i<k;i+=d)
        P[i]=cnt++ ;
    for(int i=0;i<k;i++) debugf("%d%c",P[i],i==k-1?'\n':' ') ;
    for(int i=0;i<k;i++) Q[0][i]=P[i]-1 ;
    for(int i=1;i<=20;i++) for(int j=0;j<k;j++)
        Q[i][j]= Q[i-1][j]>=0 ? Q[i-1][Q[i-1][j]] : -INF ;
    for(int i=0;i<k;i++) debugf("%d%c",Q[0][i],i==k-1?'\n':' ') ;
    for(int i=0;i<k;i++) debugf("%d%c",Q[1][i],i==k-1?'\n':' ') ;
    for(int i=0;i<k;i++) debugf("%d%c",Q[2][i],i==k-1?'\n':' ') ;
}

char t[1000001] ;
int n ;
void process()
{
    for(int x=0;x<n;x++)
    {
        int st=max(0,x-k+1) ;
        int newx=x , now=st , i=21 ;
        while(i>=0)
        {
            for(;i>=0 && ((now+(1<<i)-1)>n-k || Q[i][newx-now]==-INF);i--) ;
            if(i==-1) break ;
            newx=Q[i][newx-now]+(now+(1<<i)) ;
            now += (1<<i) ;
            if(newx-now<0) break ;
            i-- ;
        }
        debugf("x=%d , newx=%d\n",x,newx) ;
        t[newx]=s[x] ;
    }
    t[n]='\0' ;
    for(int x=0;x<=n;x++) s[x]=t[x] ;
}

main()
{
    scanf("%s",s) ; n=strlen(s) ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&k,&d) ;
        find_P_and_Q() ;
        process() ;
        printf("%s\n",s) ;
    }
}
