#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAX_VERTEX_NUM 10	//�������
#define NAME_LEN 20			//���Ƴ���
#define NUM_LEN 5			//���ų���
#define INTRO_LEN 50		//���ܳ���
#define INF 32768

typedef struct zhanghu
{
	char admin[20];
	char password[20];
};//�˻��ṹ����


/*��������ͼ���ڽӾ���洢��*/
typedef struct
{
	char name[NAME_LEN];//��������
	char num[NUM_LEN];				//�������
	char intro[INTRO_LEN];//�������
}VertexData;//��������
typedef int AdjType;
typedef struct ArcNode
{
	AdjType distance;		//ȨֵΪ·�߳���
}ArcNode;
typedef struct
{
	VertexData vertex[MAX_VERTEX_NUM];		//��������
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ���
	int vexnum, arcnum;						//ͼ�Ķ������ͻ���
}AdjMatrix;

/*�����ʼ��*/
//num:������ţ�name:�������ƣ�intro:�������
void creatVertex(VertexData* v, char num[], char name[NAME_LEN], char intro[INTRO_LEN]);
void initVertex(VertexData v[]);//����creatVertex()������ʼ��������Ϣ
void create_example_graph(AdjMatrix* G);//�����ڽӾ���
void print_graph(AdjMatrix* G);//�ڽӾ������
void print_vertexData(AdjMatrix* G, int i);//���������Ϣ
void floyd(AdjMatrix* G, int path[][MAX_VERTEX_NUM], int dist[][MAX_VERTEX_NUM]);//floyd���·��
void showDist(int dist[MAX_VERTEX_NUM][MAX_VERTEX_NUM]);
void showPath(int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM]);
void printMinLoad(AdjMatrix* G, int  dist[10][10], int  path[10][10], int start, int end);//���·�����
void Decision_Input(int a[]);//"��ѯ���·��" ��������յ�����뼰ѡ��Ϸ����ж�
void zhuce();//ע��
int denglu();//��¼
int menu_1();//�˻������˵�
void WelcomeMenu();//��ӭ�˵�
void list();//�ص��嵥
int sysMenu();//ϵͳ�˵�



