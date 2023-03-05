int main(){
	int in_a = 1, sum =0 ;
	asm("addl %1,%0;":"=a"(sum):"%I"(2),"0"(in_a));
}
