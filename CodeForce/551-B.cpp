#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

char a[maxn],b[maxn],c[maxn] ;
int ca[26],cb[26],cc[26] ;
main()
{
    int ans1=-1 , ans2=-1 ;
    scanf("%s%s%s",a,b,c) ;
    for(int i=0;a[i];i++) ca[a[i]-'a']++ ;
    for(int i=0;b[i];i++) cb[b[i]-'a']++ ;
    for(int i=0;c[i];i++) cc[c[i]-'a']++ ;
    for(int i=0;i<maxn;i++)
    {
        int ny=maxn ;
        for(int j=0;j<26;j++) if(cc[j])
            ny=min(ny,ca[j]/cc[j]) ;
        if(i+ny>ans1+ans2) ans1=i , ans2=ny ;
        bool ok=1 ;
        for(int j=0;j<26;j++)
        {
            ca[j]-=cb[j] ;
            if(ca[j]<0){ok=0 ; break ;}
        }
        if(!ok) break ;
    }
    memset(ca,0,sizeof(ca)) ;
    for(int i=0;a[i];i++) ca[a[i]-'a']++ ;
    for(int i=0;i<26;i++) ca[i]-=ans1*cb[i]+ans2*cc[i] ;
    for(int i=0;i<ans1;i++) printf("%s",b) ;
    for(int i=0;i<ans2;i++) printf("%s",c) ;
    for(int i=0;i<26;i++) while(ca[i]--) printf("%c",i+'a') ;
}
