#include<stdio.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;
int heap[10000] ;
main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;
    int n;
    stack<int> s ;
    queue<int> q ;
    while(scanf("%d",&n)!=EOF)
    {
        memset(heap,0,sizeof(heap)) ; int num=0 ;
        while(!s.empty()) s.pop() ;
        while(!q.empty()) q.pop() ;
        int ans1=1,ans2=1,ans3=1 ;
        for(int i=1;i<=n;i++)
        {
            int type,a ;
            scanf("%d %d",&type,&a);
            if(type==1)
            {
                s.push(a) ;
                q.push(a) ;
                heap[num+1]=a ;
                push_heap(heap+1,heap+num+2) ;
                num++ ;
            }
            else if(type==2)
            {
                if(s.empty()) {ans1=ans2=ans3=0 ; continue ;}
                if(a!=s.top()) ans1=0 ;
                if(a!=q.front()) ans2=0 ;
                if(a!=heap[1]) ans3=0 ;
                s.pop() ; q.pop() ;
                pop_heap(heap+1,heap+num+1) ;
                num-- ;
            }
        }
        int ans=ans1+ans2+ans3 ;
        if(!ans) printf("impossible\n");
        else if(ans>=2) printf("not sure\n") ;
        else
        {
            if(ans1) printf("stack\n") ;
            if(ans2) printf("queue\n") ;
            if(ans3) printf("priority queue\n") ;
        }
    }
}