int main()
{
	int choose1, choose2, flag1 = 1, flag2 = 1;

	int t;
	char pic_name[80] = "school.jpg";
	char cmd[100];

	int i;
	int a[2] = { 0 };
	int x;
	int start, end;
	AdjMatrix G;
	int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = { 0 };    // ���ڱ���floyd·��
	int dist[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = { 0 };    // ���ڱ���floyd����
	create_example_graph(&G);//����ͼ�Ĵ���
	floyd(&G, path, dist);

	WelcomeMenu();

	while (flag1 == 1)
	{
		choose1 = menu_1();
		switch (choose1)
		{
		case 1:
			t = denglu();
			if (t == -1)
				return;
			else if (t == 1)
			{
				flag1 = 0;
				system("pause");
			}
			break;

		case 2:zhuce(); break;
		case 0:
			printf("�˳�\n");
			system("pause");
			exit(0);
		default:system("cls"); printf("û�����ѡ�\n");
		}
	}


	while (flag2 == 1)
	{
		choose2 = sysMenu();
		switch (choose2)
		{
		case 1: //��ѯ�ص���Ϣ
			system("cls");
			list();
			printf("������Ҫ���ҵĵص����:");
			scanf("%d", &x);
			print_vertexData(&G, x);
			break;
		case 2://��ѯ�����������·��
			system("cls");
			list();
			Decision_Input(a);
			start = a[0];
			end = a[1];
			printMinLoad(&G, dist, path, start, end);
			system("pause");
			break;
		case 3://����ڽӾ���
			system("cls");
			list();
			print_graph(&G);
			system("pause");
			break;
		case 4://��ʾfloyd���ɵ�path,dist����
			system("cls");
			list();
			showPath(path);
			showDist(dist);
			system("pause");
			break;
		case 5://��ʾѧУ����ͼ
			sprintf(cmd, pic_name);
			system(cmd);
			printf("��ͼ����ʾ\n");
			system("pause");
			break;
		case 0://�˳� 
			system("cls");
			list();
			printf("�˳�\n");
			flag2 = 0;
			system("pause");
			break;
		default:
			printf("û�����ѡ��\n");
			system("pause");
			break;
		}
	}
	return 0;
}



/*�����ʼ��*/
//num:������ţ�name:�������ƣ�intro:�������
void creatVertex(VertexData* v, char num[], char name[NAME_LEN], char intro[INTRO_LEN])
{
	strcpy(v->num, num);
	strcpy(v->name, name);
	strcpy(v->intro, intro);
}

void initVertex(VertexData v[])
{
	//����creatVertex()������ʼ��������Ϣ
	creatVertex(&v[0], "000", "����", "ѧ����ְ������ͨ��");
	creatVertex(&v[1], "001", "ͼ���", "�����鼮֮�أ�ӵ�б��������Ļ��Ų���������Ϣ��Դ��������������ְ�ܡ�");
	creatVertex(&v[2], "002", "�����ѧԺ¥", "ӵ�м����ϵ�칫�ң������ҵȳ����ļ�����ۺ��Դ�¥��");
	creatVertex(&v[3], "003", "��ѧ¥", "��������֮�ء�");
	creatVertex(&v[4], "004", "����¥", "����ѧ����ѧ����ѧ����ʷ ��������ѧ������������ѧ�ƣ�������ѧ�����С��칫�����顢ͼ���������ۺϹ��ܴ�¥��");
	creatVertex(&v[5], "005", "��ʳ��", "ʳ���ﲻ������������ʳ����Ϊ��ʡѧ���ṩ���ڸ�����ɫ������");
	creatVertex(&v[6], "006", "����¥", "ѧ����Ϣ֮�����ϴ����������ÿյ����������ʡ�");
	creatVertex(&v[7], "007", "����", "ѧ����ԡ֮����Լ����ʮ�����䣬������ԡƽ��Լ���顣");
	creatVertex(&v[8], "008", "�ﾶ�˶���", "ѧ���˶�֮�������������˶���ѧҵ��æ֮�ʶ�������Ķ���Ҳ����и����");
	creatVertex(&v[9], "009", "УҽԺ", "���õ�����ҽ����Ա���ɱ���ѧ�����彡���ķ��ߡ�");
}


//�����ڽӾ���
void create_example_graph(AdjMatrix* G)
{
	int matrix[][10] = {
		/*0*//*1*//*2*//*3*//*4*//*5*//*6*//*7*//*8*//*9*/
		/*0*/ { 0, 400,  INF, 270, 210,INF, INF, INF, INF, INF },
		/*1*/ { 400, 0,  INF, 300, 250,270, 400, INF, 460, INF },
		/*2*/ { INF, INF,  0, 150, INF,INF, INF, INF, 580, INF },
		/*3*/ { 270, 300,  150, 0, INF,INF, INF, INF, INF, INF },
		/*4*/ { 210, 250,  INF, INF, 0,INF, INF, 850, INF, INF },
		/*5*/ { INF, 270,  INF, INF, INF,0, 200, INF, INF, INF },
		/*6*/ { INF, 400,  INF, INF, INF,200, 0, 180, 300, 380 },
		/*7*/ { INF, INF,  INF, INF, 850,INF, 180, 0, INF, INF },
		/*8*/ { INF, 460,  580, INF, INF,INF, 300, INF, 0, 380 },
		/*9*/ { INF, INF,  INF, INF, INF,INF, 380, INF, 380, 0 } };
	int i, j;

	// ��ʼ��"������"
	G->vexnum = MAX_VERTEX_NUM;
	G->arcnum = 15;
	// ��ʼ��"����"
	initVertex(G->vertex);

	//��ʼ����
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].distance = matrix[i][j];
		}
	}

}


//�ڽӾ������
void print_graph(AdjMatrix* G)
{
	int i, j;

	printf("Martix Graph:\n");
	printf("   ");
	for (i = 0; i < MAX_VERTEX_NUM; i++)
	{
		printf(" (%d) ", i);
		if (i == MAX_VERTEX_NUM - 1)
		{
			printf("\n");
		}
	}

	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			if (j == 0)
			{
				printf("(%d)", i);
			}
			if (G->arcs[i][j].distance == INF) {
				printf("%4c ", '-');
			}
			else { printf("%4d ", G->arcs[i][j].distance); }

		}

		printf("\n");
	}
}

//���������Ϣ
void print_vertexData(AdjMatrix* G, int i)
{
	printf("���:%s\n", G->vertex[i].num);
	printf("����:%s\n", G->vertex[i].name);
	printf("���:%s\n\n", G->vertex[i].intro);
	system("pause");
}


/*
 * floyd���·����
 *
 * ����˵����
 *        G -- ͼ
 *     path -- ·����path[i][j]=k��ʾ��"����i"��"����j"�����·���ᾭ������k��
 *     dist -- �������顣����dist[i][j]=n��ʾ��"����i"��"����j"�����·���ĳ�����n��
 */
