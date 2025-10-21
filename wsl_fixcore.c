/* wsl_fixcore.c - program to reset /proc/sys/kernel/core_pattern to "core.%p"
 * so you get traditional core dumps. For full doc and source, see
 * https://github.com/fordsfords/wsl_fixcore */
/*
# This code and its documentation is Copyright 2020 Steven Ford, http://geeky-boy.com
# and licensed "public domain" style under Creative Commons "CC0": http://creativecommons.org/publicdomain/zero/1.0/
# To the extent possible under law, the contributors to this project have
# waived all copyright and related or neighboring rights to this work.
# In other words, you can use this code for any purpose without any
# restrictions.  This work is published from: United States.  The project home
# is https://github.com/fordsfords/wsl_fixcore
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("/proc/sys/kernel/core_pattern", "w");
    if (!f) { perror("fopen"); return 1; }

    fprintf(f, "core.%%p\n");
    fclose(f);

    return 0;
}
