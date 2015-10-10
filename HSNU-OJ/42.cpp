#include<bits/stdc++.h>
using namespace std;
struct pii
{
    int x,y;
    bool operator < (const pii &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x ;
        else return y<rhs.y ;
    }
};

vector<pii> v ;
set<pii> st ;

void st_insert(const pii &p)
{
    //printf("\ninsert (%d,%d)\n",p.x,p.y) ;
    st.insert(p) ;
    set<pii>::iterator it=st.find(p) ;
    bool keep=1 ;
    it++ ;
    if(it!=st.end() && it->y >= p.y) keep=0 ;
    it-- ;
    if(!keep){st.erase(it) ; return ;}
    while(it!=st.begin())
    {
        set<pii>::iterator it2=it ; it2-- ;
        if(it2->y <= it->y) st.erase(it2) ;
        else break ;
    }
}

main()
{
    int n ; scanf("%d",&n) ;
    int sx=0,sy=0 ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(x<0 && y<0) continue ;
        else if(x>=0 && y>=0) sx+=x , sy+=y ;
        else v.push_back((pii){x,y}) ;
    }
    st.insert((pii){sx,sy}) ;
    vector<pii> tmp ;
    for(int i=0;i<v.size();i++)
    {
        tmp.clear() ;
        for(set<pii>::iterator it=st.begin();it!=st.end();it++)
            tmp.push_back((pii){ v[i].x+it->x,v[i].y+it->y }) ;
        for(int j=0;j<tmp.size();j++) st_insert(tmp[j]) ;
    }
    int ans=0 ;
    for(set<pii>::iterator it=st.begin();it!=st.end();it++)
        if(it->x>=0 && it->y>=0) ans=max(ans,it->x+it->y) ;
    printf("%d\n",ans) ;
}
