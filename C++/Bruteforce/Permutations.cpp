//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,暴力枚举法


//LeetCode, Permutations
//描述

   Given a collection of numbers, return all possible permutations.
For example, [1,2,3] have the following permutations: [1,2,3], [1,3,2], [2,1,3], [2,3,1],
[3,1,2], and [3,2,1].

//分析

    next_permutation(),偷懒的做法，可以直接使用std::next_permutation()。如果是在OJ网站上，
可以用这个API偷个懒；但如果是在面试中，面试官肯定会让你重新实现。

    


******************************************************************/



//代码
//LeetCode, Permutations
//时间复杂度O(n!)，空间复杂度O(1)


class Solution{
public:
        vector<vector<int>> permute(vector<int> &num){
            vector<vector<int>> result;
            sort(num.begin(),num.end());

            do{
                result.push_back(num);

            } while(next_permutation(num.begin(), num.end()));
            return result;
        }
};

