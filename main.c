#include <stdio.h>
#include "header.h"

#define MAX_CMD_LENGTH 100


int main(int argc, char *argv[]) {
    char user_inuput[MAX_CMD_LENGTH] = {0};  // Tableau pour l'entrée de l'utilisateur
    char arg1[MAX_CMD_LENGTH] = {0}; // bon format d'init
    char arg2[MAX_CMD_LENGTH] = {0};
    //liste comand
    char exitCMD[] = "exit";  // Commande pour quitter
    char ls[] = "ls";  // Commande pour lister les fichiers
    char help[] = "help"; // ccmd help == guide
    char touch[] = "touch";
    char pwd[] = "pwd";
    char cat[] = "cat";
    char head[] = "head";
    char rm[] = "rm";
    char cp[] = "cp";

    

    while (1) {
      printf("user@computer:~$ ");  // Affiche l'invite de commande
        fgets(user_inuput, sizeof(user_inuput), stdin);  // Lit l'entrée de l'utilisateur
        //Enlever le '\n' à la fin de la chaîne (si présent)
        split(user_inuput, arg1, arg2);
        printf("input : %s\narg1 : %s\narg2 :%s\n", user_inuput, arg1, arg2);
    
        int i = 0;
      while (user_inuput[i] != '\0') {
            if (user_inuput[i] == '\n') {
                user_inuput[i] = '\0';  // Remplacer '\n' par '\0' pour finir la chaîne
                break;
            }
            i++;
             
        } 
        if (compare_comand(user_inuput, exitCMD)) {
            c_exit(user_inuput, exitCMD);// Si la commande est exactement "exit", check str[j] == 0 , exitCMD[j] == 0
            break;  // Quitte le programme
        }

        if (compare_comand(user_inuput, ls)) {  // Si la commande est exactement "ls"
            // Simulation de la commande 'ls' en affichant des fichiers fictifs
            c_ls(argc,argv);
            continue;
        }

        if (compare_comand(user_inuput, pwd)){
            c_pwd(argc, argv);
            continue;
        }

        if(compare_comand(user_inuput, help)){
            c_help(argc, argv);
            continue;
        }
        if(c_include(user_inuput, touch)){ 
            split(user_inuput, arg1,arg2);
            char* filename =  arg1;
             c_touch(filename);    
             continue;
        }
        if(c_include(user_inuput, rm)){
            split(user_inuput,arg1,arg2);
            char* filename = arg1;
            remove(filename);
            continue;
        }

        if(c_include(user_inuput, cat)){
            split(user_inuput, arg1,arg2);
            char* filename = arg1;
            c_cat(filename);
            continue;
        }
         if(c_include(user_inuput, head)){
            split(user_inuput, arg1,arg2);
            char* filename = arg1;
            c_head(filename);
            continue;
        }
         if(c_include(user_inuput, cp)){
            split(user_inuput, arg1, arg2);;
            char* filename = arg1;
            char* filename1= arg2;
            c_cp(filename, filename1);
            continue;
         }
        else
            printf("Aucune commande : '%s'\n",user_inuput);
    }
    return 0;
}  
