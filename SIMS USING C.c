#include<stdio.h>
#include<string.h>

int i=1;
//structure declaration//

struct studentdetails{
char name[70];
int rno;
float attendance;
int marks;
int tmarks;
int cgpa;
};

int deletestudent();
int updatestudent();
int byname();
int byroll();
int calcgpa();
int display();
int updatebyname();

//main function//

void main(){
  printf("---------------------------------------------------------------------------------------\n");
  printf("-----------------------!!HELLO AND WELCOME TO STUDENT DATABSE!!------------------------\n");
  printf("----------------------------------------------------------------------------------------");
  printf("\n");
  int n;
  printf("ENTER TOTAL STUDENTS :  ");
  scanf("%d",&n);
  printf("----------------------------------------------------------------------------------------\n");
  struct studentdetails ar[100];
  strcpy(ar[0].name,"ANANYA");
  ar[0].rno=1;
  ar[0].attendance=90.5;
  ar[0].marks=355;
  ar[0].tmarks=600;
  strcpy(ar[1].name,"ANA");
  ar[1].rno=2;
  ar[1].attendance=98.5;
  ar[1].marks=305;
  ar[1].tmarks=600;
  strcpy(ar[2].name,"NYA");
  ar[2].rno=3;
  ar[2].attendance=50.5;
  ar[2].marks=255;
  ar[2].tmarks=600;
  int n1;
  printf("NUMBER OF STUDENTS YOU WANT TO ADD : ");
  scanf("%d",&n1);
  printf("------------------------------------------------------------------------------\n");


  while(i==1){
    int op;
    printf("1:ADD STUDENT DETAILS\n2:DELETE STUDENT DETAILS\n");
    printf("3:UPDATE DETAILS BY ROLL NO\n4:UPDATE DETAILS BY NAME\n");
    printf("5:FIND A STUDENT BY NAME\n");
    printf("6:FIND A STUDENT BY ROLL NUMBER \n7:CALCULATE CGPA OF ALL STUDENTS\n");
    printf("8:DISPLAY ALL RECORDS\n");
    printf("9:EXIT\n");
    printf("----------------------------------------------------------------------------\n");
    printf("WHICH OPERATION DO YOU WANNA PERFORM : ");
    scanf("%d",&op);
    printf("--------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    switch(op){

        case 1:
        //addstudentdetails//
          for (int i=3;i<n1+3;i++){
            printf("NAME : \n");
            scanf("%s",ar[i].name);
            printf("ROLL NUMBER : \n");
            scanf("%d",&ar[i].rno);
            printf("ATTENDANCE : \n");
            scanf("%f",&ar[i].attendance);
            printf("MARKS : \n");
            scanf("%d",&ar[i].marks);
            printf("TOTAL MARKS : \n");
            scanf("%d",&ar[i].tmarks);
          }
          display(n,ar);
        break;

        case 2:
        deletestudent(n,ar);
        break;
        case 3:
        updatestudent(n,ar);
        break;
        case 4:
        updatebyname(n,ar);
        break;
        case 5:
        byname(n,ar);
        break;
        case 6:
        byroll(n,ar);
        break;
        case 7:
        calcgpa(n,ar);
        break;
        case 8:
        display(n,ar);
        break;
        case 9:
        exit(0);
      }
    }

  }

//display data//

 int display(int n, struct studentdetails arrays[n]){
   printf("--------------------------------------------------------------------------\n");
   printf("--------------------------STUDENT DETAILS ARE------------------------------\n");
   printf("---------------------------------------------------------------------------\n");
   printf("NAME\tROLLNO\tATTENDANCE\tMARKS\tTOTALMARKS\n");
   printf("----------------------------------------------------------------------------\n");
   for(int i=0;i<n;i++){
      printf("%s\t",arrays[i].name);
      printf("%d\t\t",arrays[i].rno);
      printf("%f\t",arrays[i].attendance);
      printf("%d\t\t",arrays[i].marks);
      printf("%d\t",arrays[i].tmarks);
      printf("\n");
      printf("----------------------------------------------------------------\n");
    }
   return 0;
 }

//FINDING STUDENT BY NAME//

int byname(int n,struct studentdetails ar[n]){
  printf("______________________________________________________________________\n");
  char find[70];
  printf("ENTER THE NAME OF THE STUDENT YOU WANT TO FIND : ");
  scanf("%s",find);
  printf("_______________________________________________________________________\n");
  for(int i=0;i<n;i++){
    if(strcmp(ar[i].name,find)==0){
      printf("----------------------STUDENT DETAILS ARE----------------------------\n");
      printf("-----------------------------------------------------------------------\n");
      printf("NAME\tROLLNO\tATTENDANCE\tMARKS\tTOTALMARKS\n");
      printf("---------------------------------------------------------------------\n");
      printf("%s\t\t",ar[i].name);
      printf("%d\t\t",ar[i].rno);
      printf("%f\t",ar[i].attendance);
      printf("%d\t\t",ar[i].marks);
      printf("%d\n",ar[i].tmarks);
      printf("---------------------------------------------------------------------\n");
    }
  }

}

