#include <bits/stdc++.h>
using namespace std;
int t;
string itos (int n) {
    string res = "";
    res += n % 10 + '0';
    for (int div = 10; div <= n; div *= 10)
        res += (n / div) % 10 + '0';
    reverse (res.begin (), res.end ());
    return res;
}

int cnt=0 ;
void answer (string res, int n) {
    if (n == t + 1) {
        long long ans = 0, num = 0;
        char oper = '+';
        for (int i = 0; i < res.length (); ++i) {
            if (res [i] == '+' || res [i] == '-') {
                if (oper == '+')
                    ans += num;
                if (oper == '-')
                    ans -= num;
                num = 0;
                oper = res [i];
            } else if (res [i] != ' ') {
                num *= 10;
                num += res [i] - '0';
            }
        }
        if (oper == '+')
            ans += num;
        if (oper == '-')
            ans -= num;
        if (ans == 0)
            cnt++ , cout << res << endl;
    } else {
        answer (res + ' ' + itos (n), n + 1);
        answer (res + '+' + itos (n), n + 1);
        answer (res + '-' + itos (n), n + 1);
    }
}
int main () {
    ios :: sync_with_stdio (false);
    cin.tie (0);
    while(cin >> t)
        answer ("1", 2);
//    printf("cnt = %d\n",cnt) ;
    return 0;
}
