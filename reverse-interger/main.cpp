#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

//class Solution {
//    public:
//        int reverse(int x) {
//            if(x == 0 || x == -2147483648) {
//                return 0;
//            }

//            ostringstream ss;
//            unsigned long long tmp = (x>0 ? x : -x);
//            ss << tmp;
//            string s = ss.str();
//            std::reverse(s.begin(), s.end());
//            char *end;
//            auto y = strtoull(s.c_str(), &end, 10);
//            if(y>2147483648) {
//                return 0;
//            }

//            if(x<0) {
//                y = -y;
//            }
//            return y;
//        }
//};

//version 2
class Solution {
    public:
        int reverse(int x) {
            int ret = 0, n = 0;
            while(x>9 || x<-9) {
                n = x % 10;
                ret = ret * 10 + n;
                x = x / 10;
            }
            n = x % 10;
            if(ret>magic || ret<-magic) {
                return 0;
            } else {
                return ret * 10 + n;
            }
        }

    private:
        const int magic = 214748364;
};

int main(int argc, char** argv) {
    Solution s;
    int x = 123;
    cout << x << " expect: 321, output: " << s.reverse(x) << endl;

    x = -123;
    cout << x << " expect: -321, output: " << s.reverse(x) << endl;

    x = 10;
    cout << x << " expect: 1, output: " << s.reverse(x) << endl;

    x = 1000000003; //reverse overflow int, should return 0
    cout << x << " expect: 0, output: " << s.reverse(x) << endl;

    x = 1534236469;
    cout << x << " expect: 0, output: " << s.reverse(x) << endl;

    x = -2147483648;
    cout << x << " expect: 0, output: " << s.reverse(x) << endl;

    x = -2147483412;
    cout << x << " expect: -2143847412, output: " << s.reverse(x) << endl;

    x = 1563847412;
    cout << x << " expect: 0, output: " << s.reverse(x) << endl;

    return 0;
}
