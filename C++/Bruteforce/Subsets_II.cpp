//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,暴力枚举法


//LeetCode, Subsets II
//描述

   Given a collection of integers that might contain duplicates, S, return all possible subsets.
    Note:
    Elements in a subset must be in non-descending order. The solution set must not contain duplicate
subsets. For example, If S = [1,2,2], a solution is:
[
    [2],
    [1],
    [1,2,2],
    [2,2],
    [1,2],
    []
]

//分析

    这题有重复元素，但本质上，跟上一题很类似，上一题中元素没有重复，相当于每个元素只能选0或1次，
这里扩充到了每个元素可以选0到若干次而已。


    


******************************************************************/
//代码


//递归

//增量构造法
//每个元素，都有两种选择，选或不选。

//LeetCode, Subsets II
//增量构造法，版本1，时间复杂度O(2^n)，空间复杂度O(n)


class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());  // 必须排序

        vector<vector<int> > result;
        vector<int> path;

        dfs(S, S.begin(), path, result);
        return result;
    }

private:
    static void dfs(const vector<int> &S, vector<int>::iterator start,
            vector<int> &path, vector<vector<int> > &result) {
        result.push_back(path);

        for (auto i = start; i < S.end(); i++) {
            if (i != start && *i == *(i-1)) continue;
            path.push_back(*i);
            dfs(S, i + 1, path, result);
            path.pop_back();
        }
    }
};

//LeetCode, Subsets II
//增量构造法，版本2，时间复杂度O(2^n)，空间复杂度O(n)


class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > result;
        sort(S.begin(), S.end()); // 必须排序

        unordered_map<int, int> count_map; // 记录每个元素的出现次数
        for_each(S.begin(), S.end(), [&count_map](int e) {
            if (count_map.find(e) != count_map.end())
                count_map[e]++;
            else
                count_map[e] = 1;
        });

        // 将map里的pair拷贝到一个vector里
        vector<pair<int, int> > elems;
        for_each(count_map.begin(), count_map.end(),
                [&elems](const pair<int, int> &e) {
                    elems.push_back(e);
                });
        sort(elems.begin(), elems.end());
        vector<int> path; // 中间结果

        subsets(elems, 0, path, result);
        return result;
    }

private:
    static void subsets(const vector<pair<int, int> > &elems,
            size_t step, vector<int> &path, vector<vector<int> > &result) {
        if (step == elems.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i <= elems[step].second; i++) {
            for (int j = 0; j < i; ++j) {
                path.push_back(elems[step].first);
            }
            subsets(elems, step + 1, path, result);
            for (int j = 0; j < i; ++j) {
                path.pop_back();
            }
        }
    }
};


//位向量法
//开一个位向量bool selected[n]，每个元素，都有两种选择，选或不选。
//代码
//LeetCode, Subsets II
//位向量法，时间复杂度O(2^n)，空间复杂度O(n)


class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > result; // 必须排序
        sort(S.begin(), S.end());
        vector<int> count(S.back() - S.front() + 1, 0);
        // 计算所有元素的个数
        for (auto i : S) {
            count[i - S[0]]++;
        }

        // 每个元素选择了多少个
        vector<int> selected(S.back() - S.front() + 1, -1);

        subsets(S, count, selected, 0, result);
        return result;
    }

private:
    static void subsets(const vector<int> &S, vector<int> &count,
            vector<int> &selected, size_t step, vector<vector<int> > &result) {
        if (step == count.size()) {
            vector<int> subset;
            for(size_t i = 0; i < selected.size(); i++) {
                for (int j = 0; j < selected[i]; j++) {
                    subset.push_back(i+S[0]);
                }
            }
            result.push_back(subset);
            return;
        }

        for (int i = 0; i <= count[step]; i++) {
            selected[step] = i;
            subsets(S, count, selected, step + 1, result);
        }
    }
};


//迭代

//增量构造法
// LeetCode, Subsets II
// 迭代版，时间复杂度O(2^n)，空间复杂度O(1)
class Solution {
   public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end()); // 必须排序
        vector<vector<int> > result(1);

        size_t previous_size = 0;
        for (size_t i = 0; i < S.size(); ++i) {
            const size_t size = result.size();
            for (size_t j = 0; j < size; ++j) {
                if (i == 0 || S[i] != S[i-1] || j >= previous_size) {
                    result.push_back(result[j]);
                    result.back().push_back(S[i]);
                }
            }
            previous_size = size;
        }
        return result;
    } 

};


//二进制法
// LeetCode, Subsets II
// 二进制法，时间复杂度O(2^n)，空间复杂度O(1)
class Solution {
public:
    vectorvector<<int>> subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end()); //必须排序
        //用set去重，不能用unordered_set,因为输出要求有序
        set<vector<int>> result;
        const size_t n = S.size();
        vector<int> v;

        for(size_t i = 0; i < 1u << n; ++i){
            for(size_t j = 0; j < n; ++j){
                if(i & 1 << j)
                v.push_back(S[j]);

            }
            result.insert(v);
            v.clear();

        }
        vector<vector<int>> real_result;
        copy(result.begin(), result.end(), back_inserter(real_result));
        return real_result;
    }
};

