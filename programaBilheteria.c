/*
IDE utilizada para desenvolvimento: DEVC++
*/

// Declara��o de bibliotecas
#include <stdio.h> // para entrada e sa�da de dados
#include <locale.h> // para permitir caracteres da l�ngua portuguesa
#include <string.h> // para trabalhar com string
#include <stdlib.h> // para incluir o system pause e rodar o execut�vel direto no Windows
#include <time.h> // utilizada para manipula��o de data e hora  
#include <stdbool.h> // para utilizar vari�veis booleanas 

//c�digo gerado com aux�lio de intelig�ncia artificial e modificado para adequa��o (gera��o de um c�digo �nico para o cliente)
struct DataHora {
    int ano, mes, dia, hora, minuto, segundo;
};
// Fun��o para c�luculo de c�digo �nico para o cliente com base na data e hora
struct DataHora obterDataHoraAtual();

// Fun��o para gerar um arquivo CSV com os dados fornecidos
void gerarArquivoCSV(char divulgacaoStr[], char faixaEtariaStr[], char temaInteresseStr[], char motivoVisitaStr[], char escolaridadeStr[], char acessibilidadeStr[], int inteira, int meia, int isencao, int numCliente, int dinheiro, int credito, int debito, int pix, float valorTotal); 

// Fun��o para gerar um arquivo CSV com os dados fornecidos
void atualizarArquivoCSV(char divulgacaoStr[], char faixaEtariaStr[], char temaInteresseStr[], char motivoVisitaStr[], char escolaridadeStr[], char acessibilidadeStr[], int inteira, int meia, int isencao, int numCliente, int dinheiro, int credito, int debito, int pix, float valorTotal); 

// Declara��o de fun��o para c�cular a m�dia de tipos de pagamento (Inteira, Meia Entrada e Isen��o)
void atualizarPorcentagens(int inteira, int meia, int isencao, float *calcMediaInteira, float *calcMediaMeia, float *calcMediaIsencao); 

