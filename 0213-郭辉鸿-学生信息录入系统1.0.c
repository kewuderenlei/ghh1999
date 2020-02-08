#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h>
#include<Windows.h>

#define MaxStu 100       //M01�����޷ֺţ�

struct Stu
{ 
	char id[16];//ѧ��
	char name[16];//����
	char sex[2];//�Ա�
	int  age;//����
	char tel[16];//�ֻ�����
};    //M02�ṹ�嶨����Ϸֺ�
struct Stu_Proj
{
    struct Stu students[MaxStu];//ѧ�����飬���ֵ��MaxStu������ɢ�б����ʽ�洢��
	int exist[MaxStu];//ѧ���Ƿ���ڣ����exist[4]=1��˵��students[4]��ѧ���Ǵ��ڵģ����exist[5]=0��˵��students[5]��ѧ���ǲ����ڵģ���ɾ���ˣ���û��¼�룩��
	int n;//��ǰѧ������
};    //M03�ṹ�嶨����Ϸֺ�
	  /*
	  ����ʲô��
*/
void _1_enter(struct Stu_Proj *sp);
void _2_del(struct Stu_Proj *sp);
void _3_update(struct Stu_Proj *sp);
void _4_search(struct Stu_Proj *sp);
void _5_save(struct Stu_Proj *sp);
void _6_load(struct Stu_Proj *sp);
void _7_init(struct Stu_Proj *sp);

void main()
{
	
    struct Stu_Proj *sp;
	char c;
	sp=malloc(sizeof sp);//M20����ռ䣻
	system("cls");
	printf("\n\n\t\t������������������������������������������\n");
	printf("\t\t ���     ѧ����Ϣ����ϵͳ     ��� \n");
	printf("\t\t������������������������������������������\n");
	printf("\t\t��                                      ��\n");
	printf("\t\t��             0���˳�ϵͳ              ��\n");
	printf("\t\t��                                      ��\n");
	printf("\t\t��             1������ѧ����Ϣ          ��\n");
	printf("\t\t��             2��ɾ��ѧ����Ϣ          ��\n");
	printf("\t\t��             3���޸�ѧ����Ϣ          ��\n");
	printf("\t\t��             4����ѯѧ����Ϣ          ��\n");
	printf("\t\t��                                      ��\n");
	printf("\t\t��             5������ѧ����Ϣ          ��\n");
	printf("\t\t��             6������ѧ����Ϣ          ��\n");
	printf("\t\t��                                      ��\n");
	printf("\t\t��             7�����³�ʼ��ϵͳ        ��\n");
	printf("\t\t������������������������������������������\n");
	printf("\t\t��                                      ��\n");
	printf("\t\t��   �����ߣ�___________  �汾��V1.0    ��\n");
	printf("\t\t��                                      ��\n");
	printf("\t\t������������������������������������������\n");
	printf("\n\t\t��ѡ���ܣ�");
	do
	{
		
		c=getch();
		switch(c)
		{
		case '0':
			return;
		case '1':
			_1_enter(sp); break; //M04�������˲���ֵ��
		case '2':
			_2_del(sp); break;   //M05�������˲���ֵ��
		case '3':
			_3_update(sp); break;//M06�������˲���ֵ��
		case '4':
            _4_search(sp); break;//M07�������˲���ֵ��
		case '5':
			_5_save(sp); break;  //M08�������˲���ֵ��
		case '6':
			_6_load(sp);  break; //M09�������˲���ֵ��
        case '7':
			_7_init(sp); break;  //M10�������˲���ֵ��
		}
	}while(c!='0');
}
void _1_enter(struct Stu_Proj *sp)
{
	int i;
	for(i=0;i<MaxStu;i++) 
	{
		if(sp->exist[i]!=1)
			break;
	}
	printf("�������%d��ѧ������Ϣ\n",i+1);
	printf("\n   ѧ��     ����       �Ա�     ����       �绰\n");                     //M21��ȡ��ַ��
	scanf("%s %s %s %d %s",sp->students[i].id,sp->students[i].name,sp->students[i].sex,&sp->students[i].age,sp->students[i].tel);
	sp->n++;
	sp->exist[i]=1;
	printf("���������......\n");
	
}
void _2_del(struct Stu_Proj *sp)
{
	int i;
	char id[16];
	printf("������ѧ��ѧ��:");
	scanf("%s",id);
	for(i=0;i<MaxStu;i++) 
	{
		if(strcmp(sp->students[i].id, id)==0)
		{
			sp->exist[i]=0;
			break;
		}
	}
	printf("���������......\n");
}
void _3_update(struct Stu_Proj *sp)
{
	int i;
	char id[16];
	printf("������ѧ��ѧ��:");
	scanf("%s",id);
	for(i=0;i<MaxStu;i++)
	{
		if(strcmp(sp->students[i].id, id)==0)
		{                                                                                      //M21��ȡ��ַ��
			scanf("%s %s %s %d %s",sp->students[i].id,sp->students[i].name,sp->students[i].sex,&sp->students[i].age,sp->students[i].tel);
			break;
		}
	}
	printf("���������......\n");
}
void _4_search(struct Stu_Proj *sp)
{
	int i;
	for(i=0;i<MaxStu;i++)
	{
		if(sp->exist[i]==1)
		{
			printf("\n   ѧ��     ����       �Ա�     ����       �绰\n");
			printf("%-11s %-11s %-8s %-7d %-8s\n",sp->students[i].id,sp->students[i].name,sp->students[i].sex,sp->students[i].age,sp->students[i].tel);
		}
		
	}
	printf("���������......\n");
}
void _5_save(struct Stu_Proj *sp)
{
	FILE *fp;
	fp=fopen("c:\\xuesheng.dat","wb");
	fwrite(sp,sizeof(struct Stu_Proj),1,fp);//M22  sp�ĳ�struct Stu_Proj
	
	fclose(fp);
	printf("���������......");
}
void _6_load(struct Stu_Proj *sp)
{
	FILE *fp;
	fp=fopen("c:\\xuesheng.dat","rb");
	fread(sp,sizeof(struct Stu_Proj),1,fp);//M22  sp�ĳ�struct Stu_Proj 
	fclose(fp);
	printf("���������......\n");
}
void _7_init(struct Stu_Proj *sp)
{
	int i;
	sp=malloc(sizeof sp);
	sp->n=0;
	for(i=0;i<MaxStu;i++)sp->exist[i]=0;
	printf("���������......\n");
}
