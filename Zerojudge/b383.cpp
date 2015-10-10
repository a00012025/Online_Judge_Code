#include<bits/stdc++.h>
using namespace std;
const int maxn=1600000+100 ;

char s[maxn],t[maxn] ;

int Z[maxn] ;
bool is_pal(int l,int r)
{
    l=2*l+1 ; r=2*r+1 ;
    return Z[(l+r)/2] + ((l+r)/2) >= r ;
}

int ext_len(int l,int r)
{
    int i=0 ;
    while(l-i>=0 && t[r+i]!='\0' && t[l-i]==t[r+i]) i++ ;
    return i-1 ;
}

void pre_cal()
{
    int len=strlen(s) ;
    for(int i=0;i<=2*len;i++) t[i]= (i%2==0)?'@':s[i/2] ;
    t[2*len+1]='\0' ; len=2*len+1 ;

    Z[0]=0 ;
    int L=0 , R=0 ;
    for(int i=1;i<len;i++)
    {
        if(i>R) Z[i]=ext_len(i,i) , L=i-Z[i] , R=i+Z[i] ;
        else
        {
            int i2=L+R-i ;
            if(i2-Z[i2] > L) Z[i]=Z[i2] ;
            else if(i2-Z[i2] == L)
            {
                Z[i]=R-i+ext_len(2*i-R,R) ;
                if(i+Z[i] > R) R=i+Z[i] , L=i-Z[i] ;
            }
            else Z[i]=R-i ;
        }
    }
}

bool is_two[2][maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    for(int tt=1;tt<=T;tt++)
    {
        memset(is_two,0,sizeof(is_two)) ;
        scanf("%s",s) ; if(tt==5) printf("%d\n",strlen(s)) ;
        int len=strlen(s) ;
        for(int i=2*len-1;i>=0;i--) s[i]=s[i/2] ;
        s[2*len]='\0' ; len*=2 ;
        pre_cal() ;

        int now=-1 ;
        for(int i=len-2;i>=0;i-=2)
        {
            if(now!=-1 && is_pal(i,now-1)) is_two[0][i]=1 ;
            if(is_pal(i,len-1)) now=i ;
        }

        now=-1 ;
        for(int i=1;i<len;i+=2)
        {
            if(now!=-1 && is_pal(now+1,i)) is_two[1][i]=1 ;
            if(is_pal(0,i)) now=i ;
        }

        bool ok=0 ;
        for(int i=1;i<=len-3;i+=2)
        {
            if(is_two[0][i+1] && is_pal(0,i))
                { printf("Yes\n") ; ok=1 ; break ; }
            if(is_two[1][i] && is_pal(i+1,len-1))
                { printf("Yes\n") ; ok=1 ; break ; }
        }
        if(!ok) printf("No\n") ;
    }
}
