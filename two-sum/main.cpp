#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            unordered_map<int, int> hash;
            vector<int> res;

            size_t i=0, len = numbers.size();
            while(i<len) {
                int n = numbers[i];
                int sub = target - n;
                if(hash.find(sub) != hash.end()) {
                    res.push_back(hash[sub]);
                    res.push_back(i+1);
                    break;
                } else {
                    hash[n] = ++i;
                }
            }

            return res;
        }
};

int main(int argc, char** argv)
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    auto res = s.twoSum(numbers, target);
    if(!res.empty()) {
        cout << res[0] << " "<< res[1] << endl;
    } else {
        cout << "can't find the match" << endl;
    }

    return 0;
}
