#define  _CRT_SECURE_NO_WARNINGS
 #include <stdio.h>
 #include <stdlib.h>
 #include <windows.h>
 #include "score.h"
 int main()
{
     printf("********************************************************\n");
     printf("   Student achievement management analysis system        \n");
     printf("                   Yaru  Wang            \n");
     printf("********************************************************\n\n");

     int N = 0;            //学生总数
     SS  *pstu = NULL;    //学生数组-结构体数组指针实现

     //2.读取学生信息
     pstu = readDataFromFile(&N);

     /*-3.计算学生总成绩（总成绩 = 0.2*平时成绩 + 0.6*期末成绩)--*/
     calcuScore(pstu, N);

     /*-4.根据学生成绩排名-*/
     sortScore(pstu, N);

     /*-5.按照排名输出学生信息-*/
     printOut(pstu, N);
     /*-6.按照学号输出学生信息-*/
     seekone(pstu, N);
     /*-7.对全班同学的成绩的分析*/
     analysis(pstu, N);
     /*-8.释放动态内存空间-*/
     free(pstu);


     system("pause");
     return 0;
 }
