#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//PROTOTYPES
char* encryptMessage(char*);
char* decryptMessage(char*);

int main()
{
char action = '\0';//what action that the user wants to do with the message
char* message = malloc(1024 * sizeof(char));//the user inputted message
char* encryptedMessage;
char* decryptedMessage;
//put a while gate to not let the user pass until they enter a proper message
printf("Input a message\n");
fgets(message,1024,stdin);
//check if the terminator got added  and check the bounds of the message  66 to 
//this is a fixed size check on how to extend this
printf("Do you want to encrypt or decrypt the message? E for encrypt D for decrypt and F is to finish the program\n");//and F for done?
action = fgetc(stdin);
//this has to be checked for overflows
while(action != 'F' && action != 'f')
{
    
    if(action=='E' || action == 'e')
    {
        encryptedMessage = encryptMessage(message);
        printf("Your encrypted message is: %s \n", encryptedMessage);
        action = 'F';
    }
    else if(action == 'D' || action == 'd')
    {
        decryptedMessage = decryptMessage(message);
        printf("Your decrypted message is: %s \n", decryptedMessage);
        action = 'F';
    }
    else if(action != 'F')
    {
        printf("Did not recognize action keyword please choose E for encrypt, D for decrypt and F for finished\n");
        action = fgetc(stdin);
    }
}

printf("\nPROGRAM ENDED SUCCESSFULLY\n");
free(message);
free(decryptedMessage);
free(encryptedMessage);
return 0;
}

/*
/   PURPOSE: This function encrypts the user inputted message
/   RETURN: returns that encrypted message
/   PARAMETERS: passes in the user inputted message
*/
char* encryptMessage(char* message)
{
    //strlen + 1 cause null term dynamically allocate it
    char* encryptedMessage = malloc((strlen(message) + 1)* sizeof(char));

    for(int i = 0; i < strlen(message);i++)
    {
        char letter = *(message + i);
        char encryptedLetter = letter + 3;//encode the letter
        *(encryptedMessage + i) = encryptedLetter;//check this 
    }
    return encryptedMessage;
}
/*
/  PURPOSE: This function decrypts the user inputted message
/  RETURN: returns the decrypted message
/  PARAMETERS: passes in the user inputted message
*/
char* decryptMessage(char* message)
{
    char* decryptedMessage = malloc(sizeof(char) * strlen(message) + 1);
    for(int i = 0; i < strlen(message);i++)
    {
        char letter = *(message + i);
        char encryptedLetter = letter - 3;//decode the letter
        *(decryptedMessage + i) = encryptedLetter;//check this 
    }
    return decryptedMessage;

}
