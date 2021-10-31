#include <stdio.h>
#include "files.h"

FILE *readFile(char *filename) {
    return fopen(filename, "r");
}
