#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpa_e_pausa()
{
fflush(stdin);
system("pause");
}

void Regras_do_jogo()
{
	printf(" Primeiro digite uma palavra qualquer, com 48 letras no maximo\n Segundo digite 1 letra por vez podendo ser qualquer letra aleatoria de A ate Z\n Terceiro quando voce errar 5 vezes voce perde, mas se acertar todas as letras voce ganha o jogo\n Fim\n\n ");
	system("pause");
}

void Opcoes()
{
	char opcao_do_menu;
	do{
		printf(" Menu de Opcoes\n 1 Letras verdes fundo preto\n 2 Letras brancas fundo preto\n 3 Letras pretas fundo branco \n 4 Voltar  ");
		fflush(stdin);
		scanf("%c",&opcao_do_menu);
		
		switch(opcao_do_menu)
		{
			case '1' :
				{
					system("color a");
				break;
				}
			case '2' :
				{
					system("color 07");
				break;
				}
			case '3' :
				{
					system("color 70");
				break;
				}
			case '4' :
				{
				break;
				}
			default:
			{
			printf("digite valores validos");
			limpa_e_pausa();
			}
		}
		system("cls");
	}while(opcao_do_menu!='4');
}

void mostrar_frase(char* frase,char *letras)
{
	for(int i=0;i<=48;i++)
	{
		if(frase[i]=='\0')
		{
			i=48;
		}
		else
		{
			if(frase[i]==' ')
			{	
			printf("  ");
			}
			else
			{
				printf(" _");
				for(int j=0;j<=28;j++)
				{
					if(letras[j]==frase[i])
					{
						printf("%c",letras[j]);
						j=28;
					}
				}
					printf("_ ");
			}
		}
			
	}
	printf("\n\n");
}

void verifica_se_acertou(char *frasecompleta,char letra,int *erros)
{
	fflush(stdin);
	int contador = 0;
		
	for(int i=0;i<=48;i++)
	{
		if(frasecompleta[i]=='\0')
		{
			i=48;
		}
			if(letra==frasecompleta[i])
			{
				contador++;
			}	
	}
	
	if (contador>=1)
	{
		system("cls");
		printf("\n Voce acertou %d letras\n",contador);
	}
	else
	{
		system("cls");
		printf("\n Nao existiu acertos\n");
		(*erros)++;
	}
}

void verifica_se_ganhou(char *palavra_digitada_pelo_desafiante,char *letras_digitadas_pelo_jogador, int *vitoria)
{
	int numero_de_letras_na_palavra=0;
	int numero_de_letras_certas=0;

	//como contar o numero de letras sem usar strlen;
	for(int i=0;i<=48;i++)
	{
		if(palavra_digitada_pelo_desafiante[i]=='\0')
		{
			i=48;
		}
		else
		{
			if(palavra_digitada_pelo_desafiante[i]==' ')
			{	
			printf("  ");
			}
			else
			{
			numero_de_letras_na_palavra++;	
			}
		}		
	}
	
	for(int i=0;i<=48;i++)
	{
		if(palavra_digitada_pelo_desafiante[i]=='\0')
		{
			i=48;
		}
		else
		{
			if(palavra_digitada_pelo_desafiante[i]==' ')
			{	
			printf("  ");
			}
			else
			{
				for(int j=0;j<=28;j++)
				{
					if(letras_digitadas_pelo_jogador[j]==palavra_digitada_pelo_desafiante[i])
					{
						numero_de_letras_certas++;
						j=28;
					}
				}	
			}
		}	
	}
	if(numero_de_letras_certas==numero_de_letras_na_palavra)
	{
		(*vitoria)++;
	}
}

void jogo()
{
	char letras_digitadas_pelo_jogador[28];
	char palavra_digitada_pelo_desafiante[48]="_";
	char letra;
	char menu_da_palavra_do_desafiante;
	bool saida = true;
	int contador_de_erros=0;
	int i = 0;
	int vitoria = 0;
	
	do{
	fflush(stdin);
	printf(" Digite a palavra a ser ocultada :\n");
	gets(palavra_digitada_pelo_desafiante);
	system("cls");
	printf(" A palavra que voce digitou foi \"%s\" deseja permanecer com ela S ou N :",palavra_digitada_pelo_desafiante);
	scanf("%c",&menu_da_palavra_do_desafiante);
	system("cls");
	}while(menu_da_palavra_do_desafiante!='s');

	do{
		printf("\n Numero de Erros %d \n",contador_de_erros); 
		mostrar_frase(palavra_digitada_pelo_desafiante,letras_digitadas_pelo_jogador);
		printf(" Digite uma letra que vc acha que tem na frase a seguir \n");
		fflush(stdin);
		scanf("%c",&letra);
		letras_digitadas_pelo_jogador[i]=letra;
		i++;
		verifica_se_acertou(palavra_digitada_pelo_desafiante,letra,&contador_de_erros);
		if(contador_de_erros==5)
		{
			system("cls");
			saida=false;
			printf(" Voce Perdeu esse jogo\n A palavra certa era \"%s\" \n",palavra_digitada_pelo_desafiante);
		}
		verifica_se_ganhou(palavra_digitada_pelo_desafiante,letras_digitadas_pelo_jogador,&vitoria);
		if(vitoria==1)
		{
			system("cls");
			saida=false;
			printf(" PARABENS VOCE GANHOU \n ");
		}
	}while(saida);
	system("pause");
}

int main(void)
{


	char opcoes_do_menu;
	do{
		printf(" Menu\n \n 1 para iniciar\n 2 para regras do jogo\n 3 opcoes do jogo\n 4 Sair do jogo\n Qual opcao deseja ? ");
		scanf("%c",&opcoes_do_menu);
		switch(opcoes_do_menu)
		{
			case '1' :
				{
					system("cls");
					jogo();
					fflush(stdin);
					break;
				}
			case '2' :
				{
					system("cls");
					Regras_do_jogo();
					fflush(stdin);
					break;
				}
			case '3' :
				{
					system("cls");
					Opcoes();
					fflush(stdin);
					break;
				}
			case '4' :
				{
					break;
				}
			default :
			{	
				printf(" Digite valores validos\n\n");
				limpa_e_pausa();
			}	
		}
		system("cls");
	}while(opcoes_do_menu!='4');
return 0;	
}
