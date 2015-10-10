#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

map<int,int> mp ;
int a[maxn] ;
int nex[maxn],las[maxn],head,tail ;
int maxl,sum ;

multiset<int,greater<int> > st1 ;
multiset<int> st2 ;

void erase2(int val)
{
    auto it=st1.find(val) ;
    if(it!=st1.end()) st1.erase(it) ;
    else
    {
        st2.erase(st2.find(val)) ;
        sum-=val ;
        st2.insert(*st1.begin()) ;
        sum+=*st1.begin() ;
        st1.erase(st1.begin()) ;
    }
}

void insert(int val)
{
    st2.insert(val) ; sum+=val ;
    st1.insert(*st2.begin()) ; sum-=*st2.begin() ;
    st2.erase(st2.begin()) ;
}

void erase(int x)
{
    int id=mp[x] ;
    if(id==tail || id==head)
    {
        int val ;
        if(id==tail) val=a[id]-a[las[id]] , tail=las[id] ;
        else val=a[nex[id]]-a[id] , head=nex[id] ;
        maxl=a[tail]-a[head] ;
        erase2(val) ;
    }
    else
    {
        int val1=a[id]-a[las[id]] , val2=a[nex[id]]-a[id] ;
        las[nex[id]]=las[id] , nex[las[id]]=nex[id] ;

        insert(val1+val2) ;
        erase2(val1) ; erase2(val2) ;
    }
}

main()
{
    int n,k,Q ; scanf("%d%d%d",&n,&k,&Q) ;
    k-- ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]) ;
        nex[i]=i+1 ; las[i]=i-1 ;
    }
    head=1 ; tail=n ;
    sort(a+1,a+n+1) ;
    maxl=a[n]-a[1] ;
    for(int i=1;i<=n;i++)
    {
        mp[a[i]]=i ;
        if(i<n) st1.insert(a[i+1]-a[i]) ;
    }

    sum=0 ;
    for(int i=1;i<=k;i++)
    {
        sum+=*st1.begin() ;
        st2.insert(*st1.begin()) ;
        st1.erase(st1.begin()) ;
    }
    printf("%d\n",maxl-sum) ;

    while(Q--)
    {
        int x ; scanf("%d",&x) ;
        erase(x) ;
        printf("%d\n",maxl-sum) ;
    }
}
