#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int> mp;

    mp[0]=1;int sum=0,count=0;

    for(int i=0;i<nums.size();i++){
        sum = (sum+nums[i])%k;
        if(sum<0){
            sum = k+sum;
        }

        if(mp.count(sum)){
            count+=mp[sum];
        }
        mp[sum]++;
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    cout << subarraysDivByK(v,n);

    return 0;
}