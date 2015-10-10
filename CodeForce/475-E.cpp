#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10 ;

vector<int> v0[maxn],v[maxn] ;
int lev[maxn],bcc[maxn],w[maxn],bcnt=0 ;
stack<int> st ;

int dfs(int x,int f,int l)
{
    int low ;
    low=lev[x]=l ;
    st.push(x) ;
    for(auto i : v0[x]) if(i!=f)
    {
        if(lev[i]!=-1) {low=min(low,lev[i]) ; continue ;}
        int tmp=dfs(i,x,l+1) ;
        low=min(low,tmp) ;
        if(tmp>l)
        {
            bcnt++ ;
            while(1)
            {
                int top=st.top() ; st.pop() ;
                bcc[top]=bcnt ; w[bcnt]++ ;
                if(top==i) break ;
            }
        }
    }
    if(x==1)
    {
        bcnt++ ;
        while(!st.empty())
            bcc[st.top()]=bcnt , w[bcnt]++ ,
            st.pop() ;
    }
    return low ;
}

int n ;
void find_BCC()
{
    memset(lev,-1,sizeof(lev)) ;
    dfs(1,-1,0) ;
    for(int i=1;i<=n;i++) for(auto j : v0[i])
        if(bcc[i]!=bcc[j])
        v[bcc[i]].push_back(bcc[j]) ;
}

int ans ;
int dfs2(int x,int f,int s)
{
    int ret=w[x] ;
    ans+=s*w[x] ;
    for(auto i : v[x]) if(f!=i)
        ret+=dfs2(i,x,s+w[i]) ;
    return ret ;
}

int tmp[maxn] ;
bool dp[maxn] ;
main()
{
    int m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v0[x].push_back(y) ;
        v0[y].push_back(x) ;
    }

    find_BCC() ;
    int sum=n ; n=bcnt ;

    int ANS=0 ;
    for(int i=1;i<=n;i++)
    {
        ans=w[i]*sum ;
        fill(dp,dp+sum-w[i]+1,0) ; dp[0]=1 ;
        for(auto j : v[i])
        {
            int x=dfs2(j,i,w[j]) ;
            for(int k=sum-w[i];k>=x;k--)
                if(dp[k-x]) dp[k]=1 ;
        }

        int x=(sum-w[i])/2 ;
        while(!dp[x]) x-- ;
        ans+=x*(sum-w[i]-x) ;
        ANS=max(ANS,ans) ;
    }
    printf("%d\n",ANS) ;
}
