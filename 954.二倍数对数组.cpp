/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;
template <class T> std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
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
    // 如何优化？
    bool canReorderDoubled(vector<int>& arr) {
        int size = arr.size();
        map<int, int> m;
        for(int a : arr)  ++m[a];
        // for(int i = 0; i < size; ++i){
        //     if(m.find(arr[i]) == m.end()){
        //         m[arr[i]] = 1;
        //     }else{
        //         ++m[arr[i]];
        //     }
        // }
        if(m.find(0) != m.end()){
            if(m[0] % 2 == 0){
                m[0] = 0;
            }else{
                return false;
            }
        }
        
        // 利用了 map 的自动排序
        for(auto it=m.begin(); it != m.end(); ++it){
            if(it->second == 0){
                continue;
            }
            auto itrt = m.find(it->first * 2);
            if(itrt != m.end()){
                if(itrt->second != 0){
                    int duct = min(it->second, itrt->second);
                    itrt->second -= duct;
                    it->second -= duct;
                }
            }
        }
        for(auto it=m.begin(); it != m.end(); ++it){
            if(it->second != 0){
                return false;
            }
        }
        return true;
    }

    // 58 43;
    bool canReorderDoubled1(vector<int>& arr) {
        int size = arr.size();
        if(size == 0){
            return true;
        }
        map<int, int> m;
        for(int i = 0; i < size; ++i){
            if(m.find(arr[i]) == m.end()){
                m[arr[i]] = 1;
            }else{
                ++m[arr[i]];
            }
        }
        if(m.find(0) != m.end()){
            if(m[0] % 2 == 0){
                // m.erase(0);
                m[0] = 0;
            }else{
                return false;
            }
        }
        
        // for(auto it=m.begin(); it != m.end(); ++it){
        //     cout << it->first << " " << it->second << endl;
        // }
        // 利用map的自动排序
        for(auto it=m.begin(); it != m.end(); ++it){
            if(it->second == 0){
                continue;
            }
            auto itrt = m.find(it->first * 2);
            if(itrt != m.end() && itrt->second != 0){
                int duct = min(it->second, itrt->second);
                itrt->second -= duct;
                it->second -= duct;
                // if(it->second <= itrt->second){
                //     itrt->second -= it->second;
                //     // it = m.erase(it);
                //     it->second = 0;
                // }
                // else{
                //     if(it->first > 0){
                //         return false;
                //     }
                // }
                // if(itrt->second == 0){
                //     m.erase(itrt);   // 遍历时删除容易出BUG
                // }
            }
            // else{
            //     if(it->first > 0){
            //         return false;
            //     }
            // }
        }
        for(auto it=m.begin(); it != m.end(); ++it){
            // cout << it->first << " " << it->second << endl;
            if(it->second != 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> v = {1,2,1,-8,8,-4,4,-4,2,-2};
    cout << s.canReorderDoubled(v) << endl;
    return 0;
}
/*
[3,1,3,6]
[2,1,2,6]
[4,-2,2,-4]
[0, 0]
[0, 0, 0, 1]
1,2,1,-8,8,-4,4,-4,2,-2
*/