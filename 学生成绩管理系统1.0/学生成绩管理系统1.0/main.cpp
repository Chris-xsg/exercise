#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/***************************定义学生结构体、链表*************************/
typedef struct Student
{//定义一个学生结构体
	char _name[20]; //姓名
	int _stunum;    //学号
	int _Math_score;     //高数成绩
	int _English_score;  //大英成绩
	int _C_score;        //C语言成绩
}Student;

//链表储存
typedef struct Listnode
{
	Student stu; //学生
	struct Listnode* Next; //指向下一个节点
}Node;

//创建一个头结点
Node* phead = NULL; //头结点为空

/***************************各功能模块实现*************************/
//录入学生信息
void InputStudent()
{
	Node* newnode = (Node*)malloc(sizeof(Node));//创建一个新结点---学生
	newnode->Next = NULL;//下一个指向空
	
	//将新节点尾插到链表中
	Node* p = phead;
	while (phead != NULL && p->Next != NULL)
	{//找尾
		p = p->Next;
	}
	//尾插到链表中
	if (phead == NULL)
	{
		phead = newnode;
	}
	else
	{
		p->Next = newnode;
	}

	//录入信息
	printf("请输入学生姓名：");
	scanf("%s", newnode->stu._name, sizeof(newnode->stu._name));
	printf("\n");
	printf("请输入学号：");
	scanf("%d", &newnode->stu._stunum);
	printf("\n");
	printf("请输入高数成绩：");
	scanf("%d", &newnode->stu._Math_score);
	printf("\n");
	printf("请输入英语成绩：");
	scanf("%d", &newnode->stu._English_score);
	printf("\n");
	printf("请输入C语言成绩：");
	scanf("%d", &newnode->stu._C_score);
	printf("\n");

	printf("学生信息录入成功！注意及时保存\n\n");
	system("pause");
	system("cls");

}


//打印学生信息
void PrintStudent()
{
	//遍历链表进行打印
	Node* p = phead;
	if (p == NULL)
		printf("系统中无学生信息！\n\n");

	else
	{
		printf("*********************************************************************************\n");
		printf("*\t\t\t欢迎使用学生成绩管理系统\t\t\t*\n");
		printf("*********************************************************************************\n");
		printf("*\t姓名\t*\t学号\t*\t高数成绩*\t英语成绩*\tC语言成绩\t*\n");
		printf("*********************************************************************************\n");

		while (p != NULL)
		{
			printf("*\t%s\t*\t%d\t*\t%d  \t*\t%d  \t*\t%d  \t*\n",
				p->stu._name,
				p->stu._stunum,
				p->stu._Math_score,
				p->stu._English_score,
				p->stu._C_score
				);

			//下一个节点
			p = p->Next;
			printf("*********************************************************************************\n");
		}
		
	}
	system("pause");
	system("cls");
}


//保存学生信息
void SaveStudent()
{
	//打开文件--Write方式
	FILE* File = NULL;
	File = fopen(".\\StuInfo.dat", "a");

	if (File == NULL)
	{
		printf("打开文件失败！\n");
		return;
	}

	//写入数据
	Node* p = phead;
	while (p != NULL)
	{
		fwrite(&p->stu, sizeof(Node), 1, File);
		p = p->Next;
	}

	fclose(File);//关闭文件
	File = NULL;

	printf("数据保存成功！\n");
	system("pause");
	system("cls");

}

