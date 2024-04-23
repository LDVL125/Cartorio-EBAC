#include <stdio.h>//biblioteca de comunica��o com o usuario
#include <stdlib.h>//biblioteca de aloca��o de espa�o em memoria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF para cadastro: ");//coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //repons�vel por copiar os valores da string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file= fopen(arquivo, "a");
	fprintf( file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file= fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar() //Fun��o respons�vel por consultar os usu�rios no sistema 
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //Responsavel por informar ao usu�rio que nao existe usu�rio
	{
		printf("N�o foi possivel abrir o arquivo, N�o encontrado, ou n�o registrado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Respons�vel por puxar as infoma��es do banco de dados, e mostrar ao usu�rio
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()//Fun��o respons�vel por deletar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char cpf[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("Usu�rio n�o se encontra no sistema.\n");
		system("pause");
	}
}

int main() //Fun��o responsavel pela sele��o das op��es do menu do nosso sistema
{
	int opcao=0; //definindo as variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		printf("\t-Cart�rio da EBAC-\n\n"); //inicio do menu
		printf("-Escolha a op��o que deseja para seguir:\n\n");
		printf("\t1 - *Registrar nomes*\n");
		printf("\t2 - *Consultar nomes*\n");
		printf("\t3 - *Deletar nomes*\n\n");
		printf("Op��o: "); //fim do menu
		
		
		scanf("%d", &opcao); //armazenando a escolha do usuario
		system("cls");
		
		switch(opcao) //inicio  da sele��o do menu
		{
		
		case 1:
		registro(); //chamada de fun��es
		break;
		
		case 2:
		consultar();//chamada de fun��es
		break;
		
		case 3:
		deletar();//chamada de fun��es
		break;
		
		
		default:
		printf("Esta op��o n�o est� disponivel\n");
		system("pause");
		break;
		//fim da sele��o do menu
		}
    
	}
}
