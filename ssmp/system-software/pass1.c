#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char opcode[20],label[20],operand[20];  //to hold data from input.txt
    char opcodeOp[20],opcodeCode[20];       //to read data from optab.txt
    int locctr=0,startaddress=0,length=0,address=0;    //location counter, startingaddress, 
    FILE *optab,*symtab,*inputfile,*intermediate,*lengthfile;

    //open files- input,optab in read mode and symtab,intermediate,lengthfile in write mode
    inputfile=fopen("input.txt","r");
    optab=fopen("optab.txt","r");
    symtab=fopen("symtab.txt","w");
    intermediate=fopen("intermediate.txt","w");
    lengthfile=fopen("length.txt","w");

    if(inputfile==NULL||symtab==NULL||optab==NULL||intermediate==NULL||lengthfile==NULL)
    {
        printf("File Error");
        return 0;
    }

    //WRITE INTERMEDIATE FILE
    fscanf(inputfile,"%s %s %d",label,opcode,&address);     //read first line of inputfile-format label,opcode,address
    if(strcmp(opcode,"START")==0)       //check if the line is first line itself
    {
        startaddress=address;       //make the address->startingaddress
        locctr=startaddress;        //make the location->starting address
        fprintf(intermediate,"%d\t%s\t%s\t%d\n",locctr,label,opcode,startaddress);   //write to intermediate file showing locctr,label,opcode and address
    }

    while(fscanf(inputfile,"%s %s %s",label,opcode,operand)!=EOF)   //read the next lines of input.txt- format as label,opcode,operand
    {
        fprintf(intermediate,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);   //write those into intermediate includeing locctr-location address

        if(strcmp(label,"**")!=0)       //if label is not ** then it is a symbol, so we write it to symtab
        {
            fprintf(symtab,"%s\t%d\n",label,locctr);    //write the label and its location to symtab
        }

        int found=0;        
        rewind(optab);      //we start to read optab from start

        while(fscanf(optab,"%s %s",opcodeOp,opcodeCode)!=EOF)   //read each line from optab- operation and code    
        {
            if(strcmp(opcode,opcodeOp)==0)      //if the current input line's opcode is in optab(opcodeOp)
            {
                locctr=locctr+3;    //increment locctr 
                found=1;    //set it as found
                break;
            }
        }

        if(found==0)        //if the opcode is not found in optab then..
        {
            if(strcmp(opcode,"WORD")==0)    //if opcode is WORD
            {
                locctr=locctr+3;
            }
            else if(strcmp(opcode,"RESW")==0)   //if opcode is RESW
            {
                locctr=locctr+3*atoi(operand);
            }
            else if(strcmp(opcode,"RESB")==0)   //if opcode is RESB
            {
                locctr=locctr+atoi(operand);
            }
            else if(strcmp(opcode,"BYTE")==0)   //if opcode is BYTE
            {
                locctr=locctr+strlen(operand)-3;
            }
            else if(strcmp(opcode,"END")==0)    //if opcode is END, break
            {
                break;
            }
        }
    }

    length=locctr-startaddress;         //length is current location address - starting address
    fprintf(lengthfile,"%d",length);    //write it to lengthfile

    fclose(inputfile);
    fclose(symtab);
    fclose(optab);
    fclose(intermediate);
    fclose(lengthfile);
    printf("Pass1 Completed!!");
    return 0;
}