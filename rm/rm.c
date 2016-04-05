#include <stdio.h>

int main(int argc,char** argv)
{
    for(int i=1;i<argc;i++){
        if(remove(argv[i])!=0){
            perror("remove");
        }
    }
    return 0;
}
