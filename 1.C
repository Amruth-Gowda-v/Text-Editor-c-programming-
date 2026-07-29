#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int breakable=1;


int Create_New_File(){
   char filename[50];

printf("Enter filename: ");
fgets(filename, sizeof(filename), stdin);
filename[strcspn(filename, "\n")] = '\0';

FILE *ptr;
ptr=fopen(filename,"w");

if(ptr==NULL){
   printf("Sry the file could not be created pls try again ");
}
else if (ptr != NULL){
fclose(ptr);
printf("File has been created successfully");
}
return 1;


}
int Open_File()
{
    char line[200];
    char filename[50];

    printf("Enter the name of the file to be opened: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *ptr = fopen(filename, "r");

    if (ptr == NULL)
    {
        printf("ERROR 404: File not found.\n");
        return 0;
    }

    while (fgets(line, sizeof(line), ptr) != NULL)
    {
        printf("%s", line);
    }

    fclose(ptr);
    return 1;
}

  




    




int Append_Text()
{
    char filename[50];
    char line[200];

    printf("Enter the name of the file to be opened: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *ptr = fopen(filename, "a");

    if (ptr == NULL)
    {
        printf("ERROR 404: File not found.\n");
        return 0;
    }

    printf("Please enter the text to append.\n");
    printf("Type :q on a new line to stop.\n");

    while (1)
    {
        fgets(line, sizeof(line), stdin);

        /* Remove the newline added by fgets() */
        line[strcspn(line, "\n")] = '\0';

        /* Stop if the user types :q */
        if (strcmp(line, ":q") == 0)
        {
            break;
        }

        fprintf(ptr, "%s\n", line);
    }

    fclose(ptr);

    printf("The text has been appended successfully.\n");

    return 1;
}

int Search_Word()
{
    char filename[50];
    char line[200];
    char word[200];
    int line_count = 1;
    int found = 0;

    printf("Enter the name of the file to be opened: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter the word to search for: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0';

    FILE *ptr = fopen(filename, "r");

    if (ptr == NULL)
    {
        printf("ERROR 404: File not found.\n");
        return 0;
    }

    while (fgets(line, sizeof(line), ptr) != NULL)// this means that keep reading lines until there are no more lines and fgets is used to read line by line
    {
        if (strstr(line, word) != NULL)
        {
            printf("Word found on line %d\n", line_count);
            found = 1;
            

        }

        line_count++;
    }

    if (found == 0)
    {
        printf("Word not found.\n");
    }

    fclose(ptr);
    return 1;
}


int Replace_Word()
{
    FILE *fp, *temp;

    char filename[100];
    char oldWord[50];
    char newWord[50];

    char line[1000];

    printf("Enter file name: ");
    scanf("%99s", filename);
    getchar();  

    printf("Enter word to replace: ");
    scanf("%49s", oldWord);
    getchar();  

    printf("Enter new word: ");
    scanf("%49s", newWord);
    getchar();  

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    temp = fopen("temp.txt", "w");

    if (temp == NULL)
    {
        printf("Could not create temporary file.\n");
        fclose(fp);
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *token = strtok(line, " \n");

        while (token != NULL)
        {
            if (strcmp(token, oldWord) == 0)
            {
                fprintf(temp, "%s ", newWord);
            }
            else
            {
                fprintf(temp, "%s ", token);
            }

            token = strtok(NULL, " \n");
        }

        fprintf(temp, "\n");
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    printf("Word replaced successfully!\n");

    return 0;
}





int Delete_Line()
{
    char filename[50];
    char line[200];
    int delete_line;
    int line_count = 1;

    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter the line number to delete: ");
    scanf("%d", &delete_line);
    getchar(); // Remove the newline left by scanf

    FILE *ptr = fopen(filename, "r");

    if (ptr == NULL)
    {
        printf("ERROR: File not found.\n");
        return 0;
    }

    FILE *temp = fopen("temp.txt", "w");

    if (temp == NULL)
    {
        printf("ERROR: Could not create temporary file.\n");
        fclose(ptr);
        return 0;
    }

    while (fgets(line, sizeof(line), ptr) != NULL)
    {
        if (line_count != delete_line)
        {
            fprintf(temp, "%s", line);
        }

        line_count++;
    }

    fclose(ptr);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    printf("Line deleted successfully.\n");

    return 1;
}



int Word_Count()
{
    FILE *fp;
    char filename[100];
    char str[1000];
    int wordCount = 0;

    printf("Enter file name: ");
    scanf("%99s", filename);
    getchar();  

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File could not be opened.\n");
        return 1;
    }

    while (fgets(str, sizeof(str), fp) != NULL)
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] != ' ' &&
                str[i] != '\n' &&
                (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\n'))
            {
                wordCount++;
            }
        }
    }

    fclose(fp);

    printf("Total words = %d\n", wordCount);

    return 0;
}





int main(void)
{
    while(breakable){

        int choice;

printf("==============================\n");
printf("      MINI TEXT EDITOR\n");
printf("==============================\n");

printf("1. Create New File\n");
printf("2. Open File\n");
printf("3. Append Text\n");
printf("4. Search Word\n");
printf("5. Replace Word\n");
printf("6. Delete Line\n");
printf("7. Word Count\n");
printf("8. Exit\n");




printf("Pls enter your choice");
scanf("%d",&choice);
getchar();  

switch(choice){

case 1:{
    Create_New_File();
    
break;

}
case 2:{
    Open_File();
break;
    
}
case 3:{
    Append_Text();
break;
    
}
case 4:{
    Search_Word();
break;
    
}
case 5:{
    Replace_Word();

break;
    
}
case 6:{
    Delete_Line();


break;
    
}
case 7:{
    Word_Count();
    

    break;
}
case 8:{
    return 1;
break;
    
}
default :{
    printf("Pls provide proper input");
    break;


}


}
    return 0;
}}