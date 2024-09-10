#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <errno.h>

#ifndef SYS_riscv_flush_icache
    #define SYS_riscv_flush_icache 259 // Syscall number may vary depending on your kernel version.
#endif

int main() {
    // Flush the instruction cache in the address space.
    long result = syscall(SYS_riscv_flush_icache);
    
    if (result == -1) {
        perror("riscv_flush_icache");
        return 1;
    }

    printf("riscv_flush_icache syscall executed successfully\n");
    return 0;
}
