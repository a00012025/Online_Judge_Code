#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;

char s[500101],t[500] ;
LL L[500101],R[500101] ;
int len,alldif ;

bool ok()
{
    if(len%2) return 0 ;
    int dif=0 , num=0 ; alldif=0 ;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='?') num++ ;
        if(s[i]=='(') alldif++ ;
        if(s[i]==')') alldif-- ;
    }
    if(alldif-num>0 || alldif+num<0) return 0 ;
    int tmp= (num-alldif)/2 , cnt=0 ; dif=0 ;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(') dif++ ;
        if(s[i]==')') dif-- ;
        if(s[i]=='?') {cnt++ ; if(cnt<=tmp) dif++ ; else dif-- ; }
        if(dif<0) return 0 ;
    }
    return 1 ;
}

vector<int> v ; /// +3,?,?,-1,?,?,+2,?,-4,? ; ?->0 ;
LL dp[500101] ;
main()
{
    int T; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s",s) ;
        len=strlen(s) ; int cnt=0 ;
        for(int i=0;i<len;i++) if(s[i]=='?') { cnt++ ; scanf("%lld%lld",&L[cnt],&R[cnt]) ; }
        if(!ok()){ printf("IMBA\n") ; continue ; }

        v.clear() ; int dif=0 , zero=0 ;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='?'){ if(dif) v.push_back(dif) ; dif=0 ; v.push_back(0) ; zero++ ; }
            if(s[i]=='(')
            {
                if(dif<0) v.push_back(dif) , dif=0 ;
                dif++ ;
            }
            if(s[i]==')')
            {
                if(dif>0) v.push_back(dif) , dif=0 ;
                dif-- ;
            }
        }

        for(int i=0;i<=500001;i++) dp[i]=INF ; dp[0]=0LL ;
        int lo=0 , hi=0 , sum=0 ; cnt=0 ;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=0)
            {
                sum+=v[i] ;
                lo=max(lo,(cnt+1-sum)/2) ;
                continue ;
            }
            cnt++ ;
            for(int j=hi;j>=lo;j--) dp[j+1]=min(dp[j+1]+R[cnt],dp[j]+L[cnt]) ;
            dp[lo]+=R[cnt] ;
            hi++ ; hi=min(hi,(zero-alldif)/2) ;
            lo=max(lo,(cnt+1-sum)/2) ;
        }
        printf("%lld\n",dp[(zero-alldif)/2]) ;
    }
}
