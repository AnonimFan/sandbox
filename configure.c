#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_MAK "config.mak"

int config_noopts()
{
    FILE *config = fopen(CONFIG_MAK, "w");
    if (config == NULL) {
        return 1;
    }
    fprintf(config, "CC = cc\n");
    fprintf(config, "CFLAGS = -I./include -Wall -std=c99 -D_UNIX -ggdb\n");
   // fprintf(config, "LFLAGS = -lm -lSDL2 -lSDL2_image -lSDL2main -Wall");
    fclose(config);

    printf("compiler: /bin/cc\n");
    printf("linker:   /bin/ld (using cc to link)\n");
    printf("CFLAGS:   -I./include -Wall -std=c99 -D_UNIX -ggdb\n");
   // printf("LFLAGS:   -lm -lSDL2 -lSDL2_image -lSDL2main -Wall\n");
    printf("configured, now you can run \'make\'\n");
    return 0;
}

// arg rule: CC = .. CFLAGS = ... ~~LFLAGS = ...~~ no more lflags
// arg list: 0 = program name, 1,... = arguments
int config_opts(char **args)
{
    FILE *config = fopen(CONFIG_MAK, "w");
    if (config == NULL) {
        return 1;
    }
    fprintf(config, "%s\n", args[1]);
    fprintf(config, "%s\n", args[2]);
  //  fprintf(config, "%s\n", args[3]);
    fclose(config);

    printf("compiler: %s\n", args[1]);
    printf("linker:   /bin/ld (using c compiler to link)\n");
    printf("CFLAGS:   %s\n", args[2]);
    //printf("LFLAGS:   %s\n", args[3]);
    printf("configured, now you can run \'make\'\n");
    return 0;
}

int
main(int argc, char **argv)
{
    if (argc < 2) {
        int ret = config_noopts();
        return ret;
    } else {
        int ret = config_opts(argv);
        return ret;
    }
}
