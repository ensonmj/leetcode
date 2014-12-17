#include<iostream>

using namespace std;

class Solution
{
    public:
        int lengthOfLongestSubstring(string s) {
            int len = 0;
            string subStr;
            for(auto c : s) {
                auto i=subStr.find(c);
                if(i != string::npos) {
                    if(subStr.length()>len) {
                        len = subStr.length();
                    }
                    subStr = subStr.substr(i+1) + c;
                } else {
                    subStr += c;
                }
            }
            if(subStr.length()>len) {
                len = subStr.length();
            }

            return len;
        }
};

int main(int argc, char** argv)
{
    Solution s;
    string str = "abcabcbb";
    cout << str << " expect 3, output " << s.lengthOfLongestSubstring(str) << endl;

    str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    cout << str << " expect 12, output " << s.lengthOfLongestSubstring(str) << endl;

    str = "qopubjguxhxdipfzwswybgfylqvjzhar";
    cout << str << " expect 12, output " << s.lengthOfLongestSubstring(str) << endl;

    return 0;
}
