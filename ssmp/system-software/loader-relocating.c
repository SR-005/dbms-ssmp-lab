#include<stdio.h>
#include<string.h>

char bit[50];       //to store the binary version of bitmask

//funciton to convert hex to binary digits
int convert(char hex[])
{
    bit[0] = '\0';
    int i;
    for(i=0;hex[i];i++)
    {
        if(hex[i]=='0')
        {
            strcat(bit,"0000");
        }
        else if(hex[i]=='1')
        {
            strcat(bit,"0001");
        }
        else if(hex[i]=='2')
        {
            strcat(bit,"0010");
        }
        else if(hex[i]=='3')
        {
            strcat(bit,"0011");
        }
        else if(hex[i]=='4')
        {
            strcat(bit,"0100");
        }
        else if(hex[i]=='5')
        {
            strcat(bit,"0101");
        }
        else if(hex[i]=='6')
        {
            strcat(bit,"0110");
        }
        else if(hex[i]=='7')
        {
            strcat(bit,"0111");
        }
        else if(hex[i]=='8')
        {
            strcat(bit,"1000");
        }
        else if(hex[i]=='9')
        {
            strcat(bit,"1001");
        }
        else if(hex[i]=='A'||hex[i]=='a')
        {
            strcat(bit,"1010");
        }
        else if(hex[i]=='B'||hex[i]=='b')
        {
            strcat(bit,"1011");
        }
        else if(hex[i]=='C'||hex[i]=='c')
        {
            strcat(bit,"1100");
        }
        else if(hex[i]=='D'||hex[i]=='d')
        {
            strcat(bit,"1101");
        }
        else if(hex[i]=='E'||hex[i]=='e')
        {
            strcat(bit,"1110");
        }
        else if(hex[i]=='F'||hex[i]=='f')
        {
            strcat(bit,"1111");
        }
    }
}

int main()
{
    FILE *in,*out;
    in=fopen("RLIN.txt","r");       //Open the input file in read mode
    out=fopen("RLOUT.txt","w");     //Open the output file in write mode

    int i,startingaddress,address,opcode,actual,len;   
    char type[2],mask[12],reloc;
    printf("Enter the Starting Address: "); //input the starting address and store it
    scanf("%x",&startingaddress);

    while(fscanf(in,"%s",type)==1 && strcmp(type,"E")!=0)   //reads the record and stores in type- a record ends with E, so fetch each string until it comes accross E
    {
        if(strcmp(type,"T")==0)         //checks if we are in text record
        {
            fscanf(in, "%x %x %s", &address, &len, mask);   //fetch address,lenght of record and mask from record
            address=startingaddress+address;    //adjust the current address with the starting address
            convert(mask);      //convert the mask into decimal-function call

            for(i=0;i<strlen(bit);i++)      //loop until the number of bits in 'bit'-> The result of converting mask to decimal
            {
                if(fscanf(in,"%x %x",&opcode, &actual)!=2)  //read opcode and actuall from text record, returns 2 if both values are read
                {
                    break;  //break if the return is not 2 i.e, if read fails
                }
                reloc=bit[i];   //take the ith value from bit (synchronized with number of loops)
                if(reloc=='1')  // if it is 1, relocation is needed
                {
                    actual=startingaddress+actual;  //add the actual with starting address for relocation
                }
                fprintf(out,"%X\t%X%X\n",address,opcode,actual);    //print the address,opcode and actual to output file
                address=address+3;      //increment address to point to next
            }
        }
        fprintf(out, "-----------------------------\n");
        fclose(in);
        fclose(out);
        printf("\nRelocation done → check RLOUT.txt\n");
        return 0;
    }
}