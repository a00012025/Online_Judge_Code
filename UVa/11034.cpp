#include<stdio.h>
#include<queue>
using namespace std;
queue<int> l,r ;
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int L,m ;
        scanf("%d%d",&L,&m) ; L*=100 ;
        while(!l.empty()) l.pop() ;
        while(!r.empty()) r.pop() ;
        while(m--)
        {
            char s[10] ; int a ;
            scanf("%d%s",&a,s) ;
            if(s[0]=='l') l.push(a) ;
            else r.push(a) ;
        }
        bool left=1 ;
        int ans=0 ;
        while(!l.empty() || !r.empty())
        {
            if(l.empty() && left==1) {ans++ ; left=0 ;}
            else if(r.empty() && left==0) {ans++ ; left=1 ;}
            else
            {
                int cnt=0 ;
                if(left)
                {
                    while(!l.empty())
                    {
                        int a=l.front() ; cnt+=a ;
                        if(cnt>L) break ;
                        l.pop() ;
                    }
                    left=0 ; ans++ ;
                }
                else
                {
                    while(!r.empty())
                    {
                        int a=r.front() ; cnt+=a ;
                        if(cnt>L) break ;
                        r.pop() ;
                    }
                    left=1 ; ans++ ;
                }
            }
        }
        printf("%d\n",ans) ;
    }
}
