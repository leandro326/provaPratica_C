#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

struct disciplina{
	char nome[30];
	char professor[30];
	float n1;
	float n2;
	int codigo;
};

typedef struct disciplina Disciplina;

struct aluno{
	char nome[30];
	char curso[30];
	float matricula;
	Disciplina disciplinaAluno[5];
};

typedef struct aluno Aluno;

void cadastrar_aluno(aluno *a, int n){ 
		printf("---CADASTRO DE ALUNOS---\n");

	for(int i=0; i<n; i++){
		
		printf("informe o nome do alunos: ");
		setbuf(stdin, NULL);
		gets(a[i].nome);
		setbuf(stdin, NULL);
		
		printf("Informe o Nome do Curso: ");
		setbuf(stdin, NULL);
		gets(a[i].curso);
		setbuf(stdin, NULL);
				
		float mat = 1.2019 + i;
		
		a[i].matricula = mat;
		
	}
}

 
void cadastrar_disciplina(disciplina *d, int n){ 
	   
    int j;
	for(j = 0; j < n; j++) {
		printf("Informe o nome da disciplina: ");
		setbuf(stdin, NULL);
		gets(d[j].nome);
		setbuf(stdin, NULL);
		printf("Informe o nome do professor: ");
		gets(d[j].professor);
		setbuf(stdin, NULL);
		d[j].codigo = 1+j;
	}
}

void adicionar_disciplina_aluno(aluno *a, float mat, int tot_alunos, int *codigos_disc, Disciplina *disc, int tot_disc){
	int cod;
	int i;
	int j;
	for( i =0; i<tot_alunos; i++){
	   	if(mat==a[i].matricula){
       		for( j=0;j<tot_disc;j++){
       			if(codigos_disc[j] == disc[j].codigo)
       			{
	   				a[i].disciplinaAluno[j] = disc[j];
					   	  	
			   }
          	}
          }
      }
}

void adicionar_nota(Aluno *a, float mat, int cod_disc, int QtdAluno, int tot_disc){
int i;
int j;
		for( i =0; i<QtdAluno; i++){
	 	
	       	if(mat==a[i].matricula){
	
		   		for( j=0;j<tot_disc;j++){
		   			
	       			if (a[i].disciplinaAluno[j].codigo == cod_disc )
	       			{
						float n1;
						float n2;	
	       				
						printf("\nInforme a nota 1 da disciplina %d : ", cod_disc );
						scanf("%f", &n1);
					 
						printf("\nInforme a nota 2 da disciplina %d : ", cod_disc );
						scanf("%f", &n2);
							
	       				a[i].disciplinaAluno[j].n1 = n1;
	          			a[i].disciplinaAluno[j].n2 = n2;
	          			
					}
	          	}
	        }
	    }
}
 
void imprime_alunos(Aluno *a, int n){ 

	printf("[Matricula]\t[aluno]\t[curso]\n");
	for(int i =0; i<n; i++){
		printf("%.4f\t%s\t%s\n", a[i].matricula, a[i].nome, a[i].curso);
	}
}

void imprime_disciplinas(Disciplina *d, int n){ 

	printf("[codigo]\t[disciplina]\t[professor]\n");
	
	for(int i =0; i<n; i++){

		printf("%d\t%s\t%s\n", d[i].codigo, d[i].nome, d[i].professor);
	
	}
}
 
void relatorio_aluno(Aluno *a, float mat, int cod_disc,int n){
	int i;
	int j;
	printf("[Aluno]\t[Matricula]\t[Disciplina]\t[Nota1]\t[Nota2]\n");
	
	for( i =0; i<n; i++){
	   	if(mat==a[i].matricula){
       		for( j=0;j<5;j++){ // total displina 5
       			if(cod_disc ==  a[i].disciplinaAluno[j].codigo)
       			{	
					printf("\t%s\t%.4f\t%s\t%.2f\t%.2f\n", a[i].nome, a[i].matricula, a[i].disciplinaAluno[j].nome, a[i].disciplinaAluno[j].n1, a[i].disciplinaAluno[j].n2 );
	       			
			   }
          	}
          }
      }
}

void relatorio_aluno_curso (Aluno *a, int n, char *curso, int cod_disc){
	printf("[Matricula]\t[aluno]\t[curso]\t[Disciplina]\t[media]\t[conceito]\n");
		
	int i;
	int j;	
	float media;
	char conceito;
	for( i =0; i<n; i++){


	   	if(strcmp(curso,a[i].curso)==0){
			for( j=0;j<5;j++){ // total displina 5
			

	   			if(cod_disc == a[i].disciplinaAluno[j].codigo){

			   		media = (a[i].disciplinaAluno[j].n1 + a[i].disciplinaAluno[j].n2 )/ 2;
		       		
		       		if (media>= 7){
		       			conceito = 'A';
		       		}
		       		else if(media>=5){
		       			conceito = 'F';
				   }
				   else{
				   		conceito = 'R';
				   }
	
	/*									
					printf("\n %f: media---", media );
					printf("\n %c conceito:", conceito );
					printf("%.4f", a[i].matricula);
		       		printf("%s",a[i].nome);	
		       		printf("%s", a[i].curso);
		       		printf("%s", a[i].disciplinaAluno[j].nome);
		       		printf("%.f", media);
		       		printf("%c", conceito);
	*/	       		
		       	    printf("\t%.4f\t%s\t%s\t%s\t%.2f\t%c\n", a[i].matricula, a[i].nome, a[i].curso,a[i].disciplinaAluno[j].nome, media, conceito );
		       	 	
			   }
	      	}
	   }
	   else
	   {
			printf("\nDEBUG ENTROU NO curso else %s", a[i].curso );//esse foi informado no 1 do menu 
			printf("\nDEBUG ENTROU NO curso else %s\n",curso);//esse e foi informado no intem 8 do menu
	   }
   }
}

