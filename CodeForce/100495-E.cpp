#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
int a[100001] ;
map<int,int> m ;
map<int,int>::iterator it ;
main()
{
    int T,tc=0;
    scanf("%d",&T);
    while(T-- && ++tc)
    {
        int n,t ;
        scanf("%d %d",&n,&t) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        int left,right=1,ans=1 ;
        m.clear() ; m[a[1]]=1 ;
        for(left=1;left<=n;left++)
        {
            for(right=right+1;right<=n;right++)
            {
                if(!m.count(a[right])) m[a[right]]=1 ;
                else m[a[right]]++ ;
                int ma,mi ;
                it=m.begin() ; mi=it->first ;
                it=m.end() ; it-- ; ma=it->first ;
                if(ma-mi>t) break ;
            }
            ans=max(ans,right-left) ;
            if(right<=n)
            {
                if(m[a[right]]>1) m[a[right]]-- ;
                else m.erase(a[right]) ;
            }
            right-- ;
            if(m[a[left]]>1) m[a[left]]-- ;
            else m.erase(a[left]) ;
        }
        printf("Case #%d: %d\n",tc,ans) ;
    }
}
