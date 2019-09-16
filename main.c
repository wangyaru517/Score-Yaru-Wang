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

     int N = 0;            //ѧ������
     SS  *pstu = NULL;    //ѧ������-�ṹ������ָ��ʵ��

     //2.��ȡѧ����Ϣ
     pstu = readDataFromFile(&N);

     /*-3.����ѧ���ܳɼ����ܳɼ� = 0.2*ƽʱ�ɼ� + 0.6*��ĩ�ɼ�)--*/
     calcuScore(pstu, N);

     /*-4.����ѧ���ɼ�����-*/
     sortScore(pstu, N);

     /*-5.�����������ѧ����Ϣ-*/
     printOut(pstu, N);
     /*-6.����ѧ�����ѧ����Ϣ-*/
     seekone(pstu, N);
     /*-7.��ȫ��ͬѧ�ĳɼ��ķ���*/
     analysis(pstu, N);
     /*-8.�ͷŶ�̬�ڴ�ռ�-*/
     free(pstu);


     system("pause");
     return 0;
 }
