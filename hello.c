
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*long factorial(int n){
    return n==1?1:n*factorial(n-1);
}*/
char* join(char *s1,char *s2){
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    if(result == NULL) exit(1);
    strcpy(result,s1);
    strcat(result,s2);
    return result;
}

int main()
{
    /*FILE *fp=NULL;
    int ch;
    fp=fopen("show.txt","r+");
    if(fp==NULL){
        return 0;
    }
    ch=getc(fp);
    while(ch!=EOF){
        putchar(ch);
        ch=getc(fp);
    }

    char str[] ="liyang";
    for(int i=0;i<strlen(str);i++){
        putc(str[i],fp);
    }
    fclose(fp);*/

    //char *separate="\\";
   /* char *hel="hello";
    printf("%s",join("\\",hel));*/
    FILE *fp;
    char str[22];
    if((fp=fopen("History.xml","r"))==NULL){
        printf("open file failed！\n");exit(1);
    }
    char *ret=fgets(str,22,fp);
    printf("%d\n",ret==str);
    while(ret){
        printf("%s",ret);
        ret=fgets(str,22,fp);
    }
    fclose(fp);
    return 0;
}





