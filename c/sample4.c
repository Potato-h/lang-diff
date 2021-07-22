#include <stdio.h>
#include <stdlib.h>

struct A {
    int cnt;
};

struct B {
    int cnt;
    int* cnt_a;
};

static void inc_a(struct A* a) {
    a->cnt++;
}

static void inc_b(struct B* b) {
    b->cnt++;
    (*b->cnt_a)++;
}

int main(int argc, char* argv[]) {
    struct A* a = NULL;
    struct B* b = NULL;

    a = malloc(sizeof(struct A));
    if (!a) {
        printf("Fail to allocate memory\n");
        goto END;
    }

    *a = (struct A) {
        .cnt = 0
    };

    b = malloc(sizeof(struct B));
    if (!b) {
        printf("Fail to allocate memory\n");
        goto END;
    }

    *b = (struct B) {
        .cnt = 0,
        .cnt_a = &a->cnt
    };

    inc_a(a);
    inc_b(b);
    inc_a(a);

    printf("a.cnt = %d, b.cnt = %d\n", a->cnt, b->cnt);  

END:
    free(a);
    free(b);

    return 0;
}