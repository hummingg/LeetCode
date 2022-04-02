/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int n, int k) {
        
        return 0;
    }

    // 超时
    int findKthNumber1(int n, int k) {
        // int ret = 0;
        long count = 0;
        long num = 1;
        // int base = 0;
        while(count < k){
            while(count < k && num <= n){
                // ret.push_back(num);
                ++count;
                num *= 10;  // 1090
            };
            num /= 10;
            if(count == k){
                return num;
            }
            ++num; // 回退到110，但11还没进来
            if(num % 10 == 0){  // 110应由 11*10 得到，不应由回退得到
                do{
                    num /= 10;
                }while(num % 10 == 0);
                continue;
            }
            long top = min(num / 10 * 10 + 9, (long)n);
            long maxStep = min(k-count, top-num+1); // num 到 top
            count += maxStep;
            num += maxStep;
            // long base = num / 10;
            //     while(count < k && num <= n && num/10 == base){
            //         // ret.push_back(num);
            //         ++count;
            //         ++num;
            //     }
            if(count == k){
                return num-1;
            }
            
            // 回退要补全
            if(num % 10 == 0){
                do{
                    num /= 10; // 个位的0应由 *10 得到，不应由回退、增加得到
                }while(num % 10 == 0);
            }else{  // 较少，如例13. 14 -> 2 
                num = num / 10 + 1; // 回退。什么时候回退到个位数？
                if(num % 10 == 0){  // 110应由 11*10 得到，不应由回退得到
                    do{
                        num /= 10;
                    }while(num % 10 == 0);
                }
            }
        }
        return (int)num;
    }
};
// @lc code=end
/*
13\n2
1\n1
1000000000\n1000000000
783368691\n319151369 总时间超时，CPU听了都摇头
304089173\n87099045 48/69
*/
