#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<locale.h>

using namespace std;

//área de definição de cabeçalhos de funções
void menuinicial();

void limpatela(){
	system("CLS");
}

void iniciatabuleiro(char tabuleiro[3][3]){
	
	int linha,coluna;								//auxiliares
	//navega e popula o tabuleiro com -
	for(linha=0;linha<3;linha++){
		for(coluna=0;coluna<3;coluna++){
			tabuleiro[linha][coluna]='-';
		}
		
	}
		
}

void exibetabuleiro(char tabuleiro[3][3]){
	
	int linha,coluna;								//auxiliares
	//exibe o tabuleiro
	for(linha=0;linha<3;linha++){
		for(coluna=0;coluna<3;coluna++){
			cout<<tabuleiro[linha][coluna];
		}
		cout<<"\n";
	}
	
}

//1=X vence; 2=O vence; 0=nimguem vence
int conferetabuleiro(char tabuleiro[3][3]){
	
	int linha,coluna;								//auxiliares
	
	//confere linhas
	for(linha=0;linha<3;linha++){
		if(tabuleiro[linha][0]=='X' && tabuleiro[linha][0]==tabuleiro[linha][1] && tabuleiro[linha][1]==tabuleiro[linha][2]){
			return 1;	
		}else if(tabuleiro[linha][0]=='O' && tabuleiro[linha][0]==tabuleiro[linha][1] && tabuleiro[linha][1]==tabuleiro[linha][2]){
				cout<<"\nO jogador O venceu\n";
				return 2;
			}
		}
		
	//confere colunas
	for(coluna=0;coluna<3;coluna++){
		if(tabuleiro[0][coluna]=='X' && tabuleiro[0][coluna]==tabuleiro[1][coluna] && tabuleiro[1][coluna]==tabuleiro[2][coluna]){
			return 1;
		}else if(tabuleiro[0][coluna]=='O' && tabuleiro[0][coluna]==tabuleiro[1][coluna] && tabuleiro[1][coluna]==tabuleiro[2][coluna]){
				return 2;
			}
		}
		
	//diagonal principal
	if(tabuleiro[0][0] != '-' && tabuleiro[0][0]==tabuleiro[1][1] && tabuleiro[1][1]==tabuleiro[2][2]){
		
		if(tabuleiro[0][0]=='X'){
			return 1;
		}else{
			return 2;
		}
		
	}
	
	//diagonal secondária
	if(tabuleiro[0][2] != '-' && tabuleiro[0][2]==tabuleiro[1][1] && tabuleiro[1][1]==tabuleiro[2][0]){
			
		if(tabuleiro[0][2]=='X'){
			return 1;
		}else{
			return 2;
		}
		
	}
	
	return 0;
	
}

void exibeinstrucao(){
	
	cout<<"\nMapa de posições:\n";
	cout<<" 7 | 8 | 9\n";
	cout<<" 4 | 5 | 6\n";
	cout<<" 1 | 2 | 3\n";
	
}

