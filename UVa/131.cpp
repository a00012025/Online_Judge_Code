#include<stdio.h>
#include<map>
#include<string.h>
#include<set>
#include<algorithm>
using namespace std;
typedef struct {int x,y ;} P ;
bool cmp(P a,P b)
{
    if(a.x!=b.x) return a.x<b.x ;
    else return a.y<b.y ;
}
map<char,int> mp1,mp2 ;
multiset<int> s1,s2 ;
int str[20][20]={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9},{6,7,8,9,10},{7,8,9,10,11},{8,9,10,11,12},{9,10,11,12,13},{10,11,12,13,1}};
char ANS[50][50]={"highest-card","one-pair","two-pairs","three-of-a-kind","straight","flush","full-house","four-of-a-kind","straight-flush"} ;
P p[11],card[11] ;
int ans,num1[20],num2[5] ;

int check(P a,P b,P c,P d,P e)
{
    s1.clear() ; s2.clear() ;
    for(int i=1;i<=13;i++) num1[i]=0 ;
    for(int i=1;i<=4;i++) num2[i]=0 ;
    s1.insert(a.x) ; s1.insert(b.x) ; s1.insert(c.x) ; s1.insert(d.x) ; s1.insert(e.x) ;
    s2.insert(a.y) ; s2.insert(b.y) ; s2.insert(c.y) ; s2.insert(d.y) ; s2.insert(e.y) ;
    num1[a.x]++ ; num1[b.x]++ ; num1[c.x]++ ; num1[d.x]++ ; num1[e.x]++ ;
    num2[a.y]++ ; num2[b.y]++ ; num2[c.y]++ ; num2[d.y]++ ; num2[e.y]++ ;
    bool flu=0,strai=0 ;
    for(int i=1;i<=4;i++) if(num2[i]==5) flu=1 ;
    for(int i=0;i<10;i++)
    {
        bool yes=1 ;
        for(int j=0;j<5;j++) if(!s1.count(str[i][j])) yes=0 ;
        if(yes==1) {strai=1 ; break ;}
    }
    if(flu && strai) return 8 ;
    else if(flu) return 5 ;
    else if(strai) return 4 ;

    int total[15]={0} ;
    for(int i=1;i<=13;i++) total[num1[i]]++ ;
    if(total[4]) return 7 ;
    else if(total[3]&&total[2]) return 6 ;
    else if(total[3]) return 3 ;
    else if(total[2]>=2) return 2;
    else if(total[2]) return 1;
    return 0 ;
}

void dfs(int last,int num)
{
        //for(int i=1;i<=5;i++)printf("(%d,%d) ",card[i].x,card[i].y);
        //printf("\n");
    ans=max(ans,check(card[1],card[2],card[3],card[4],card[5])) ;
    for(int i=last+1;i<=5;i++)
    {
        card[i]=p[num+6] ;
        dfs(i,num+1) ;
        card[i]=p[i] ;
    }
}

main()
{
    mp1['A']=1 ; mp1['2']=2 ; mp1['3']=3 ; mp1['4']=4 ;
    mp1['5']=5 ; mp1['6']=6 ; mp1['7']=7 ; mp1['8']=8 ;
    mp1['9']=9 ; mp1['T']=10 ; mp1['J']=11 ; mp1['Q']=12 ; mp1['K']=13 ;
    mp2['C']=1 ; mp2['D']=2 ; mp2['H']=3 ; mp2['S']=4 ;
    char s[100] ;
    while(gets(s))
    {
        int cnt=0 ;
        for(int i=0;i<strlen(s);i+=3)
            p[(i/3)+1].x=mp1[s[i]] , p[(i/3)+1].y=mp2[s[i+1]] ;
        for(int i=1;i<=5;i++) card[i]=p[i] ;
        ans=-1 ;
        dfs(0,0) ;
        printf("Hand: ") ;
        for(int i=0;i<=13;i++)printf("%c",s[i]);
        printf(" Deck: ") ;
        for(int i=15;i<=28;i++)printf("%c",s[i]);
        printf(" Best hand: %s\n",ANS[ans]) ;
    }
}
