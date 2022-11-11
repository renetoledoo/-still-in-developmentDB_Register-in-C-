#include <stdio.h>
#include <stdlib.h>
#include <mysqld_error.h>
#include <mysql.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

MYSQL *__stdcall conectarDB(){
	
	puts("[!] Conectando com o banco ... ");
	Sleep(1000);
	MYSQL *conexao = mysql_init(NULL);	
	if(!mysql_real_connect(conexao, "127.0.0.1", "root", "root", "registro", 0, NULL, 0)){
		
		printf("%s", mysql_error(conexao));
	} else {
		printf("[!]Sejas bem vindo(a) %s \n",  getenv("USERNAME") );
		return conexao;
	}
}

void cadastrarCliente (MYSQL *conexao, char* nome, int idade, char *sexo) {
	char consulta[100];
	sprintf(consulta, "CALL cadastrarCliente (%s, %i, %s);", nome, idade ,sexo);
	
	if(!mysql_query(conexao, consulta)) {
		printf("%s",mysql_error(conexao));
	} else {
		printf("Deu certo : %s",mysql_error(conexao));
	}
}

void consultando(MYSQL *conexao) {
	
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	
	if(mysql_query(conexao, "SELECT * FROM P_PESSOA_NOVA")) 
		printf("%s", mysql_error(conexao));
	
	resultado = mysql_store_result(conexao);
	
	if(resultado == NULL) 
		printf("%s", mysql_error(conexao));
		
	
	while((row = mysql_fetch_row(resultado)) != NULL){
		
		printf("Nome : %s", row[1]);	
	}
	
		mysql_free_result(resultado);
}

void login (MYSQL *conexao) {
	
	MYSQL_ROW row; 
	MYSQL *resultado ;
	int retorno, retorno2;
	if(mysql_query(conexao, "SELECT * FROM P_PESSOA_NOVA")) 
			printf("%s", mysql_error(conexao));
	
	char user[100], pwd[100];
	
	printf("Digite o usuario : ");
	gets(user);
	printf("Digite a senha : ");
	gets(pwd);
	
	system("cls");
	resultado = mysql_store_result(conexao);
	puts("[!] Testando conectivade.....");
	Sleep(1000);
		
	while((row = mysql_fetch_row(resultado)) != NUL){
		retorno = strcmp(user, row[1]);
		retorno2 = strcmp(pwd, row[2]);
		
		printf("%i %i", retorno, retorno2);
	}
	
		
	mysql_free_result(resultado);
	
}
int main(int argc, char *argv[]) {
	
	MYSQL *meubanco = conectarDB();
	
	int opc, idade;
	char buffer[10];
	login(meubanco);
	
 	return 0;
}
