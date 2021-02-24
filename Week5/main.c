//#include <stdio.h>
////
//// Created by Darren on 23/02/2021.
////
//struct student{
//    char name[20];
//    char courseCode[5];
//    int yearOfStudy;
//    float results[6];
//};
//
//typedef struct student STUDENT;
//
//int main();
//void inputStudents(STUDENT *);
//void display(STUDENT *);
//void totalFailed(STUDENT *);
//
//int main(){
//
//    STUDENT students[5];
//
//    inputStudents(students);
//    display(students);
//    totalFailed(students);
//
//}
//void inputStudents(STUDENT *students){
//
//    for(int i = 0; i < 5; i++) {
//        printf("Input a student name");
//        scanf("%s", students[i].name);
//        getchar();
//        getchar();
//
//        printf("Input a student's code");
//        scanf("%s", students[i].courseCode);
//        getchar();
//        getchar();
//
//        while (students[i].yearOfStudy <= 4 && students[i].yearOfStudy > 0) {
//            printf("Input a students year of study");
//            scanf("%d", &students[i].yearOfStudy);
//            getchar();
//            getchar();
//        }
//
//        for (int x = 0; x < 6; x++) {
//            printf("Input grade %d: ", x);
//            scanf("%f", &students[i].results[x]);
//            getchar();
//            getchar();
//        }
//    }
//}
//
//void display(STUDENT *students){
//    for(int i = 0; i < 5; i++) {
//        printf("\nStudent Name: %s",students[i].name);
//        printf("\nStudent Code: %s",students[i].courseCode);
//        printf("\nStudent year of study: %d",students[i].yearOfStudy);
//
//        for (int x = 0; x < 6; x++) {
//            printf("\nExam Result %d: %.2f", x, students[i].results[x]);
//
//        }
//
//    }
//}
//
//void totalFailed(STUDENT *students){
//    int failed[5];
//    int count, total;
//    for(int i =0; i < 5; i++){
//        count = 0;
//        for(int x = 0; x < 6; x++){
//            if(students[i].results[x] <= 40){
//                count++;
//            }
//        }
//        failed[i] = count;
//        count = 0;
//        printf("Student %s failed %d subjects", students[i].name, failed[i]);
//
//
//    }
//    for(int index = 0; index < 5;index++){
//        total += failed[i];
//    }
//    printf("Total Failed: %d", total);
//
//}