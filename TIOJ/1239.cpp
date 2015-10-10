#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;

int size[maxn] ;
vector<int> v[maxn] ;
bool vis[maxn] ;

bool dfs(int x,int num)
{
    vis[x]=1 ; size[x]=1 ;
    multiset<int> st ;
    for(auto i : v[x]) if(!vis[i])
    {
        if(!dfs(i,num)) return 0 ;
        size[x]+=size[i] ;
        if(size[i]%num) st.insert(size[i]%num) ;
    }
    if(st.size()<=1) return 1 ;
    if(x==1)
    {
        if(st.size()%2) return 0 ;
        while(!st.empty())
        {
            int t=*st.begin() ; st.erase(st.begin()) ;
            if(!st.count(num-t)) return 0 ;
            st.erase(st.find(num-t)) ;
        }
        return 1 ;
    }

    int cnt=0 ;
    while(st.size()>1)
    {
        int t=*st.begin() ; st.erase(st.begin()) ;
        if(!st.count(num-t)) cnt++ ;
        else st.erase(st.find(num-t)) ;
        if(cnt>1) return 0 ;
    }
    if(!st.empty()) cnt++ ;
    return cnt<=1 ;
}

bool check(int x)
{
    if(x<=2) return 1 ;
    memset(vis,0,sizeof(vis)) ;
    return dfs(1,x) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    for(int i=n-1;i>=1;i--) if(((n-1)%i==0) && check(i))
    {
        printf("%d\n",i) ;
        return 0 ;
    }
}
