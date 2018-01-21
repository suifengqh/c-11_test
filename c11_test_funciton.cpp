#include <functional>
#include <iostream>
using namespace std;

std::function< int(int) > print_func;

/// normal function -> std::function object
int CPrint(int a){
    std::cout<<"global::a:"<<a<<endl;
}

/// functor -> std::function object
class CxxPrint
{
public:
    size_t operator()(int a) {
        cout<<"CxxPoint::a:"<<a<<endl;
    }
};
int main(){
    CxxPrint p;
    print_func = p;
    print_func(3);
    print_func = CPrint;
    print_func(6);
    return 0;
}
