#include "utils.h"

int check(int exp , const char *msg) {
    if (exp == -1) {
        perror(msg);
        exit(EXIT_FAILURE);
    }
    return exp;
}
