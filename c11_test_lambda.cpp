#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector< int> vec;
/// 1. simple lambda
//auto it = std::find_if(vec.begin(), vec.end(), [](int i) { return i > 50; });
class A
{
public:
        bool operator()(int i) const { return i > 50; }
};
//auto it = std::find_if(vec.begin(), vec.end(), A());

/// 2. lambda return syntax
std::function<int(int)> square = [](int i) -> int { return i * i; };

/// 3. lambda expr: capture of local variable
int main()
{
        vector<int> vec = {0, 10, 20, 30, 40, 50, 60, 70, 80};

        int min_val = 20;
        int max_val = 50;

        auto it1 = std::find_if(vec.begin(), vec.end(), [&](int i) -> bool {
                bool flag = false;
                if(i > min_val && i < max_val){
                        flag = true;
                }
                i = max_val;
                return flag;
        });
        cout<<(*it1)<<endl;

        auto it2 = std::find_if(vec.begin(), vec.end(), [&](int i) {
                return i > min_val && i < max_val;
        });
        cout<<(*it2)<<endl;

        auto it3 = std::find_if(vec.begin(), vec.end(), [=, &max_val](int i) {
                //return i > min_val && i < max_val;
                bool flag = false;
                if(i > min_val && i < max_val){
                        flag = true;
                }
                max_val = i;
                return flag;
        });
        cout<<(*it3)<<endl;
        cout<<"new max: "<<max_val<<endl;

        return 0;
}