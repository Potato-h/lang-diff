#include <stdio.h>
#include <stdlib.h>

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
    struct A* a = NULL;
    struct B* b1 = NULL;
    struct B* b2 = NULL;

    a = malloc(sizeof(struct A));
    if (!a) {
        printf("Fail to allocate memory\n");
        goto END;
    }

    *a = (struct A) {
        .cnt = 0
    };

    b1 = malloc(sizeof(struct B));
    if (!b1) {
        printf("Fail to allocate memory\n");
        goto END;
    }

    *b1 = (struct B) {
        .cnt = 0,
        .a = a
    };

    b2 = malloc(sizeof(struct B));
    if (!b2) {
        printf("Fail to allocate memory\n");
        goto END;
    }

    *b2 = (struct B) {
        .cnt = 0,
        .a = a
    };

    inc_a(a);
    inc_b(b1);
    inc_a(a);
    inc_b(b2);

    printf("a.cnt = %d, b1.cnt = %d, b2.cnt = %d\n", a->cnt, b1->cnt, b2->cnt);  

END:
    free(a);
    free(b1);
    free(b2);

    return 0;
}