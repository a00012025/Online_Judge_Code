#include<bits/stdc++.h>
#define pii pair<int,int>
#define MKP(x,y) make_pair(x,y)
using namespace std;
const int maxn=100000+100 ;
int n,a,sum1[maxn],sum2[maxn] ;

int search(int x,int t)
{
    int l=x-1 , r=n+1 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if((sum1[mid]-sum1[x-1]>=t) || (sum2[mid]-sum2[x-1]>=t)) r=mid ;
        else l=mid ;
    }
    return r ;
}

int check(int t)
{
    int num1=0 , num2=0 , last=-1 ;
    for(int i=1;i<=n;)
    {
        int j=search(i,t) ;
        if(j==n+1) return -1 ;
        if(sum1[j]-sum1[i-1]==t) num1++ , last=1 ;
        else num2++ , last=2 ;
        i=j+1 ;
    }
    if(num1==num2) return -1 ;
    if(num1>num2) return last==1 ? num1 : -1 ;
    else return last==2 ? num2 : -1 ;
}

vector<pii> ans ;
main()
{
    scanf("%d",&n) ;
    sum1[0]=sum2[0]=0 ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a) ;
        sum1[i]=sum1[i-1]+ (a==1 ? 1 : 0) ;
        sum2[i]=sum2[i-1]+ (a==2 ? 1 : 0) ;
    }
    for(int i=max(sum1[n],sum2[n]);i>=1;i--)
    {
        int res=check(i) ;
        if(res!=-1) ans.push_back(MKP(res,i)) ;
    }
    sort(ans.begin(),ans.end()) ;
    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second) ;
}
