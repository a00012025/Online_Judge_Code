#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<iostream>
#include<vector>
#include<queue>
#define FOR(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
struct P{int x,y,z;};
vector<P> rule ;
map<char,int> mp ;
char ch[50] ;
int n,L,ch_num,num ;

int id(char c)
{
    if(mp.count(c)) return mp[c] ;
    ch_num++ ; num++ ; mp[c]=ch_num ; ch[ch_num]=c ;
    return ch_num ;
}

bool operator < (const vector<int> &u,const vector<int> &v)
{
    for(int i=0;i<u.size() && i<v.size();i++) if(u[i]!=v[i]) return u[i]<v[i] ;
    return u.size()<v.size() ;
}

vector<int> d[600][21],low[600][21] ;
bool have_str[2][600][21] ;
struct pii
{
    int first,second ;
    bool operator < (const pii &rhs) const
    {
        return d[first][second]>d[rhs.first][rhs.second] ;
    }
};
priority_queue<pii> pq ;

bool update(int x1,int y1,int x2,int y2,int x3,int y3)
{
    vector<int> s1=d[x2][y2] ;
    if(d[x3][y3].size())
    FOR(i,0,d[x3][y3].size()-1) s1.push_back(d[x3][y3][i]) ;
    vector<int> s2=low[x2][y2] ;
    if(low[x3][y3].size())
    FOR(i,0,low[x3][y3].size()-1) s2.push_back(low[x3][y3][i]) ;

    bool ok1=0 ;
    if(have_str[0][x2][y2] && have_str[0][x3][y3])
    {
        if(!have_str[0][x1][y1] || s1<d[x1][y1])
        {
            d[x1][y1]=s1 ;
            have_str[0][x1][y1]=1 ;
            ok1=1 ;
        }
    }
    bool ok2=0 ;
    if(have_str[1][x2][y2] && have_str[1][x3][y3])
    {
        if(!have_str[1][x1][y1] || s2<low[x1][y1])
        {
            low[x1][y1]=s2 ;
            have_str[1][x1][y1]=1 ;
            ok2=1 ;
        }
    }

    return (ok1||ok2) ;
}

bool go_empty[600] ;
string dp()
{
    memset(go_empty,0,sizeof(go_empty)) ;
    memset(have_str,0,sizeof(have_str)) ;
    for(int i=0;i<=num;i++) for(int j=0;j<=L;j++)
        {d[i][j].clear() ; low[i][j].clear() ; }
    for(int i=0;i<rule.size();i++) if(!rule[i].y && !rule[i].z)
    {
        have_str[0][rule[i].x][0]=have_str[1][rule[i].x][0]=1 ;
        go_empty[rule[i].x]=1 ;
    }
    for(int i=1;i<=num;i++)
    {
        d[i][1].push_back(i) ; have_str[0][i][1]=1 ;
        if(i<=ch_num && ch[i]>='a' && ch[i]<='z')
            {low[i][1].push_back(i) ; have_str[1][i][1]=1 ;}
    }
    FOR(len,2,L)
    {
        FOR(i,1,num) FOR(j,0,rule.size()-1) if(rule[j].x==i){
        FOR(l2,1,len-1)
            update(i,len,rule[j].y,l2,rule[j].z,len-l2) ;}

        while(!pq.empty()) pq.pop() ;
        FOR(i,1,num) if(have_str[0][i][len]) pq.push((pii){i,len}) ;
        while(!pq.empty())
        {
            pii v=pq.top() ; pq.pop() ;
            FOR(i,0,rule.size()-1) if(rule[i].y==v.first || rule[i].z==v.first)
            {
                if(rule[i].y==v.first && go_empty[rule[i].z])
                {
                    if(update(rule[i].x,len,v.first,len,rule[i].z,0))
                        pq.push((pii){rule[i].x,len}) ;
                }
                if(rule[i].z==v.first && go_empty[rule[i].y])
                {
                    if(update(rule[i].x,len,rule[i].y,0,v.first,len))
                        pq.push((pii){rule[i].x,len}) ;
                }
            }
        }
    }
/*
    FOR(len,2,L) FOR(i,1,num) if(have_str[0][i][len])
    {
        printf("%d,%d :",i,len) ;
        FOR(j,0,d[i][len].size()-1) printf(" %d",d[i][len][j]) ;
        printf("\n") ;
    }*/

    string ret ;
    if(have_str[1][id('S')][L]) FOR(i,0,low[id('S')][L].size()-1)
        ret.push_back(ch[low[id('S')][L][i]]) ;
    else ret="-" ;
    return ret ;
}

main()
{
    string tmp[60] ;
    while(scanf("%d%d",&n,&L)==2 && n+L)
    {
        rule.clear() ; mp.clear() ; ch_num=0 ;
        for(int i=1;i<=n;i++)
        {
            cin >> tmp[i] ;
            for(int j=0;j<tmp[i].size();j++) if(j!=1) id(tmp[i][j]) ;
        }
        for(int i=1;i<=n;i++)
        {
            if(tmp[i].size()==2) rule.push_back((P){id(tmp[i][0]),0,0}) ;
            else if(tmp[i].size()==3)
            {
                rule.push_back((P){id(tmp[i][0]),id(tmp[i][2]),num+1}) ;
                rule.push_back((P){num+1,0,0}) ;
                num++ ;
            }
            else if(tmp[i].size()==4)
                rule.push_back((P){id(tmp[i][0]),id(tmp[i][2]),id(tmp[i][3])}) ;
            else
            {
                num++ ;
                rule.push_back((P){id(tmp[i][0]),id(tmp[i][2]),num}) ;
                int sz=tmp[i].size() ;
                for(int j=2;j<sz-2;j++)
                {
                    rule.push_back((P){num,id(tmp[i][j+1]),num+1}) ;
                    num++ ;
                }
                rule.push_back((P){num,id(tmp[i][sz-2]),id(tmp[i][sz-1])}) ;
            }
        }
        //FOR(i,0,rule.size()-1) printf("%d -> %d , %d\n",rule[i].x,rule[i].y,rule[i].z) ;
        string ans=dp() ;
        cout << ans << endl ;
    }
}
