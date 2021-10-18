#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//Dans la MatriCe:
//Question 1:
struct matrix{
    int tab;
};

typedef struct matrix Matrix;
typedef struct matrix MatrixArray;

//Question 2:
void readMatrix(Matrix **mat){
    int a,b;
	scanf("%i %i\n",&a,&b);
    int val[a][b];
    *mat = (Matrix*) calloc(a,b);
    for (int i=0;i<a;i++){
        for (int j=0;j<(b-1);j++){
            scanf("%i ",&val[i][j]);
        }
        scanf("%i\n",&val[i][b-1]);             //dernier cas séparé pour éviter un problème d'indentation
        mat->tab=val[a][b];
    }
}

void readMatrixArray(MatrixArray **tab_mat){
    int n_mat;
    scanf("%i\n",&n_mat);
    *tab_mat= (MatrixArray*) calloc(n_mat,sizeof(Matrix));
    for (int i=0;i<n_mat;i++){
        Matrix *val_tab_mat;
        readMatrix(&val_tab_mat);
        (*tab_mat)[i]=val_tab_mat;
}

}
//Question 3
void printDoc(MatrixArray *tab_mat){
    int n_mat=sizeof(*tab_mat);
    printf("%i\n",n_mat);
    for (int i=0;i<n_mat;i++){
        int n_ligne=sizeof(tab_mat->i);
        int n_colonnes=sizeof((tab_mat->i)[0]);
        printf("%i %i\n",n_ligne,n_colonnes);
        for (int u=0;u<n_ligne;u++){                        //écriture d'une matrice
            for (int v=0;v<n_colonnes-1;v++){
                printf("%i ",(tab_mat->i)[u][v]);
            }
            printf("%i\n",(tab_mat->i)[u][n_colonnes-1]);   //dernier cas séparé pour éviter un problème d'indentation
        }
    }
}

//Question 4
int main(void) {
MatrixArray *mat_texte;
    readMatrixArray(&mat_texte);
    printDoc(mat_texte);
    free(mat_texte);
}

//Question 5