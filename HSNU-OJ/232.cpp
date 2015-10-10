#include<bits/stdc++.h>
#define LL long long
using namespace std;
const char ch[]={'A','C','G','T'} ;
map<char,int> mp ;
LL dp[50010][11][4],power[50010] ;
char s[50002] ;
bool now[20] ;

void pre_cal(int n)
{
    power[n+1]=1LL ;
    for(int i=n;i>=1;i--) power[i]= (s[i]=='N' ? power[i+1]*4 : power[i+1]) ;
}

main()
{
    for(int i=0;i<4;i++) mp[ch[i]]=i ;
    int n,k ; LL R ; scanf("%d%d%lld%s",&n,&k,&R,s+1) ;
    pre_cal(n) ;
    for(int i=n+1;i>=1;i--) for(int j=1;j<=k;j++) for(int z=0;z<4;z++)
    {
        if(i==n+1)
        {
            if(j==1) dp[i][j][z]=1LL ;
            continue ;
        }
        if(i==n)
        {
            if(j==2) dp[i][j][z]= s[i]=='N' ? 4LL : 1LL ;
            if(j==1)
            {
                if(s[i]=='N') dp[i][j][z]= (LL)4-z ;
                else if(z<=mp[s[i]]) dp[i][j][z]=1LL ;
            }
            continue ;
        }

        vector<int> tmp ;
        if(s[i]=='N') for(int z2=0;z2<4;z2++) tmp.push_back(z2) ;
        else tmp.push_back(mp[s[i]]) ;
        for(int x=0;x<tmp.size();x++)
        {
            int z2=tmp[x] ;
            if(z2>=z)
            {
                dp[i][j][z]+=dp[i+1][j][z2] ;
                if(n-i+1==j-1) dp[i][j][z]+=power[i+1] ;
            }
            else dp[i][j][z]+=dp[i+1][j-1][z2] ;
        }
    }
    /// length=n , k parts , the R-th small

    memset(now,0,sizeof(now)) ; now[0]=1 ;
    s[0]='A' ;
    int l=0 , r=0 ;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='N')
        {
            int newz ;
            for(newz=0;newz<4;newz++)
            {
                int l2,r2 ;
                if(mp[s[i-1]]<=newz) l2=l , r2=r+1 ;
                else l2=l+1 , r2=r+1 ;

                LL val=0LL ;
                for(int j=k+1-l2;j>=k+1-r2 && j>=1;j--)
                    val=max(val,dp[i+1][j][newz]) ;
                if(val>=R) break ;
                R-=val ;
            }
            s[i]=ch[newz] ;
        }
        if(mp[s[i]]>=mp[s[i-1]]) r++ ;
        else l++ , r++ ;
        if(i==1) l=1 ;
    }
    printf("%s\n",s+1) ;
}
