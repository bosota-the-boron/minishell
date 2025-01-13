#include <stdio.h>
#include "header.h"



// fonction strlen : compter le nombre de char - \n
int my_strlen(char *str){
    int i = 0; //compteur 
    while(str[i] != '\0') // tant que le char \0 nest pas i++
        i++;
    return i - 1;

}
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
    FILE *fp;
    fp = popen("help", "r");
    if (fp == NULL){
        perror("Errur lors de l'execution de la commande");
        return 1;
    }
    fclose(fp);
    return 0;
}

