#include "mmc.h"
#include "cpu-internal.h"
#include "ppu.h"

CPU_STATE cpu;

byte CPU_RAM[0x8000];

byte op_code;             // Current instruction code
int op_value, op_address; // Arguments for current instruction
int op_cycles;            // Additional instruction cycles used (e.g. when paging occurs)

unsigned long long cpu_cycles;  // Total CPU Cycles Since Power Up (wraps)

void (*cpu_op_address_mode[256])();       // Array of address modes
void (*cpu_op_handler[256])();            // Array of instruction function pointers
bool cpu_op_in_base_instruction_set[256]; // true if instruction is in base 6502 instruction set
char *cpu_op_name[256];                   // Instruction names
int cpu_op_cycles[256];                   // CPU cycles used by instructions


byte mmc_id;


byte PPU_SPRRAM[0x100];
byte PPU_RAM[0x4000];
