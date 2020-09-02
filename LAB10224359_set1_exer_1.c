// ----------------------------------------
// Tepelidis Avraam
//
//AM: 2008030104
// 
// 
// ----------------------------------------

#include <stdio.h>
#include <stdlib.h>
//ANADROMIKI synartisi
int katoptriko(int *arr, int i, int nums){

	if (arr[i] + arr[nums] == arr[0]){    //elegxos an to athroisma twn symmetrikwn stoixeiwn toy pinaka einai = me to 1o stoixeio
		printf("to katoptriko zeugos einai %d, %d poy to athroisma toy kanei %d\n",arr[i],arr[nums],arr[0]);   //typwnw to katoptriko zeugos 
		return i;             //epistrefw ti thesi sto pinaka toy 1ou stoixeioy toy zeugous
	}
	if ((i==nums)||(i==nums-1)){     //otan ftasoyme sti mesi toy pinaka, 1h periptwsi gia peritto arithmo stoixeiwn toy pinaka, 2h gia zygo
		printf("\nDen vrethike katoptriko zeugos\n");		
		return -1;                       //epistrefw -1 afou den vrethike katoptriko zeugos
	}
	return katoptriko(arr,i+1,nums-1);    //anadromiki klisi tis synartisis
}
//ARXI main
int main(){
    int n,j,x;               //dhlwsi topikwn metavlitwn
    char flag;
	
    do{       //epanaliptiki leitourgia toy programmatos
	printf("\ndwse akeraio: ");         //dineis akeraio arithmo, dld posa stoixeia thes na xei o pinakas sou
	scanf("%d",&n);
	int *arr=(int*)malloc(n*sizeof(int));        //dynamiki desmeusi mnimis gia ton pinaka analoga me ton akeraio poy dwses
	for (j=0;j<n;j++){                           //gemisma me for loop toy pinaka me akeraioys
		printf("dwse to %do stoixeio toy pinaka: ",j+1);    
		scanf("%d",&arr[j]);	
	}
	x=katoptriko(arr, 0, n-1);       //klisi tis ANADROMIKIS synartisis
	if (x!=-1)                                                                       //an i epistrofi tis synartisis den einai -1 
		printf("\nH thesi toy 1ou stoixeiou toy zeugous sto pinaka einai: %d\n",x);  //tote einai i thesi tou pinaka pou vrisketai to 1o stoixeio tou zeugous kai to typwnw
	else
		printf("\nH timi epistrofis tis synartisis einai: %d\n",x);       //alliws typwnw to -1 poy epestrepse
	free(arr);      //eleutherwnw ti mnimi pou desmeusa me tin malloc gia to pinaka

	printf("\nThes na ksanatrekseis to programma;(y/n)");
	scanf("%s",&flag);
    }while (flag=='y');

    return(0);
}
