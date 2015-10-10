#include <stdio.h>

#define max(x, y) (x>y? (x) : (y))
#define MAXSIZE 33

class Bignum{
public:
    Bignum(int n = 0){
        for(int i=0; i<MAXSIZE; ++i) _digit[i] = 0;
        _size = 0;
        while(n!=0){
            _digit[_size++] = n%10;
            n/=10;
        }
    }
    Bignum operator = (const Bignum& a){
        for(int i=0; i<MAXSIZE; ++i) _digit[i] = a._digit[i];
        _size = a._size;
        return (*this);
    }
    Bignum operator + (const Bignum& a){
        Bignum ret(*this);
        return (ret += a);
    }
    Bignum operator += (const Bignum& a){
        _size = max(_size, a._size);
        for(int i=0; i<_size; ++i) _digit[i] += a._digit[i];
        carry();
        return (*this);
    }
    Bignum operator * (int n){
        Bignum ret(*this);
        return (ret *= n);
    }
    Bignum operator *= (int n){
        for(int i=0; i<_size; ++i) _digit[i] *= n;
        carry();
        return (*this);
    }
    void print() const {
        for(int i=_size-1; i>=0; --i) putchar('0'+_digit[i]);
        if(_size == 0) putchar('0');
    }
private:
    void carry(){
        for(int i=0; i<_size; ++i){
            if(_digit[i] > 9){
                if(i == _size-1) _size++;
                _digit[i+1] += _digit[i]/10;
                _digit[i] %= 10;
            }
        }
    }

    int _digit[MAXSIZE], _size;
};

Bignum dp[26][26][51][4];
// 0: not touched top and bottom
// 1: only touched top
// 2: only touched bottom
// 3: touched both top and botton
Bignum ways[26][51];

void calcWays(int n, int m){
    // printf("ways %d %d:\n", n, m);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<m; ++k){
                for(int t=0; t<4; ++t) dp[i][j][k][t] = 0;
            }
        }
    }
    for(int i=1; i<n-1; ++i){
        for(int j=i; j<n-1; ++j) dp[i][j][0][0] = 1;
    }
    for(int j=0; j<n-1; ++j) dp[0][j][0][1] = 1;
    for(int i=1; i<n; ++i) dp[i][n-1][0][2] = 1;
    ways[n][1] = dp[0][n-1][0][3] = 1;

    Bignum sum;
    for(int k=1; k<m; ++k){
        // 0
        for(int i=0; i<n; ++i){
            sum = 0;
            for(int j=i; j<n; ++j){
                for(int i2=i; i2<=j; ++i2) sum += dp[i2][j][k-1][0];
                dp[i][j][k][0] += sum;
            }
        }
        // 1
        for(int i=0; i<n; ++i){
            sum = 0;
            for(int j=i; j<n; ++j){
                for(int i2=0; i2<=i; ++i2) sum += dp[i2][j][k-1][1];
                dp[i][j][k][1] += sum;
            }
        }
        // 2
        for(int j=0; j<n; ++j){
            sum = 0;
            for(int i=j; i>=0; --i){
                for(int j2=n-1; j2>=j; --j2) sum += dp[i][j2][k-1][2];
                dp[i][j][k][2] += sum;
            }
        }
        // 3
        for(int i=0; i<n; ++i){
            sum = 0;
            for(int j=n-1; j>=i; --j){
                for(int i2=0; i2<=i; ++i2) sum += dp[i2][j][k-1][3];
                dp[i][j][k][3] += sum;
            }
        }

        for(int j=0; j<n-1; ++j){
            dp[0][j][k][1] += dp[0][j][k][0];
            dp[0][j][k][0] = 0;
            dp[0][j][k][3] += dp[0][j][k][2];
            dp[0][j][k][2] = 0;
        }
        for(int i=1; i<n; ++i){
            dp[i][n-1][k][2] += dp[i][n-1][k][0];
            dp[i][n-1][k][0] = 0;
            dp[i][n-1][k][3] += dp[i][n-1][k][1];
            dp[i][n-1][k][1] = 0;
        }
        dp[0][n-1][k][3] += (dp[0][n-1][k][0] + dp[0][n-1][k][1] + dp[0][n-1][k][2]);
        dp[0][n-1][k][0] = dp[0][n-1][k][1] = dp[0][n-1][k][2] = 0;

        sum = 0;
        for(int i=0; i<n; ++i){
            for(int j=i; j<n; ++j) sum += dp[i][j][k][3];
        }
        ways[n][k+1] = sum;
    }
}

int main(){
    int T, n;
    Bignum ans;

    for(int i=1; i<26; ++i) calcWays(i, 50-i);

    scanf("%d", &T);
    for(int t=1; t<=T; ++t){
        scanf("%d", &n);
        printf("Case #%d: ", t);
        if(n&1){
            printf("0\n");
            continue;
        }
        ans = 0;

        for(int i=1; i*2<=n/2; ++i){
            if(i*2 == n/2) ans += ways[i][n/2-i];
            else ans += ways[i][n/2-i] * 2;
        }
        ans.print();
        printf("\n");
    }
    return 0;
}
