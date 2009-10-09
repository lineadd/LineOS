#include <types.h>

int strlen(const unsigned char *string){
        u32 size=0;
        for(size=0; *string!='\0';string++)
                size++;

        return size;
}

