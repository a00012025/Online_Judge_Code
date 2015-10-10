#include<stdio.h>
int li[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}} ;
int now[9] ;
int have_line(int x)
{
    for(int i=0;i<8;i++)
    {
        int ok=1 ;
        for(int j=0;j<3;j++) if(now[li[i][j]]!=x)
            {ok=0 ; break ;}
        if(ok) return 1 ;
    }
    return 0 ;
}
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;n;n--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(x<0||x>2||y<0||y>2||now[3*x+y]) continue ;
        now[3*x+y]=i%2+1 ;
        if(have_line(1)||have_line(2))
        {
            printf("%s wins.\n",i%2 ? "White" : "Black") ;
            return 0 ;
        }
        i++ ;
    }
    printf("There is a draw.\n") ;
}
