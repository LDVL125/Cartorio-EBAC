#include <stdio.h>//biblioteca de comunicação com o usuario
#include <stdlib.h>//biblioteca de alocação de espaço em memoria
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF para cadastro: ");//coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //reponsável por copiar os valores da string
	
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

int consultar() //Função responsável por consultar os usuários no sistema 
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //Responsavel por informar ao usuário que nao existe usuário
	{
		printf("Não foi possivel abrir o arquivo, Não encontrado, ou não registrado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Responsável por puxar as infomações do banco de dados, e mostrar ao usuário
	{
		printf("\nEssas são as informações do usuário:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()//Função responsável por deletar os usuários no sistema
{
	//inicio criação de variáveis/string
	char cpf[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("Usuário não se encontra no sistema.\n");
		system("pause");
	}
}

int main() //Função responsavel pela seleção das opções do menu do nosso sistema
{
	int opcao=0; //definindo as variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		printf("\t-Cartório da EBAC-\n\n"); //inicio do menu
		printf("-Escolha a opção que deseja para seguir:\n\n");
		printf("\t1 - *Registrar nomes*\n");
		printf("\t2 - *Consultar nomes*\n");
		printf("\t3 - *Deletar nomes*\n\n");
		printf("Opção: "); //fim do menu
		
		
		scanf("%d", &opcao); //armazenando a escolha do usuario
		system("cls");
		
		switch(opcao) //inicio  da seleção do menu
		{
		
		case 1:
		registro(); //chamada de funções
		break;
		
		case 2:
		consultar();//chamada de funções
		break;
		
		case 3:
		deletar();//chamada de funções
		break;
		
		
		default:
		printf("Esta opção não está disponivel\n");
		system("pause");
		break;
		//fim da seleção do menu
		}
    
	}
}
