#include <functional>
#include <iostream>
using namespace std;

void g_Func(int x, int y){
    cout<<"first:"<<x<<endl;
    cout<<"second:"<<y<<endl;
}

void third_Func(int a, int b, int c){
    cout<<"first:"<<a<<endl;
    cout<<"second:"<<b<<endl;
    cout<<"third:"<<c<<endl;
}

class A
{
public:
    void a_Func(int x, int y){
        cout<<"A::first:"<<x<<endl;
        cout<<"A::second:"<<y<<endl;
    }
};

int main(){
    auto bf1 = std::bind(g_Func, 10, std::placeholders::_1);
    bf1(20);
    auto bf2 = std::bind(g_Func, std::placeholders::_1 , 10);
    bf2(20);

    A a;
    // std::function< void(int, int)> bf3 = std::bind(&A::a_Func, a, std::placeholders::_1, std::placeholders::_2);
    // bf3(10, 20); ///< same as a.Func(10, 20)

    // std::function< void(int)> bf4 = std::bind(&A::a_Func, a, 100, std::placeholders::_1);
    // bf4(10); ///< same as a.Func(10, 100)

    // std::function< void(int)> bf5 = std::bind(&A::a_Func, a, std::placeholders::_1, 100);
    // bf5(10); ///< same as a.Func(100, 10)

    std::function< void(int)> a1 = std::bind(third_Func, 10, 20, std::placeholders::_1);
    a1(30);

    std::function< void(int)> a2 = std::bind(third_Func, 10, std::placeholders::_1, 20);
    a2(30);

    // std::function< void(int, int, int)> a3 = std::bind(third_Func,
    //                                                 std::placeholders::_1,
    //                                                 std::placeholders::_2,
    //                                                 std::placeholders::_3);
    // a3(100, 0, 200);
    std::function< void(int, int)> a4 = std::bind(third_Func, std::placeholders::_1, 10, std::placeholders::_2);
    a4(0,20);
    std::function< void(int, int)> a5 = std::bind(third_Func, 10, placeholders::_1, placeholders::_2);
    a5(0,20);

    return 0;
}