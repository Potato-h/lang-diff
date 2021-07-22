#include <stdio.h>

struct A {
    int cnt;
};

struct B {
    int cnt;
    struct A* a;
};

static void inc_a(struct A* a) {
    a->cnt++;
}

static void inc_b(struct B* b) {
    b->cnt++;
    inc_a(b->a);
}

int main(int argc, char* argv[]) {
    struct A a = { 
        .cnt = 0
    };

    struct B b = {
        .cnt = 0,
        .a = &a
    };

    inc_a(&a);
    inc_b(&b);
    inc_a(&a);

    printf("a.cnt = %d, b.cnt = %d\n", a.cnt, b.cnt);  

    return 0;
}