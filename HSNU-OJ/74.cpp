#include<bits/stdc++.h>
#define LL long long
const int maxn=1000000 + 10 ;
int left[maxn],right[maxn],val[maxn],fix[maxn],weight[maxn] ;
int cnt,root ;

int newnode(int value)
{
    int u=++cnt ; left[u]=right[u]=0 ;
    val[u]=value ; fix[u]=rand() ; weight[u]=1 ;
    return u ;
}

struct Treap
{
    void left_rotate(int &u)
    {
        int v=right[u] ;
        right[u]=left[v] ;
        left[v]=u ;
        u=v ;
    }

    void right_rotate(int &u)
    {
        int v=left[u] ;
        left[u]=right[v] ;
        right[v]=u ;
        u=v ;
    }

    void insert(int &u,int value)
    {
        if(!u) u=newnode(value) ;
        else if(val[u]>value)
        {
            insert(left[u],value) ;
            if(fix[left[u]]<fix[u]) right_rotate(u) ;
        }
        else if(val[u]<value)
        {
            insert(right[u],value) ;
            if(fix[right[u]]<fix[u]) left_rotate(u) ;
        }
        else weight[u]++ ;
    }

    int find_max(int &u) {return right[u] ? find_max(right[u]) : val[u] ;}
    int find_min(int &u) {return left[u] ? find_min(left[u]) : val[u] ;}

    void erase(int &u,int value)
    {
        if(val[u]==value)
        {
            if(!left[u]) {weight[u]-- ; if(!weight[u]) u=right[u] ; }
            else if(!right[u]) {weight[u]-- ; if(!weight[u]) u=left[u] ; }
            else
            {
                if(fix[left[u]]<fix[right[u]])
                {
                    right_rotate(u) ;
                    erase(right[u],value) ;
                }
                else
                {
                    left_rotate(u) ;
                    erase(left[u],value) ;
                }
            }
        }
        else if(val[u]>value) erase(left[u],value) ;
        else erase(right[u],value) ;
    }
};

main()
{
    srand(time(NULL)) ;
    Treap trp ;
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        LL ans=0LL ;
        cnt=0 , root=0 ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            while(x--)
            {
                int y ; scanf("%d",&y) ;
                trp.insert(root,y) ;
            }
            int M=trp.find_max(root) , m=trp.find_min(root) ;
            trp.erase(root,M) ; trp.erase(root,m) ;
            ans+=(LL)(M-m) ;
        }
        printf("%lld\n",ans) ;
    }
}
