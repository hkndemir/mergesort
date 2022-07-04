#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int sol, int orta, int sag)//sol orta sag indisi 
{
    int i, j, k;
    int es1 = orta - sol + 1;//'es':eleman sayısı veya boyutu es1:sol taraf,es2:sağ taraf  dizileri
    int es2 =  sag - orta;
 
    int L[es1], R[es2];//hakoo
 
    for (i = 0; i < es1; i++)//burda for döngüsü ile dizilere elemanları atıyoruz
        L[i] = arr[sol + i];
    for (j = 0; j < es2; j++)
        R[j] = arr[orta + 1+ j];
 
    i = 0;
    j = 0;
    k = sol;
    while (i < es1 && j < es2)//burda while döngüsü ile eleman olduğu sürece fonksiyonumuz dönecek.
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;//k değeri sürekli artıyor yeni bir dizi oluştuğu için.
    }
 
    while (i < es1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < es2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

int main(){
      FILE *dosya;//dosya açma
    dosya = fopen("ödev.txt","w");//dosya açma ve yazdırma

    int sayılar[10];//dizi oluşturma
    printf("dizinin elemanlarını giriniz:");
    for(int i = 0 ; i<10 ;i++){
      scanf("%d",&sayılar[i]);//kullanıcıdan alınan girdileri diziye atama

    }
    fprintf(dosya,"Normal hali: \n"); 
    for(int i =0  ; i<10 ; i++){
        fprintf(dosya," %d,",sayılar[i]);//normal diziyi dosyaya yazdırma  
    }   
    mergeSort(sayılar,0,10);//diziyi mergeSorta tanımlama
   fprintf(dosya,"\n"); 
   fprintf(dosya,"\n");
   fprintf(dosya,"MergeSort hali: \n"); 
   for(int i = 0 ; i<10 ; i++){
        fprintf(dosya," %d<",sayılar[i]); //mergeSort'lu halini dosyaya yazdırma
    }
    fclose(dosya); //dosyayı kapatma 
}
