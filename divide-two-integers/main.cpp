#include <iostream>
#include <cassert>
#include <climits>

using namespace std;

//Euclidean division, too slow
//class Solution {
//    public:
//        int divide(int dividend, int divisor) {
//            assert(divisor);
//            //overflow, return INT_MAX
//            if(dividend == INT_MIN && divisor == -1) {
//                return INT_MAX;
//            }
//            if(divisor < 0) {
//                return -divide(dividend, -divisor);
//            }
//            if(dividend<0) {
//                //move quotient close to 0, not to negative infinity(-∞)
//                return -divide(-dividend, divisor);
//            }

//            // At this point, dividend >= 0 and divisor > 0
//            int quotient = 0, reminder = dividend;
//            while(reminder >= divisor) {
//                quotient += 1;
//                reminder -= divisor;
//            }

//            return quotient;
//        }
//};

// long division
class Solution {
    public:
        //move quotient close to 0, not to negative infinity(-∞)
        int divide(int dividend, int divisor) {
            assert(divisor);
            // overflow, return INT_MAX
            if(dividend == INT_MIN && divisor == -1) {
                return INT_MAX;
            }

            return divide(static_cast<long>(dividend),
                    static_cast<long>(divisor));
        }

    private:
        long divide(long dividend, long divisor) {
            if(divisor < 0) {
                return -divide(dividend, -divisor);
            }
            if(dividend < 0) {
                return -divide(-dividend, divisor);
            }

            // At this point, dividend >= 0 and divisor > 0
            long quotient = 0, reminder = 0;

            int n = getHighestBitIndex(dividend);
            for(int i=n; i>=0; --i) {
                reminder = reminder << 1;
                reminder += getBit(dividend, i);
                if(reminder >= divisor) {
                    reminder -= divisor;
                    setBit(quotient, i);
                }
            }

            return quotient;
        }
        inline int getHighestBitIndex(long num) {
            for(int i=31; i>=0; --i) {
                if(num & (1<<i)) {
                    return i;
                }
            }
            return 0;
        }

        inline int getBit(long num, int index) {
            return (num >> index) & 1;
        }

        inline void setBit(long &num, int index) {
            num |= 1 << index;
        }

        //inline int clearBit(int &num, int index) {
            //num &= ~(1 << index);
            //return num;
        //}

};

int main(int argc, char const* argv[]) {
    Solution s;

    int dividend = 13, divisor = 5;
    int quotient = s.divide(dividend, divisor);
    cout << 13/5 << "== " << quotient << endl;

    dividend = -13;
    divisor = 5;
    quotient = s.divide(dividend, divisor);
    cout << -13/5 << "== " << quotient << endl;

    dividend = 13;
    divisor = -5;
    quotient = s.divide(dividend, divisor);
    cout << 13/-5 << "== " << quotient << endl;

    dividend = INT_MAX;
    divisor = 1;
    quotient = s.divide(dividend, divisor);
    cout << INT_MAX << " == " << quotient << endl;

    dividend = INT_MAX;
    divisor = INT_MAX;
    quotient = s.divide(dividend, divisor);
    cout << "1 == " << quotient << endl;

    dividend = INT_MIN;
    divisor = -1;
    quotient = s.divide(dividend, divisor);
    cout << INT_MAX << " == " << quotient << endl;

    dividend = INT_MIN;
    divisor = 1;
    quotient = s.divide(dividend, divisor);
    cout << INT_MIN << " == " << quotient << endl;

    dividend = INT_MIN;
    divisor = 2;
    quotient = s.divide(dividend, divisor);
    cout << INT_MIN/2 << " == " << quotient << endl;

    dividend = INT_MIN;
    divisor = INT_MIN;
    quotient = s.divide(dividend, divisor);
    cout << "1 == " << quotient << endl;
    return 0;
}
