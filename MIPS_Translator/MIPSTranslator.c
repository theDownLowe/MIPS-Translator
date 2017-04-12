// Trevor N. Lowe
// TCSS 372 - Mini Couse Project
// This program simulates the MIPS computer by translating
//    assembly to binary and then performs those instructions.
// This program assumes MIPS has 32 bit instructions and contains
//    only those instructions as defined on:
//    http://alumni.cs.ucr.edu/~vladimir/cs161/mips.html
// This program assumes those asswmbly instructions loaded do not
//    contain labels(symbols).

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Constants
#define I_SIZE 32 // Size of MIPS Binary Instruction
#define OP_LEN 5 // Max length of MIPS Assembly Op code
#define TOK_LEN 10 // Max length of MIPS assembly tokens

// Prototypes
int* translateCode(char* assembly);


int main() {

   int reg[32][32]; // 32 registers each of 32 bits. Each int is 0 or 1.

   
// 1) Load Assembly Code
// 2) Translate Assembly Code
   // a) create a new array
   // b) Add chars to the array until you get \n
   // c) Translate the assembly code
   // d) Store assembly code to some kind of list
// 3) Store Mcahine Code in I-Mem (Instruction Memory)
// 4) Store Data in D-Mem
// 5) Display I-Mem, D-mem, and Registers similar to LC-3 or QTSpim
// 6) Implement the datapath/pipeline
// 7) Controlled by PC, fetch instructions one by one and run each
//       through the pipeline
// 8) Store sum back to D-mem

   //char* ac1 = malloc(sizeof(int) * 32);
   //char* ac2 = malloc(sizeof(int) * 32);

   char ac1[] = {'a','d','d',' ','$','t','0',',',' ','$','t','0',',',' ','$','t','0'};
   char ac2[] = {' ','s','u','b',' ','$','t','1',',',' ','$','t','1',',',' ','$','t','1'};

   int* bin1 = translateCode(ac1);
   int* bin2 = translateCode(ac2);
   
   free(bin1);
   free(bin2);
   
   printf("\n\nEND");
   
   return 0;
}

