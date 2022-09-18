/*
 * @lc app=leetcode.cn id=2353 lang=cpp
 *
 * [2353] 设计食物评分系统
 *
 * https://leetcode.cn/problems/design-a-food-rating-system/description/
 *
 * algorithms
 * Medium (28.34%)
 * Likes:    14
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 18.5K
 * Testcase Example:  '["FoodRatings","highestRated","highestRated","changeRating","highestRated","changeRating","highestRated"]\n' +
  '[[["kimchi","miso","sushi","moussaka","ramen","bulgogi"],["korean","japanese","japanese","greek","japanese","korean"],[9,12,8,15,14,7]],["korean"],["japanese"],["sushi",16],["japanese"],["ramen",16],["japanese"]]'
 *
 * 设计一个支持下述操作的食物评分系统：
 * 
 * 
 * 修改 系统中列出的某种食物的评分。
 * 返回系统中某一类烹饪方式下评分最高的食物。
 * 
 * 
 * 实现 FoodRatings 类：
 * 
 * 
 * FoodRatings(String[] foods, String[] cuisines, int[] ratings) 初始化系统。食物由
 * foods、cuisines 和 ratings 描述，长度均为 n 。
 * 
 * 
 * foods[i] 是第 i 种食物的名字。
 * cuisines[i] 是第 i 种食物的烹饪方式。
 * ratings[i] 是第 i 种食物的最初评分。
 * 
 * 
 * void changeRating(String food, int newRating) 修改名字为 food 的食物的评分。
 * String highestRated(String cuisine) 返回指定烹饪方式 cuisine 下评分最高的食物的名字。如果存在并列，返回
 * 字典序较小 的名字。
 * 
 * 
 * 注意，字符串 x 的字典序比字符串 y 更小的前提是：x 在字典中出现的位置在 y 之前，也就是说，要么 x 是 y 的前缀，或者在满足 x[i] !=
 * y[i] 的第一个位置 i 处，x[i] 在字母表中出现的位置在 y[i] 之前。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入
 * ["FoodRatings", "highestRated", "highestRated", "changeRating",
 * "highestRated", "changeRating", "highestRated"]
 * [[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean",
 * "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14,
 * 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16],
 * ["japanese"]]
 * 输出
 * [null, "kimchi", "ramen", null, "sushi", null, "ramen"]
 * 
 * 解释
 * FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi",
 * "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek",
 * "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
 * foodRatings.highestRated("korean"); // 返回 "kimchi"
 * ⁠                                   // "kimchi" 是分数最高的韩式料理，评分为 9 。
 * foodRatings.highestRated("japanese"); // 返回 "ramen"
 * ⁠                                     // "ramen" 是分数最高的日式料理，评分为 14 。
 * foodRatings.changeRating("sushi", 16); // "sushi" 现在评分变更为 16 。
 * foodRatings.highestRated("japanese"); // 返回 "sushi"
 * ⁠                                     // "sushi" 是分数最高的日式料理，评分为 16 。
 * foodRatings.changeRating("ramen", 16); // "ramen" 现在评分变更为 16 。
 * foodRatings.highestRated("japanese"); // 返回 "ramen"
 * ⁠                                     // "sushi" 和 "ramen" 的评分都是 16 。
 * ⁠                                     // 但是，"ramen" 的字典序比 "sushi" 更小。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2 * 10^4
 * n == foods.length == cuisines.length == ratings.length
 * 1 <= foods[i].length, cuisines[i].length <= 10
 * foods[i]、cuisines[i] 由小写英文字母组成
 * 1 <= ratings[i] <= 10^8
 * foods 中的所有字符串 互不相同
 * 在对 changeRating 的所有调用中，food 是系统中食物的名字。
 * 在对 highestRated 的所有调用中，cuisine 是系统中 至少一种 食物的烹饪方式。
 * 最多调用 changeRating 和 highestRated 总计 2 * 10^4 次
 * 
 * 
 */
#include "includeLc/leetcode.h"
// @lc code=start
struct MyCompare {
	bool operator()(const pair<string,int> &a, const pair<string,int> &b) const{
        if (a.second != b.second){
            return a.second > b.second;
        }
        return a.first < b.first;
	}
};
class FoodRatings {
    // 76: 5.22%(712ms) 30.8%(162.1MB);
    map<string, int> mfr;   // food, rate
    map<string, string> mfc;    // food, cui
    map<string, set<pair<string, int>, MyCompare>> mcfr;   // cui, food rate
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; ++i){
            mfr[foods[i]] = ratings[i];
            mfc[foods[i]] = cuisines[i];
            mcfr[cuisines[i]].insert(set<pair<string, int>, MyCompare>::value_type(foods[i], ratings[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        mcfr[mfc[food]].erase(set<pair<string, int>, MyCompare>::value_type(food, mfr[food]));
        mfr[food] = newRating;
        mcfr[mfc[food]].insert(set<pair<string, int>, MyCompare>::value_type(food, newRating));
    }
    
    string highestRated(string cuisine) {
        return mcfr[cuisine].begin()->first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// @lc code=end
/*
["FoodRatings","highestRated","highestRated","changeRating","highestRated","changeRating","highestRated"]\n
[[["kimchi","miso","sushi","moussaka","ramen","bulgogi"],["korean","japanese","japanese","greek","japanese","korean"],[9,12,8,15,14,7]],["korean"],["japanese"],["sushi",16],["japanese"],["ramen",16],["japanese"]]\n

["FoodRatings","changeRating","highestRated","changeRating","highestRated","highestRated","changeRating","highestRated","highestRated","changeRating","highestRated","changeRating","highestRated"]\n
[[["tjokfmxg","xmiuwozpmj","uqklk","mnij","iwntdyqxi","cduc","cm","mzwfjk"],["waxlau","ldpiabqb","ldpiabqb","waxlau","ldpiabqb","waxlau","waxlau","waxlau"],[9,13,7,16,10,17,16,17]],["tjokfmxg",19],["waxlau"],["uqklk",7],["waxlau"],["waxlau"],["tjokfmxg",14],["waxlau"],["waxlau"],["tjokfmxg",4],["waxlau"],["mnij",18],["waxlau"]]
*/
