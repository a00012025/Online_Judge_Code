#include <cstdlib>
#include <iostream>
#include <cmath>
#include<stdio.h>
#define MAX 10000.0

using namespace std;

int main()
{
    int w, n, i, id, x1, x2, y1, y2, s;
    double best, cp;
    scanf("%d",&w) ;
    while (w--)
    {
        scanf("%d",&n) ;
        double ans=10000.0 ;
        for (i=1, id=0; i<=n; i++)
        {
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&s);
            x1= (x1>x2) ? (x1-x2) : (x2-x1) ;
            y1= (y1>y2) ? (y1-y2) : (y2-y1) ;
            cp= sqrt(x1*x1+y1*y1)*s/x1;
            if (cp<ans)
            {
                ans=cp;
                id=i;
            }
        }
        printf("%d\n",id) ;
    }
//    system("PAUSE");
    return 0;
}
