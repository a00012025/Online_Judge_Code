#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
using namespace std;
map<int,int> mp ;
int l[10001],r[10001],tmp[30000] ;
int ST[100000],ans[20000] ;

void buildtree(int l,int r,int id)
{
    ST[id]=0 ;
    if(l==r) return ;
    int mid=(l+r)/2 ;
    buildtree(l,mid,2*id) ;
    buildtree(mid+1,r,2*id+1) ;
}

void modify(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R) {ST[id]=val ; return ;}
    int mid=(L+R)/2 ;
    if(ST[id]>0) {ST[2*id]=ST[id] ; ST[2*id+1]=ST[id] ;}
    if(r<=mid) modify(l,r,L,mid,2*id,val) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1,val) ;
    else
    {
        modify(l,mid,L,mid,2*id,val) ;
        modify(mid+1,r,mid+1,R,2*id+1,val) ;
    }
    if(ST[2*id]!=ST[2*id+1]) ST[id]=-1 ;
    else if(ST[2*id]!=0) ST[id]=ST[2*id] ;
    else ST[id]=0 ;
}

int query(int x,int L,int R,int id)
{
    if(ST[id]!=-1) return ST[id] ;
    else
    {
        int mid=(L+R)/2 ;
        if(x<=mid) return query(x,L,mid,2*id) ;
        else return query(x,mid+1,R,2*id+1) ;
    }
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        mp.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&l[i],&r[i]) ;
            tmp[2*i-1]=l[i] ; tmp[2*i]=r[i]+1 ;
        }
        sort(tmp+1,tmp+2*n+1) ;
        int cnt=0 ;
        for(int i=1;i<=2*n;i++)
        {
            if(i==1 || tmp[i]!=tmp[i-1]) mp[tmp[i]]=++cnt ;
        }
        buildtree(1,cnt,1) ;
        for(int i=1;i<=n;i++)
        {
            int x=mp[l[i]] , y=mp[r[i]+1];
            y-- ;
            modify(x,y,1,cnt,1,i) ;
                //for(int j=1;j<=13;j++)printf("%d,",ST[j]);
                //printf("\n");
        }
        memset(ans,0,sizeof(ans)) ;
        int ANS=0 ;
        for(int i=1;i<=cnt;i++) ans[query(i,1,cnt,1)]=1 ;
        for(int i=1;i<=n;i++) if(ans[i]) ANS++ ;
        printf("%d\n",ANS) ;
            //for(int i=1;i<=cnt;i++) printf("%d,",query(i,1,cnt,1));
            //for(int i=1;i<=11;i++)printf("%d,",mp[i]);
            //printf("\n");
    }
}
