/*
 * @lc app=leetcode.cn id=2049 lang=cpp
 *
 * [2049] 统计最高分的节点数目
 */
#include <iostream>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <iterator>
#include <cstring>
using namespace std;
// template <typename T> std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
//     if (!v.empty()) {
//         out << '[';
//         std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
//         out << "]";
//     }
//     return out;
// }
// template <typename T> std::ostream& operator<< (std::ostream& out, const std::set<T>& v) {
//     if (!v.empty()) {
//         out << '[';
//         std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
//         out << "]";
//     }
//     return out;
// }
template <typename T> std::ostream& operator<< (std::ostream& out, const std::deque<T>& v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "]";
    }
    return out;
}
// @lc code=start
class Solution {
public:
    // Wrong Answer
    int countHighestScoreNodes(vector<int>& parents) {
        // 从叶节点开始动态规划
        int size = parents.size();
        deque<int> dq;
        dq.resize(2, 0);
        cout << dq.front() << " " << dq.back() << endl;
        dq.push_back(1);
        // cout << dq << endl;
        dq.push_back(2);
        // cout << dq << endl;
        dq.pop_front();
        // cout << dq << endl;
        dq.pop_front();
        // cout << dq << endl;
        deque<int> dp[size];    // 左、右子树结点数size个deque
        for(int i = 0; i < size; i++){
            dp[i].resize(2, 0);
        }
        // cout << dp[size-1].front() << " " << dp[size-1].back() << endl;
        // return 0;
        set<int> nonleaves;
        for(int i = 1; i < parents.size(); i++){
            nonleaves.insert(parents[i]);
            // chldrn[parents[i]].push_back(i);
        }
        // nonleaves.erase(-1);
        set<int> children;
        for(int i = 0; i < size; i++){
            if(nonleaves.find(i) == nonleaves.end()){
                children.insert(i);
            }
        }
        // cout << children << endl;

        // 叶节点
        set<int> prnts;
        for(auto child : children){
            int parent = parents[child];
            if(parent == -1){
                continue;
            }
            prnts.insert(parent);
            dp[parent].push_back(1);
            dp[parent].pop_front();
            // if(dp[parent][0] == 0){
            //     dp[parent][0] = 1;
            // }else{
            //     dp[parent][1] = 1;
            // }
        }
        // prnts.erase(-1);
        // 循环处理
        
        children = prnts;
        // children = clearParents(prnts, parents);
        prnts.clear();
        // cout << "111" << endl;
        while(!children.empty()){
            // cout << children << endl;
            // 可能先更新父节点再更新子节点，导致父节点误更新？
            for(auto child : children){
                int parent = parents[child];
                if(parent == -1){
                    continue;
                }
                prnts.insert(parent);
                // if(child == 6){
                //     cout << "出现两次6："<< children << endl;
                // }
                // if(parent == 17){
                //     cout << child << " " << dp[child][0] << " " << dp[child][1] << " 同时：" << endl;
                //     cout << parent << " " << dp[parent][0] << " " << dp[parent][1] << endl;
                // }

                int newNodes = dp[child].front() + dp[child].back() + 1;                
                dp[parent].push_back(newNodes);
                dp[parent].pop_front();
            }
            // prnts.erase(-1);
            children = prnts;
            // children = clearParents(prnts, parents);
            prnts.clear();
        }
        // cout << 17 << "xxx " << dp[17][0] << " " << dp[17][1] << endl;
        
        // cout << "111" << endl;
        long long maxScore = 0;
        int count = 0;
        for(int i = 0; i < size; i++){
            long long score = 1LL * max(dp[i].front(), 1) * max(dp[i].back(), 1);    // 错误！ 有可能1棵、2棵、3棵
            int parent = parents[i];
            if(parent != -1){
                score = score * (size - dp[i].front() - dp[i].back() - 1);
            }
            // cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << score << endl;

            if(score > maxScore){
                maxScore = score;
                count = 1;
            }else if(score == maxScore){
                count++;
            }
        }
        
        // cout << maxScore << endl;
        return count;
    }

