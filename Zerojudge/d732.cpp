#include<stdio.h>
int p,q,j,m,c,a[100002];
void f(int r,int s)
    {
    if(a[(r+s)/2]>c)
        {
        p=r;
        q=(r+s)/2; 
        } 
    else if(a[(r+s)/2]<c)
        {
        p=(r+s)/2;
        q=s; 
        } 
    else if(a[(r+s)/2]==c)
        {
        m=1;
        p=(r+s)/2;
        q=(r+s)/2; 
        }
    } 
main()
{
 int n,k,i;
 while(scanf("%d %d",&n,&k)==2)
    {
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=k;i++)
        {
        scanf("%d",&c);
        if (c<a[1]) printf("0\n");
        else if (c>a[n]) printf("0\n"); 
        else
            {
            m=0; 
            p=1;
            q=n;
            while((m!=1)&&(p!=q)&&(p!=q-1)) f(p,q);
            if ((m==0)&&(a[p]!=c)&&(a[p+1]!=c)) printf("0\n");
            else if (a[p]==c) printf("%d\n",p) ; 
            else if (a[p+1]==c) printf("%d\n",p+1); 
            else printf("%d\n",p);
            m=0; 
            }
        } 
    } 
}
