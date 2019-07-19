#include "stdio.h"
#include "color.h"
#include "elf.h"
#include "elf32.h"

int main() {
    FILE *fp;
    fp = fopen("./hello", "r");
    read_Elf32_Ehdr(fp);
    read_Elf32_Shdr(fp);
    read_Elf32_str(fp);
    read_Elf32_sym(fp);
    
    fclose(fp);
}