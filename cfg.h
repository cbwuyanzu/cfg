//
// Created by wojiubaniheiheihei on 2018/9/5.
//

#ifndef CFG_CFG_H
#define CFG_CFG_H

#endif //CFG_CFG_H

/******
 *
 * @param filename
 * @return -1 false
 *          0  success
 */
int cfgOpen(char *filename);

/*****
 *
 * @param pBuffer input stream
 * @param pKey  key in the config file
 * @param ppValue the pointer point to the value
 * @return
 */
//int cfgGetString(char *pBuffer, char *pKey, char **ppValue);
/******
 *
 * @param filename
 * @return -1 false
 *          0  success
 */
int cfgClose(void);

/*****
 *
 * @param pBuffer input stream
 * @param pGroup group name
 * @param pKey  key
 * @param ppValue the pointer point to the value
 * @return
 */
int cfgGetString(char *pBuffer, char *pGroup, char *pKey, char **ppValue);

int cfgLocateGroup(char *pBuffer, char *pGroup);