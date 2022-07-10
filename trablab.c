#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
    char nome_aluno[100];
    int matricula_aluno;
    char curso_aluno[100];
    char email_aluno[100];
    char nome_orientador[100];
    int frequencia_aluno;
    char nome_avaliador[100];
    char nome_instituicao[100];
    char email_avaliador[100];
    char banca_titulo[100];
    char banca_resumo[600];
    char banca_horario[100];
    char banca_local[100];

    struct dados * prox;
    struct dados * ant;
}dados;

dados * inicio = NULL;

int sair = 0;
int tam = 0;
FILE *p;
FILE *aux;


dados* gerar_banca(){
 
  dados *NOVO = malloc(sizeof(dados));
 
  if(inicio == NULL){
    inicio = NOVO;
    tam++;
  }else{
    dados *aux = inicio;                   
    for(int i = 0; i < tam -1; i++){     
      aux = aux->prox;                
    }
    NOVO->prox = aux->prox;             
    aux->prox = NOVO;                                  
    tam++;                              
  }
  return NOVO;
}
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void Cadastrar(){
    dados * nova_banca = gerar_banca();
    clean_stdin();
    printf("Informe Nome: \n");
    fgets(nova_banca -> nome_aluno, 100,stdin);
    printf("Informe Sua matricula: \n");
    scanf("%d",&nova_banca -> matricula_aluno);
    clean_stdin();
    printf("Informe seu Curso: \n");
    fgets(nova_banca -> curso_aluno, 100,stdin);
    printf("Informe seu email: \n");
    fgets(nova_banca -> email_aluno, 100,stdin);
    printf("Informe o nome do orientador: \n");
    fgets(nova_banca -> nome_orientador, 100,stdin);
    printf("Informe frequencia do aluno: \n");
    scanf("%d",&nova_banca -> frequencia_aluno);
    clean_stdin();
    printf("Informe o nome do avaliador: \n");
    fgets(nova_banca -> nome_avaliador, 100,stdin);
    printf("Informe instituicao: \n");
    fgets(nova_banca -> nome_instituicao, 100,stdin);
    printf("Informe o email do avaliador: \n");
    fgets(nova_banca -> email_avaliador, 100,stdin);
    printf("Informe o titulo da banca: \n");
    fgets(nova_banca -> banca_titulo, 100,stdin);
    printf("Informe o resumo: \n");
    fgets(nova_banca -> banca_resumo, 100,stdin);
    printf("Informe o horario: \n");
    fgets(nova_banca -> banca_horario, 100,stdin);
    printf("Informe o local: \n");
    fgets(nova_banca -> banca_local, 100,stdin);
    Salvar_informacoes();
    
}

