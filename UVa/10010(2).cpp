#include<stdio.h>
char G[60][60],s[100] ;
int n,m ;

bool check(int i,int j)
{
    int x;
    if(s[1]=='\0') return 1;
    for (x=1; i-x>=0 && s[x]==G[i-x][j];) {x++; if (s[x]=='\0') return 1;}
    for (x=1; i+x<m  && s[x]==G[i+x][j];) {x++; if (s[x]=='\0') return 1;}
    for (x=1; j-x>=0 && s[x]==G[i][j-x];) {x++; if (s[x]=='\0') return 1;}
    for (x=1; j+x<n  && s[x]==G[i][j+x];) {x++; if (s[x]=='\0') return 1;}
    for (x=1; i-x>=0 && j-x>=0 && s[x]==G[i-x][j-x];) {x++; if (s[x]=='\0') return 1;}
    for (x=1; i+x<m  && j-x>=0 && s[x]==G[i+x][j-x];) {x++; if (s[x]=='\0') return 1;}
    for (x=1; i-x>=0 && j+x<n  && s[x]==G[i-x][j+x];) {x++; if (s[x]=='\0') return 1;}
    for (x=1; i+x<m  && j+x<n  && s[x]==G[i+x][j+x];) {x++; if (s[x]=='\0') return 1;}
    return 0;
}

void upper_to_lower (char a[])
{
    for (int i=0; a[i]; i++)
        if (a[i]>='A' && a[i]<='Z')
            a[i] += 32;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%s",G[i]);
            upper_to_lower(G[i]);
        }

        int k;
        scanf("%d",&k) ;
        while(k--)
        {
            scanf("%s",s);
            upper_to_lower(s);

            int i,j,ok=0;
            for (i=0; i<n && !ok; i++) for (j=0; j<m && !ok; j++)
                if (G[i][j] == s[0] && check(i,j))
                {
                    printf("%d %d\n",i+1,j+1);
                    ok = 1;
                }
        }
        if(T) printf("\n") ;
    }
    return 0;
}
