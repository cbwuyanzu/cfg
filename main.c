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
            if (1 == cfgGetString(buff, "THIS", argv[j], &pValue)) {
                printf("THIS %s is %s\n", argv[j], pValue);
            } else {
                printf("[THIS][%s] not found\n", argv[j]);
            }
            if (1 == cfgGetString(buff, "THAT", argv[j], &pValue)) {
                printf("THAT %s is %s\n", argv[j], pValue);
            } else {
                printf("[THAT][%s] not found\n", argv[j]);
            }
        }
    }
    printf("%d", cfgClose());
    return 0;
}


