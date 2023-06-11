#include <stdio.h>
#include <stdlib.h>

struct dugum
{
	int veri;
	struct dugum *gosterici;
};

struct dugum *bas=NULL;
struct dugum *gecici=NULL;

void basaEkle(int sayi){
	struct dugum *eklenecek;
	eklenecek=(struct dugum*)malloc(sizeof(struct dugum));
	eklenecek->veri=sayi;
	eklenecek->gosterici=bas;
	bas=eklenecek;
}

void sonaEkle(int sayi){
	struct dugum *eklenecek;
	eklenecek=(struct dugum*)malloc(sizeof(struct dugum));
	eklenecek->veri=sayi;
	eklenecek->gosterici=NULL;
	
	if(bas==NULL){ //liste boþ;
		bas=eklenecek;
	}
	else // liste doluysa;
	{
		gecici=bas;
		while(gecici->gosterici!=NULL){
			gecici=gecici->gosterici;
		}
		gecici->gosterici=eklenecek;
	}
}

void yazdir(){
	gecici=bas;
	while(gecici->gosterici!=NULL ){
		if(gecici->veri!=-1)
			printf(" %d ",gecici->veri);
		gecici=gecici->gosterici;
	}
	printf(" %d ",gecici->veri);//Null karakter için;
}

int main() {
	int sayi=0;
	while(sayi!=-1){
		printf("sayi girin(stop -1):");
		scanf("%d",&sayi);
		if(sayi%2==0){
			sonaEkle(sayi);
		}
		else{
			basaEkle(sayi);
		}
	}
	yazdir();
	return 0;
}
