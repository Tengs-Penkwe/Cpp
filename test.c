#include <stdio.h>
#include <string.h>

int main(){
	
	char p[]={'1','2','3','4','5','7','6','0','9','8','\0'};
	int m,n;
	m=sizeof(p);
	int j=sizeof(char);
	int k=sizeof(char*);
	int l=sizeof(void*);
	n=strlen(p);
	printf("%d,%d,%d,%d,%d\n",m,n,j,k,l);
}
