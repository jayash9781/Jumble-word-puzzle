#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include<time.h>
#include <ctype.h>
struct data
{
    int num;
    char q[50], ans[50], hint[250];
} ut;
void display(int r);
void input(int p);
void admin();
void play();
void start();
void AnswerTheQuestion(int x);
void menu();
void blink(char a[]);
int main()
{
    system("cls");
    system("COLOR F5");
    blink("\n\n\n\n\n\t\t\t\tWELCOME TO WORD PUZZLE!!\n\n");
     printf("\n\n\n\n\t\t\t\t");
      system("pause");
    system("cls");
    system("COLOR F0");
    start();
}
  void start()
  {
     system("cls");
     int ch;
    printf("\n\t\t\t1.Play\n\t\t\t2.Admin\n\t\t\t3.Exit\n\n\t\t\t");
    again:
    printf("\n\t\t\tEnter your choice:  ");
    scanf("%d", &ch);
    switch(ch)
    {
      case 1: play();
             break;
      case 2: admin();
             break;
      case 3: exit(0);
             break;
      default: printf("\n\t\t\tInvalid choice!! Choose correct option.\n");
             goto again;
    }
}
  void play()
 {
    system("cls");
    int mob_no;
    char name[50],mail[50];
    blink("\n\n\t\t\t\tREGISTER YOURSELF TO PLAY\n\n");
     printf("\t\t\t\t\n");
         fflush(stdin);
     printf("\t\t\t\tEnter your Name: ");
    scanf("%[^\n]s",&name);
    fflush(stdin);
    printf("\n\t\t\t\tEnter mobile number: ");
    scanf("%li", &mob_no);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your EmailId : ");
    fflush(stdin);
    gets(mail);
    blink("\n\t\t\t\tREGISTRATION SUCCESSFUL !!\n\n\t\t\t\tLETS PLAY !\n\n");
    system("pause");
    system("cls");
    system("COLOR F2");
    blink("\n\n\t\t\t\t.....SOME TIPS BEFORE PLAYING WORD QUIZ.....\n\n\n\n");
     blink("\t\t\t1. You will have three difficulty modes as easy, medium and hard.\n\n");
    blink("\t\t\t2. You will be displayed 5 questions each carrying 5 points.\n\n");
    blink("\t\t\t3. You will have only one attempt to answer each question.\n\n");
     blink("\t\t\t4. Maximum two hints can be used in each game.\n\n");
     printf("\t==========================================================================================\n\n");
     fflush(stdin);
    printf("\n\n\n\t\t\t");
    system("pause");
    menu();
}