void jogo(string nomeJ1,string nomeJ2,int pts1,int pts2){
	
	//acentuação
	setlocale(LC_ALL, "");
	
	///variáveis gerais
	string nomeJA;									//nomes dos jogadores(nome jogador 1; nome jogador 2; nome jogador atual)
	char tabuleiro[3][3];							//tabuleiro do jogo
	int linha,coluna;								//auxiliares para tabuleiro
	int lj,cj,pj;									//posição q o jogador coloca a marca(linha jogada;colunajogada;posição jogada)
	int statusjogo=1;								//0=sem jogo/1=em jogo
	int turno=1;									//1=X/2=O
	int rodada=0;									//quantas vezes foram jogadas no total
	int op;											//opção de reinício
	bool posjog;									//verifica se o jogador posicionou o marcador no tabuleiroc(posição jogada)
	
	//coloca os - no tabuleiro, indicando o vazio
	iniciatabuleiro(tabuleiro);
	
	while(rodada<9 && statusjogo==1){
		
		limpatela();
		
		//exibe o placar
		cout<<"Pontuação:\n";
		cout<<nomeJ1<<"-"<<pts1<<"\n";
		cout<<nomeJ2<<"-"<<pts2<<"\n\n";
		
		//imprime tabuleiro na tela
		exibetabuleiro(tabuleiro);
		
		//exibe o número que corresponde a cada posição
		exibeinstrucao();
		
		cout<<"\nRodada: "<<rodada<<"\n";
		
		//atualiza o nome do jogador atual
		if(turno==1){
			nomeJA=nomeJ1;
		}else{
			nomeJA=nomeJ2;
		}
		
		posjog = false;
		
		//matriz de posições possíveis
		int pos[9][2]={{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}};
		
		while(posjog == false){
			
			//lê a jogada
			cout<<nomeJA<<", digite uma posição conforme o mapa acima: ";
			cin>>pj;
			
			//passa a linha e a coluna de acordo com a matriz de posições do mapa
			lj=pos[pj-1][0];
			cj=pos[pj-1][1];
			
			//verifica se a posição eh vazia
			if(tabuleiro[lj][cj]=='-'){
				
				//posicionou corretamente o marcador
				posjog = true;
				
				//verifica de quem eh a vez de posicionar o marcador
				if(turno==1){
					tabuleiro[lj][cj]='X';
					
					//muda o turno para O
					turno=2;
				}else{
					tabuleiro[lj][cj]='O';
					
					//muda o turno para X
					turno=1;
				}
			
			}
			
		}
		
		//confere se alguem ganhou
		if(conferetabuleiro(tabuleiro)==1){
			cout<<"\n"<<nomeJ1<<" venceu.\n";
			pts1++;
			statusjogo=0;
		}else if(conferetabuleiro(tabuleiro)==2){
			cout<<"\n"<<nomeJ2<<" venceu.\n";
			pts2++;
			statusjogo=0;
		}
		
		//aumenta uma rodada
		rodada++;
		
	}
	
	cout<<"\n";
	exibetabuleiro(tabuleiro);
	cout<<"\nFim de jogo.";
	cout<<"\nO que deseja fazer?";
	cout<<"\n1-Continuar jogando";
	cout<<"\n2-Voltar para o menu inicial";
	cout<<"\n3-Sair\n";
	cin>>op;
	if(op==1){
		jogo(nomeJ1,nomeJ2,pts1,pts2);
	}else if(op==2){
		menuinicial();
	}else{
		limpatela();
		cout<<"\nArrivederci.\n\n";
		system("pause");
	}
	
}

void menuinicial(){
	
	//acentuação
	setlocale(LC_ALL, "");
	
	//opção escolhida pelo usuário
	int op=0;
	
	//nome dos jogadores
	string nomeJ1,nomeJ2;
	
	//caso o jogador não digite uma opção válida, mostra menu dnv
	while(op<1 || op>3){
		limpatela();
		cout<<"Bem vindo ao jogo da velha\n\n";
		cout<<"1-Jogar\n";
		cout<<"2-Sobre\n";
		cout<<"3-Sair\n";
		cout<<"\nSelecione uma opção e tecle ENTER: ";
		cin>>op;
		
		switch(op){
			case 1:
				cout<<"Digite o nome do jogador 1(X): ";
				cin>>nomeJ1;
				cout<<"Digite o nome do jogador 2(O): ";
				cin>>nomeJ2;
				jogo(nomeJ1,nomeJ2,0,0);
				break;
			case 2:
				limpatela();
				cout<<"Desenvolvido por Paulo Campos, em dev C++,2020.\n\n";
				cout<<"1-Voltar para o menu inicial\n";
				cout<<"2-Sair do jogo\n";
				cin>>op;
				if(op==1){
					menuinicial();
				}else{
					cout<<"\nArrivederci.\n\n";
					system("pause");
				}
			case 3:
				limpatela();
				cout<<"\nArrivederci.\n\n";
				system("pause");
				break;
		}
	} 
}

int main(){
	
	menuinicial();
	
	return 0;
}