// in�cio do m�todo main
int main() {
    setlocale(LC_ALL, "Portuguese");
    
    // Declara��o de vari�veis e atribui��es de valores
    //question�rio
	char respQuestionario[5];
	int divulgacao, faixaEtaria, motivoVisita, escolaridade, acessibilidade;
	char divulgacaoStr[30]="";
	char faixaEtariaStr[30]="";
	char temaInteresseStr[50]="";
	char motivoVisitaStr[30]="";
	char escolaridadeStr[50]="";
	char acessibilidadeStr[30]="";
	
	// avalia��o para resposta do question�rio
	bool questionarioRespondido = false;
	int tipoAcessib = 0;
	
	//programa
	char adquirirAtracao[5];
	char reservaSala1[5][6][50]; // Matriz para armazenar fila, coluna e nome - sala 1
	char reservaSala2[5][6][50]; // Matriz para armazenar fila, coluna e nome - sala 2
    char reservaSala3[5][6][50]; // Matriz para armazenar fila, coluna e nome - sala 3
    char reservaSala4[5][6][50]; // Matriz para armazenar fila, coluna e nome - sala 4
	char nomeAtracao[70];
	int i, j, k, menuAtracao, menuFuncao, primeiraExecucao = 1, arquivoGerado = 0, fila, cadeira;
	int formaPgto = 0, dinheiro = 0, credito = 0, debito = 0, pix = 0;
	int salaVazia = 0, sala1 = 0, sala2 = 0, sala3 = 0, sala4 = 0; 
    int numCliente = 0, meia = 0, inteira = 0, isencao = 0, tipoEntrada = 0, atracao = 0, codCliente = 0;  
	float valorTotal = 0.0;
	//declara��o de constante valor integral
    const float VALOR_ENTRADA = 60.00;
    
	// pagamento
	int numClientePgto = 0, pgtoMeia = 0, pgtoInteira = 0, comIsencao = 0; 			
	float valorInteira = 0.0, valorMeia = 0.0, valorTotalPgto = 0.0;
	bool pgtoPendente = false;
	char resposta[5]; // Vari�vel para armazenar a resposta do usu�rio S ou N
	
	// para individualiza��o de cada cliente ao chamar a fun��o gerar ou atualizarArquivoCSV
	int csvInteira = 0, csvMeia = 0, csvIsencao = 0, numClienteCSV = 0, dinheiroCSV = 0, creditoCSV = 0, debitoCSV = 0, pixCSV = 0;
	
	
	// Inicializando a matriz com strings vazias. Evitar erro ao listar reserva (menu 4)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            for (k = 0; k < 50; k++) {
                reservaSala1[i][j][k] = '\0'; // Inicializa cada elemento com uma string vazia
				reservaSala2[i][j][k] = '\0'; // Inicializa cada elemento com uma string vazia
				reservaSala3[i][j][k] = '\0'; // Inicializa cada elemento com uma string vazia
				reservaSala4[i][j][k] = '\0'; // Inicializa cada elemento com uma string vazia
            }
        }
    }
	do{//estrutura de repeti��o caso o usu�rio cancele a opera��o e garantir que o programa n�o seja fechado
		do { // menuFuncao 
		
			if (questionarioRespondido == false){ //se afirma��o verdadeira, chama o question�rio
		
				printf("**************************************************\n");
				printf("======== BEM-VINDO AO MUSEU MULTITEM�TICO ========\n");
				printf("**************************************************\n");
				
				do {
					printf("\nVoc� poderia responder a um breve question�rio?\n");
					printf("\nToda e qualquer informa��o ser� devidamente tra-\ntada, segundo a Lei Geral de Prote��o de Dados.\n");
					printf("Sua resposta ser� utilizada para conhecer o p�bli-\nco visitante e melhorar nossos servi�os.\n");
					printf("\nDigite 'S' para (sim) ou 'N' para (n�o): ");	        
					scanf("%1s", respQuestionario);
				
					// Converter a resposta para letras min�sculas para tornar a compara��o insens�vel a mai�sculas e min�sculas    
					respQuestionario[0] = tolower(respQuestionario[0]);
					        
					if (respQuestionario[0] == 's') { // se o usu�rio optar por sim ele n�o ser� obrigado a responder novamente o question�rio
					    questionarioRespondido = true;			            
					    printf("\nComo voc� ficou sabendo da exist�ncia deste evento?\n");
						printf("(1) Internet\t\t(2) M�dia Social\n(3) Amigos ou Fam�lia\t(4) Outros\nOp��o: ");
						scanf("%d", &divulgacao);
					
						while(divulgacao < 1 || divulgacao > 4){
							printf("\nComo voc� ficou sabendo da exist�ncia deste museu?\n");
							printf("(1) Internet\t\t(2) M�dia Social\n(3) Amigos ou Fam�lia\t(4) Outros\nOp��o: ");
							scanf("%d", &divulgacao);
						}
										
						if(divulgacao == 1){ // at� 4 itens else if, acima switch case
							strcpy(divulgacaoStr, "Internet");
						} else if(divulgacao == 2){
							strcpy(divulgacaoStr, "M�dia Social");
						} else if(divulgacao == 3){
							strcpy(divulgacaoStr, "Amigos ou Fam�lia");
						} else if(divulgacao == 4){
							strcpy(divulgacaoStr, "Outros");
						}
			
						printf("\nQual � a sua faixa et�ria?\n");
						printf("(1) at� 21 anos\t\t(2) de 22 a 45 anos\n(3) de 46 a 60 anos\t(4) mais de 60 anos\nOp��o: ");
						scanf("%d", &faixaEtaria);
					
						while(faixaEtaria < 1 || faixaEtaria > 5){
							printf("\nQual � a sua faixa et�ria?\n");
							printf("(1) at� 21 anos\t\t(2) de 22 a 45 anos\n(3) de 46 a 60 anos\t(4) mais de 60 anos\nOp��o: ");
							scanf("%d", &faixaEtaria);
						}
				
						switch (faixaEtaria){ // 5 itens ou mais switch case
							case 1:
								strcpy(faixaEtariaStr, "at� 21 anos");	
								break;
							case 2:
								strcpy(faixaEtariaStr, "de 22 a 45 anos");	
								break;
							case 3:
								strcpy(faixaEtariaStr, "de 46 a 65 anos");	
								break;
							case 4:
								strcpy(faixaEtariaStr, "mais de 65 anos");	
								break;
						}
						
						printf("\nQual � a principal raz�o da sua visita?\n"); 
						printf("(1) Lazer\t(2) Entretenimento\n(3) Cultura\t(4) Outros\nOp��o: ");
						scanf("%d", &motivoVisita);
				
						while(motivoVisita < 1 || motivoVisita > 4){	
							printf("\nQual � a principal raz�o da sua visita?\n"); 
							printf("(1) Lazer\t(2) Entretenimento\n(3) Cultura\t(4) Outros\nOp��o: ");
							scanf("%d", &motivoVisita);
						}
				
						if(motivoVisita == 1){
							strcpy(motivoVisitaStr, "Lazer");
						} else if(motivoVisita == 2){
							strcpy(motivoVisitaStr, "Entretenimento");
						} else if(motivoVisita == 3){
							strcpy(motivoVisitaStr, "Cultura");
						} else if(motivoVisita == 4){
							strcpy(motivoVisitaStr, "Outros");
						}
		
						printf("\nQual � o seu n�vel de escolaridade:\n");
						printf("(1) Ensino Fundamental\t(2) Ensino M�dio\n(3) Ensino Superior\t(4) Especializa��o\n(5) Mestrado/Doutorado\t(6) Sem educa��o formal\n");
						printf("Op��o: ");
						scanf("%d", &escolaridade);
							
						while(escolaridade < 1 || escolaridade > 6){	
							printf("\nQual � o seu n�vel de escolaridade:\n");
							printf("(1) Ensino Fundamental\t(2) Ensino M�dio\n(3) Ensino Superior\t(4) Especializa��o\n(5) Mestrado/Doutorado\t(6) Sem educa��o formal\n");
							printf("Op��o: ");
							scanf("%d", &escolaridade);
						}
						
						switch (escolaridade){
							case 1:
								strcpy(escolaridadeStr, "Ensino Fundamental");
								break;
							case 2:
								strcpy(escolaridadeStr, "Ensino M�dio");
								break;
							case 3:
								strcpy(escolaridadeStr, "Ensino Superior");	
								break;
							case 4:
								strcpy(escolaridadeStr, "Especializa��o");	
								break;
							case 5:
								strcpy(escolaridadeStr, "Mestrado/Doutorado");	
								break;
							case 6:
								strcpy(escolaridadeStr, "Sem educa��o formal");	
								break;				
						}
			
						printf("\nVoc� necessita de alguma forma de acessibilidade\npara uma imers�o completa ao museu?\n");
						printf("(1) Sim\t(2) N�o - Op��o: ");
						scanf("%d", &acessibilidade);
							
						while(acessibilidade < 1 || acessibilidade > 2){	
							printf("\nVoc� necessidade de alguma forma de acessibilidade\npara uma imers�o completa ao museu?\n");
							printf("(1) Sim\t(2) N�o - Op��o: ");
							scanf("%d", &acessibilidade);
						}
						
						if (acessibilidade == 1){
							printf("\nQual o tipo de acessibilidade voc� necessita?\n");
							printf("(1) Visual\t\t(2) Auditiva\n(3) Mobilidade\t\t(4) Outras formas\nOp��o: ");
							scanf("%d", &tipoAcessib);
					
						while(tipoAcessib < 1 || tipoAcessib > 4){	
							printf("\nQual o tipo de acessibilidade voc� necessita?\n");
							printf("(1) Visual\t\t(2) Auditiva\n(3) Mobilidade\t\t(4) Outras formas\nOp��o: ");
							scanf("%d", &tipoAcessib);
						}
						}
					
						if (tipoAcessib == 1){
								strcpy(acessibilidadeStr, "Visual");	
							} else if (tipoAcessib == 2){
								strcpy(acessibilidadeStr, "Auditiva");
							} else if (tipoAcessib == 3){
								strcpy(acessibilidadeStr, "Mobilidade");
							} else if (tipoAcessib == 4){ 
								strcpy(acessibilidadeStr, "Outras formas");
							}
					
						if (acessibilidade == 2){
							strcpy(acessibilidadeStr, "N�o necessita");
						}
						
					system("cls"); //limpa a tela	
					printf("Obrigado por sua participa��o.");        		
					break;
					} else if (respQuestionario[0] == 'n') {
				        questionarioRespondido = false;
				        break;
				    } else {
					    printf("\nResposta inv�lida.\nPor favor, digite 'S' para (sim) ou 'N' para (n�o).\n ");
					}
				
				} while ("n"); 	
			}
		
			atracao = 0; //permite que o usu�rio mude de atra��o.
			printf("\nMenu\n");
	    	printf("(1) Atra��es\t\t(2) Fazer reserva\n(3) Gerar ingresso\t(4) Cadeira dispon�vel\n(5) Sair\t\tEscolha sua op��o: "); 
			scanf("\n%d", &menuFuncao);
		
			while(menuFuncao < 1 || menuFuncao > 5){
				printf("\nA op��o %d n�o existe, escolha novamente:\n", menuFuncao);
				printf("Menu\n"); 
				printf("(1) Atra��es\t\t(2) Fazer reserva\n(3) Gerar ingresso\t(4) Cadeira dispon�vel\n(5) Sair\t\tEscolha sua op��o: ");
	        	scanf("\n%d", &menuFuncao);
			}
			if (menuFuncao == 1){ //condi��o para retornar ao menu, caso o usu�rio, ap�s escolher S "adquirir exposi��o", queira mudar de exposi��o  
				atracao = 0;
			}
			
	        switch (menuFuncao) {
	            case 1:
					if (tipoEntrada == 1 || tipoEntrada == 2 || tipoEntrada == 3){
						printf("\nH� uma reserva em andamento!\n");
						printf("\nEscolha o menu 2 para continuar comprando OU\nmenu 3 para gerar o ingresso\n");
					} else {
					
						printf("\n**************************************************\n");
					    printf("======== BEM-VINDO AO MUSEU MULTITEM�TICO ========\n");
					    printf("**************************************************\n");
					    printf("Aquisi��o de bilhetes de entrada:\n");
					    printf("Valor Integral:     R$ %.2f\n", VALOR_ENTRADA);
					    printf("Valor Meia entrada: R$ %.2f\n", VALOR_ENTRADA / 2);
					    printf("Isen��o de acordo com a legisla��o vigente.\n");
				    
						do{
							if (atracao != 0){
								break;
							}
							printf("\nVeja uma sinopse das exposi��es dispon�veis:\n");
					    	printf("(1) 100 anos da Semana de Arte Moderna\n(2) 150 anos de Santos Dumont\n(3) Jogos Ol�mpicos Paris 2024\n(4) Ind�stria 4.0 Tecnologia e Futuro\nEscolha sua atra��o: ");
					    	scanf("%d", &menuAtracao);
							
							while(menuAtracao < 1 || menuAtracao > 4){
								printf("\nA op��o %d n�o existe, escolha uma nova op��o:\n", menuAtracao);
								printf("\nVeja uma sinopse das atra��es dispon�veis:\n");
					    		printf("(1) 100 anos da Semana de Arte Moderna\n(2) 150 anos de Santos Dumont\n(3) Jogos Ol�mpicos Paris 2024\n(4) Ind�stria 4.0 Tecnologia e Futuro\nEscolha sua atra��o: ");
					    		scanf("%d", &menuAtracao);		
							}
						
							do{	
								switch (menuAtracao){
									case 1:
										printf("\n100 anos da Semana de Arte Moderna.\n");
										printf("\nA Semana de Arte Moderna de 1922 revolucio-\nnou a cultura brasileira com manifesta��es\nart�sticas inovadoras, desafiando normas aca-\nd�micas e europeias. Marcou o in�cio do Mo-\ndernismo no pa�s, introduzindo novas lin-\nguagens e abordagens nacionalistas que in-\nfluenciaram gera��es futuras de artistas e\nmoldaram a identidade cultural brasileira. \nSeu centen�rio celebra um legado duradouro.\n\n");
										break;
									case 2:
										printf("\n150 anos de Santos Dumont.\n");
										printf("\nOs 150 anos de Santos Dumont celebram a vida\ne legado do pioneiro da avia��o. \nAlberto Santos Dumont, nascido em 1873, foi um \nvision�rio brasileiro que realizou voos hist�- \nricos com aeronaves ultra leves e contribuiu signi-\nficativamente para o desenvolvimento da avia��o \nmundial. Seus feitos, como o voo do 14-Bis em \n1906, marcaram avan�os cruciais na hist�ria da \ntecnologia aeron�utica, solidificando seu lugar \ncomo um �cone da inova��o e coragem. A comemora-\n��o de seu anivers�rio reconhece suas contribui-\n��es not�veis para a humanidade.\n\n");
										break;
									case 3:
										printf("\nJogos Ol�mpicos Paris 2024.\n");
										printf("\nOs Jogos Ol�mpicos de 2024 ser�o sediados em \nParis, Fran�a, celebrando esportes, cultura \ne sustentabilidade. Atletas de todo o mundo \ncompetir�o em um ambiente moderno, refletindo \nos valores ol�mpicos e deixando um legado \nduradouro para a cidade.\n\n");
										break;
									case 4:
										printf("\nInd�stria 4.0 Tecnologia e Futuro.\n");
										printf("\nA Ind�stria 4.0 � um conceito que se refere\n� quarta revolu��o industrial, caracterizada \npela integra��o de tecnologias avan�adas de \nautoma��o, an�lise de dados, Internet das \nCoisas (IoT) e intelig�ncia artificial nas \nopera��es industriais. Essa revolu��o busca \ntransformar profundamente os processos de \nprodu��o e fabrica��o, resultando em f�bricas \nmais eficientes, flex�veis e conectadas.\n\n");
											
								} //fechamento do switch case
							
			        			printf("\nAdquirir esta atra��o? \nDigite 'S' para (sim) ou 'N' para (n�o): ");
						        scanf("%1s", adquirirAtracao);
								printf("\n");
						        // Converter a resposta para letras min�sculas para tornar a compara��o insens�vel a mai�sculas e min�sculas    
						        adquirirAtracao[0] = tolower(adquirirAtracao[0]);
						        
			        			if (adquirirAtracao[0] == 's') { 
			            			system("cls");
									if (menuAtracao == 1){
										atracao = 1;
										sala1 = 1, sala2 = 0, sala3 = 0, sala4 = 0;
										strcpy(nomeAtracao, "\n Sala 1\n Exposi��o: 100 anos da Semana de Arte Moderna");
										strcpy(temaInteresseStr, "100 anos da Semana de Arte Moderna");
									} else if (menuAtracao == 2){
										atracao = 2;
										sala1 = 0, sala2 = 2, sala3 = 0, sala4 = 0;
										strcpy(nomeAtracao, "\n Sala 2\n Exposi��o: 150 anos de Santos Dumont");
										strcpy(temaInteresseStr, "150 anos de Santos Dumont");	
									}else if (menuAtracao == 3){
										atracao = 3;
										sala1 = 0, sala2 = 0, sala3 = 3, sala4 = 0;
										strcpy(nomeAtracao, "\n Sala 3\n Exposi��o: Jogos Ol�mpicos Paris 2024");
										strcpy(temaInteresseStr, "Jogos Ol�mpicos Paris 2024");	
									}else{
										atracao = 4;
										sala1 = 0, sala2 = 0, sala3 = 0, sala4 = 4;
										strcpy(nomeAtracao, "\n Sala 4\n Exposi��o: Ind�stria 4.0 Tecnologia e Futuro");
										strcpy(temaInteresseStr, "Ind�stria 4.0 Tecnologia e Futuro");
									}
								    break;
							    } else if (adquirirAtracao[0] == 'n') {
							    	 menuAtracao = 1;
									 break; 
							    } else {
							        printf("\nResposta inv�lida. Por favor, digite 'S' para (sim) ou 'N' para (n�o): ");
							    }
						
							} while (adquirirAtracao[0] == 'n');
						} while (menuAtracao != 4);
		
					    printf("%s\n", nomeAtracao);
					    questionarioRespondido = true;
					    salaVazia = 1; 
						}
	        		break;
				case 2:
					questionarioRespondido = true; 
					if (menuAtracao == 0){
						printf("\nPasso 1: Escolha a atra��o.\nPasso 2: Fa�a reserva.\nPasso 3: Gerar ingresso .\n");
						break;
					}
					// Fazer reserva
					printf("\nEscolha de assento:");
	                printf("\nDigite o n�mero da fileira: ");
	                scanf("%d", &fila);
	                printf("\nDigite o n�mero da cadeira: ");
	                scanf("%d", &cadeira);
	
	                while (fila < 1 || fila > 6 || cadeira < 1 || cadeira > 5) {
	                    printf("\nTentativa inv�lida. Disponibilidade de 6 fileiras e 5 colunas de cadeiras!");
	                    printf("\nDigite o n�mero da fileira: ");
	                    scanf("%d", &fila);
	                    printf("\nDigite o n�mero da cadeira: ");
	                    scanf("%d", &cadeira);
	                }
	
					if (sala1 == 1){	
		                if (reservaSala1[fila - 1][cadeira - 1][0] != '\0') {
		                    printf("\nCadeira j� reservada! Escolha outra op��o.\n\n");
		                    break;
		                } else {
		                    getchar(); //limpeza de buffer
							printf("\nDigite um nome para reserva: ");
		                    scanf(" %[^\n]", reservaSala1[fila - 1][cadeira - 1]);
		                    printf("Reserva realizada com sucesso!\n");    
		                }
	            	}
	
					if (sala2 == 2){	
		                if (reservaSala2[fila - 1][cadeira - 1][0] != '\0') {
		                    printf("\nCadeira j� reservada! Escolha outra op��o.\n\n");
		                    break;
		                } else {
		                    getchar(); //limpeza de buffer
							printf("\nDigite um nome para reserva: ");
		                    scanf(" %[^\n]", reservaSala2[fila - 1][cadeira - 1]);
		                    printf("Reserva realizada com sucesso!\n");    
		                }
	            	}
					
					if (sala3 == 3){	
		                if (reservaSala3[fila - 1][cadeira - 1][0] != '\0') {
		                    printf("\nCadeira j� reservada! Escolha outra op��o.\n\n");
		                    break;
		                } else {
		                    getchar(); //limpeza de buffer
							printf("\nDigite um nome para reserva: ");
		                    scanf(" %[^\n]", reservaSala3[fila - 1][cadeira - 1]);
		                    printf("Reserva realizada com sucesso!\n");    
		                }
	            	}
					
					if (sala4 == 4){	
		                if (reservaSala4[fila - 1][cadeira - 1][0] != '\0') {
		                    printf("\nCadeira j� reservada! Escolha outra op��o.\n\n");
		                    break;
		                } else {
		                    getchar(); //limpeza de buffer
							printf("\nDigite um nome para reserva: ");
		                    scanf(" %[^\n]", reservaSala4[fila - 1][cadeira - 1]);
		                    printf("Reserva realizada com sucesso!\n");    
		                }
	            	}
	            	printf("\nTipo de entrada:\n");
					printf("Valor Integral:     R$ %.2f\n", VALOR_ENTRADA);
	    			printf("Valor Meia entrada: R$ %.2f\n", VALOR_ENTRADA / 2);
	    			printf("Isen��o de acordo com a legisla��o vigente.\n");
					printf("\nTipo de entrada: \n(1) Inteira (2) Meia Entrada  (3) Isen��o\n");
			        printf("Sua escolha: ");
					scanf("%d", &tipoEntrada);
							
			        while (tipoEntrada < 1 || tipoEntrada > 3)  {
			        	printf("\nA op��o %d n�o existe, escolha uma nova op��o:\n", tipoEntrada);
			            printf("\nTipo de entrada: \n(1) Inteira (2) Meia Entrada (3) Isen��o\n");
			            printf("Sua escolha: ");
						scanf(" %d", &tipoEntrada);
			        }
			        				
					//contabilidade do tipo de entrada e bilheteria
					if (tipoEntrada == 1){ 
					    valorTotal += VALOR_ENTRADA;
					    valorTotalPgto += VALOR_ENTRADA;//mesma fun��o do valorTotal, utilizado no pagamento, pois o usu�rio pode pagar mais de uma vez  
					    valorInteira += VALOR_ENTRADA;
						inteira++; // vari�vel para controle do total de inteiras do relat�rio
						pgtoInteira++;// mesma fun��o de (inteira++), utilizado no pagamento, pois o usu�rio pode pagar mais de uma vez
						csvInteira++;//individualiza��o do cliente a cada chamada da fun��o gerar ou atualizarArquivoCSV
						pgtoPendente = true; // para garantir a chamada da forma de pagamento
						
					} else if (tipoEntrada == 2){
					    valorTotal += VALOR_ENTRADA / 2;
					    valorTotalPgto += VALOR_ENTRADA / 2;//mesma fun��o do valorTotal, utilizado no pagamento, pois o usu�rio pode pagar mais de uma vez
					    valorMeia += VALOR_ENTRADA / 2;
						meia++; // vari�vel para controle do total de meias do relat�rio
						pgtoMeia++;// mesma fun��o de (meia++), mas para pagamento, pois o usu�rio pode pagar mais de uma vez
						csvMeia++;//individualiza��o do cliente a cada chamada da fun��o gerar ou atualizarArquivoCSV
						pgtoPendente = true; //para garantir a chamada da forma de pagamento
						
					} else {
					    isencao++; // vari�vel para controle do total de isen��o do relat�rio
					    comIsencao++; // mesma fun��o de (isen��o++), mas para pagamento, pois o usu�rio pode pagar mais de uma vez
						csvIsencao++;//individualiza��o do cliente a cada chamada da fun��o gerar ou atualizarArquivoCSV
					}
					 
					numClienteCSV++;
					numClientePgto++;
					numCliente++;
					break;
					
				case 3:
					//Gerar ingresso / Pagamento        	 		
					while (formaPgto >= 1 && formaPgto <=4){//pr� avalia��o antes de entrar no pagamento
						printf("\nO carrinho est� vazio OU \nO pagamento j� foi realizado OU\nUsu�rio isento de pagamento!\n");
						printf("\n");
						break;
					}
					
					if (pgtoPendente){
						printf("\nForma de Pagamento:\n");
						printf("(1) Dinheiro (2) Cart�o de Cr�dito  (3) Cart�o de D�bito (4) Pix\n");
						printf("Sua escolha: ");
						scanf("%d", &formaPgto);
						pgtoPendente = false; // retorna a vari�vel a condi��o inicial
					
					while (formaPgto < 1 || formaPgto > 4) {
						printf("\nA op��o %d n�o existe\n", formaPgto);
						printf("\nForma de Pagamento:\n");
						printf("(1) Dinheiro (2) Cart�o de Cr�dito  (3) Cart�o de D�bito (4) Pix\n");
						printf("Sua escolha: ");
						scanf("%d", &formaPgto);
						pgtoPendente = false; // retorna a vari�vel a condi��o inicial
					}
						
					} else {
						printf("\nPasso 1: Escolha a atra��o.\nPasso 2: Fa�a reserva.\nPasso 3: Gerar ingresso.\n");
						questionarioRespondido = true;
					}
					
					//caso a �ltima aquisi��o for tipoEntrada=3, o if abaixo garante a contabiliza��o da forma pgto
					if (formaPgto == 1){
						dinheiro++;
						dinheiroCSV++;//individualiza��o da forma de pgto a cada chamada da fun��o gerar ou atualizarArquivoCSV
					} else if (formaPgto == 2){
						credito++;
						creditoCSV++;//individualiza��o da forma de pgto a cada chamada da fun��o gerar ou atualizarArquivoCSV
					} else if (formaPgto == 3){
						debito++;
						debitoCSV++;//individualiza��o da forma de pgto a cada chamada da fun��o gerar ou atualizarArquivoCSV
					} else if (formaPgto == 4){
						pix++;
						pixCSV++;//individualiza��o da forma de pgto a cada chamada da fun��o gerar ou atualizarArquivoCSV
					}
			
					if (tipoEntrada == 0){
						//se verdadeiro o cliente j� efetuou o pagamento ou j� tentou gerar ingresso sem escolher uma atra��o e fazer reserva
					} else {
					    system("cls");
						printf("Reserva confirmada.");
						printf("\nRetire seu ingresso.\n");
						
						//impress�o do ingresso do cliente
						printf("\n===============================================\n");
						printf("============= MUSEU MULTITEM�TICO =============\n");
						
						printf("%s", nomeAtracao);
						// Gera��o de c�digo do cliente contendo ano, m�s, dia, hora, min, seg e um contador identificador
						struct DataHora dataHoraAtual = obterDataHoraAtual();
						printf(" \n C�digo identificador do Cliente:\n");
	    				printf("   %d%d%d%d%d%d%d\n", dataHoraAtual.ano, dataHoraAtual.mes, dataHoraAtual.dia, dataHoraAtual.hora, dataHoraAtual.minuto, dataHoraAtual.segundo, codCliente++);
						printf(" \n Reserva realizada para %d cliente(s).\n", numClientePgto);
						printf("\n Inteira:\n"); 
						printf("   %d Ingresso(s)...........R$ %.2f\n", pgtoInteira, valorInteira); 
						printf(" Meia Entrada:\n");
						printf("   %d Ingresso(s)...........R$ %.2f\n", pgtoMeia, valorMeia); 
						printf(" Isento:\n");
						printf("   %d Ingresso(s)...........R$ 0,00\n", comIsencao);
						printf("\n Total pago:...............R$ %.2f\n", valorTotalPgto);
					    //aproveita o c�lculo da fun��o de gera��o de c�digo do cliente e extrai a data atual
						printf(" Compra realizada em: %d/%d/%d\n", dataHoraAtual.dia, dataHoraAtual.mes, dataHoraAtual.ano);
						printf("\n APRESENTE ESTE INGRESSO NA ENTRADA\n DA EXPOSI��O E UM DOCUMENTO COM FOTO.\n");
						printf("===============================================\n\n");		
						
						tipoEntrada = 0; //nova atribui��o de valor para impedir pagamento duplicado
							
						// Nova atribui��o de valor caso o usu�rio fa�a um segundo pagamento ou mais
						//tipos inteiros
						numClientePgto = 0, pgtoInteira = 0, pgtoMeia = 0,  comIsencao = 0;
						//tipos float
						valorTotalPgto = 0.0, valorMeia = 0.0, valorInteira = 0.0; 
					
						if (arquivoGerado == 0){ 
							// Chamando a fun��o para gerar o arquivo CSV, primeiro pagamento 
							gerarArquivoCSV(divulgacaoStr, faixaEtariaStr, temaInteresseStr, motivoVisitaStr, escolaridadeStr, acessibilidadeStr, csvInteira, csvMeia, csvIsencao, numClienteCSV, dinheiroCSV, creditoCSV, debitoCSV, pixCSV, valorTotal); 
							arquivoGerado = 1;
						} else {
							// Chamando a fun��o para atualizar o arquivo CSV, segundo pagamento em diante
							atualizarArquivoCSV(divulgacaoStr, faixaEtariaStr, temaInteresseStr, motivoVisitaStr, escolaridadeStr, acessibilidadeStr, csvInteira, csvMeia, csvIsencao, numClienteCSV, dinheiroCSV, creditoCSV, debitoCSV, pixCSV, valorTotal); 	
						}
						csvInteira = 0, csvMeia = 0, csvIsencao = 0, numClienteCSV = 0, dinheiroCSV = 0, creditoCSV = 0, debitoCSV = 0, pixCSV = 0;
						valorTotal = 0.0;
						formaPgto = 0; // para impedir dois pagamentos da mesma compra, salvo se o usu�rio realizar nova reserva
						salaVazia = 0, sala1 = 0, sala2 = 0, sala3 = 0, sala4 = 0;
						menuAtracao = 0; //n�o permite que o usu�rio fa�a reserva sem escolher a atra��o primeiro
						
						do {
					        printf("Continuar comprando? \nDigite 'S' para (sim) ou 'N' para (n�o): ");
					        scanf("%1s", resposta);
					        // Converter a resposta para letras min�sculas para tornar a compara��o insens�vel a mai�sculas e min�sculas    
					        resposta[0] = tolower(resposta[0]);
					        if (resposta[0] == 's') { // se o usu�rio optar por sim ele n�o ser� obrigado a responder novamente o question�rio
					            questionarioRespondido = true;
					            strcpy(divulgacaoStr, "''"); //caso o usu�rio continue a comprar os valores n�o ser�o duplicados no arquivo csv
								strcpy(faixaEtariaStr, "''");
							    strcpy(motivoVisitaStr, "''");
								strcpy(escolaridadeStr, "''");
							    strcpy(acessibilidadeStr, "''");
								break;
					        } else if (resposta[0] == 'n') {
					            questionarioRespondido = false;				
								system("cls"); //limpa a tela
								strcpy(divulgacaoStr, ""); //caso o usu�rio continue a comprar os valores n�o ser�o duplicados no arquivo csv
								strcpy(faixaEtariaStr, "");
							    strcpy(motivoVisitaStr, "");
								strcpy(escolaridadeStr, "");
							    strcpy(acessibilidadeStr, "");
								break; // Sai do loop
					        } else {
					            printf("\nResposta inv�lida. Por favor, digite 'S' para (sim) ou 'N' para (n�o): ");
					        }
					    } while ("n");
						 
					}
					break;
	
				case 4: 
					if (salaVazia == 0){
						questionarioRespondido = true; //para evitar o question�rio e entrar no menu
						printf("\nFun��o dispon�vel ap�s a escolha de uma atra��o.\n");
					}
					
					if (sala1 == 1){
						if (reservaSala1[i][j][0] == '\0') {
			                printf("Fila %d, Cadeira %d: Dispon�vel\n", i + 1, j + 1);
			            }    
						//varre a matriz e inclui a palavra "Dispon�vel" aos locais n�o reservados     
			            printf("\n==== CADEIRAS DISPON�VEIS ====\n");
			            for (i = 0; i < 5; i++) {
			                for (j = 0; j < 6; j++) {
			                    if (reservaSala1[i][j][0] == '\0') {
			                        printf("Fila %d, Cadeira %d: Dispon�vel\n", i + 1, j + 1); 
			                    }
			                }
			                printf("\n");
			            }
		            }
		            
		            if (sala2 == 2){
						if (reservaSala2[i][j][0] == '\0') {
			                printf("Fila %d, Cadeira %d: Dispon�vel\n", i + 1, j + 1);
			            }    
						//varre a matriz e inclui a palavra "Dispon�vel" aos locais n�o reservados     
			            printf("\n==== CADEIRAS DISPON�VEIS ====\n");
			            for (i = 0; i < 5; i++) {
			                for (j = 0; j < 6; j++) {
			                    if (reservaSala2[i][j][0] == '\0') {
			                        printf("Fila %d, Cadeira %d: Dispon�vel\n", i + 1, j + 1); 
			                    }
			                }
			                printf("\n");
			            }
		            }
					if (sala3 == 3){
						if (reservaSala3[i][j][0] == '\0') {
			                printf("Fila %d, Cadeira %d: Dispon�vel\n", i + 1, j + 1);
			            }    
						//varre a matriz e inclui a palavra "Dispon�vel" aos locais n�o reservados     
			            printf("\n==== CADEIRAS DISPON�VEIS ====\n");
			            for (i = 0; i < 5; i++) {
			                for (j = 0; j < 6; j++) {
			                    if (reservaSala3[i][j][0] == '\0') {
			                        printf("Fila %d, Cadeira %d: Dispon�vel\n", i + 1, j + 1); 
			                    }
			                }
			                printf("\n");
			            }
		            }
		            
		            if (sala4 == 4){
						if (reservaSala4[i][j][0] == '\0') {
			                printf("Fila %d, Cadeira %d: Dispon�vel\n", i + 1, j + 1);
			            }    
						//varre a matriz e inclui a palavra "Dispon�vel" aos locais n�o reservados     
			            printf("\n==== CADEIRAS DISPON�VEIS ====\n");
			            for (i = 0; i < 5; i++) {
			                for (j = 0; j < 6; j++) {
			                    if (reservaSala4[i][j][0] == '\0') {
			                        printf("Fila %d, Cadeira %d: Dispon�vel\n", i + 1, j + 1); 
			                    }
			                }
			                printf("\n");
			            }
		            }
	                break;	 
	            case 5: //cancelar compra e rotornar ao in�cio
	            	system("cls");
	            	
	            	if (pgtoPendente && sala1 == 1){								
						if (fila != 0 && cadeira != 0){
							reservaSala1[fila - 1][cadeira - 1][0] = '\0';
						}	
					}
					
					if (pgtoPendente && sala1 == 2){
						if (fila != 0 && cadeira != 0){
							reservaSala2[fila - 1][cadeira - 1][0] = '\0';
						}	
					}
					
					if (pgtoPendente && sala3 == 3){
						if (fila != 0 && cadeira != 0){
							reservaSala3[fila - 1][cadeira - 1][0] = '\0';
						}	
					}
					
					if (pgtoPendente && sala4 == 4){
						if (fila != 0 && cadeira != 0){
							reservaSala4[fila - 1][cadeira - 1][0] = '\0';
						}	
					}
					
					// zerando as vari�veis
	            	tipoEntrada = 0;  
					numClientePgto = 0, pgtoInteira = 0, pgtoMeia = 0,  comIsencao = 0;
					valorTotalPgto = 0.0, valorMeia = 0.0, valorInteira = 0.0; 
					csvInteira = 0, csvMeia = 0, csvIsencao = 0, numClienteCSV = 0, dinheiroCSV = 0, creditoCSV = 0, debitoCSV = 0, pixCSV = 0;
					valorTotal = 0.0;
					formaPgto = 0; 
					salaVazia = 0, 
					sala1 = 0, sala2 = 0, sala3 = 0, sala4 = 0;
					char divulgacaoStr[30]="";
					char faixaEtariaStr[30]="";
				    char temaInteresseStr[50]="";
					char motivoVisitaStr[30]="";
					char escolaridadeStr[50]="";
				    char acessibilidadeStr[30]="";
				    menuAtracao = 0; 
					questionarioRespondido = false;
	            	break;		
			}
	    } while (menuFuncao != 5);
		} while (true); // loop caso o usu�rio escolha a fun��o 5	
    system("pause"); //aguarda o usu�rio para fechar a janela, importante caso execute o (.exe) no ambiente Windows
	return 0;
}

