MCSC - Arithmétique
Date limite : 1 déc. 2018 13:00
Établir un code en langage C permettant de résoudre l'identité de Bézout: au+bv=d. La meilleur note sera pour le programme le plus rapide!
5 points
Youssouf Amal 16 oct. 2018 (Modification : 1 déc. 2018)
Commentaires ajoutés au cours
Votre devoir
Remis
devoir2.c
C
Commentaires privés

#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>
#include<assert.h>

/* Author : BATALI OUALID */ 
// COMMANDE POUR COMPILER LE FICHIER : gcc -o devoir2 devoir2.c -lgmp 
int main(){

	printf("#____CALCUL DES COEFFICIENTS DE BEZOUT DE DEUX ENTIERS NATURELS PAR L'ALGORITHME D'EUCLIDE ETTENDU___# \n ");
     	char inputStr1[1024];
	char inputStr2[1024];	
	
	mpz_t x, y, u, v, reste, c, q, a, b, m; 
	int flag_a, flag_b;
	/* Initialisation des variables */
	mpz_init_set_ui(a,0);
	mpz_init_set_ui(b,0);
	mpz_init_set_ui(x,0);
	mpz_init_set_ui(y,1);
	mpz_init_set_ui(u,1);
	mpz_init_set_ui(v,0);
	mpz_init_set_ui(reste,0);
	mpz_init_set_ui(q,0);
	mpz_init_set_ui(c,0);
	mpz_init_set_ui(m,0);
	printf("Donner la valeur de l'entier naturel a (une valeur non nulle)  = ");
       	scanf("%1023s",inputStr1);
       	printf("Donner la valeur de l'entier naturel  b  (une valeur non nulle) =   ");
       	scanf("%1023s",inputStr2);	
	flag_a = mpz_set_str(a,inputStr1,10);
       	flag_b = mpz_set_str(b,inputStr2,10);
	assert(flag_a == 0);// Si le flag est nulle => echec de l'operation
	assert(flag_b == 0); // Si le flag est null => echec de l'operation
	if (mpz_cmp(a,b) > 0){ mpz_swap(a,b);}// Inverser les valeurs de a et b;
	mpz_tdiv_r(reste,a,b);// reste = a % b;
       	while(mpz_sgn(reste) != 0){	
		mpz_set(a,b);//a = b;
		mpz_set(b,reste); //b = reste;
		mpz_tdiv_qr(q,reste,a,b); // Une affecation double du Quotient q = [a/b] et du  reste = a%b
		// Operations de recurrence pour calculer les coefs Vi de a 
		mpz_mul(m,q,y);mpz_sub(c,x,m); mpz_set(x,y) ; mpz_set(y,c); // c = x - q * y ; u = v ; v = c 
		// Operations de recurrence pour calculer les coefs Ui de b
		mpz_mul(m,q,v);mpz_sub(c,u,m); mpz_set(u,v) ; mpz_set(v,c);// c = u - q * v ; u = v ; v = c 
		}
	printf("le pgcd est : "); // LE PGCD DE A ET B 
	mpz_out_str(stdout,10,b);
	printf("\n ");
	if (mpz_cmp(a,b) > 0){mpz_swap(u,x);} // Si a > b alors on doit inverser les valeurs u et x trouves dans la boucle While 		
	printf("les coefficients de Bezout sont (u,v) = (");	
	mpz_out_str(stdout,10,u);
	printf(" ; ");
	mpz_out_str(stdout,10,x); 
	printf(" ) ");
	printf(" \n \n ");
	//Netoyage de la memoire utilisee !
	mpz_clear(a);
	mpz_clear(b) ;
	mpz_clear(u);
       	mpz_clear(v);
	mpz_clear(x);
	mpz_clear(y); 
	mpz_clear(reste);
       	mpz_clear(q);
	mpz_clear(c);
       	mpz_clear(m); 

}





devoir2.c
devoir2.c est maintenant affiché.