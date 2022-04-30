#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static bool myfunc(string i, string j)
{
    return i == j;
}

void test(int n){
    int a[n];
    cout << n << endl;
}

void testSet(){
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
}

void testBinaryCom(){
    int i = 1;
	i = i << 1 + 0;
   cout << i << endl;
	// i = (i << 1) + 1;
	i = i << 1 + 1;
   cout << i << endl;
}

void testVectorInsert(){
    vector<int> v;
    for(int i = 0; i < 3; i++){
        v.push_back(i);
        v.push_back(i);
    }

    vector<int> v1;
    // for(int i = 0; i < 3; i++){
    //     v1.push_back(i);
    // }
    v1.assign(v.begin(), v.begin()+3);
    // cout << (v == v1) << endl;
    // v.insert(v.begin()+3, 9);
    // v1.erase(v1.end()-1);
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    cout << v1.back() << endl;
}

int main(){
    string s;
    string str1 = "111";
    string str2 = "1";
    string str3 = str2 + str2 + str2;
    // string str2 = str1.insert(1, "()");
    // cout << str1 << endl;
    // cout << str2 << endl;
    // return 0;
    // cout << ("111" == "111") << endl;
    vector<string> vs1 = {"111", "111", "222", "222"};
    vs1.push_back(str1);
    cout << (str3 == "111") << endl;
    
    cout << vs1.size() << endl;
    // vector<string> vs2;
    // vs2.push_back("222");
    // cout << vs1.begin() - vs1.end()<< endl;
    cout << min(1, (int)(vs1.begin() - vs1.end())) << endl;
    vs1.erase(unique(vs1.begin(), vs1.end(), myfunc), vs1.end());
    cout << vs1.size() << endl;
    for(int i = 0; i < vs1.size(); i++){
        cout << vs1[i] << endl;
        for(int j=0; j<=vs1[i].size(); j++){
            s = vs1[i];
            s.insert(j, "()");
            // cout << s << endl;
            // cout << vs1[i].insert(j, "()") << endl;
        }
    }

    // cout << string::npos << endl;
    // long long sum = 1000000000LL / 2 * (1000000000-1);
    // cout << sum  << endl;
    // sum += 1000000001;
    // cout << sum  << endl;
    // // test(10);
    // testVectorInsert();
   return 0;
}