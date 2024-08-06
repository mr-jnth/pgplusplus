#include <string.h>
#include <memory.h>
#include <time.h>

#ifndef BSDISH
#include <malloc.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <signal.h>

#include "include/proto.h"

#ifndef AUTOSHUTDOWN
extern int auto_shutdown;
#endif

int is_perma_admin(char* name)
{
    char buf[512], *ptr, *sta;
    strncpy(buf, get_config_msg("hcadmin"), 511);

    for (ptr = sta = buf; *ptr; ptr++) {
        if (*ptr == ' ') {
            *ptr++ = 0;
            if (!strcasecmp(name, sta)) {
                return 1;
            }
            sta = ptr;
        }
    }
    if (!strcasecmp(name, sta)) {
        return 1;
    }
    return 0;
}