#include<stdio.h>
char c[10000],s[10000000] ;
int ST[10000000],a[1000][1000],now,cnt ;

int val(int x,int y,int z,int w)
{
    if(x!=y || x!=z || x!=w || y!=z || y!=w || z!=w) return -1 ;
    else if(x==-1) return -1 ;
    else return x ;
}

char chr(int n)
{
    if(n==-1) return 'D' ;
    else return n+'0' ;
}

bool ok(char x)
{
    if(x=='1' || x=='0' || x=='D') return 1;
    else return 0 ;
}

void build_tree(int x1,int y1,int x2,int y2,int id)
{
    if(x2<x1 || y2<y1) return ;
    if(x1==x2 && y1==y2) {ST[id]=a[x1][y1] ; return ;}
    int midx=(x1+x2)/2 , midy=(y1+y2)/2 ;
    if(x1==x2)
    {
        build_tree(x1,y1,x1,midy,4*id) ;
        build_tree(x1,midy+1,x1,y2,4*id+1) ;
        ST[id]=val(ST[4*id+1],ST[4*id+1],ST[4*id],ST[4*id]) ;
    }
    else if(y1==y2)
    {
        build_tree(x1,y1,midx,y1,4*id) ;
        build_tree(midx+1,y1,x2,y1,4*id+1) ;
        ST[id]=val(ST[4*id+1],ST[4*id+1],ST[4*id],ST[4*id]) ;
    }
    else
    {
        build_tree(x1,y1,midx,midy,4*id) ;
        build_tree(x1,midy+1,midx,y2,4*id+1) ;
        build_tree(midx+1,y1,x2,midy,4*id+2) ;
        build_tree(midx+1,midy+1,x2,y2,4*id+3) ;
        ST[id]=val(ST[4*id],ST[4*id+1],ST[4*id+2],ST[4*id+3]) ;
    }
        //printf("ST[%d]=%d\n",id,ST[id]) ;
}

void print_ans(int x1,int y1,int x2,int y2,int id)
{
    if(x2<x1 || y2<y1) return ;
    if(cnt && cnt%50==0) printf("\n") ;
    printf("%c",chr(ST[id])) ; cnt++ ;
    if(ST[id]!=-1) return ;
    int midx=(x1+x2)/2 , midy=(y1+y2)/2 ;
    if(x1==x2)
    {
        print_ans(x1,y1,x1,midy,4*id) ;
        print_ans(x1,midy+1,x1,y2,4*id+1) ;
    }
    else if(y1==y2)
    {
        print_ans(x1,y1,midx,y1,4*id) ;
        print_ans(midx+1,y1,x2,y1,4*id+1) ;
    }
    else
    {
        print_ans(x1,y1,midx,midy,4*id) ;
        print_ans(x1,midy+1,midx,y2,4*id+1) ;
        print_ans(midx+1,y1,x2,midy,4*id+2) ;
        print_ans(midx+1,midy+1,x2,y2,4*id+3) ;
    }
}

void read_tree(int x1,int y1,int x2,int y2)
{
    if(x2<x1 || y2<y1) return ;
    char c ;
    scanf("%c",&c) ; while(!ok(c)) scanf("%c",&c) ;
    if(c!='D')
    {
        for(int i=x1;i<=x2;i++) for(int j=y1;j<=y2;j++)
            a[i][j]=c-'0' ;
    }
    else
    {
        int midx=(x1+x2)/2 , midy=(y1+y2)/2 ;
        read_tree(x1,y1,midx,midy) ;
        read_tree(x1,midy+1,midx,y2) ;
        read_tree(midx+1,y1,x2,midy) ;
        read_tree(midx+1,midy+1,x2,y2) ;
    }
}

main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;
    bool fir=1 ;
    while(scanf("%s",c)!=EOF && c[0]!='#')
    {
        int n,m ; cnt=0 ;
        scanf("%d%d",&n,&m) ;
        if(c[0]=='B')
        {
            for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
            {
                char c; scanf("%c",&c) ;
                while(!ok(c)) scanf("%c",&c) ;
                s[cnt++]=c ;
            }
            cnt=0 ;
            for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
                a[i][j]=s[cnt++]-'0' ;
            build_tree(1,1,n,m,1) ;
            //if(fir) fir=0 ;
            //else printf("\n") ;
            cnt=0 ;
            printf("D%4d%4d\n",n,m) ;
            print_ans(1,1,n,m,1) ;
            printf("\n") ;
        }
        else
        {
            read_tree(1,1,n,m) ;
            //if(fir) fir=0 ;
            //else printf("\n") ;
            printf("B%4d%4d\n",n,m) ;
            cnt=0 ;
            for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
                { if(cnt && cnt%50==0) printf("\n") ; printf("%d",a[i][j]) ; cnt++ ;}
            printf("\n") ;
        }
    }
}
