#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    int sum = 0;int l=0,ct=0;

    for(int r=0;r<n;r++){
        sum+=r;

        if(sum==x) ct++;

        while(sum>x && l<=r){
            sum-=nums[l];
            l++;
        }
    }

    cout << ct;
}

int main() {
    solve();
    return 0;
}