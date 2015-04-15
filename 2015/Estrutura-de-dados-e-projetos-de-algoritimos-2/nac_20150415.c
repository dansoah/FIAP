/**
 * Nac de EDPA II - 3ECR
 * - André Sousa - RM 68366
 * - Danilo Rechi - RM 69313
 */

#include <stdlib.h>
#include <stdio.h>
typedef struct{

    int matricula;
    float nota_1;
    float nota_2;
    float media_ponderada;

} Aluno;

float mediaPonderada(float nota_1,float peso_1,float nota_2,float peso_2){

    return ((nota_1 * peso_1) + (nota_2 * peso_2)) / peso_1 + peso_2;

}

Aluno * addAluno(Aluno * aluno_array, int total, int matricula, float nota_1, float nota_2){

    int i = 0;


    Aluno * new_list;
    new_list = (Aluno *)malloc((total+1) * sizeof(Aluno));

    if(total > 0){

        for(i = 0;i<=total-1;i++){

            //printf("%i = %i\n",new_list[i].matricula, aluno_array[i].matricula);
            new_list[i]= aluno_array[i];

        }

    }

    new_list[total].matricula = matricula;
    new_list[total].nota_1 = nota_1;
    new_list[total].nota_2 = nota_2;
    new_list[total].media_ponderada = mediaPonderada(nota_1,2,nota_2,4);


    return new_list;

}

void listAlunos(Aluno * array_alunos,int total ){
    int i = 0;
    printf("===========================================================\n");
    printf("|   Matricula    |    Nota 1    |    Nota 2   |  Final    |\n");
    printf("===========================================================\n");

    for(i = 0;i<=total-1;i++){

        printf("|     %i      |    %.2f     |    %.2f    |    %.2f    | \n",
                                        array_alunos[i].matricula,
                                        array_alunos[i].nota_1,
                                        array_alunos[i].nota_2,
                                        array_alunos[i].media_ponderada);


    }


    printf("===========================================================\n");
    printf("|   Matricula    |    Nota 1    |    Nota 2   |  Final    |\n");
    printf("===========================================================\n");

}

Aluno * orderByNota(Aluno * alunos, int total_elements){

    int i;
    int j;
    int lowest_element;

    for(i=0;i<=total_elements-1;i++){
        lowest_element = i;
        for(j=(i+1);j<total_elements;j++){

            if(alunos[j].media_ponderada < alunos[lowest_element].media_ponderada){
                lowest_element = j;

            }//who's bigger?

            //Something changed?
            if(lowest_element != i){

                Aluno aux;

                aux.matricula = alunos[i].matricula;
                aux.nota_1 = alunos[i].nota_1;
                aux.nota_2 = alunos[i].nota_2;
                aux.media_ponderada = alunos[i].media_ponderada;

                alunos[i].matricula = alunos[lowest_element].matricula;
                alunos[i].nota_1 = alunos[lowest_element].nota_1;
                alunos[i].nota_2 = alunos[lowest_element].nota_2;
                alunos[i].media_ponderada = alunos[lowest_element].media_ponderada;

                alunos[lowest_element].matricula = aux.matricula;
                alunos[lowest_element].nota_1 = aux.nota_1;
                alunos[lowest_element].nota_2 = aux.nota_2;
                alunos[lowest_element].media_ponderada = aux.media_ponderada;

            }

        }//for(j=i+1;j<getElementCount();j++)

    }//for(i=0;i<=getElementCount()-1;i++)

    return alunos;
}

Aluno * orderByMatricula(Aluno * alunos, int total_elements){

    int i;
    int j;
    int lowest_element;

    for(i=0;i<=total_elements-1;i++){
        lowest_element = i;
        for(j=(i+1);j<total_elements;j++){

            if(alunos[j].matricula < alunos[lowest_element].matricula){
                lowest_element = j;

            }//who's bigger?

            //Something changed?
            if(lowest_element != i){


                Aluno aux;

                aux.matricula = alunos[i].matricula;
                aux.nota_1 = alunos[i].nota_1;
                aux.nota_2 = alunos[i].nota_2;
                aux.media_ponderada = alunos[i].media_ponderada;

                alunos[i].matricula = alunos[lowest_element].matricula;
                alunos[i].nota_1 = alunos[lowest_element].nota_1;
                alunos[i].nota_2 = alunos[lowest_element].nota_2;
                alunos[i].media_ponderada = alunos[lowest_element].media_ponderada;

                alunos[lowest_element].matricula = aux.matricula;
                alunos[lowest_element].nota_1 = aux.nota_1;
                alunos[lowest_element].nota_2 = aux.nota_2;
                alunos[lowest_element].media_ponderada = aux.media_ponderada;

            }

        }//for(j=i+1;j<getElementCount();j++)

    }//for(i=0;i<=getElementCount()-1;i++)

    return alunos;
}

int main(){
    Aluno * alunos;
    Aluno * alunos_ordered;
    int total = 0;

    int i = 0;
    int max_i = 0;

    int matricula;
    float nota_1;
    float nota_2;


    printf("Quantos alunos voce vai inserir?\n-");
    scanf("%i",&max_i);

    printf("\n\n");

    for(i = 0;i<=max_i;i++){

        printf("Aluno #%i\n",i);
        printf("Matricula: #");
        scanf("%i",&matricula);
        printf("\nNota 1: ");
        scanf("%f",&nota_1);

        printf("\nNota 2: ");
        scanf("%f",&nota_2);

        alunos = addAluno(alunos,total,matricula,nota_1,nota_2);
        total++;

    }

    int sair = 0;
    int opt = 0;
    do{

        system("CLS");
        printf("1- Ordenar por matricula\n");
        printf("2- Ordenar por nota\n");
        printf("0- Sair\n-");
        scanf("%i",&opt);

        system("CLS");

        switch(opt){

            case 1:
                printf("Listando alunos por matricula\n");
                alunos_ordered = orderByMatricula(alunos,total);
                break;
            case 2:
                printf("Listando alunos por nota final\n");
                alunos_ordered = orderByNota(alunos,total);
                break;
        }



        listAlunos(alunos_ordered,total);

        getche();

    }while(opt > 0);

    return 0;


}
