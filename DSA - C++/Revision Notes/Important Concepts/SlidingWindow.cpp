// ------------------------------------------------------------ Sliding Window Concept ----------------------------------------------------------------------->
// The Sliding Window Technique is a method used to reduce the time complexity of certain problems that require us to look at contiguous subarrays or substrings.
// Instead of recalculating things again and again for overlapping parts of subarrays, you "slide" a window across the input and reuse computations from the previous window.

// When to Use Sliding Window : You need to find a subarray/subsequence that meets a certain condition (like a sum, length, unique characters).
//                            : The problem involves contiguous elements.
//                            : You want to improve from O(n²) to O(n) or O(n log n).

// There are various types of sliding windows. While not all problems fit neatly into one category, most of them fall under one of the following types:
// 1. Fixed Size Sliding Window : Maintain a window of fixed size k. As you move forward, subtract the element going out and add the new incoming one.
// 2. Variable Size Sliding Window : Use two pointers (start and end) to expand and contract the window based on a condition.
// 3. Two Pointers / Dynamic Sliding Window : Similar to variable size sliding window.
// 4. Circular Sliding Window (less common) : Use modulo operation i % n when accessing array elements.
// 5. Monotonic Sliding Window (used with Deque) : Use a deque (double-ended queue) to maintain a monotonic decreasing/increasing queue.
// However, depending on the problem statement, you may need to apply different variations, incorporate additional data structures, or combine sliding window logic with other algorithms or strategies.

// Practice Question 1 : Leetcode Q3
//                     : Problem Statement : Given a string s, find the length of the longest substring without duplicate characters.
//                     : Example 1 : Input: s = "abcabcbb", Output: 3, Explanation: The answer is "abc", with the length of 3.
//                     : Constraints: 0 <= s.length <= 5 * 104, s consists of English letters, digits, symbols and spaces.
// Approach 1 : Brute Force!
//            : 