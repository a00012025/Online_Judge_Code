#include<stdio.h>
#include<stdlib.h>
bool now[16] ;
int maxd,ans[100],goal;
int jump[6][16][16]={

    {{0},{2,4,7,11},{4,7,11},{5,8,12},{7,11},{8,12},{9,13},{0},{0},{0},{0},{0},{0},{0},{0},{0}},
    {{0},{3,6,10,15},{5,9,14},{6,10,15},{8,13},{9,14},{10,15},{0},{0},{0},{0},{0},{0},{0},{0},{0}},
    {{0},{0},{0},{0},{2,1},{0},{0},{4,2,1},{5,3},{0},{0},{7,4,2,1},{8,5,3},{9,6},{0},{0}},
    {{0},{0},{0},{0},{0},{0},{3,1},{0},{0},{5,3},{6,3,1},{0},{0},{8,4},{9,5,2},{10,6,3,1}},
    {{0},{0},{0},{0},{5,6},{0},{0},{8,9,10},{9,10},{0},{0},{12,13,14,15},{13,14,15},{14,15},{0},{0}},
    {{0},{0},{0},{0},{0},{0},{5,4},{0},{0},{8,7},{9,8,7},{0},{0},{12,11},{13,12,11},{14,13,12,11}}
};

bool iddfs(int d,int num)
{
    if(d==maxd)
    {
        if(num==1 && now[goal])
        {
            printf("%d\n",d) ;
            for(int i=1;i<=2*d;i++) printf("%d%c",ans[i],i==2*d?'\n':' ') ;
            return 1;
        }
        else return 0;
    }
    if(3*(maxd-d)<num) return 0;
    for(int i=1;i<=15;i++) for(int j=1;j<=15;j++) if(i!=j && now[i] && !now[j])
    {
        for(int type=0;type<6;type++)
        {
            if(jump[type][i][0]==0) continue ;

            int tar=0 ;
            for(;tar<=3 && jump[type][i][tar]!=j;tar++) ;
            if(tar==4 || tar==0) continue ;

            bool ok=1 ;
            for(int z=0;z<tar;z++) if(!now[jump[type][i][z]]) ok=0 ;
            if(!ok) continue ;

            for(int z=0;z<tar;z++) now[jump[type][i][z]]=0 ;
            now[j]=1 ; now[i]=0 ;

            ans[2*d+1]=i ; ans[2*d+2]=j ; //printf("depth:%d , %d->%d\n",d,i,j);
            if(iddfs(d+1,num-tar)) return 1 ;

            for(int z=0;z<tar;z++) now[jump[type][i][z]]=1 ;
            now[j]=0 ; now[i]=1 ;
        }
    }
    return 0;
}

main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        for(int i=1;i<=15;i++) now[i]=1 ;
        scanf("%d",&goal) ; now[goal]=0 ;
        for(maxd=0;maxd<=13;maxd++) if(iddfs(0,14)) break ;
    }
}
