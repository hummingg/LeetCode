/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */
#include <iostream>
#include <vector>
#include <bitset>
#include <string>
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
    // 15 76;
    bool validUtf8(vector<int>& data) {
        // bitset<8> bits;
        int count = 0;
        string binary;
        for(int i = 0; i < data.size();){
            binary = bitset<8>(data[i]).to_string();
            count = 0;
            int j = 0;
            while(binary[j] == '1'){
                count++;
                j++;
            }
            // cout << count << endl;
            if(count > 4 || count == 1) {
                return false;
            }else if(count == 0){
                i++;
                continue;
            }
            count--;
            for(i = i + 1; i < data.size() && count > 0;i++){
                binary = bitset<8>(data[i]).to_string();
                // cout << count << endl;
                if(binary[0] == '1' && binary[1] == '0'){
                    count--;
                }else{
                    return false;
                }
            }
        }
        
        return count == 0;
    }
};
// @lc code=end
int main(){
    Solution s;
    bitset<8> bits; //7位长度
    // vector<int> v = {197,130,1};
    vector<int> v = {235,140,4};
    bits = 145;
    string str = bits.to_string();
    cout << str << endl;
    cout << str[1] << endl;
    bitset<8> nums(str);
    // cout<<nums.to_ullong()<<endl;//转换成unsigned long long 类型整数
    cout << s.validUtf8(v) << " <- 答案" << endl;
    return 0;
}
