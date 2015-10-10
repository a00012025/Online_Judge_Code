#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=4000+10 ;

void get_pos(char *s,int n,vector<int> *pos)
{
    for(int i=0;i<=n;i++) pos[i].clear() ;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(s[i]!=s[j])
        pos[j-i+1].push_back(i) ;
}

int val[maxn][maxn] ;
void process(vector<int> *v,vector<int> *pos,int inv)
{
    for(int i=0;i<26;i++)
        for(int j=0;j<v[i].size();j++) for(int k=j+1;k<v[i].size();k++)
    {
        int x1=v[i][j] , x2=v[i][k] , len=x2-x1+1 ;
        if(!inv) for(auto it : pos[len])
            val[x1][it]=min(val[x1][it],len) ;
        else for(auto it : pos[len])
            val[it][x1]=min(val[it][x1],len) ;
    }
}

char s[maxn],t[maxn] ;
vector<int> v1[26],v2[26],pos1[maxn],pos2[maxn] ;
int mi1[maxn],mi2[maxn] ;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s%s",s,t) ;
        int n=strlen(s) , m=strlen(t) ;
        get_pos(s,n,pos1) ;
        get_pos(t,m,pos2) ;
        for(int i=0;i<26;i++) v1[i].clear() , v2[i].clear() ;
        for(int i=0;i<n;i++) v1[s[i]-'a'].push_back(i) ;
        for(int i=0;i<m;i++) v2[t[i]-'a'].push_back(i) ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            val[i][j]=min(n-i,m-j)+1 ;

        process(v1,pos2,0) ;
        process(v2,pos1,1) ;

        for(int i=n-2;i>=0;i--) for(int j=m-2;j>=0;j--)
            val[i][j]=min(val[i][j],val[i+1][j+1]+1) ;

        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            printf("val[%d][%d]=%d\n",i,j,val[i][j]) ;

        LL ans=0LL ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            int maxl=min(n-i,m-j) ;
            ans+=(LL)(val[i][j]+maxl)*(maxl-val[i][j]+1)/2 ;
        }
        printf("%lld\n",ans) ;
    }
}
