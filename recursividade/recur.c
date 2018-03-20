#include<stdio.h>

int fatorial(int n){
	if(n == 0){
		return 1;
	}
	else{
		return n * fatorial(n-1);
	}
}

void contagem(int n){
	if(n == 0){
		printf("bomba \n");
	}
	else{
		printf("%d \n", n);
		contagem(n-1);
	}
}

int fibonacci(int num){
   if(num == 1 || num == 0)
       return num;
   else
       return fibonacci(num-1) + fibonacci(num-2); 
}

int padovan(int n){

	if(n == 0 || n == 1 || n == 2) {
		return 1;
	}
	return padovan(n - 2) + padovan(n - 3);
}

int somatoria(int i){
	
	if(i == 0){
		return 0;
	}
	else{
		return i + somatoria(i-1);
	}
	
}

int multi(int a, int b){
		if(b == 1) {
            return a;
        } else {
            return a + multi(a, b - 1);
        }
}

int quadrado (int n){

	  if(n == 0){
	  	return 1;
	  }
	  else{
	  	return (2*n-1) + quadrado (n-1);
	  }
	  
}

void contagemCrescente(int a){
	
	if(a > 0){
	 	contagemCrescente(a-1);
	}
    printf("%d\n", a);
	
}

void hanoi(int discos, char veio_estaca, char para_estaca, char estaca_aux){
    if (discos == 1)
    {
        printf("\n Moveu disco 1 da estaca %c para estaca %c \n", veio_estaca,  para_estaca);
        return;
    }
    hanoi(discos-1, veio_estaca, estaca_aux,  para_estaca);
    printf("\n Moveu disco %d da estaca %c para a estaca %c \n", discos, veio_estaca,  para_estaca);
    hanoi(discos-1, estaca_aux,  para_estaca, veio_estaca);
}


int main(){

	hanoi(3,'A','B','C');
	return 0;
}
