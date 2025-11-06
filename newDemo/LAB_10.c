#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *sourceFile, *destFile;
    char sourceName[100], destName[100];
    char ch;

    // Input file names
    printf("Enter the name of the source file: ");
    scanf("%s", sourceName);

    printf("Enter the name of the destination file: ");
    scanf("%s", destName);

    // Open source file in read mode
    sourceFile = fopen(sourceName, "r");
    if (sourceFile == NULL)
    {
        printf("Error: Cannot open source file '%s'.\n", sourceName);
        exit(1);
    }

    // Open destination file in write mode
    destFile = fopen(destName, "w");
    if (destFile == NULL)
    {
        printf("Error: Cannot open destination file '%s'.\n", destName);
        fclose(sourceFile);
        exit(1);
    }

    // Copy contents from source to destination
    while ((ch = fgetc(sourceFile)) != EOF)
    {
        fputc(ch, destFile);
    }

    printf("File copied successfully from '%s' to '%s'.\n", sourceName, destName);

    // Close files
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}