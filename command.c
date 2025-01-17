#include <stdio.h>
#include "header.h"



/*----------------------C----------------------------*/
// fonction strlen : compter le nombre de char - \n
int c_strlen(char *str){
    int i = 0; //compteur 
    while(str[i] != '\0') // tant que le char \0 nest pas i++
        i++;
    return i ;
}
// focntion pouyr armoniser les condition de main
int compare_comand(const char *input, const char *cmd){
    int i = 0;
    while(cmd[i] != '\0' && input[i] != '\0'){
        if(input[i] != cmd[i]){
            return 0; // les commande ne correspondent pas
        }
        i++;
    }
    return cmd[i] == '\0' && input[i] == '\0'; 
}


/*---------------------SHELL------------------*/

int c_ls(int argc, char *argv[]){
    FILE *fp;
    char path[1035];
    fp = popen("ls -la", "r");  // Ouvre un flux pour la commande "ls"
    if (fp == NULL) {
        perror("Erreur lors de l'exécution de la commande");
        return 1;
    }
    while (fgets(path, sizeof(path), fp) != NULL) {
        printf("%s", path);  // Affiche chaque ligne lue
    }
    fclose(fp);  // Ferme le flux
    return 0;
}
int c_help(int argc, char *argv[]){
    printf("pas d'aide pour les heretiques !!!\n");
    return 0;
}                                      
int c_touch(char *filename){    
    FILE *fp;
    if(filename == NULL || *filename == '\0'){
        printf("ERREUR NOM DU FICHIER VIDE\n");
        return 1;
    }
    fp = fopen(filename, "w");
    if (fp == NULL){
        perror("ERROR\n");
        return 1;
    }
    fclose(fp);
    printf("ficher crée avec succes\n");
    return 0;
}

int c_exit(){
    return 1;
}

//chaque espace == nouvelle ligne
int c_strplit(){ 

    return 0;
}
