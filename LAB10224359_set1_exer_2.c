// ----------------------------------------
// Tepelidis Avraam
//
// AM: 2008030104
// 
// 
// ----------------------------------------

#include <stdio.h>                         //include tis vivliothikes poy xreiazomaste
#include <stdlib.h>

struct list{       //dhlwsi tis listas poy nai mia domi
	int value;
	struct list *next;
};

//----------------
// PRINT
//----------------
void printList(struct list *l){
	
	while(l != NULL){      //mexri na ftasei sto telos tis listas dld o deiktis na deixnei se NULL
		printf("%d ", l->value);      //typwse ti timi poy deixnei o deiktis, dld to "koytaki"-stoixeio tis listas, ti timi toy
		l = l->next;                  //deikse sto epomeno stoixeio tis listas
    }             	
}

// --------------------------
// FREE
// --------------------------
void freeList(struct list *node){
	struct list *tmp = node;     //vazei to voithitiko deikti stin arxi tis listas   
    
    while(tmp != NULL){          
		node = node->next;       //proxwra tin kefali tis listas ston epomeno komvo
		free(tmp);               //eleutherwnei ton prohgoymeno komvo tis listas
		tmp = node;              //vazei to voithitiko kovmo ston 1o komvo tis neas listas
    }
}
//dimioyrgia komvwn kai eisagwgi stoixeiwn sti lista
struct list *insertNodeList(int v, struct list *listHead) { 
   struct list *node;
   node=(struct list *)malloc(sizeof(struct list));       //dynamiki desmeusi mnimis gia ena komvo
   node->value = v;                         //vazei ti timi poy dwsame sti main sto komvo
   node->next = listHead; /* kalyptei kai ti periptwsi poy i kefali head == NULL */
   return node;                 /* epistrefoyme ti nea kefali tis listas */
}
//ANADROMIKI synartisi gia to elegxo ikanopoihshs toy kritirioy
struct list *searchNextNodeList( struct list *ptr) { 
	struct list *node;
	struct list *node2;
	if ((ptr!=NULL) && ((ptr)->next!=NULL)){       //h synthiki auti eksasfalizei ousiastika oti doyleuei to programma mas kai gia lista me 0-1 komvous 
		node=(ptr)->next;                          //den mporoume dld na valoume se NULL na deixnei ston epomeno komvo afou eimaste hdh sto telos tis listas
		node2=(node)->next;                        //den yparxei epomenos komvos an isxyei i synthiki
	}

	if ((ptr==NULL) || ((ptr)->next == NULL) || ((node)->next == NULL)){         // edw elegxoyme oti an 1 apo mia triada apo komvoys deixnei se NULL
		printf("to kritirio ikanopoieitai");                                     //tote ikanopoieitai to kritirio
		return NULL;                                                             //kai epistrefw NULL opws leei h ekfwnisi
	}
	if ((ptr)->value >= (((node)->value)*((node2)->value)) && (node!=NULL) && (node2!=NULL)){         //elegxoyme an to periexomeno toy komvou poy deixnei o ptr einai
		printf("\nto kritirio den ikanopoieitai kai i triada arithmwn einai i parakatw");             //>= apto ginomeno twn antistoixwn poy deixnoyn oi node kai node2
		printf("\n1st node=%d",(ptr)->value);                                                         //dld pote DEN isxyei to kritirio kai typonw parakatw
		printf("\n2nd node=%d",(node)->value);                                                        //tin 3ada poy den isxyei
		printf("\n3rd node=%d",(node2)->value);
		return ptr;}                                                              //epistrefw to deikti poy deixnei ston 1o komvo tis triadas
	else
		return searchNextNodeList( ((ptr)->next) );                               //ANADROMIKI klisi tis synartisis, paw tin kefali ston epomeno komvo kai ksanatrexw ti synartisi
}                                                                                 //mexri eite na vrw triada poy den ikanopoiei to kritirio eite na ikanopoieitai kai 
                                                                                  //ayta poy grapsa parapanw         
//ARXH main
int main(){
	
	struct list *head;
	struct list *node3;
	char flag;
	int value,j,n,k;
	do{                               //epanaliptiki leitourgia toy programmatos
		// the list is initially empty
		head = NULL;


		printf("\ndwse arithmo akeraiwn tis listas: ");         //dineis ton arithmo akeraiwn-komvwn poy thes na valeis sti lista soy
		scanf("%d",&n);
		if (n>0){                           
			k=n;
			for (j=0;j<n;j++){
				printf("dwse to %do stoixeio tis listas: ",k);           //dineis ta stoixeia tis listas apo to telos pros tin arxi
				scanf("%d",&value);	
				k--;
				head=insertNodeList(value,head);                        //klisi tis synartisis, me parametrous to value poy diavases parapanw kai to head, dld tin kefali tis listas
                                                                        //poy deixnei stin arxi tis listas, poy dimioyrgei toys komvous tis listas kai tous gemizei me tis times 
			}                                                           //poy dwses parapanw
		
			printList(head);                                           //typwnei ta stoixeia tis listas, ta values 
			printf("\n");
		}
		node3 = searchNextNodeList(head);                              //klisi tis ANADROMIKIS synartisis me parametro to deikti poy deixnei stin arxi tis listas
		if (node3!=NULL)	                                          //an h epistrofi tis synartisis den einai NULL ara epestrepse mia timi sto deikti node3 poy deixnei 
			printf("\nto 1o stoixeio tis triadas einai: %d",(node3)->value);           //sto 1o komvo tis 3adas poy DEN ikanopoiei to kritirio kai edw emfanizoyme ti timi tou
		else
			printf("\nH synartisi epestrepse NULL");                      //alliws epestrepse NULL kai emfanizoyme to katallilo mnm
		printf("\n");
		//free the list
		freeList(head);	          //klisi tis synartisis poy eleutherwnei tous komvous tis listas

		printf("\nThes na ksanatrekseis to programma;(y/n)");             
		scanf("%s",&flag);
	}while (flag=='y');

	return(0);
}
