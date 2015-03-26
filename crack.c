#include <stdio.h>
#include "md5.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("You must supply a hashfile and a dictionary file\n");
        return 1;
    }
    
    FILE *hf, *df;
    hf = fopen(argv[1], "r");
    if (!hf)
    {
        printf("Couldn't open %s for reading\n", argv[1]);
        return 2;
    }
    
    df = fopen(argv[2], "r");
    if (!df)
    {
        printf("Couldn't open %s for reading\n", argv[2]);
        return 3;
    }
    
    char hash[40];
    while (fscanf(hf, "%s", hash) != EOF)
    {
        printf("%s\n", hash);
    }
    
    fclose(hf);
    fclose(df);
}
