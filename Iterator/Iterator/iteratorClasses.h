#ifndef ITERATORCLASSES_H
#define ITERATORCLASSES_H

#include <String>
#include <iostream>
#include <iomanip>
#include <io.h>

using namespace std;

class FileItem {
public:
	string fname; // �������� �����
	bool isDir;   // 1 - ����������; 0 - ����
	string fMask; // ���� � ����� ��� ����������
};

class Iterator {
	Iterator *it;
	FileItem *cache;
	string Mask;
	string name;
	intptr_t hFind;

	bool comparison(FileItem*); // ��������� cash->fname � name, 1 - ����� 0 - �� �����
	FileItem* searchInDir(); // ���� ��������� ����/������� ������ Mask (0 - ����, 1 - ����������)
	FileItem* doSearch(); // ���� ������ Mask � ������������ ��������� ����, �������.name

public:
	Iterator() : name("*"), it(NULL), hFind(NULL), cache(NULL) {}
	Iterator(string mask);
	~Iterator();

	bool hasMore();   // ���� �� ���� �� ���� Mask
	FileItem* next();// ���������� � ��������� � ��������� ����� � ��������� name �� ���� Mask

	void get();
};
#endif // ITERATORCLASSES_H
