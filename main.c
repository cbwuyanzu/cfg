#include <stdio.h>
#include <mem.h>
#include "cfg.h"


int main(int argc, char *argv[]) {
    char buff[300];
    char *pValue;
    for (int i = 0; i < argc; i++) {
        printf("arg[%d]is[%s]\n", i, argv[i]);
    }
    if (argc >= 2) {
        cfgOpen(argv[1]);
        for (int j = 2; j < argc; j++) {
            cfgGetString(buff, argv[j], &pValue);
            printf("%s is %s\n", argv[j], pValue);
        }
    }
    printf("%d", cfgClose());
    return 0;
}


