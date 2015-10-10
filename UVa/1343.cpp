#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std ;
int now[24],maxd ;
int center[]={6,7,8,11,12,15,16,17} ;
int go[8][8]={{0,2,6,11,15,20,22},{1,3,8,12,17,21,23},{10,9,8,7,6,5,4},{19,18,17,16,15,14,13},
             {23,21,17,12,8,3,1},{22,20,15,11,6,2,0},{13,14,15,16,17,18,19},{4,5,6,7,8,9,10}} ;
char ch[]={'A','B','C','D','E','F','G','H'},now_ch[50000],ans[50000] ;
int rev[]={5,4,7,6,1,0,3,2} ;

int estimate()
{
    int cnt[4]={0} ;
    for(int i=0;i<8;i++) cnt[now[center[i]]]++ ;
    return 8-max(max(cnt[1],cnt[2]),cnt[3]) ;
}

void Move(int k)
{
    int tem=now[go[k][0]] ;
    for(int i=0;i<6;i++) now[go[k][i]]=now[go[k][i+1]] ;
    now[go[k][6]]=tem ;
}

bool iddfs(int num)
{
    if(num==maxd)
    {
        if(estimate()==0)
        {
            for(int i=1;i<=maxd;i++) printf("%c",now_ch[i]) ;
            printf("\n") ;
            return 1;
        }
        else return 0;
    }
    if(estimate()>maxd-num) return 0 ;
    for(int i=0;i<8;i++)
    {
        Move(i) ;
        now_ch[num+1]=ch[i] ;
        if(iddfs(num+1)) return 1;
        Move(rev[i]) ;
    }
    return 0 ;
}

main()
{
    while(scanf("%d",&now[0])==1 && now[0])
    {
        for(int i=1;i<24;i++) scanf("%d",&now[i]) ;
        for(int i=0;i<24;i++) if(!now[i]) break ;
        if(estimate()==0) printf("No moves needed\n") ;
        else
        {
            maxd=1 ;
            for(;;maxd++) if(iddfs(0)) break ;
        }
        printf("%d\n",now[6]) ;
    }
}
