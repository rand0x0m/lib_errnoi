#define errnoi_data_f(SIG, CODE, MSG) \
    {#SIG, CODE, #MSG}

typedef struct errnoi_s {
    char *sig;
    int code;
    char *msg;
} errnoi_t;
