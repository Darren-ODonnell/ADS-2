//#include <stdio.h>
//#define EXAMS 3
//#define STUDENTS 4
//
//int main() {
//    int exams[STUDENTS][EXAMS];
//    float averages[STUDENTS];
//    int sum;
//    //input the results
//    for (int i = 0; i < STUDENTS; i++) {
//        printf("Input the %d results for student %d \n", EXAMS, (i + 1));
//        for (int j = 0; j < EXAMS; j++)
//            scanf("%d", &exams[i][j]);
//    }
//
//    printf("\n\n");
//
//    //display the results
//    for (int i = 0; i < STUDENTS; i++) {
//        printf("The %d results for student %d are...\n", EXAMS, (i + 1));
//        for (int j = 0; j < EXAMS; j++)
//            printf("%d%% ", exams[i][j]);
//        printf("\n");
//    }
//    for (int i = 0; i < STUDENTS; i++) {
//
//    sum = 0;
//        for (int x = 0; x < EXAMS; x++){
//            sum = sum + exams[i][x];
//        }
//        averages[i] = (float) sum / EXAMS;
//        printf("Averages Of Exam for Student %d: %4.2f", i+1, averages[i]);
//    }
//
//
//}