void menu()
{
    int choice;
    while (1)
    {
        system("cls");
        system("COLOR F0");
        printf("\t\t\t1. Easy\n\t\t\t2. Medium\n\t\t\t3. Hard\n\t\t\t4. Exit\n\t\t\t");
        again1:
        printf("\n\t\tChoose the Difficulty level : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            AnswerTheQuestion(0);
            break;
        case 2:
            AnswerTheQuestion(1);
            break;
        case 3:
            AnswerTheQuestion(2);
            break;
        case 4:
            exit(0);
            break;
        default: printf("\n\t\t\tInvalid choice!! Choose correct option.\n");
             goto again1;
        }
    }
}
void admin()
{
    int choice;
    char user[15], pass[15];
    system("cls");
    printf("\n\n\n\n\n\n\t\tEnter Username : ");
    fflush(stdin);
    gets(user);
    printf("\n\t\tEnter Password : ");
    fflush(stdin);
    gets(pass);

    if (strcmp(user, "Username") == 0 && strcmp(pass, "Password") == 0)
    {
       system("COLOR F2");
        printf("\n\n\n\t\t\tLogin Successfull\n\n\n");
        system("pause");
        while (1)
        {
            system("cls");
            printf("\t\t\t1. Input Easy\n\t\t\t2. Input Medium\n\t\t\t3. Input Hard\n\t\t\t");
            printf("4. Display Easy\n\t\t\t5. Display Medium\n\t\t\t6. Display Hard\n\t\t\t7. Logout\n\t\t\t8. Exit\n");
            again2:
            printf("\n\t\tEnter Your Choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                input(0);
                break;
            case 2:
                input(1);
                break;
            case 3:
                input(2);
                break;
            case 4:
                display(0);
                break;
            case 5:
                display(1);
                break;
            case 6:
                display(2);
                break;
            case 7:
                start();
                break;
            case 8:
                exit(0);
                break;
            default: printf("\n\t\t\tInvalid choice!! Choose correct option.\n");
             goto again2;

            }
        }
    }
    else
    {
        system("COLOR F4");
        printf("\n\n\n\t\t\tCheck Your Username And Password and try again\n\n\n");
        system("pause");
        start();
    }
}
void input(int p)
{
    system("cls");
    if (p == 0)
    {
        int i = 0;
        FILE *fp;
        fp = fopen("EasyQ&Ans.txt", "a");
        while (i != 10)
        {
            ut.num = i + 1;

            printf("Enter The Shuffled Word : ");
            fflush(stdin);
            gets(ut.q);

            printf("Enter Answer : ");
            fflush(stdin);
            gets(ut.ans);

            printf("Enter Hint : ");
            fflush(stdin);
            gets(ut.hint);

            fwrite(&ut, sizeof(struct data), 1, fp);
            i++;
        }
        fclose(fp);
        system("pause");
    }
    if (p == 1)
    {
        int i = 30;
        FILE *fp;
        fp = fopen("MediumQue&Ans.txt", "a");
        while (i != 50)
        {
            ut.num = i + 1;

            printf("Enter The Shuffled Word : ");
            fflush(stdin);
            gets(ut.q);

            printf("Enter Answer : ");
            fflush(stdin);
            gets(ut.ans);

            printf("Enter Hint : ");
            fflush(stdin);
            gets(ut.hint);

            fwrite(&ut, sizeof(struct data), 1, fp);
            i++;
        }
        fclose(fp);
        system("pause");
    }
    if (p == 2)
    {
        int i = 20;
        FILE *fp;
        fp = fopen("HardQue&Ans.txt", "a");
        while (i != 30)
        {
            ut.num = i + 1;

            printf("Enter The Shuffled Word : ");
            fflush(stdin);
            gets(ut.q);

            printf("Enter Answer : ");
            fflush(stdin);
            gets(ut.ans);

            printf("Enter Hint : ");
            fflush(stdin);
            gets(ut.hint);

            fwrite(&ut, sizeof(struct data), 1, fp);
            i++;
        }
        fclose(fp);
        system("pause");
    }
}

void display(int r)
{
    system("cls");
    if (r == 0)
    {
        FILE *fp;
        fp = fopen("EasyQ&Ans.txt", "r");

        while (fread(&ut, sizeof(struct data), 1, fp) == 1)
        {
            if (ut.num >= 0 && ut.num <= 10)
            {
                printf("Que : %s\n", ut.q);
                printf("Ans : %s\n\n", ut.ans);
                printf("Hint : %s\n", ut.hint);
            }
        }
        fclose(fp);
        system("pause");
    }
    if (r == 1)
    {
        FILE *fp;
        fp = fopen("MediumQue&Ans.txt", "r");

        while (fread(&ut, sizeof(struct data), 1, fp) == 1)
        {
            if (ut.num >= 0 && ut.num <= 20)
            {
                printf("Que : %s\n", ut.q);
                printf("Ans : %s\n\n", ut.ans);
                printf("Hint : %s\n", ut.hint);
            }
        }
        fclose(fp);
        system("pause");
    }
    if (r == 2)
    {
        FILE *fp;
        fp = fopen("HardQue&Ans.txt", "r");

        while (fread(&ut, sizeof(struct data), 1, fp) == 1)
        {
            if (ut.num >= 0 && ut.num <= 20)
            {
                printf("Que : %s\n", ut.q);
                printf("Ans : %s\n\n", ut.ans);
                printf("Hint : %s\n", ut.hint);
            }
        }
        fclose(fp);
        system("pause");
    }
}

