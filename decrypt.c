#include <stdio.h>
#include <string.h>

void reverse(char cipher[], char otext[]) {

    int i = 0;
    int shift = 0;
    int cipherlen = strlen(cipher);

    do {
        for (i = 0 ; i <= (cipherlen-2); i++) {

            if (cipher[i] + shift <= '~') {

                otext[i] = cipher[i] + shift;

            }
            else if (cipher[i] + shift >= '~') {

                otext[i] = cipher[i] + shift - 95;

            }
        }
        otext[i] = '\0';
        printf("Possible plaintext is %s using shift of %d\n", otext, shift);
        shift++;
    }while(shift <= 94);
}

int main(void) {

    char cipher[256];
    char otext[256];


    printf("Enter string to decrypt: ");
    fgets(cipher, 256, stdin);

    reverse(cipher, otext);

    return 0;
}
