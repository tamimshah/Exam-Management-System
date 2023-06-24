#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void addRoutine();
void viewRoutine();
void addSeatPlan();
void checkSeatPlan();
void showSeatPlan();
void updateDeleteInfo();
void addTeacherInfo();
void checkteacherInfo();
int checkRoutInfo(int a,char[20]);
int checkStdInfo(char id[20],char c[20]);
void deleteRoutine();
void deleteRoutineSpec();
void deleteRoutineBat();
void deleteSeatPlan();
void deleteTeacInfo();
void editRoutine();
void creatorsInfo();
int passwords();
int passprotect();

FILE *fr,*ft,*fs,*fd;

struct Routine{
  int batch;
  float time;
  char zone[5];
  char examName[20];
  char date[20];
}r1;

struct SeatPlan{
  char id[20];
  char examName[20];
  int roomNumber;
  int coloumn;
  int benchNo;
}s1;

struct TeacherInfo{
  int roomNumber;
  char date[15];
  int totalStud;
  float time;
  char zone[5];
  char ini1[10];
  char ini2[10];
  char id1[20];
  char id2[20];
}t1;


int main()
{
  int i;
  system("cls");
  system("COLOR A");
  printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
  printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
  printf("\n\n\t\t1.View Routine\n");
  printf("\t\t2.Teacher Info\n");
  printf("\t\t3.Check Seat Plan\n");
  printf("\t\t4.Update & Delete Info\n");
  printf("\t\t5.Creators Info\n");
  printf("\t\t6.Close Application\n");
  printf("\n\tEnter Choice: ");
  scanf("%d",&i);
  switch(i)
    {
        case 1:
        viewRoutine();
        break;
        case 2:
        checkteacherInfo();
        break;
        case 3:
        checkSeatPlan();
        break;
        case 4:
        passprotect();
        break;
        case 5:
        creatorsInfo();
        break;
        case 6:
        {
        system("cls");
        system(" Color 4");
        printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Thanks for using the Program.. \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        return 0;
        }
        default:
        {
            main();
        }
    }
}
void addRoutine(){
  system("cls");
  int b;
  char d[20];
  fr=fopen("routine.dat","ab+");
  printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Routine");
  printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
  printf("\n\n\t\t-> Batch: ");
  scanf("%d",&b);
  printf("\n\t\t-> Exam date(dd-mm-yyyy): ");
  scanf("%s",&d);
  if(checkRoutInfo(b,d)== 0)
    {
        printf("\n\t\t\t\xB2\xB2\xB2\xB1\xB1 schedule exist!!\xB1\xB1\xB2\xB2\xB2\n");
        printf("\n\t\t Press 'n' to UPDATE & DELETE INFO Else to Add routine: ");
        getchar();
        if(getchar()=='n'){
           updateDeleteInfo();
        }
        else{
            addRoutine();
       }
    }
  r1.batch = b;
  strcpy(r1.date,d);
  printf("\n\t\t-> Exam Time : ");
  scanf("%f",&r1.time);
  printf("\n\t\t-> AM/PM : ");
  scanf("%s",&r1.zone);
  printf("\n\t\t-> Course Code : ");
  scanf("%s",&r1.examName);
  fseek(fr,0,SEEK_END);
  fwrite(&r1,sizeof(r1),1,fr);
  fclose(fr);
  printf("\n\t\t\t\xB2\xB2\xB2\xB1\xB1 The record is sucessfully saved \xB1\xB1\xB2\xB2\xB2\n");
  printf("\n\t\tSave any more?(Y/N): ");
  getchar();
  if(getchar()=='n'){
        updateDeleteInfo();
        }
  else{
     addRoutine();
  }
}
int checkRoutInfo(int b,char d[20])
{
    rewind(fr);
    while(fread(&r1,sizeof(r1),1,fr)==1){
    if((b==r1.batch) && (strcmp(d,r1.date)==0)){
    return 0;
    }
  }
  return 1;
}
void viewRoutine(){
   int b;
   system("cls");
   printf("\n\t\t--> Enter Batch: ");
   scanf("%d",&b);
   system("cls");
   printf("\n \t\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2  BATCH - %d  \xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\n",b);
   printf(" \t\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 EXAM ROUTINE \xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\n");
   printf("\n\t--------------------------------------------\n");
   printf("\t COURSE CODE \t DATE \t\t TIME\n");
   printf("\t--------------------------------------------\n");
   fr=fopen("routine.dat","rb");
   while(fread(&r1,sizeof(r1),1,fr)==1){
   if((b == r1.batch)){
   printf("\t %s",r1.examName);
   printf("\t\t%s",r1.date);
   printf("\t %.2f %s",r1.time,r1.zone);
   printf("\n\n");
    }
   }
   fclose(fr);
   printf("\n\t Press 'b' to goto MAIN MENU: ");
   getchar();
   if(getchar()=='b'){
       main();
   }
}
void addSeatPlan(){
  system("cls");
  char id[20];
  char c[20];
  fs=fopen("student.dat","ab+");
  //printf("\t\Add Seat PLan\t\n");
  printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB1\xB1\xB1\xB1 Add Seat PLan");
  printf(" \xB1\xB1\xB1\xB1\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
  printf("\n\t\t-> Student ID:\t");
  scanf("%s",&id);
  printf("\t\t-> Exam Name:\t");
  scanf("%s",&c);
  if(checkStdInfo(id,c)== 0)
    {
        printf("\n\t\t\xB2\xB2\xB2\xB1\xB1 Seat plan updated already \xB1\xB1\xB2\xB2\xB2\n");
        printf("\n\t press 'n' to UPDATE & DELETE INFO Else to Add Seat Plan: ");
        getchar();
        if(getchar()=='n'){
            updateDeleteInfo();
        }
        else{
            addSeatPlan();
       }
    }
  strcpy(s1.id,id);
  strcpy(s1.examName,c);
  printf("\t\t-> Room Number:\t");
  scanf("%d",&s1.roomNumber);
  printf("\t\t-> Coloumn No:\t");
  scanf("%d",&s1.coloumn);
  printf("\t\t-> Bench No:\t");
  scanf("%d",&s1.benchNo);
  fseek(fs,0,SEEK_END);
  fwrite(&s1,sizeof(s1),1,fs);
  fclose(fs);
  printf("\n\t\tThe record is sucessfully saved\t\n");
  printf("\t\tSave any more?(Y/N): ");
  getchar();
  if(getchar()=='n'){
        updateDeleteInfo();
        }
  else{
     addSeatPlan();
  }
}

int checkStdInfo(char id[20],char c[20])
{
    rewind(fs);
    while(fread(&s1,sizeof(s1),1,fs)==1){
    if((strcmp(id,s1.id)==0) && (strcmp(c,s1.examName)==0)){
    return 0;
    }
  }
  return 1;
}

void checkSeatPlan(){
   system("cls");
   char id[20];
   char courseCode[20];
   int flag = 0;
   printf("\n\t\t\tEnter Id and Course code to Check Seat PLan\t\n");
   printf("\t\t -------------------------------------------------------\n");
   printf("\n\t-> Student ID: ");
   scanf("%s",&id);
   printf("\t-> Exam Name: ");
   scanf("%s",&courseCode);
   fs=fopen("student.dat","rb");
   rewind(fs);
   while(fread(&s1,sizeof(s1),1,fs)==1){
   if((strcmp(s1.id,(id)) == 0) && (strcmp(s1.examName,(courseCode)) == 0)){
     showSeatPlan();
     int flag=1;
    }
   }
   if(flag != 1){
     printf("\n\t\t\tInvalid Student ID or COURSE CODE!!!\n");
     printf("\n\tSearch Again?(Y/N): ");
     getchar();
     if(getchar()=='n'){
        main();
        }
    else{
        checkSeatPlan();
     }
   }
   fclose(fs);
}
void showSeatPlan(){
   system("cls");
   printf("\n\t\t\tShowing Seat PLan\t\n");
   printf("\t----------------------------------------------\n");
   printf("\t-> Course Code: %s\t",s1.examName);
   printf("\n\t-> Room Number: %d\t",s1.roomNumber);
   printf("\n\t-> Coloumn No: %d\t",s1.coloumn);
   printf("\n\t-> Bench No: %d\t\n",s1.benchNo);
   printf("\n\t\tPress 'n' to Go back to MAIN MENU: ");
   getchar();
   if(getchar()=='n'){
        main();
    }
}
void addTeacherInfo(){
   system("cls");
   ft=fopen("teacher.dat","ab+");
   printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB1\xB1\xB1\xB1 Add Teacher info");
    printf(" \xB1\xB1\xB1\xB1\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
   printf("\n\t-> Enter Room Number: ");
   scanf("%d",&t1.roomNumber);
   printf("\n\t-> Enter Date(dd-mm-yyyy): ");
   scanf("%s",&t1.date);
   printf("\n\t-> Duty time: ");
   scanf("%f",&t1.time);
   printf("\n\t-> AM/PM : ");
   scanf("%s",&t1.zone);
   printf("\n\t-> Enter total number of Student: ");
   scanf("%d",&t1.totalStud);
   printf("\n\n\t\t\xB2\xB2\xB2\xB1\xB1 Invigilator 1 \xB1\xB1\xB2\xB2\xB2\n");
   printf("\n\t-> ID:\t");
   scanf("%s",&t1.id1);
   printf("\t-> Teacher Initial: ");
   scanf("%s",&t1.ini1);
   printf("\n\n\t\t\xB2\xB2\xB2\xB1\xB1 Invigilator 2 \xB1\xB1\xB2\xB2\xB2\n");
   printf("\n\t-> ID:\t");
   scanf("%s",&t1.id2);
   printf("\t-> Teacher Initial: ");
   scanf("%s",&t1.ini2);
   fseek(ft,0,SEEK_END);
   fwrite(&t1,sizeof(t1),1,ft);
   fclose(ft);
   printf("\n\n\tThe record is sucessfully saved\n");
   printf("\tSave any more?(Y/N): ");
   getchar();
   if(getchar()=='n'){
        updateDeleteInfo();
        }
   else{
     addTeacherInfo();
   }
}

void checkteacherInfo(){
   system("cls");
   char id[20];
   char date[15];
   int flag=0;
   printf("\n\t\t\t\tEnter Id and Date to Check information\t\n");
   printf("\n\t\t-> ID: ");
   scanf("%s",&id);
   printf("\n\t\t-> Date(dd-mm-yyyy): ");
   scanf("%s",&date);
   ft=fopen("teacher.dat","rb");
   system("cls");
   while(fread(&t1,sizeof(t1),1,ft)==1){
      if(((strcmp(id,t1.id1)==0) || (strcmp(id,t1.id2)==0)) && (strcmp(date,t1.date)==0)){
        printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Showing Teacher INFO \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\t-> Date: %s\t",t1.date);
        printf("\n\t-> Room Number: %d\t",t1.roomNumber);
        printf("\n\t-> Duty Time: %.2f %s\t",t1.time,t1.zone);
        if(strcmp(id,t1.id1)==0){
        printf("\n\t-> Invigilator Partner: %s\t",t1.ini2);
        }
        else{
        printf("\n\t-> Invigilator Partner: %s\t",t1.ini1);
        }
        printf("\n\t-> Total Student: %d\t",t1.totalStud);
        printf("\n");
        flag = 1;
      }
    }
    if(flag == 1){
         printf("\n\t\tPress 'n' to Go back to MAIN MENU: ");
         getchar();
         if(getchar()=='n'){
          main();
        }
     }
    if(flag != 1){
     printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Sorry Sir, you don't have any Duty \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
     printf("\n\t\t\t\tSearch Again?(Y/N): ");
     getchar();
     if(getchar()=='n'){
        main();
        }
    else{
        checkteacherInfo();
     }
   }
   fclose(ft);
}
void updateDeleteInfo(){


  int i;
  system("cls");
  printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UPDATE & DELETE INFO \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
  printf("\n\t\t\t1.Add Routine\n");
  printf("\t\t\t2.Delete Routine\n");
  printf("\t\t\t3.Edit Routine\n");
  printf("\t\t\t4.Add Teacher Info\n");
  printf("\t\t\t5.Delete Teacher Info\n");
  printf("\t\t\t6.Add Seat Plan\n");
  printf("\t\t\t7.Delete Seat Plan\n");
  printf("\t\t\t8.Back to MAIN MENU\n");
  printf("\n\t\t Enter Choice: ");
  scanf("%d",&i);
  switch(i)
    {
        case 1:
        addRoutine();
        break;
        case 2:
        deleteRoutine();
        break;
        case 3:
        editRoutine();
        break;
        case 4:
        addTeacherInfo();
        break;
        case 5:
        deleteTeacInfo();
        break;
        case 6:
        addSeatPlan();
        break;
        case 7:
        deleteSeatPlan();
        break;
        case 8:
        main();
        break;
        default:
        updateDeleteInfo();

     }
}

void deleteRoutine()
{
    int i;
    system("cls");
    printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB1\xB1\xB1\xB1 DELETE STUDENT INFO");
    printf(" \xB1\xB1\xB1\xB1\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Delete Whole Batch Routine\n");
    printf("\t\t2.Delete Specific Routine\n");
    printf("\t\t3.Back To MAIN MENU\n");
    printf("\tEnter Choice: ");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
        deleteRoutineBat();
        break;
        case 2:
        deleteRoutineSpec();
        break;
        case 3:
        main();
        break;
        default:
        updateDeleteInfo();
    }

}

void deleteRoutineBat(){
        int d;
        int flag = 0;
        system("cls");
        printf("\n\t\t-> Enter the Batch: ");
        scanf("%d",&d);
        fr=fopen("routine.dat","rb+");
        rewind(fr);
        printf("\n\t---------------- BATCH- %d -----------------\n",d);
        printf("\t\t\tEXAM ROUTINE\t\n");
        printf("\t--------------------------------------------\n");
        printf("\t COURSE CODE \t DATE \t\t TIME\n");
        printf("\t--------------------------------------------\n");
        while(fread(&r1,sizeof(r1),1,fr)==1)
       {
            if(r1.batch == d)
           {
                printf("\t %s",r1.examName);
                printf("\t\t%s",r1.date);
                printf("\t %.2f %s",r1.time,r1.zone);
                printf("\n\n");
                flag = 1;
           }
        }
    if(flag != 1)
        {
          printf("\n\tNo schedule is found modify the search");
          printf("\n\tpress 'y' to goto UPDATE DELETE INFO: ");
          getchar();
          if(getchar()=='y'){
           updateDeleteInfo();
          }
        }
    if(flag == 1)
    {
           printf("\n\tDo you want to delete it?(Y/N): ");
           getchar();
           if(getchar() =='y')
           {
             fd=fopen("test.dat","wb+");
             rewind(fr);
             while(fread(&r1,sizeof(r1),1,fr)==1)
             {
                   if(r1.batch != d)
                  {
                    fseek(fd,0,SEEK_CUR);
                    fwrite(&r1,sizeof(r1),1,fd);
                  }
             }
             fclose(fd);
             fclose(fr);
             remove("routine.dat");
             rename("test.dat","routine.dat");
             fr=fopen("routine.dat","rb+");
             printf("\n\n\tThe record is sucessfully deleted");
             printf("\n\tDelete another record?(Y/N): ");
             getchar();
             if(getchar()=='n'){
             updateDeleteInfo();
              }
             else{
             deleteRoutine();
              }
           }
           else{
            updateDeleteInfo();
          }
     }
}

void deleteRoutineSpec(){
        int d;
        char c[20];
        int flag = 0;
        system("cls");
        printf("\n\t ->Enter the Batch: ");
        scanf("%d",&d);
        printf("\n\t ->Enter the Course Code: ");
        scanf("%s",&c);
        fr=fopen("routine.dat","rb+");
        rewind(fr);
        while(fread(&r1,sizeof(r1),1,fr)==1)
        {
              if((r1.batch == d) && (strcmp(c,r1.examName) == 0))
               {
                 printf("\n\tSchedule for %s is available", r1.examName);
                 printf("\n\tDate is %s",r1.date);
                 printf("\n\tTime is %.2f %s",r1.time,r1.zone);
                 flag = 1;
               }
         }
        if(flag != 1)
        {
           printf("\n\tNo schedule is found modify the search");
           printf("\n\tpress 'y' to goto UPDATE AND DELETE INFO: ");
           getchar();
           if(getchar()=='y'){
              updateDeleteInfo();
           }
        }
        if(flag == 1)
        {
           printf("\n\n\t\tDo you want to delete it?(Y/N): ");
           getchar();
           if(getchar() =='y')
           {
             fd=fopen("test.dat","wb+");
             rewind(fr);
              while(fread(&r1,sizeof(r1),1,fr)==1)
             {
                if((r1.batch != d) || (strcmp(c,r1.examName) != 0))
                {
                  fseek(fd,0,SEEK_CUR);
                  fwrite(&r1,sizeof(r1),1,fd);
                }
             }
               fclose(fd);
               fclose(fr);
               remove("routine.dat");
               rename("test.dat","routine.dat");
               fr=fopen("routine.dat","rb+");
               printf("\n\n\tThe record is sucessfully deleted");
               printf("\n\tDelete another record?(Y/N): ");
               getchar();
            if(getchar()=='n'){
               updateDeleteInfo();
              }
            else{
              deleteRoutine();
             }
          }
          else{
           updateDeleteInfo();
        }
     }
}

void deleteSeatPlan(){
        char id[20];
        char c[20];
        int flag = 0;
        system("cls");
        system("color 6");
        printf("\n\t-> Enter ID: ");
        scanf("%s",&id);
        printf("\t-> Enter the Course Code: ");
        scanf("%s",&c);
        fs=fopen("student.dat","rb+");
        rewind(fs);
        while(fread(&s1,sizeof(s1),1,fs)==1)
        {
              if((strcmp(id,s1.id) == 0) && (strcmp(c,s1.examName) == 0))
               {
                 printf("\n\tSeat Plan for ID : %s is available", s1.id);
                 printf("\n\tCourse Code is %s",s1.examName);
                 printf("\n\tRoom No is %d",s1.roomNumber);
                 printf("\n\tColoumn No is %d",s1.coloumn);
                 printf("\n\tBench No is %d",s1.benchNo);
                 flag = 1;
               }
         }
        if(flag != 1)
        {
           printf("\n\t\tNo Seat Plan is found modify the search");
           printf("\n\t\tpress 'y' to goto UPDATE AND DELETE INFO: ");
           getchar();
           if(getchar()=='y'){
              updateDeleteInfo();
           }
        }
        if(flag == 1)
        {
           printf("\n\n\t\tDo you want to delete it?(Y/N): ");
           getchar();
           if(getchar() =='y')
           {
             fd=fopen("test.dat","wb+");
             rewind(fs);
              while(fread(&s1,sizeof(s1),1,fs)==1)
             {
                if((strcmp(id,s1.id) != 0) || (strcmp(c,s1.examName) != 0))
                {
                  fseek(fd,0,SEEK_CUR);
                  fwrite(&s1,sizeof(s1),1,fd);
                }
              }
               fclose(fd);
               fclose(fs);
               remove("student.dat");
               rename("test.dat","student.dat");
               fs=fopen("student.dat","rb+");
               printf("\n\tThe record is sucessfully deleted");
               printf("\n\tDelete another record?(Y/N): ");
               getchar();
               if(getchar()=='n'){
                   updateDeleteInfo();
                }
               else{
                   deleteSeatPlan();
                }
          }
          else{
           updateDeleteInfo();
        }
     }
}

void deleteTeacInfo(){
        int room;
        char date[15];
        float time;
        int flag = 0;
        system("cls");
        printf("\n\t ->Room No: ");
        scanf("%d",&room);
        printf("\t ->Enter Date: ");
        scanf("%s",&date);
        printf("\t ->Time: ");
        scanf("%f",&time);
        ft=fopen("teacher.dat","rb+");
        rewind(ft);
        while(fread(&t1,sizeof(t1),1,ft)==1)
        {
              if((room == t1.roomNumber) && (time == t1.time) && (strcmp(date,t1.date)==0)){
                     system("cls");
                     printf("\n\t\t\xB2\xB2\xB2\xB1\xB1 Schedule is Availabe \xB1\xB1\xB2\xB2\xB2\n");
                     printf("\n\t-> Date: %s\t",t1.date);
                     printf("\n\t-> Room Number: %d\t",t1.roomNumber);
                     printf("\n\t-> Duty Time: %.2f %s\t",t1.time,t1.zone);
                     printf("\n\t-> Invigilator 1: %s\t",t1.ini1);
                     printf("\n\t-> Invigilator 2: %s\t",t1.ini2);
                     printf("\n\t-> Total Student: %d\t",t1.totalStud);
                     flag = 1;
               }
         }
        if(flag != 1)
        {
           printf("\n\tNo Schedule is found modify the search");
           printf("\n\tpress 'y' to goto UPDATE AND DELETE INFO: ");
           getchar();
           if(getchar()=='y'){
              updateDeleteInfo();
           }
        }
        if(flag == 1)
        {
           printf("\n\n\t\tDo you want to delete it?(Y/N): ");
           getchar();
           if(getchar() =='y')
           {
             fd=fopen("test.dat","wb+");
             rewind(ft);
              while(fread(&t1,sizeof(t1),1,ft)==1)
             {
                if((room != t1.roomNumber) || (time != t1.time) || (strcmp(date,t1.date)!=0))
                {
                  fseek(fd,0,SEEK_CUR);
                  fwrite(&t1,sizeof(t1),1,fd);
                }
              }
               fclose(fd);
               fclose(ft);
               remove("teacher.dat");
               rename("test.dat","teacher.dat");
               ft=fopen("teacher.dat","rb+");
               printf("\n\tThe record is sucessfully deleted");
               printf("\n\tDelete another record?(Y/N): ");
               getchar();
               if(getchar()=='n'){
                   updateDeleteInfo();
                }
               else{
                   deleteTeacInfo();
                }
          }
          else{
           updateDeleteInfo();
        }
     }
}

void editRoutine(){
        system("color 6");
        int d;
        char c[20];
        int flag = 0;
        system("cls");
        printf("\n\t ->Enter the Batch: ");
        scanf("%d",&d);
        printf("\n\t ->Enter Exam date: ");
        scanf("%s",&c);
        fr=fopen("routine.dat","rb+");
        system("cls");
        while(fread(&r1,sizeof(r1),1,fr)==1)
        {
              if((r1.batch == d) && (strcmp(c,r1.date) == 0))
               {
                 printf("\n\t\tSchedule is Available for Batch %d and Course Code %s is available\n", d, r1.examName);
                 printf("\n\t\t\tEnter New Date: ");scanf("%s",&r1.date);
                 printf("\n\t\t\tEnter New Course Code: ");scanf("%s",&r1.examName);
                 printf("\n\t\t\tEnter New Time: ");scanf("%f",&r1.time);
                 printf("\n\t\t\tEnter New AM/PM: ");scanf("%s",&r1.zone);
                 fseek(fr,ftell(fr)-sizeof(r1),0);
                 fwrite(&r1,sizeof(r1),1,fr);
                 fclose(fr);
                 flag = 1;
                 printf("\n\n\tThe record is sucessfully Modified");
                 printf("\n\tModify another record?(Y/N): ");
                 getchar();
                 if(getchar()=='n'){
                  updateDeleteInfo();
                 }
                 else{
                  editRoutine();
                 }
               }
         }
        if(flag != 1)
        {
           printf("\n\n\tNo schedule is found modify the search");
           printf("\n\tpress 'y' to goto UPDATE AND DELETE INFO: ");
           getchar();
           if(getchar()=='y'){
              updateDeleteInfo();
           }
        }

}

void creatorsInfo(){
   system("cls");
   system("Color 5f");
   printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB1\xB1\xB1 This Project Develop By \xB1\xB1\xB1\xB2\xB2\xB2\xB2\xB2\xB2\n");
   printf("\t\t\t---------------------------------------------------------");
   printf("\n\n\tZahir Hossain Dipto\n");
   printf("\tID: *********\n");
   printf("\tStudent\n");
   printf("\tDepartment of Software Engineering\n");
   printf("\tDaffodil International University\n");

   printf("\n\n\n\n");

   printf("\tMd. Tahmid Shah Tamim\n");
   printf("\tID: ********\n");
   printf("\tStudent\n");
   printf("\tDepartment of Software Engineering\n");
   printf("\tDaffodil International University\n");

   printf("\n\n\n\t\t\t\tThanks for using our system\n");
   printf("\n\t\t\t\tGoto MAIN MENU?(Y/N): ");
   getchar();
   if(getchar()=='y'){
    main();
    }
   else{
    creatorsInfo();
    }

}

int passprotect(){
 passwords();

}


int passwords() {
    system("cls");
    system("color B");
    char password[10] = "exam";
    char input[10];
    int i=0;

    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\xB2\xB2\xB2\xB2\t\t LOGIN INTERFACE\t    \xB2\xB2\xB2\xB2");
    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\tEnter Password: ");

    while(1) {
        char ch = getch();
        if(ch == 13) {
            input[i] = '\0';
            break;
        }
        else {
            input[i] = ch;
            i++;
            printf("*");
        }
    }

    if(strcmp(input, password) == 0) {
        printf("\n\n\t\t\tAccess Granted!\n");
        printf("\t\t Press any key to countinue.....");
	    getch();
        updateDeleteInfo();
    }
    else {
        printf("\n\n\t\t\tWrong Password!!!\n");
        printf("\t\tPress any key to countinue.....");
	    getch();
        //passwords();
        passprotect();
    }


    return 0;
}
