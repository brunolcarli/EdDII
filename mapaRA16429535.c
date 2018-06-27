#include <stdio.h>

//Aluno: Bruno Luvizotto Carli
//RA: 16429535
//Disciplina: Estrutura de Dados II

//Atividade:
/*
Árvores binárias são estruturas de dados que possuem três elementos 
denominados raiz, nó esquerdo e nó direito, que também são árvores binárias. 
Todos estes elementos unidos formam uma estrutura parecida com uma árvore de 
cabeça para baixo, daí a razão do seu nome. Este tipo de estrutura é muito 
utilizado em operações como: organizar os arquivos no sistema operacional, 
realizar cálculos matemáticos, efetuar buscas otimizadas, entre outros.

Baseado no conteúdo do nosso livro de estudo e nas aulas ao vivo, elabore 
um programa em linguagem C que faça a leitura da árvore binária abaixo, 
executando as expressões aritméticas e imprimindo na tela o resultado do 
cálculo efetuado. Vale ressaltar que o resultado da expressão da árvore 
abaixo é o valor 20.

imagem:
http://sistemasead.unicesumar.edu.br/flex/amfphp/services/Portal/ImagemQuestionario2/QUE_33524_138964_1.jpg

*/

////////////////////////////////////////////////////
//.            structs
////////////////////////////////////////////////////
typedef struct arv arvore;
struct arv {
	char operador;
	int valor;
	arvore *esquerda;
	arvore *direita;
	arvore *pai;
	int is_leaf;
};
////////////////////////////////////////////////////
//                globals
////////////////////////////////////////////////////

arvore no[10];
int i;

////////////////////////////////////////////////////
//                funcs
////////////////////////////////////////////////////

void fulfill(){
	/*
	preenche automaticamente a arvore com os valores
	da atividade;
	*/
	no[0].operador = '+';
	no[0].esquerda = &no[1];
	no[0].direita  = &no[2];
	no[0].valor = 0;
	no[0].is_leaf = 0;
	no[0].pai = NULL;

	no[1].operador = '*';
	no[1].esquerda = &no[3];
	no[1].direita  = &no[4];
	no[1].valor = 0;
	no[1].is_leaf = 0;
	no[1].pai = &no[0];

	no[2].valor = 5;
	no[2].is_leaf = 1;
	no[2].pai = &no[0];

	no[3].operador = '-';
	no[3].esquerda = &no[7];
	no[3].direita  = &no[8];
	no[3].valor = 0;
	no[3].is_leaf = 0;
	no[3].pai = &no[1];

	no[4].operador = '+';
	no[4].esquerda = &no[9];
	no[4].direita  = &no[10];
	no[4].valor = 0;
	no[4].is_leaf = 0;
	no[4].pai = &no[1];

	no[7].valor = 6;
	no[7].is_leaf = 1;
	no[7].pai = &no[3];

	no[8].valor = 3;
	no[8].is_leaf = 1;
	no[8].pai = &no[3];

	no[9].valor = 4;
	no[9].is_leaf = 1;
	no[9].pai = &no[4];

	no[10].valor = 1;
	no[10].is_leaf = 1;
	no[10].pai = &no[4];
}

int result(int v1, char op, int v2) {
	/*
	calcula uma expressaoa ritmetica
	*/
	int r;
	switch (op){
		case '*':
			r = v1 * v2;
			break;
		case '+':
			r = v1 + v2;
			break;
		case '-':
			r = v1 - v2;
			break;
		case '/':
			r = v1 / v2;
			break;
	}
	return r;
}

void poda(){
	/*
	algoritmo de poda
	vamos podar a arvore folha por folha
	*/
	char op;
	int val1, val2, r;
	

	// vamos descer a arvore em direção a raiz
	for (i = 10; i >= 0; i--) {

		//se o ramo (no) for uma folha
		if (no[i].is_leaf && no[i].pai != NULL) {

			// podamos a arvore
			op = no[i].pai->operador;            // pega o operador do pai
			val1 = no[i].pai->esquerda->valor;  //  pega o valor do filho esquerdo do pai
			val2 = no[i].pai->direita->valor;  //   pega o valor do filho direito do pai 
			r = result(val1, op, val2);       //    realiza o calculo

			// as folhas nao mais serao folhas
			no[i].pai->esquerda->is_leaf = 0;
			no[i].pai->direita->is_leaf = 0;

			// o pai agora recebe o valor do calculo dos filhos
			no[i].pai->valor = r;

			// o pai se torna a folha
			no[i].pai->is_leaf = 1;
			printf("%d %c %d = %d \n", val1, op, val2, r);

		}
	}
	printf("=====================================\n");
}

void logo(){

	printf("=====================================\n");
	printf(" _ __ ___   __ _ _ __   __ _ \n");
	printf("| '_ ` _ \\ / _` | '_ \\ / _` |\n");
	printf("| | | | | | (_| | |_) | (_| |\n");
	printf("|_| |_| |_|\\__,_| .__/ \\__,_|\n");
	printf("                |_|         \n");
	printf("=====================================\n");
}


////////////////////////////////////////////////////
//.     Main
////////////////////////////////////////////////////
int main(void)
{
	logo();
	
	
	//preenche os nos
	fulfill();

	//poda a arvore em busca dos resultados
	poda();
	

	printf("\n");
	return 0;
}
