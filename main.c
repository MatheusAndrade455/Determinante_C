#include <stdio.h>
#include <stdlib.h>
void ImprimiMatriz(int matriz[21][21],int tam);
int EhTriangular(int matriz[21][21],int tam);
int LinhaColunaZero(int matriz[21][21],int tam);

int EhTriangular(int matriz[21][21],int tam){
    int i,j,condicaoINF=0,condicaoSUP=0;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            if(i!=tam-1 && j>i){
                if(matriz[i][j]!=0) condicaoINF=1;
            }
            if(i!=0 && j<=i-j){
            if(matriz[i][j]!=0) condicaoSUP=1;
            }
        }
    }
    if(condicaoINF==0 && condicaoSUP==0) return 3;
    if(condicaoSUP==0) return 1;
    if(condicaoINF==0) return 2;
    return 0;
}

int LinhaColunaZero(int matriz[21][21],int tam){
    int i,j,Ezerado=0,LinhaZerada=1,ColunaZerada=1,EzeradoCOl=0;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            if(matriz[i][j]==0){
                Ezerado++;
            }
            if(matriz[j][i]==0){
                EzeradoCOl++;
            }
        }
        if(Ezerado==tam){
            LinhaZerada=0;
        }
        if(EzeradoCOl==tam){
            ColunaZerada=0;
        }
        EzeradoCOl=0;
        Ezerado=0;
    }

    if(LinhaZerada==0 && ColunaZerada==0) return 3;
    if(LinhaZerada==0) return 1;
    if(ColunaZerada==0) return 2;
    return 0;
}

int CalculoDet(int matriz[21][21],int n){
  int i,j,aux;
  if(EhTriangular(matriz,n)!=0){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        if(i==j && i==0){
          aux=matriz[i][j];
        }
        if(i==j && i!=0){
          aux=aux*matriz[i][j];
        }
      }
    }
    return aux;
  }
  if(LinhaColunaZero(matriz,n)!=0){
    return 0;
  }
  return -1;
}

int main(){
    int matriz[21][21],tam,i,j,det;
    FILE *arq=fopen("matriz.txt","r");
    if(arq==NULL){
        printf("Erro na Abertura!");
        exit(1);
    }

    fscanf(arq,"%d\n",&tam);
    for (i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            fscanf(arq,"%d",&matriz[i][j]);
        }
        fscanf(arq,"\n");
    }
    ImprimiMatriz(matriz,tam);
    return 0;
}

void ImprimiMatriz(int matriz[21][21],int tam){
    int i,j;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------\n");
    int veri=EhTriangular(matriz,tam);
    if(veri==1)  
        printf("Matriz Triangular Superior!\n");
    if(veri==2)
        printf("Matriz Triangular Inferior!\n");
    if(veri==0)
        printf("Matriz nao eh Triangular!\n");
    if(veri==3)
        printf("Matriz Triangular Superior e Inferior!\n");
    veri=CalculoDet(matriz,tam);
    if(veri!=-1)
        printf("Determinante: %d\n",veri);
    else printf("A matriz nao possui nenhuma das propiedades, logo nao foi possivel calcular seu determinante.\n");
    
}