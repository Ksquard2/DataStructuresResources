#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct instruction { //3 components of the instruction
    uint8_t opcode;
    uint8_t regA;
    uint8_t regBI;
};

struct CPU {
    uint8_t reg[8]; //register
    int pc; //program counter
};

int binToDec(char binary[8]){
    int result = 0;
    int scale = 1;
    for(int i = 0;i < 8;i++){
        if(binary[i] == '1'){
            result+=scale;
        }
        scale*=2;
    }
    return result;
}
int assembler(char* action, char* reg1, char* reg2){
    int result  = 0;
    if(!strcmp(action,"AND")){
        result+=64;
    }
    else if(!strcmp(action,"MOV")){
        result+=128;
    }
    else if(!strcmp(action,"JMP")){

        result+=192;
    }
    result+=(atoi(&reg1[1])<<3);
    result+=atoi(&reg2[1]);
    return result;
}

struct instruction decode(int dec){
    struct instruction i;
    i.opcode = dec >> 6; //bit shifting
    i.regA   = (dec >> 3) & 7; //bit masking and shifting
    i.regBI  = dec & 7; //bit masking
    return i;
}

struct CPU* createCPU(){
    struct CPU *myCPU = malloc(sizeof(struct CPU));
    srand((int)time(NULL));
    for (int i = 0; i < 8; i++){
        uint8_t x = rand() % 20; 
        myCPU->reg[i] = x;
    }
    myCPU->pc = 0;
    return myCPU;//you have to return a pointer so that you can pass the address when you execute and print
}

void decToBin(int dec){
    FILE *foutput = fopen("output.txt", "a");
    fprintf(foutput, "Binary: "); 
    char binary[9];//turns decimal into binray string
    for (int i = 0; i < 8; i++){
        binary[i] = '0';
    }
    binary[8] = '\0';

    int index = 7;
    while (dec != 0 && index >= 0) {
        binary[index] = (dec % 2) + '0';
        index--;
        dec /= 2;
    }

    for (int i = 0; i < 8; i++){
        if (i == 2 || i == 5){
            fprintf(foutput, " ");
        }
        fprintf(foutput, "%c", binary[i]);
    }
    fprintf(foutput, "\n");
    fclose(foutput);
}

void displayCPU(struct CPU *myCPU){//must pass as a pointer to ensure authentic addressing
    FILE *foutput = fopen("output.txt", "a"); 
    fprintf(foutput, "CPU\n");
    fprintf(foutput, "Registers: ");
    for (int i = 0; i < 8; i++){
        fprintf(foutput, "%p: %d",
                (void*)&myCPU->reg[i],
                myCPU->reg[i]);
        if (i != 7){
            fprintf(foutput, ", ");
        }
    }
    fprintf(foutput, "\nProgram Counter: %d\n", myCPU->pc);

    fclose(foutput);
}

void displayInstr(struct instruction i, int dec){
    FILE *foutput = fopen("output.txt", "a"); 
    fprintf(foutput, "Instruction\n");
    fclose(foutput);  
    decToBin(dec);

    foutput = fopen("output.txt", "a");
    if (!foutput) {
        perror("Failed to open output.txt");
        return;
    }

    fprintf(foutput, "Opcode: ");
    switch (i.opcode){
        case 0: 
            fprintf(foutput, "ADD"); 
            break;
        case 1: 
            fprintf(foutput, "AND"); 
            break;
        case 2: 
            fprintf(foutput, "MOV"); 
            break;
        case 3: 
            fprintf(foutput, "JMP"); 
            break;
        default: fprintf(foutput, "Stop"); break;
    }

    if (i.opcode != 3){
        fprintf(foutput, " Register A: %d", i.regA);
    }
    if (i.opcode < 2){
        fprintf(foutput, " Register B: %d\n", i.regBI);
    } else {
        fprintf(foutput, " Immediate: %d\n", i.regBI);
    }

    fclose(foutput);
}

void execute(struct CPU *myCPU, int inst){
    struct instruction i = decode(inst);
    switch (i.opcode){
        case 0: 
            myCPU->reg[i.regA] += myCPU->reg[i.regBI];
            break;
        case 1:
            myCPU->reg[i.regA] &= myCPU->reg[i.regBI];
            break;
        case 2: 
            myCPU->reg[i.regA]  = i.regBI;
            break;
        case 3:
            myCPU->pc += i.regBI;
            break;
    }

    if (i.opcode != 3){
        myCPU->pc++;
    }

    displayCPU(myCPU);
    displayInstr(i, inst);
}

char* decToBin2(int dec){
    static char binary[9] = {'0','0','0','0','0','0','0','0','\0'};
    int index = 7;
    while (dec != 0 && index >= 0) {
        binary[index] = (dec % 2) + '0';
        index--;
        dec /= 2;
    }
    return binary;
}
int main(){
    FILE *foutput = fopen("output.txt", "w");
    fclose(foutput);
    struct CPU *myCPU = createCPU();
    displayCPU(myCPU);
    execute(myCPU, assembler("MOV","R0","#3"));
    execute(myCPU, assembler("ADD","R0","R1"));
    execute(myCPU, 21);
    execute(myCPU, 65);
    execute(myCPU, 92);
    execute(myCPU, 128);
    execute(myCPU, 146);
    execute(myCPU, 193);
    execute(myCPU, 212);
    free(myCPU);
    return 0;
}
