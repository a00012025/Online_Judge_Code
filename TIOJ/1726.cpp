#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=60000+10 ;

int n ;
int cal1(const vector<int> &v1,const vector<int> &v2)
{
    int ret=n+1 ;
    int i=0 , j=0 ;
    while(i+1<v1.size() && j+1<v2.size())
    {
        if(v1[i]<v2[j])
        {
            while(i<v1.size() && v1[i]<v2[j])
                ret=min(ret,v2[j]-v1[i]) , i++ ;
            if(i!=v1.size()) ret=min(ret,v1[i]-v2[j]) ;
        }
        else
        {
            ret=min(ret,v1[i]-v2[j]) ;
            while(j<v2.size() && v2[j]<v1[i])
                ret=min(ret,v1[i]-v2[j]) , j++ ;
            if(j!=v2.size()) ret=min(ret,v2[j]-v1[i]) ;
        }
    }
    return ret ;
}

int cal2(const vector<int> &v1,const vector<int> &v2)
{
    int ret=n+1 ;
    for(int i=0;i<v1.size();i++)
    {
        int id=lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin() ;
        if(id!=v2.size()) ret=min(ret,v2[id]-v1[i]) ;
        if(id) ret=min(ret,v1[i]-v2[id-1]) ;
    }
    return ret ;
}

vector<int> gp[maxn],v ;
int ans[200][200] ;
main()
{
    int Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++)
    {
        int t ; scanf("%d",&t) ;
        gp[t].push_back(i) ;
    }

    int x= (int)pow( ((DB)n)*((DB)n)/log(n),1.0/3.0) ;

    for(int i=1;i<=n;i++) if(gp[i].size()>x) v.push_back(i) ;
    for(int i=0;i<v.size();i++) for(int j=i+1;j<v.size();j++)
        ans[i][j]=ans[j][i]=cal1(gp[v[i]],gp[v[j]]) ;

    while(Q--)
    {
        int a,b ; scanf("%d%d",&a,&b) ;
        if(gp[a].empty() || gp[b].empty()) printf("-1\n") ;
        else if(gp[a].size()>x && gp[b].size()>x)
        {
            int id1=lower_bound(v.begin(),v.end(),a)-v.begin() ;
            int id2=lower_bound(v.begin(),v.end(),b)-v.begin() ;
            printf("%d\n",ans[id1][id2]) ;
        }
        else printf("%d\n", gp[a].size()>gp[b].size() ?
                            cal2(gp[b],gp[a]) : cal2(gp[a],gp[b])) ;
    }
}
