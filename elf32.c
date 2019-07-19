#include "elf32.h"
#include "color.h"
#include "stdlib.h"

void read_Elf32_Ehdr(FILE *fp) {
    
    printf("\n");
    printf(GRAY"##############################################################################################\n"NONE);
    printf("\n");
    printf(GRAY" 展示 ELF32文件内容 之 ELF头(Ehdr) 结构\n");
    printf("\n");
    printf(GRAY"##############################################################################################\n"NONE);


    Elf32_Ehdr ehdr;
    fseek(fp, 0, 0);
    fread(&ehdr, sizeof(ehdr), 1, fp);

    printf("\n\n");

    // e_ident
    printf(L_BLACK"// elf32.e_ident"NONE);
    printf("\n"L_RED"[16字节] "NONE""GRAY"elf32.e_ident"NONE);
    printf("\n  "L_BLACK"// 表示 'DEL' 'E' 'L' 'F' 的ANSI 值"NONE);
    printf("\n  "L_BLUE"[00-03]: 0x%02x 0x%02x 0x%02x 0x%02x" NONE, ehdr.e_ident[0], ehdr.e_ident[1],
        ehdr.e_ident[2], ehdr.e_ident[3]);
    printf("\n  "L_BLACK"// 04： 指示ELF文件类型， 0 表示无效文件类型， 1 表示elf32文件类型, 2 表示elf64文件类型"NONE);
    printf("\n  "L_BLACK"// 05： 指示字节序, 0 表示无效格式， 1 表示小端序, 2 表示大端序"NONE);
    printf("\n  "L_BLACK"// 06： 指示ELF主版本, ELF自1.2之后未更新，没有太大意义"NONE);
    printf("\n  "L_BLUE"[04-06]: 0x%02x 0x%02x 0x%02x" NONE, ehdr.e_ident[4], ehdr.e_ident[5],
        ehdr.e_ident[6]);
    printf("\n  "L_BLACK"// 后面9个字节ELF标准没有定义，一般是0,有些系统会使用后面9位作为扩展标志"NONE);
    printf("\n  "L_BLUE"[07-15]: 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x" NONE, 
        ehdr.e_ident[7], ehdr.e_ident[8], ehdr.e_ident[9], ehdr.e_ident[10],
        ehdr.e_ident[11], ehdr.e_ident[12], ehdr.e_ident[13], ehdr.e_ident[14], 
        ehdr.e_ident[15]);
    printf("\n\n");


    // e_type
    printf(L_BLACK"// elf32.e_type 可使用的常量以 'ET' 开头，如下所示\n"NONE);
    printf(L_BLACK"\
    #define ET_NONE     0		/* No file type */ \n\
    #define ET_REL      1		/* Relocatable file */\n\
    #define ET_EXEC     2		/* Executable file */\n\
    #define ET_DYN      3		/* Shared object file */\n\
    #define ET_CORE     4		/* Core file */\n\
    #define ET_NUM      5		/* Number of defined types */\n\
    #define ET_LOOS     0xfe00		/* OS-specific range start */\n\
    #define ET_HIOS     0xfeff		/* OS-specific range end */\n\
    #define ET_LOPROC   0xff00		/* Processor-specific range start */\n\
    #define ET_HIPROC   0xffff		/* Processor-specific range end */\
    "NONE);
    printf(L_BLACK"\n// ELF 包括：可执行文件、可重定位文件、动态库、coredump\n"NONE);
    printf(L_RED"[2字节] "NONE""GRAY"elf32.e_type"NONE);
        printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_type);
    printf("\n\n");


    // e_machine
    printf(L_BLACK"// elf32.e_machine 可使用的常量以 'EM'\n"NONE);
    printf(L_BLACK"// 常用的 EM_386=3, EM_X86_64=62\n"NONE);
    printf(L_RED"[2字节] "NONE""GRAY"elf32.e_machine"NONE);
        printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_machine);
    printf("\n\n");

    printf(L_BLACK"// elf32.e_version ELF 版本号，在 e_ident 中也有存在 'EM'\n"NONE);
    printf(L_RED"[4字节] "NONE""GRAY"elf32.e_version"NONE);
        printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_version);
    printf("\n\n");

    printf(L_BLACK"// elf32.e_entry 程序入口的偏移地址\n"NONE);
    printf(L_RED"[4字节] "NONE""GRAY"elf32.e_entry"NONE);
        printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_entry);
    printf("\n\n");
    
    printf(L_BLACK"// elf32.e_phoff program header 的入口\n"NONE);
    printf(L_RED"[4字节] "NONE""GRAY"elf32.e_phoff"NONE);
    printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_phoff);
    printf("\n\n");

    printf(L_BLACK"// elf32.e_shoff program header 的入口\n"NONE);
    printf(L_RED"[4字节] "NONE""GRAY"elf32.e_shoff"NONE);
    printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_shoff);
    printf("\n\n");
    
    printf(L_BLACK"// elf32.e_flags 处理相关的标志 的入口\n"NONE);
    printf(L_RED"[4字节] "NONE""GRAY"elf32.e_flags"NONE);
    printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_flags);
    printf("\n\n");

    printf(L_BLACK"// elf32.e_flags 处理相关的标志 的入口\n"NONE);
    printf(L_RED"[4字节] "NONE""GRAY"elf32.e_flags"NONE);
    printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_flags);
    printf("\n\n");

    printf(L_BLACK"// ehdr 的大小（字节单位）\n"NONE);
    printf(L_RED"[2字节] "NONE""GRAY"elf32.e_ehsize"NONE);
    printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_ehsize);
    printf("\n\n");

    printf(L_BLACK"// program header 的每个条目大小（字节单位）\n"NONE);
    printf(L_RED"[2字节] "NONE""GRAY"elf32.e_phentsize"NONE);
    printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_phentsize);
    printf("\n\n");

    printf(L_BLACK"// program header 的条目数量（字节单位）\n"NONE);
    printf(L_RED"[2字节] "NONE""GRAY"elf32.e_phnum"NONE);
    printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_phnum);
    printf("\n\n");

    printf(L_BLACK"// section header 的每个条目大小（字节单位）\n"NONE);
    printf(L_RED"[2字节] "NONE""GRAY"elf32.e_shentsize"NONE);
    printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_shentsize);
    printf("\n\n");

    printf(L_BLACK"// section header 的条目数量（字节单位）\n"NONE);
    printf(L_RED"[2字节] "NONE""GRAY"elf32.e_shnum"NONE);
    printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_shnum);
    printf("\n\n");

    printf(L_BLACK"// 段表字符串表（shstrtab）段在段（section)表中的下标， readelf -h xx 中第一列\n"NONE);
    printf(L_RED"[2字节] "NONE""GRAY"elf32.e_shstrndx"NONE);
    printf("\n  "L_BLUE"0x%04x" NONE, ehdr.e_shstrndx);
    printf("\n\n");
}

