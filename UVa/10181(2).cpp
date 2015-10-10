#include<bits/stdc++.h>
using namespace std;

int a0[35][4]={ {0,0,0,4},{0,0,1,3},{0,0,2,2},{0,0,3,1},{0,0,4,0},
{0,1,0,3},{0,1,1,2},{0,1,2,1},{0,1,3,0},{0,2,0,2},{0,2,1,1},{0,2,2,0},
{0,3,0,1},{0,3,1,0},{0,4,0,0},{1,0,0,3},{1,0,1,2},{1,0,2,1},{1,0,3,0},
{1,1,0,2},{1,1,1,1},{1,1,2,0},{1,2,0,1},{1,2,1,0},{1,3,0,0},{2,0,0,2},
{2,0,1,1},{2,0,2,0},{2,1,0,1},{2,1,1,0},{2,2,0,0},{3,0,0,1},{3,0,1,0},
{3,1,0,0},{4,0,0,0} } ;

int b0[20][4]={ {0,0,0,3},{0,0,1,2},{0,0,2,1},{0,0,3,0},{0,1,0,2},
{0,1,1,1},{0,1,2,0},{0,2,0,1},{0,2,1,0},{0,3,0,0},{1,0,0,2},{1,0,1,1},
{1,0,2,0},{1,1,0,1},{1,1,1,0},{1,2,0,0},{2,0,0,1},{2,0,1,0},{2,1,0,0},
{3,0,0,0} } ;

struct P
{
    int x,y,z ;
    bool operator < (const P &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x ;
        if(y!=rhs.y) return y<rhs.y ;
        return z<rhs.z ;
    }
};

struct state
{
    int a[16] ;
    int zero ;
    bool scan()
    {
        if(scanf("%d",&a[0])==EOF) return 0 ;
        zero=0 ;
        for(int i=1;i<16;i++)
        {
            scanf("%d",&a[i]) ;
            if(!a[i]) zero=i ;
        }
        return 1 ;
    }
};

int __d[1500000] ;
struct WalkingDistance
{
    int cod[5] ;
    map<P,int> mpa,mpb ;
    int encode()
    {
        int ret=0 ;
        for(int i=0;i<4;i++) ret=ret*35+cod[i] ;
        return ret ;
    }

    void decode(int x)
    {
        for(int i=0;i<4;i++) cod[3-i]=x%35 , x/=35 ;
    }

    int num[4][4] ;
    void cal()
    {
        for(int i=0;i<35;i++) mpa[(P){a0[i][0],a0[i][1],a0[i][2]}]=i ;
        for(int i=0;i<20;i++) mpb[(P){b0[i][0],b0[i][1],b0[i][2]}]=i ;

        queue<int> q ;
        memset(__d,-1,sizeof(__d)) ;
        int *d = __d ;
        cod[0]=mpa[(P){4,0,0}] , cod[1]=mpa[(P){0,4,0}] ,
        cod[2]=mpa[(P){0,0,4}] , cod[3]=mpb[(P){0,0,0}] ;
        int start=encode() ; d[start]=0 ; q.push(start) ;
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ;
            decode(u) ;
            int num2[4]={0} ;
            for(int i=0;i<4;i++) for(int j=0;j<4;j++)
                num[i][j]= i==3 ? b0[cod[i]][j] : a0[cod[i]][j] ,
                num2[j]+=num[i][j] ;
            int emp ;
            for(emp=0;emp<4 && num2[emp]==4;emp++) ;

            for(int i=-1;i<=1;i+=2) if(emp+i>=0 && emp+i<4)
                for(int j=0;j<4;j++) if(num[j][emp+i])
            {
                num[j][emp+i]-- ;
                num[j][emp]++ ;
                for(int z=0;z<4;z++) cod[z]= z==3 ?
                    mpb[(P){num[z][0],num[z][1],num[z][2]}] :
                    mpa[(P){num[z][0],num[z][1],num[z][2]}] ;
                int newu=encode() ;
                if(d[newu]==-1) d[newu]=d[u]+1 , q.push(newu) ;
                num[j][emp+i]++ ;
                num[j][emp]-- ;
            }
        }
    }

    int get_wd(const state &s)
    {
        int ret=0 , num[4][4] ;
        memset(num,0,sizeof(num)) ;
        for(int i=0;i<16;i++) if(s.a[i])
            num[(s.a[i]-1)/4][i/4]++ ;
        for(int z=0;z<4;z++) cod[z]= z==3 ?
            mpb[(P){num[z][0],num[z][1],num[z][2]}] :
            mpa[(P){num[z][0],num[z][1],num[z][2]}] ;
        ret+=__d[encode()] ;

        memset(num,0,sizeof(num)) ;
        for(int i=0;i<16;i++) if(s.a[i])
            num[(s.a[i]-1)%4][i%4]++ ;
        for(int z=0;z<4;z++) cod[z]= z==3 ?
            mpb[(P){num[z][0],num[z][1],num[z][2]}] :
            mpa[(P){num[z][0],num[z][1],num[z][2]}] ;
        ret+=__d[encode()] ;

        return ret ;
    }

    void set_num(const state &s,int type)
    {
        memset(num,0,sizeof(num)) ;
        for(int i=0;i<16;i++) if(s.a[i])
        {
            if(type==1) num[(s.a[i]-1)/4][i/4]++ ;
            else num[(s.a[i]-1)%4][i%4]++ ;
        }
    }

    int get_wd()
    {
        for(int z=0;z<4;z++) cod[z]= z==3 ?
            mpb[(P){num[z][0],num[z][1],num[z][2]}] :
            mpa[(P){num[z][0],num[z][1],num[z][2]}] ;
        return __d[encode()] ;
    }
}wd1,wd2;

