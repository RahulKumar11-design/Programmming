#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int n,x;
    cin >> n >> x;
    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    unordered_map<int,int> mp;
    mp[0]=1;
    int sum = 0;
    int total = 0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];

        if(mp.count(sum-x)){
            total+=mp[sum-x];
        }

        mp[sum]++;
    }

    cout << total;
}

int main() {
    solve();
    return 0;
}