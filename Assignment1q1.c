#include <stdio.h>

int main(int argc, char *argv[]){

    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char pw[4];
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
   
    for ( i = 0; i < 26; i++) {
        for ( j = 0; j < 26; j++) {
            for ( k = 0; k < 26; k++) {                
                for ( l = 0; l < 26; l++) {                    
                    if (i != j && i != k && i != l && j != k && j != l && k != l) {
                        pw[0] = letters[i];
                        pw[1] = letters[j];
                        pw[2] = letters[k];
                        pw[3] = letters[l];
                        printf("%c%c%c%c\n", pw[0],pw[1],pw[2],pw[3]);
                    }
                }
            }
        }
    }
}