void floyd(AdjMatrix* G, int path[][MAX_VERTEX_NUM], int dist[][MAX_VERTEX_NUM])
{
	int i, j, k, v, w;

	// ��ʼ��
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			dist[i][j] = G->arcs[i][j].distance;    // "����i"��"����j"��·������Ϊ"i��j��Ȩֵ"��
			path[i][j] = j;                 // "����i"��"����j"�����·���Ǿ�������j��
		}
	}


	for (k = 0; k < G->vexnum; k++)
	{
		for (v = 0; v < G->vexnum; v++)
		{
			for (w = 0; w < G->vexnum; w++)
			{
				if (dist[v][w] > (dist[v][k] + dist[k][w]))
				{//��������±�Ϊk����·����ԭ�����·�����̣�����ǰ�����Ȩֵ��Ϊ��С��һ�� 
					dist[v][w] = dist[v][k] + dist[k][w];
					path[v][w] = path[v][k];
				}

			}
		}
	}

}

void showDist(int dist[MAX_VERTEX_NUM][MAX_VERTEX_NUM])
{
	int i, j;
	printf("ͨ��floyd�õ���Dist��������:\n");
	printf("  dist[i][j]��ʾ����i������j��·������Ϊdist[i][j]\n");
	printf("    ");
	for (i = 0; i < MAX_VERTEX_NUM; i++)
	{
		printf(" (%d) ", i);
		if (i == MAX_VERTEX_NUM - 1)
		{
			printf("\n");
		}
	}
	for (i = 0; i < MAX_VERTEX_NUM; i++)
	{
		for (j = 0; j < MAX_VERTEX_NUM; j++)
		{
			if (j == 0)
				printf("(%d)", i);
			printf("%5d", dist[i][j]);
		}
		printf("\n");
	}
}

void showPath(int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM])
{
	int i, j;
	printf("ͨ��floyd�õ���Path��������:\n");
	printf("  path[i][j]��ʾ����i������j�����·���Ǿ�������path[i][j]��\n");
	printf("    ");
	for (i = 0; i < MAX_VERTEX_NUM; i++)
	{
		printf("(%d)", i);
		if (i == MAX_VERTEX_NUM - 1)
		{
			printf("\n");
		}
	}
	for (i = 0; i < MAX_VERTEX_NUM; i++)
	{
		for (j = 0; j < MAX_VERTEX_NUM; j++)
		{
			if (j == 0)
				printf("(%d)", i);
			printf("%3d", path[i][j]);
		}

		printf("\n");
	}
}

//"��ѯ���·��" ��������յ�����뼰ѡ��Ϸ����ж�
void Decision_Input(int a[])
{

	while (1)
	{
		while (1)
		{
			printf("������������:");
			scanf("%d", &a[0]);
			if (a[0] >= 0 && a[0] <= 9)
			{
				break;
			}
			else
			{
				system("cls");
				list();
				printf("���������㳬����Χ,����������\n");

			}
		}

		while (1)
		{
			printf("�������յ����:");
			scanf("%d", &a[1]);
			if (a[1] >= 0 && a[1] <= 9)
			{
				break;
			}
			else
			{
				printf("��������յ㳬����Χ,����������\n");

			}
		}
		if (a[0] == a[1])
		{
			system("cls");
			list();
			printf("������յ㲻����ͬ,����������\n");

		}
		else
		{
			break;
		}
	}

}
//���·�����
void printMinLoad(AdjMatrix* G, int  dist[10][10], int  path[10][10], int start, int end)
{
	int k, i = start, j = end;
	printf("��ѯ�ɹ���\n");
	printf("%s-->%s �����·��Ϊ:%d��", G->vertex[i].name, G->vertex[j].name, dist[i][j]);
	k = path[i][j];
	printf("\n·��Ϊ:%s", G->vertex[i].name);
	while (k != j)
	{
		printf("->%s", G->vertex[k].name);
		k = path[k][j];
	}
	printf("->%s\n", G->vertex[j].name);
}

/*��¼ע��*/
void zhuce()
{
	FILE* fp;
	char yhm[20], mima_0[20], mima_1[20];
	struct zhanghu s;
	struct zhanghu* p = &s;
	int t = 0, i, m = 0;
	do {
		printf("�������û�����\n");
		scanf("%s", yhm);
		printf("���������룺\n");
		scanf("%s", mima_0);
		printf("����һ���������룺\n");
		scanf("%s", mima_1);
		if (strcmp(mima_0, mima_1) == 0)
		{
			system("cls");
			printf("ע��ɹ���\n");
			t = 1;
			break;
		}
		else
		{
			m++;
			if (m > 2) { system("cls"); printf("����3�����벻һ�£����˳��˲�����\n"); }
			else printf("���벻һ�£����������룺\n");
		}
	} while (t == 0 && m < 3);
	/***********���浽�˻��ļ�**************************************/
	if (m < 3)
	{
		for (i = 0; mima_0[i] != '\0'; i++)
			mima_0[i] += 10;                                     //�������
		strcpy(p->admin, yhm);		strcpy(p->password, mima_0);
		if ((fp = fopen("zhanghu.txt", "ab")) == NULL)
		{
			printf("cuowu0"); exit(0);
		}
		if ((fwrite(&s, sizeof(struct zhanghu), 1, fp)) != 1)
		{
			printf("д�����ݴ���"); exit(0);
		}
		fclose(fp);
	}
}

