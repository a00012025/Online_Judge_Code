#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define LL long long
#define INF (1LL<<33)
const int maxn=60000+10 ;
int left[20*maxn],right[20*maxn],fix[20*maxn] ;
LL val[20*maxn] ;
int weight[20*maxn],size[20*maxn],cnt,root[maxn] ;

int newnode(LL value)
{
    int u=++cnt ; right[u]=left[u]=0 ;
    val[u]=value ; fix[u]=rand() ; weight[u]=size[u]=1 ;
    return u ;
}

struct Treap
{
    inline int lsize(int u){ return left[u] ? size[left[u]] : 0 ; }
    inline int rsize(int u){ return right[u] ? size[right[u]] : 0 ; }
    void maintain(int u) { size[u]=lsize(u)+rsize(u)+weight[u] ; }

    void left_rotate(int &u)
    {
        int v=right[u] ;
        right[u]=left[v] ;
        left[v]=u ;
        u=v ; v=left[u] ;
        maintain(v) ; maintain(u) ;
    }

    void right_rotate(int &u)
    {
        int v=left[u] ;
        left[u]=right[v] ;
        right[v]=u ;
        u=v ; v=right[u] ;
        maintain(v) ; maintain(u) ;
    }

    void insert(int &u,LL value)
    {
        if(!u) u=newnode(value) ;
        else if(val[u]>value)
        {
            insert(left[u],value) ; maintain(u) ;
            if(fix[left[u]]<fix[u]) right_rotate(u) ;
        }
        else if(val[u]<value)
        {
            insert(right[u],value) ; maintain(u) ;
            if(fix[right[u]]<fix[u]) left_rotate(u) ;
        }
        else weight[u]++ , size[u]++ ;
    }

    void erase(int &u,LL value)
    {
        if(!u) return ;
        if(val[u]==value)
        {
            if(!left[u]) {weight[u]-- ; if(!weight[u]) u=right[u] ; maintain(u) ; }
            else if(!right[u]) {weight[u]-- ; if(!weight[u]) u=left[u] ; maintain(u) ; }
            else
            {
                if(fix[left[u]]<fix[right[u]])
                {
                    right_rotate(u) ;
                    erase(right[u],value) ;
                    maintain(u) ;
                }
                else
                {
                    left_rotate(u) ;
                    erase(left[u],value) ;
                    maintain(u) ;
                }
            }
        }
        else if(val[u]>value) erase(left[u],value) , maintain(u) ;
        else erase(right[u],value) , maintain(u) ;
    }

    int great(int u,LL value)
    {
        if(!u) return 0 ;
        if(val[u]==value) return lsize(u)+weight[u] ;
        else if(val[u]>value) return great(left[u],value) ;
        else return lsize(u)+weight[u]+great(right[u],value) ;
    }

    int strict_great(int u,LL value)
    {
        if(!u) return 0 ;
        if(val[u]==value) return lsize(u) ;
        else if(val[u]>value) return strict_great(left[u],value) ;
        else return lsize(u)+weight[u]+strict_great(right[u],value) ;
    }
};

LL a[maxn] ; int n ;
Treap trp[maxn] ;

void build_BIT()
{
    for(int i=1;i<=n;i++)
        for(int j=i;j>i-lowbit(i);j--)
            trp[i].insert(root[i],a[j]) ;
}

main()
{
    srand(time(NULL)) ;
    int m ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        cnt=0 ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        memset(root,0,sizeof(root)) ;
        build_BIT() ;
        while(m--)
        {
            char c[3] ; scanf("%s",c) ;
            if(c[0]=='2')
            {
                int x ; LL y ; scanf("%d%lld",&x,&y) ;
                for(int i=x;i<=n;i+=lowbit(i))
                    trp[i].erase(root[i],a[x]) , trp[i].insert(root[i],y) ;
                a[x]=y ;
            }
            else if(c[0]=='1')
            {
                int L,R,k ; scanf("%d%d%d",&L,&R,&k) ;
                LL l=-1 , r=INF , ans=-1 ;
                while(r-l>1)
                {
                    LL mid=l+(r-l)/2 ;   /// num1 : L~R , strictly great
                    int num1=0,num2=0 ; /// num2 : L~R , great
                    for(int x=R;x;x-=lowbit(x))
                        num1 += trp[x].strict_great(root[x],mid) ,
                        num2 += trp[x].great(root[x],mid) ;
                    for(int x=L-1;x;x-=lowbit(x))
                        num1 -= trp[x].strict_great(root[x],mid) ,
                        num2 -= trp[x].great(root[x],mid) ;
//                    printf("mid=%d , num1=%d , num2=%d\n",mid,num1,num2) ;
                    if(num1+1<=k && k<=num2) { ans=mid ; break ; }
                    else if(k<=num1) r=mid ;
                    else l=mid ;
                }
                printf("%lld\n",ans) ;
            }
            else
            {
                int x,y ; scanf("%d%d",&x,&y) ;
                printf("7122\n") ;
            }
        }
    }
}
