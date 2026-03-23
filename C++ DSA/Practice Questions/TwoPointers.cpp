// ------------------------------------------------------------ Two Pointers Concept ----------------------------------------------------------------------->
// Question 1 : Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
// 
int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0;  // slow pointer - tracks the position of unique elements

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;               // move the slow pointer
                nums[i] = nums[j]; // copy the unique element
            }
        }

        return i + 1; // unique count = last unique index + 1
    }