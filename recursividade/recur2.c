#include <stdio.h>

//P(n) = P(n - 2) + P(n - 3) se n > 2

int loop(int n){

	if(n == 0 || n == 1 || n == 2) {
		return 1;
	}
	return loop(n - 2) + loop(n - 3);
}

int main(){

	printf("%d \n", loop(12));

	return 0;
}
