#include<bits/stdc++.h>
using namespace std;
char s[300] ;
int n ;
int d[301][301] ;
bool fold[101][101][101] ;

void find_fold()
{
    memset(fold,0,sizeof(fold)) ;
    for(int i=0;i<n;i++) for(int j=i;j<n;j++)
        for(int k=j-i+1;k>=2;k--) if(((j-i+1)%k)==0)
    {
        int len=(j-i+1)/k ;
        bool ok=1 ;
        for(int l=i;l+len<=j;l++) if(s[l]!=s[l+len]) {ok=0 ; break ;}
        if(ok) fold[i][j][k]=1 ;
        //printf("num[%d][%d]=%d\n",i,j,num[i][j]) ;
    }
}

int dec_cnt(int x)
{
    int ret=0 ;
    while(x) {x/=10 ; ret++ ;}
    return ret ;
}

int type[305][305] ;
int id[305][305] ;
void update_ans(int l,int r,int k,int val)
{
    if(d[l][r]<=val) return ;
    d[l][r]=val ; type[l][r]=1 ;
    id[l][r]=k ; //if(l==9 && r==14) printf("%d,%d,%d\n",i,j,val) ;
}

int mid[305][305] ;
void update_ans2(int l,int r,int md,int val)
{
    if(d[l][r]<=val) return ;
    d[l][r]=val ; type[l][r]=2 ;
    mid[l][r]=md ;
}

int dp(int l,int r)
{
    if(d[l][r]>=0) return d[l][r] ;
    if(r<=l+1) return r-l+1 ;
    d[l][r]=r-l+1 ;
    for(int i=l;i<r;i++) update_ans2(l,r,i,dp(l,i)+dp(i+1,r)) ;
    for(int k=2;k<=r-l+1;k++) if(fold[l][r][k])
    {
        int len=(r-l+1)/k ;
        update_ans(l,r,k,2+dec_cnt(k)+dp(l,l+len-1)) ;
    }
    return d[l][r] ;
}

void print_ans(int l,int r)
{
    if(l>r) return ;
    if(type[l][r]==0) {for(int i=l;i<=r;i++) printf("%c",s[i]) ; return ;}
    else if(type[l][r]==1)
    {
        int k2=id[l][r] , len=(r-l+1)/k2 ;
        printf("%d(",k2) ; print_ans(l,l+len-1) ; printf(")") ;
    }
    else
    {
        int md=mid[l][r] ;
        print_ans(l,md) ; print_ans(md+1,r) ;
    }
}

main()
{
    //freopen("all.txt","r",stdin) ;
    //freopen("output.txt","w",stdout) ;
    while(scanf("%s",s)!=EOF)
    {
        n=strlen(s) ;
        find_fold() ; //printf("%d\n",num[9][14]) ;
        memset(d,-1,sizeof(d)) ;
        memset(type,0,sizeof(type)) ;
        dp(0,n-1) ;
        print_ans(0,n-1) ;
        printf("\n") ;
    }
}
