#include <stdio.h>
#include "header.h"

#define MAX_CMD_LENGHT 100

int main(int argc, char *argv[]) {
    char str[MAX_CMD_LENGHT];  // Tableau pour l'entrée de l'utilisateur
    
    //liste comand
    char exitCMD[] = "exit";  // Commande pour quitter
    char ls[] = "ls";  // Commande pour lister les fichiers
    char help[] = "help"; // ccmd help == guide
    char touch[] = "touch";
//    char *argv2[];

    while (1) {
        printf("user@computer:~$ ");  // Affiche l'invite de commande
        fgets(str, sizeof(str), stdin);  // Lit l'entrée de l'utilisateur
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
        
        if (compare_comand(str, exitCMD)) {
            c_exit(str, exitCMD);// Si la commande est exactement "exit", check str[j] == 0 , exitCMD[j] == 0
            break;  // Quitte le programme
        }

        if (compare_comand(str, ls)) {  // Si la commande est exactement "ls"
            // Simulation de la commande 'ls' en affichant des fichiers fictifs
            c_ls(argc,argv);
        } 

        if(compare_comand(str, help))
            c_help(argc, argv);
       
        if(compare_comand(str, touch)){
            char *filename = str + c_strlen(touch) + 1; //salope
            c_touch(filename);
        }
    }
    return 0;
}  
