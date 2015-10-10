#include<stdio.h>
#include<stack>
using namespace std;
main()
{
 int N,n,A,m,i,j,k,No,max1,XD;
 stack<int> s;
 while(scanf("%d",&n)==1)
{
 if(n==0) break ;
 while(1)
 {
     XD=0 ;
     while(s.empty()==0) s.pop();
     No=0;
     max1=0;
     s.push(0);
     for(i=1;i<=n;i++)
        {
        scanf("%d",&A);
        if(i==1 && A==0) {XD=1 ; break ;}
        if(No==1)continue;
        if(s.top()<A)
            {
            for(k=max1+1;k<=A-1;k++) s.push(k);
            max1=A;
            }
        else if(s.top()==A) s.pop();
        else No=1;
        }
     if(XD==1) break ;
     if(No==0)printf("Yes\n");
     else printf("No\n");
 }
 printf("\n") ;
}

}
