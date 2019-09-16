

 /*----------------ͷ�ļ�--------------*/
#define  _CRT_SECURE_NO_WARNINGS
 #include <math.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include "score.h"

 /*----------------��������-------------*/

 //1.1�ֶ�����ѧ����������
 void readData(SS stu[], int N)
 {

     printf("Please enter student information in the following format:student number, name, dailyScore, finalScore\n");

     for (int i = 0; i < N; i++)
     {
         printf("��%d��ѧ��:", i + 1);
         scanf("%s %s %f %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].experimentScore, &stu[i].finalScore);
         printf("\n");
     }

     printf("------Results entry complete!--------\n");

 }
 //1.2���ļ����ȡѧ����������
 SS* readDataFromFile(int *N)
 {

     printf("\n\n------Step 1: Read the student's grade information from the file--------\n\n");

     SS *stu;                      // �����¿ռ�,��ȡ�ļ��е�ÿ��ѧ����Ϣ
     FILE *fp = NULL;
     int count = 0;
     int index = 0;

     fp = fopen("data.txt", "r");

     //1.��ȡѧ����Ŀ
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

     printf("ѧ����ĿΪ:%d\n", count);


     //2.������ѧ������洢�ռ�
     stu = (SS*)malloc(count * sizeof(SS));


     //3.��ȡÿ��ѧ������Ϣ
     while ((!feof(fp)))
     {

         //�����ļ����ݵ��ڴ�
         fscanf(fp, "%s%s%f%f%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore, &stu[index].experimentScore, &stu[index].finalScore);

        //���������ѧ����Ϣ
         printf("* number��%s	name:%s		dailyScore��%4.2f��		experimentScore��%4.2f��		finalScore:%4.2f��\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, stu[index].experimentScore, stu[index].finalScore);

         index++;
     }

     getchar();

     fclose(fp);

     return stu;
 }
  //2.����N��ѧ�����Ե������ɼ�
  void calcuScore(SS stu[], int N)
 {


     printf("\n\n------Step 2: Calculate the general score of each student--------\n\n");

     for (int i = 0; i < N; i++)
     {

         stu[i].generalScore = 0.2*stu[i].dailyScore + 0.6*stu[i].finalScore + 0.2*stu[i].experimentScore;
         printf("* number��%s	name:%s		generalScore:%4.2f��\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

     }

     getchar();
 }

 //3.���������ɼ�����
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

 //4.����һ���ĸ�ʽ���N��ѧ������Ϣ
 void printOut(SS stu[], int N)
 {

     printf("\n------Step 3: Output student ranking information based on the total score!------\n\n");

     for (int i = 0; i < N; i++)
     {

         printf("The number of the student: number��%s	name:%s		generalScore:%4.2f��\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
     }

     getchar();

 }
 //5.����ѧ�Ų���
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
             printf("The information of the%d student number��%s	name:%s		generalScore:%4.2f��\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
         }
     }
     getchar();
 }
 void analysis(SS stu[], int N)
 {
     int totally = 0;
     //1.����ƽ����
     for (int i = 0; i < N; i++)
     {
       totally = totally + stu[i].generalScore;
     }
     printf("*************Class Average is ��%d*************\n", totally / N);
     //2.�����׼����
     int fangcha = 0;
     for (int i = 0; i < N; i++)
     {
         fangcha = fangcha + (stu[i].generalScore - totally / N)*(stu[i].generalScore - totally / N);
     }
     printf("*************The standard variance is��%d*************\n", fangcha / N);
     //3.�жϰ༶�ɼ��ֲ�
     int j = 0;
     for (int i = 0; i < N; i++)
     {
         if (stu[i].generalScore <= 85)
             j++;
     }
     int s = 0;
     for (int i = 0; i < N; i++)
     {
         if (stu[i].generalScore > 85��
             s++;
     }
     if (s > j)
         printf("******************Most of the classes have excellent grades��>85��**************\n");
     else
         printf("******************Most of the classes don't have excellent grades��<85��**************");
     getchar();
 }

