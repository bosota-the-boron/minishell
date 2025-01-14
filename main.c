#include <stdio.h>
#include "header.h" char *filename = str + i2 + 1;  


int main(int argc, char *argv[]) {
    char str[100];  // Tableau pour l'entrée de l'utilisateur
    
    //liste comand
    char exitCMD[] = "exit";  // Commande pour quitter
    char ls[] = "ls";  // Commande pour lister les fichiers
    char help[] = "help"; // ccmd help == guide
    char touch[] = "touch";
//    char *argv2[];

    while (1) {
        printf("user@computer:~$ ");  // Affiche l'invite de commande
        fgets(str, sizeof(str), stdin);  // Lit l'entrée de l'utilisateur
       printf("L'entree a : %d char \n",c_strlen(str));
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
        } 
        int i1 = 0;
        int ihelp = 1;
        while(help[i1] != '\0' && str[i1] != '\0'){
            if(str[i1] != help[i1]){
                ihelp = 0;
                break;
            }
            i1++;
        }
        if(ihelp && str[i1] == '\0' && help[i1] == '\0')
            c_help(argc, argv);
       
        int i2 = 0;
        int itouch = 1;
        while(touch[i2] != '\0' && str[i2] != ' '){
            if(str[i2] != touch[i2]){
                itouch = 0;
                break;
            }
            i2++;
        }
        printf("test içi : '%s' |\n",str);    
        if(itouch && str[i2] == ' ' && touch[i2] == '\0'){
            char *filename = str + i2 + 1; //salope
            c_touch(filename);
        }
        else
            printf("test içi hors condition: '%d' |\n",argc);

    }
    return 0;
}  
