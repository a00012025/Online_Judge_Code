#include<cstdio>

#include<cstring>

#include<cstdlib>

#define LL long long// 因为这道题有可能会很大的数，用longlong

using namespace std;

LL maxx ( LL x, LL y){ return x > y ? x : y; } // 求两个数的最大值

LL n, p, a[1100000];// a是一开始的那一段数

LL b[1100000],c[1100000]; // b是特征值，c是分数

int main (){

    int i, j;

    scanf ( "%lld%lld", &n,&p );

    for ( i = 1; i <= n; i ++ )

     scanf( "%lld", &a[i] );

    b[1] = a[1];

    LL now = maxx ( a[1], 0 ); // 看看第一个数是正数还是负数，如果是负数，则忽略这一个数，免得使统计的数变小

    for ( i = 2; i <= n; i ++ ){

        b[i]= b[i - 1]; // 先等于前面的特征值

        now+= a[i]; // 把这个累加值加上当前小孩子手上的数字

        b[i] = maxx ( now, b[i] ); // 看看是前面特征值的大还是累加值大

        if( now < 0 ) now = 0; // 如果累加值比0小，那又把它变成0，重新累加

    }

    c[1] = b[1];

    c[2] = c[1] + b[1]; // c1和c2是固定的，可以现在前面算

    int ok = 0; // ok就是看是最后的值更大些还是第一个更大些

    LL tmp = c[1];

    for ( i = 2; i < n; i ++ ){

        tmp += maxx ( b[i], 0ll );

        if ( tmp >= 0 ){ // 如果这个累加值比0大，那么就证明会累加越来越大

            ok = 1;

            break;

        }

    }

    for ( i = 3; i <= n; i ++ )

     c[i]= ( c[i - 1] + maxx ( b[i - 1], 0ll ) ) % p; // 求每个人分数的最大值

    if ( ok ) // 如果最后的大些

     printf ( "%d\n", int ( c[n] ) ); // 输出最后的

    else // 如果第一个大些

     printf ( "%d\n", int ( c[1] % p ) );// 输出第一个

    return 0;

}
