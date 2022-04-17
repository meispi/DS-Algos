#include<bits/stdc++.h>

using namespace std;

class BIT {
    vector<int> bit;
public:
    BIT(int n){
        bit.resize(n+1, 0);
    }
    void updateBIT(int ind, int val){
        ind++;
        while(ind < this->bit.size()){
            this->bit[ind] += val;
            ind += ind & (-ind);
        }
    }
    int rangeSum(int left, int right){
        int lsum = 0, rsum = 0;
        right++;
        while(right > 0){
            rsum += this->bit[right];
            right -= right & (-right);
        }
        while(left > 0){
            lsum += this->bit[left];
            left -= left & (-left);
        }
        return rsum-lsum;
    }
};
int main() {
    vector<int> arr = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    BIT bit = BIT(arr.size());
    for(int i = 0;i < arr.size();i++)
        bit.updateBIT(i, arr[i]);
    int sum = bit.rangeSum(3, 7);
    cout << "Sum of values between indices 3 and 7 (inclusive): " << sum << "\n";
    bit.updateBIT(4, 6-arr[4]);
    cout << "Updated value at 4th index to 6\n";
    sum = bit.rangeSum(3, 7);
    cout << "Sum of values between indices 3 and 7 (inclusive): " << sum << "\n";
    return 0;
}