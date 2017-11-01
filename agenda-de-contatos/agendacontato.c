/*

  * Universidade de Brasília
  * Disciplina: Algoritmos de programação de computadores - 2017/1
  Professor: Felipe Duerno do Couto Almeida
  * Turma: FF
  * Alunos: Bruno Rodrigues Santos - 16/0114934
  			Guilherme Simões Dias - 16/0123364
  *
  * Substituição da lista 06: Agenda de contatos

*/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>



struct ficha{ // criação da estrutura para ficahamento de informações

  char nome[100];
  char email[100];
  char telefone[100];
  char sexo[100];
  char idade[10];




};

typedef struct ficha Agenda;



int main(){

	Agenda agenda[100]; // banco de dados para cadastramento de contatos

	int contatos_cadastrados = 0, posicao = 0;
	int op;
	

	while(op!=6){

		printf("\n");
		printf("\n");
    	printf("      ----- Agenda de Contatos -----\n");
		printf("      ----- Escolha a opção desejada: -----\n");
		printf("\n");

		printf("      1 - Cadastrar novo contato\n");
		printf("      2 - Atualizar contato existente\n");
		printf("      3 - Pesquisar contato por email\n");
		printf("      4 - Listar todos os contatos\n");
		printf("      5 - Remover contato\n");
		printf("      6 - Sair\n");
		
		scanf("%d", &op);
		
		
		if(op == 1){ // inserir contatos

			if(contatos_cadastrados == 0){

				int sex;

				printf("Nome do primeiro contato:\n");
				getchar();
				fgets(agenda[posicao].nome, 100, stdin);
				
				printf("Email do primeiro contato:\n");
				scanf("%s", agenda[posicao].email);

				
				
				printf("Telefone do primeiro contato:\n");
				scanf("%s", agenda[posicao].telefone);


				
				printf("Sexo do primeiro contato: 1- Maculino 2-Feminino\n");
					scanf("%d", &sex);
					
					if(sex == 1){
						strcpy(agenda[posicao].sexo,"Maculino");
					}
					
					else if(sex == 2){
						strcpy(agenda[posicao].sexo,"Feminino");
					}

				
				
				printf("Idade do primeiro contato:\n");
				scanf("%s", agenda[posicao].idade);
				

				contatos_cadastrados++;
				posicao++;


			}

			else{

				int i,sex;
				char novo_email[20];

				printf("Email do novo contato:\n");
				scanf("%s", novo_email);

				bool encontrado = false;

				for(i = 0; i < contatos_cadastrados; i++){

					if(strcmp(novo_email,agenda[i].email)==0){

						encontrado = true;
						printf("\n");
						printf("Contato já cadastrado\n");
						printf("\n");

						break;
					}



				}

				if(encontrado == false){
					
					
					
					printf("Nome do novo contato:\n");
					getchar();
					fgets(agenda[posicao].nome, 100, stdin);
					
					strcpy(agenda[posicao].email,novo_email);
					
					printf("Telefone do novo contato:\n");
					scanf("%s", agenda[posicao].telefone);
					
					printf("Sexo do novo contato: 1- Maculino 2-Feminino\n");
					scanf("%d", &sex);
					
					if(sex == 1){
						strcpy(agenda[posicao].sexo,"Maculino");
					}
					
					else if(sex == 2){
						strcpy(agenda[posicao].sexo,"Feminino");
					}
					
					printf("Idade do novo contato:\n");
					scanf("%s", agenda[posicao].idade);

					contatos_cadastrados++;
					posicao++;
				}




			}


		}


		if(op == 2){ // atualizar informações de contato existente

			char novo_nome[50];
			int i;
			bool encontrado = false;

			printf("Nome do contato que deseja atualizar:\n");
			getchar();
			fgets(novo_nome, 100, stdin);

			

			for(i = 0; i < contatos_cadastrados; i++){

					if(strcmp(novo_nome,agenda[i].nome)==0){

						encontrado = true;
						
						int escolha;
						printf("O que deseja atualizar?\n");
						printf("\n");
						printf("1-Email 2-Telefone 3-Idade\n");
						
						scanf("%d", &escolha);
						
						switch(escolha){
						
							case 1:
								
								printf("novo email:\n");
								scanf("%s", agenda[i].email);
								
								break;
							
							case 2:
								
								printf("novo telefone:\n");
								scanf("%s", agenda[i].telefone);
								
								break;
							
							case 3:
								
								printf("nova idade:\n");
								scanf("%s", agenda[i].idade);
								
								break;
							
							default:
							
								printf("Opção inválida\n");
							
						
						}


						break;
					}
			}

			if(encontrado == false){
					
				printf("Contato não cadastrado\n");
				printf("\n");


			}


		}


		if(op == 3){ // pesquisar contato por email
		  
		  if(contatos_cadastrados == 0){
		    printf("Nenhum contato cadastrado até o momento\n");
		    printf("\n");
		  }
		  
		  else{
		    
		    char procurar[20];
  			int i;
  
  			printf("Email:\n");
  			scanf("%s", procurar);
  
  			bool encontrado = false;
  
  			for (int i = 0; i < contatos_cadastrados; i++){
  				if (strcmp(procurar,agenda[i].email) == 0){
  
  					encontrado = true;
  
  					printf("Nome do contato procurado:\n");
  					printf("%s\n",agenda[i].nome);
  
  					printf("telefone do contato procurado:\n");
  					printf("%s\n",agenda[i].telefone);
  
  					printf("sexo do contato procurado:\n");
  					printf("%s\n",agenda[i].sexo);
  
  					printf("idade do contato procurado:\n");
  					printf("%s\n",agenda[i].idade);

				  }
				
				
			  }

  			if (encontrado == false){
  
  				printf("Contato não encontrado\n");
  
  			}
		    
		  }

			

		}

		if (op == 4){ // listar todos os contatos
			
			if (contatos_cadastrados == 0){
				printf("Nenhum contato cadastrado até o momento\n");
				printf("\n");
			}

			else{

				int i;
				for (int i = 0; i < contatos_cadastrados; i++){

					printf("CONTATO %d :\n", i+1);
					printf("\n");

					printf("Nome: %s\n", agenda[i].nome);
					printf("Email: %s\n", agenda[i].email);
					printf("Telefone: %s\n", agenda[i].telefone);
					printf("Sexo: %s\n", agenda[i].sexo);
					printf("Idade: %s\n", agenda[i].idade);
					
					
				}
			}

		}

		if (op == 5){ // remover contato
			
			char procurar[20];
  			int i;
  
  			printf("Nome do contato que deseja excluir:\n");
  			getchar();
			fgets(procurar, 100, stdin);
  
  			bool encontrado = false;

  			for (int i = 0; i < contatos_cadastrados; i++){
  				if (strcmp(procurar,agenda[i].nome) == 0){
  
  					encontrado = true;
  
  					int j;

  					for(j = i+1; j < contatos_cadastrados; j++){

  						agenda[j-1] = agenda[j];

  					}

  					contatos_cadastrados--;
  					posicao--;

  					printf("Contato removido com sucesso\n");
					printf("\n");

  					break;

				}
				
				
			}

			if (encontrado == false){
				printf("Contato não econtrado\n");
				printf("\n");
			}


		}


		

	}


		
		

			return 0;
		

}
