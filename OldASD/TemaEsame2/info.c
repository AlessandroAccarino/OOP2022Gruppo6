#include "info.h"
#include <stdio.h>


/* 
 * Operazioni su TInfo
 */

bool info2_equals (TInfo2 info1, TInfo2 info2) {
    return 0==strcmp(info1.key, info2.key);
}

bool info2_greater (TInfo2 info1, TInfo2 info2) {
    return strcmp(info1.key, info2.key)>0;
}

bool info2_less (TInfo2 info1, TInfo2 info2) {
    return  !info2_greater(info1, info2) && !info2_equals(info1, info2);
}

void info2_print (TInfo2 info) {
    printf ("(%s:%llu) ", info.key, info.value);
}



bool info1_equals (TInfo1 info1, TInfo1 info2) {
    return 0==strcmp(info1, info2);
}

bool info1_greater (TInfo1 info1, TInfo1 info2) {
    return strcmp(info1, info2)>0;
}

bool info1_less (TInfo1 info1, TInfo1 info2) {
    return  !info1_greater(info1, info2) && !info1_equals(info1, info2);
}

void info1_print (TInfo1 info) {
    printf ("(%s) ", info);
}
