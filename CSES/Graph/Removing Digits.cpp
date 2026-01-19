#include <iostream>
using namespace std;

int max_digit(int n){
    int dig = 0;
    while(n>0){
        int rem = n%10;
        if(rem==9) return 9;

        dig = max(dig,rem);
        n/=10;
    }
    return dig;
}

void solve() {
    int n;
    cin >> n;

    int op=0;
    while(n>0){
        n-=max_digit(n);
        op++;
    }

    cout << op;
}

int main() {
    solve();
    return 0;
}