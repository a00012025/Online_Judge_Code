#include<bits/stdc++.h>
using namespace std;
const int maxn=50000+10 ;

int a[2*maxn],L[2*maxn] ;
int st[2*maxn] ;
vector<int> ans ;

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=2*n;i++) scanf("%d",&a[i]) ;
    for(int i=2*n;i>=1;i--) if(!L[a[i]]) L[a[i]]=i ;
    int num=0 ;
    for(int now=1;now<=2*n;)
    {
        st[num++]=a[now++] ;
        if(num>=2 && L[st[num-1]]>L[st[num-2]])
        {
            for(int i=num-1;i>=1;i--)
            {
                if(L[st[i]]>L[st[i-1]])
                    ans.push_back(i) , swap(st[i],st[i-1]) ;
                else break ;
            }
            while(now<=2*n && num && st[num-1]==a[now]) now++ , num-- ;
        }
    }
    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]) ;
}