int denglu()
{
	struct zhanghu read;
	struct zhanghu* p = &read;
	char yhm[20], mima[20];
	FILE* fp;
	int n = 0, i, j, t = 0;
	if ((fp = fopen("zhanghu.txt", "rb")) == NULL)
	{
		system("cls");
		printf("�������˻����ݣ���ע��\n"); return 0;
	}
	for (i = 4; i >= 0; i--)
	{
		printf("�������û�����\n");
		scanf("%s", yhm);
		printf("���������룺\n");
		scanf("%s", mima);
		rewind(fp);
		while (t == 0 && fp != NULL && n == 0)
		{
			if ((fread(&read, sizeof(struct zhanghu), 1, fp)) != NULL)
			{
				if (strcmp(p->admin, yhm) == 0)
				{
					t = 1; n = 1;
					for (j = 0; p->password[j] != '\0'; j++)
						p->password[j] -= 10;					//�������
					if (strcmp(p->password, mima) == 0)
					{
						system("cls");
						printf("��¼�ɹ������������ʼʹ��ϵͳ\n");
						return 1;
					}
					else
					{
						n = 0; t = 0;
						if (i == 4)
						{
							system("cls");
							printf("�û�������������������������룡\n");
						}
						else
						{
							system("cls");
							printf("��¼ʧ�ܣ�������%d�λ��ᣡ\n", i);
							if (i == 0)
							{
								printf("������������࣬��ǿ���˳���");

								return -1;
							}
						}
						break;
					}
				}
			}
			else
			{
				system("cls");
				printf("���˻������ڣ�\n");
				return 0;
			}
		}
	}
	fclose(fp);
}


void WelcomeMenu()
{
	printf("\n\n\n");
	printf("\t\t\t  ******************************************************\n");
	printf("\t\t\t  *           ��ӭʹ���������̴�ѧУ԰����ϵͳ         *\n");
	printf("\t\t\t  ******************************************************\n");
	printf("\t\t\t  *****************���ߣ���𿡣�¬����*****************\n");
	printf("\t\t\t  ******************************************************\n");
	system("pause");
	system("cls");
}

int menu_1()
{
	int n;
	printf("\t\t\t\t********************************\n");
	printf("\t\t\t\t*           1.��¼             *\n");
	printf("\t\t\t\t*           2.ע��             *\n");
	printf("\t\t\t\t*           0.�˳�             *\n");
	printf("\t\t\t\t********************************\n");
	printf("����������ѡ��");
	scanf("%d", &n);
	return n;
}

void list()
{

	printf("\n");
	printf("\t\t\t  * * * * * * * * * * * * * ** * * * * * * * * * * * * *\n");
	printf("\t\t\t  *                       �ص��б�                     *\n");
	printf("\t\t\t  ******************************************************\n");
	printf("\t\t\t  *      <0>����                  <1>ͼ���            *\n");
	printf("\t\t\t  *      <2>�������ѧѧԺ        <3>��ѧ¥Ⱥ          *\n");
	printf("\t\t\t  *      <4>����¥                <5>��ʳ��            *\n");
	printf("\t\t\t  *      <6>ѧ������¥Ⱥ          <7>����              *\n");
	printf("\t\t\t  *      <8>�ﾶ�˶���            <9>УҽԺ            *\n");
	printf("\t\t\t  ******************************************************\n");
	printf("\n");
}

//ϵͳ����
int sysMenu()
{
	int chose;
	system("cls");
	list();
	printf("\t\t\t  ******************************************************\n");
	printf("\t\t\t  *                         �˵�                       *\n");
	printf("\t\t\t  *                1.��ѯ�ص���Ϣ                      *\n");
	printf("\t\t\t  *                2.��ѯ���·��                      *\n");
	printf("\t\t\t  *                3.��ʾ�ڽӾ���                      *\n");
	printf("\t\t\t  *                4.��ʾpath�����dist����            *\n");
	printf("\t\t\t  *                5.��ʾѧУ���׵�ͼ                  *\n");
	printf("\t\t\t  *                0.�˳�                              *\n");
	printf("\t\t\t  ******************************************************\n");
	printf("������������Ҫʹ�õĹ��ܵ���ţ�");
	scanf("%d", &chose);
	return chose;
}