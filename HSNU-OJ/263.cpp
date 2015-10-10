#include<bits/stdc++.h>
using namespace std;
const int maxn=150000+10 ;

struct P
{
    int pos,id,num,right ;
    bool operator < (const P &rhs) const
    {
        return pos!=rhs.pos ? pos<rhs.pos : id<rhs.id ;
    }
};
bool cmp(const P &a,const P &b)
{
    if(a.pos!=b.pos) return a.pos<b.pos ;
    else return a.id<b.id ;
}
vector<P> gp[maxn] ;

int n,sqr,L,now[maxn],gpcnt ;
int lgp[maxn],rgp[maxn],firgp,lasgp ;
int gid[maxn] ;

int upper_bound(const vector<P> &v,int val)
{
    if(v[0].pos > val) return 0 ;
    int l=0 , r=v.size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(v[mid].pos>val) r=mid ;
        else l=mid ;
    }
    return r ;
}

void cal_group(int x,bool ok)
{
    if(!ok) sort(gp[x].begin(),gp[x].end(),cmp) ;
    int sz=gp[x].size() , ri=gp[x][sz-1].pos ;
    for(int i=sz-1;i>=0;i--)
    {
        if(gp[x][i].pos + L >= ri)
        {
            gp[x][i].num=1 ;
            gp[x][i].right = gp[x][i].pos + L ;
            continue ;
        }
        int i2= upper_bound(gp[x],gp[x][i].pos + L) ;
        gp[x][i].num=gp[x][i2].num+1 ;
        gp[x][i].right=gp[x][i2].right ;
    }
}

int get_ans()
{
    int ret=0 , now2=gp[firgp][0].pos-1 ;
    for(int i=firgp;;i=rgp[i])
    {
        int sz=gp[i].size() ;
        if(now2>=gp[i][sz-1].pos)
        {
            if(i==lasgp) break ;
            continue ;
        }

        int id= upper_bound(gp[i],now2) ;
        ret+=gp[i][id].num ;
        now2=gp[i][id].right ;
        if(i==lasgp) break ;
    }
    return ret ;
}

void erase(int id,int x,int val)
{
    int sz=gp[id].size() ;
    int id2=upper_bound(gp[id].begin(),gp[id].end(),(P){val,x-1,-1,-1},cmp)-gp[id].begin() ;
    for(int i=id2;i<sz-1;i++) gp[id][i]=gp[id][i+1] ;
    gp[id].resize(sz-1) ;
    if(sz==1)
    {
        if(firgp==id) firgp=rgp[id] ;
        else if(lasgp==id) lasgp=lgp[id] ;
        else lgp[rgp[id]]=lgp[id] , rgp[lgp[id]]=rgp[id] ;
    }
    else cal_group(id,1) ;
}

void insert(int id,int x,int newpos)
{
    int sz=gp[id].size() ;
    P las=gp[id][sz-1] ;
    P newp=(P){newpos,x,-1,-1} ;
    if(gp[id][sz-1]<newp) gp[id].push_back(newp) ;
    else
    {
        int i ;
        for(i=sz-1;i>0 && newp<gp[id][i-1];i--) gp[id][i]=gp[id][i-1] ;
        gp[id][i]=newp ; gp[id].push_back(las) ;
    }
    cal_group(id,1) ;
}

void split(int id)
{
    int sz=gp[id].size() ;
    for(int i=sz/2;i<sz;i++)
        gp[gpcnt].push_back(gp[id][i]) ,
        gid[gp[id][i].id]=gpcnt ;
    gp[id].resize(sz/2) ;
    if(id==lasgp) lasgp=gpcnt , rgp[id]=gpcnt , lgp[gpcnt]=id ;
    else
    {
        lgp[rgp[id]]=gpcnt ; rgp[gpcnt]=rgp[id] ;
        lgp[gpcnt]=id ; rgp[id]=gpcnt ;
    }
    cal_group(id,1) ;
    cal_group(gpcnt,1) ;
    gpcnt++ ;
}

void maintain(int id)
{
    int sz=gp[id].size() ;
    if(sz>=2*sqr) split(id) ;
}

main()
{
    int Q ; scanf("%d%d%d",&n,&L,&Q) ;
    sqr=(int)sqrt(n+0.5) ;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&now[i]) ;
        gp[i/sqr].push_back((P){now[i],i,-1,-1}) ;
        gid[i]=i/sqr ;
    }

    gpcnt=((n-1)/sqr)+1 ;
    firgp=0 ; lasgp=gpcnt-1 ;
    for(int i=0;i<gpcnt;i++)
    {
        lgp[i]=i-1 , rgp[i]=i+1 ;
        cal_group(i,1) ;
    }
    maintain(gpcnt-1) ;

    int last=0 ;
    while(Q--)
    {
        int x,newpos ; scanf("%d%d",&x,&newpos) ;
        x-=last , newpos-=last ;
        erase(gid[x],x,now[x]) ;
        maintain(gid[x]) ;

        int ngp=firgp ;
        while(ngp!=lasgp && gp[ngp][0].pos <= newpos)
            ngp=rgp[ngp] ;
        if(gp[ngp][0].pos > newpos && ngp!=firgp) ngp=lgp[ngp] ;

        now[x]=newpos ; gid[x]=ngp ;
        insert(ngp,x,newpos) ;
        maintain(ngp) ;

        printf("%d\n",last=get_ans()) ;
    }
}
