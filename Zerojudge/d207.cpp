#include<stdio.h>
#include<string.h>
#include<queue>
#define LL long long
#define M 100000
using namespace std;
queue<LL> q ;
int state[5][5],s[5][5] ;
int dx[4]={1,-1,0,0} , dy[4]={0,0,1,-1} ;
int head[M] , next[10*M], cnt ;
LL val[10*M] ;

LL encode()
{
    LL ret=0 ;
    for(int i=1;i<=4;i++) for(int j=1;j<=4;j++)
    {
        ret*=16 ;
        ret+=s[i][j] ;
    }
    return ret ;
}

void decode(LL n)
{
    for(int i=4;i>=1;i--) for(int j=4;j>=1;j--)
    {
        state[i][j]=n%16 ;
        n /= 16 ;
    }
}

int h(LL n)
{
    return n%M ;
}

void hash_clear()
{
    memset(next,0,sizeof(next)) ;
    memset(head,-1,sizeof(head)) ;
    cnt=0 ;
}

bool found(LL n)
{
    int k=h(n) ;
    if(head[k]==-1) return 0 ;
    for(int j=head[k];j!=0;j=next[j]) if(n==val[j]) return 1;
    return 0;
}

void hash_insert(LL n)
{
    int k=h(n) ; cnt++ ; val[cnt]=n ;
    if(head[k]==-1) head[k]=cnt ;
    else
    {
        next[cnt]=head[k] ;
        head[k]=cnt ;
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        hash_clear() ;
        LL start=0,ed=0 ;
        for(int i=1;i<=16;i++)
        {
            int a;
            scanf("%d",&a) ;
            start *= 16 ; start+=a ;
        }
        for(int i=1;i<=4;i++) for(int j=1;j<=4;j++)
        {
            ed*=16 ;
            ed+=( (i==4&&j==4) ? 0 : ((i-1)*4)+j ) ;
        }
        while(!q.empty()) q.pop() ;
        q.push(start) ; q.push(0) ; hash_insert(start) ;
        decode(start) ;
        for(int i=1;i<=4;i++) for(int j=1;j<=4;j++) if(!state[i][j]) {q.push(i) ; q.push(j) ; break ;}
        int ans=100000000 ;
        while(!q.empty())
        {
            LL u=q.front() ; q.pop() ;
            LL num=q.front() ; q.pop() ;
            LL x0=q.front() ; q.pop() ;
            LL y0=q.front() ; q.pop() ;
            if(u==ed) {ans=num ; break ;}
            decode(u) ;

            memcpy(s,state,sizeof(s)) ;
            for(int k=0;k<4;k++)
            {
                int nx=x0+dx[k] , ny=y0+dy[k] ;
                if(nx<1 || nx>4 || ny<1 || ny>4) continue ;
                    //printf("(%d,%d)->(%d,%d)\n",i,j,nx,ny) ;
                s[x0][y0]=s[nx][ny] ; s[nx][ny]=0 ;
                LL N=encode() ;
                if(!found(N)) {hash_insert(N) ; q.push(N) ; q.push(num+1) ; q.push(nx) ; q.push(ny);}
                s[nx][ny]=s[x0][y0] ; s[x0][y0]=0 ;
            }
        }
        if(ans==100000000) printf("This puzzle is not solvable.\n") ;
        else printf("%d\n",ans) ;
    }
}
