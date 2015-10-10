#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int a[200001],dp[200001],lis ;
vector<int> v[200001],anc[200001] ;
bool ans[200001],inva[200001] ;

int find_in_v(int n,int val)
{
    if(a[v[n][0]]<val) return 0 ;
    int l=0 , r=v[n].size()-1 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(a[v[n][mid]]>val) l=mid ;
        else r=mid ;
    }
    return r ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n ;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        memset(ans,0,sizeof(ans)) ;
        memset(inva,0,sizeof(inva)) ;
        for(int i=0;i<=n;i++)
        {
            v[i].clear() ; anc[i].clear() ;
            dp[i]=300000 ;
        }
        dp[1]=a[1] ; lis=1 ; v[1].push_back(1) ;
        for(int i=2;i<=n;i++)
        {
            if(dp[lis]<a[i])
            {
                int start=find_in_v(lis,a[i]) ;
                for(int j=start;j<v[lis].size();j++)
                    anc[i].push_back(v[lis][j]) ;
                lis++ ; dp[lis]=a[i] ;
                v[lis].push_back(i) ;
                continue ;
            }
            else if(dp[1]>a[i])
            {
                v[1].push_back(i) ;
                dp[1]=a[i] ;
                continue ;
            }
            int l=1 , r=lis ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ;
                if(dp[mid]>a[i]) r=mid ;
                else l=mid ;
            }
            int start=find_in_v(l,a[i]) ;
            for(int j=start;j<v[l].size();j++)
                anc[i].push_back(v[l][j]) ;
            v[l+1].push_back(i) ;
            dp[l+1]=min(dp[l+1],a[i]) ;
        }
        if(v[lis].size()==1) ans[v[lis][0]]=1 ;
        for(int i=lis;i>=2;i--)
        {
            for(int j=0;j<v[i-1].size();j++) inva[v[i-1][j]]=1 ;
            int candi=-1 , nosol=0 ;
            for(int j=0;j<v[i].size();j++)
            {
                int nowid=v[i][j] ;
                if(inva[nowid]) continue ;
                for(int k=0;k<anc[nowid].size();k++)
                {
                    inva[anc[nowid][k]]=0;
                    if(candi==-1) candi=anc[nowid][k] ;
                    else if(candi!=anc[nowid][k]) nosol=1 ;
                }
            }
            if(!nosol) ans[candi]=1 ;
        }
        int cnt=0,ANS=0 ;
        for(int i=1;i<=n;i++)
        {
            if(!ans[i]) continue ;
            cnt++ ; ANS ^= (i+cnt) ;
        }
        printf("%d %d\n",cnt,ANS) ;
    }
}
