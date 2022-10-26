#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 50
#define MAX_KIND_LEN 30

/*
 * 图书管理系统头文件
 * 所有函数操作均以图书编号为主键
 * 
 * @Author SnhAenIgseAl
 * @Date 2022.10.22
 * @Test SnhAenIgseAl
 * @version 0.1.0 on 2022.10.22 
 *		完成增删改查
 * 
 * @version 0.1.1 on 2022.10.23 
 *		优化图书信息输出对齐格式
 * 
 * @version 0.2.0 on 2022.10.24
 *		添加借书和还书功能
 *		添加了一个彩蛋
 *		添加了几本我比较喜欢的书
 *		修复已知BUG
 *		已摆烂
 */

//图书结构
struct Book
{
	int ID;				//图书编号
	char name[MAX_NAME_LEN];	//图书名称
	char author[MAX_KIND_LEN];	//图书作者
	char kind[MAX_KIND_LEN];	//图书分类
	float price;			//图书价格
	int number;			//图书数量
};

//BookNode结点
struct BookNode
{
	struct Book data;		//图书数据
	struct BookNode* next;		//指向下一个Book结点
};

/*
 * 分割线
 */
void Line()
{
	printf("-----------------------------------------------------------------------------------------------\n");
}

/*
 * 图书信息列表栏目输出规范
 */
void StandardBookTap()
{
	printf("\n");
	Line();
	printf("%-15s", "图书编号");
	printf("%-30s", "图书名称");
	printf("%-20s", "图书作者");
	printf("%-10s", "图书种类");
	printf("%10s", "图书价格");
	printf("%10s\n", "图书数量");
	Line();
}

/*
 * 图书信息格式输出规范
 * @param BookNode* 目标链表
 */
void StandardPrint(struct BookNode* B)
{
	printf("%-15d%-30s%-20s%-10s%10.2f%10d\n", B->data.ID, B->data.name, B->data.author, B->data.kind, B->data.price, B->data.number);
}

/*
 * 打印图书列表
 * @param BookNode* 目标链表
 */
void PrintBookList(struct BookNode* B)
{
	//跳过头结点
	B = B->next;

	StandardBookTap();

	while (B != NULL)
	{
		StandardPrint(B);
		B = B->next;
	}
	Line();
	printf("\n");
}

/*
 * 初始化头结点，头结点的图书信息作为彩蛋
 * @return BookNode* book结点
 */
struct BookNode* InitBook()
{
	struct BookNode* book = (struct BookNode*)malloc(sizeof(struct BookNode));

	if (book == NULL)
	{
		printf("结点内存分配失败\n");
		exit(0);
	}

	book->data.ID = -0x194;
	strcpy_s(book->data.name, "岁月史书");
	strcpy_s(book->data.author, "\u26E7");
	strcpy_s(book->data.kind, "\uFFEF\uFFEF\uFFEF");
	book->data.price = 666;
	book->data.number = 1;
	book->next = NULL;

	return book;
}

/*
 * 创建BookNode结点
 * @return BookNode* 结点
 */