//finding student by roll number//


int byroll(int n,struct studentdetails ar[n]){
  int find;
  printf("ENTER ROLL NUMBER YOU WANT TO FIND : \n");
  scanf("%d",&find);
  for(int i=0;i<n;i++){
    if(ar[i].rno==find){
      printf("----------------------STUDENT DETAILS ARE----------------------------\n");
      printf("NAME\tROLLNO\tATTENDANCE\tMARKS\tTOTALMARKS\n");
      printf("----------------------------------------------------------------------\n");
      printf("%s\t\t",ar[i].name);
      printf("%d\t\t",ar[i].rno);
      printf("%f\t",ar[i].attendance);
      printf("%d\t\t",ar[i].marks);
      printf("%d\n",ar[i].tmarks);
      printf("---------------------------------------------------------------------\n");
    }
  }
}

//calculating CGPA//

int calcgpa(int n,struct studentdetails ar[n]){
  printf("--------------------STUDENT DETAILS ARE----------------------------\n");
  printf("NAME\tROLLNO\tATTENDANCE\tMARKS\tTOTALMARKS\tCGPA\n");
  printf("-------------------------------------------------------------------\n");

  for(int i=0;i<n;i++){
      ar[i].cgpa=((ar[i].marks)/60);
      printf("%s\t\t",ar[i].name);
      printf("%d\t",ar[i].rno);
      printf("%f\t",ar[i].attendance);
      printf("%d\t\t",ar[i].marks);
      printf("%d\t\t",ar[i].tmarks);
      printf("%d\n",ar[i].cgpa);
      printf("\n");
      printf("----------------------------------------------------------------\n");
  }
}

//UPDATE BY ROLL NUMBER//

int updatestudent(int n,struct studentdetails ar[n]){
  int find;
  printf("ENTER ROLL NO OF STUDENT WHOSE DETAILS YOU WANT TO UPDATE : \n");
  scanf("%d",&find);
  for(int j=0;j<n;j++){
    if(ar[j].rno==find){
        printf("WHAT DO YOU WANT TO CHANGE : \n");
        int k;
        printf("1:NAME\n2:ROLLNO\n3:ATTENDANCE\n4:MARKS\n5:DONE\n");
        scanf("%d",&k);
        switch(k){
          case 1:
          printf("ENTER NEW NAME : \n");
          scanf("%s",ar[j].name);
          break;
          case 2:
          printf("ENTER NEW ROLL NUMBER : \n");
          scanf("%d",&ar[j].rno);
          break;
          case 3:
          printf("ENTER ATTENDANCE : \n");
          scanf("%f",&ar[j].attendance);
          break;
          case 4:
          printf("ENTER NEW MARKS : \n");
          scanf("%d",&ar[j].marks);
          break;
      }
      display(n,ar);
    }
  }
}

//UPDATE BY NAME//

int updatebyname(int n,struct studentdetails ar[n]){
  char find[70];
  printf("ENTER NAME OF STUDENT WHOSE DETAILS YOU WANT TO UPDATE : \n");
  scanf("%s",find);
  for(int i=0;i<n;i++){
    if(strcmp(ar[i].name,find)==0){
      printf("WHAT DO YOU WANT TO CHANGE : \n");
      int k;
      printf("1:NAME\n2:ROLLNO\n3:ATTENDANCE\n4:MARKS\n5:DONE\n");
      scanf("%d",&k);
      switch(k){
        case 1:
        printf("ENTER NEW NAME : \n");
        scanf("%s",ar[i].name);
        break;
        case 2:
        printf("ENTER NEW ROLL NUMBER : \n");
        scanf("%d",&ar[i].rno);
        break;
        case 3:
        printf("ENTER ATTENDANCE : \n");
        scanf("%f",&ar[i].attendance);
        break;
        case 4:
        printf("ENTER NEW MARKS : \n");
        scanf("%d",&ar[i].marks);
        break;
    }
      display(n,ar);
  }
}
}


int deletestudent(int n,struct studentdetails ar[n]){
  int a;
  printf("ENTER THE ROLL NUMBER YOU WANT TO DELETE : \n");
  scanf("%d", &a);
      for (int j = 0; j < n; j++) {
          if (a == ar[j].rno) {
              for (int k = j; k < n; k++)
                  ar[k] = ar[k + 1];
              i--;
          }
      }
      printf("THE ROLL NUMBER IS SUCESSFULLY DELETED\n");
      display(n,ar);
}