//读取文件中学生信息
void ReadStudent()
{
	//打开文件--Read方式
	FILE* File = NULL;
	File = fopen(".\\StuInfo.dat", "r");

	if (File == NULL)
	{
		printf("打开文件失败！\n");
		return;
	}

	Node* p = (Node*)malloc(sizeof(Node));
	p->Next = NULL;
	phead = p; //创新创建链表

	//逐个单词读入文本内容
	char str[256];
	int i = 0;
	while (fscanf(File, "%s", str) != EOF)
	{//读文件 单词不是*或者空时，进行赋值
		if (strcmp(str, "*") && str != NULL)
		{
			switch (i)
			{
			case 0:
				strcpy(p->stu._name, str);
				break;
			case 1:
				p->stu._stunum = atoi(str);
				break;
			case 2:
				p->stu._Math_score = atoi(str);
				break;
			case 3:
				p->stu._English_score = atoi(str);
				break;
			case 4:
				p->stu._C_score = atoi(str);
				break;
			default:
				Node* newnode = (Node*)malloc(sizeof(Node));
				newnode->Next = NULL;
				p->Next = newnode;
				p = newnode;
				strcpy(p->stu._name, str);
				i = 0;
				break;
				
			}
			i++;
		}

	}
	fclose(File);
	File = NULL;
	PrintStudent();

}

//查询学生信息
void FindStudent()
{
	int flag = 0;
	printf("输入 1 按学号查询、输入 2 按姓名查询,按任意键返回：");
	scanf("%d", &flag);
	printf("\n");
	if (flag == 1)
	{
		//按学号查找
		int stunum;
		printf("请输入查找学生学号：");
		scanf("%d", &stunum);
		printf("\n");
		//遍历链表进行查找，找到后进行打印
		Node* p = phead;
		bool IsFind = false;//记录是否找到该学号的信息
		while (p != NULL)
		{
			if (stunum == p->stu._stunum)
			{
				printf("*********************************************************************************\n");
				printf("*\t姓名\t*\t学号\t*\t高数成绩\t*\t英语成绩\t*\tC语言成绩\t*\n");
				printf("*********************************************************************************\n");
				printf("*\t%s\t*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\n",
					p->stu._name,
					p->stu._stunum,
					p->stu._Math_score,
					p->stu._English_score,
					p->stu._C_score
					);
				IsFind = true;
				printf("*********************************************************************************\n");
			}
			p = p->Next;
		}
		if (!IsFind)
			printf("学号有误，系统中无该学生信息！\n\n");
	}
	else if (flag == 2)
	{
		//按姓名查找
		char name[20];
		printf("请输入学生姓名：");
		scanf("%s", name, sizeof(name));
		printf("\n");
		//遍历链表进行查找，找到后进行打印
		Node* p = phead;
		bool IsFind = false;//记录是否找到该学号的信息
		while (p != NULL)
		{
			if (strcmp(name, p->stu._name) == 0)
			{
				printf("*********************************************************************************\n");
				printf("*\t姓名\t*\t学号\t*\t高数成绩\t*\t英语成绩\t*\tC语言成绩\t*\n");
				printf("*********************************************************************************\n");
				printf("*\t%s\t*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\n",
					p->stu._name,
					p->stu._stunum,
					p->stu._Math_score,
					p->stu._English_score,
					p->stu._C_score
					);
				IsFind = true;
				printf("*********************************************************************************\n");
			}
			p = p->Next;
		}
		if (!IsFind)
			printf("姓名有误，系统中无该学生信息！\n\n");

	}
	else
		return;

	system("pause");
	system("cls");

}


//修改学生信息
void ChangeStudent()
{
	//修改信息需要查找学到学生，与上面的查找结合起来,在此只写用学号查找修改信息

	//按学号查找
	int stunum;
	printf("请输入要修改的学生学号：");
	scanf("%d", &stunum);
	printf("\n");
	//遍历链表进行查找，找到后进行打印
	Node* p = phead;
	bool IsFind = false;//记录是否找到该学号的信息
	while (p != NULL)
	{
		if (stunum == p->stu._stunum)
		{
			printf("*********************************************************************************\n");
			printf("*\t姓名\t*\t学号\t*\t高数成绩\t*\t英语成绩\t*\tC语言成绩\t*\n");
			printf("*********************************************************************************\n");
			printf("*\t%s\t*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\n",
				p->stu._name,
				p->stu._stunum,
				p->stu._Math_score,
				p->stu._English_score,
				p->stu._C_score
				);
			IsFind = true;
			printf("*********************************************************************************\n");
			printf("请输入学生姓名：");
			scanf("%s", p->stu._name, sizeof(p->stu._name));
			printf("\n");
			printf("请输入学号：");
			scanf("%d", &p->stu._stunum);
			printf("\n");
			printf("请输入高数成绩：");
			scanf("%d", &p->stu._Math_score);
			printf("\n");
			printf("请输入英语成绩：");
			scanf("%d", &p->stu._English_score);
			printf("\n");
			printf("请输入C语言成绩：");
			scanf("%d", &p->stu._C_score);
			printf("\n");

			printf("学生信息修改成功！注意及时保存\n\n");

		}
		p = p->Next;
	}
	if (!IsFind)
		printf("学号有误，系统中无该学生信息！\n\n");

	system("pause");
	system("cls");
}