bool check(const state &s)
{
    int x=0,pos=0 ;
    for(int i=0;i<16;i++)
    {
        if(s.a[i]) for(int j=i+1;j<16;j++)
        {
            if(s.a[j] && s.a[j]<s.a[i])
                x++ ;
        }
        else pos=i ;
    }
    x+=(pos/4) ;
    return x%2 ;
}

state st ;
int dx[]={1,0,0,-1} , dy[]={0,1,-1,0} ;
int maxdep ;
char ch[]={'D','R','L','U'} , path[100] ;
int iddfs(int dep,int val1,int val2,int pre)
{
    if(!(val1+val2)) return 1 ;
    if(dep + val1 + val2 > maxdep) return 0 ;

    int z=st.zero , x=z/4 , y=z%4 ;
    for(int i=0;i<4;i++) if(i+pre!=3)
    {
        int nx=x+dx[i] , ny=y+dy[i] ;
        if(nx<0||nx>3||ny<0||ny>3) continue ;
        int nz=4*nx+ny ;

        int newval1=val1,newval2=val2 ;
        if(x!=nx)
            wd1.num[(st.a[nz]-1)/4][nx]-- , wd1.num[(st.a[nz]-1)/4][x]++ ,
            newval1 = wd1.get_wd() ;
        else
            wd2.num[(st.a[nz]-1)%4][ny]-- , wd2.num[(st.a[nz]-1)%4][y]++ ,
            newval2 = wd2.get_wd() ;
        swap(st.a[z],st.a[nz]) ; st.zero=nz ;

        path[dep]=ch[i] ;
        if(iddfs(dep+1,newval1,newval2,i)) return 1 ;

        swap(st.a[z],st.a[nz]) ; st.zero=z ;
        if(x!=nx)
            wd1.num[(st.a[nz]-1)/4][nx]++ , wd1.num[(st.a[nz]-1)/4][x]-- ;
        else
            wd2.num[(st.a[nz]-1)%4][ny]++ , wd2.num[(st.a[nz]-1)%4][y]-- ;
    }
    return 0 ;
}

main()
{
    wd1.cal() ; wd2.cal() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
//        int start=clock() ;
        st.scan() ;
        if(!check(st))
            { printf("This puzzle is not solvable.\n") ; continue ; }

        wd1.set_num(st,1) ;
        wd2.set_num(st,2) ;
        int val1=wd1.get_wd() , val2=wd2.get_wd() ;
        for(int i=val1+val2;;i++)
        {
//            printf("now depth = %d\n",i) ;
            maxdep=i ;
            if(iddfs(0,val1,val2,-1))
            {
                for(int i=0;i<maxdep;i++) printf("%c",path[i]) ;
//                printf("%d",i) ;
                printf("\n") ;
                break ;
            }
        }
//        int end=clock() ;
//        printf("total use %.4f s \n",((double)(end-start))/CLOCKS_PER_SEC) ;
    }
}
