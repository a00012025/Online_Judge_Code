#include<bits/stdc++.h>
#define DB double
using namespace std;
struct pt{DB x,y;};

const DB eps=1e-7 ;
int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

pt operator + (const pt &a,const pt &b) {return (pt){a.x+b.x , a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) {return (pt){a.x-b.x , a.y-b.y} ; }

DB dot(const pt &a,const pt &b) {return a.x*b.x + a.y*b.y ;}
DB cross(const pt &a,const pt &b) {return a.x*b.y - a.y*b.x ;}

bool on_segment(const pt &p,const pt &a,const pt &b)
{
    return dcmp(cross(a-p,b-p))==0 && dcmp(dot(a-p,b-p))<=0 ;
}

DB area(const pt &a,const pt &b,const pt &c)
{
    return fabs(cross(a-b,c-b))/2 ;
}

vector<pt> p ;

bool check(int i,int j,int k,int l)
{
    int max1,max2,min1,min2 ;
    max1=max(max(p[i].x,p[j].x),max(p[k].x,p[l].x)) ;
    max2=max(max(p[i].y,p[j].y),max(p[k].y,p[l].y)) ;
    min1=min(min(p[i].x,p[j].x),min(p[k].x,p[l].x)) ;
    min2=min(min(p[i].y,p[j].y),min(p[k].y,p[l].y)) ;
    return max1==4 && max2==4 && min1==0 && min2==0 ;
}

struct P{int x,y,z,u;};
vector<P> ans ;
set<int> angle ;
main()
{
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) p.push_back((pt){i,j}) ;
    angle.insert(0) ; /*angle.insert(4) ; angle.insert(20) ; */angle.insert(24) ;
    int cnt=0,cnt2=0 ;
    for(int i=0;i<25;i++) for(int j=i+1;j<25;j++)
    for(int k=j+1;k<25;k++) for(int l=k+1;l<25;l++)
    {
        if(on_segment(p[i],p[j],p[k])) continue ;
        if(on_segment(p[i],p[l],p[k])) continue ;
        if(on_segment(p[i],p[j],p[l])) continue ;
        if(on_segment(p[j],p[l],p[k])) continue ;
        if(on_segment(p[j],p[i],p[k])) continue ;
        if(on_segment(p[j],p[l],p[i])) continue ;
        if(on_segment(p[k],p[j],p[i])) continue ;
        if(on_segment(p[k],p[l],p[j])) continue ;
        if(on_segment(p[k],p[i],p[l])) continue ;
        if(on_segment(p[l],p[i],p[j])) continue ;
        if(on_segment(p[l],p[j],p[k])) continue ;
        if(on_segment(p[l],p[k],p[i])) continue ;
        if(area(p[i],p[j],p[l])+area(p[j],p[k],p[l])+area(p[i],p[k],p[l])
           ==area(p[i],p[j],p[k]))
           {if(check(i,j,k,l)) ans.push_back((P){i,j,k,l}) ;
            cnt++ ; continue ;}
        if(area(p[i],p[j],p[k])+area(p[j],p[l],p[k])+area(p[i],p[l],p[k])
           ==area(p[i],p[j],p[l]))
           {if(check(i,j,k,l)) ans.push_back((P){i,j,k,l}) ;
            cnt++ ; continue ;}
        if(area(p[i],p[k],p[j])+area(p[l],p[k],p[j])+area(p[i],p[l],p[j])
           ==area(p[i],p[l],p[k]))
           {if(check(i,j,k,l)) ans.push_back((P){i,j,k,l}) ;
            cnt++ ; continue ;}
        if(area(p[j],p[k],p[i])+area(p[l],p[k],p[i])+area(p[l],p[j],p[i])
           ==area(p[l],p[j],p[k]))
           {if(check(i,j,k,l)) ans.push_back((P){i,j,k,l}) ;
            cnt++ ; continue ;}
    }
    printf("%d\n",cnt) ;
    cnt2=0 ;
    for(int i=0;i<ans.size();i++)
    {
        int num=angle.count(ans[i].x)+angle.count(ans[i].y)+angle.count(ans[i].z)+angle.count(ans[i].u) ;
        if(num==2) printf("%d,%d,%d,%d,%d\n",ans[i].x,ans[i].y,ans[i].z,ans[i].u,++cnt2);
    }
}
