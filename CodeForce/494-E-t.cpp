#include<bits/stdc++.h>
using namespace std;

const int maxn=100+10 ;

vector<int> v ;
int mex()
{
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
    for(int i=0;i<v.size();i++) if(v[i]!=i+1) return i+1 ;
    return v.size()+1 ;
}

int a[maxn][maxn][maxn] ;
int cal(int id,int x1,int y1,int x2,int y2)
{
    int ret=0 ;
    for(int i=x1;i<=x2;i++) for(int j=y1;j<=y2;j++)
        ret^=a[id][i][j] ;
    return ret ;
}

main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int ik=1;ik<=k;ik++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        if(i==1||j==1){a[ik][i][j]=1 ; continue ;}
        v.clear() ;
        for(int z=2;z<=ik && z<=min(i,j);z++)
        {
            int val=cal(ik,i-z+1,j-z+1,i,j) ;
            if(val) v.push_back(val) ;
        }
        a[ik][i][j]=mex() ;
    }

//    int x,y ;
//    while(scanf("%d%d",&x,&y)==2)
//    {
//        for(int i=1;i<=k;i++) printf("%d,",a[i][x][y]) ;
//        printf("\n") ;
//    }
//
//    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[k][i][j]==5)
//        printf("(%d,%d):%d\n",i,j,a[k][i][j]) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        int x=a[k][i][j],t=1 ;
        while(x!=1){if(x&1)t=0 ; x/=2;}
        printf("%c",a[k][i][j]==5?'@':' ') ;
        if(j==n) printf("\n") ;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        printf("%2d%c",a[k][i][j],j==n?'\n':' ') ;
}