void read_Elf32_Shdr(FILE *fp) {
    Elf32_Ehdr ehdr;
    fseek(fp, 0, 0);
    fread(&ehdr, sizeof(ehdr), 1, fp);
    
    printf("\n");
    printf(GRAY"##############################################################################################\n"NONE);
    printf("\n");
    printf(GRAY" 展示 ELF32文件内容 之 Section Header(Shdr) 结构\n");
    printf("\n");
    printf(GRAY"##############################################################################################\n"NONE);

    Elf32_Shdr* shdr; // 存储 section header
    shdr = malloc(ehdr.e_shnum * sizeof(Elf32_Shdr));
    if (fseek(fp, ehdr.e_shoff, SEEK_SET) == 0) {
        fread(shdr, sizeof(Elf32_Shdr), ehdr.e_shnum, fp);
    }

    Elf32_Shdr shstrtab; // 段表字符串表内容
    char* shstrtab_content;
    shstrtab = shdr[ehdr.e_shstrndx];
    shstrtab_content = malloc(shstrtab.sh_size);
    if (fseek(fp, shstrtab.sh_offset, SEEK_SET) == 0) {
        fread(shstrtab_content, 1, shstrtab.sh_size, fp);
        // for (int i = 0; i < shstrtab.sh_size; i++) {
        //     printf("%c", shstrtab_content[i]);
        // }
    }
    printf("%-4s\t%-10s\t%-20s\t%-10s\t%-8s\n", "[NO]", "sh_addr", "sh_name", "sh_size", "sh_type");
    for (int i = 0; i < ehdr.e_shnum; i++) {
        printf("[%2d]\t0x%08x\t%-20s\t0x%-08x\t%x\n", i, shdr[i].sh_addr,
            shstrtab_content + shdr[i].sh_name, shdr[i].sh_size, shdr[i].sh_type);
    }
    free(shstrtab_content);
    free(shdr);
}

void read_Elf32_rel(FILE *fp) {
    Elf32_Ehdr ehdr;
    fseek(fp, 0, 0);
    fread(&ehdr, sizeof(ehdr), 1, fp);
    
    printf("\n");
    printf(GRAY"##############################################################################################\n"NONE);
    printf("\n");
    printf(GRAY" 展示 ELF32文件内容 之 重定位表 结构\n");
    printf("\n");
    printf(GRAY"##############################################################################################\n"NONE);

    Elf32_Shdr* shdr; // 存储 section header
    shdr = malloc(ehdr.e_shnum * sizeof(Elf32_Shdr));
    if (fseek(fp, ehdr.e_shoff, SEEK_SET) == 0) {
        fread(shdr, sizeof(Elf32_Shdr), ehdr.e_shnum, fp);
    }

    Elf32_Shdr shstrtab; // 段表字符串表内容
    char* shstrtab_content;
    shstrtab = shdr[ehdr.e_shstrndx];
    shstrtab_content = malloc(shstrtab.sh_size);
    if (fseek(fp, shstrtab.sh_offset, SEEK_SET) == 0) {
        fread(shstrtab_content, 1, shstrtab.sh_size, fp);
        // for (int i = 0; i < shstrtab.sh_size; i++) {
        //     printf("%c", shstrtab_content[i]);
        // }
    }
    printf("%-4s\t%-10s\t%-20s\t%-10s\t%-8s\n", "[NO]", "sh_addr", "sh_name", "sh_size", "sh_type");
    for (int i = 0; i < ehdr.e_shnum; i++) {
        printf("[%2d]\t0x%08x\t%-20s\t0x%-08x\t%x\n", i, shdr[i].sh_addr,
            shstrtab_content + shdr[i].sh_name, shdr[i].sh_size, shdr[i].sh_type);
    }
    free(shstrtab_content);
    free(shdr);
}

