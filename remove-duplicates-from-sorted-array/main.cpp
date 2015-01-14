#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if(n<=1) {
                return n;
            }

            int val = A[0];
            int i = 1, j = 1;
            while(j<n) {
                if(A[j] != val) {
                    A[i++] = A[j];
                    val = A[j];
                } else {
                    ++j;
                }
            }

            return i;
        }
};

int main(int argc, char const* argv[]) {
    Solution s;

    int A[] = {1, 1, 2};
    int n = s.removeDuplicates(A, sizeof(A)/sizeof(A[0]));
    cout << "1 2 == ";
    for_each(A, A+n, [](int &val){cout << val << " ";});
    cout << endl;

    int A1[] = {1, 1, 1, 2, 2, 2, 3, 4};
    n = s.removeDuplicates(A1, sizeof(A1)/sizeof(A1[0]));
    cout << "1 2 3 4 == ";
    for_each(A1, A1+n, [](int &val){cout << val << " ";});
    cout << endl;

    return 0;
}