//删除学生信息
void DeleteStudent()
{
	//还是以查找为基础，找到学生进行删除

	//按学号查找
	int stunum;
	printf("请输入要删除的学生学号：");
	scanf("%d", &stunum);
	printf("\n");
	//遍历链表进行查找，找到后进行打印
	Node* p = phead;
	Node* prev = phead;//建立一个前驱指针用来存放p的前一个结点
	bool IsFind = false;//记录是否找到该学号的信息
	while (p != NULL)
	{
		if (stunum == p->stu._stunum)
		{
			printf("*********************************************************************************\n");
			printf("*\t姓名\t*\t学号\t*\t高数成绩\t*\t英语成绩\t*\tC语言成绩\t*\n");
			printf("*********************************************************************************\n");
			printf("*\t%s\t*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\n",
				p->stu._name,
				p->stu._stunum,
				p->stu._Math_score,
				p->stu._English_score,
				p->stu._C_score
				);
			IsFind = true;
			printf("*********************************************************************************\n");
			//找到后进行删除 删除分三种情况：头结点、中间结点、尾结点
			if (p == phead)
			{//删除头结点
				phead = p->Next;
			}
			else if (p->Next == NULL)
			{//删除尾结点
				p = prev;
				p->Next = NULL;
			}
			else
			{//删除中间结点
				prev->Next = p->Next;
				delete p;
			}
			printf("学生信息删除成功！注意及时保存\n\n");
		}
		prev = p;
		p = p->Next;
	}
	if (!IsFind)
		printf("学号有误，系统中无该学生信息！\n\n");

	system("pause");
	system("cls");
}

