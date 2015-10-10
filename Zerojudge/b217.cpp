#include<bits/stdc++.h>
#define LL long long
using namespace std;

char s[100000] ;
string subj[100000] ;
int day[100000] ; LL id[100000] ;

map<string,int> mp ;
string inv[20000] ;
int idnum=0 ;
int ID(const string &st)
{
    if(!mp.count(st))
    {
        mp[st]=++idnum ;
        inv[idnum]=st ;
    }
    return mp[st] ;
}

struct P
{
    int day ; LL id ; int cnt ;
    bool operator < (const P &rhs) const
    {
        if(day!=rhs.day) return day<rhs.day ;
        else return cnt<rhs.cnt ;
    }
};
vector<P> v[100000] ;

struct Q
{
    int day ; LL id ; int cnt,vid ;
    bool operator < (const Q &rhs) const
    {
        if(day!=rhs.day) return day<rhs.day ;
        else return cnt<rhs.cnt ;
    }
};

main()
{
    int cnt=0 ;
    while(gets(s))
    {
        if(s[0]=='\n' || s[0]=='\0' || s[0]=='\r') break ;
        cnt++ ;
        string st ;
        int len=strlen(s) ;
        int re=0 ;
        if(s[9]=='R' && (s[10]=='e' || s[10]=='E') && s[11]==':' && s[12]==' ')
            re=1 ;
        while(s[len]=='\0' || s[len]=='\n' || s[len]=='\r' || s[len]==' ') len-- ;
        for(int i= re?13:9;i<=len;i++) st.push_back(s[i]) ;
        subj[cnt]=st ;
        int m=1,d=2,h=3,y=4 ; gets(s) ;
        sscanf(&s[5],"%d%d%d%d",&m,&d,&h,&y) ;
        day[cnt]=100000*y+1000*m+30*d+h ;
        gets(s) ;
        sscanf(&s[3],"%lld",&id[cnt]) ;
        gets(s) ;
    }
    for(int i=1;i<=cnt;i++) v[ID(subj[i])].push_back((P){day[i],id[i],i}) ;
    for(int i=1;i<=idnum;i++) sort(v[i].begin(),v[i].end()) ;
    vector<Q> tmp ;
    for(int i=1;i<=idnum;i++)
        tmp.push_back((Q){v[i][0].day,v[i][0].id,v[i][0].cnt,i}) ;
    sort(tmp.begin(),tmp.end()) ;
    int ansid[3] ; ansid[0]=tmp[0].vid ; if(tmp.size()>=2) ansid[1]=tmp[1].vid ;
    for(int z=0;z<2;z++)
    {
        if(z==1 && tmp.size()==1) continue ;
        int id1=ansid[z] ;
        cout << "Subject: " << inv[id1] << endl << "ID: " ;
        for(int i=0;i<v[id1].size();i++)
            printf("%lld%c",v[id1][i].id,i+1==v[id1].size()?'\n':',') ;
        printf("\n") ;
    }
    printf("\n") ;
}
