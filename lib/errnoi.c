#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#include "errnoi.h"

extern errnoi_t errnoi_data[];
extern size_t errnoi_data_len;

errnoi_t *errnoi_by_sig(char *sig) {
    int i = 0;
    for (i=0; i<errnoi_data_len; i++) {
        if(errnoi_data[i].sig == sig) {
            return &errnoi_data[i];
        }
    }

    return NULL;
}

errnoi_t *errnoi_by_code(int code) {
    int i = 0;
    for (i=0; i<errnoi_data_len; i++) {
        if(errnoi_data[i].code == code) {
            return &errnoi_data[i];
        }
    }

    return NULL;
}

errnoi_t *errnoi_by_msg(char *msg) {
    int i = 0;
    for (i=0; i<errnoi_data_len; i++) {
        if(errnoi_data[i].msg == msg) {
            return &errnoi_data[i];
        }
    }

    return NULL;
}

int clean_up_done = 1;

char *errnoi_format() {
    char *buff;
    errnoi_t *errnoi;
    if ((buff = malloc(100)) != NULL) {
        //printf("Here");
        if ((errnoi = errnoi_by_code(errno)) != NULL) {
            snprintf(buff, 100,"***Error : %d %s, %s***", errnoi->code, errnoi->sig, errnoi->msg);
            return buff;
        } else {
            printf("***Error: Unknow type of error!***");
        }
    }

    return NULL;
}

void errnoi_print(char *filename, int line) {
    char *err_str;
    if ((err_str = errnoi_format()) != NULL) {
        fprintf(stderr, "%s at %s:%d\n", err_str, filename, line);
    }
}
