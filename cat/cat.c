#include <stdio.h>
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
    if(isDir(argv[1])){
        printf("file is dir!\n");exit(1);
    }
    FILE *fp;
    char str[22];
    if(argv[1]==NULL) exit(1);
    if((fp=fopen(argv[1],"r"))==NULL){
        printf("open file failed\n");exit(1);
    }
    while(!feof(fp)){
        fgets(str,22,fp);
        printf("%s",str);
    }
    fclose(fp);
}