// Fun��o para c�lculo do c�digo de identifica��o do usu�rio com base na data e hora (c�digo criado com aux�lio de IA)
struct DataHora obterDataHoraAtual() {
    struct DataHora dataHora;
    time_t tempoAtual;
    struct tm *infoTempo;

    time(&tempoAtual); // Obt�m o tempo atual
    infoTempo = localtime(&tempoAtual); // Converte para a estrutura tm

    // Extrai as informa��es de data e hora
    dataHora.ano = infoTempo->tm_year + 1900; // Adicione 1900 ao ano
    dataHora.mes = infoTempo->tm_mon + 1;     // Os meses s�o indexados de 0 a 11
    dataHora.dia = infoTempo->tm_mday;
    dataHora.hora = infoTempo->tm_hour;
    dataHora.minuto = infoTempo->tm_min;
    dataHora.segundo = infoTempo->tm_sec;
    return dataHora;
}

// Fun��o para gerar um arquivo CSV com os dados fornecidos (c�digo criado com aux�lio de IA)
void gerarArquivoCSV(char divulgacaoStr[], char faixaEtariaStr[], char temaInteresseStr[], char motivoVisitaStr[], char escolaridadeStr[], char acessibilidadeStr[], int inteira, int meia, int isencao, int numCliente, int dinheiro, int credito, int debito, int pix, float valorTotal) {
			
    // Nome do arquivo CSV
    const char* nomeArquivo = "Relat�rio_Museu.csv";

    // Abrir o arquivo para escrita
    FILE* arquivo = fopen(nomeArquivo, "w");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
	fprintf(arquivo, "Divulga��o, Faixa Et�ria, Tema de Interesse, Motivo da visita, Escolaridade, Acessibilidade, Pagantes Inteira, Pagantes Meia Entrada, Clientes isentos, N�mero Clientes,Pgto dinheiro, Pgto Cr�dito, Pgto D�bito, Pgto PIX, Valor da Bilheteria\n");  
   
   	fprintf(arquivo, "%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%.0f\n", divulgacaoStr, faixaEtariaStr, temaInteresseStr, motivoVisitaStr, escolaridadeStr, acessibilidadeStr, inteira, meia, isencao, numCliente, dinheiro, credito, debito, pix, valorTotal);

    // Fechar o arquivo
    fclose(arquivo);
	
}

// Fun��o para gerar um arquivo CSV com os dados fornecidos (c�digo criado com aux�lio de IA)
void atualizarArquivoCSV(char divulgacaoStr[], char faixaEtariaStr[], char temaInteresseStr[], char motivoVisitaStr[], char escolaridadeStr[], char acessibilidadeStr[], int inteira, int meia, int isencao, int numCliente, int dinheiro, int credito, int debito, int pix, float valorTotal) {
			
    // Nome do arquivo CSV
    const char* nomeArquivo = "Relat�rio_Museu.csv";
	
	// Abrir o arquivo para escrita
    FILE* arquivo = fopen(nomeArquivo, "a");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
	fprintf(arquivo, "%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%.0f\n", divulgacaoStr, faixaEtariaStr, temaInteresseStr, motivoVisitaStr, escolaridadeStr, acessibilidadeStr, inteira, meia, isencao, numCliente, dinheiro, credito, debito, pix, valorTotal);

    // Fechar o arquivo
    fclose(arquivo);
				    
}

