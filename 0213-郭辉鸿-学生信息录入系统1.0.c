#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h>
#include<Windows.h>

#define MaxStu 100       //M01定义无分号；

struct Stu
{ 
	char id[16];//学号
	char name[16];//姓名
	char sex[2];//性别
	int  age;//年龄
	char tel[16];//手机号码
};    //M02结构体定义加上分号
struct Stu_Proj
{
    struct Stu students[MaxStu];//学生数组，最大值是MaxStu，采用散列表的形式存储；
	int exist[MaxStu];//学生是否存在，如果exist[4]=1，说明students[4]的学生是存在的；如果exist[5]=0，说明students[5]的学生是不存在的（被删除了，或还没有录入）；
	int n;//当前学生数；
};    //M03结构体定义加上分号
	  /*
	  这是什么？
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
	sp=malloc(sizeof sp);//M20分配空间；
	system("cls");
	printf("\n\n\t\t┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
	printf("\t\t ☆☆     学生信息管理系统     ☆☆ \n");
	printf("\t\t┌┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┐\n");
	printf("\t\t┆                                      ┆\n");
	printf("\t\t┆             0、退出系统              ┆\n");
	printf("\t\t┆                                      ┆\n");
	printf("\t\t┆             1、新增学生信息          ┆\n");
	printf("\t\t┆             2、删除学生信息          ┆\n");
	printf("\t\t┆             3、修改学生信息          ┆\n");
	printf("\t\t┆             4、查询学生信息          ┆\n");
	printf("\t\t┆                                      ┆\n");
	printf("\t\t┆             5、保存学生信息          ┆\n");
	printf("\t\t┆             6、加载学生信息          ┆\n");
	printf("\t\t┆                                      ┆\n");
	printf("\t\t┆             7、重新初始化系统        ┆\n");
	printf("\t\t├┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┤\n");
	printf("\t\t┆                                      ┆\n");
	printf("\t\t┆   开发者：___________  版本：V1.0    ┆\n");
	printf("\t\t┆                                      ┆\n");
	printf("\t\t└┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┘\n");
	printf("\n\t\t请选择功能：");
	do
	{
		
		c=getch();
		switch(c)
		{
		case '0':
			return;
		case '1':
			_1_enter(sp); break; //M04函数少了参数值；
		case '2':
			_2_del(sp); break;   //M05函数少了参数值；
		case '3':
			_3_update(sp); break;//M06函数少了参数值；
		case '4':
            _4_search(sp); break;//M07函数少了参数值；
		case '5':
			_5_save(sp); break;  //M08函数少了参数值；
		case '6':
			_6_load(sp);  break; //M09函数少了参数值；
        case '7':
			_7_init(sp); break;  //M10函数少了参数值；
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
	printf("请输入第%d个学生的信息\n",i+1);
	printf("\n   学号     姓名       性别     年龄       电话\n");                     //M21加取地址符
	scanf("%s %s %s %d %s",sp->students[i].id,sp->students[i].name,sp->students[i].sex,&sp->students[i].age,sp->students[i].tel);
	sp->n++;
	sp->exist[i]=1;
	printf("任意键继续......\n");
	
}
void _2_del(struct Stu_Proj *sp)
{
	int i;
	char id[16];
	printf("请输入学生学号:");
	scanf("%s",id);
	for(i=0;i<MaxStu;i++) 
	{
		if(strcmp(sp->students[i].id, id)==0)
		{
			sp->exist[i]=0;
			break;
		}
	}
	printf("任意键继续......\n");
}
void _3_update(struct Stu_Proj *sp)
{
	int i;
	char id[16];
	printf("请输入学生学号:");
	scanf("%s",id);
	for(i=0;i<MaxStu;i++)
	{
		if(strcmp(sp->students[i].id, id)==0)
		{                                                                                      //M21加取地址符
			scanf("%s %s %s %d %s",sp->students[i].id,sp->students[i].name,sp->students[i].sex,&sp->students[i].age,sp->students[i].tel);
			break;
		}
	}
	printf("任意键继续......\n");
}
void _4_search(struct Stu_Proj *sp)
{
	int i;
	for(i=0;i<MaxStu;i++)
	{
		if(sp->exist[i]==1)
		{
			printf("\n   学号     姓名       性别     年龄       电话\n");
			printf("%-11s %-11s %-8s %-7d %-8s\n",sp->students[i].id,sp->students[i].name,sp->students[i].sex,sp->students[i].age,sp->students[i].tel);
		}
		
	}
	printf("任意键继续......\n");
}
void _5_save(struct Stu_Proj *sp)
{
	FILE *fp;
	fp=fopen("c:\\xuesheng.dat","wb");
	fwrite(sp,sizeof(struct Stu_Proj),1,fp);//M22  sp改成struct Stu_Proj
	
	fclose(fp);
	printf("任意键继续......");
}
void _6_load(struct Stu_Proj *sp)
{
	FILE *fp;
	fp=fopen("c:\\xuesheng.dat","rb");
	fread(sp,sizeof(struct Stu_Proj),1,fp);//M22  sp改成struct Stu_Proj 
	fclose(fp);
	printf("任意键继续......\n");
}
void _7_init(struct Stu_Proj *sp)
{
	int i;
	sp=malloc(sizeof sp);
	sp->n=0;
	for(i=0;i<MaxStu;i++)sp->exist[i]=0;
	printf("任意键继续......\n");
}
