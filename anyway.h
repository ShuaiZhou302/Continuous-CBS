#ifndef CCBS_ANYWAY_H
#define CCBS_ANYWAY_H

struct A {
    int a;
    int b;
};

template<class T>
class B {
public:
    T a;
    T b;
};

B<int> x;
B<bool> y;

int a = 2;

#endif //CCBS_ANYWAY_H
