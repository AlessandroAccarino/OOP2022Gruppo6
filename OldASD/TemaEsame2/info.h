#ifndef INFO_H
#define INFO_H

#include <stdbool.h>
#include <string.h>

#define SURNAME_LEN 50
    
typedef char TKey[SURNAME_LEN];
typedef unsigned long long TValue;

typedef char* TInfo1;

struct SInfo {
    TKey key;
    TValue value;
};
typedef struct SInfo TInfo2;
/* Operazioni su TInfo */
bool info1_equals (TInfo1, TInfo1);
bool info1_greater (TInfo1, TInfo1);
bool info1_less (TInfo1, TInfo1);
void info1_print (TInfo1);

bool info2_equals (TInfo2, TInfo2);
bool info2_greater (TInfo2, TInfo2);
bool info2_less (TInfo2, TInfo2);
void info2_print (TInfo2);



#endif /* INFO_H */

