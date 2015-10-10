#include <set>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MaxN = 24;
const LL INF = 1LL<<60;
set<LL> S;
pair<LL,LL> SolveSubproblem( const vector<LL> &A ) {
	LL Sum = 0;
	for( int i = 0; i < A.size(); i++ )Sum += A[i];
	S.clear() ;
	int n1 = A.size()/2;
	int n2 = A.size() - n1;
	for( int i = 0; i < (1<<n1); i++ ) {
		LL Temp = 0;
		for( int j = 0; j < n1; j++ ) {
			if( i & (1<<j) ) {
				Temp += A[j];
			}
		}
		S.insert( Temp );
	}
	pair<LL,LL> Answer = make_pair( 0 , Sum );
	for( int i = 0; i < (1<<n2); i++ ) {
		LL Temp = 0;
		for( int j = 0; j < n2; j++ ) {
			if( i & (1<<j) ) {
				Temp += A[n1+j];
			}
		}
		LL a = Sum/2 - Temp;
		set<LL>::iterator P = lower_bound( S.begin() , S.end() , a );
		if( P == S.end() )continue;
		else {
			a = Temp + *P;
			LL b = Sum - a;
			if( a > b )swap( a , b );
			if( b-a < Answer.second - Answer.first ) {
				Answer = make_pair( a , b );
			}
		}
	}
	return Answer;
}
int Readint() {
	char c;
	int Number;
	for( c = getchar(); !( c >= '0' && c <= '9' ); c = getchar() );
	for( Number = 0; c >= '0' && c <= '9'; c = getchar() )Number = Number*10 + ( c - '0' );
	return Number;
}
LL ReadLL() {
	char c;
	LL Number;
	for( c = getchar(); !( c >= '0' && c <= '9' ); c = getchar() );
	for( Number = 0; c >= '0' && c <= '9'; c = getchar() )Number = Number*10 + ( c - '0' );
	return Number;
}
int main() {
	int N = Readint();
	vector<LL> Cindy;
	LL Sum = 0;
	for( int i = 0; i < N; i++ ) {
		Cindy.push_back( ReadLL() );
		Sum += Cindy.back();
	}
	LL Answer = INF;
	for( int i = 0; i < (1<<N); i++ ) {
		int BitCount = 0;
		for( int j = 0; j < N; j++ ) {
			if( i & (1<<j) ) {
				BitCount++;
			}
		}
		if( BitCount > N/3 )continue;
		LL a = 0;
		vector<LL> A;
		for( int j = 0; j < N; j++ ) {
			if( i & (1<<j) ) {
				a += Cindy[j];
			}
			else {
				A.push_back( Cindy[j] );
			}
		}
		if( abs( (Sum-a)/2-a ) >= Answer )continue;
		pair<LL,LL> Answer_Subproblem = SolveSubproblem( A );
		LL b = Answer_Subproblem.first , c = Answer_Subproblem.second;
		if( a > b )swap( a , b );
		if( b > c )swap( b , c );
		Answer = min( Answer , c-a );
	}
	printf("%lld\n",Answer);
	return 0;
}
