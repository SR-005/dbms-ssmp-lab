#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int hextodecimal(char c)
{
    return 0;
}

int main()
{
    FILE *inputfile;
    int headeraddress=0,textaddress=0;
    inputfile=fopen("input1.txt","r");
    
    
    char line[200];
    fgets(line,sizeof(line),inputfile);
    headeraddress=(int)strtol(line+7,NULL,16);
    printf("Header Address: %d",headeraddress);

    while(fgets(line,sizeof(line),inputfile))
    {
        if(line[0]=='E')
        {
            break;
        }
        if(line[0]=='T')
        {
            break;
        }

    }

}