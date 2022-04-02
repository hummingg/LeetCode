/*
 * @lc app=leetcode.cn id=2038 lang=cpp
 *
 * [2038] 如果相邻两个颜色均相同则删除当前颜色
 */

// @lc code=start
class Solution {
public:
    // 73 7;
    bool winnerOfGame(string colors) {
        vector<int> va, vb;
        int size = colors.size();
        int cnta = 0, cntb = 0;
        for(int i = 0; i < size; ++i){
            if(colors[i] == 'A'){
                ++cnta;
                if(cntb > 2){
                    vb.push_back(cntb-2);
                }
                cntb = 0;
            }else{
                ++cntb;
                if(cnta > 2){
                    va.push_back(cnta-2);
                }
                cnta = 0;
            }
        }
        if(cnta > 2){
            va.push_back(cnta-2);
        }
        if(cntb > 2){
            vb.push_back(cntb-2);
        }
        
        int suma = accumulate(va.begin(), va.end(), 0);
        int sumb = accumulate(vb.begin(), vb.end(), 0);
        // cout << suma << " " << sumb << endl;
        return suma > sumb;
    }

    // 73 25;
    bool winnerOfGame1(string colors) {
        //  不能从字符串两端删除颜色片段。
        int a = 0, b = 0, i = 0, j = 0;
        int size = colors.size();
        bool alice = true;
        char c;
        while(i < size && j < size){
            if(alice){
                c = colors[i];
                if(c == 'A'){
                    ++a;
                    if(a == 3){
                        alice = false;
                        --a;
                        if(i == size-1){ // 最后一次删除，自然+1会导致跳出循环。苟延残喘一下
                            --i;
                            a = 0;
                        }
                    }
                }else{
                    a = 0;
                }
                ++i;
            }else{
                c = colors[j];
                if(c == 'B'){
                    ++b;
                    if(b == 3){
                        alice = true;
                        --b;
                        if(j == size-1){ // 最后一次删除，自然+1会导致跳出循环。苟延残喘一下
                            --j;
                            b = 0;
                        }
                    }
                }else{
                    b = 0;
                }
                ++j;
            }
        }
        return j == size;
    }
};
// @lc code=end
/*
""AAABABB"
"AA"
"ABBBBBBBAAA""
*/
