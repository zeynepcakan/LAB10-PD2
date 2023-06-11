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

int elemanSay(){
	int adet=0;
	if(start==NULL)
		return adet;
	else{
		temp=start;
		while(temp->next!=NULL){
			adet++;
			temp=temp->next;
		}
		adet++;
		return adet;
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
	
	while(secim!=5){
		
		printf("-Basa eleman eklemek icin:...........1\n");
		printf("-Sona eleman eklemek icin:...........2\n");
		printf("-Eleman adeti bulmak icin:...........3\n");
		printf("-Ortadaki elemani silmek icin:.......4\n");
		printf("-Cikmak icin:........................5\n\n");
		 
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
				printf("\nEleman adeti: %d\n",elemanSay());
				break;	
			case 4:
				printf("Ortadaki eleman siliniyor...\n");
				if (elemanSay() % 2 == 1) {
					int i;
					int ortaIndex = ((elemanSay()+1)/2)-1;
					temp = start;
					for (i = 0; i < ortaIndex-1 ; i++) {
					temp = temp->next;
				}
				struct node *silinen = temp->next;
				temp->next = temp->next->next;
				free(silinen);
			}
			else {
				printf("Ortada eleman yok!\n");
			}
				yazdir();
				break;
			
			case 5:
			break;		
						
		}
		printf("\n");
	}
	return 0;
} 
