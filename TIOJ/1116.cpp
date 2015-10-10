#include<bits/stdc++.h>
using namespace std;

char s[10] ;
int a[10] ;
main()
{
    while(scanf("%s",s)!=EOF)
    {
        for(int i=0;i<4;i++)
        {
            if(s[i]=='a') a[i]=1 ;
            if(s[i]=='b') a[i]=2 ;
            if(s[i]=='c') a[i]=3 ;
        }
        for(int i=0;i<4;i++)
        {
            bool ok=0 ;
            if(!(a[i]&1)) printf("X") , ok=1 ;
            else
            {
                if(a[(i+3)%4]&2) printf("A") , ok=1 ;
                if(a[(i+1)%4]&2) printf("B") , ok=1 ;
                if(a[(i+2)%4]&2) printf("C") , ok=1 ;
            }
            if(!ok) printf("Y") ;
            printf("%s",i==3?"\n":", ") ;
        }
    }
}
