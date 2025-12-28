#ifndef DEMO_METHODS_H
#define DEMO_METHODS_H

#include <stdio.h>

/* forward type */
typedef struct demo_methods demo_methods;

/* ---- GENERA LA STRUCT DEI METODI ---- */
struct demo_methods {
#define X_METHOD(name, ret, args, tag) ret (* name ## _ ## tag) args;
#include "list.h"
#undef X_METHOD
};

/* ---- GENERA I PROTOTIPI DELLE FUNZIONI ---- */
#define X_METHOD(name, ret, args, tag) ret name ## _ ## tag args;
#include "list.h"
#undef X_METHOD

/* ---- OVERLOAD WRAPPER ---- */
#define demo_bar(x) \
    _Generic((x), \
        int:         demo->bar_INT, \
        const char*: demo->bar_CHARP, \
        char*: demo->bar_CHARP \
    )(x)

#endif
