#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//to convert hexadecimal to corresponding decimal character
int hextodecimal(char c)
{
    if(c>='0'&&c<='9')
    {
        return c-'0';
    }
    if(c>='A'&&c<='F')
    {
        return 10+(c-'A');
    }
    if(c>='a'&&c<='f')
    {
        return 10+(c-'a');
    }
    return 0;
}

int main()
{
    FILE *inputfile;
    int i,value,headeraddress=0,textaddress=0;
    inputfile=fopen("input1.txt","r");      //open the input file
    if(inputfile==NULL)
    {
        printf("No Input File Found!");
        return 0;
    }
    
    char line[200];             //for reading each line
    fgets(line,sizeof(line),inputfile);         //read the first line of input file (i.e, Header)
    headeraddress=(int)strtol(line+7,NULL,16);  //convert the hexadecimal address into Decimal, read the line from 7th character onwards
    printf("Header Address: %d\n",headeraddress);

    while(fgets(line,sizeof(line),inputfile))   //read rest of the input file (Text Record)
    {
        if(line[0]=='E')        //if line starts with 'E'-> end of Text Record
        {
            break;
        }
        if(line[0]=='T')        //if line starts with 'T'-> convert it
        {
            textaddress=(int)strtol(line+2,NULL,16);  //starting address of text record, convert the hexadecimal address to Decimal, read from the 2nd character onwards

            for(i=12;line[i]!='\0' && line[i]!='\n';i=i+2)  //for each set(2) of character in the current line-proccess it and inc 2, until it is \0 or \n
            {
                if(line[i]=='^')    //if the character is ^, you dont need to process the character, so to skip that, we decrement i
                {
                    i--;
                    continue;
                }
                value=hextodecimal(line[i])*16 + hextodecimal(line[i+1]);   //convert the first character in set to decimal and x16 and add to next character in set after converting it too
                printf("%04x : %02x\n",textaddress,value);      //print the address and value
                textaddress++;      //increment text address
            }
        }
    }
    printf("Loading Finished");
    fclose(inputfile);
}