#include<bits/stdc++.h>
using namespace std;

struct bign
{
    vector<int> s ;
    bign operator = (int a)
    {
        s.clear() ;
        int tmp=a ;
        while(1)
        {
            s.push_back(tmp%10) ;
            tmp/=10 ;
            if(!tmp) break ;
        }
        return *this ;
    }
    bign operator + (const bign &rhs)
    {
        bign ret ;
        for(int i=0;i<s.size()||i<rhs.s.size();i++)
        {
            if(i>=s.size()) ret.s.push_back(rhs.s[i]) ;
            else if(i>=rhs.s.size()) ret.s.push_back(s[i]) ;
            else ret.s.push_back(s[i]+rhs.s[i]) ;
        }
        for(int i=0;i<ret.s.size();i++) if(ret.s[i]>9)
        {
            ret.s[i]-=10 ;
            if(i==ret.s.size()-1) ret.s.push_back(1) ;
            else ret.s[i+1]++ ;
        }
        return ret ;
    }
    bign operator += (const bign &rhs)
    {
        return (*this = *this + rhs) ;
    }
    void print()
    {
        for(int i=s.size()-1;i>=0;i--) printf("%d",s[i]) ;
    }
};

bign dp[150][150][150][4] ;

main()
{
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        printf("Case #%d: ",++tc) ;
        if(n%2) {printf("0\n") ; continue ; }
        for(int i=0;i<=n/2;i++) for(int j=0;j<=n/2;j++)
            for(int k=0;k<=n;k++) for(int type=0;type<4;type++)
            dp[i][j][k][type]=0 ;
        for(int j=1;j<n/2;j++) dp[0][j][n-j][0]=1 ;
        bign ans ; ans=0 ;
        for(int i=0;i<=n/2;i++) for(int j=1;j<=n/2;j++)
            for(int k=3;k<n;k++)
        {
            if(j+2>k) continue ;
            if(j+2==k)
            {
                for(int type=0;type<4;type++) ans+=dp[i][j][k][type] ;
                continue ;
            }
            for(int h1=j ; 4+2*h1-j<=k ; h1++) for(int h2=0 ; 4+2*(h1-h2)-j<=k ; h2--)
                dp[i+1][h1-h2][k-2-(h1-j-h2)][0] += dp[i][j][k][0] ; /// 0->0

            for(int h1=j-1 ; h1>0 ; h1--) for(int h2=0 ; 4+j-2*h2<=k ; h2--)
                dp[i+1][h1-h2][k-2-(j-h1-h2)][1] += dp[i][j][k][0] ; /// 0->1

            for(int h1=j ; 4+2*h1-j <= k ; h1++) for(int h2=1 ; h2<j ; h2++)
                dp[i+1][h1-h2][k-2-(h1-j+h2)][2] += dp[i][j][k][0] ; /// 0->2

            if(j+4<=k)
            for(int h1=j-1 ; h1>=2 ; h1--) for(int h2=1 ; h2<h1 ;h2++)
                dp[i+1][h1-h2][k-2-(j-h1+h2)][3] += dp[i][j][k][0] ; /// 0->3

            for(int h1=j ; h1>0 ; h1--) for(int h2=0; 4+j-2*h2<=k ; h2--)
                dp[i+1][h1-h2][k-2-(j-h1-h2)][1] += dp[i][j][k][1] ; /// 1->1

            if(j+4<=k)
            for(int h1=j ; h1>=2 ; h1--) for(int h2=1 ; h2<h1 ; h2++) /// 1->3
                dp[i+1][h1-h2][k-2-(j-h1+h2)][3] += dp[i][j][k][1] ;

            for(int h1=j ; 4+2*h1-j<=k ; h1++) for(int h2=0 ; h2<j ; h2++)
                dp[i+1][h1-h2][k-2-(h1-j+h2)][2] += dp[i][j][k][2] ; /// 2->2

            if(j+4<=k)
            for(int h1=j-1 ; h1>=2 ; h1--) for(int h2=0 ; h2<h1 ; h2++)
                dp[i+1][h1-h2][k-2-(j-h1+h2)][3] += dp[i][j][k][2] ; /// 2->3

            if(j+4<=k)
            for(int h1=j ; h1>=2 ; h1--) for(int h2=0 ; h2<h1 ; h2++)
                dp[i+1][h1-h2][k-2-(j-h1+h2)][3] += dp[i][j][k][3] ; /// 3->3
        }
        ans.print() ;
        printf("\n") ;
    }
}

