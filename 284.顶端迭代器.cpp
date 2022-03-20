/*
 * @lc app=leetcode.cn id=284 lang=cpp
 *
 * [284] 顶端迭代器
 */

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

// template <typename T>
class PeekingIterator : public Iterator {
private:
	int cur;
	int size;
	vector<int> vData;
public:
	// 23 62;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		vData = nums;
		cur = -1;
		size = nums.size();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if(cur < size-1){
			return vData[cur+1];
		}
		return INT_MIN;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if(cur < size-1){
			cur++;
			return vData[cur];
		}
		return INT_MIN;
	}
	
	bool hasNext() const {
		return cur < size-1;
	}
};
// @lc code=end

