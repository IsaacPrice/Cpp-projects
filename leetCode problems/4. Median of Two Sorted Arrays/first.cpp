#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combined = nums1;
        for (auto& num : nums2) {
            combined.push_back(num);
        }

        // Sort them
        sort(combined.begin(), combined.end());

        // They are calculated diffrently if it is even or odd
        if (combined.size() % 2 == 0) {
            // Gets the average of the two need numbers
            double num = combined.at(combined.size() / 2) + combined.at(combined.size() / 2 - 1);
            return num / 2.0;
        }
        else {
            return combined.at(int(combined.size() / 2.0));
        }
        return 0;

    }
};