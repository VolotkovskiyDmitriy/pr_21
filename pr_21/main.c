#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int money = 5000;
int payment = 1000;
int koef = 50;
int countOfNums = 3;
int arr[3];

void randValue(){
    int i;
    for(i = 0; i < countOfNums; i++){
        arr[i] = rand() % 8;
    }
  
}

int checkTheSame (){
    int i;

    for (i = 1; i < countOfNums; i++){
        if ((arr[i - 1] != arr[i])) return -1;
    } 

    return arr[0];
}

int winCheck(){
    int prize = -payment;
    int mark = checkTheSame();
    //1 - 4
    if (arr[0] <= 4){
        if (mark != -1) prize = (arr[0] + 1) * koef;
    }
    //5 - 7
    if (arr[0] > 4){
        if(mark == 6) return 2; else
        if(mark == 7) return 1; else
        if((mark == -1) && (arr[0] == 6)) prize = 0; else
        prize = (arr[0] + 1) * koef;

    }

    return prize;
}

void OutPut(){
    int i;
    sleep(1);
    system("clear");
    printf("\nYour prize = %d\n",winCheck());
    printf("-=|");
    for (i = 0; i < countOfNums; i++){
        printf("-%d-|", arr[i]);
    }
    printf("=- MONEY: %d $\n", money);
    
    
}

void runWhileHaveMoney(int mark){
    while ((money - payment) >= 0) {
        randValue();
        OutPut();
        if (winCheck() == 1) {
            if (mark == 1){system("play /home/user/Projects/pr_21/sound.mp3");
            system("clear");}
            printf("WIINN!!! \n\n\n");            
            exit(1);
        }
        if(winCheck() == 2){
            if (mark == 1){system("play /home/user/Projects/pr_21/loseSound.mp3");
            system("clear");}
            printf("LOSEE!!!\n\n\n");          
            exit(0);
        }
        money = money + winCheck();
          
    }
    
    if (mark == 1){
        system("play /home/user/Projects/pr_21/loseSound.mp3");
        system("clear");
    }
    printf("LOSEE!!!\n\n\n");        
    exit(0);

}


int main(){

    int i = 0;
    srand(time(NULL));
    printf("press 1 to play with sounds!");
    if(getchar() == '1'){
        system("sudo apt install sox");
    	system("sudo apt install libsox-fmt-mp3");
    	i = 1;
    }
    runWhileHaveMoney(i);
    return 0;
}
