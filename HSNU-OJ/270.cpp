#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;
vector<int> v[maxn],reg[25001] ;
vector<int> v1 ;
int n,R ;
int in[maxn],out[maxn],tim=0;
int ans1[450][25001],ans2[450][25001] ;

bool cmp(int x,int y)
{
    return in[x]<in[y] ;
}

void dfs(int x)
{
    in[x]=++tim ;
    for(int i=0;i<v[x].size();i++)
        dfs(v[x][i]) ;
    out[x]=++tim ;
}

inline bool is_fa(int x,int y) /// x is fa of y
{
    return in[x]<=in[y] && out[x]>=out[y] ;
}

int rbd[maxn] ;
int st[maxn] ;
int cal_ans(int x,int y) /// x : down , y : up
{
    int sz1=reg[x].size() , sz2=reg[y].size() ;

    int rcnt=0 ;
    int sz=0 ;
    for(int i=0;i<sz2;i++)
    {
        while(sz && st[sz-1]<out[reg[y][i]])
            rbd[rcnt++]=st[sz-1] , sz-- ;
        st[sz++]=out[reg[y][i]] ;
    }
    for(int i=sz-1;i>=0;i--)
        rbd[rcnt++]=st[i] ;

    int ret=0 , lid=0 , rid=0 , num=0 ;
    for(int i=0;i<sz1;i++)
    {
        while(lid<sz2 && in[reg[y][lid]]<in[reg[x][i]])
            num++ , lid++ ;
        while(rid<sz2 && rbd[rid]<in[reg[x][i]])
            num-- , rid++ ;
        ret+=num ;
    }

    return ret ;
}

int pre[maxn],col[maxn] ;
void pre_cal()
{
    for(int i=0;i<v1.size();i++) /// up : large
    {
        int sz=0,cnt=0 ;
        for(int j=1;j<=n;j++) if(col[pre[j]]!=v1[i])
        {
            while(cnt<reg[v1[i]].size() && in[reg[v1[i]][cnt]]<in[pre[j]])
            {
                while(sz && out[reg[v1[i]][st[sz-1]]]<in[reg[v1[i]][cnt]])
                    sz-- ;
                st[sz++]=cnt++ ;
            }
            while(sz && out[reg[v1[i]][st[sz-1]]]<in[pre[j]]) sz-- ;
            ans1[i][col[pre[j]]]+=sz ;
        }
        for(int j=1;j<=R;j++)
            if(!reg[j].empty() && j!=v1[i])
            ans2[i][j]=cal_ans(v1[i],j) ;
    }
}

main()
{
    int Q ; scanf("%d%d%d",&n,&R,&Q) ;
    for(int i=1;i<=n;i++)
    {
        int x,y ;
        if(i==1) scanf("%d",&y) ;
        else scanf("%d%d",&x,&y) ;
        if(i>1) v[x].push_back(i) ;
        reg[y].push_back(i) ;
        col[i]=y ;
    }
    dfs(1) ;
    int sq=(int)sqrt(n+0.5) ;
    for(int i=1;i<=R;i++)
        sort(reg[i].begin(),reg[i].end(),cmp) ;

    for(int i=1;i<=n;i++) pre[i]=i ;
    sort(pre+1,pre+n+1,cmp) ;

    for(int i=1;i<=R;i++) if(reg[i].size()>=sq)
        v1.push_back(i) ;
    pre_cal() ;

    while(Q--)
    {
        int x,y ; scanf("%d%d",&x,&y) ; /// x : up , y : down
        if(reg[x].size()>=sq)
        {
            int i=lower_bound(v1.begin(),v1.end(),x)-v1.begin() ;
            printf("%d\n",ans1[i][y]) ;
        }
        else if(reg[y].size()>=sq)
        {
            int i=lower_bound(v1.begin(),v1.end(),y)-v1.begin() ;
            printf("%d\n",ans2[i][x]) ;
        }
        else printf("%d\n",cal_ans(y,x)) ;
    }
}
