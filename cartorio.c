#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //bibliteca responsável pelas strings
// as bibliotecas precisam obrigatoriamente estar no inicio do codigo

int registro() //função responsavel por cadastras os usuarios no sistema
{
		//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		//fim da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//colentando informações - print permite texto 
	scanf("%s", cpf); //%s refere-se a strings, salvar string
	
	strcpy(arquivo, cpf); //copia os valores das strings
	
	FILE *file; //  cria o arquivo
	file = fopen(arquivo, "w"); //  nomea o arquivo - w de write, permite 'escrever'
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //  fecho o arquivo
	
	file = fopen(arquivo, "a"); //abriu o arquivo e Alterou o mesmo arquivo 'a'
	fprintf(file,","); //adicionando uma vírgula
	fclose(file);//  fecho o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//colentando informações - print permite texto
	scanf("%s",nome);//%s refere-se a strings, salvar string
	
	file = fopen(arquivo, "a");//abriu o arquivo e Alterou o mesmo arquivo
	fprintf(file,nome);//adicionando uma vírgula a cada informação
	fclose(file);//  fecho o arquivo
	
	file = fopen(arquivo, "a"); //abriu o arquivo e Alterou o mesmo arquivo
	fprintf(file,","); //adicionando uma vírgula
	fclose(file);//adicionando uma vírgula
	
	printf("Digite o sobrenome a ser cadastrado: ");//colentando informações - print permite text
	scanf("%s",sobrenome);//%s refere-se a strings, salvar string
	
	file = fopen(arquivo, "a");//abriu o arquivo e Alterou o mesmo arquivo
	fprintf(file,sobrenome);//adicionando uma vírgula
	fclose(file);//adicionando uma vírgula
	
	file = fopen(arquivo, "a"); //abriu o arquivo e Alterou o mesmo arquivo
	fprintf(file,","); //adicionando uma vírgula
	fclose(file); //adicionando uma vírgula
	
	printf("Digite o cargo a ser cadastrado: ");//colentando informações - print permite texto
	scanf("%s",cargo);//%s refere-se a strings, salvar string em cadeia
	
	file = fopen(arquivo, "a");//abriu o arquivo e Alterou o mesmo arquivo
	fprintf(file,cargo);//adicionando uma vírgula
	fclose(file);//adicionando uma vírgula
	
	system("pause"); //da um 'break' após ação que foi programada
	
}

int consulta() //função responsavel por consultar os usuarios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da variavel
	char cpf[40];
	char conteudo[200];
	//fim da variavel
	
	printf("Digite o CPF a ser consultado: ");//colentando informações para a pesquisa
	scanf("%s",cpf); //salvou o valor na variavel
	
	FILE *file;//  nomeia o arquivo
	file = fopen(cpf,"r"); //  nomea o arquivo - r de read, permite 'ler' o arquivo
	
	if(file == NULL)//funcao SE, indicando tudo que seria nulo resultaria abaixo
	{
		printf("Arquivo não localizado!\n");//apresentando informações - printf permite texto
	}
	
	while(fgets(conteudo, 200, file) != NULL) //funçao SESIM, indica abaixo o que se procura
	{
		printf("\nEssas são as informações do usuário: "); // apresenta as informações
		printf("%s", conteudo); //apresentando o valor na variavel
		printf("\n\n"); //pulando linhas
	}
	
	system("pause"); //da um 'break' após ação que foi programada
	fclose(file);
		
} //fim da função

int deletar() //função responsavel por deletar os usuarios do sistema
{
	//inicio da variave
	char cpf[40];
	//fim da variavel
	
	printf("Digite o CPF do usuário a ser deletado: "); //texto para o usuario identificar o que ele busca
	scanf("%s",cpf);//%s refere-se a strings, encontrando a que se busca
	
	remove(cpf);  //remove os arquivos referenciados pela string e escritos no printf
	
	FILE *file; //indicando que É arquivo
	file = fopen(cpf,"r"); //indicando O arquivo requisitado
	
	if(file == NULL) //funcao SE, indicando tudo que seria nulo resultaria abaixo
	{
		printf("Usuário não encontrado!\n"); //apresentando informações - printf permite texto
		system("pause"); //da um 'break' após ação que foi programada
	}  
	
}

int main() //função principal - inicial do projeto, a 'main'
{
	int opcao=0; //definindo variáveis
	int rep=1; //função de repetição do menu
		
	for(rep=1;rep=1;) //para se entender quantas vezes é 'possível' inicializar o menu
	{

		system("cls"); //limpeza da mensagem da tela

		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio menu
		printf("Escolha a opção desejada do menu:\n\n"); //colentando informações - print permite texto
		printf("\t1 - Registrar nomes\n"); //colentando informações - print permite texto
		printf("\t2 - Consultar nomes\n"); //colentando informações - print permite texto
		printf("\t3 - Deletar nomes\n\n\n"); //colentando informações - print permite texto
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando escolhas
	
		system("cls"); //limpeza da tela pós escolhas 
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1: //funciona como um SE
				registro(); //indicação da função
			break; //fim da opção
				
			case 2:	//funciona como um SE
				consulta(); //indicação da função
			break; //fim da opção
			
			case 3://funciona como um SE
				deletar(); //indicação da função
			break; //fim da opção
			
			default: //funciona como um SENAO
				printf("Essa opção não está disponível!\n"); //colentando informações - print permite texto
				system("pause"); //da um 'break' após ação que foi programada
			break;
		} //fim da seleção
	
	
	}
}
