/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.16%)
 * Total Accepted:    23.9K
 * Total Submissions: 98.9K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，找出不含有重复字符的最长子串的长度。
 *
 * 示例 1:
 *
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 无重复字符的最长子串是 "abc"，其长度为 3。
 *
 *
 * 示例 2:
 *
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 无重复字符的最长子串是 "b"，其长度为 1。
 *
 *
 * 示例 3:
 *
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 无重复字符的最长子串是 "wke"，其长度为 3。
 * 请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
 *
 *
 */
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> set;
        int                 begin = 0, end = 0, max = 0;
        while (end < s.length())
        {
            if (set.count(s[end]) == 0)
            {
                set.insert(s[end]);
                end++;
            }
            else
            {
                if (end - begin > max)
                {
                    max = end - begin;
                }
                while (s[begin] != s[end])
                {
                    set.erase(s[begin]);
                    begin++;
                }
                set.erase(s[begin]);
                begin++;
            }
        }
        if (end - begin > max)
        {
            max = end - begin;
        }
        return max;
    }
};
