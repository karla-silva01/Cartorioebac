#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca reponsável por cuidar das string

int registro() //Função responsável por cadastrar os usuáriosno sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo na pasta e o "w" refere-se a escrever
	fprintf(file,cpf); // Salvo o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo na pasta e o "a" refere-se a atualizar
	fprintf(file,"  ||  " );// Salvo o valor da variável
	fclose(file);// Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Cria o arquivo na pasta e o "a" refere-se a atualizar
	fprintf(file,nome);// Salvo o valor da variável
	fclose(file);// Fecha o arquivo
	
	file = fopen(arquivo, "a");//Cria o arquivo na pasta e o "a" refere-se a atualizar
	fprintf(file,"  ||  ");// Salvo o valor da variável
	fclose(file);// Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Cria o arquivo na pasta e o "a" refere-se a atualizar
	fprintf(file,sobrenome);// Salvo o valor da variável
	fclose(file);// Fecha o arquivo
	
	file = fopen(arquivo, "a");//Cria o arquivo na pasta e o "a" refere-se a atualizar
	fprintf(file,"  ||  ");// Salvo o valor da variável
	fclose(file);// Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Cria o arquivo na pasta e o "a" refere-se a atualizar
	fprintf(file,cargo);// Salvo o valor da variável
	fclose(file);// Fecha o arquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//Início da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//Fim da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: ");//Coletando informações do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	FILE *file; //Consultar a biblioteca e puxar arquivos
	file = fopen(cpf, "r"); //Abre a pasta e procura o arquivo "CPF" e o "r" é de ler
	
	if(file == NULL) // Quando não achar o arquivo
	{
		printf("\nNão foi possível abrir o arquivo. Não localizado! ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n\nEssas são as informações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n\n");
	}
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");//Coletando informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;//Consultar a biblioteca e puxar arquivos
	file = fopen(cpf,"r"); //Abre a pasta e procura o arquivo "CPF" e o "r" é de ler
	fclose(file); // Fecha o arquivo

	
	if(file == NULL) //Condição se o usuário não estiver cadastrado no sistema
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	else // Condição para o usuário ser deletado do sistema
	{
		remove(cpf);
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //
	{
	
		system("cls"); //Responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("###Cartório da EBAC###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
		
		
		switch(opcao) //Início da seleção do menu
		{
			case 1:
			registro(); //Chamada de funções
			break;
			
			case 2:
			consulta();//Chamada de funções
			break;
			
			case 3:
			deletar();//Chamada de funções
			break;
			
			default://Mensagem de erro para quando o usuário usa uma opção diferente
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;			
		} //fim de seleção
	}
}
