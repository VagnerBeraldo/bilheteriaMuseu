/*
IDE utilizada para desenvolvimento: DEVC++
*/

// Declaração de bibliotecas
#include <stdio.h> // para entrada e saída de dados
#include <locale.h> // para permitir caracteres da língua portuguesa
#include <string.h> // para trabalhar com string
#include <stdlib.h> // para incluir o system pause e rodar o executável direto no Windows
#include <time.h> // utilizada para manipulação de data e hora  
#include <stdbool.h> // para utilizar variáveis booleanas 

//código gerado com auxílio de inteligência artificial e modificado para adequação (geração de um código único para o cliente)
struct DataHora {
    int ano, mes, dia, hora, minuto, segundo;
};
// Função para cáluculo de código único para o cliente com base na data e hora
struct DataHora obterDataHoraAtual();

// Função para gerar um arquivo CSV com os dados fornecidos
void gerarArquivoCSV(char divulgacaoStr[], char faixaEtariaStr[], char temaInteresseStr[], char motivoVisitaStr[], char escolaridadeStr[], char acessibilidadeStr[], int inteira, int meia, int isencao, int numCliente, int dinheiro, int credito, int debito, int pix, float valorTotal); 

// Função para gerar um arquivo CSV com os dados fornecidos
void atualizarArquivoCSV(char divulgacaoStr[], char faixaEtariaStr[], char temaInteresseStr[], char motivoVisitaStr[], char escolaridadeStr[], char acessibilidadeStr[], int inteira, int meia, int isencao, int numCliente, int dinheiro, int credito, int debito, int pix, float valorTotal); 

// Declaração de função para cácular a média de tipos de pagamento (Inteira, Meia Entrada e Isenção)
void atualizarPorcentagens(int inteira, int meia, int isencao, float *calcMediaInteira, float *calcMediaMeia, float *calcMediaIsencao); 

