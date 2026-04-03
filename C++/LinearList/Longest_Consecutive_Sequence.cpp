//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,线性表
//这类题目考察线性表的操作，例如，数组，单链表，双向链表等。


//LeetCode, Longest Consecutive Sequence
//描述

    Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
    For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1,
2, 3, 4]. Return its length: 4.
    Your algorithm should run in O(n) complexity

//分析

    如果允许O(nlogn)的复杂度，那么可以先排序，可是本题要求O(n)。
    由于序列里的元素是无序的，又要求O(n),首先要想到用哈希表。
    用一个哈希表unordered_map<int, bool> used记录每个元素是否使用，对每个元素，以该元素为中心，
往左右扩张，直到不连续为止，记录下最长的长度。


******************************************************************/



//代码


// LeetCode, Longest Consecutive Sequence
// 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int longestConsecutive(const vector<int> &nums) {
        unordered_map<int, bool> used;

        for (auto i : nums) used[i] = false;

        int longest = 0;

        for (auto i : nums) {
            if (used[i]) continue;

            int length = 1;

            used[i] = true;

            for (int j = i + 1; used.find(j) != used.end(); ++j) {
                used[j] = true;
                ++length;
            }

            for (int j = i - 1; used.find(j) != used.end(); --j) {
                used[j] = true;
                ++length;
            }

            longest = max(longest, length);
        }

        return longest;
    } 
};

//分析2
//第一直觉是个聚类的操作,应该有union,find的操作.连续序列可以用两端和长度来表示.
//本来用两端就可以表示,但考虑到查询的需求,将两端分别暴露出来.用unordered_map<int, int> map来
//存储
// LeetCode, Longest Consecutive Sequence
// 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> map;
        int size = nums.size();
        int l = 1;
        for (int i = 0; i < size; i++) {
            if (map.find(nums[i]) != map.end()) continue;
            map[nums[i]] = 1;
            if (map.find(nums[i] - 1) != map.end()) {
                l = max(l, mergeCluster(map, nums[i] - 1, nums[i]));
            }
            if (map.find(nums[i] + 1) != map.end()) {
                l = max(l, mergeCluster(map, nums[i], nums[i] + 1));
            }
        }
        return size == 0 ? 0 : l;
    }

private:
    int mergeCluster(unordered_map<int, int> &map, int left, int right) {
        int upper = right + map[right] - 1;
        int lower = left - map[left] + 1;
        int length = upper - lower + 1;
        map[upper] = length;
        map[lower] = length;
        return length;
    } 
};
