#include <bits/stdc++.h>
using namespace std;

// Find the median of two sorted arrays without merging them

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int N = m+n;
    int left = (m+n+1)/2;
    if(m>n) {
        return findMedianSortedArrays(nums2, nums1);
    }
    int low = 0, high = m;
    while(low<=high) {
        int mid = (low+high)/2;
        int oMid = left - mid;
        int l1 = INT_MIN, l2=INT_MIN;
        int r1 = INT_MAX, r2=INT_MAX;
        if(mid<m) r1 = nums1[mid];
        if(oMid<n) r2 = nums2[oMid];
        if(mid-1>=0) l1 = nums1[mid-1];
        if(oMid-1>=0) l2 = nums2[oMid-1];
        if(l1<=r2 && l2<=r1) {
            if(N%2 != 0) {
                return max(l1,l2);
            } else {
                return (double) (max(l1,l2) + min(r1,r2)) / 2;
            }
        } else if (l1>r2) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
}

int main() {
    vector<int> v1;
    v1.push_back(7);
    v1.push_back(12);
    v1.push_back(14);
    v1.push_back(15);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(9);
    v2.push_back(11);

    double median2Arrays = findMedianSortedArrays(v1, v2);
    cout << median2Arrays;
}
