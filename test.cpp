#include <iostream>
#include <set>
using namespace std;

void test(int n){
    int a[n];
    cout << n << endl;
}

int main(){
    // test(10);
    std::set<int> mySet;    // 直接定义内置类型set集合
 mySet.insert(10);       // 默认比较函数为less
mySet.insert(20);       // 从小到大排序
mySet.insert(15);
mySet.insert(1);
mySet.insert(5);
for(auto it:mySet)    
{
std::cout<<it<<std::endl;
}
    int i = 1;
	i = i << 1 + 0;
   cout << i << endl;
	// i = (i << 1) + 1;
	i = i << 1 + 1;
   cout << i << endl;
   return 0;
    return 0;
}