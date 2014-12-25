#include <iostream>

using namespace std;

class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            if(!s || !p) {
                return false;
            }

            while(*p && *s && *(p+1) != '*') {
                if(*p == '.' || *s == *p) {
                    ++s;
                    ++p;
                } else {
                    return false;
                }
            }

            if(*p == '\0') {
                return *s == '\0';
            } else if(*s == '\0') {
                return *(p+1) == '*' && isMatch(s, p+2);
            }

            // ".*" or "x*", greedy first
            const char *pbegin = s;
            if(*p == '.') {
                while(*s != '\0') {
                    ++s;
                }
            } else {
                while(*s == *p) {
                    ++s;
                }
            }

            if(isMatch(s, p+2)) {
                return true;
            } else {
                while(s>pbegin) {
                    if(isMatch(--s, p+2)) {
                        return true;
                    }
                }

                return false;
            }

        }
};

int main(int argc, char** argv) {
    Solution s;
    const char *str = "aa";
    const char *p = "a";
    cout << str << "|" << p << ", 0 == " << s.isMatch(str, p) << endl;

    str = "aa";
    p = "aa";
    cout << str << "|" << p << ", 1 == " << s.isMatch(str, p) << endl;

    str = "aaa";
    p = "aa";
    cout << str << "|" << p << ", 0 == " << s.isMatch(str, p) << endl;

    str = "aa";
    p = "a*";
    cout << str << "|" << p << ", 1 == " << s.isMatch(str, p) << endl;

    str = "aa";
    p = ".*";
    cout << str << "|" << p << ", 1 == " << s.isMatch(str, p) << endl;

    str = "ab";
    p = ".*";
    cout << str << "|" << p << ", 1 == " << s.isMatch(str, p) << endl;

    str = "aab";
    p = "c*a*b";
    cout << str << "|" << p << ", 1 == " << s.isMatch(str, p) << endl;

    str = "a";
    p = ".*..a*";
    cout << str << "|" << p << ", 0 == " << s.isMatch(str, p) << endl;

    str = "a";
    p = "ab*";
    cout << str << "|" << p << ", 1 == " << s.isMatch(str, p) << endl;

    str = "aaa";
    p = "aaaa";
    cout << str << "|" << p << ", 0 == " << s.isMatch(str, p) << endl;

    str = "";
    p = "c*c*";
    cout << str << "|" << p << ", 1 == " << s.isMatch(str, p) << endl;
    return 0;
}
