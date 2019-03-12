#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct Bliste {
	int veri;
	struct Bliste *ileri;
	struct Bliste *kontrol;
	struct Bliste *listebasi;
};
struct Bliste* yeni_bliste = NULL;
void dugum_ekle(int yeni_veri) {
	struct Bliste* yeni_Bliste = (struct Bliste*)malloc(sizeof(Bliste));
	yeni_Bliste->veri = yeni_veri;
	yeni_Bliste->ileri = yeni_bliste;
	yeni_bliste = yeni_Bliste;
}
void ekranayaz() {
	struct Bliste* dugumPtr;
	dugumPtr = yeni_bliste;
	while (dugumPtr != NULL) {
	cout << dugumPtr->veri << " ";
	dugumPtr = dugumPtr->ileri;
	}
}
void eleman_ekle(int yeni) {
	struct Bliste *kontrol = yeni_bliste;
	while (kontrol->ileri != NULL) {
		kontrol = kontrol->ileri;
	}
	kontrol->ileri = (struct Bliste*)malloc(sizeof(Bliste));
	kontrol->ileri->veri = yeni;
	kontrol->ileri->ileri = NULL;
}
int main() {
	int key,i,j;
	dugum_ekle(5);
	dugum_ekle(12);
	dugum_ekle(3);
	dugum_ekle(23);
	dugum_ekle(4);
	cout << "Tek yonlu Bagli Liste: ";
	ekranayaz();
	cout << "\nEleman Giriniz: ";
	cin >> i;
	eleman_ekle(i);
	cout << "\n";
	cout << "Tek yonlu Bagli Liste Yeni Hali: ";
	ekranayaz();
	cout << "\n";
	return 0;
}
