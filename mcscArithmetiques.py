# Python --version : Python 2.7.15rc1
"""
Created on Fri Oct 19 21:44:13 2018
@author: BATALI OUALID
""" 
# -*- coding: utf-8 -*- 
# Methode 1: calcul du pgcd par l'algorithme d'euclide

def pgcd_avec_euclide(a,b):
    while (a%b != 0):
        a , b = b , a%b
    return b 

# Methode 2: Calcul du pgcd en utilisant la decomposition en facteurs premiers 
def puissance_premier(i,a):
    """Cette fonction retourne l'exposant du divieur i
    dans la factorisatin en nombres premiers de a """
    exposant = 0
    while a % i == 0 :
        exposant = exposant + 1
        a = a/i 
    return (exposant,a)

def pgcd_avec_decompo(n,m): 
    i = 2
    pgcd = 1 
    while n > 1 and m > 1: 
        j,n = puissance_premier(i,n)
        k,m = puissance_premier(i,m)
        if j >= k :
            indice = k 
        else :
            indice = j
        pgcd = pgcd * pow(i,indice)
        i=i+1 
    return pgcd 

## DES TESTS POUR VERIFIER LES ALGORITHMES 
if __name__ == '__main__' :
    a = int(input("Donner un entier a :"))
    b = int(input("Donner un entier b :"))
    print("LE PGCD AVEC LA METHODE d'Euler est ",pgcd_avec_euclide(a,b))
    print("LE PGCD AVEC LA METHODE de decomposition est ", pgcd_avec_decompo(a,b)) 
    # Comparaison en termes de rapidite!
