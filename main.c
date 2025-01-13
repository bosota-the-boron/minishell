#include <stdio.h>
#include "header.h"


int main(int argc, char *argv[]) {
    char str[100];  // Tableau pour l'entrée de l'utilisateur
    char exitCMD[] = "exit";  // Commande pour quitter
    char ls[] = "ls";  // Commande pour lister les fichiers
    while (1) {
        printf("user@computer:~$ ");  // Affiche l'invite de commande
        fgets(str, sizeof(str), stdin);  // Lit l'entrée de l'utilisateur
        //printf("L'entree a : %d char \n",my_strlen(str));
        //Enlever le '\n' à la fin de la chaîne (si présent)
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] == '\n') {
                str[i] = '\0';  // Remplacer '\n' par '\0' pour finir la chaîne
                break;
            }
            i++;
        }

        // Comparaison manuelle de la commande "exit"
        int j = 0;
        int iexit = 1;
        while (exitCMD[j] != '\0' && str[j] != '\0') {
            if (str[j] != exitCMD[j]) {
                iexit = 0;  // Si les caractères ne correspondent pas, ce n'est pas "exit" m
                break;
            }
            j++;
        }
        if (iexit && str[j] == '\0'&& exitCMD[j] == '\0') {  // Si la commande est exactement "exit", check str[j] == 0 , exitCMD[j] == 0
            break;  // Quitte le programme
        }

        // Comparaison manuelle de la commande "ls"
        int k = 0;
        int ils = 1;
        while (ls[k] != '\0' && str[k] != '\0') {
            if (str[k] != ls[k]) {
                ils = 0;  // Si les caractères ne correspondent pas, ce n'est pas "ls"
                break;
            }
            k++;
        }

        if (ils && str[k] == '\0' && ls[k] == '\0') {  // Si la commande est exactement "ls"
            // Simulation de la commande 'ls' en affichant des fichiers fictifs
            c_ls(argc,argv);
            c_help(argc,argv);      
        } else {    
            printf("Commande inconnue: %s\n", str);  // Commande non reconnue
        }
    }

    return 0;
}

