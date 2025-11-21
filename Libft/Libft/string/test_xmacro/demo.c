#include "ft.h"

/* implementazioni vere dei metodi */
int foo_NONE(int x) {
    printf("foo_NONE(%d)\n", x);
    return x * 2;
}

void bar_CHARP(const char *s) {
    printf("bar_CHARP(\"%s\")\n", s);
}

void bar_INT(int x) {
    printf("bar_INT(%d)\n", x);
}

/* registro i metodi */
static void register_demo_methods(demo_methods *demo) {
(void)demo;
#define X_METHOD(name, ret, args, tag) \
    demo->name ## _ ## tag = name ## _ ## tag;
#include "list.h"
#undef X_METHOD
}

int main(void) {
    demo_methods dm;
    demo_methods *demo = &dm;

    register_demo_methods(demo);

    printf("Testing foo:\n");
    int r = demo->foo_NONE(10);
    printf("foo returned %d\n\n", r);

    printf("Testing bar overloads:\n");
    demo_bar(42);          // chiama bar_INT
    demo_bar("ciao");      // chiama bar_CHARP

    return 0;
}
