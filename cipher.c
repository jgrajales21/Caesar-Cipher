#include <stdio.h>
#include <string.h>

int check_string(char name[]) {

    int name_len = strlen(name); //length of name array; by assigining this value to a variable we decrease computation expense
    int i = 0; // a counter

    //comapre the char-value in array with the max bounds of ascii char [ ,~]
    for (i = 0; i <= (name_len-2); i++) {           // -2 from name_len b/c we need to copy the string of letters w/o '\n' and '\0'

        if(name[i] >= ' ' && name[i] <='~') {

            // if true do nothing leave array as is

        }
        else {

            return 0; // if input chars are out of bounds kill the code

        }
    }
    name[i] = '\0'; //must assign this to end of str; recall that the for loop updates the value of i -- say ab was the input then i=2 at the end of for loop
    return 1;
}

void caesar_cipher(char valid_name[], int shift, char cipher[]) {
    //name[] -- the brackets specify that the paramter is a LIST of type char;
    //equivalent to: char *name

    int valid_namelen = strlen(valid_name); //length of validated name array (valid iff all chars in array are with ascii bounds of [32,96]
    int i = 0;

    for (i = 0; i <= (valid_namelen-1); i++) {      //recall we added '\0' at the end of check_string; get rid of '\0' as you copy string

        if (valid_name[i] + shift >= ' ' && valid_name[i] + shift <= '~') {

            cipher[i] = valid_name[i] + shift;

        }
        else if (valid_name[i] + shift >= '~') {

            cipher [i] = valid_name[i] + shift - 95;
        }
    }
    cipher[i] = '\0';
}

int main(void) {

    char name[256];
    int shift = 0;
    char cipher[256];
    int x;

    printf("Enter a string to encrypt: ");
    fgets(name, 256, stdin); // fgets keeps the '\n' enterted by user and adds '\0' to end of input

    printf("Enter the shift amount for Caesar cipher: ");
    scanf(" %d", &shift);

    x = check_string(name);

    if (x == 1) {

        caesar_cipher(name, shift, cipher);
        printf("Ciphertext is %s\n", cipher);
    }

    else {
        printf("Error\n");
    }
}
 
