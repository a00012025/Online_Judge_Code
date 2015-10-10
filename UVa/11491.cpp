#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;
struct P{
    int val,id ;
    bool operator < (const P &rhs) const
    {
        if(val != rhs.val) return val>rhs.val ;
        else return id<rhs.id ;
    }
} ;
set<P> s ;
set<P>::iterator it ;
main()
{
    int n,d ;
    char c[101001],ans[101001] ;
    while(scanf("%d %d",&n,&d)==2 && n && d)
    {
        gets(c) ;
        while(c[0]<'0' || c[0]>'9') gets(c) ;
        int left=n,now=-1,cnt=0,d2=d ;
        int l=-1,r=-1 ; s.clear() ;
        while(left)
        {
            now++ ;
            if(l!=-1) for(int i=l;i<now;i++)
                s.erase(s.find((P){c[i]-'0',i})) ;
            for(int i=r+1;i<=now+d && i<n;i++)
                s.insert((P){c[i]-'0',i}) ;
            l=now ; r=now+d ;
            int val=(*s.begin()).val , id=(*s.begin()).id ;
            ans[cnt++]=val ;
            d-=id-now ; left=n-id-1 ; now=id ;
        }
        for(int i=now+1;i<n;i++) ans[cnt++]=c[i]-'0' ;
        for(int i=0;i<n-d2;i++) printf("%d",ans[i]) ;
        printf("\n") ;
    }
}
