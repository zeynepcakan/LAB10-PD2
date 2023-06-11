#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *start=NULL;
struct node *temp=NULL;

void basaEkle(int veri){
	struct node *eleman;
	eleman=(struct node*)malloc(sizeof(struct node));
	eleman->data= veri;
	eleman->next=start;
	start=eleman;
}

void sonaEkle(int veri){
	struct node *eleman;
	eleman=(struct node*)malloc(sizeof(struct node));
	eleman->data= veri;
	eleman->next=NULL;
	
	if(start==NULL)//hiç eleman yoksa;
		start=eleman;
	else
	{
		temp=start;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=eleman;
	}
}

void cutFirstAddLast() {
    if (start != NULL && start->next != NULL) {
        struct node *second = start->next;
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = start;
        start->next = NULL;
        start = second;
    }
}

void yazdir(){
	system("cls");
	if(start!=NULL){
		temp=start;
		while(temp->next!=NULL){
			printf(" %d ",temp->data);
			temp=temp->next;
		}
		printf(" %d ",temp->data);
	}
	else
		printf("Eleman yok!!!\n");
}

int main() {
	
	
	int sayi,secim,n,veri;
	
	while(secim!=4){
		
		printf("-Basa eleman eklemek icin:...........1\n");
		printf("-Sona eleman eklemek icin:...........2\n");
		printf("-Bastaki ve sondaki elemani degistir:3\n");
		printf("-Cikmak icin:........................4\n\n");
		 
		printf("Seciminizi yapin \n"); scanf("%d",&secim);
		
		switch(secim){
			
			case 1:
				printf("basa eklenecek elemanin degeri:");
				scanf("%d",&sayi);
				basaEkle(sayi);
				yazdir();
				break;
			
			case 2:
				printf("sona eklenecek elemanin degeri:");
				scanf("%d",&sayi);
				sonaEkle(sayi);
				yazdir();
				break;
			
			case 3:
				cutFirstAddLast();
				yazdir();
				break;	
			case 4:
				break;	
						
		}
		printf("\n");
	}
	return 0;
} 
