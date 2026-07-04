88. Merge Sorted Array
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*****************************************
Approach--------------------

The idea is to merge the two sorted arrays from the end instead of the beginning.
Since nums1 already has enough extra space (m + n) to store all elements, we use three pointers:
i → Points to the last valid element in nums1 (m - 1).
j → Points to the last element in nums2 (n - 1).
k → Points to the last position of nums1 (m + n - 1).
Algorithm
Initialize three pointers:
i = m - 1
j = n - 1
k = m + n - 1
Compare nums1[i] and nums2[j].
If nums1[i] is greater, place it at nums1[k] and decrement i.
Otherwise, place nums2[j] at nums1[k] and decrement j.
Decrement k after every placement.
Continue this process until one of the arrays is exhausted.
If any elements remain in nums2, copy them into nums1.
No need to copy the remaining elements of nums1 because they are already in their correct positions.
The merged sorted array is stored directly in nums1.
*************************************************************************************************************
Solution-------------------

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;          // nums1 ke valid elements ka last index
        int j = n - 1;          // nums2 ka last index
        int k = m + n - 1;      // nums1 ka last index

        while(i >= 0 && j >= 0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // Agar nums2 ke elements bache hain
        while(j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }

    }
};
