//
// Created by wojiubaniheiheihei on 2018/9/5.
//

#ifndef CFG_CFG_H
#define CFG_CFG_H

#endif //CFG_CFG_H


int cfgOpen(char *filename);

int cfgGetString(char *pBuffer, char *pKey, char **ppValue);

int cfgClose(void);
//void cfgFilter(char *pInput, char *pOutput, char ignore);
//int cfgStartWith(char *pString, char *pSubString);