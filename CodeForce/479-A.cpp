#include<bits/stdc++.h>
using namespace std;
main()
{
    int a,b,c ; scanf("%d%d%d",&a,&b,&c) ;
    printf("%d\n",max(max((a+b)*c,(b+c)*a),max(a*b*c,a+b+c))) ;
}
