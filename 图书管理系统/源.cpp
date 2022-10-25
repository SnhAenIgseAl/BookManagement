#include <stdio.h>
#include <windows.h>
#include "BookManagement.h"

/*
 * 图书管理系统交互界面
 * 
 * @Author SnhAenIgseAl
 * @Date 2022.10.22
 * @Test SnhAenIgseAl
 */

int main()
{
	struct Book book;
	struct BookNode* B = InitBook();

	int ID;			//图书编号
	int number;		//图书数量
	int choose;		//操作选项

	//以下这几本书是我比较喜欢的
	book = { 101001, "麦克白", "莎士比亚", "小说", 38, 10 };
	AddBook(B, book);
	book = { 101002, "李尔王", "莎士比亚", "小说", 38, 10 };
	AddBook(B, book);
	book = { 102001, "项链", "莫泊桑", "小说", 48, 10 };
	AddBook(B, book);
	book = { 201001, "欺骗的艺术", "凯文·米特尼克", "人文社科", 48, 10 };
	AddBook(B, book);

	printf("-------------------------------------SnhAenIgseAl的图书馆--------------------------------------\n");
	PrintBookList(B);
	do
	{
		printf("请输入操作选项：\n");
		printf("1.添加图书信息\n");
		printf("2.按图书编号删除图书信息\n");
		printf("3.按图书编号更改图书信息\n");
		printf("4.按图书编号查询图书信息\n");
		printf("5.打印图书列表：\n");
		printf("6.借书\n");
		printf("7.还书\n");
		printf("8.退出\n");
		Line();

		scanf_s("%d", &choose);

		switch (choose)
		{
			case 1:
				printf("请输入图书ID、图书名称、图书作者、图书种类、图书价格、图书数量：\n");
				scanf_s("%d %s %s %s %f %d", &book.ID, book.name, MAX_NAME_LEN, book.author, MAX_KIND_LEN, book.kind, MAX_KIND_LEN, &book.price, &book.number);
				AddBook(B, book);
				PrintBookList(B);
				break;

			case 2:
				printf("请输入要删除的图书编号：");
				scanf_s("%d", &ID);
				DeleteBookByID(B, ID);
				break;

			case 3:
				printf("请输入要更改后的图书ID、图书名称、图书种类、图书价格、图书数量：\n");
				scanf_s("%d %s %s %s %f %d", &book.ID, book.name, MAX_NAME_LEN, book.author, MAX_KIND_LEN, book.kind, MAX_KIND_LEN, &book.price, &book.number);
				ChangeBookDataByID(B, book.ID, book.name, book.author, book.kind, book.price, book.number);
				break;

			case 4:
				printf("请输入要查找的图书编号：");
				scanf_s("%d", &ID);
				SelectBookDataByID(B, ID);
				break;

			case 5:
				PrintBookList(B);
				break;

			case 6:
				printf("请输入要借阅的图书编号及数量：");
				scanf_s("%d %d", &ID, &number);
				BorrowBook(B, ID, number);
				break;

			case 7:
				printf("请输入要归还的图书编号及数量：");
				scanf_s("%d %d", &ID, &number);
				ReturnBooK(B, ID, number);
				break;

			case 8:
				exit(0);
				break;

			default:
				printf("输入的操作选项不存在\n");
				break;
		}

	} while (choose != 8);

	system("pause");
	return 0;
}