struct BookNode* CreateBookNode(struct Book data)
{
	struct BookNode* newNode = (struct BookNode*)malloc(sizeof(struct BookNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

/*
 * 暴力遍历查找图书信息是否存在
 * @param BookNode* 目标链表
 * @param int 编号
 * @return BookNode* 存在
 * @return NULL 不存在
 */
struct BookNode* isFindBook(struct BookNode* B, int id)
{
	while (B != NULL)
	{
		if (B->data.ID == id)
		{
			return B;
			break;
		}
		else
		{
			B = B->next;
		}
	}

	return NULL;
}

/*
 * 尾插法添加图书信息
 * @param BookNode* 目标链表
 * @param Book* 图书数据
 */
void AddBook(struct BookNode* B, struct Book data)
{
	if (isFindBook(B, data.ID))
	{
		printf("添加图书信息失败，图书编号不能重复\n");
	}
	else 
	{
		struct BookNode* p = B;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = CreateBookNode(data);
	}
}

/*
 * 按图书编号删除图书信息
 * @param BookNode* 目标链表
 * @param int 编号
 */
void DeleteBookByID(struct BookNode* B, int id)
{
	struct BookNode* p = B;
	struct BookNode* last = B;

	if (id == -0x194)
	{
		printf("删除成?失败%c图书编号不存在¿\n", 0xB2);
		printf("You can't destroy me...\n\n");
	}
	else
	{
		if (isFindBook(p, id))
		{
			while (p != NULL)
			{
				if (p->data.ID == id)
				{
					last->next = p->next;
					free(p);
					p = NULL;
					printf("删除成功\n");
					PrintBookList(B);
					printf("\n");
					break;
				}
				else
				{
					last = p;	//记录上一个结点的地址
					p = p->next;
				}
			}
		}
		else
		{
			printf("删除失败，图书编号不存在\n\n");
		}
	}
}

/*
 * 更改图书信息
 * @param BookNode* 目标链表
 * @param int 图书编号
 * @param char[] 图书名称
 * @param char[] 图书种类
 * @param float 图书价格
 * @param int 图书数量
 */
void ChangeBookDataByID(struct BookNode* B, int id, char name[], char author[], char kind[], float price, int number)
{
	//跳过头结点
	B = B->next;

	if (B = isFindBook(B, id))
	{
		strcpy_s(B->data.name, name);
		strcpy_s(B->data.author, author);
		strcpy_s(B->data.kind, kind);
		B->data.price = price;
		B->data.number = number;
		printf("更改成功\n");
		StandardBookTap();
		StandardPrint(B);
		Line();
		printf("\n");
	}
	else
	{
		printf("更改失败，图书编号不存在\n\n");
	}
}

/*
 * 根据图书编号查询图书信息
 * @param BookNode* 目标链表
 * @param int 编号
 */
void SelectBookDataByID(struct BookNode* B, int id)
{
	if (B = isFindBook(B, id))
	{
		printf("查找成功\n");
		StandardBookTap();
		StandardPrint(B);
		Line();
		if (id == -0x194 && B->data.number == 1)
		{
			printf("Take me out...\n");
		}
		printf("\n");
	}
	else
	{
		printf("查找失败，图书编号不存在\n\n");
	}
}

/*
 * 根据图书编号借书
 * @param BookNode* 目标链表
 * @param int 编号
 * @param int 数量
 */
void BorrowBook(BookNode* B, int id, int number)
{
	if (id == -0x194)
	{
		if (B->data.number - number >= 0)
		{
			printf("借书成功\n");
			B->data.number = 0;
			StandardBookTap();
			StandardPrint(B);
			Line();
			printf("So, you wanna tamper the history¿\n");
			printf("\n");
		}
		else
		{
			printf("借书失败，图书库存数量不足\n\n");
		}
	}
	else
	{
		//跳过头结点
		B = B->next;

		if (B = isFindBook(B, id))
		{
			if (B->data.number - number >= 0)
			{
				printf("借书成功\n");
				B->data.number = B->data.number - number;
				StandardBookTap();
				StandardPrint(B);
				Line();
			}
			else
			{
				printf("借书失败，图书库存数量不足\n\n");
			}
		}
		else
		{
			printf("借书失败，图书编号不存在\n\n");
		}
	}
}

/*
 * 根据图书编号还书
 * @param BookNode* 目标链表
 * @param int 编号
 * @param int 数量
 */
void ReturnBooK(struct BookNode* B, int id, int number)
{
	struct BookNode* head = B;
	
	if (id ==- 0x194 && head->data.number == 1)
	{
		printf("还书成?失败%c图书编号不存在¿\n", 0xB2);
		printf("Anthor one? Uh, I'm the only one.\n\n");
	}
	else if (id == -0x194 && head->data.number == 0)
	{
		printf("还书成?失败%c图书编号不存在¿\n", 0xB2);
		printf("Now I'm yours, MASTER...\n\n");
	}
	else
	{
		if (B = isFindBook(B, id))
		{
			printf("还书成功\n");
			B->data.number = B->data.number + number;
			StandardBookTap();
			StandardPrint(B);
			Line();
			printf("\n");
		}
		else
		{
			printf("还书失败，图书编号不存在\n\n");
		}
	}
}
