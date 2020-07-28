#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/***************************����ѧ���ṹ�塢����*************************/
typedef struct Student
{//����һ��ѧ���ṹ��
	char _name[20]; //����
	int _stunum;    //ѧ��
	int _Math_score;     //�����ɼ�
	int _English_score;  //��Ӣ�ɼ�
	int _C_score;        //C���Գɼ�
}Student;

//������
typedef struct Listnode
{
	Student stu; //ѧ��
	struct Listnode* Next; //ָ����һ���ڵ�
}Node;

//����һ��ͷ���
Node* phead = NULL; //ͷ���Ϊ��

/***************************������ģ��ʵ��*************************/
//¼��ѧ����Ϣ
void InputStudent()
{
	Node* newnode = (Node*)malloc(sizeof(Node));//����һ���½��---ѧ��
	newnode->Next = NULL;//��һ��ָ���
	
	//���½ڵ�β�嵽������
	Node* p = phead;
	while (phead != NULL && p->Next != NULL)
	{//��β
		p = p->Next;
	}
	//β�嵽������
	if (phead == NULL)
	{
		phead = newnode;
	}
	else
	{
		p->Next = newnode;
	}

	//¼����Ϣ
	printf("������ѧ��������");
	scanf("%s", newnode->stu._name, sizeof(newnode->stu._name));
	printf("\n");
	printf("������ѧ�ţ�");
	scanf("%d", &newnode->stu._stunum);
	printf("\n");
	printf("����������ɼ���");
	scanf("%d", &newnode->stu._Math_score);
	printf("\n");
	printf("������Ӣ��ɼ���");
	scanf("%d", &newnode->stu._English_score);
	printf("\n");
	printf("������C���Գɼ���");
	scanf("%d", &newnode->stu._C_score);
	printf("\n");

	printf("ѧ����Ϣ¼��ɹ���ע�⼰ʱ����\n\n");
	system("pause");
	system("cls");

}


//��ӡѧ����Ϣ
void PrintStudent()
{
	//����������д�ӡ
	Node* p = phead;
	if (p == NULL)
		printf("ϵͳ����ѧ����Ϣ��\n\n");

	else
	{
		printf("*********************************************************************************\n");
		printf("*\t\t\t��ӭʹ��ѧ���ɼ�����ϵͳ\t\t\t*\n");
		printf("*********************************************************************************\n");
		printf("*\t����\t*\tѧ��\t*\t�����ɼ�*\tӢ��ɼ�*\tC���Գɼ�\t*\n");
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

			//��һ���ڵ�
			p = p->Next;
			printf("*********************************************************************************\n");
		}
		
	}
	system("pause");
	system("cls");
}


//����ѧ����Ϣ
void SaveStudent()
{
	//���ļ�--Write��ʽ
	FILE* File = NULL;
	File = fopen(".\\StuInfo.dat", "a");

	if (File == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return;
	}

	//д������
	Node* p = phead;
	while (p != NULL)
	{
		fwrite(&p->stu, sizeof(Node), 1, File);
		p = p->Next;
	}

	fclose(File);//�ر��ļ�
	File = NULL;

	printf("���ݱ���ɹ���\n");
	system("pause");
	system("cls");

}

