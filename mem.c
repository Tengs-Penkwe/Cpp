#include <stdio.h>

int main(){

	int in_a = 1, in_b =2, out_sum;

	printf("in_b is %d\n",in_b);

	asm("movb %0, %1"::"a"(in_a),"m"(in_b));

	printf("in_b now is %d\n",in_b);
}
