/*
 * @lc app=leetcode.cn id=2043 lang=cpp
 *
 * [2043] 简易银行系统
 */

// @lc code=start
class Bank {
private:
    vector<long long> balan;
    int accSize = 0;
public:
    Bank(vector<long long>& balance) {
        balan = balance;
        accSize = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1 -= 1;
        account2 -= 1;
        if(account1 < 0 || account1 >= accSize || account2 < 0 || account2 >= accSize
            || balan[account1] < money){
            return false;
        }
        balan[account1] -= money;
        balan[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        account -= 1;
        if(account < 0 || account >= accSize){
            return false;
        }
        balan[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        account -= 1;
        if(account < 0 || account >= accSize || balan[account] < money){
            return false;
        }
        balan[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// @lc code=end

