#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string encrypt(string plaintext, int key);

int main(int argc, string argv[])
{   
    if (argv[1] == NULL || atoi(argv[1]) == 0) // User doesn't cooperate
    {
        printf("Usage: ./caesar key\n");
        return 1;
    } 
    if (argv[2] != NULL) // User inputs more than 1 parameter (1 key)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    } 
    int size = strlen(argv[1]);
    for (int i = 0; i < size; i++)
    {
        if (isdigit(argv[1][i]))
        {
            continue;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt(plaintext, k);
    printf("ciphertext: %s\n", ciphertext);
}

// Encrypt a string with specific key
string encrypt(string plaintext, int key)
{
    string ciphertext = "";
    while (key > 26)
    {
        key -= 26;
    }
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if ((int)plaintext[i] >= 65 && (int)plaintext[i] <= 90) // Check for Capital letter
        {
            if ((int)plaintext[i] + key > 90)
            {
                plaintext[i] = ((plaintext[i] + key) - 26); 
            }
            else
            {
                plaintext[i] += key;
            }
        }
        else if ((int)plaintext[i] >= 97 && (int)plaintext[i] <= 122) // check for Small letter
        {
            if ((int)plaintext[i] + key > 122)
            {
                plaintext[i] = ((plaintext[i] + key) - 26); 
            }
            else
            {
                plaintext[i] += key;
            }
        }
        else
        {
            continue;
        }
    }
    ciphertext = plaintext;
    return ciphertext;
}
