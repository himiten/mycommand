#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

int isDir(char *str){
    struct stat buf;
    stat(str,&buf);
    if(_S_IFDIR & buf.st_mode){
        return 1;
    } else{
        return 0;
    }
}
int main(int argc,char** argv)
{
    DIR *dir;
    struct dirent *ptr;
    int n=0;
    char *dir_name="./";
    if(argv[1]!=NULL) dir_name=argv[1];
    if(!isDir(dir_name)){
        printf("file can't show list!\n");exit(1);
    }
    dir=opendir(dir_name);
    while ((ptr=readdir(dir))!=NULL){
        const char *s1=".";
        const char *s2="..";
        if(strcmp(s1,ptr->d_name)!=0 && strcmp(s2,ptr->d_name)!=0 ){
            printf("  %s ",ptr->d_name); n++;
        }
        if(n!=0 && n%8==0){
            printf("\n");
        }
    }
    closedir(dir);
    return 0;
}