int* translateCode(char* assembly) {

   // Initialize Array
   int *bin;
   bin = (int *)malloc(sizeof(int) * I_SIZE);
   
   char op[OP_LEN];
   
   // Finds the start of the lines statement
   int i = 0;
   while (assembly[i] == ' ') {
      i++;
   }
   // Copys operator to op array
   int index = 0;
   while (assembly[i] != ' ') {
      op[index] = assembly[i];
      i++;
      index++;
   }
   index++;
   // Nulls out unused indices
   while (i < OP_LEN) {
      op[i] = 0;
      i++;
   }
   
   
   
   // Note: Dashes in the following comments represent unchecked char's
   //          rather than the char '-'.
                                                      // op =
                                                      // "-----"
   
   // Arithmetic and Logical Instructions
   
   if (op[0] == 'a') {                                // "a----"
      if (op[1] == 'd') {                             // "add--"
         if (op[3] == 0) {                            // "add" 100000
            bin[0] = 1;
            bin[1] = 0;
            bin[2] = 0;
            bin[3] = 0;
            bin[4] = 0;
            bin[5] = 0;
            // 3 registers
         }
         else if (op[3] == 'u') {                     // "addu" 100001
            bin[0] = 1;
            bin[1] = 0;
            bin[2] = 0;
            bin[3] = 0;
            bin[4] = 0;
            bin[5] = 1;            
            // 3 registers           
         }
         else if (op[5] == 0) {                       // "addi" 001000
            bin[0] = 0;
            bin[1] = 0;
            bin[2] = 1;
            bin[3] = 0;
            bin[4] = 0;
            bin[5] = 0;            
            // 2 registers, 1 long  
         }
         else {                                       // "addiu" 001001
            bin[0] = 0;
            bin[1] = 0;
            bin[2] = 1;
            bin[3] = 0;
            bin[4] = 0;
            bin[5] = 1;
            // 2 registers. 1 unsigned long                               
         }
      }
      else if (op[3] == 0) {                          // "and" 100100
         bin[0] = 1;
         bin[1] = 0;
         bin[2] = 0;
         bin[3] = 1;
         bin[4] = 0;
         bin[5] = 0;
         // 3 registers                                 
      } 
      else {                                          // "andi" 001100
         bin[0] = 0;
         bin[1] = 0;
         bin[2] = 1;
         bin[3] = 1;
         bin[4] = 0;
         bin[5] = 0;                            
      }
   }
   else if (op[0] == 'd') {                           // "div--"
      if (op[3] == 0) {                               // "div" 011010
         bin[0] = 0;
         bin[1] = 1;
         bin[2] = 1;
         bin[3] = 0;
         bin[4] = 1;
         bin[5] = 0; 
      }
      else {                                          // "divu" 011011
         // divu (011011)
      }
   } 
   else if (op[0] == 'm' && op[1] == 'u') {           // "mult--"
      if (op[4] == 0) {                               // "mult" 011000
         // mult (011000)
      } 
      else {                                          // "multu" 011001
         // multu (011001)
      }
   }
   else if (op[0] == 'n') {                           // "nor" 100111
      // nor (100111)
   }
   else if (op[0] == 'o') {                           // "or---"
      if (op[2] == 0) {                               // "or" 100101
         // or (100101)
      }
      else {                                          // "ori" 001101
         // ori (001101)
      }
   }
   else if (op[0] == 's' && op[1] == 'l'
            && op[2] == 'l') {                        // "sll--"
      if (op[3] == 0) {                               // "sll" 000000
         // sll (000000)     
      }
      else {                                          // "sllv" 000100
         // sllv (000100) 
      }
   }
   else if (op[0] == 's' && op[1] == 'r') {           // "sr---"
      if (op[2] == 'a' && op[3] == 0) {               // "sra" 000011
         // sra (000011)
      }
      else if (op[2] == 'a') {                        // "srav" 000111
         // srav (000111)
      }
      else if (op[2] == 'l' && op[3] == 0) {
         // srl (000010)                              // "srl" 000010
      }
      else {
         // srlv (000110)                             // "srlv" 000110
      }
   }
   else if (op[0] == 's' && op[1] == 'u') {           // "sub--"
      if (op[3] == 0) {                               // "sub" 100010
         // sub (100010)
      }
      else {                                          // "subu" 100011
         // subu (100011)
      }
   }
   else if (op[0] == 'x') {                           // "xor--"
      if (op[3] == 0) {                               // "xor" 100110
         // xor (100110)
      }
      else {                                          // "xori" 001110
         // xori (001110)
      }
   }
   
   
   // Constant-Manipulation Instructions
   
   else if (op[0] == 'l' && op[1] == 'h'
            && op[2] == 'i') {                        // "lhi" 011001
      // lhi (011001)
   }
   else if (op[0] == 'l' && op[1] == 'l') {           // "llo" 011000
      // llo (011000)
   }
   
   
   // Comparison Instructions
   
   else if (op[0] == 's' && op[1] == 'l') {           // "slt--" 
      if (op[3] == 0) {                               // "slt" 101010
         // slt (101010)   
      }
      else if (op[3] == 'u') {                        // "sltu" 101001
         // sltu (101001
      }
      else if (op[4] == 0) {                          // "slti" 001010
         // slti (001010)
      }
      else {                                          // "sltiu" 001001
         // sltiu (001001)
      }
   }   
   
   
   // Branch Instructions
   
   else if (op[0] == 'b') {                           // "b----"
      if (op[1] == 'e') {                             // "beq" 000100                         
         // beq (000100)
      }
      else if (op[1] == 'g') {                        // "bgtz" 000111
         // bgtz (000111)
      }
      else if (op[1] == 'l') {                        // "blez" 000110
         // blez (000110)
      }
      else {                                          // "bne" 000101
         // bne (000101)
      }
   }
   

   // Jump Instructions
   
   else if (op[0] == 'j') {                           // "j----"
      if (op[1] == 0) {                                // "j" 000010
         // j (000010)
      }
      else if (op[1] == 'a' && op[3] == 0) {          // "jal" 000011
         // jal (000011)
      }
      else if (op[1] == 'a') {                        // "jalr" 001001
         // jalr (001001)
      }
      else {                                          // "jr" 001000
         // jr (001000)
      }
   }

   
   // Load Instructions
   
   else if (op[0] == 'l') {                           // "l----"
      if (op[1] == 'b' && op[2] == 0) {               // "lb" 100000
         // lb (100000)
      } 
      else if (op[1] == 'b') {                        // "lbu" 100100
         // lbu (100100)
      }
      else if (op[1] == 'h' && op[2] == 0) {          // "lh" 100001
         // lh (100001)
      }
      else if (op[1] == 'h'){                         // "lhu" 100101
         // lhu (100101)
      }
      else {                                          // "lw" 100011
         // lw (100011)
      }
   }
   
   
   // Store Instructions
   
   else if (op[0] == 's') {                           // "s----"
      if (op[1] == 'b') {                             // "sb" 101000
         // sb (101000)
      }
      else if (op[1] == 'h') {                        // "sh" 101001
         // sh (101001)
      }
      else {                                          // "sw" 101011
         // sw (101011)
      }
   }
   
   
   // Data Movement Instructions
   
   else if (op[0] == 'm') {                           // "m----"
      if (op[1] == 'f' && op[2] == 'h') {             // "mfhi" 010000
         // mfhi (010000)
      }
      else if (op[1] == 'f') {                        // "mflo" 010010
         // mflo (010010)
      }
      else if (op[2] == 'h') {                        // "mthi" 010001
         // mthi (010001)
      }
      else {                                          // "mtlo" 010011
         // mtlo (010011)
      }
   }

   
   // Exception and Interrupt Instructions
   
   else {                                             // "trap" 011010
      // trap (011010)
   }
   
   return bin;
}
