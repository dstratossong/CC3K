//
// Created by glados on 4/11/15.
//

#include <stdlib.h>
#include <iostream>
#include "RandomUtility.h"

int RandomUtility::get_random_integer(int range) {
    return rand() % range;
}

void RandomUtility::seed() {
    srand((unsigned int) time(NULL));
}
