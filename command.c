#include <stdio.h>
#include "header.h"

// token split fonction
#define TOKEN_CMD 0
#define TOKEN_ARG1 1
#define TOKEN_ARG2 2

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

int split(char* user_input, char* arg1, char* arg2){

    int args_max = 2; // nb max args
         
    int token = 0; // referenc token
    int token_cmd = TOKEN_CMD; // init token (case) == cp
    int token_arg1 = TOKEN_ARG1; // == nates
    int token_arg2 = TOKEN_ARG2; // path

    int cursor = 0; // curseur char 
    int cursor_token = 0;

    for(; user_input[cursor] != '\0'; cursor++ ){
        if(*(user_input + cursor) == ' ' || *(user_input + cursor) == '\n' ||*(user_input + cursor) == '\r' ){ // verification changement mots
            switch(token){ // delimitation arg
                case 1:
                    *(arg1 + cursor_token) = '\0';
                    break;
                case 2:
                    *(arg2 + cursor_token) = '\0';
                    break;
            }
            token++;
            cursor_token = 0;
          }
        else{
            switch (token){ // lecture + affectation
                case 0:
                    break;
                case 1:
                    *(arg1 + cursor_token) = *(user_input + cursor);
                    break;
                case 2:
                     *(arg2 + cursor_token)= *(user_input + cursor);
                    break;
                default:
                    printf("trop d'arguments\n"); 
            }
            cursor_token++;
        }            
     }
    return token;
};

int c_include(char* str,char* str2 ){ // check les mort dans str2 > str
    int strlen_temp = c_strlen(str2);
    for(size_t i = 0; *(str + i) != '\0'; i++){
        if(i >= strlen_temp)
            break;
        if(*(str + i ) != *(str2 + i))
            return 0;
     }
    return 1;
}
        


/*---------------------SHELL------------------*/

int c_ls(char* filename, char* filename1){
    FILE *fp;
    char path[1035];
    fp = popen("colorls -la", "r");  // Ouvre un flux pour la commande "ls"
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
          
int c_cp(char *filename, char *filename1) {
    // Ouvrir le fichier source en lecture
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ERREUR : Impossible d'ouvrir le fichier à copier '%s'\n", filename);
        return 1;
    }

    // Ouvrir le fichier destination en écriture
    FILE *fp1 = fopen(filename1, "a");
    if (fp1 == NULL) {
        printf("ERREUR : Impossible d'ouvrir le fichier de destination '%s'\n", filename1);
        fclose(fp);  // Fermer le fichier source ouvert
        return 1;
    }

    // Copier le contenu du fichier source vers le fichier destination
    char buffer[256];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        fwrite(buffer, 1, n, fp1);
    }

    // Fermer les fichiers
    fclose(fp);
    fclose(fp1);

    printf("Le fichier '%s' a été copié vers '%s'.\n", filename, filename1);
    return 0;
}
int c_mv(char *filename, char *filename1) {
    // Ouvrir le fichier source en lecture
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ERREUR : Impossible de trouver le chemin d'oringine '%s'\n", filename);
        return 1;
    }

    // Ouvrir le fichier destination en écriture
    FILE *fp1 = fopen(filename1, "a");
    if (fp1 == NULL) {
        printf("ERREUR : Impossible de trouver le chemin de destination '%s'\n", filename1);
        fclose(fp);  // Fermer le fichier source ouvert
        return 1;
    }

    // Copier le contenu du fichier source vers le fichier destination
    char buffer[1024];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        fwrite(buffer, 1, n, fp1);
    }

    // Fermer les fichiers
    fclose(fp);
    fclose(fp1);
    remove(filename);
    printf("Le fichier '%s' a été deplacé vers '%s'.\n", filename, filename1);
    return 0;
}
int c_rm(char *filename){
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
    printf("ficher supprimer avec succes\n");
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