    // Wrong Answer
    int countHighestScoreNodes1(vector<int>& parents) {
        // 从叶节点开始动态规划
        int size = parents.size();
        int dp[size][2];    // 左、右子树结点数
        // 错误
        // fill_n(dp[0], dp[0]+size*2, 0);
        // fill(dp[0], dp[0]+size*2, 0);
        memset(dp, 0, sizeof(dp));
        // for(int i = 0; i < size; i++){
        //     fill(dp[i], dp[i]+2, 0);
        // }
        // cout << dp[1][1] << endl;
        // cout << dp[size-1][0] << endl;
        // vector<vector<int>> chldrn{size};
        set<int> nonleaves;
        for(int i = 1; i < parents.size(); i++){
            nonleaves.insert(parents[i]);
            // chldrn[parents[i]].push_back(i);
        }
        // nonleaves.erase(-1);
        set<int> children;
        for(int i = 0; i < size; i++){
            if(nonleaves.find(i) == nonleaves.end()){
                children.insert(i);
            }
        }
        // cout << children << endl;

        // 叶节点
        set<int> prnts;
        for(auto child : children){
            int parent = parents[child];
            if(parent == -1){
                continue;
            }
            prnts.insert(parent);
            dp[parent][0] = 1;
            // if(dp[parent][0] == 0){
            //     dp[parent][0] = 1;
            // }else{
            //     dp[parent][1] = 1;
            // }
        }
        // prnts.erase(-1);
        // 循环处理
        
        children = prnts;
        // children = clearParents(prnts, parents);
        prnts.clear();
        // cout << "111" << endl;
        while(!children.empty()){
            // cout << children << endl;
            // 可能先更新父节点再更新子节点，导致父节点误更新？
            for(auto child : children){
                int parent = parents[child];
                if(parent == -1){
                    continue;
                }
                prnts.insert(parent);
                // if(child == 6){
                //     cout << "出现两次6："<< children << endl;
                // }
                // if(parent == 17){
                //     cout << child << " " << dp[child][0] << " " << dp[child][1] << " 同时：" << endl;
                //     cout << parent << " " << dp[parent][0] << " " << dp[parent][1] << endl;
                // }

                int newNodes = dp[child][0] + dp[child][1] + 1;
                if(dp[parent][0] == 0){
                    dp[parent][0] = newNodes;
                }else if(dp[parent][1] == 0){
                    dp[parent][1] = newNodes;
                }
            }
            // prnts.erase(-1);
            children = prnts;
            // children = clearParents(prnts, parents);
            prnts.clear();
        }
        // cout << 17 << "xxx " << dp[17][0] << " " << dp[17][1] << endl;
        
        // cout << "111" << endl;
        int maxScore = 0;
        int count = 0;
        for(int i = 0; i < size; i++){
            int score = max(dp[i][0], 1) * max(dp[i][1], 1);    // 错误！ 有可能1棵、2棵、3棵
            int parent = parents[i];
            if(parent != -1){
                score = score * (size - dp[i][0] - dp[i][1] - 1);
            }
            // cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << score << endl;

            if(score > maxScore){
                maxScore = score;
                count = 1;
            }else if(score == maxScore){
                count++;
            }
        }
        
        // cout << maxScore << endl;
        return count;
    }

    // 应该清理掉父亲->祖宗->长辈结点，寄
    set<int> clearParents(set<int> s, vector<int> parents){
        for(auto node : s){
            int parent = parents[node];
            while(parent != -1){
                if(s.find(parent) != s.end()){
                    s.erase(parent);
                }
                parent = parents[parent];
            }
        }
        return s;
    }
};
// int main(){
//     vector<int> v = {-1,0,17,6,16,16,17,19,6,4,2,1,5,11,3,10,1,0,20,11,2};
//     // cout << v << endl;
//     // // return 0;
//     // for(int i = 0; i < v.size(); i++){
//     //     cout << i << " "  << v[i]<< endl;
//     // }
//     Solution s;
//     cout << s.countHighestScoreNodes(v) << endl;
//     // set<int> st = {1, 2, 6, 11, 16, 17};
//     // cout << s.clearParents(st, v) << endl;
//     return 0;
// }
// @lc code=end

