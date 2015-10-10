#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

int fail[maxn] ;
void getfail(const vector<int> &v)
{
    if(v.size()==1) return ;
    fail[0]=-1 ;
    for(int i=1,j=-1;i+1<v.size();i++)
    {
        while(j>=0 && v[j+2]-v[j+1]!=v[i+1]-v[i])
            j=fail[j] ;
        if(v[j+2]-v[j+1]==v[i+1]-v[i]) j++ ;
        fail[i]=j ;
    }
}

void match(const vector<int> &v,const vector<int> &S,vector<int> &ret)
{
    ret.clear() ;
    int sz=v.size() , last=v[sz-1] ;
    if(sz==1)
    {
        for(auto i : S) ret.push_back(i-last+1) ;
        return ;
    }
    for(int i=0,j=-1;i+1<S.size();i++)
    {
        while(j>=0 && v[j+2]-v[j+1]!=S[i+1]-S[i]) j=fail[j] ;
        if(v[j+2]-v[j+1]==S[i+1]-S[i]) j++ ;
        if(j==sz-2) ret.push_back(S[i+1]-last+1) , j=fail[j] ;
    }
}

vector<int> v1[30],v2[30] ;

int mch[maxn][30],num[maxn] ;
void update(int pos,int sz,int i,int j)
{
    num[pos]+=sz ;
    mch[pos][i]=j ;
}

vector<int> tmp,ans ;
char s[maxn],t[maxn] ;
main()
{
    int n,m ; scanf("%d%d%s%s",&n,&m,s+1,t+1) ;
    for(int i=1;i<=n;i++) v1[s[i]-'a'+1].push_back(i) ;
    for(int i=1;i<=m;i++) v2[t[i]-'a'+1].push_back(i) ;
    for(int i=1;i<=26;i++) if(!v2[i].empty())
    {
        getfail(v2[i]) ;
        int sz=v2[i].size() ;
        for(int j=1;j<=26;j++) if(!v1[j].empty())
        {
            match(v2[i],v1[j],tmp) ;
            for(auto it : tmp) if(it>=1 && it<=n-m+1)
                update(it,sz,i,j) ;
        }
    }
    for(int i=1;i<=n-m+1;i++) if(num[i]==m)
    {
        bool ok=1 ;
        for(int j=1;j<=26;j++) if(mch[i][j])
        {
            int x=mch[i][j] ;
            if(mch[i][x] && mch[i][x]!=j)
                {ok=0 ; break ;}
            mch[i][x]=j ;
        }
        if(ok) ans.push_back(i) ;
    }
    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++) printf("%d%c",ans[i],i+1==ans.size()?'\n':' ') ;
}
