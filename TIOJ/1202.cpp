#include<bits/stdc++.h>
using namespace std;

struct P
{
    int pos,h,type;
    bool operator < (const P &rhs) const
    {
        if(pos!=rhs.pos) return pos<rhs.pos ;
        if(h!=rhs.h) return h<rhs.h ;
        return type<rhs.type ;
    }
};

multiset<int,greater<int> > s ;
vector<P> v ;
main()
{
    int n ;
    while(scanf("%d",&n)==1 && n)
    {
        s.clear() ;
        v.clear() ;
        while(n--)
        {
            int l,h,r ; scanf("%d%d%d",&l,&h,&r) ;
            v.push_back((P){l,h,1}) ;
            v.push_back((P){r,h,2}) ;
        }
        sort(v.begin(),v.end()) ;
        int now=0 ;
        s.insert(0) ;
        for(int i=0;i<v.size();)
        {
            int i2=i ;
            while(i2<v.size() && v[i2].pos==v[i].pos)
            {
                if(v[i2].type==1) s.insert(v[i2].h) ;
                else s.erase(s.find(v[i2].h)) ;
                i2++ ;
            }
            if(*s.begin() != now)
                { now=*s.begin() ; printf("%d %d ",v[i].pos,now) ; }
            i=i2 ;
        }
        printf("\n") ;
    }
}
