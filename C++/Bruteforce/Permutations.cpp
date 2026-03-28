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

//LeetCode, Permutations
//重新实现next_permutation()
//时间复杂度O(n!)，空间复杂度O(1)


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());

        do {
            result.push_back(num);
        // 调用的是之前实现的 next_permutation()
        // 而不是 std::next_permutation()
        } while(next_permutation(num.begin(), num.end()));
        return result;
    }
};





//递归
//本题是求路径本身，求所有解，函数参数需要标记当前走到了哪步，还需要中间结果的引用，最终结果的引用。
//扩展节点，每次从左到右，选一个没有出现过的元素。
//本题不需要判重，因为状态装换图是一颗有层次的树。收敛条件是当前走到了最后一个元素。
// LeetCode, Permutations
// 深搜，增量构造法
// 时间复杂度O(n!)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int> > permute(vector<int>& num) {
        sort(num.begin(), num.end());

        vector<vector<int>> result;
        vector<int> path;  // 中间结果

        dfs(num, path, result);
        return result;
    }
private:
    void dfs(const vector<int>& num, vector<int> &path,
            vector<vector<int> > &result) {
        if (path.size() == num.size()) {  // 收敛条件
            result.push_back(path);
            return;
        }

        // 扩展状态
        for (auto i : num) {
            // 查找 i 是否在path 中出现过
            auto pos = find(path.begin(), path.end(), i);

            if (pos == path.end()) {
                path.push_back(i);
                dfs(num, path, result);
                path.pop_back();
            }
        }
    }
};