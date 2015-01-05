#include <iostream>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            int len = num.size();
            if(len<=3) {
                return accumulate(num.begin(), num.end(), 0);
            }

            sort(num.begin(), num.end());
            long long sum = INT_MAX;
            for(int i=0; i<len-2; ++i) {
                int j = i+1, k = len -1;
                while(j<k) {
                    int tmp = num[i]+num[j]+num[k];
                    if(tmp == target) {
                        return tmp;
                    } else if(tmp<target) {
                        ++j;
                    } else {
                        --k;
                    }

                    if(llabs(tmp-target)<llabs(sum-target)) {
                        sum = tmp;
                    }
                }
            }

            return sum;
        }
};

int main(int argc, char const* argv[]) {
    Solution s;

    vector<int> num = {-1, 2, 1, -4};
    int target = 1;
    cout << "2 == " << s.threeSumClosest(num, target) << endl;

    num = {-3, -2, -5, 3, -4};
    target = -1;
    cout << "-2 == " << s.threeSumClosest(num, target) << endl;
    return 0;
}
