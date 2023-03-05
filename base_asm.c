#include <stdio.h>

int in_a = 1, in_b =2, out_sum;

int main(){

	asm volatile("pusha; 		\
		movl in_a,%eax;	\
		movl in_b,%ebx;	\
		addl %eax,%ebx;	\
		movl %ebx,out_sum;	\
		popa");

	printf("Sum is %d\n",out_sum);
}
