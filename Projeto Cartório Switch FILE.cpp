#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //responsável por cuidar das strings


int registrar() //Função responsável por cadastrar os nomes no sistema 
{
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", &cpf); //%s Refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo 	
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo,"a"); //Abre o arquivo e o "a" significa copiar o "w"
	fprintf(file,","); //Acrescenta uma virgula entre informações do usuário
	fclose(file); //Fecha o programa 
	
	printf("Digite o nome a ser cadastrado: "); //Campo de preenchimento do usuário
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
		printf("Não foi possível abrir o arquivo, não localizado \n");
	} 
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as informações do usuário: %s \n %s ", nome, sobrenome);
		printf("%s", conteudo);
		printf("\n\n");
	}

		system("pause");
		
}

int excluir()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(	file == NULL)
	{
		printf("O usuário nao se encontra no sistema: \n");
		system("pause");
	}
	
	
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //repetição
	{
	
		system("cls"); //Limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		//Início do menu
		printf("\tCartório EBAC\t \n\n"); 
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Incluir nomes \n");
		printf("\t2 - Consultar os nomes \n");
		printf("\t3 - Excluir nomes \n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); 
		//Fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
	
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registrar(); //chamada de funções 
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
			printf("Essa opção não está disponível!\n");
			system("pause"); //espera o usuário sair do que foi selecionado
			break; 
			//fim da seleção 
		}
	}
}
