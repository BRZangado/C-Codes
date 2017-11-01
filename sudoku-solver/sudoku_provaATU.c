#include <stdio.h>
#include <stdbool.h>


int verifica_linha(int sudoku[9][9], int linha, int num){
    int coluna;
	for (coluna = 0; coluna < 9; coluna++) {
		if (sudoku[linha][coluna] == num) {
			return 1;
		}
	}
	return 0;
}

int verifica_coluna(int sudoku[9][9], int coluna, int num) {
    int linha;
	for (linha = 0; linha < 9; linha++) {
		if (sudoku[linha][coluna] == num) {
			return 1;
		}
	}
	return 0;
}

int verifica_caixa(int sudoku[9][9], int linha_inicial, int coluna_inicial, int num) {
    int linha;
    int coluna;
	for (linha = 0; linha < 3; linha++) {
		for (coluna = 0; coluna < 3; coluna++) {
			if (sudoku[linha + linha_inicial][coluna + coluna_inicial] == num) {
				return 1;
			}
		}
	}
	return 0;
}

int salvar_num(int sudoku[9][9], int lin, int col, int num) {
	return !verifica_linha(sudoku, lin, num) && !verifica_coluna(sudoku, col, num) && !verifica_caixa(sudoku, lin-(lin % 3), col-(col%3), num);
}

int procurar_elemento_vazio(int sudoku[9][9], int *linha, int *coluna) {
	for(*linha = 0; *linha < 9;(*linha)++){
		for(*coluna = 0; *coluna < 9; (*coluna)++){

			if(sudoku[*linha][*coluna] == 0){

				return 1;
			}
		}
	}
	return 0;
}

int resolve(int sudoku[9][9]) {

	int linha = 0, coluna = 0;
	int num;

	if (procurar_elemento_vazio(sudoku, &linha, &coluna) == false){
		return 1;
	}

	for (num = 1; num <= 9; num++ ){

		if (salvar_num(sudoku, linha, coluna, num) == true){
			sudoku[linha][coluna] = num;

			if (resolve(sudoku) == true) {
				return 1;
			}

			sudoku[linha][coluna] = 0;
		}
	}

	return 0;
}

void imprimir(int sudoku[9][9]) {

    int i;
    int j;

	for (i = 0; i < 9; i++) {
               if(i == 3 || i == 6){
                printf("- - - - - - - - - - -\n");
        }
		for (j = 0; j < 9; j++) {

        if(j==2 || j == 5){
                    printf("%d | ", sudoku[i][j]);
                }
                else if(j==0 || j==1 || j==3 || j==4 || j==6 || j==7){
                    printf("%d ", sudoku[i][j]);
                }
                else{
                    printf("%d", sudoku[i][j]);
                }
		}



        printf("\n");

	}
}


int main(){

	int sudoku[9][9];
	bool resolvido = false;
    int i, j;
	char t;


	for(i=0; i<9; i++){
        for(j=0; j<9; j++){
                scanf(" %c", &t);

                t -= 48;
                sudoku[i][j] = t;
                if(sudoku[i][j]==40){

                        sudoku[i][j] = 0;

                }
        }
    }

    resolve(sudoku);

	if (resolve(sudoku) == true) {
		resolvido = true;
	} else {
		resolvido = false;
	}

	if(resolvido == true){
        imprimir(sudoku);
	}
	else{
        printf("Nenhuma solução econtrada\n");
	}

	return 0;
}
