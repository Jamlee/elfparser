#include "elf.h"
#include "stdio.h"

// 读取 Ehdr 并解释每个字段含义
void read_Elf32_Ehdr(FILE *f);

// 读取段表内容
void read_Elf32_Shdr(FILE *f);

// 读取段表中所有类型为重定位表的内容
void read_Elf32_rel(FILE *f);

// 读取段表中所有类型为字符串表的内容
void read_Elf32_str(FILE *f);

// 读取段表中符号表的内容
void read_Elf32_sym(FILE *f);