void AnswerTheQuestion(int x)
{
    system("cls");
   char  answer[50];
   float b[8];
   clock_t begin,end;
    int hint = 0,score=0;
    if (x == 0) // For Easy Questions
    {

        int e= 0, estart, eend, ect,g;
        FILE *fptr, *fp1;
        fp1 = fopen("eCount.dat", "r");
        if (fp1 == NULL)
        {
            fclose(fp1);
            fp1 = fopen("eCount.dat", "w");
            putw(1, fp1);
            putw(5, fp1);
            fclose(fp1);
            fp1=fopen("eCount.dat", "r");
        }
        fp1 = fopen("eCount.dat", "r");
        while (!feof(fp1))
        {
            ect = getw(fp1);
            if (e == 0)
                estart = ect;
            else if (e== 1)
                eend = ect;
            e++;
        }
        fclose(fp1);
        if (estart > 10 || eend > 10)
        {
            estart = 1;
            eend = 5;
        }
        e = 0;
        FILE *fp;
        fp = fopen("EasyQ&Ans.txt", "r");
        while (fread(&ut, sizeof(struct data), 1, fp) == 1)
        {

            if (ut.num >=estart && ut.num<= eend)
            {
                e++;
                 system("COLOR F0");
                printf("\n\t\t\tQue : %s\n", ut.q);
                printf("\t\t\tEnter Your Answer: ");
                printf("\t\t\tFor Hint Press 1 \n\t\t\t");
                fflush(stdin);

                up:
                    printf("\t\t\t");
                    begin=clock();
                    gets(answer);

                for (g =0; g < strlen(answer); g++)

                    answer[g] = toupper(answer[g]);
                    if (answer[0] == '1')
                    {
                        if (hint == 2)
                            printf("\t\t\tHint Already Used!!!!!\n\n");
                        else
                        {
                            printf("\t\t\t%s\n\n", ut.hint);
                            hint++;
                        }
                        goto up;
                    }
                    else if (strcmp(answer, ut.ans) == 0){
                            system("COLOR F2");
                        printf("\n\t\t\tCorrect Answer!!\n\n");
                        score=score+5;
                    }
                    else {
                        system("COLOR F4");
                        printf("\t\t\tWrong Answer!!\n\n");
                        printf("\t\t\tThe correct answer is %s\n",ut.ans);
                    }
                    end=clock();
                b[ut.num]=(float)(end-begin);
                 printf("\n\t\t\tTime taken to answer is %0.2f seconds\n\n",b[ut.num]/CLOCKS_PER_SEC);
                 system("pause");
                  system("cls");



            if (e == 5)
              {
                fp1 = fopen("eCount.dat", "w");
                putw(eend + 1, fp1);
                putw(eend + 5, fp1);
                fclose(fp1);
                system("COLOR F5");
                printf("\n\n\t\t\tYou have scored %d points.", score);
                printf("\n\n\t\t\tThank You!!!!\n\n");
              }

         }
        }
        fclose(fp);
        system("pause");
    }

        if (x == 1) // For Medium level Questions
        {

            int m = 0, mstart, mend, mct,g;
            FILE *fptr, *fp1;
            fp1 = fopen("mCount.dat", "r");
            if (fp1 == NULL)
            {
                fclose(fp1);
                fp1 = fopen("mCount.dat", "w");
                putw(1, fp1);
                putw(5, fp1);
                fclose(fp1);
            }
            fp1=fopen("mCount.dat","r");
                while (!feof(fp1))
                {
                    mct = getw(fp1);
                    if (m == 0)
                        mstart = mct;
                    else if (m == 1)
                        mend = mct;
                    m++;
                }
                fclose(fp1);
                if (mstart > 20 || mend > 20)
                {
                    mstart = 1;
                    mend = 5;
                }
                m = 0;

                FILE *fp;
                fp = fopen("MediumQue&Ans.txt", "r");
                while (fread(&ut, sizeof(struct data), 1, fp) == 1)
                {
                    if (ut.num >= mstart && ut.num <= mend)
                    {
                         m++;
                         system("COLOR F0");
                        printf("\n\t\t\tQue : %s\n", ut.q);
                        printf("\t\t\tEnter Your Answer: ");
                         printf("\t\t\tFor Hint Press 1 \n\t\t\t");
                        fflush(stdin);
                        up1:
                         printf("\t\t\t");
                         begin=clock();
                        gets(answer);
                        for (g =0; g < strlen(answer); g++)

                    answer[g] = toupper(answer[g]);
                     if (answer[0] == '1')
                    {
                        if (hint == 2)
                            printf("\t\t\tHint Already Used!!!!!\n\n");
                        else
                        {
                            printf("\t\t\t%s\n\n", ut.hint);
                            hint++;
                        }
                        goto up1;
                    }

                        else if (strcmp(answer, ut.ans) == 0)
                        {
                            system("COLOR F2");
                            printf("\t\t\tCorrect Answer!!\n\n");
                            score=score+5;
                        }
                        else
                        {
                           system("COLOR F4");
                            printf("\t\t\tWrong Answer!!\n\n");
                            printf("\t\t\tThe correct answer is %s\n",ut.ans);
                        }
                        end=clock();
                b[ut.num]=(float)(end-begin);
                 printf("\n\t\t\tTime taken to answer is %0.2f seconds\n\n",b[ut.num]/CLOCKS_PER_SEC);
                 system("pause");
                  system("cls");

                        if (m == 5)
                        {
                            fp1 = fopen("mCount.dat", "w");
                            putw(mend + 1, fp1);
                            putw(mend + 5, fp1);
                            fclose(fp1);
                            system("COLOR F5");
                             printf("\n\n\t\t\tYou have scored %d points.", score);
                            printf("\n\n\t\t\tThank You!!!!\n\n");
                        }
                    }
                }
                fclose(fp);
                system("pause");
            }
            if (x == 2) // For Hard Level Questions
            {

                int h = 0, hstart, hend, hct,g;
                FILE *fptr, *fp1;
                fp1 = fopen("hCount.dat", "r");
                if (fp1 == NULL)
                {
                    fclose(fp1);
                    fp1 = fopen("hCount.dat", "w");
                    putw(1, fp1);
                    putw(5, fp1);
                    fclose(fp1);
                }
                fp1 = fopen("hCount.dat", "r");
                    while (!feof(fp1))
                    {
                        hct = getw(fp1);
                        if (h == 0)
                            hstart = hct;
                        else if (h == 1)
                            hend = hct;
                        h++;
                    }
                    fclose(fp1);
                    if (hstart > 20 || hend > 20)
                    {
                        hstart = 1;
                        hend = 5;
                    }
                    h = 0;

                    FILE *fp;
                    fp = fopen("HardQue&Ans.txt", "r");
                    while (fread(&ut, sizeof(struct data), 1, fp) == 1)
                    {
                        if (ut.num >= hstart && ut.num <= hend)
                        {
                            h++;
                            system("COLOR F0");
                            printf("\n\t\t\tQue : %s\n", ut.q);
                            printf("\t\t\tEnter Your Answer:");
                             printf("\t\t\tFor Hint Press 1 \n\t\t\t");
                            fflush(stdin);
                            up2:
                            printf("\t\t\t");
                             begin=clock();
                            gets(answer);

                            for (g =0; g < strlen(answer); g++)

                    answer[g] = toupper(answer[g]);
                     if (answer[0] == '1')
                    {
                        if (hint == 2)
                            printf("\t\t\tHint Already Used!!!!!\n\n");
                        else
                        {
                            printf("\t\t\t%s\n\n", ut.hint);
                            hint++;
                        }
                        goto up2;
                    }

                            else if (strcmp(answer, ut.ans) == 0)
                            {
                               system("COLOR F2");
                                printf("\t\t\tCorrect Answer!!\n\n");
                                score=score+5;
                            }
                            else
                            {
                                system("COLOR F4");
                                printf("\t\t\tWrong Answer!!\n\n");
                                printf("\t\t\tThe correct answer is %s\n",ut.ans);
                            }
                            end=clock();
                          b[ut.num]=(float)(end-begin);
                            printf("\n\t\t\tTime taken to answer is %0.2f seconds\n\n",b[ut.num]/CLOCKS_PER_SEC);
                           system("pause");
                           system("cls");

                            if (h == 5)
                            {
                                fp1 = fopen("hCount.dat", "w");
                                putw(hend + 1, fp1);
                                putw(hend + 5, fp1);
                                fclose(fp1);
                                system("COLOR F5");
                                 printf("\n\n\t\t\tYou have scored %d points.", score);
                                printf("\n\n\t\t\tThank You!!!!\n\n");
                            }
                        }
                    }
                    fclose(fp);
                    system("pause");

            }
        }
        void blink(char a[])
{
    int i;
    for (i = 0; i <= strlen(a); i++)
    {
        printf("%c", a[i]);
        Sleep(50);
    }
    printf("\n");
}


