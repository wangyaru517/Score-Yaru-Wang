

 /*----------------头文件--------------*/
#define  _CRT_SECURE_NO_WARNINGS
 #include <math.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include "score.h"

 /*----------------函数定义-------------*/

 //1.1手动输入学生基本数据
 void readData(SS stu[], int N)
 {

     printf("Please enter student information in the following format:student number, name, dailyScore, finalScore\n");

     for (int i = 0; i < N; i++)
     {
         printf("第%d个学生:", i + 1);
         scanf("%s %s %f %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].experimentScore, &stu[i].finalScore);
         printf("\n");
     }

     printf("------Results entry complete!--------\n");

 }
 //1.2从文件里读取学生基本数据
 SS* readDataFromFile(int *N)
 {

     printf("\n\n------Step 1: Read the student's grade information from the file--------\n\n");

     SS *stu;                      // 开辟新空间,存取文件中的每个学生信息
     FILE *fp = NULL;
     int count = 0;
     int index = 0;

     fp = fopen("data.txt", "r");

     //1.获取学生数目
     if (fp != NULL)
     {
         fscanf(fp, "%d", &count);
 * N = count;
     }
     else
     {
         printf("failed to open the info file\n");
         getchar();
     }

     printf("学生数目为:%d\n", count);


     //2.给所有学生分配存储空间
     stu = (SS*)malloc(count * sizeof(SS));


     //3.读取每条学生的信息
     while ((!feof(fp)))
     {

         //读入文件数据到内存
         fscanf(fp, "%s%s%f%f%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore, &stu[index].experimentScore, &stu[index].finalScore);

        //输出排序后的学生信息
         printf("* number：%s	name:%s		dailyScore：%4.2f分		experimentScore：%4.2f分		finalScore:%4.2f分\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, stu[index].experimentScore, stu[index].finalScore);

         index++;
     }

     getchar();

     fclose(fp);

     return stu;
 }
  //2.计算N个学生各自的总评成绩
  void calcuScore(SS stu[], int N)
 {


     printf("\n\n------Step 2: Calculate the general score of each student--------\n\n");

     for (int i = 0; i < N; i++)
     {

         stu[i].generalScore = 0.2*stu[i].dailyScore + 0.6*stu[i].finalScore + 0.2*stu[i].experimentScore;
         printf("* number：%s	name:%s		generalScore:%4.2f分\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

     }

     getchar();
 }

 //3.根据总评成绩排名
 int cmpBigtoSmall(const void *a, const void *b)
 {

     SS *aa = (SS *)(a);
     SS *bb = (SS *)(b);


     if ((*aa).generalScore < (*bb).generalScore)  return 1;

     else if ((*aa).generalScore > (*bb).generalScore)  return -1;

     else
         return 0;

 }

 void sortScore(SS stu[], int N)
 {

     qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);

 }

 //4.按照一定的格式输出N个学生的信息
 void printOut(SS stu[], int N)
 {

     printf("\n------Step 3: Output student ranking information based on the total score!------\n\n");

     for (int i = 0; i < N; i++)
     {

         printf("The number of the student: number：%s	name:%s		generalScore:%4.2f分\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
     }

     getchar();

 }
 //5.按照学号查找
 void seekone(SS stu[], int N)
 {
     printf("\n------Step 4: Find results according to the school number-------------------\n\n");
     printf("*****************Please enter the number***************\n");
     char str[10];
     scanf("%s", str);
     for (int i = 0; i < N; i++)
     {
         if (strcmp(stu[i].number, str) == 0)
         {
             printf("The information of the%d student number：%s	name:%s		generalScore:%4.2f分\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
         }
     }
     getchar();
 }
 void analysis(SS stu[], int N)
 {
     int totally = 0;
     //1.计算平均分
     for (int i = 0; i < N; i++)
     {
       totally = totally + stu[i].generalScore;
     }
     printf("*************Class Average is ：%d*************\n", totally / N);
     //2.计算标准方差
     int fangcha = 0;
     for (int i = 0; i < N; i++)
     {
         fangcha = fangcha + (stu[i].generalScore - totally / N)*(stu[i].generalScore - totally / N);
     }
     printf("*************The standard variance is：%d*************\n", fangcha / N);
     //3.判断班级成绩分布
     int j = 0;
     for (int i = 0; i < N; i++)
     {
         if (stu[i].generalScore <= 85)
             j++;
     }
     int s = 0;
     for (int i = 0; i < N; i++)
     {
         if (stu[i].generalScore > 85）
             s++;
     }
     if (s > j)
         printf("******************Most of the classes have excellent grades（>85）**************\n");
     else
         printf("******************Most of the classes don't have excellent grades（<85）**************");
     getchar();
 }

