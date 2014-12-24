#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            //assume negative intergers are not palindrome
            if(x<0) {
                return false;
            }

            int div = 1;
            while(x / div >= 10) {
                div *= 10;
            }

            int l=0, r=0;
            while(x) {
                l = x / div;
                r = x % 10;
                if(l != r) {
                    return false;
                }
                x = (x % div) / 10;
                div /= 100;
            }

            return true;

        }
};

int main(int argc, char** argv) {
    Solution s;

    int x = 1;
    cout << x << " expect:true, output:" << s.isPalindrome(x) << endl;

    x = 11;
    cout << x << " expect:true, output:" << s.isPalindrome(x) << endl;

    x = 111;
    cout << x << " expect:true, output:" << s.isPalindrome(x) << endl;

    x = -111;
    cout << x << " expect:false, output:" << s.isPalindrome(x) << endl;

    x = -2147483648;
    cout << x << " expect:false, output:" << s.isPalindrome(x) << endl;

    x = -2147447412;
    cout << x << " expect:false, output:" << s.isPalindrome(x) << endl;

    x = 10;
    cout << x << " expect:false, output:" << s.isPalindrome(x) << endl;

    x = 1000021;
    cout << x << " expect:false, output:" << s.isPalindrome(x) << endl;

    x = 121;
    cout << x << " expect:true, output:" << s.isPalindrome(x) << endl;
    return 0;
}
