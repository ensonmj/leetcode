#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int> &num) {
            int len = num.size();
            if(len <= 2) {
                return {};
            }

            sort(num.begin(), num.end());

            vector<vector<int>> ret;
            for(int i=0; i<len-2;) {
                int l = i+1, r = len -1;
                int sum;
                while(l<r) {
                    sum = num[i] + num[l] + num[r];
                    if(sum == 0) {
                        ret.emplace_back(vector<int>{num[i], num[l], num[r]});
                        do{++l;}while(num[l] == num[l-1]);
                        do{--r;}while(num[r] == num[r+1]);
                    } else if(sum < 0) {
                        ++l;
                    } else {
                        --r;
                    }
                }
                do{++i;}while(num[i] == num[i-1]);
            }

            return ret;
        }
};


void print(vector<vector<int>> &&vnums) {
    cout << "size:" << vnums.size();
    cout << " {";
    for(auto v : vnums) {
        cout << "{";
        for(auto n : v) {
            cout << n << ",";
        }
        cout << "}, ";
    }
    cout << "}" << endl;
}

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, 4};
    cout << "{{-1, 0, 1}, {-1, -1, 2}} == ";
    print(s.threeSum(nums));

    nums = {-1, 0};
    cout << "{} == ";
    print(s.threeSum(nums));

    nums = {13,-11,-14,4,-9,-10,-11,7,-14,-9,14,0,-5,-7,6,-9,11,6,-14,-12,-10,9,-8,-7,5,6,8,-12,-1,-4,14,-3,0,7,9,7,12,13,-9,13,11,-10,-10,-9,-10,12,-10,8,-5,13,11,-8,7,-12,0,-11,2,-14,-8,8,-3,13,-9,5,5,7,-11,-6,5,-13,-7,1,14,-10,-1,-11,-13,4,12,-11,2,0,-4,-14,4,4,-10,13,-3,-10,6,1,-12,4,-9,1,-4,-13,10,8,-11,10,-14,-12,-14,1,-8,10,-10,11,-15,0,-3,-12,1,-14,-1,-1,6,11,-4,-3,-2,-1,-13};
    cout << "{...} == ";
    print(s.threeSum(nums));

    nums = {0, 1, 1};
    cout << "{} == ";
    print(s.threeSum(nums));

    nums = {-1, 1, -1, 1};
    cout << "{} == ";
    print(s.threeSum(nums));

    nums = {-2, 0, 1, 1, 2};
    cout << "{{-2, 0, 2}, {-2, 1, 1}} == ";
    print(s.threeSum(nums));

    nums = {-2, -1, -1, 0, 2};
    cout << "{{-2, 0, 2}, {-1, -1, 2}} == ";
    print(s.threeSum(nums));

    nums = {-2, 3, -2};
    cout << "{} == ";
    print(s.threeSum(nums));

    nums = {-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1};
    cout << "{...} == ";
    print(s.threeSum(nums));
    return 0;
}
