#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string convert(string s, int nRows) {
            if(nRows == 1) {
                return s;
            }

            vector<string> vec;
            for(int i=0; i<nRows; ++i) {
                vec.push_back(string(""));
            }

            for(int i=0; i<s.length(); ++i) {
                int k = i % (2*nRows-2);
                if(k<nRows) {
                    vec[k] += s[i];
                } else {
                    vec[2*nRows-2-k] += s[i];
                }
            }

            string str;
            for(int i=0; i<nRows; ++i) {
                str += vec[i];
            }

            return str;
        }
};

int main(int argc, char** argv) {
    Solution s;

    string str = "PAYPALISHIRING";
    cout << "expect: PAHNAPLSIIGYIR, output: " << s.convert(str, 3) << endl;

    str = "A";
    cout << "expect: A, output: " << s.convert(str, 1) << endl;

    return 0;
}
