#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
struct pii{int st,emp ;};
vector<pii> v[2000] ;
map<string,int> mp ;
string mp_inv[2000] ;
int car[2000],cdr[2000] ;

int n,L,num ;

bool all_lower(string &s)
{
    for(int i=0;i<s.size();i++) if(s[i]<'a' || s[i]>'z') return 0;
    return 1;
}

int id(string s)
{
    if(mp.count(s)) return mp[s] ;
    mp[s]=num ; mp_inv[num]=s ;
    num++ ; return mp[s] ;
}

void get_tmp_symbol(string S)
{
    int s=id(S) ;
    if(S.size()<2) return ;
    int s1=id(S.substr(0,1)) ;
    int s2=id(S.substr(1,S.size()-1)) ;
    v[s1].push_back((pii){s,s2}) ;
    v[s2].push_back((pii){s,s1}) ;
    car[s]=s1 ;
    cdr[s]=s2 ;
}

string dp[2000][25] ;

bool update(string &s,string t)
{
    if(s=="-" || t<s) {s=t ; return 1 ;}
    else return 0 ;
}

struct P
{
    int id ; string s ;
    bool operator < (const P &rhs) const
    {
        return s>rhs.s ;
    }
};

bool vis[2000] ;
void Search(int len)
{
    priority_queue<P> pq ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=0;i<num;i++) if(dp[i][len]!="-") pq.push((P){i,dp[i][len]}) ;
    while(!pq.empty())
    {
        P u=pq.top() ; pq.pop() ;
        string s=u.s ;
        if(vis[u.id]) continue ;
        vis[u.id]=1 ;
        for(int i=0;i<v[u.id].size();i++)
        {
            int st=v[u.id][i].st , emp=v[u.id][i].emp ;
            if(dp[emp][0]=="" && update(dp[st][len],s))
                pq.push((P){st,dp[st][len]}) ;
        }
    }
}

main()
{
    while(scanf("%d%d",&n,&L)==2 && n+L)
    {
        mp.clear() ; num=0 ;
        for(int i=0;i<2000;i++) {v[i].clear() ; mp_inv[i].clear() ;}
        id("") ;
        for(int i=1;i<=n;i++)
        {
            string tmp ; cin >> tmp ;
            int s1=id(tmp.substr(0,1)) ;
            int s2=id(tmp.substr(2)) ;
            v[s2].push_back((pii){s1,id("")}) ;
            for(int j=2;j<tmp.size();j++)
                get_tmp_symbol(tmp.substr(j)) ;
        }

        for(int i=0;i<num;i++) for(int len=0;len<=L;len++)
            dp[i][len]="-" ;
        dp[0][0]="" ;
        for(int len=0;len<=L;len++)
        {
            for(int i=0;i<num;i++)
            {
                if(mp_inv[i].size()==len && all_lower(mp_inv[i]))
                    dp[i][len]=mp_inv[i] ;
                if(mp_inv[i].size()<2) continue ;
                int s1=car[i] , s2=cdr[i] ;
                for(int j=1;j<len;j++) if(dp[s1][j]!="-" && dp[s2][len-j]!="-")
                    update(dp[i][len] , dp[s1][j]+dp[s2][len-j]) ;
            }
            Search(len) ;
        }
        cout << dp[id("S")][L] << endl ;
    }
}
