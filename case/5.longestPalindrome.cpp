/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>


using std::string;
class Solution {
public:

    bool it_is_a_palindrome(const string& substr){
        size_t len = substr.size() ;

        for(size_t i = 0;i < (len >> 1); ++i)
        {
            if (substr.at(i) != substr.at(len - (i + 1))){
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string s) {
        if (s.empty() || s.size() == 1 ){
            return s;
        }
        
        string palindrome;
        palindrome.push_back(s.front());
        for(size_t i = 0; i < s.size(); ++i)
        {
            char ch = s.at(i);
            size_t pos_start = i + 1;
            size_t pos = s.find_first_of(ch, pos_start);
            while (pos != string::npos)
            {
                if (it_is_a_palindrome(s.substr(i + 1, pos - i - 1))){
                    string tmp = s.substr(i,pos - i + 1);
                    if (tmp.size() > palindrome.size()){
                        palindrome = tmp;
                    }
                }
                pos_start = pos + 1;
                pos = s.find_first_of(ch, pos_start);
            }

            if (palindrome.size() == s.size()){
                break;
            }
        }

        return palindrome;
    }
};
// @lc code=end