// início do método main
int main() {
    setlocale(LC_ALL, "Portuguese");
    
    // Declaração de variáveis e atribuições de valores
    //questionário
	char respQuestionario[5];
	int divulgacao, faixaEtaria, motivoVisita, escolaridade, acessibilidade;
	char divulgacaoStr[30]="";
	char faixaEtariaStr[30]="";
	char temaInteresseStr[50]="";
	char motivoVisitaStr[30]="";
	char escolaridadeStr[50]="";
	char acessibilidadeStr[30]="";
	
	// avaliação para resposta do questionário
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
	//declaração de constante valor integral
    const float VALOR_ENTRADA = 60.00;
    
	// pagamento
	int numClientePgto = 0, pgtoMeia = 0, pgtoInteira = 0, comIsencao = 0; 			
	float valorInteira = 0.0, valorMeia = 0.0, valorTotalPgto = 0.0;
	bool pgtoPendente = false;
	char resposta[5]; // Variável para armazenar a resposta do usuário S ou N
	
	// para individualização de cada cliente ao chamar a função gerar ou atualizarArquivoCSV
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
	do{//estrutura de repetição caso o usuário cancele a operação e garantir que o programa não seja fechado
		do { // menuFuncao 
		
			if (questionarioRespondido == false){ //se afirmação verdadeira, chama o questionário
		
				printf("**************************************************\n");
				printf("======== BEM-VINDO AO MUSEU MULTITEMÁTICO ========\n");
				printf("**************************************************\n");
				
				do {
					printf("\nVocê poderia responder a um breve questionário?\n");
					printf("\nToda e qualquer informação será devidamente tra-\ntada, segundo a Lei Geral de Proteção de Dados.\n");
					printf("Sua resposta será utilizada para conhecer o públi-\nco visitante e melhorar nossos serviços.\n");
					printf("\nDigite 'S' para (sim) ou 'N' para (não): ");	        
					scanf("%1s", respQuestionario);
				
					// Converter a resposta para letras minúsculas para tornar a comparação insensível a maiúsculas e minúsculas    
					respQuestionario[0] = tolower(respQuestionario[0]);
					        
					if (respQuestionario[0] == 's') { // se o usuário optar por sim ele não será obrigado a responder novamente o questionário
					    questionarioRespondido = true;			            
					    printf("\nComo você ficou sabendo da existência deste evento?\n");
						printf("(1) Internet\t\t(2) Mídia Social\n(3) Amigos ou Família\t(4) Outros\nOpção: ");
						scanf("%d", &divulgacao);
					
						while(divulgacao < 1 || divulgacao > 4){
							printf("\nComo você ficou sabendo da existência deste museu?\n");
							printf("(1) Internet\t\t(2) Mídia Social\n(3) Amigos ou Família\t(4) Outros\nOpção: ");
							scanf("%d", &divulgacao);
						}
										
						if(divulgacao == 1){ // até 4 itens else if, acima switch case
							strcpy(divulgacaoStr, "Internet");
						} else if(divulgacao == 2){
							strcpy(divulgacaoStr, "Mídia Social");
						} else if(divulgacao == 3){
							strcpy(divulgacaoStr, "Amigos ou Família");
						} else if(divulgacao == 4){
							strcpy(divulgacaoStr, "Outros");
						}
			
						printf("\nQual é a sua faixa etária?\n");
						printf("(1) até 21 anos\t\t(2) de 22 a 45 anos\n(3) de 46 a 60 anos\t(4) mais de 60 anos\nOpção: ");
						scanf("%d", &faixaEtaria);
					
						while(faixaEtaria < 1 || faixaEtaria > 5){
							printf("\nQual é a sua faixa etária?\n");
							printf("(1) até 21 anos\t\t(2) de 22 a 45 anos\n(3) de 46 a 60 anos\t(4) mais de 60 anos\nOpção: ");
							scanf("%d", &faixaEtaria);
						}
				
						switch (faixaEtaria){ // 5 itens ou mais switch case
							case 1:
								strcpy(faixaEtariaStr, "até 21 anos");	
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
						
						printf("\nQual é a principal razão da sua visita?\n"); 
						printf("(1) Lazer\t(2) Entretenimento\n(3) Cultura\t(4) Outros\nOpção: ");
						scanf("%d", &motivoVisita);
				
						while(motivoVisita < 1 || motivoVisita > 4){	
							printf("\nQual é a principal razão da sua visita?\n"); 
							printf("(1) Lazer\t(2) Entretenimento\n(3) Cultura\t(4) Outros\nOpção: ");
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
		
						printf("\nQual é o seu nível de escolaridade:\n");
						printf("(1) Ensino Fundamental\t(2) Ensino Médio\n(3) Ensino Superior\t(4) Especialização\n(5) Mestrado/Doutorado\t(6) Sem educação formal\n");
						printf("Opção: ");
						scanf("%d", &escolaridade);
							
						while(escolaridade < 1 || escolaridade > 6){	
							printf("\nQual é o seu nível de escolaridade:\n");
							printf("(1) Ensino Fundamental\t(2) Ensino Médio\n(3) Ensino Superior\t(4) Especialização\n(5) Mestrado/Doutorado\t(6) Sem educação formal\n");
							printf("Opção: ");
							scanf("%d", &escolaridade);
						}
						
						switch (escolaridade){
							case 1:
								strcpy(escolaridadeStr, "Ensino Fundamental");
								break;
							case 2:
								strcpy(escolaridadeStr, "Ensino Médio");
								break;
							case 3:
								strcpy(escolaridadeStr, "Ensino Superior");	
								break;
							case 4:
								strcpy(escolaridadeStr, "Especialização");	
								break;
							case 5:
								strcpy(escolaridadeStr, "Mestrado/Doutorado");	
								break;
							case 6:
								strcpy(escolaridadeStr, "Sem educação formal");	
								break;				
						}
			
						printf("\nVocê necessita de alguma forma de acessibilidade\npara uma imersão completa ao museu?\n");
						printf("(1) Sim\t(2) Não - Opção: ");
						scanf("%d", &acessibilidade);
							
						while(acessibilidade < 1 || acessibilidade > 2){	
							printf("\nVocê necessidade de alguma forma de acessibilidade\npara uma imersão completa ao museu?\n");
							printf("(1) Sim\t(2) Não - Opção: ");
							scanf("%d", &acessibilidade);
						}
						
						if (acessibilidade == 1){
							printf("\nQual o tipo de acessibilidade você necessita?\n");
							printf("(1) Visual\t\t(2) Auditiva\n(3) Mobilidade\t\t(4) Outras formas\nOpção: ");
							scanf("%d", &tipoAcessib);
					
						while(tipoAcessib < 1 || tipoAcessib > 4){	
							printf("\nQual o tipo de acessibilidade você necessita?\n");
							printf("(1) Visual\t\t(2) Auditiva\n(3) Mobilidade\t\t(4) Outras formas\nOpção: ");
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
							strcpy(acessibilidadeStr, "Não necessita");
						}
						
					system("cls"); //limpa a tela	
					printf("Obrigado por sua participação.");        		
					break;
					} else if (respQuestionario[0] == 'n') {
				        questionarioRespondido = false;
				        break;
				    } else {
					    printf("\nResposta inválida.\nPor favor, digite 'S' para (sim) ou 'N' para (não).\n ");
					}
				
				} while ("n"); 	
			}
		
			atracao = 0; //permite que o usuário mude de atração.
			printf("\nMenu\n");
	    	printf("(1) Atrações\t\t(2) Fazer reserva\n(3) Gerar ingresso\t(4) Cadeira disponível\n(5) Sair\t\tEscolha sua opção: "); 
			scanf("\n%d", &menuFuncao);
		
			while(menuFuncao < 1 || menuFuncao > 5){
				printf("\nA opção %d não existe, escolha novamente:\n", menuFuncao);
				printf("Menu\n"); 
				printf("(1) Atrações\t\t(2) Fazer reserva\n(3) Gerar ingresso\t(4) Cadeira disponível\n(5) Sair\t\tEscolha sua opção: ");
	        	scanf("\n%d", &menuFuncao);
			}
			if (menuFuncao == 1){ //condição para retornar ao menu, caso o usuário, após escolher S "adquirir exposição", queira mudar de exposição  
				atracao = 0;
			}
			
	        switch (menuFuncao) {
	            case 1:
					if (tipoEntrada == 1 || tipoEntrada == 2 || tipoEntrada == 3){
						printf("\nHá uma reserva em andamento!\n");
						printf("\nEscolha o menu 2 para continuar comprando OU\nmenu 3 para gerar o ingresso\n");
					} else {
					
						printf("\n**************************************************\n");
					    printf("======== BEM-VINDO AO MUSEU MULTITEMÁTICO ========\n");
					    printf("**************************************************\n");
					    printf("Aquisição de bilhetes de entrada:\n");
					    printf("Valor Integral:     R$ %.2f\n", VALOR_ENTRADA);
					    printf("Valor Meia entrada: R$ %.2f\n", VALOR_ENTRADA / 2);
					    printf("Isenção de acordo com a legislação vigente.\n");
				    
						do{
							if (atracao != 0){
								break;
							}
							printf("\nVeja uma sinopse das exposições disponíveis:\n");
					    	printf("(1) 100 anos da Semana de Arte Moderna\n(2) 150 anos de Santos Dumont\n(3) Jogos Olímpicos Paris 2024\n(4) Indústria 4.0 Tecnologia e Futuro\nEscolha sua atração: ");
					    	scanf("%d", &menuAtracao);
							
							while(menuAtracao < 1 || menuAtracao > 4){
								printf("\nA opção %d não existe, escolha uma nova opção:\n", menuAtracao);
								printf("\nVeja uma sinopse das atrações disponíveis:\n");
					    		printf("(1) 100 anos da Semana de Arte Moderna\n(2) 150 anos de Santos Dumont\n(3) Jogos Olímpicos Paris 2024\n(4) Indústria 4.0 Tecnologia e Futuro\nEscolha sua atração: ");
					    		scanf("%d", &menuAtracao);		
							}
						
							do{	
								switch (menuAtracao){
									case 1:
										printf("\n100 anos da Semana de Arte Moderna.\n");
										printf("\nA Semana de Arte Moderna de 1922 revolucio-\nnou a cultura brasileira com manifestações\nartísticas inovadoras, desafiando normas aca-\ndêmicas e europeias. Marcou o início do Mo-\ndernismo no país, introduzindo novas lin-\nguagens e abordagens nacionalistas que in-\nfluenciaram gerações futuras de artistas e\nmoldaram a identidade cultural brasileira. \nSeu centenário celebra um legado duradouro.\n\n");
										break;
									case 2:
										printf("\n150 anos de Santos Dumont.\n");
										printf("\nOs 150 anos de Santos Dumont celebram a vida\ne legado do pioneiro da aviação. \nAlberto Santos Dumont, nascido em 1873, foi um \nvisionário brasileiro que realizou voos histó- \nricos com aeronaves ultra leves e contribuiu signi-\nficativamente para o desenvolvimento da aviação \nmundial. Seus feitos, como o voo do 14-Bis em \n1906, marcaram avanços cruciais na história da \ntecnologia aeronáutica, solidificando seu lugar \ncomo um ícone da inovação e coragem. A comemora-\nção de seu aniversário reconhece suas contribui-\nções notáveis para a humanidade.\n\n");
										break;
									case 3:
										printf("\nJogos Olímpicos Paris 2024.\n");
										printf("\nOs Jogos Olímpicos de 2024 serão sediados em \nParis, França, celebrando esportes, cultura \ne sustentabilidade. Atletas de todo o mundo \ncompetirão em um ambiente moderno, refletindo \nos valores olímpicos e deixando um legado \nduradouro para a cidade.\n\n");
										break;
									case 4:
										printf("\nIndústria 4.0 Tecnologia e Futuro.\n");
										printf("\nA Indústria 4.0 é um conceito que se refere\nà quarta revolução industrial, caracterizada \npela integração de tecnologias avançadas de \nautomação, análise de dados, Internet das \nCoisas (IoT) e inteligência artificial nas \noperações industriais. Essa revolução busca \ntransformar profundamente os processos de \nprodução e fabricação, resultando em fábricas \nmais eficientes, flexíveis e conectadas.\n\n");
											
								} //fechamento do switch case
							
			        			printf("\nAdquirir esta atração? \nDigite 'S' para (sim) ou 'N' para (não): ");
						        scanf("%1s", adquirirAtracao);
								printf("\n");
						        // Converter a resposta para letras minúsculas para tornar a comparação insensível a maiúsculas e minúsculas    
						        adquirirAtracao[0] = tolower(adquirirAtracao[0]);
						        
			        			if (adquirirAtracao[0] == 's') { 
			            			system("cls");
									if (menuAtracao == 1){
										atracao = 1;
										sala1 = 1, sala2 = 0, sala3 = 0, sala4 = 0;
										strcpy(nomeAtracao, "\n Sala 1\n Exposição: 100 anos da Semana de Arte Moderna");
										strcpy(temaInteresseStr, "100 anos da Semana de Arte Moderna");
									} else if (menuAtracao == 2){
										atracao = 2;
										sala1 = 0, sala2 = 2, sala3 = 0, sala4 = 0;
										strcpy(nomeAtracao, "\n Sala 2\n Exposição: 150 anos de Santos Dumont");
										strcpy(temaInteresseStr, "150 anos de Santos Dumont");	
									}else if (menuAtracao == 3){
										atracao = 3;
										sala1 = 0, sala2 = 0, sala3 = 3, sala4 = 0;
										strcpy(nomeAtracao, "\n Sala 3\n Exposição: Jogos Olímpicos Paris 2024");
										strcpy(temaInteresseStr, "Jogos Olímpicos Paris 2024");	
									}else{
										atracao = 4;
										sala1 = 0, sala2 = 0, sala3 = 0, sala4 = 4;
										strcpy(nomeAtracao, "\n Sala 4\n Exposição: Indústria 4.0 Tecnologia e Futuro");
										strcpy(temaInteresseStr, "Indústria 4.0 Tecnologia e Futuro");
									}
								    break;
							    } else if (adquirirAtracao[0] == 'n') {
							    	 menuAtracao = 1;
									 break; 
							    } else {
							        printf("\nResposta inválida. Por favor, digite 'S' para (sim) ou 'N' para (não): ");
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
						printf("\nPasso 1: Escolha a atração.\nPasso 2: Faça reserva.\nPasso 3: Gerar ingresso .\n");
						break;
					}
					// Fazer reserva
					printf("\nEscolha de assento:");
	                printf("\nDigite o número da fileira: ");
	                scanf("%d", &fila);
	                printf("\nDigite o número da cadeira: ");
	                scanf("%d", &cadeira);
	
	                while (fila < 1 || fila > 6 || cadeira < 1 || cadeira > 5) {
	                    printf("\nTentativa inválida. Disponibilidade de 6 fileiras e 5 colunas de cadeiras!");
	                    printf("\nDigite o número da fileira: ");
	                    scanf("%d", &fila);
	                    printf("\nDigite o número da cadeira: ");
	                    scanf("%d", &cadeira);
	                }
	
					if (sala1 == 1){	
		                if (reservaSala1[fila - 1][cadeira - 1][0] != '\0') {
		                    printf("\nCadeira já reservada! Escolha outra opção.\n\n");
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
		                    printf("\nCadeira já reservada! Escolha outra opção.\n\n");
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
		                    printf("\nCadeira já reservada! Escolha outra opção.\n\n");
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
		                    printf("\nCadeira já reservada! Escolha outra opção.\n\n");
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
	    			printf("Isenção de acordo com a legislação vigente.\n");
					printf("\nTipo de entrada: \n(1) Inteira (2) Meia Entrada  (3) Isenção\n");
			        printf("Sua escolha: ");
					scanf("%d", &tipoEntrada);
							
			        while (tipoEntrada < 1 || tipoEntrada > 3)  {
			        	printf("\nA opção %d não existe, escolha uma nova opção:\n", tipoEntrada);
			            printf("\nTipo de entrada: \n(1) Inteira (2) Meia Entrada (3) Isenção\n");
			            printf("Sua escolha: ");
						scanf(" %d", &tipoEntrada);
			        }
			        				
					//contabilidade do tipo de entrada e bilheteria
					if (tipoEntrada == 1){ 
					    valorTotal += VALOR_ENTRADA;
					    valorTotalPgto += VALOR_ENTRADA;//mesma função do valorTotal, utilizado no pagamento, pois o usuário pode pagar mais de uma vez  
					    valorInteira += VALOR_ENTRADA;
						inteira++; // variável para controle do total de inteiras do relatório
						pgtoInteira++;// mesma função de (inteira++), utilizado no pagamento, pois o usuário pode pagar mais de uma vez
						csvInteira++;//individualização do cliente a cada chamada da função gerar ou atualizarArquivoCSV
						pgtoPendente = true; // para garantir a chamada da forma de pagamento
						
					} else if (tipoEntrada == 2){
					    valorTotal += VALOR_ENTRADA / 2;
					    valorTotalPgto += VALOR_ENTRADA / 2;//mesma função do valorTotal, utilizado no pagamento, pois o usuário pode pagar mais de uma vez
					    valorMeia += VALOR_ENTRADA / 2;
						meia++; // variável para controle do total de meias do relatório
						pgtoMeia++;// mesma função de (meia++), mas para pagamento, pois o usuário pode pagar mais de uma vez
						csvMeia++;//individualização do cliente a cada chamada da função gerar ou atualizarArquivoCSV
						pgtoPendente = true; //para garantir a chamada da forma de pagamento
						
					} else {
					    isencao++; // variável para controle do total de isenção do relatório
					    comIsencao++; // mesma função de (isenção++), mas para pagamento, pois o usuário pode pagar mais de uma vez
						csvIsencao++;//individualização do cliente a cada chamada da função gerar ou atualizarArquivoCSV
					}
					 
					numClienteCSV++;
					numClientePgto++;
					numCliente++;
					break;
					
				case 3:
					//Gerar ingresso / Pagamento        	 		
					while (formaPgto >= 1 && formaPgto <=4){//pré avaliação antes de entrar no pagamento
						printf("\nO carrinho está vazio OU \nO pagamento já foi realizado OU\nUsuário isento de pagamento!\n");
						printf("\n");
						break;
					}
					
					if (pgtoPendente){
						printf("\nForma de Pagamento:\n");
						printf("(1) Dinheiro (2) Cartão de Crédito  (3) Cartão de Débito (4) Pix\n");
						printf("Sua escolha: ");
						scanf("%d", &formaPgto);
						pgtoPendente = false; // retorna a variável a condição inicial
					
					while (formaPgto < 1 || formaPgto > 4) {
						printf("\nA opção %d não existe\n", formaPgto);
						printf("\nForma de Pagamento:\n");
						printf("(1) Dinheiro (2) Cartão de Crédito  (3) Cartão de Débito (4) Pix\n");
						printf("Sua escolha: ");
						scanf("%d", &formaPgto);
						pgtoPendente = false; // retorna a variável a condição inicial
					}
						
					} else {
						printf("\nPasso 1: Escolha a atração.\nPasso 2: Faça reserva.\nPasso 3: Gerar ingresso.\n");
						questionarioRespondido = true;
					}
					
					//caso a última aquisição for tipoEntrada=3, o if abaixo garante a contabilização da forma pgto
					if (formaPgto == 1){
						dinheiro++;
						dinheiroCSV++;//individualização da forma de pgto a cada chamada da função gerar ou atualizarArquivoCSV
					} else if (formaPgto == 2){
						credito++;
						creditoCSV++;//individualização da forma de pgto a cada chamada da função gerar ou atualizarArquivoCSV
					} else if (formaPgto == 3){
						debito++;
						debitoCSV++;//individualização da forma de pgto a cada chamada da função gerar ou atualizarArquivoCSV
					} else if (formaPgto == 4){
						pix++;
						pixCSV++;//individualização da forma de pgto a cada chamada da função gerar ou atualizarArquivoCSV
					}
			
					if (tipoEntrada == 0){
						//se verdadeiro o cliente já efetuou o pagamento ou já tentou gerar ingresso sem escolher uma atração e fazer reserva
					} else {
					    system("cls");
						printf("Reserva confirmada.");
						printf("\nRetire seu ingresso.\n");
						
						//impressão do ingresso do cliente
						printf("\n===============================================\n");
						printf("============= MUSEU MULTITEMÁTICO =============\n");
						
						printf("%s", nomeAtracao);
						// Geração de código do cliente contendo ano, mês, dia, hora, min, seg e um contador identificador
						struct DataHora dataHoraAtual = obterDataHoraAtual();
						printf(" \n Código identificador do Cliente:\n");
	    				printf("   %d%d%d%d%d%d%d\n", dataHoraAtual.ano, dataHoraAtual.mes, dataHoraAtual.dia, dataHoraAtual.hora, dataHoraAtual.minuto, dataHoraAtual.segundo, codCliente++);
						printf(" \n Reserva realizada para %d cliente(s).\n", numClientePgto);
						printf("\n Inteira:\n"); 
						printf("   %d Ingresso(s)...........R$ %.2f\n", pgtoInteira, valorInteira); 
						printf(" Meia Entrada:\n");
						printf("   %d Ingresso(s)...........R$ %.2f\n", pgtoMeia, valorMeia); 
						printf(" Isento:\n");
						printf("   %d Ingresso(s)...........R$ 0,00\n", comIsencao);
						printf("\n Total pago:...............R$ %.2f\n", valorTotalPgto);
					    //aproveita o cálculo da função de geração de código do cliente e extrai a data atual
						printf(" Compra realizada em: %d/%d/%d\n", dataHoraAtual.dia, dataHoraAtual.mes, dataHoraAtual.ano);
						printf("\n APRESENTE ESTE INGRESSO NA ENTRADA\n DA EXPOSIÇÃO E UM DOCUMENTO COM FOTO.\n");
						printf("===============================================\n\n");		
						
						tipoEntrada = 0; //nova atribuição de valor para impedir pagamento duplicado
							
						// Nova atribuição de valor caso o usuário faça um segundo pagamento ou mais
						//tipos inteiros
						numClientePgto = 0, pgtoInteira = 0, pgtoMeia = 0,  comIsencao = 0;
						//tipos float
						valorTotalPgto = 0.0, valorMeia = 0.0, valorInteira = 0.0; 
					
						if (arquivoGerado == 0){ 
							// Chamando a função para gerar o arquivo CSV, primeiro pagamento 
							gerarArquivoCSV(divulgacaoStr, faixaEtariaStr, temaInteresseStr, motivoVisitaStr, escolaridadeStr, acessibilidadeStr, csvInteira, csvMeia, csvIsencao, numClienteCSV, dinheiroCSV, creditoCSV, debitoCSV, pixCSV, valorTotal); 
							arquivoGerado = 1;
						} else {
							// Chamando a função para atualizar o arquivo CSV, segundo pagamento em diante
							atualizarArquivoCSV(divulgacaoStr, faixaEtariaStr, temaInteresseStr, motivoVisitaStr, escolaridadeStr, acessibilidadeStr, csvInteira, csvMeia, csvIsencao, numClienteCSV, dinheiroCSV, creditoCSV, debitoCSV, pixCSV, valorTotal); 	
						}
						csvInteira = 0, csvMeia = 0, csvIsencao = 0, numClienteCSV = 0, dinheiroCSV = 0, creditoCSV = 0, debitoCSV = 0, pixCSV = 0;
						valorTotal = 0.0;
						formaPgto = 0; // para impedir dois pagamentos da mesma compra, salvo se o usuário realizar nova reserva
						salaVazia = 0, sala1 = 0, sala2 = 0, sala3 = 0, sala4 = 0;
						menuAtracao = 0; //não permite que o usuário faça reserva sem escolher a atração primeiro
						
						do {
					        printf("Continuar comprando? \nDigite 'S' para (sim) ou 'N' para (não): ");
					        scanf("%1s", resposta);
					        // Converter a resposta para letras minúsculas para tornar a comparação insensível a maiúsculas e minúsculas    
					        resposta[0] = tolower(resposta[0]);
					        if (resposta[0] == 's') { // se o usuário optar por sim ele não será obrigado a responder novamente o questionário
					            questionarioRespondido = true;
					            strcpy(divulgacaoStr, "''"); //caso o usuário continue a comprar os valores não serão duplicados no arquivo csv
								strcpy(faixaEtariaStr, "''");
							    strcpy(motivoVisitaStr, "''");
								strcpy(escolaridadeStr, "''");
							    strcpy(acessibilidadeStr, "''");
								break;
					        } else if (resposta[0] == 'n') {
					            questionarioRespondido = false;				
								system("cls"); //limpa a tela
								strcpy(divulgacaoStr, ""); //caso o usuário continue a comprar os valores não serão duplicados no arquivo csv
								strcpy(faixaEtariaStr, "");
							    strcpy(motivoVisitaStr, "");
								strcpy(escolaridadeStr, "");
							    strcpy(acessibilidadeStr, "");
								break; // Sai do loop
					        } else {
					            printf("\nResposta inválida. Por favor, digite 'S' para (sim) ou 'N' para (não): ");
					        }
					    } while ("n");
						 
					}
					break;
	
				case 4: 
					if (salaVazia == 0){
						questionarioRespondido = true; //para evitar o questionário e entrar no menu
						printf("\nFunção disponível após a escolha de uma atração.\n");
					}
					
					if (sala1 == 1){
						if (reservaSala1[i][j][0] == '\0') {
			                printf("Fila %d, Cadeira %d: Disponível\n", i + 1, j + 1);
			            }    
						//varre a matriz e inclui a palavra "Disponível" aos locais não reservados     
			            printf("\n==== CADEIRAS DISPONÍVEIS ====\n");
			            for (i = 0; i < 5; i++) {
			                for (j = 0; j < 6; j++) {
			                    if (reservaSala1[i][j][0] == '\0') {
			                        printf("Fila %d, Cadeira %d: Disponível\n", i + 1, j + 1); 
			                    }
			                }
			                printf("\n");
			            }
		            }
		            
		            if (sala2 == 2){
						if (reservaSala2[i][j][0] == '\0') {
			                printf("Fila %d, Cadeira %d: Disponível\n", i + 1, j + 1);
			            }    
						//varre a matriz e inclui a palavra "Disponível" aos locais não reservados     
			            printf("\n==== CADEIRAS DISPONÍVEIS ====\n");
			            for (i = 0; i < 5; i++) {
			                for (j = 0; j < 6; j++) {
			                    if (reservaSala2[i][j][0] == '\0') {
			                        printf("Fila %d, Cadeira %d: Disponível\n", i + 1, j + 1); 
			                    }
			                }
			                printf("\n");
			            }
		            }
					if (sala3 == 3){
						if (reservaSala3[i][j][0] == '\0') {
			                printf("Fila %d, Cadeira %d: Disponível\n", i + 1, j + 1);
			            }    
						//varre a matriz e inclui a palavra "Disponível" aos locais não reservados     
			            printf("\n==== CADEIRAS DISPONÍVEIS ====\n");
			            for (i = 0; i < 5; i++) {
			                for (j = 0; j < 6; j++) {
			                    if (reservaSala3[i][j][0] == '\0') {
			                        printf("Fila %d, Cadeira %d: Disponível\n", i + 1, j + 1); 
			                    }
			                }
			                printf("\n");
			            }
		            }
		            
		            if (sala4 == 4){
						if (reservaSala4[i][j][0] == '\0') {
			                printf("Fila %d, Cadeira %d: Disponível\n", i + 1, j + 1);
			            }    
						//varre a matriz e inclui a palavra "Disponível" aos locais não reservados     
			            printf("\n==== CADEIRAS DISPONÍVEIS ====\n");
			            for (i = 0; i < 5; i++) {
			                for (j = 0; j < 6; j++) {
			                    if (reservaSala4[i][j][0] == '\0') {
			                        printf("Fila %d, Cadeira %d: Disponível\n", i + 1, j + 1); 
			                    }
			                }
			                printf("\n");
			            }
		            }
	                break;	 
	            case 5: //cancelar compra e rotornar ao início
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
					
					// zerando as variáveis
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
		} while (true); // loop caso o usuário escolha a função 5	
    system("pause"); //aguarda o usuário para fechar a janela, importante caso execute o (.exe) no ambiente Windows
	return 0;
}

// Função para cálculo do código de identificação do usuário com base na data e hora (código criado com auxílio de IA)
struct DataHora obterDataHoraAtual() {
    struct DataHora dataHora;
    time_t tempoAtual;
    struct tm *infoTempo;

    time(&tempoAtual); // Obtém o tempo atual
    infoTempo = localtime(&tempoAtual); // Converte para a estrutura tm

    // Extrai as informações de data e hora
    dataHora.ano = infoTempo->tm_year + 1900; // Adicione 1900 ao ano
    dataHora.mes = infoTempo->tm_mon + 1;     // Os meses são indexados de 0 a 11
    dataHora.dia = infoTempo->tm_mday;
    dataHora.hora = infoTempo->tm_hour;
    dataHora.minuto = infoTempo->tm_min;
    dataHora.segundo = infoTempo->tm_sec;
    return dataHora;
}

// Função para gerar um arquivo CSV com os dados fornecidos (código criado com auxílio de IA)
void gerarArquivoCSV(char divulgacaoStr[], char faixaEtariaStr[], char temaInteresseStr[], char motivoVisitaStr[], char escolaridadeStr[], char acessibilidadeStr[], int inteira, int meia, int isencao, int numCliente, int dinheiro, int credito, int debito, int pix, float valorTotal) {
			
    // Nome do arquivo CSV
    const char* nomeArquivo = "Relatório_Museu.csv";

    // Abrir o arquivo para escrita
    FILE* arquivo = fopen(nomeArquivo, "w");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
	fprintf(arquivo, "Divulgação, Faixa Etária, Tema de Interesse, Motivo da visita, Escolaridade, Acessibilidade, Pagantes Inteira, Pagantes Meia Entrada, Clientes isentos, Número Clientes,Pgto dinheiro, Pgto Crédito, Pgto Débito, Pgto PIX, Valor da Bilheteria\n");  
   
   	fprintf(arquivo, "%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%.0f\n", divulgacaoStr, faixaEtariaStr, temaInteresseStr, motivoVisitaStr, escolaridadeStr, acessibilidadeStr, inteira, meia, isencao, numCliente, dinheiro, credito, debito, pix, valorTotal);

    // Fechar o arquivo
    fclose(arquivo);
	
}

// Função para gerar um arquivo CSV com os dados fornecidos (código criado com auxílio de IA)
void atualizarArquivoCSV(char divulgacaoStr[], char faixaEtariaStr[], char temaInteresseStr[], char motivoVisitaStr[], char escolaridadeStr[], char acessibilidadeStr[], int inteira, int meia, int isencao, int numCliente, int dinheiro, int credito, int debito, int pix, float valorTotal) {
			
    // Nome do arquivo CSV
    const char* nomeArquivo = "Relatório_Museu.csv";
	
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

