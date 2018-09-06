//
// Created by wojiubaniheiheihei on 2018/9/5.
//

#include <mem.h>
#include "cfg.h"
#include <stdio.h>
#include <ctype.h>

FILE *cfg;

int cfgOpen(char *filename) {
    cfg = fopen(filename, "r+");
    if (cfg == NULL) {
        perror("fail to open the configuration file.");
        return -1;
    }
    return 0;
}

void cfgFilter(char *pInput, char *pOutput, char ignore) {
    while (*pInput != 0) {
        if (*pInput == ignore) {
            pInput++;
        } else {
            *pOutput++ = *pInput++;
        }
    }
    *pOutput = 0;
}

int cfgStartWith(char *pString, char *pSubString) {
    while (*pSubString != 0) {
        if (toupper(*pString) == toupper(*pSubString)) {
            pString++;
            pSubString++;
        } else {
            return 0;
        }
    }
    return 1;
}

int cfgReadLine(char *pBuffer) {
    do {
        if (fgets(pBuffer, 2048, cfg) == NULL) return -1;
        cfgFilter(pBuffer, pBuffer, ' ');
        cfgFilter(pBuffer, pBuffer, '\n');
        cfgFilter(pBuffer, pBuffer, '\r');
        cfgFilter(pBuffer, pBuffer, '=');
    } while (pBuffer[0] == '#');
    // skip the line starts with '#'
    return 0;
}

/*int cfgGetString(char *pBuffer, char *pKey, char **ppValue) {
    fseek(cfg, 0L, SEEK_SET);
    while (0 == cfgReadLine(pBuffer)) {
        if (cfgStartWith(pBuffer, pKey)) {
            *ppValue = pBuffer + strlen(pKey);
            return 1;
        } else {

        }
    }
    return 0;
}*/
int cfgGetString(char *pBuffer, char *pGroup, char *pKey, char **ppValue) {
    fseek(cfg, 0L, SEEK_SET);
    if (1 == cfgLocateGroup(pBuffer, pGroup)) {

    } else {
        return 0;
    }
    while (0 == cfgReadLine(pBuffer)) {
        if ('[' == pBuffer[0]) {
            return 0;
        }
        if (cfgStartWith(pBuffer, pKey)) {
            *ppValue = pBuffer + strlen(pKey);
            return 1;
        } else {

        }
    }
    return 0;
}

int cfgLocateGroup(char *pBuffer, char *pGroup) {
//    fseek(cfg, 0L, SEEK_SET);
    while (0 == cfgReadLine(pBuffer)) {
        char temp[32];
        sprintf(temp, "[%s]", pGroup);
        if (cfgStartWith(pBuffer, temp)) {
            return 1;
        }
    }
    return 0;
}

int cfgClose(void) {
    if (fclose(cfg) == -1) return -1;
    cfg = NULL;
    return 0;
}