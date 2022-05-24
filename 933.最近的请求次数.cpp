/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 *
 * https://leetcode-cn.com/problems/number-of-recent-calls/description/
 *
 * algorithms
 * Easy (73.06%)
 * Likes:    138
 * Dislikes: 0
 * Total Accepted:    54.5K
 * Total Submissions: 72.8K
 * Testcase Example:  '["RecentCounter","ping","ping","ping","ping"]\n[[],[1],[100],[3001],[3002]]'
 *
 * 写一个 RecentCounter 类来计算特定时间范围内最近的请求。
 * 
 * 请你实现 RecentCounter 类：
 * 
 * 
 * RecentCounter() 初始化计数器，请求数为 0 。
 * int ping(int t) 在时间 t 添加一个新请求，其中 t 表示以毫秒为单位的某个时间，并返回过去 3000
 * 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 [t-3000, t] 内发生的请求数。
 * 
 * 
 * 保证 每次对 ping 的调用都使用比之前更大的 t 值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：
 * ["RecentCounter", "ping", "ping", "ping", "ping"]
 * [[], [1], [100], [3001], [3002]]
 * 输出：
 * [null, 1, 2, 3, 3]
 * 
 * 解释：
 * RecentCounter recentCounter = new RecentCounter();
 * recentCounter.ping(1);     // requests = [1]，范围是 [-2999,1]，返回 1
 * recentCounter.ping(100);   // requests = [1, 100]，范围是 [-2900,100]，返回 2
 * recentCounter.ping(3001);  // requests = [1, 100, 3001]，范围是 [1,3001]，返回 3
 * recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002]，范围是
 * [2,3002]，返回 3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= t <= 10^9
 * 保证每次对 ping 调用所使用的 t 值都 严格递增
 * 至多调用 ping 方法 10^4 次
 * 
 * 
 */

// @lc code=start
class RecentCounter {
private:
    vector<int> v;  // 最长3001
    int begin = 0;
public:
    RecentCounter() {
    }
    // 90 9;
    int ping(int t) {
        // 8 35;
        if(v.size() > 3100){
            begin -= v.size() - 3100;
            v.erase(v.begin(), v.begin() + v.size() - 3100);    //清内存
        }
        v.push_back(t);
        int bottom = t - 3000;
        while(v[begin] < bottom){ // begin < v.size() && 
            ++begin;
        }
        return v.size() - begin;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
/*
["RecentCounter", "ping", "ping", "ping", "ping"]\n
[[], [1], [100], [3001], [3002]]
*/
