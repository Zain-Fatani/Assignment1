/*
* RSA Decryption using OpenSSL library and Python encode/decode
* 
* to complile gcc Assignment1q2.c -o Assignment1q2 -lssl -lcrypto
* message to decrypt: 858FF93C7C313EDC14E79A13EAF539D0893DACC7C70D335384965088E88AFC
* */
#include <stdio.h>
#include <string.h>
#include <openssl/bn.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void printBN(char *msg, BIGNUM *tmp){
     char *number_str = BN_bn2hex(tmp); // Convert BIGNUM to hex
     printf("%s%s\n", msg, number_str); // Print hex
     OPENSSL_free(number_str); // Free memory
}

int main(int argc, char *argv[]){
	BN_CTX *ctx = BN_CTX_new();
/*
* Here initialize all needed BIGNUM variables
* 1- Encryption Key variable*/
	BIGNUM *e = BN_new();
/*
* 2- Decryption Key variable*/
	BIGNUM *d = BN_new();
/*
* 3- product of large prime numbers p and q
*/
	BIGNUM *n = BN_new();
/*
* 4- Totient of (n) Euler's totient function
*/
	BIGNUM *phin = BN_new();
/*
* 5- Encrypted Message variable*/
	BIGNUM *C = BN_new();
/*
* 6- Decrypted Ciphertext variable*/
	BIGNUM *D = BN_new();
/*
* */
// Find Decryption Key (d) using (e) and (Phin):
// 1- Assign value to (e) Encryption Key from hex
	BN_hex2bn(&e,"010001");
// 2- Assign value to (Phin) Encryption Key from hex
	BN_hex2bn(&phin, "E103ABD94892E3E74AFD724BF28E78348D52298BD687C44DEB3A81065A7981A4");
// 3- Calculate the Decryption Key (Private Key) d=e mod(Phi(n))
	BN_mod_inverse(d, e, phin, ctx);

	char *CC= malloc(100 * sizeof(char));
	printf("\nEnter your Encrypted Message:\n");
// Read the Encrypted Message from the user to variable CC
	fgets(CC, 1000, stdin);
// Assign the input value in variable (CC) to Encrypted Message variable
	BN_hex2bn(&C, CC);	
/*
Decrypt ciphertext using D=C^d(mod(n)) ,
where: (D) is the Decrypted Ciphertext and (C) is the Ciphertext
*/

// Assign value to (n) product of two large prime numbers from hex
	BN_hex2bn(&n, "E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1");
// decrypt Ciphertext using the Private Key
	BN_mod_exp(D, C, d, n, ctx);
// Convert Hex string to ASCII letters
	printf("\nOriginal Message:\n");
	char str1[500]="print(\"";
	char *str2 = BN_bn2hex(D);
	char str3[]="\".decode(\"hex\"))";
	strcat(str1,str2);
	strcat(str1,str3);
	char* args[]={"python2", "-c",str1, NULL};
	execvp("python2", args);
	return EXIT_SUCCESS;
}

