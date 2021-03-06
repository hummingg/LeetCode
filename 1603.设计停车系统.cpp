/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem {
private:
    int bigLeft, mediumLeft, smallLeft;
public:
    // 42 78;
    ParkingSystem(int big, int medium, int small) {
        bigLeft = big;
        mediumLeft = medium;
        smallLeft = small;
    }
    
    bool addCar(int carType) {
        bool added = false;
        switch (carType){
            case 1:
                if(bigLeft > 0){
                    bigLeft--;
                    added = true;
                }
                break;
            case 2:
                if(mediumLeft > 0){
                    mediumLeft--;
                    added = true;
                }
                break;
            case 3:
                if(smallLeft > 0){
                    smallLeft--;
                    added = true;
                }
                break;
            default:
                break;
        }
        return added;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

