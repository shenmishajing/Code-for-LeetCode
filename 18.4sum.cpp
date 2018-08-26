/*
 * [18] 4Sum
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (28.99%)
 * Total Accepted:    3.8K
 * Total Submissions: 13.2K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 *
 * 注意：
 *
 * 答案中不可以包含重复的四元组。
 *
 * 示例：
 *
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 *
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 *
 */
class pair_pos
{
  public:
    int first = 0, second = 0;
};

class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(),nums.end());
        map<int, list<pair_pos>>::iterator tmpit;
        map<int, list<pair_pos>>           map;
        set<vector<int>>                   pset;
        vector<vector<int>>                result;
        for (auto i = 0; i < nums.size(); ++i)
        {
            for (auto j = i + 1; j < nums.size(); ++j)
            {
                if ((tmpit = map.find(target - nums[i] - nums[j])) != map.end())
                {
                    for (list<pair_pos>::iterator it = tmpit->second.begin(); it != tmpit->second.end(); ++it)
                    {
                        if (it->first != i && it->first != j && it->second != i && it->second != j)
                        {
                            vector<int> tmp;
                            tmp.push_back(nums[i]);
                            tmp.push_back(nums[j]);
                            tmp.push_back(nums[it->first]);
                            tmp.push_back(nums[it->second]);
                            sort(tmp.begin(), tmp.end());
                            if (pset.find(tmp) == pset.end())
                            {
                                result.push_back(tmp);
                                pset.insert(tmp);
                            }
                        }
                    }
                }
                if (map.find(nums[i] + nums[j]) == map.end())
                {
                    pair_pos tmp;
                    tmp.first  = i;
                    tmp.second = j;
                    list<pair_pos> temp;
                    temp.push_back(tmp);
                    map[nums[i] + nums[j]] = temp;
                }
                else
                {
                    pair_pos tmp;
                    tmp.first  = i;
                    tmp.second = j;
                    map[nums[i] + nums[j]].push_back(tmp);
                }
            }
        }
        return result;
    }
};
