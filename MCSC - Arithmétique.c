MCSC - Arithmétique
Date limite : 22 oct. 2018 01:59
Établir un code en langage C permettant de calculer le pcgd de deux entiers en utilisant la décomposition en nombres premiers ainsi que l'algorithme Euclidien. Comparer entre les deux codes en terme de rapidité et taille de données possible en Input.
3,5/5
3,5 points sur 5
Youssouf Amal 5 oct. 2018 (Modification : 29 oct. 2018)
Commentaires ajoutés au cours
Youssouf Amal13 oct. 2018
Le dernier délai pour rendre le devoir est le 19 oct!
Youssouf Amal20 oct. 2018
les étudiants qui n'ont pas encore envoyés leur devoir: Fayad Dayaf, Hamza Ouamzane, Oualid Batali, soufiane lagziri.
Youssouf Amal21 oct. 2018
Si vous cherchez une fct de la lib gmp.h, voici un site intéressant:

https://machinecognitis.github.io/Math.Gmp.Native/html/846f5c8a-6cba-433e-9f18-cde2ff5695cd.htm
Youssouf Amal3 nov. 2018
Je vous informe que les codes dont les debug et les erreurs sont semblables ont été pénalisés.
Votre devoir
Noté
Les fichiers que vous ajoutez ou créez peuvent être consultés et modifiés par votre enseignant.
BATALI_OUALID.c
C
BATALI_OUALID.py
Texte
Commentaires privés

/* 
Created on Fri Oct 17 21:44:13 2018
@author: BATALI OUALID
*/


#include<stdio.h>
#include<stdlib.h>


/* # CALCUL DU PGCD PAR LA METHODE D'EULER ET PAR LA DECOMPOSITION EN FACTEURS PREMIERS */
int pgcd_avec_decompo(int n, int m);
int pgcd_avec_euclide(int n, int m);
//DEFINITION DES FONCTIONS 
int pgcd_avec_decompo(int n, int m){
	int i, pgcd, indice , j ,k, l;
	i = 2;
	pgcd = 1;
	while(n > 1 && m > 1){
		j = 0;
		while (n % i == 0){
			j = j + 1;
			n = n / i ;}
		k = 0;
		while (m % i == 0){
			k = k + 1;
			m = m / i ;}
		if (j >= k ) {indice = k;}
		else {indice = j;}
		for (int l =0;l<indice;l++){
			pgcd = pgcd * i;}
		i++;
	}
	return (pgcd);} 

int pgcd_avec_euclide(int a, int b ){
	int r; // r c'est le reste de la division euclidienne
	r = a % b ;
	while(r != 0){
		a = b;
		b = r;
		r = a % b;}
	return(b);
}
/* FONCTIN PRINCIPALE POUR TESTER LES DEUX METHODES */ 

int main(){
	int a,b;

	printf("Donner la valeur de a  :  ");
	scanf("%d",&a);
	printf("Donner la valeur de b  :  ");
	scanf("%d",&b);
	printf("PGCD par Euclide : pgcd(%d,%d)= %d \n ",a,b,pgcd_avec_euclide(a,b));
	printf("PGCD par decomposition : pgcd(%d,%d)= %d \n ",a,b,pgcd_avec_decompo(a,b));
	return 0;
}





BATALI_OUALID.c
BATALI_OUALID.c est maintenant affiché.