void Exibir(){
    dados * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Nome do aluno: %s", aux -> nome_aluno);
        printf("Matricula: %d \n", aux -> matricula_aluno);
        printf("Email do aluno: %s", aux -> email_aluno);
        printf("Curso: %s", aux -> curso_aluno);
        printf("Nome do Orientador: %s", aux -> nome_orientador);
        printf("Frequencia do aluno: %d \n", aux -> frequencia_aluno);
        printf("Nome do Avaliador: %s", aux -> nome_avaliador);
        printf("Email do avaliador: %s", aux -> email_avaliador);
        printf("Nome da instituicao: %s", aux -> nome_instituicao);
        printf("Titulo da banca: %s", aux -> banca_titulo);
        printf("Resumo da banca: %s", aux -> banca_resumo);
        printf("Horario da banca: %s", aux -> banca_horario);
        printf("Local da banca: %s", aux -> banca_local);
        
        
        
        aux = aux->prox;
    }
}
void Salvar_informacoes(){
 
    FILE *arquivo;
    arquivo = fopen("aluno.txt", "w");
 
    dados *aux = inicio;
    for(int i =0; i<tam; i++){ 
        if(aux==NULL){
            break;
        }
        fprintf(arquivo,"Nome: %s",aux->nome_aluno);
        fprintf(arquivo,"Matricula: %d\n", aux->matricula_aluno);
        fprintf(arquivo,"Email: %s", aux->email_aluno);
        fprintf(arquivo,"Curso: %s", aux->curso_aluno);
        fprintf(arquivo,"Orientador: %s", aux->nome_orientador);
        fprintf(arquivo,"Frequencia: %d\n", aux->frequencia_aluno);
        fprintf(arquivo,"Avaliador: %s", aux->nome_avaliador);
        fprintf(arquivo,"Avaliador email: %s", aux->email_avaliador);
        fprintf(arquivo,"Intituicao: %s", aux->nome_instituicao);
        fprintf(arquivo,"Titulo: %s", aux->banca_titulo);
        fprintf(arquivo,"Local: %s", aux->banca_local);
        fprintf(arquivo,"Resumo: %s", aux->banca_resumo);
        fprintf(arquivo,"Horario: %s\n", aux->banca_horario);
        aux = aux->prox;
    }
    printf("\t========================================\n"); 
    printf("\t\tArquivos salvos com exito.\n");
    printf("\t========================================\n"); 
    fclose(p);
}
void atualizar(){

    int mat;
    printf("insira a matricula a ser atualizada: \n");
    scanf("%d", &mat);
    dados *aux = inicio;
    for (int i = 0; i < tam; i++){
        if(aux->matricula_aluno == mat){
            clean_stdin();
            printf("Informe Nome: \n");
            fgets(aux -> nome_aluno, 100,stdin);
            printf("Informe Sua matricula: \n");
            scanf("%d",&aux -> matricula_aluno);
            clean_stdin();
            printf("Informe seu Curso: \n");
            fgets(aux -> curso_aluno, 100,stdin);
            printf("Informe seu email: \n");
            fgets(aux -> email_aluno, 100,stdin);
            printf("Informe o nome do orientador: \n");
            fgets(aux -> nome_orientador, 100,stdin);
            printf("Informe frequencia do aluno: \n");
            scanf("%d",&aux -> frequencia_aluno);
            clean_stdin();
            printf("Informe o nome do avaliador: \n");
            fgets(aux -> nome_avaliador, 100,stdin);
            printf("Informe instituicao: \n");
            fgets(aux -> nome_instituicao, 100,stdin);
            printf("Informe o email do avaliador: \n");
            fgets(aux -> email_avaliador, 100,stdin);
            printf("Informe o titulo da banca: \n");
            fgets(aux -> banca_titulo, 100,stdin);
            printf("Informe o resumo: \n");
            fgets(aux -> banca_resumo, 100,stdin);
            printf("Informe o horario: \n");
            fgets(aux -> banca_horario, 100,stdin);
            printf("Informe o local: \n");
            fgets(aux -> banca_local, 100,stdin);
            Salvar_informacoes();
        }else if(mat =! aux->matricula_aluno){
            aux = aux->prox;
        }else{
            printf("matricula não encontrada\n");
        }
    }
    
}
void remover(){
    int mat;
    printf("insira a matricula a ser removida: \n");
    scanf("%d", &mat);
    dados *aux = inicio;
    for (int i = 0; i < tam; i++){
       if(aux->matricula_aluno == mat){
            inicio = aux->prox;
            free(aux);
            tam--;
            Salvar_informacoes();
        }else if(aux->prox->matricula_aluno == mat){
            aux->prox = aux->prox->prox;
            tam--;
            free(aux);
            Salvar_informacoes();
        }else{
            aux = aux->prox;
        }
    }
    
}
int menu(){
    int op;
    printf("1 - Cadastrar\n");
    printf("2 - Exibir\n");
    printf("3 - Atualizar\n");
    printf("4 - Remover\n");
    printf("5 - Sair\n");
    scanf("%d", &op);
    switch(op){
        case 1: Cadastrar();break;
        case 2: Exibir();break;
        case 3: atualizar();break;
        case 4: remover();break;
        case 5: sair = 1; return 0;
        default:printf("Opçao invalida\n");break;
    }
}
    

int main(){
   p = fopen("aluno.txt", "wb");
   if(p == NULL){
       printf("Erro para abrir arquivo\n");
       system("pause");
       exit(1);
       
   }
   fclose(p);
   while(sair < 1){
       menu();
   }

}










