#include <stdio.h>
#include "header.h"

#define MAX_CMD_LENGTH 100


int main(int argc, char *argv[]) {
    char str[MAX_CMD_LENGTH];  // Tableau pour l'entrée de l'utilisateur
    char str1[MAX_CMD_LENGTH];
    char str2[MAX_CMD_LENGTH];

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

           
        if (compare_comand(str, exitCMD)) {
            c_exit(str, exitCMD);// Si la commande est exactement "exit", check str[j] == 0 , exitCMD[j] == 0
            break;  // Quitte le programme
        }

        if (compare_comand(str, ls)) {  // Si la commande est exactement "ls"
            // Simulation de la commande 'ls' en affichant des fichiers fictifs
            c_ls(argc,argv);
            continue;
        } 

        if(compare_comand(str, help)){
            c_help(argc, argv);
            continue;
        }
        if(compare_comand(str, touch)){                                                                                              
            c_space(str, str1, str2);
             char *filename =  str2 + 1; //salope
             c_touch(filename);
             
        }
        
        else
            printf("Aucune commande : '%s'\n",str);
    }
    return 0;
}  
