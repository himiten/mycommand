#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char* join(char *s1,char *s2){
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    if(result == NULL) exit(1);
    strcpy(result,s1);
    strcat(result,s2);
    return result;
}

int main(int argc,char** argv)
{
    if(argc!=3){
        printf("参数错误!");
        return 0;
    }
    FILE *sfp,*dfp;
    int c;
    sfp=fopen(argv[1],"rb");

    struct stat buf;
    stat(argv[2],&buf);
    if(_S_IFDIR & buf.st_mode){
        char *separate="\\";
        char *tmp_name=join(separate,argv[1]);
        char *file_path=join(argv[2],tmp_name);
        dfp=fopen(file_path,"wb");
    } else{
        dfp=fopen(argv[2],"wb");
    }

    if(sfp==NULL || dfp==NULL){
        printf("open file failed!");
        if(sfp) fclose(sfp);
        if(dfp) fclose(dfp);
        return 0;
    }else{
        while((c=fgetc(sfp))!=EOF){
            fputc(c,dfp);
        }
        fclose(sfp);
        fclose(dfp);
    }
    return 0;
}

