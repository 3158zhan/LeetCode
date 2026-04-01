//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,暴力枚举法


//LeetCode, Letter Combinations Of A Phone Number
//描述

   Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
        图Phone Keyboard如路径image/Phone-keyboard.png所示

    Input:Digit string "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
    Note: Although the above answer is in lexicographical order, your answer could be in any order you
want.

//分析

    无


******************************************************************/



//代码

//递归

// LeetCode, Letter Combinations of a Phone Number
// 时间复杂度O(3^n)，空间复杂度O(n)
class Solution {
public:
    const vector<string> keyboard{ " ", "", "abc", "def", // '0','1','2',...
"ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> letterCombinations(const string &digits){
        vector<string> result;
        if(digits.empty()) return result;
        dfs(digits, 0, "", result);
    }

    void dfs(const string &digits, size_t cur, string path,
            vector<string> &result){
                if(cur == digits.size()){
                    result.push_back(path);
                    return;
                }
                for(auto c : keboard[digits[cur] - '0']){
                    dfs(digits, cur + 1, path + c, result);
                }
            }
};

//迭代

// LeetCode, Letter Combinations of a Phone Number
// 时间复杂度O(3^n)，空间复杂度O(1)
class Solution {
public:
    const vector<string> keyboard{ " ", "", "abc", "def", // '0','1','2',...
"ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> letterCombinations(const string &digits){
        if(digits.empty()) return vector<string>();
        vector<string> result(1, "");
        for(auto d : digits){
            const size_t n = result.size();
            const size_t m = keyboard[d - '0'].size();

            result.resize(n * m);
            for(size_t i = 0; i < m; ++i)
                copy(result.begin(),result.begin() + n, result.begin() + n * i);

                for(size_t i = 0; i < m; ++i){
                    auto begin = result.begin();
                    for_each(begin + n * i, begin + n * (i+1), [&](string &s){
                        s += keyboard[d - '0'][i];
                    });
                }
            }
            return result;
   }
};