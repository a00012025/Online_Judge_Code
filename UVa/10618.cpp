#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#define INF 1000000
using namespace std;
int dp[100][5][5][3] ;
int tp_l[]={0,2,3,2},tp_r[]={0,5,6,5} ;
int add_l[3][4]={{1,1,1,1},{3,5,7,5},{1,1,1,1}},add_r[3][4]={{1,1,1,1},{1,1,1,1},{3,5,7,5}} ;
map<char,int> mp ;

int fa_l[100][5][5][3],fa_r[100][5][5][3],fa_tp[100][5][5][3] ;
char type[100][5][5][3] ;
void update_ans(int l,int r,int last,char t,int a,int b,int c,int d,int val)
{
    int &ans=dp[a][b][c][d] ;
    if(val<ans)
    {
        ans=val ;
        fa_l[a][b][c][d]=l ;
        fa_r[a][b][c][d]=r ;
        fa_tp[a][b][c][d]=last ;
        type[a][b][c][d]=t ;
    }
}

bool ok(int l1,int r1,int l2,int r2)
{
    if(l1==3 && r1==1 && l2!=3) return 0 ;
    if(l1==0 && r1==1 && l2!=0) return 0 ;
    if(r1==0 && l1==2 && r2!=0) return 0 ;
    if(r1==3 && l1==2 && r2!=3) return 0 ;
    return 1 ;
}

void print_ans(int x,int a,int b,int c)
{
    if(x==0) return ;
    print_ans(x-1,fa_l[x][a][b][c],fa_r[x][a][b][c],fa_tp[x][a][b][c]) ;
    printf("%c",type[x][a][b][c]) ;
}

main()
{
    char s[100] ;
    mp['U']=0 ; mp['L']=1 ; mp['R']=2 ; mp['D']=3 ;
    while(1)
    {
        scanf("%s",s+1) ;
        if(s[1]=='#') break ;
        int n=strlen(s+1) ;
        for(int i=0;i<=n;i++) for(int z1=0;z1<4;z1++) for(int z2=0;z2<4;z2++)
            for(int z3=0;z3<3;z3++) dp[i][z1][z2][z3]=INF ;
        dp[0][1][2][0]=0 ;
        for(int i=0;i<n;i++) for(int l=0;l<4;l++) for(int r=0;r<4;r++) if(l!=r)
            for(int last=0;last<3;last++) if(dp[i][l][r][last]!=INF)
        {
            if(s[i+1]=='.')
            {
                update_ans(l,r,last,'.',i+1,l,r,0,dp[i][l][r][last]) ;
                for(int nx=0;nx<4;nx++) if(nx!=l && nx!=r)
                {
                    int dx= nx+l==3 ? 2 : 1 ;
                    int add=add_l[last][dx] ;
                    if(ok(l,r,nx,r))
                    update_ans(l,r,last,'L',i+1,nx,r,1,dp[i][l][r][last]+add) ;

                    dx= nx+r==3 ? 2 : 1 ;
                    add=add_r[last][dx] ;
                    if(ok(l,r,l,nx))
                    update_ans(l,r,last,'R',i+1,l,nx,2,dp[i][l][r][last]+add) ;
                }
            }
            else
            {
                int goal=mp[s[i+1]] ;
                if(l==goal)
                {
                    int add=add_l[last][0] ;
                    update_ans(l,r,last,'L',i+1,l,r,1,dp[i][l][r][last]+add) ;
                }
                else if(r==goal)
                {
                    int add=add_r[last][0] ;
                    update_ans(l,r,last,'R',i+1,l,r,2,dp[i][l][r][last]+add) ;
                }
                else
                {
                    int dx= l+goal==3 ? 2 : 1 ;
                    int add=add_l[last][dx] ;
                    if(ok(l,r,goal,r))
                    update_ans(l,r,last,'L',i+1,goal,r,1,dp[i][l][r][last]+add) ;

                    dx=r+goal==3 ? 2 : 1;
                    add=add_r[last][dx] ;
                    if(ok(l,r,l,goal))
                    update_ans(l,r,last,'R',i+1,l,goal,2,dp[i][l][r][last]+add) ;
                }
            }
            //printf("dp[%d][%d][%d][%d]=%d\n",i,l,r,last,dp[i][l][r][last]) ;
        }
        int ans=INF , id1,id2,id3 ;
        for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int k=0;k<3;k++)
            if(dp[n][i][j][k]<ans) ans=dp[n][id1=i][id2=j][id3=k] ;
        //printf("%d\n",ans) ;
        print_ans(n,id1,id2,id3) ;
        printf("\n") ;
    }
}
