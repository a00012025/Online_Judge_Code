#include<bits/stdc++.h>
using namespace std ;
const int maxn=100000+10  ;

struct P{int x,y ; } ;
struct cmp1
{
    bool operator () (const P &a,const P &b)
    {
        return a.x==b.x ? a.y<b.y : a.x<b.x  ;
    }
}CMP ;
struct cmp2
{
    bool operator () (const P &a,const P &b)
    {
        return a.y==b.y ? a.x<b.x : a.y<b.y  ;
    }
} ;

set<P,cmp1> s1[2*maxn]  ;
set<P,cmp2> s2[2*maxn]  ;
int scnt=0  ;

int solve(set<P,cmp1> &st1,set<P,cmp2> &st2)
{
    scnt++  ;
    auto i1=st1.begin()  ;  auto i2=st2.begin()  ;
    auto r1=st1.rbegin()  ;  auto r2=st2.rbegin()  ;

    while(CMP(*i1,*r1))
    {
        int v=i1->x  ;
        if((++i1)->x > v+1 )
        {
            int tmp=scnt  ;
            for(auto it=st1.begin() ; it->x <= v ; it=st1.begin())
                s2[tmp].insert(*it) , st2.erase(*it) ,
                s1[tmp].insert(*it) , st1.erase(*it)  ;
            return solve(st1,st2)+solve(s1[tmp],s2[tmp])  ;
        }

        v=r1->x  ;
        if((++r1)->x < v-1 )
        {
            int tmp=scnt  ;
            for(auto it=st1.rbegin() ; it->x >= v ; it=st1.rbegin())
                s2[tmp].insert(*it) , st2.erase(*it) ,
                s1[tmp].insert(*it) , st1.erase(*it)  ;
            return solve(st1,st2)+solve(s1[tmp],s2[tmp])  ;
        }

        v=i2->y  ;
        if((++i2)->y > v+1 )
        {
            int tmp=scnt  ;
            for(auto it=st2.begin() ; it->y <= v ; it=st2.begin())
                s1[tmp].insert(*it) , st1.erase(*it) ,
                s2[tmp].insert(*it) , st2.erase(*it)  ;
            return solve(st1,st2)+solve(s1[tmp],s2[tmp])  ;
        }

        v=r2->y  ;
        if((++r2)->y < v-1 )
        {
            int tmp=scnt  ;
            for(auto it=st2.rbegin() ; it->y >= v ; it=st2.rbegin())
                s1[tmp].insert(*it) , st1.erase(*it) ,
                s2[tmp].insert(*it) , st2.erase(*it)  ;
            return solve(st1,st2)+solve(s1[tmp],s2[tmp])  ;
        }
    }
    return 1  ;
}

int main()
{
    int n  ;  scanf("%d",&n)  ;
    while(n--)
    {
        int x,y  ;  scanf("%d%d",&x,&y)  ;
        s1[0].insert((P){x,y})  ;
        s2[0].insert((P){x,y})  ;
    }
    printf("%d\n",solve(s1[0],s2[0]))  ;
}
