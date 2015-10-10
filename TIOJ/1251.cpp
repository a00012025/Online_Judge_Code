#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int las[maxn],nex[maxn],ans[maxn] ;
int head,sz ;

void erase(int x)
{
    sz-- ;
    if(x==head) head=nex[x] ;
    else las[nex[x]]=las[x] , nex[las[x]]=nex[x] ;
}

main()
{
    head=1 ; sz=1 ;
    for(int i=1;i<maxn-2;i+=2)
    {
        nex[i]=i+2 , sz++ ;
        las[i+2]=i ;
    }
    for(int i=2;i<=sz;i++)
    {
        int num=head ;
        for(int j=1;j<i;j++) num=nex[num] ;
        if(num>sz) break ;
        for(int j=head;j;)
        {
            for(int r=1;r<num && j ;r++) j=nex[j] ;
            if(!j) break ;
            erase(j) ; j=nex[j] ;
        }
    }
//    for(int i=head;i<=193;i=nex[i]) printf("%d,",i) ;
}
