#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAX_VERTEX_NUM 10	//�������
#define NAME_LEN 20			//���Ƴ���
#define NUM_LEN 5			//���ų���
#define INTRO_LEN 50		//���ܳ���
#define INF 32768
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

typedef struct ArcData
{
	int start; // �ߵ����
	int end;   // �ߵ��յ�
	int distance; // �ߵ�Ȩֵ
}ArcData;

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
	creatVertex(&v[0], "001", "����", "ѧ����ְ������ͨ��");
	creatVertex(&v[1], "002", "ͼ���", "*****************");
	creatVertex(&v[2], "***", "�����ѧԺ¥", "*****************");
	creatVertex(&v[3], "***", "��ѧ¥", "*****************");
	creatVertex(&v[4], "***", "����¥", "*****************");
	creatVertex(&v[5], "***", "��ʳ��", "*****************");
	creatVertex(&v[6], "***", "����¥", "*****************");
	creatVertex(&v[7], "***", "����", "*****************");
	creatVertex(&v[8], "***", "�ﾶ�˶���", "*****************");
	creatVertex(&v[9], "***", "УҽԺ", "*****************");
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
		for ( j = 0; j < G->vexnum; j++)
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

///*�󶥵�λ��*/
//int LocateVertex(AdjMatrix* G, VertexData v) 
//{
//	int k;
//	for (k = 0; k < G->vexnum; k++) {
//		if (G->vertex[k].num == v.num)
//			break;
//	}
//	return k;
//}
//
//// ���ض���v�ĵ�һ���ڽӶ����������ʧ���򷵻�-1
//int first_vertex(AdjMatrix* G, int v)
//{
//	int i;
//
//	if (v<0 || v>(G->vexnum - 1))
//		return -1;
//
//	for (i = 0; i < G->vexnum; i++)
//		if ( G->arcs[v][i].distance != INF)
//			return i;
//
//	return -1;
//}
////���ض���v�����w����һ���ڽӶ����������ʧ���򷵻�-1
//int next_vertix(AdjMatrix* G, int v, int w)
//{
//	int i;
//
//	if (v<0 || v>(G->vexnum - 1) || w<0 || w>(G->vexnum - 1))
//		return -1;
//
//	for (i = w + 1; i < G->vexnum; i++)
//		if (G->arcs[v][i].distance != INF)
//			return i;
//
//	return -1;
//}
////��ȡͼ�еı�
//ArcData* get_edges(AdjMatrix* G)
//{
//	int i, j;
//	int index = 0;
//	ArcData* edges;
//
//	edges = (ArcData*)malloc(G->arcnum * sizeof(ArcData));
//	for (i = 0; i < G->vexnum; i++)
//	{
//		for (j = i + 1; j < G->vexnum; j++)
//		{
//			if (G->arcs[i][j].distance != INF)
//			{
//				edges[index].start = G->vertex[i].num;
//				edges[index].end = G->vertex[j].num;
//				edges[index].distance = G->arcs[i][j].distance;
//				index++;
//			}
//		}
//	}
//	return edges;
//}
////�Ա߰���Ȩֵ����
//void sorted_edges(ArcData* edges, int elen)
//{
//	int i, j;
//
//	for (i = 0; i < elen; i++)
//	{
//		for (j = i + 1; j < elen; j++)
//		{
//			if (edges[i].distance > edges[j].distance)
//			{
//				// ����"��i����"��"��j����"
//				ArcData tmp = edges[i];
//				edges[i] = edges[j];
//				edges[j] = tmp;
//			}
//		}
//	}
//}
//
//// ��ȡi���յ�
//int get_end(int vends[], int i)
//{
//	while (vends[i] != 0)
//		i = vends[i];
//	return i;
//}



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
	printf("\t\t\t  *      <8>�ﾶ�˶���            <9>УҽԺ           *\n");
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
	printf("\t\t\t  *                4.��ʾfloyd���ɵ�path����           *\n");
	printf("\t\t\t  *                5.��ʾfloyd���ɵ�dist����           *\n");
	printf("\t\t\t  *                6.�˳�                              *\n");
	printf("\t\t\t  ******************************************************\n");
	printf("������������Ҫʹ�õĹ��ܵ���ţ�");
	scanf("%d", &chose);
	return chose;
}

//"��ѯ���·��" ��������յ�����뼰ѡ��Ϸ����ж�
void Decision_Input(int a[2])
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



void main()
{
	int chose, flag = 1;
	AdjMatrix G;
	int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = { 0 };    // ���ڱ���floyd·��
	int dist[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = { 0 };    // ���ڱ���floyd����
	create_example_graph(&G);//����ͼ�Ĵ���
	floyd(&G, path, dist);

	WelcomeMenu();
	while (flag)
	{
		chose = sysMenu();
		switch (chose)
		{
		case 1: //��ѯ�ص���Ϣ
			system("cls");
			list();
			int x;
			printf("������Ҫ���ҵĵص����:");
			scanf("%d", &x);
			print_vertexData(&G, x);
			break;
		case 2://��ѯ�����������·��
			system("cls");
			list();
			int a[2] = {0};
			int start, end;
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
		case 4://��ʾfloyd���ɵ�path����
			system("cls");
			list();
			showPath(path);
			system("pause");
			break;
		case 5://��ʾfloyd���ɵ�dist���� 
			system("cls");
			list();
			showDist(dist);
			system("pause");
			break;
		default:
			flag = 0;
			break;
		}
	}

}