void read_Elf32_str(FILE *fp) {
    Elf32_Ehdr ehdr;
    fseek(fp, 0, 0);
    fread(&ehdr, sizeof(ehdr), 1, fp);
    
    printf("\n");
    printf(GRAY"##############################################################################################\n"NONE);
    printf("\n");
    printf(GRAY" 展示 ELF32文件内容 之 字符串表 结构\n");
    printf("\n");
    printf(GRAY"##############################################################################################\n"NONE);

    Elf32_Shdr* shdr; // 存储 section header
    shdr = malloc(ehdr.e_shnum * sizeof(Elf32_Shdr));
    if (fseek(fp, ehdr.e_shoff, SEEK_SET) == 0) {
        fread(shdr, sizeof(Elf32_Shdr), ehdr.e_shnum, fp);
    }
    // 查找类型为符号表的段
    for (int i = 0;   i < ehdr.e_shnum; i++) {
        if (shdr[i].sh_type == SHT_STRTAB) {
            printf("\n");
            Elf32_Shdr strtab; // 段表字符串表内容
            char* strtab_content;
            strtab = shdr[i];
            strtab_content = malloc(strtab.sh_size);
            if (fseek(fp, strtab.sh_offset, SEEK_SET) == 0) {
                fread(strtab_content, 1, strtab.sh_size, fp);
                for (int i = 0; i < strtab.sh_size; i++) {
                    printf("%c", strtab_content[i]);
                }
            }
            free(strtab_content);
            printf("\n");
        }
    }
    free(shdr);
}

void read_Elf32_sym(FILE *fp) {
    Elf32_Ehdr ehdr;
    fseek(fp, 0, 0);
    fread(&ehdr, sizeof(ehdr), 1, fp);
    
    printf("\n");
    printf(GRAY"##############################################################################################\n"NONE);
    printf("\n");
    printf(GRAY" 展示 ELF32文件内容 之 符号表 结构\n");
    printf("\n");
    printf(GRAY"##############################################################################################\n"NONE);

    Elf32_Shdr* shdr; // 存储 section header
    shdr = malloc(ehdr.e_shnum * sizeof(Elf32_Shdr));
    if (fseek(fp, ehdr.e_shoff, SEEK_SET) == 0) {
        fread(shdr, sizeof(Elf32_Shdr), ehdr.e_shnum, fp);
    }

    // 找到 strtab
    Elf32_Shdr strtab = shdr[ehdr.e_shstrndx - 1];
    char* strtab_content;
    strtab_content = malloc(strtab.sh_size);
    if (fseek(fp, strtab.sh_offset, SEEK_SET) == 0) {
        fread(strtab_content, 1, strtab.sh_size, fp);
        // for (int i = 0; i < strtab.sh_size; i++) {
        //     printf("%c", strtab_content[i]);
        // }
        // 查找类型为符号表的段
        for (int i = 0;   i < ehdr.e_shnum; i++) {
            if (shdr[i].sh_type == SHT_SYMTAB) {
                printf("\n");
                Elf32_Shdr symtab; // 段表字符串表内容
                Elf32_Sym* syms;
                uint32_t count;
                symtab = shdr[i];
                count = symtab.sh_size / symtab.sh_entsize; // 得到条目数量
                syms = malloc(count*sizeof(Elf32_Sym));
                printf("%-4s\t%-10s\t%-20s\n", "[NO]", "sh_addr", "sh_name");
                if (fseek(fp, symtab.sh_offset, SEEK_SET) == 0) {
                    fread(syms, 1, symtab.sh_size, fp);
                    for (int i = 0; i < count; i++) {
                        printf("[%2d]\t0x%08x\t%-10s\n", i, syms[i].st_value, strtab_content + syms[i].st_name);
                        // if (syms[i].st_name!=0) {
                        //     printf("%s\n", strtab_content + syms[i].st_name);
                        // }   
                    }
                }
                free(syms);
                printf("\n");
            }
        }
    }

    free(shdr);
}
