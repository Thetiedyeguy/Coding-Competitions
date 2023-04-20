#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[]){
    FILE* fp = fopen(argv[1], "r");
    int numIncreased, current, previous, letter;
    char c;
    char string[30];
    letter = 0;
    previous = 100000;
    while(!feof(fp)){
        c = fgetc(fp);
        if(c == '\n'){
            current = atoi(string);
            if(current > previous){
                numIncreased++;
            }
            letter = 0;
            previous = current;
            for(int i = 0; i < 30; i++){
                string[i] = ' ';
            }
        }else{
            string[letter] = c;
            letter++;
        }
    }
    printf("%d\n", numIncreased);
}
