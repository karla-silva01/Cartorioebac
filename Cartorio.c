#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca repons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�riosno sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo na pasta e o "w" refere-se a escrever
	fprintf(file,cpf); // Salvo o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo na pasta e o "a" refere-se a atualizar
	fprintf(file,"  ||  " );// Salvo o valor da vari�vel
	fclose(file);// Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Cria o arquivo na pasta e o "a" refere-se a atualizar
	fprintf(file,nome);// Salvo o valor da vari�vel
	fclose(file);// Fecha o arquivo
	
	file = fopen(arquivo, "a");//Cria o arquivo na pasta e o "a" refere-se a atualizar
	fprintf(file,"  ||  ");// Salvo o valor da vari�vel
	fclose(file);// Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Cria o arquivo na pasta e o "a" refere-se a atualizar
	fprintf(file,sobrenome);// Salvo o valor da vari�vel
	fclose(file);// Fecha o arquivo
	
	file = fopen(arquivo, "a");//Cria o arquivo na pasta e o "a" refere-se a atualizar
	fprintf(file,"  ||  ");// Salvo o valor da vari�vel
	fclose(file);// Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Cria o arquivo na pasta e o "a" refere-se a atualizar
	fprintf(file,cargo);// Salvo o valor da vari�vel
	fclose(file);// Fecha o arquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//In�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: ");//Coletando informa��es do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	FILE *file; //Consultar a biblioteca e puxar arquivos
	file = fopen(cpf, "r"); //Abre a pasta e procura o arquivo "CPF" e o "r" � de ler
	
	if(file == NULL) // Quando n�o achar o arquivo
	{
		printf("\nN�o foi poss�vel abrir o arquivo. N�o localizado! ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n\n");
	}
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//Coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;//Consultar a biblioteca e puxar arquivos
	file = fopen(cpf,"r"); //Abre a pasta e procura o arquivo "CPF" e o "r" � de ler
	fclose(file); // Fecha o arquivo

	
	if(file == NULL) //Condi��o se o usu�rio n�o estiver cadastrado no sistema
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	else // Condi��o para o usu�rio ser deletado do sistema
	{
		remove(cpf);
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //
	{
	
		system("cls"); //Respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("###Cart�rio da EBAC###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
		
		
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1:
			registro(); //Chamada de fun��es
			break;
			
			case 2:
			consulta();//Chamada de fun��es
			break;
			
			case 3:
			deletar();//Chamada de fun��es
			break;
			
			default://Mensagem de erro para quando o usu�rio usa uma op��o diferente
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;			
		} //fim de sele��o
	}
}
