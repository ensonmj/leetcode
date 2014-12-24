#include <iostream>
#include <iomanip>
#include <cctype>
#include <climits>

using namespace std;

class Solution {
    public:
        // no valid conversion, return 0
        // overflow, return INT_MAX(2147483647) or INT_MIN(-2147483648)
        int atoi(const char *str) {
            if(!str) {
                return 0;
            }

            int i = 0;
            while(isspace(str[i])) {
                //remove all space
                ++i;
            }

            bool minus = false;
            if(str[i] == '-') {
                minus = true;
                ++i;
            } else if(str[i] == '+') {
                ++i;
            }

            int res = 0;
            while(isdigit(str[i])) {
                int n = str[i++] - '0';
                if(res > INT_MAX/10) {
                    if(minus) {
                        return INT_MIN;
                    } else {
                        return INT_MAX;
                    }
                } else if(res == INT_MAX/10) {
                    if(minus) {
                        if(n>=8) {
                            return INT_MIN;
                        }
                    } else {
                        if(n>=7) {
                            return INT_MAX;
                        }
                    }
                    res = res * 10 + n;
                } else {
                    res = res * 10 + n;
                }
            }

            return minus ? -res : res;
        }
};

int main(int argc, char** argv) {
    Solution s;

    const char *str = NULL;
    cout << setw(12) << "NULL" << " expect: 0, output: " << s.atoi(str) << endl;

    str = "   ";
    cout << setw(12) << str << " expect: 0, output: " << s.atoi(str) << endl;

    str = "   123";
    cout << setw(12) << str << " expect: 123, output: " << s.atoi(str) << endl;

    str = "  skjf123";
    cout << setw(12) << str << " expect: 0, output: " << s.atoi(str) << endl;

    str = "123";
    cout << setw(12) << str << " expect: 123, output: " << s.atoi(str) << endl;

    str = "-123";
    cout << setw(12) << str << " expect: -123, output: " << s.atoi(str) << endl;

    str = "12312312322";
    cout << setw(12) << str << " expect: 2147483647, output: " << s.atoi(str) << endl;

    str = "-12312312322";
    cout << setw(12) << str << " expect: -2147483648, output: " << s.atoi(str) << endl;

    return 0;
}
