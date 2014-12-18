#include <iostream>

using namespace std;

class Solution {
    public:
        // assume the maximum length of s is 1000
        // and there exists one unique longest palindromic substring.
        string longestPalindrome(string s) {
            int res_b=0, res_e=0, tmp_b=0, tmp_e=0, i=1;
            bool found = false;
            int len = s.length();

            while(i<len) {
                if(s[i] == s[tmp_e])  { //found palindrome
                    while(s[++i] == s[tmp_e]) { //find all successive same char
                    }

                    tmp_b = tmp_e - 1;
                    tmp_e = tmp_e + (i-tmp_e-1)/2;
                    found = true;
                } else if(tmp_e>0 && s[i] == s[tmp_e-1]) {
                    tmp_b = tmp_e - 1;
                    found = true;
                }

                if(found) {
                    while(tmp_b>=0 && i<len) {
                        if(s[i] == s[tmp_b]) {
                            ++i;
                            --tmp_b;
                        } else {
                            break;
                        }
                    }
                    if((i-tmp_b-1)>(res_e-res_b+1)) {
                        res_b = tmp_b + 1;
                        res_e = i - 1;
                    }
                    found = false;
                }

                ++tmp_e;
                i = tmp_e + 1;
                //cout << s.substr(res_b, res_e-res_b+1) << endl;
            }

            return s.substr(res_b, res_e-res_b+1);
        }
};

int main(int argc, char** argv) {
    Solution s;

    string str = "abcddcabcddcba";
    cout << str << " expect: abcddcba, output: " << s.longestPalindrome(str)
        << endl;

    str = "bb";
    cout << str << " expect: bb, output: " << s.longestPalindrome(str) << endl;

    str = "ccc";
    cout << str << " expect: ccc, output: " << s.longestPalindrome(str) << endl;

    str = "bbbb";
    cout << str << " expect: bbbb, output: " << s.longestPalindrome(str) << endl;

    str = "aaabaaaa";
    cout << str << " expect: aaabaaaa, output: " << s.longestPalindrome(str) << endl;

    return 0;
}
