// Trevor Lowe
// This program translates MIPS assembly code and simulates
//    the MIPS computer.
// This program assumes the assembly code is less than 256 lines long.


// Libraries
#include <stdio.h>
#include <stdlib.h>

int main() {

   int iMem[256][32]; // 256 instructions; each 32 bits long
   int dMem[256][32]; // 256 data storage locations; each 32 bits long
   int reg[32][32]; // 32 registers; each 32 bits long

   // 1) Load Assembly Code
   char assembly[256][32]; 
   char line[32];
   FILE* aCode = fopen("assemblyCode.txt", "r");
   int inum = 0;
   while (fgets(line, 32, aCode) != '\0') {
      sscanf(line);
      int i;
      for (i = 0; i < 32; i++) {
         assembly[inum][i] = line[i];
      }
      inum++;
   }
   fclose(aCode);
   
   
   // 2) Translate Assembly Code
   
   while ()
   // add
   
   // lw
   
   // sw
   
   // 3) Store Mcahine Code in I-Mem (Instruction Memory)
   // 4) Store Data in D-Mem
   // 5) Display I-Mem, D-mem, and Registers similar to LC-3 or QTSpim
   // 6) Implement the datapath/pipeline
   // 7) Controlled by PC, fetch instructions one by one and run each
   //       through the pipeline
   // 8) Store sum back to D-mem
   
   
   printf("\n\nEND");
   return 0;
}