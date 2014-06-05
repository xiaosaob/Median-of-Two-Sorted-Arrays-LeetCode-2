// There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2)
            return findKth((m+n)/2+1, A, m, B, n);
        return (findKth((m+n)/2, A, m, B, n)+findKth((m+n)/2+1, A, m, B, n))/2;
    }
    
    double findKth(int k, int A[], int m, int B[], int n) {
        if(m <= 0) return B[k-1];
        if(n <= 0) return A[k-1];
        if(k <= 1) return min(A[0], B[0]);
        if(m > n) return findKth(k, B, n, A, m);
        
        int aMid = min(k/2, m);
        int bMid = k-aMid;
        
        if(A[aMid-1] == B[bMid-1]) {
            return A[aMid-1];
        } else if(A[aMid-1] < B[bMid-1]){
            return findKth(k-aMid, A+aMid, m-aMid, B, bMid);
        } else {
            return findKth(k-bMid, A, aMid, B+bMid, n-bMid);
        }
    }
};
