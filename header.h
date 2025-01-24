#ifndef HEADER_H
#define HEADER_H
// fonction strlen : compter le nombre de char - \n
int c_strlen(char* str); // nombre de char 
int c_ls(int argc, char* argv[]); // fonction ls
int c_help(int argc, char* argv[]); // focntion help
int c_touch(char* filename);
int c_rm(char *filename);
int c_cat(char* filename);
int c_cp(char* filename, char* filename1);
int compare_comand(const char* input, const char* cmd);
int c_exit();
void c_StockStr(char* str, char* str2, char* str3);
int c_include(char* str,char* str2);
int c_pwd(int argc, char* argv[]); 
int c_head(char* filename);
int split(char* input, char* arg1, char* arg2);
#endif
