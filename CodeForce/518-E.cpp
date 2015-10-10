#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;
const int maxn=100000+10 ;

bool solve(vector<int> &v)
{
    int sz=v.size() ;
    for(int i=0;i<sz-1;i++) if(v[i]!=INF && v[i+1]!=INF
        && v[i+1]<=v[i]) return 0 ;
    for(int i=0;i<sz-1;i++) if(v[i+1]==INF)
    {
        int j ;
        for(j=i+1;j<sz && v[j]==INF;j++) ;
        int num=j-i-1 ;
        if(v[i]+num>=v[j]) return 0 ;
        if(v[j]<=1) for(int z=i+1;z<j;z++)
            v[z]=z-j+v[j] ;
        else if(v[i]>=-1) for(int z=i+1;z<j;z++)
            v[z]=z-i+v[i] ;
        else
        {
            int l=0 , r=0 ; num-- ;
            while(num--)
            {
                if(r==v[j]-1 || (r+l>0 && l>v[i]+1)) l-- ;
                else r++ ;
            }
            for(int z=i+1;z<j;z++)
                v[z]=z-i-1+l ;
        }
    }
    return 1 ;
}

int n,k ;
int a[maxn] ;
vector<int> tmp ;
main()
{
    scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++)
    {
        char s[20] ; scanf("%s",s) ;
        if(s[0]=='?') a[i]=INF ;
        else sscanf(&s[0],"%d",&a[i]) ;
    }
    for(int i=1;i<=k;i++)
    {
        tmp.clear() ;
        tmp.push_back(-INF+1) ;
        for(int j=i;j<=n;j+=k) tmp.push_back(a[j]) ;
        tmp.push_back(INF-1) ;
        if(!solve(tmp))
        {
            printf("Incorrect sequence\n") ;
            return 0 ;
        }
        for(int j=i,cnt=0;j<=n;j+=k) a[j]=tmp[++cnt] ;
    }
    for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ') ;
}
