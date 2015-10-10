#include<bits/stdc++.h>
using namespace std;
struct P
{
    int x,y ;
    bool operator < (const P &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x ;
        else return y<rhs.y ;
    }
    bool operator != (const P &rhs) const { return (x!=rhs.x)||(y!=rhs.y) ; }
};

typedef vector<P> poly ;
vector<poly> v ;
char color[500] ;

bool equ(const poly &v1,const poly &v2)
{
    for(int i=0;i<v1.size();i++) if(v1[i]!=v2[i]) return 0 ;
    return 1 ;
}

void normalize(poly &p)
{
    int minx=1000 , miny=1000 ;
    for(auto i : p)
    {
        minx=min(minx,i.x) ;
        miny=min(miny,i.y) ;
    }
    poly q ;
    for(auto i : p) q.push_back((P){(i.x)-minx,(i.y)-miny}) ;
    p=q ;
}

void rotat(poly &p)
{
    poly q ;
    for(auto i : p) q.push_back((P){-i.y,i.x}) ;
    normalize(q) ;
    p=q ;
}

int n,m ;
char ans[500][500],now[500][500] ;
int rot_num[30] ;

bool better()
{
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(now[i][j]!=ans[i][j])
        return now[i][j]<ans[i][j] ;
    return 0 ;
}

bool can_place(int x,int y,const poly &p)
{
    for(auto i : p) if(now[x+i.x][y+i.y]!='Z') return 0 ;
    return 1 ;
}


void dfs(int x)
{
    if(x==(int)v.size())
    {
        if(better()) for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            ans[i][j]=now[i][j] ;
        return ;
    }
    poly newp=v[x] ;
    for(int z=0;z<rot_num[x];z++)
    {
        int mx=0,my=0 ;
        for(auto it : newp) mx=max(mx,it.x) , my=max(my,it.y) ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            if(i+mx>=n || j+my>=m) continue ;
            if(can_place(i,j,newp))
            {
                for(auto it : newp) now[i+it.x][j+it.y]=color[x] ;
                dfs(x+1) ;
                for(auto it : newp) now[i+it.x][j+it.y]='Z' ;
            }
        }
        rotat(newp) ;
    }
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int x ; scanf("%d%d%d",&n,&m,&x) ;
        v.clear() ;
        poly tmp ;
        for(int i=0;i<x;i++)
        {
            char s[100],ch ;
            tmp.clear() ;
            for(int j=0;j<4;j++)
            {
                scanf("%s",s) ;
                for(int k=0;k<4;k++) if(s[k]!='.')
                {
                    color[i]=s[k] ;
                    tmp.push_back((P){j,k}) ;
                }
            }
            normalize(tmp) ;
            v.push_back(tmp) ;
            if(i!=x-1) scanf("%s",s) ;
        }

        for(int i=0;i<x;i++)
        {
            poly tmp2=v[i] ;
            int num=0 ;
            for(num=1;;num++)
            {
                rotat(tmp2) ;
                sort(tmp2.begin(),tmp2.end()) ;
                if(equ(v[i],tmp2)) break ;
            }
            rot_num[i]=num ;
        }

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) ans[i][j]=now[i][j]='Z' ;
        dfs(0) ;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ans[i][j]=='Z') printf(".") ;
                else printf("%c",ans[i][j]) ;
            }
            printf("\n") ;
        }
        if(T) printf("#\n") ;
    }
}

