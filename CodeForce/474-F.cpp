#include<stdio.h>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int a[100001],G[20][100001],tem[100001] ;
map<int,vector<int> > mp ;

int gcd(int x,int y)
{
    return y==0 ? x : gcd(y,x%y) ;
}

main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]) ; G[0][i]=a[i] ;
        if(mp.count(a[i])) mp[a[i]].push_back(i) ;
        else
        {
            vector<int> v ; v.clear() ; v.push_back(i) ;
            mp[a[i]]=v ;
        }
    }
    for(int i=1;i<20;i++) for(int j=1;j<=n;j++)
    {
        if(j+(1<<i)>n+1) continue ;
        G[i][j]=gcd(G[i-1][j],G[i-1][j+(1<<(i-1))]) ;
    }
    int Q;
    scanf("%d",&Q) ;
    while(Q--)
    {
        int l,r ;
        scanf("%d %d",&l,&r) ;
        int g=a[l] , left=l  ,len=20;
        while(left<r+1)
        {
            while(len>=0 && (left+(1<<len) > r+1)) len-- ;
            g=gcd(g,G[len][left]) ;
            left=left+(1<<len) ;
        }
        if(!mp.count(g)) {printf("%d\n",r-l+1) ; continue ;}
        len=mp[g].size() ;
        int ll=0,rr=len,r2,l2 ;
        while(rr-ll>1)
        {
            int mid=(ll+rr)/2 ;
            if(mp[g][mid]>=l) rr=mid ;
            else ll=mid ;
        }
        if(rr==1 && mp[g][0]>=l) rr=0 ;
        l2=rr ;

        ll=0 ; rr=len ;
        while(rr-ll>1)
        {
            int mid=(rr+ll)/2 ;
            if(mp[g][mid]>r) rr=mid ;
            else ll=mid ;
        }
        if(rr==1 && mp[g][0]>r) rr=0 ;
        r2=rr ;
        printf("%d\n",r-l+1-(r2-l2)) ;
        //printf("l2=%d , r2=%d\n",l2,r2) ;
    }
}
