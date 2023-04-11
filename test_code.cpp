#include <iostream>
class Par{
protected:
    int a;
public:
    Par():a(1004){}
    int b;
};

class Ch: public Par{
public:
    int c = a;
};

int main(){
    Ch mem;
    std::cout << mem.c << '\n';
}