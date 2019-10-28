#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void collatz(int sayi);

int main(){
    int sayi = 0;

    do{
        printf("Lutfen pozitif bir tamsayi giriniz: ");
        scanf("%d",&sayi);
    }while(sayi<=0);
    
    collatz(sayi);
    return 0;
}

void collatz(int sayi){

    pid_t pid = fork();

    if (pid == 0){
        printf("Child process calisiyor...\n");
        printf("%d\n", sayi);
        while (sayi != 1)
        {
            if (sayi % 2 == 0)
            {
                sayi = sayi / 2;
            }
            else if (sayi % 2 == 1)
            {
                sayi = 3 * (sayi) + 1;
            }

            printf("%d\n", sayi);
        }

        printf("Child process tamamlandi.\n");
    }
    else{
        printf("Parent process bekliyor...\n");
        wait();
        printf("Parent process tamamlandi.\n");
    }
    
}