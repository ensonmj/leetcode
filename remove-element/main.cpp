#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            int i=0, j=0;
            while(i<n && A[i] != elem) {
                ++i;
            }

            j = i + 1;
            while(j<n) {
                if(A[j] == elem) {
                    ++j;
                } else {
                    swap(A[i++], A[j++]);
                }

            }

            return i;
        }
};

int main(int argc, char const* argv[]) {
    Solution s;

    int A[] = {1, 1, 3, 1, 2, 3, 5, 4};
    int len = s.removeElement(A, sizeof(A)/sizeof(A[0]), 1);
    for_each(A, A+len, [](int &val){ cout << val << " ";});
    cout << endl;

    int A1[] = {1, 1, 3, 1, 2, 3, 5, 4};
    len = s.removeElement(A1, sizeof(A1)/sizeof(A1[0]), 3);
    for_each(A1, A1+len, [](int &val){ cout << val << " ";});
    cout << endl;
    return 0;
}