//统计信息
typedef struct Class
{//定义一个学科结构体，方便统计
	int Max = 0;//最高分
	int a = 0,//不及格人数
		b = 0,//60-69人数
		c = 0,//70-79人数
		d = 0,//80-89人数
		e = 0;//90-100人数

}Class;
void StatisticsStudent()
{
	//需要统计各科的最高分；不及格、60-69、70-79、80-89、90-100的人数
	Class Math, English, C;
	//遍历链表
	if (phead == NULL)
	{
		printf("系统中无数据，无法统计\n");
		return;
	}
	Node* p = phead;
	while (p != NULL)
	{
		//各科最高分统计
		if (p->stu._Math_score > Math.Max)
			Math.Max = p->stu._Math_score;

		if (p->stu._English_score> English.Max)
			English.Max = p->stu._English_score;

		if (p->stu._C_score> C.Max)
			C.Max = p->stu._C_score;

		//高数成绩的各段人数统计
		if (p->stu._Math_score >= 0 && p->stu._Math_score <= 59)
			Math.a++;
		else if (p->stu._Math_score >= 60 && p->stu._Math_score <= 69)
			Math.b++;
		else if (p->stu._Math_score >= 70 && p->stu._Math_score <= 79)
			Math.c++;
		else if (p->stu._Math_score >= 80 && p->stu._Math_score <= 89)
			Math.d++;
		else
			Math.e++;
		
		//英语成绩的各段人数统计
		if (p->stu._English_score >= 0 && p->stu._English_score <= 59)
			English.a++;
		else if (p->stu._English_score >= 60 && p->stu._English_score <= 69)
			English.b++;
		else if (p->stu._English_score >= 70 && p->stu._English_score <= 79)
			English.c++;
		else if (p->stu._English_score >= 80 && p->stu._English_score <= 89)
			English.d++;
		else
			English.e++;

		//C语言成绩的各段人数统计
		if (p->stu._C_score >= 0 && p->stu._C_score <= 59)
			C.a++;
		else if (p->stu._C_score >= 60 && p->stu._C_score <= 69)
			C.b++;
		else if (p->stu._C_score >= 70 && p->stu._C_score <= 79)
			C.c++;
		else if (p->stu._C_score >= 80 && p->stu._C_score <= 89)
			C.d++;
		else
			C.e++;

		p = p->Next;
	}
	printf("*********************************************************************************\n");
	printf("*\t\t\t高数成绩总览\t\t\t*\n");
	printf("*********************************************************************************\n");
	printf("高数最高分为：%d\n", Math.Max);
	printf("*\t不及格\t*\t60-69\t*\t70-79\t*\t80-89\t*\t90-100\t*\n");
	printf("*********************************************************************************\n");
	printf("*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\n",Math.a,Math.b,Math.c,Math.d,Math.e);
	printf("*********************************************************************************\n\n");

	printf("*********************************************************************************\n");
	printf("*\t\t\t英语成绩总览\t\t\t*\n");
	printf("*********************************************************************************\n");
	printf("英语最高分为：%d\n", English.Max);
	printf("*\t不及格\t*\t60-69\t*\t70-79\t*\t80-89\t*\t90-100\t*\n");
	printf("*********************************************************************************\n");
	printf("*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\n",English.a, English.b, English.c, English.d, English.e);
	printf("*********************************************************************************\n\n");
	
	printf("*********************************************************************************\n");
	printf("*\t\t\tC语言成绩总览\t\t\t*\n");
	printf("*********************************************************************************\n");
	printf("C语言最高分为：%d\n", C.Max);
	printf("*\t不及格\t*\t60-69\t*\t70-79\t*\t80-89\t*\t90-100\t*\n");
	printf("*********************************************************************************\n");
	printf("*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\n",C.a, C.b, C.c, C.d, C.e);
	printf("*********************************************************************************\n\n");

	system("pause");
	system("cls");

}

/***************************菜单界面、主函数实现*************************/

//菜单
void Menu() 
{
	printf("*************************************************\n");
	printf("*\t欢迎使用学生成绩管理系统\t\t*\n");
	printf("*\t\t请选择功能\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.录入学生信息\t\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t\t*\n");
	printf("*\t\t3.保存学生信息\t\t\t*\n");
	printf("*\t\t4.读取学生信息\t\t\t*\n");
	printf("*\t\t5.统计学生成绩信息\t\t*\n");
	printf("*\t\t6.查询学生信息\t\t\t*\n");
	printf("*\t\t7.修改学生信息\t\t\t*\n");
	printf("*\t\t8.删除学生信息\t\t\t*\n");
	printf("*\t\t0.退出系统\t\t\t*\n");
	printf("*************************************************\n");
}
//主函数
int main() 
{
	while (1)
	{
		//打印菜单
		Menu();
		//用switch case实现各功能
		int n;
		scanf("%d", &n);
		switch (n)
		{
		case 1://1.录入学生信息
			InputStudent();
			break;
		case 2://2.打印学生信息
			PrintStudent();
			break;
		case 3://3.保存学生信息
			SaveStudent();
			break;
		case 4://4.读取学生信息
			ReadStudent();
			break;
		case 5://5.统计学生成绩信息
			StatisticsStudent();
			break;
		case 6://6.查找学生信息
			FindStudent();
			break;
		case 7://7.修改学生信息
			ChangeStudent();
			break;
		case 8://8.删除学生信息
			DeleteStudent();
			break;
		case 0://0.退出系统
			printf("已退出，欢迎下次使用！\n");
			return 0;
			break;
		default:
			printf("输入有误，没有该功能\n\n");
			system("pause");  //暂停
			system("cls");    //清屏
			break;
		}
	}

	return 0;
}
