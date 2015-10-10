#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<string>
#include<map>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n , m;
int s[ 100005 ];
int st[ 800005 ];
int a , b ;
bool rev ;

void buildTree( int id , int l , int r ) {
	if ( l == r ) { st[ id ] = s[ l ] = 1 ; return ; }
	int mid = ( l + r ) / 2 ;
	buildTree( id * 2 , l , mid );
	buildTree( id * 2 + 1 , mid + 1 , r );
	st[ id ] = st[ id * 2 ] + st[ id * 2 + 1 ];
}

void modify( int id , int l , int r , int pos , int val ) {
	if ( l == r ) { st[ id ] += val ; s[ l ] += val ; return ; }
	int mid = ( l + r ) / 2 ;
	if ( pos <= mid ) modify( id * 2 , l , mid , pos , val );
	else modify( id * 2 + 1 , mid + 1 , r , pos , val );
	st[ id ] = st[ id * 2 ] + st[ id * 2 + 1 ] ;
}

int query( int id , int l , int r , int L , int R ) {
	if ( L <= l && r <= R ) return st[ id ] ;
	if ( l > R || r < L ) return 0 ;
	int mid = ( l + r ) / 2 ;
	return query( id * 2 , l , mid , L , R ) + query( id * 2 + 1 , mid + 1 , r , L , R ) ;
}

void init() {
	scanf( "%d%d" , &n , &m );
	a = 1 , b = n , rev = false ;
	buildTree( 1 , 1 , n );
}

void process() {
	int type , l , r ;
	for ( int i = 0 ; i < m ; i ++ ) {
		scanf( "%d" , &type );
		if ( type == 1 ) {
			scanf( "%d" , &l );
			if ( rev ) {
				if ( ( b - a + 1 - l ) > l ) {
					for ( int j = b - l + 1 ; j <= b ; j ++ ) {
						modify( 1 , 1 , n , ( b - l ) * 2 + 1 - j , s[ j ] );
					} b = b - l ;
				} else {
					for ( int j = b - l ; j >= a ; j -- ) {
						modify( 1 , 1 , n , ( b - l ) * 2 + 1 - j , s[ j ] );
					} a = b - l + 1 ; rev = false ;
				}
			} else {
				if ( ( b - a + 1 - l ) > l ) {
					for ( int j = a + l - 1 ; j >= a ; j -- ) {
						modify( 1 , 1 , n , ( a + l ) * 2 - 1 - j , s[ j ] );
					} a = a + l ;
				} else {
					for ( int j = a + l ; j <= b ; j ++ ) {
						modify( 1 , 1 , n , ( a + l ) * 2 - 1 - j , s[ j ] );
					} b = a + l - 1 ; rev = true ;
				}
			}
		} else {
			scanf( "%d%d" , &l , &r );
			if ( rev ) {
				printf( "%d\n" , query( 1 , 1 , n , b - r + 1 , b - l ) ) ;
			} else {
				printf( "%d\n" , query( 1 , 1 , n , a + l , a + r - 1 ) ) ;
			}
		}
	}
}

int main() {
	init();
	process();
	return 0;
}
