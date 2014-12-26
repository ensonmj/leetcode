#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if(strs.empty()) {
                return "";
            }
            string str = strs.front();
            for(size_t i=1; i<strs.size(); ++i) {
                size_t len = 0;
                if(str.length() <= strs[i].length()) {
                    len = str.length();
                } else {
                    len = strs[i].length();
                }
                if(len == 0) {
                    return "";
                }
                size_t j=0;
                for(; j<len; ++j) {
                    if(str[j] != strs[i][j]) {
                        if(j == 0) {
                            return "";
                        } else {
                            break;
                        }
                    }
                }
                str = str.substr(0, j);
            }

            return str;
        }

};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<string> strs;
    cout << " == " << s.longestCommonPrefix(strs) << endl;

    strs = {""};
    cout << " == " << s.longestCommonPrefix(strs) << endl;

    strs = {"", "abc"};
    cout << " == " << s.longestCommonPrefix(strs) << endl;

    strs = {"a", "abc"};
    cout << "a == " << s.longestCommonPrefix(strs) << endl;

    strs = {"abc", "a"};
    cout << "a == " << s.longestCommonPrefix(strs) << endl;

    strs = {"ca", "a"};
    cout << " == " << s.longestCommonPrefix(strs) << endl;
    return 0;
}
