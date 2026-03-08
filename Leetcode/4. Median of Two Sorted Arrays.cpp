double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    int m1 = 0, m2 = 0;
    int total = nums1Size + nums2Size;

    for (int count = 0; count <= total / 2; count++) {
        m2 = m1;
        
        if (i < nums1Size && j < nums2Size) {
            if (nums1[i] < nums2[j]) {
                m1 = nums1[i++];
            } else {
                m1 = nums2[j++];
            }
        } else if (i < nums1Size) {
            m1 = nums1[i++];
        } else {
            m1 = nums2[j++];
        }
    }

    if (total % 2 == 1) {
        return (double)m1;
    } else {
        return (double)(m1 + m2) / 2.0;
    }
}