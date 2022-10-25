#include <stdio.h>
#include <windows.h>
#include "BookManagement.h"

/*
 * ͼ�����ϵͳ��������
 * 
 * @Author SnhAenIgseAl
 * @Date 2022.10.22
 * @Test SnhAenIgseAl
 */

int main()
{
	struct Book book;
	struct BookNode* B = InitBook();

	int ID;			//ͼ����
	int number;		//ͼ������
	int choose;		//����ѡ��

	//�����⼸�������ұȽ�ϲ����
	book = { 101001, "��˰�", "ɯʿ����", "С˵", 38, 10 };
	AddBook(B, book);
	book = { 101002, "�����", "ɯʿ����", "С˵", 38, 10 };
	AddBook(B, book);
	book = { 102001, "����", "Ī��ɣ", "С˵", 48, 10 };
	AddBook(B, book);
	book = { 201001, "��ƭ������", "���ġ��������", "�������", 48, 10 };
	AddBook(B, book);

	printf("-------------------------------------SnhAenIgseAl��ͼ���--------------------------------------\n");
	PrintBookList(B);
	do
	{
		printf("���������ѡ�\n");
		printf("1.���ͼ����Ϣ\n");
		printf("2.��ͼ����ɾ��ͼ����Ϣ\n");
		printf("3.��ͼ���Ÿ���ͼ����Ϣ\n");
		printf("4.��ͼ���Ų�ѯͼ����Ϣ\n");
		printf("5.��ӡͼ���б�\n");
		printf("6.����\n");
		printf("7.����\n");
		printf("8.�˳�\n");
		Line();

		scanf_s("%d", &choose);

		switch (choose)
		{
			case 1:
				printf("������ͼ��ID��ͼ�����ơ�ͼ�����ߡ�ͼ�����ࡢͼ��۸�ͼ��������\n");
				scanf_s("%d %s %s %s %f %d", &book.ID, book.name, MAX_NAME_LEN, book.author, MAX_KIND_LEN, book.kind, MAX_KIND_LEN, &book.price, &book.number);
				AddBook(B, book);
				PrintBookList(B);
				break;

			case 2:
				printf("������Ҫɾ����ͼ���ţ�");
				scanf_s("%d", &ID);
				DeleteBookByID(B, ID);
				break;

			case 3:
				printf("������Ҫ���ĺ��ͼ��ID��ͼ�����ơ�ͼ�����ࡢͼ��۸�ͼ��������\n");
				scanf_s("%d %s %s %s %f %d", &book.ID, book.name, MAX_NAME_LEN, book.author, MAX_KIND_LEN, book.kind, MAX_KIND_LEN, &book.price, &book.number);
				ChangeBookDataByID(B, book.ID, book.name, book.author, book.kind, book.price, book.number);
				break;

			case 4:
				printf("������Ҫ���ҵ�ͼ���ţ�");
				scanf_s("%d", &ID);
				SelectBookDataByID(B, ID);
				break;

			case 5:
				PrintBookList(B);
				break;

			case 6:
				printf("������Ҫ���ĵ�ͼ���ż�������");
				scanf_s("%d %d", &ID, &number);
				BorrowBook(B, ID, number);
				break;

			case 7:
				printf("������Ҫ�黹��ͼ���ż�������");
				scanf_s("%d %d", &ID, &number);
				ReturnBooK(B, ID, number);
				break;

			case 8:
				exit(0);
				break;

			default:
				printf("����Ĳ���ѡ�����\n");
				break;
		}

	} while (choose != 8);

	system("pause");
	return 0;
}