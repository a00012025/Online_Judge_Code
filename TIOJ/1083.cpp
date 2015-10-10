#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=200000 ;

char s[2][maxn] ;
int len[50] ;
char tmp[50] ;
main()
{
    s[1][0]='1' ; s[1][1]=0 ; len[1]=1 ;
    for(int i=2;i<43;i++)
    {
        int cnt=0 ;
        for(int j=0;j<len[i-1];)
        {
            int j2=j ;
            while(j2<len[i-1] && s[(i+1)%2][j2]==s[(i+1)%2][j])
                j2++ ;
            int num=j2-j,cnt2=0 ;
            while(num) tmp[cnt2++]=num%10 , num/=10 ;
            for(int k=cnt2-1;k>=0;k--) s[i%2][cnt++]='0'+tmp[k] ;
            s[i%2][cnt++]=s[(i+1)%2][j] ;
            j=j2 ;
        }
        len[i]=cnt ;
    }

    int n ;
    while(scanf("%d",&n)==1 && n)
    {
        printf("%d %.6f\n",len[n],((DB)len[n-1])/((DB)len[n])) ;
    }
}
