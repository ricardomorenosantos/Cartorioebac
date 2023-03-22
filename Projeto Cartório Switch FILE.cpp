#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //respons�vel por cuidar das strings


int registrar() //Fun��o respons�vel por cadastrar os nomes no sistema 
{
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", &cpf); //%s Refere-se a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo 	
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo,"a"); //Abre o arquivo e o "a" significa copiar o "w"
	fprintf(file,","); //Acrescenta uma virgula entre informa��es do usu�rio
	fclose(file); //Fecha o programa 
	
	printf("Digite o nome a ser cadastrado: "); //Campo de preenchimento do usu�rio
	scanf("%s", &nome); //Armazena (nesse caso) as strings
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa copiar o "w"
	fprintf(file,nome); //Escreve dentro do arquivo
	fclose(file); //Fecha o arquivo 
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	char cpf[40];
	char conteudo[200];
	char nome [40];
	char sobrenome [40];
	
	printf("Digite o o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado \n");
	} 
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: %s \n %s ", nome, sobrenome);
		printf("%s", conteudo);
		printf("\n\n");
	}

		system("pause");
		
}

int excluir()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(	file == NULL)
	{
		printf("O usu�rio nao se encontra no sistema: \n");
		system("pause");
	}
	
	
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //repeti��o
	{
	
		system("cls"); //Limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		//In�cio do menu
		printf("\tCart�rio EBAC\t \n\n"); 
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Incluir nomes \n");
		printf("\t2 - Consultar os nomes \n");
		printf("\t3 - Excluir nomes \n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); 
		//Fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
	
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registrar(); //chamada de fun��es 
			break;	
			
			case 2:
			consultar();
			break;
			
			case 3: 
			excluir();
			break; //encerra
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause"); //espera o usu�rio sair do que foi selecionado
			break; 
			//fim da sele��o 
		}
	}
}
