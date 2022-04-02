/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
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
    // Time Limit Exceeded 81
    int maxConsecutiveAnswers(string answerKey, int k) {
        int sizeKey = answerKey.size();
        if(sizeKey < 3 || k >= sizeKey/2){
            return sizeKey;
        }
        
        vector<int> v;
        int count = 1;
        for(int i = 1; i < sizeKey; ++i){
            if(answerKey[i] == answerKey[i-1]){
                ++count;
            }else{
                v.push_back(count);
                count = 1;
            }
        }
        v.push_back(count);
        // cout << v << endl;
        int size = v.size();
        int maxConLen = 0;
        vector<int> preSum(size+1);
        preSum[0] = 0;
        for(int i = 0; i < size; ++i){
            preSum[i+1] = preSum[i] + v[i];
        }
        // cout << preSum << endl;
        for(int i = 0; i < size; ++i){
            int count = 0;
            int j = i;
            // 太慢了
            while(count < k && j < size){
                count += v[j];
                j += 2; // <= size+1
            }
            // 加v[j-2]后第一次>=k, 策反了i i+2 ... j-4 j-2(可能不完全使用，若完全则j-1)，
            // 连接了 i-1(可能越界) i+1 ... j-3 j-1(可能不)
            int conLen;
            if(k >= count){ // 刚好完全使用j-2，连接了j-1
                j = min(j, size);
                conLen = preSum[j] - preSum[i];
                conLen += k - count;    // 回退到前面补充
            }else if(count > k){
                conLen = preSum[j-2] - preSum[i] + k -(count - v[j-2]);
            }
            // else{  // count < k, j = size or size+1
            //     conLen = preSum[size] - preSum[i];
            //     conLen += k - count;    // 回退到前面补充
            // }
            if(i > 0){
                conLen += v[i-1];
            }
            // cout << count << " " << conLen << endl;
            maxConLen = max(maxConLen, conLen);
        }
        return min(maxConLen, sizeKey);
    }

    int maxConsecutiveAnswers9(string answerKey, int k) {
        vector<int> v;
        int sizeKey = answerKey.size();
        if(sizeKey < 3 || k >= sizeKey/2){
            return sizeKey;
        }
        int count = 1;
        for(int i = 1; i < sizeKey; ++i){
            if(answerKey[i] == answerKey[i-1]){
                ++count;
            }else{
                v.push_back(count);
                count = 1;
            }
        }
        v.push_back(count);
        // cout << v << endl;
        int size = v.size();
        vector<int> v1, v2;
        int maxConLen = 0;
        for(int i = 0; i < size-1; i+=2){
            v1.push_back(v[i]);
            v2.push_back(v[i+1]);
        }
        if(size % 2 == 1){
            v1.push_back(v.back());
        }
        // if(v2.empty()){
        //     return v1.front();
        // }
        vector<int> preSum1(v1.size()+1), preSum2(v2.size()+1);
        preSum1[0] = 0;
        preSum2[0] = 0;
        for(int i = 0; i < v1.size(); ++i){
            preSum1[i+1] = preSum1[i] + v1[i];
        }
        for(int i = 0; i < v2.size(); ++i){
            preSum2[i+1] = preSum2[i] + v2[i];
        }
        // cout << v1 << " " << preSum1 << endl;
        // cout << v2 << " " << preSum2 << endl;
        for(int i = 0; i < v1.size(); ++i){
            int j = i+1;
            while(j < preSum1.size() && preSum1[i] + k > preSum1[j]){
                ++j;
            }
            int conLen = preSum2[j-1] - preSum2[i] + k; // i <-> j-2
            if(preSum1[i] + k == preSum1[j] && i > 0){
                conLen += preSum2[i] - preSum2[i-1];    // i-1
            }
            maxConLen = max(maxConLen, conLen);
        }
        for(int i = 0; i < v2.size(); ++i){
            int j = i+1;
            while(j < preSum2.size() && preSum2[i] + k > preSum2[j]){
                ++j;
            }
            int conLen = preSum1[j-1] - preSum1[i] + k; // i <-> j-2
            if(preSum2[i] + k == preSum2[j] && i > 0){
                conLen += preSum1[i] - preSum1[i-1];    // i-1
            }
            maxConLen = max(maxConLen, conLen);
        }
        return min(maxConLen, sizeKey);
    }

    // Time Limit Exceeded 69
    int maxConsecutiveAnswers1(string answerKey, int k) {
        vector<int> v;
        int sizeKey = answerKey.size();
        if(sizeKey < 3 || k >= sizeKey/2){
            return sizeKey;
        }
        int count = 1;
        for(int i = 1; i < sizeKey; ++i){
            if(answerKey[i] == answerKey[i-1]){
                ++count;
            }else{
                v.push_back(count);
                count = 1;
            }
        }
        v.push_back(count);
        // cout << v << endl;
        int size = v.size();
        int maxConLen = 0;
        for(int i = 0; i < size-1; ++i){
            int count = 0, conLen = 0, j = i;
            bool front = true;
            // cout << "j begin: " << j << endl;
            while(j < size && count < k){
                int deduct = min(k-count, v[j]);
                count += deduct;
                conLen += deduct;    // 策反成后方
                if(deduct == v[j] && j < size-1){
                    conLen += v[j+1];
                }
                if(j<2 && deduct == v[j])    front=false;
                if(j == i && j > 0 && deduct == v[j]){
                    // 可能合并前方
                    conLen += v[j-1];
                    // if(j-1==0) front = false;
                }
                j += 2;
                // cout << conLen << " ";
            }
            
            // cout << "j end: " << j << endl;
            // conLen += min(k-count, sizeKey-conLen);
            if(front)   conLen += min(k-count, sizeKey-conLen);  // 不满足j < size 导致退出时,往前补充。一次就补完了吧！要补两次的话包含在前面的i里了
            // cout << conLen << endl;
            maxConLen = max(maxConLen, conLen);
        }
        // i  = size-1 ? 策反成前方，已经在i-1的情况里了

        return maxConLen;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> v = {1, 2};
    // cout << s.maxConsecutiveAnswers("TTFF",  2) << endl;
    // cout << s.maxConsecutiveAnswers("TFFT",  1) << endl;
    // cout << s.maxConsecutiveAnswers("TTFTTFTT",  1) << endl;
    // cout << s.maxConsecutiveAnswers("TTTTTFTFFT",  2) << endl;
    // cout << s.maxConsecutiveAnswers("FTTFFTFFFTFTFTTFTTFFTFFTTTFTFTTTTFFFFFTTFFTFFTFFFFFFTFFFFTFTFTFFTTFFFFFTFFFTFFFTTFFTTTFTTTTFFFTTFFFF", 49) << endl;
    cout << s.maxConsecutiveAnswers("FFFTTFTTFT",  3) << endl;
    return 0;
}
/*
5 1 1 2 1
5 1 1   0 5 6 7
1 2     0 1 3

"TTFF",  2
"TFFT",  1
"TTFTTFTT",  1
"TTTTTFTFFT",  2
"TTTTTFTFFT",  2    8
"FTTFFTFFFTFTFTTFTTFFTFFTTTFTFTTTTFFFFFTTFFTFFTFFFFFFTFFFFTFTFTFFTTFFFFFTFFFTFFFTTFFTTTFTTTTFFFTTFFFF", 49  100
"FFFTTFTTFT",  3    8
3 2 1 2 1 1


"TTFTTFTT" 最多策反周围k个
2 1 2 1 2

2 2 2 + 前缀和  0 2 4 6
1 1 + 前缀和    0 1 2

2 2 4 4 6
+
0 1 1 2 2
=
2 3 5 6 8

"TTTTTFTFFT"
2

*/
