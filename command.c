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


int c_HasSpace(char *str){ // = a espace 
    for(size_t i = 0; *(str + i) != '\0'; i++){ // *(str + i) == str[i]
        if(*(str + i) == ' ')
            return 1;
    }
    return 0;
}

void c_StockStr(char *str, char *str2){ // stpck apres espace > str2
    int count = 0, found = 0;
    
    for(size_t i = 0; *(str + i) != '\0'; i++){
        if (found){
            *(str2 + count) = *(str +i);
            count++;
        }
        if (*(str + i ) == ' ')
            found = 1;

    }
}    

int c_include(char* str,char* str2 ){ // check les mort dans str2 > str
    for(size_t i = 0; *(str + i) != '\0'; i++){
        if(i >= c_strlen(str2))
            break;
        if(*(str + i ) != *(str2 + i))
            return 0;
     }
    return 1;
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
int c_cat(char *filename){    
    FILE *fp;
    char line[1035];
    if(filename == NULL || *filename == '\0'){
        printf("ERREUR NOM DU FICHIER A LIRE VIDE\n");
        return 1;
    }
    fp = fopen(filename, "r");
    if (fp == NULL){
        perror("ERROR ");
        return 1;
    }
    while(fgets(line, sizeof(line), fp) != NULL){ // lis chaque ligne
        printf("%s", line); //les affiches  
    }
    fclose(fp);
    printf("lecture en cour : '%s'\n", filename);
    return 0;
}

int c_head(char* filename){
    FILE *fp;
    char line[1035];
    int i = 0;
    if(filename == NULL || *filename == '\0'){
        printf("ERREUR NOM DU FICHIER A HEAD VIDE");
        return 1;
    }
    fp = fopen(filename, "r");
    if(fp == NULL){
        perror("ERROR");
        return 1;
    }
    while(fgets(line, sizeof(line),fp) != NULL && i < 5){
        printf("%s", line);
        i++;
    }

}

int c_exit(){
    return 1;
}

int c_pwd(int argc, char *argv[]){
    FILE *fp;
    char path[1035];
    fp = popen("pwd", "r");
    if (fp == NULL){
           perror("Erreur lors de l'exécution de la commande");
            return 1;
    }

    while (fgets(path, sizeof(path), fp) != NULL) {
    printf("%s", path);
    }
    fclose(fp);
    return 1;

}
