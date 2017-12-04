#include <stdio.h>
#include <assert.h>
#include <errno.h>

#include "errnoi_data.h"

#define EQ ==
#define NEQ !=
#define GT >
#define GTE >=

#define errnoi_gt_zero(ARG) do{errnoi_cmp(ARG, 0, GT);}while(0)
#define errnoi_gte_zero(ARG) do{errnoi_cmp(ARG, 0, GTE);}while(0)

#define errnoi_lt_zero(ARG) do{errnoi_cmp(ARG, 0, LT);}while(0)
#define errnoi_lte_zero(ARG) do{errnoi_cmp(ARG, 0, LTE);}while(0)

#define errnoi_eq_zero(ARG) do{errnoi_cmp(ARG, 0, EQ);}while(0)
#define errnoi_neq_zero(ARG) do{errnoi_cmp(ARG, 0, NEQ);}while(0)

#define errnoi_eq_negone(ARG) do{errnoi_cmp(ARG, -1, EQ);}while(0)
#define errnoi_neq_negone(ARG) do{errnoi_cmp(ARG, -1, NEQ);}while(0)

#define errnoi_eq_eof(ARG) do{errnoi_cmp(ARG, EOF, EQ);}while(0)
#define errnoi_neq_eof(ARG) do{errnoi_cmp(ARG, EOF, NEQ);}while(0)

#define errnoi_eq_true(ARG) do{errnoi_cmp(ARG, TRUE, EQ);}while(0)
#define errnoi_eq_false(ARG) do{errnoi_cmp(ARG, FALSE, EQ);}while(0)

#define errnoi_cmp(ARG1, ARG2, OPERATOR) \
    do { \
        assert(clean_up_done); \
        errno = 0; \
        if ((ARG1) OPERATOR (ARG2)) { \
            if (errno != 0) { \
                errnoi_print(__FILE__, __LINE__-2); \
                goto clean_up_begin; \
            } \
        } \
    } while(0)

#define ERRNOI_CLEAN_UP_BEGIN \
    clean_up_done = 0; \
    clean_up_begin : {

#define ERRNOI_CLEAN_UP_END \
    }

char *errnoi_format();
errnoi_t *errnoi_by_sig(char *sig);
errnoi_t *errnoi_by_code(int code);
errnoi_t *errnoi_by_msg(char *msg);
void errnoi_print(char *filename, int line);

int clean_up_done;
