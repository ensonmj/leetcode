#include<iostream>

using namespace std;

class Solution
{
    public:
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            if(m<=n) {
                return findMedian(A, m, B, n);
            } else {
                return findMedian(B, n, A, m);
            }
        }
    private:
        double findMedian(int A[], int less, int B[], int more) {
            if(less == 0) {
                if(more == 0) {
                    return 0;
                } else if(more == 1) {
                    return B[0];
                } else if(more == 2) {
                    return (B[0]+B[1])/2.0;
                } else {
                    int mid = more/2;
                    if(more&1) { //odd
                        return B[mid];
                    } else {
                        return (B[mid-1]+B[mid])/2.0;
                    }
                }
            } else if(less == 1) {
                if(more == 1) {
                    return (A[0]+B[0])/2.0;
                }
                int mid = more/2;
                if(more&1) { //odd
                    if(A[0] <= B[mid-1]) {
                        return (B[mid-1]+B[mid])/2.0;
                    } else if(A[0]>=B[mid+1]) {
                        return (B[mid+1]+B[mid])/2.0;
                    } else {
                        return (A[0]+B[mid])/2.0;
                    }
                } else { //even
                    if(A[0]<=B[mid-1]) {
                        return B[mid-1];
                    } else if(A[0]>=B[mid]) {
                        return B[mid];
                    } else {
                        return A[0];
                    }
                }
            } else {
                // remove elements which not include median from two arrays.
                int midA = less/2;
                int midB = more/2;
                if(A[midA] == B[midB]) {
                    if(!(less&1) && !(more&1)) {
                        int big = A[midA-1]>=B[midB-1] ? A[midA-1] : B[midB-1];
                        return (big+A[midA])/2.0;
                    } else {
                        return A[midA];
                    }
                } else if(A[midA]<B[midB] && A[midA-1]>=B[midB-1]) { /* \/ */
                    return findMedianSortedArrays(A, less, &B[midA], more-2*midA);
                } else if(A[midA]<B[midB] && A[midA-1]<B[midB-1]) { /* // */
                    return findMedian(&A[midA], less-midA, B, more-midA);
                } else if(A[midA]>B[midB] && A[midA-1]>=B[midB-1]) { /* \\ */
                    return findMedian(A, less-midA, &B[midA], more-midA);
                } else { //A[midA]>B[midB] && A[midA-1]<B[midB-1] /* /\ */
                    return findMedian(&A[midA], less-2*midA, B, more);
                }
            }
        }
};

int main()
{
    //2.5
    int A[] = {1, 2};
    int B[] = {3, 4};
    Solution s;
    cout << s.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int)) << endl;

    //1
    int A0[] = {1, 2};
    int B0[] = {1, 1};
    cout << s.findMedianSortedArrays(A0, sizeof(A0)/sizeof(int), B0, sizeof(B0)/sizeof(int)) << endl;

    //2.5
    int A1[] = {3, 4};
    int B1[] = {1, 2};
    cout << s.findMedianSortedArrays(A1, sizeof(A1)/sizeof(int), B1, sizeof(B1)/sizeof(int)) << endl;

    //3
    int A2[] = {1, 2};
    int B2[] = {3, 4, 5};
    cout << s.findMedianSortedArrays(A2, sizeof(A2)/sizeof(int), B2, sizeof(B2)/sizeof(int)) << endl;

    //3
    int A3[] = {3, 4};
    int B3[] = {1, 2, 5};
    cout << s.findMedianSortedArrays(A3, sizeof(A3)/sizeof(int), B3, sizeof(B3)/sizeof(int)) << endl;

    //3.5
    int A4[] = {1, 2};
    int B4[] = {3, 4, 5, 6};
    cout << s.findMedianSortedArrays(A4, sizeof(A4)/sizeof(int), B4, sizeof(B4)/sizeof(int)) << endl;

    //3.5
    int A5[] = {4, 5};
    int B5[] = {1, 2, 3, 6};
    cout << s.findMedianSortedArrays(A5, sizeof(A5)/sizeof(int), B5, sizeof(B5)/sizeof(int)) << endl;

    //2
    int A6[] = {1, 2, 2};
    int B6[] = {1, 2, 3};
    cout << s.findMedianSortedArrays(A6, sizeof(A6)/sizeof(int), B6, sizeof(B6)/sizeof(int)) << endl;

    //2.5
    int A7[] = {1, 4};
    int B7[] = {2, 3};
    cout << s.findMedianSortedArrays(A7, sizeof(A7)/sizeof(int), B7, sizeof(B7)/sizeof(int)) << endl;

    //2.5
    int A8[] = {1, 3};
    int B8[] = {2, 4};
    cout << s.findMedianSortedArrays(A8, sizeof(A8)/sizeof(int), B8, sizeof(B8)/sizeof(int)) << endl;

    //3.5
    int A9[] = {1, 4, 5};
    int B9[] = {2, 3, 6};
    cout << s.findMedianSortedArrays(A9, sizeof(A9)/sizeof(int), B9, sizeof(B9)/sizeof(int)) << endl;

    //3.5
    int A10[] = {1, 5, 6};
    int B10[] = {2, 3, 4};
    cout << s.findMedianSortedArrays(A10, sizeof(A10)/sizeof(int), B10, sizeof(B10)/sizeof(int)) << endl;

    //3.5
    int A11[] = {2, 4, 5};
    int B11[] = {1, 3, 6};
    cout << s.findMedianSortedArrays(A11, sizeof(A11)/sizeof(int), B11, sizeof(B11)/sizeof(int)) << endl;

    return 0;
}
