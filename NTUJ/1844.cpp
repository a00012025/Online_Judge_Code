#include<bits/stdc++.h>
using namespace std;
const int maxn=100 ;

int a[maxn] ;
main()
{
    int m ;
    while(scanf("%d",&m)!=EOF)
    {
        int cnt=0 ;
        memset(a,0,sizeof(a)) ;
        for(int x=m;x;x/=27,cnt++) a[cnt]=x%27 ;
        string s,t ;
        for(int i=0;i<cnt+3;i++)
        {
            a[i+1]+=a[i]/27 , a[i]%=27 ;
            if(a[i]==26) s.push_back('b') , a[i]=1 , a[i+1]++ ;
            else s.push_back('a') , a[i]++ ;
            t.push_back((char)a[i]+'a'-1) ;
        }
        reverse(s.begin(),s.end()) ;
        reverse(t.begin(),t.end()) ;
        cout << s << " " << t << endl ;
    }
}
