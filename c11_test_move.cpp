#include <iostream>
using namespace std;

class HugeMem{
    public:
        HugeMem(int size): sz(size > 0 ? size : 1) {
            c = new int[sz];
        }
        ~HugeMem() { cout<<"HugeMem 析构\n";delete [] c; }
        HugeMem(HugeMem && hm): sz(hm.sz), c(hm.c) {
            cout<<"HugeMem move 构造\n";
            hm.c = nullptr;
        }
        int * c;
        int sz;
};
class Moveable{
    public:
        Moveable():i(new int(3)), h(1024) {}
        ~Moveable() { cout<<"Moveable 析构\n";delete i; }
        Moveable(Moveable && m):
            i(m.i), h(move(m.h)) {      // 强制转为右值，以调用移动构造函数
                m.i = nullptr;
            }
        int* i;
        HugeMem h;
};

Moveable GetTemp() {
    //Moveable tmp = Moveable();
    Moveable tmp;
    cout << hex << "Huge Mem from " << __func__
        << " @" << tmp.h.c << endl; // Huge Mem from GetTemp @0x603030
    return tmp;
}

int main() {
    Moveable a(GetTemp());
    cout << hex << "Huge Mem from " << __func__
        << " @" << a.h.c << endl;   // Huge Mem from main @0x603030
    return 0;
}