//��ȡ�ļ���ѧ����Ϣ
void ReadStudent()
{
	//���ļ�--Read��ʽ
	FILE* File = NULL;
	File = fopen(".\\StuInfo.dat", "r");

	if (File == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return;
	}

	Node* p = (Node*)malloc(sizeof(Node));
	p->Next = NULL;
	phead = p; //���´�������

	//������ʶ����ı�����
	char str[256];
	int i = 0;
	while (fscanf(File, "%s", str) != EOF)
	{//���ļ� ���ʲ���*���߿�ʱ�����и�ֵ
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

//��ѯѧ����Ϣ
void FindStudent()
{
	int flag = 0;
	printf("���� 1 ��ѧ�Ų�ѯ������ 2 ��������ѯ,����������أ�");
	scanf("%d", &flag);
	printf("\n");
	if (flag == 1)
	{
		//��ѧ�Ų���
		int stunum;
		printf("���������ѧ��ѧ�ţ�");
		scanf("%d", &stunum);
		printf("\n");
		//����������в��ң��ҵ�����д�ӡ
		Node* p = phead;
		bool IsFind = false;//��¼�Ƿ��ҵ���ѧ�ŵ���Ϣ
		while (p != NULL)
		{
			if (stunum == p->stu._stunum)
			{
				printf("*********************************************************************************\n");
				printf("*\t����\t*\tѧ��\t*\t�����ɼ�\t*\tӢ��ɼ�\t*\tC���Գɼ�\t*\n");
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
			printf("ѧ������ϵͳ���޸�ѧ����Ϣ��\n\n");
	}
	else if (flag == 2)
	{
		//����������
		char name[20];
		printf("������ѧ��������");
		scanf("%s", name, sizeof(name));
		printf("\n");
		//����������в��ң��ҵ�����д�ӡ
		Node* p = phead;
		bool IsFind = false;//��¼�Ƿ��ҵ���ѧ�ŵ���Ϣ
		while (p != NULL)
		{
			if (strcmp(name, p->stu._name) == 0)
			{
				printf("*********************************************************************************\n");
				printf("*\t����\t*\tѧ��\t*\t�����ɼ�\t*\tӢ��ɼ�\t*\tC���Գɼ�\t*\n");
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
			printf("��������ϵͳ���޸�ѧ����Ϣ��\n\n");

	}
	else
		return;

	system("pause");
	system("cls");

}


//�޸�ѧ����Ϣ
void ChangeStudent()
{
	//�޸���Ϣ��Ҫ����ѧ��ѧ����������Ĳ��ҽ������,�ڴ�ֻд��ѧ�Ų����޸���Ϣ

	//��ѧ�Ų���
	int stunum;
	printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	scanf("%d", &stunum);
	printf("\n");
	//����������в��ң��ҵ�����д�ӡ
	Node* p = phead;
	bool IsFind = false;//��¼�Ƿ��ҵ���ѧ�ŵ���Ϣ
	while (p != NULL)
	{
		if (stunum == p->stu._stunum)
		{
			printf("*********************************************************************************\n");
			printf("*\t����\t*\tѧ��\t*\t�����ɼ�\t*\tӢ��ɼ�\t*\tC���Գɼ�\t*\n");
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
			printf("������ѧ��������");
			scanf("%s", p->stu._name, sizeof(p->stu._name));
			printf("\n");
			printf("������ѧ�ţ�");
			scanf("%d", &p->stu._stunum);
			printf("\n");
			printf("����������ɼ���");
			scanf("%d", &p->stu._Math_score);
			printf("\n");
			printf("������Ӣ��ɼ���");
			scanf("%d", &p->stu._English_score);
			printf("\n");
			printf("������C���Գɼ���");
			scanf("%d", &p->stu._C_score);
			printf("\n");

			printf("ѧ����Ϣ�޸ĳɹ���ע�⼰ʱ����\n\n");

		}
		p = p->Next;
	}
	if (!IsFind)
		printf("ѧ������ϵͳ���޸�ѧ����Ϣ��\n\n");

	system("pause");
	system("cls");
}

//ɾ��ѧ����Ϣ
void DeleteStudent()
{
	//�����Բ���Ϊ�������ҵ�ѧ������ɾ��

	//��ѧ�Ų���
	int stunum;
	printf("������Ҫɾ����ѧ��ѧ�ţ�");
	scanf("%d", &stunum);
	printf("\n");
	//����������в��ң��ҵ�����д�ӡ
	Node* p = phead;
	Node* prev = phead;//����һ��ǰ��ָ���������p��ǰһ�����
	bool IsFind = false;//��¼�Ƿ��ҵ���ѧ�ŵ���Ϣ
	while (p != NULL)
	{
		if (stunum == p->stu._stunum)
		{
			printf("*********************************************************************************\n");
			printf("*\t����\t*\tѧ��\t*\t�����ɼ�\t*\tӢ��ɼ�\t*\tC���Գɼ�\t*\n");
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
			//�ҵ������ɾ�� ɾ�������������ͷ��㡢�м��㡢β���
			if (p == phead)
			{//ɾ��ͷ���
				phead = p->Next;
			}
			else if (p->Next == NULL)
			{//ɾ��β���
				p = prev;
				p->Next = NULL;
			}
			else
			{//ɾ���м���
				prev->Next = p->Next;
				delete p;
			}
			printf("ѧ����Ϣɾ���ɹ���ע�⼰ʱ����\n\n");
		}
		prev = p;
		p = p->Next;
	}
	if (!IsFind)
		printf("ѧ������ϵͳ���޸�ѧ����Ϣ��\n\n");

	system("pause");
	system("cls");
}

//ͳ����Ϣ
typedef struct Class
{//����һ��ѧ�ƽṹ�壬����ͳ��
	int Max = 0;//��߷�
	int a = 0,//����������
		b = 0,//60-69����
		c = 0,//70-79����
		d = 0,//80-89����
		e = 0;//90-100����

}Class;
void StatisticsStudent()
{
	//��Ҫͳ�Ƹ��Ƶ���߷֣�������60-69��70-79��80-89��90-100������
	Class Math, English, C;
	//��������
	if (phead == NULL)
	{
		printf("ϵͳ�������ݣ��޷�ͳ��\n");
		return;
	}
	Node* p = phead;
	while (p != NULL)
	{
		//������߷�ͳ��
		if (p->stu._Math_score > Math.Max)
			Math.Max = p->stu._Math_score;

		if (p->stu._English_score> English.Max)
			English.Max = p->stu._English_score;

		if (p->stu._C_score> C.Max)
			C.Max = p->stu._C_score;

		//�����ɼ��ĸ�������ͳ��
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
		
		//Ӣ��ɼ��ĸ�������ͳ��
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

		//C���Գɼ��ĸ�������ͳ��
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
	printf("*\t\t\t�����ɼ�����\t\t\t*\n");
	printf("*********************************************************************************\n");
	printf("������߷�Ϊ��%d\n", Math.Max);
	printf("*\t������\t*\t60-69\t*\t70-79\t*\t80-89\t*\t90-100\t*\n");
	printf("*********************************************************************************\n");
	printf("*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\n",Math.a,Math.b,Math.c,Math.d,Math.e);
	printf("*********************************************************************************\n\n");

	printf("*********************************************************************************\n");
	printf("*\t\t\tӢ��ɼ�����\t\t\t*\n");
	printf("*********************************************************************************\n");
	printf("Ӣ����߷�Ϊ��%d\n", English.Max);
	printf("*\t������\t*\t60-69\t*\t70-79\t*\t80-89\t*\t90-100\t*\n");
	printf("*********************************************************************************\n");
	printf("*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\n",English.a, English.b, English.c, English.d, English.e);
	printf("*********************************************************************************\n\n");
	
	printf("*********************************************************************************\n");
	printf("*\t\t\tC���Գɼ�����\t\t\t*\n");
	printf("*********************************************************************************\n");
	printf("C������߷�Ϊ��%d\n", C.Max);
	printf("*\t������\t*\t60-69\t*\t70-79\t*\t80-89\t*\t90-100\t*\n");
	printf("*********************************************************************************\n");
	printf("*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\t%d\t*\n",C.a, C.b, C.c, C.d, C.e);
	printf("*********************************************************************************\n\n");

	system("pause");
	system("cls");

}

/***************************�˵����桢������ʵ��*************************/

//�˵�
void Menu() 
{
	printf("*************************************************\n");
	printf("*\t��ӭʹ��ѧ���ɼ�����ϵͳ\t\t*\n");
	printf("*\t\t��ѡ����\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.¼��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t2.��ӡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t3.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t4.��ȡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t5.ͳ��ѧ���ɼ���Ϣ\t\t*\n");
	printf("*\t\t6.��ѯѧ����Ϣ\t\t\t*\n");
	printf("*\t\t7.�޸�ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t8.ɾ��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t0.�˳�ϵͳ\t\t\t*\n");
	printf("*************************************************\n");
}
//������
int main() 
{
	while (1)
	{
		//��ӡ�˵�
		Menu();
		//��switch caseʵ�ָ�����
		int n;
		scanf("%d", &n);
		switch (n)
		{
		case 1://1.¼��ѧ����Ϣ
			InputStudent();
			break;
		case 2://2.��ӡѧ����Ϣ
			PrintStudent();
			break;
		case 3://3.����ѧ����Ϣ
			SaveStudent();
			break;
		case 4://4.��ȡѧ����Ϣ
			ReadStudent();
			break;
		case 5://5.ͳ��ѧ���ɼ���Ϣ
			StatisticsStudent();
			break;
		case 6://6.����ѧ����Ϣ
			FindStudent();
			break;
		case 7://7.�޸�ѧ����Ϣ
			ChangeStudent();
			break;
		case 8://8.ɾ��ѧ����Ϣ
			DeleteStudent();
			break;
		case 0://0.�˳�ϵͳ
			printf("���˳�����ӭ�´�ʹ�ã�\n");
			return 0;
			break;
		default:
			printf("��������û�иù���\n\n");
			system("pause");  //��ͣ
			system("cls");    //����
			break;
		}
	}

	return 0;
}
