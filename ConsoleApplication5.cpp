// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string>
#include <string.h>
#include <iostream>
using namespace std;

class Doc
{
public:
	string name;
	int count_owner;

	Doc(string name = "no name")
	{
		this->name = name;
		this->count_owner = 0;
	}

	~Doc()
	{

	}

	Doc* getPoint()
	{
		count_owner += 1;
		return this;
	}

	int clearPoint()
	{
		if (count_owner > 0)
			--count_owner;
		return count_owner;
	}

	bool final()
	{
		return count_owner == 0;
	}

	void print()
	{
		cout << "Документ: " << name;
		if (final())
		{
			cout << " Документ сформирован " << endl;
		}
		else
		{
			cout << " count_owner: " << count_owner << endl;
		}
	}
};


class Worker
{
public:
	string name;
	Doc* document;


	Worker(string name = "no name")
	{
		this->name = name;
		this->document = NULL;
	}

	~Worker()
	{
		if (document != NULL)
			document->clearPoint();
	}

	void setDoc(Doc* doc)
	{
		document = doc->getPoint();
	}

	void print()
	{
		cout << "Сотрудник- " << name << endl;
	}

	void clearDoc()
	{
		if (document != NULL)
		{
			document->clearPoint();
			document = NULL;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Doc report("отчёт");
	Worker worker_one("Иванов");
	Worker worker_two("Смирнова");
	Worker worker_three("Соколов");
	//Worker worker_four("Васильев");
	worker_one.setDoc(&report);
	worker_two.setDoc(&report);
	worker_three.setDoc(&report);
	//worker_four.setDoc(&report);
	report.print();
	worker_one.clearDoc();

	report.print();
	worker_two.clearDoc();

	report.print();
	worker_three.clearDoc();

	//report.print();
	//worker_four.clearDoc();

	report.print();
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
