//#define NDEBUG
#include<bits/stdc++.h>
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
using namespace std;
struct P
{
    int st ; char c;
    bool operator < (const P &rhs) const
    {
        if(st!=rhs.st) return st<rhs.st ;
        else return c<rhs.c ;
    }
};
struct Q{int st ; char c,type ;};
map<P,Q> mp ;
char s[20001] ;
int S,M ;

void build_turning()
{
    mp.clear() ;
    for(int i=1;i<=(S-2)*(M+2);i++)
    {
        int x,z ; char y[3],u[3],v[3] ; scanf("%d%s%d%s%s",&x,y,&z,u,v) ;
        mp[(P){x,y[0]}]=(Q){z,u[0],v[0]} ;
    }
}

bool implement()
{
    int state=3 , pos=0 ;
    while(1)
    {
        Q next=mp[(P){state,s[pos]}] ;
        debugf("state=%d , pos=%d , s=%s , next : (%d,%c,%c)\n",state,pos,s,next.st,next.c,next.type);
        if(next.st<=2) return next.st==1 ;
        int dx= (next.type=='<' ? -1 : (next.type=='>' ? 1 : 0)) ;
        s[pos]=next.c ;
        pos += dx ; if(dx==1 && s[pos]=='\0') {s[pos]='u' ; s[pos+1]='\0' ;}
        state=next.st ;
    }
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&S,&M) ;
        build_turning() ;
        int Q ; scanf("%d",&Q) ; fgets(s+1,15000,stdin) ;
        while(Q--)
        {
            fgets(s+1,15000,stdin) ;
            s[0]='s' ;
            int k=strlen(s+1) ;
            if(s[k]=='\n' || s[k]=='\r') s[k]='\0' ;
            else if(k && (s[k-1]=='\n' || s[k-1]=='\r')) s[k-1]='\0' ;
            if(implement()) printf("yes %s\n",s) ;
            else printf("no\n") ;
        }
    }
}
