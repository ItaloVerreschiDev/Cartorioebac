#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //bibliteca respons�vel pelas strings
// as bibliotecas precisam obrigatoriamente estar no inicio do codigo

int registro() //fun��o responsavel por cadastras os usuarios no sistema
{
		//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		//fim da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//colentando informa��es - print permite texto 
	scanf("%s", cpf); //%s refere-se a strings, salvar string
	
	strcpy(arquivo, cpf); //copia os valores das strings
	
	FILE *file; //  cria o arquivo
	file = fopen(arquivo, "w"); //  nomea o arquivo - w de write, permite 'escrever'
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //  fecho o arquivo
	
	file = fopen(arquivo, "a"); //abriu o arquivo e Alterou o mesmo arquivo 'a'
	fprintf(file,","); //adicionando uma v�rgula
	fclose(file);//  fecho o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//colentando informa��es - print permite texto
	scanf("%s",nome);//%s refere-se a strings, salvar string
	
	file = fopen(arquivo, "a");//abriu o arquivo e Alterou o mesmo arquivo
	fprintf(file,nome);//adicionando uma v�rgula a cada informa��o
	fclose(file);//  fecho o arquivo
	
	file = fopen(arquivo, "a"); //abriu o arquivo e Alterou o mesmo arquivo
	fprintf(file,","); //adicionando uma v�rgula
	fclose(file);//adicionando uma v�rgula
	
	printf("Digite o sobrenome a ser cadastrado: ");//colentando informa��es - print permite text
	scanf("%s",sobrenome);//%s refere-se a strings, salvar string
	
	file = fopen(arquivo, "a");//abriu o arquivo e Alterou o mesmo arquivo
	fprintf(file,sobrenome);//adicionando uma v�rgula
	fclose(file);//adicionando uma v�rgula
	
	file = fopen(arquivo, "a"); //abriu o arquivo e Alterou o mesmo arquivo
	fprintf(file,","); //adicionando uma v�rgula
	fclose(file); //adicionando uma v�rgula
	
	printf("Digite o cargo a ser cadastrado: ");//colentando informa��es - print permite texto
	scanf("%s",cargo);//%s refere-se a strings, salvar string em cadeia
	
	file = fopen(arquivo, "a");//abriu o arquivo e Alterou o mesmo arquivo
	fprintf(file,cargo);//adicionando uma v�rgula
	fclose(file);//adicionando uma v�rgula
	
	system("pause"); //da um 'break' ap�s a��o que foi programada
	
}

int consulta() //fun��o responsavel por consultar os usuarios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da variavel
	char cpf[40];
	char conteudo[200];
	//fim da variavel
	
	printf("Digite o CPF a ser consultado: ");//colentando informa��es para a pesquisa
	scanf("%s",cpf); //salvou o valor na variavel
	
	FILE *file;//  nomeia o arquivo
	file = fopen(cpf,"r"); //  nomea o arquivo - r de read, permite 'ler' o arquivo
	
	if(file == NULL)//funcao SE, indicando tudo que seria nulo resultaria abaixo
	{
		printf("Arquivo n�o localizado!\n");//apresentando informa��es - printf permite texto
	}
	
	while(fgets(conteudo, 200, file) != NULL) //fun�ao SESIM, indica abaixo o que se procura
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // apresenta as informa��es
		printf("%s", conteudo); //apresentando o valor na variavel
		printf("\n\n"); //pulando linhas
	}
	
	system("pause"); //da um 'break' ap�s a��o que foi programada
	fclose(file);
		
} //fim da fun��o

int deletar() //fun��o responsavel por deletar os usuarios do sistema
{
	//inicio da variave
	char cpf[40];
	//fim da variavel
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //texto para o usuario identificar o que ele busca
	scanf("%s",cpf);//%s refere-se a strings, encontrando a que se busca
	
	remove(cpf);  //remove os arquivos referenciados pela string e escritos no printf
	
	FILE *file; //indicando que � arquivo
	file = fopen(cpf,"r"); //indicando O arquivo requisitado
	
	if(file == NULL) //funcao SE, indicando tudo que seria nulo resultaria abaixo
	{
		printf("Usu�rio n�o encontrado!\n"); //apresentando informa��es - printf permite texto
		system("pause"); //da um 'break' ap�s a��o que foi programada
	}  
	
}

int main() //fun��o principal - inicial do projeto, a 'main'
{
	int opcao=0; //definindo vari�veis
	int rep=1; //fun��o de repeti��o do menu
		
	for(rep=1;rep=1;) //para se entender quantas vezes � 'poss�vel' inicializar o menu
	{

		system("cls"); //limpeza da mensagem da tela

		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio menu
		printf("Escolha a op��o desejada do menu:\n\n"); //colentando informa��es - print permite texto
		printf("\t1 - Registrar nomes\n"); //colentando informa��es - print permite texto
		printf("\t2 - Consultar nomes\n"); //colentando informa��es - print permite texto
		printf("\t3 - Deletar nomes\n\n\n"); //colentando informa��es - print permite texto
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando escolhas
	
		system("cls"); //limpeza da tela p�s escolhas 
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1: //funciona como um SE
				registro(); //indica��o da fun��o
			break; //fim da op��o
				
			case 2:	//funciona como um SE
				consulta(); //indica��o da fun��o
			break; //fim da op��o
			
			case 3://funciona como um SE
				deletar(); //indica��o da fun��o
			break; //fim da op��o
			
			default: //funciona como um SENAO
				printf("Essa op��o n�o est� dispon�vel!\n"); //colentando informa��es - print permite texto
				system("pause"); //da um 'break' ap�s a��o que foi programada
			break;
		} //fim da sele��o
	
	
	}
}