int main() {
	
	//declarar variáveis
	int opc = 0;
	
	//variáveis do aluno
	int i, quantidade_aluno;
	float matricula_aluno;
	Aluno aluno[1000];
	
	//variáveis da disciplina
	int j = 0, quantidade_disciplina, quantidade_disciplina_alocada, codigo_disciplina[1000];
	Disciplina disciplina[1000];
	int CodDisp;
	char Curso[1000];
	
	do {
		//menu inicial
		printf("Menu:");
		printf("\n(1) Cadastrar aluno");
		printf("\n(2) Cadastrar disciplina");
		printf("\n(3) Vincular disciplina a aluno");
		printf("\n(4) Vincular nota do aluno");
		printf("\n(5) Exibir total de alunos");
		printf("\n(6) Exibir disciplinas");
		printf("\n(7) Relatório individual do aluno");
		printf("\n(8) Relatório individual do aluno por curso");
		printf("\n(9) SAIR DO SISTEMA \n");
		scanf("%d", &opc);
		//escolha de opção
		switch(opc) {
			//cadastrar aluno
			case 1:
				printf("\n--- CADASTRAR ALUNOS ---");
				printf("\nInforme a quantidade de alunos: ");
				scanf("%d", &quantidade_aluno);
				cadastrar_aluno(aluno, quantidade_aluno);
				imprime_alunos(aluno,quantidade_aluno);
				break;
			//cadastrar disciplina
			case 2:
				printf("\n--- CADASTRAR DISCIPLINAS ---");
				printf("\nInforme a quantidade de disciplinas: ");
				scanf("%d", &quantidade_disciplina);
				cadastrar_disciplina(disciplina, quantidade_disciplina);
				imprime_disciplinas(disciplina, quantidade_disciplina);
	
				break;
			//cadastrar displina a aluno
			case 3:
				printf("\n--- VINCULAR ALUNO A DISCIPLINA ---");
				printf("\nInforme a matricula do aluno: ");
				scanf("%f", &matricula_aluno);
				printf("Informe a quantidade de disciplina para vincular ao aluno: ");
				scanf("%d", &quantidade_disciplina_alocada);
				for(j=0; j < quantidade_disciplina_alocada;j++){
					printf("Informe o codigo da disciplina : ");
					scanf("%d", &codigo_disciplina[j]);
				}
				adicionar_disciplina_aluno(aluno, matricula_aluno,quantidade_aluno, codigo_disciplina, disciplina, quantidade_disciplina ) ;
				
				printf("\n");
				break;
			//incluindo nota do aluno
			case 4:
				printf("\n--- VINCULAR NOTA AO ALUNO ---");
				printf("\nInforme a matricula do aluno: ");
				scanf("%f", &matricula_aluno);
				for(j=0; j < quantidade_disciplina_alocada;j++){
					printf("Informe o codigo da disciplina : ");
					scanf("%d", &CodDisp);
					adicionar_nota(aluno, matricula_aluno, CodDisp, quantidade_aluno, quantidade_disciplina ) ;
				
				}
				
				printf("\n");
				break;
			//exibir total de alunos
			case 5:
				printf("\n--- IMPRIMIR ALUNOS ---");
				
				imprime_alunos(aluno, quantidade_aluno);

				break;
				
			//exibir disciplinas
			case 6:
				printf("\n--- IMPRIMIR DISCIPLINAS ---");
				
				imprime_disciplinas(disciplina, quantidade_disciplina);
	
				break;
			//relatório individual do aluno
			case 7:
				printf("\n--- RELATORIO INDIVIDUAL DO ALUNO ---");
				printf("\nInforme a matricula do aluno: ");
				scanf("%f", &matricula_aluno);
				printf("Informe o codigo da disciplina : " );
				scanf("%d", &CodDisp);
				
				relatorio_aluno(aluno, matricula_aluno, CodDisp,quantidade_aluno);
				break;
			//relatório individual do aluno por curso
			case 8:
				printf("\n--- RELATORIO INDIVIDUAL POR CURSO ---");
				printf("\nInforme o codigo da disciplina : " );
				scanf("%d", &CodDisp);
				
			//	printf("\nInforme o nome do curso : ");
			//	scanf("%s", &Curso);
			
				printf("\nInforme o nome do curso:");
				setbuf(stdin, NULL);
				gets(Curso);
				setbuf(stdin, NULL);
			
				
			 	relatorio_aluno_curso (aluno, quantidade_aluno, Curso, CodDisp);
				
				break;
			//sair do sistema
			case 9:
				printf("\nO sistema esta sendo encerrado");
				
				break;
			//outros casos 
			deafult:
				printf("\nNumero invalido");
				break;
		}	
	} while(opc != 9);
	
	return 0;
}
