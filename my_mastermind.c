//
//  main.c
//  mastermind
//
//  Created by Geghard Simonian on 10/12/22.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>


int missplaced(char* winningCode, char* ch){
    int missplaced = 0;
//    printf("%s\n", ch);
//    printf("%s\n", winningCode);
    for(int k=0; ch[k] != '\0'; k++){
        for(int l=0; winningCode[l] != '\0'; l++){
            //printf("%d\n", strlen(ch));
            if(ch[k] == winningCode[l]){
                missplaced++;
            }
        }
    }
    //printf("miss function %d\n", missplaced);
    return missplaced;
}

int wellplaced(char* winningCode, char* ch){
    int wellplaced = 0;
    for(int k=0; ch[k] != '\0'; k++){
        if(ch[k]== winningCode[k]){
            wellplaced++;
        }
    }
    //printf("well function %d\n", wellplaced);
    return wellplaced;
}

int checkInput(char* ch){
    int counter = 0;
    for(int k=0; ch[k] != '\0'; k++){
        if(ch[k]>='0' && ch[k]<='8'){
            counter++;
        }
    }
    if(counter == 4){
        return 1;
    }else{
        return 0;
    }
}

int read_input(char input[]){
    int bytes = read(0, input, 5);
    input[5]='\0';
    return bytes;
}

int main(int ac, char** av) {
    char winningCode[5];
           
           if(ac>2 && av[1][0] == '-' && av[1][1]=='c'){
               for(int i=0; i<4; i++){
                   winningCode[i]=av[2][i];
               }
           }
           else{
               srand(time(NULL));
               int array[5];
               bool unique = true;
               int rand_num;
               for(int i = 0 ; i < 4 ; i++ ) {
                   do
                   {
                       rand_num = (rand() % 8);
                       for (int j = 0; j < i; j++)
                           if (array[j] == rand_num){
                               unique = false;
                           }
                   }while (!unique);
                   winningCode[i]=(rand_num+'0');
                
               }
          }
    winningCode[4]='\0';
    int round = 0;
    char ch[6];
    printf("Will you find the secret code?\nPlease enter a valid guess\n");
    while(wellplaced(winningCode, ch)<4 && round<10){
        //read_input(ch);
        if(read_input(ch)==0){
            return 0;
        }
        if(checkInput(ch)){
            printf("\nRound %d\nWell placed pieces: %d\nMisplaced pieces: %d\n",round,wellplaced(winningCode,ch),missplaced(winningCode,ch)-wellplaced(winningCode,ch));
            round++;
        }else{
            
            printf("Wrong input!\n");
        }
    }
    printf("Congratz! You did it!");
    return 0;
}