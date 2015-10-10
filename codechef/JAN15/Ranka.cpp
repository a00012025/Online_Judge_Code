#include<bits/stdc++.h>
using namespace std;
struct P{int x,y ;};
bool now[10][10] ;
int last[10],a[3001][10] ;

int RAND(int x,int y)
{
    int t=rand()%(y-x+1) ; if(t<0) t+=y-x+1 ;
    return x+t ;
}

set<int> st ;
main()
{
    srand(time(NULL)) ;
    for(int i=1;i<=9;i++) last[i]=1 ;
    for(int i=1;i<=2000;i++)
    {
        if(i%2) while(1)
        {
            for(int j=1;j<=9;j++) a[i][j]= ( j==1 ? RAND(last[1],8) :
                    RAND(max(last[j],a[i][j-1]-1),min(8,a[i][j-1]+1)) ) ;
            int x=0 ;
            for(int j=1;j<=9;j++) x=x*10+a[i][j] ;
            if(st.count(x)) continue ;
            for(int j=1;j<=9;j++) last[j]=a[i][j]+1 ;
            st.insert(x) ; break ;
        }
        else while(1)
        {
            for(int j=1;j<=9;j++) a[i][j]= ( j==1 ? RAND(2,last[1]) :
                    RAND(max(2,a[i][j-1]-1),min(last[j],a[i][j-1]+1)) ) ;
            int x=0 ;
            for(int j=1;j<=9;j++) x=x*10+a[i][j] ;
            if(st.count(x)) continue ;
            for(int j=1;j<=9;j++) last[j]=a[i][j]-1 ;
            st.insert(x) ; break ;
        }
    }

    int n ; scanf("%d",&n) ;
    memset(now,0,sizeof(now)) ;
    for(int i=1;i<=2000;i++)
    {
        vector<P> tmp ;
        if(i%2)
        {
            for(int j=1;j<=9;j++) for(int k=1;k<=a[i][j];k++)
                if(!now[j][k]) tmp.push_back((P){j,k}) ;
        }
        else
        {
            for(int j=1;j<=9;j++) for(int k=a[i][j];k<=9;k++)
                if(!now[j][k]) tmp.push_back((P){j,k}) ;
        }
        random_shuffle(tmp.begin(),tmp.end()) ;
        for(int j=0;j<tmp.size();j++)
        {
            if(j)
            {
                printf("0 0\n") ;
                if(!(--n)) return 0 ;
            }
            printf("%d %d\n",tmp[j].x,tmp[j].y) ;
            if(!(--n)) return 0 ;
        }
        for(int j=1;j<=9;j++)
        {
            printf("%d %d\n",j,i%2 ? a[i][j]+1 : a[i][j]-1) ;
            if(!(--n)) return 0 ;
            printf("0 0\n") ;
            if(!(--n)) return 0 ;
        }
        memset(now,0,sizeof(now)) ;
        for(int j=1;j<=9;j++)
        {
            if(i%2) now[j][a[i][j]+1]=1 ;
            else now[j][a[i][j]-1]=1 ;
        }
    }
}
