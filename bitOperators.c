/*
* Author: Michael Harrison
* Bitwise operations 
*/

#include <stdio.h>

unsigned int add(unsigned int, unsigned int);
unsigned int sub(unsigned int, unsigned int);
unsigned int mul(unsigned int, unsigned int);
unsigned int lt(unsigned int, unsigned int);
unsigned int gt(unsigned int, unsigned int);
unsigned int getByte(unsigned int, unsigned int);

int main(int argc, char **argv) {
    unsigned int i, j;
    printf("Enter an integer ");
    scanf("%u", &i);
    printf("\nEnter another integer ");
    scanf("%u", &j);
    printf("\ni + j = %u\n", add(i,j));
    printf("\ni - j = %u\n", sub(i,j));
    printf("\ni * j = %u\n", mul(i,j));
    printf("i > j = %s\n", (gt(i,j) ? "TRUE" : "FALSE"));
    printf("i < j = %s\n", (lt(i,j) ? "TRUE" : "FALSE"));
    printf("jth byte of i = %ux\n", getByte(i,j));

    return 0;
}

unsigned int add(unsigned int i, unsigned int j){
	unsigned int carry;
	do {
		carry=j;
		j&=i;
		i^=carry;
	} while((j<<=1)!=0);
	return i;
}

unsigned int sub(unsigned int i, unsigned int j){
   	return add(i,-j);
}

unsigned int mul(unsigned int i, unsigned int j){
    unsigned int sum = 0;
	while(j){
		if(j&1)
			sum = add(sum,i);
		i<<=1;
		j>>=1;
	}
	return sum;
}

/* returns non-zero if i is less than j or zero otherwise */
unsigned int lt(unsigned int i, unsigned int j){
	unsigned int ltb = ~j&i;
	unsigned int gtb = j&~i;
	ltb |= ltb>>1;
    ltb |= ltb>>2;
    ltb |= ltb>>4;
    ltb |= ltb>>8;
    ltb |= ltb>>16;
    return (gtb&~ltb);
}

/* returns non-zero if i is greater than j or zero otherwise */
unsigned int gt(unsigned int i, unsigned int j){
	return lt(j,i);
}

/* return byte #j of int i */
unsigned int getByte(unsigned int i, unsigned int j){
	i>>=(j-1);
	return (i&0xFF);
}
