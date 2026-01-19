#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll dp[2][2][303][20][20];

ll dp_func(string& s,bool tight,bool lz,int sum,int pos,int idx){
    if(idx==s.size()){
        if(sum==0)
            return 1;
        else return 0;
    }

    if(dp[tight][lz][sum+150][pos][idx]!=-1){
        return dp[tight][lz][sum+150][pos][idx];
    }

    int lower_bound = 0;
    int upper_bound = (tight==true)?(s[idx]-'0'):9;

    ll ans = 0;
    for(int dig=lower_bound;dig<=upper_bound;dig++){
        //invalid case
        if(idx==s.size()-1 && lz) continue;
        
        if(lz && dig!=0){
            pos=1;
            ans += dp_func(s,(tight && dig==upper_bound),(lz && dig==0),sum+dig,pos+1,idx+1);
        }else if(!lz){
            if(pos%2!=0){
                ans += dp_func(s,(tight && dig==upper_bound),(lz && dig==0),sum+dig,pos+1,idx+1);
            }else{
                ans += dp_func(s,(tight && dig==upper_bound),(lz && dig==0),sum-dig,pos+1,idx+1);
            }
        }else{
            ans += dp_func(s,(tight && dig==upper_bound),(lz && dig==0),sum,pos,idx+1);
        }
        
    }

    return dp[tight][lz][sum+150][pos][idx] = ans;
}

void solve() {
    // Your code here
    ll a,b;
    cin >> a >> b;
    string l = to_string(a-1);
    string r = to_string(b);

    memset(dp, -1, sizeof(dp));
    ll ans_left = dp_func(l,true,true,0,0,0);

    memset(dp, -1, sizeof(dp));
    ll ans_right = dp_func(r,true,true,0,0,0);

    cout << ans_right - ans_left;
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}