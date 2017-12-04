#include <stdio.h>
#include <assert.h>
#include <fcntl.h>

#include "errnoi.h"

int main(int argc, char *argv[]) {
    if (argc <= 1) return 1;
    int fd;
    errnoi_eq_negone((fd = open(argv[1], O_RDONLY)), -1);

    ERRNOI_CLEAN_UP_BEGIN
        errnoi_eq_negone((fd = open(argv[1], O_RDONLY)), -1);
    ERRNOI_CLEAN_UP_END

    return 0;
}
