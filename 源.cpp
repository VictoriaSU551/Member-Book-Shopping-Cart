#include<iostream>
#include<string>
#include <graphics.h>	
#include<easyx.h>
#include<fstream>
using namespace std;

//��1�������ߣ����ࣩ
class buyer
{
protected:
	string name;
	int buyerID;
	string address;
	double pay;
public:
	buyer()
	{
		name = "";
		buyerID = 0;
		address = "";
		pay = 0;
	}

	buyer(string n, int b, string a, double p)
	{
		name = n;
		buyerID = b;
		address = a;
		pay = p;
	}

	string getbuyname()
	{
		return name;
	}

	string getaddress()
	{
		return address;
	}

	double getpay()
	{
		return pay;
	}

	int getid()
	{
		return buyerID;
	}

	virtual void display() = 0;
	virtual void setpay(double = 0) = 0;
};

//��2����Ա
class  member :public buyer
{
private:
	int leaguer_grade;
public:
	member(string n, int b, int l, string a, double p) :buyer(n, b, a, p)
	{
		leaguer_grade = 1;
	}

	void display()
	{
		cout << "������������" << name << endl;
		cout << "�����˱�ţ�" << buyerID << endl;
		cout << "������Ϊ��Ա������" << leaguer_grade << endl;
		cout << "��ַ��" << address << endl;
		cout << endl;
	}

	void setpay(double p)
	{
		switch (leaguer_grade)
		{
		case 1:
			pay = 0.95 * p + pay;
			break;
		case 2:
			pay = 0.9 * p + pay;
			break;
		case 3:
			pay = 0.85 * p + pay;
			break;
		case 4:
			pay = 0.8 * p + pay;
			break;
		case 5:
			pay = 0.7 * p + pay;
			break;
		default:
			cout << "�������" << endl;
			break;
		}

	}
};

//��3�����
class honoured_guest :public buyer
{
private:
	double discount_rate;
public:
	honoured_guest(string n, int b, double r, string a, double p) :buyer(n, b, a, p)
	{
		discount_rate = r;
	}

	void display()
	{
		cout << "������������" << name << endl;
		cout << "�����˱��:" << buyerID << endl;
		cout << "������Ϊ���!�ۿ���Ϊ:" << discount_rate  << endl;
		cout << "��ַ:" << address << endl;
		cout << endl;
	}

	void setpay(double p)
	{
		pay = pay + (1 - discount_rate) * p;
	}
};

//��4����ͨ��
class layfolk :public buyer
{
public:
	layfolk(string n, int b, string a, double p) :buyer(n, b, a, p)
	{}
	void display()
	{
		cout << "������������" << name << endl;
		cout << "�����˱�ţ�" << buyerID << endl;
		cout << "������Ϊ��ͨ��!" << endl;
		cout << "��ַ��" << address << endl;
		cout << endl;
	}

	void setpay(double p)
	{
		pay = pay + p;
	}
};

//��5����
class book
{
protected:
	string book_ID;
	string book_name;
	string author;
	string publishing;
	double price;
public:
	book()
	{
		book_ID = "";
		book_name = "";
		author = "";
		publishing = "";
		price = 0;
	}

	book(string b_id, string b_n, string au, string pu, double pr)
	{
		book_ID = b_id;
		book_name = b_n;
		author = au;
		publishing = pu;
		price = pr;
	}

	void display()
	{
		cout << "��ţ�" << book_ID << endl;
		cout << "������" << book_name << endl;
		cout << "���ߣ�" << author << endl;
		cout << "�����磺" << publishing << endl;
		cout << "���ۣ�" << price << endl;
		cout << endl;
	}

	string getbook_ID()
	{
		return book_ID;
	}

	string getbook_name()
	{
		return book_name;
	}

	string getauthor()
	{
		return author;
	}

	string getpublishing()
	{
		return publishing;
	}

	double getprice()
	{
		return price;
	}
};

void menu()
{
	cout << " *************************" << endl;
	cout << "      ��ӭ���ٱ����      " << endl;
	cout << " *************************" << endl;
	cout << "��������λ���롣" << endl;
}

bool password(int p)
{
	if (p == 1234)
		return true;
	else
		return false;
}

void display_book()
{
	cout << "           ͼ��           " << endl;
	cout << "**************************" << endl;
	int i = 0;
	book* c[2];
	book c1("111", "Time", "Jenny", "UT", 25);
	book c2("222", "Art", "Victoria", "HKU", 30);
	c[0] = &c1;
	c[1] = &c2;
	cout << "ͼ����Ϣ��" << endl;
	for (i = 0; i < 2; i++)
		c[i]->display();
	cout << "**************************" << endl;
}

void button_word(int tx, int ty, TCHAR text)
{
	settextstyle(100,100, _T("����"));
	settextcolor(WHITE);
	outtextxy(tx, ty, text);
}

void button_space(int x, int y, int w, int h)
{
	setbkmode(TRANSPARENT);
	setfillcolor(BLUE);
	fillroundrect(x, y, x + w, y + h, 10, 10);
}

void button_showbookdetails(int x, int y, int w, int h)
{
	button_space(x, y, w, h);
	TCHAR text[] = _T("��ʾͼ����Ϣ");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void button_showpay(int x, int y, int w, int h)
{
	button_space(x, y, w, h);
	TCHAR text[] = _T("����");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void button_showpeople(int x, int y, int w, int h)
{
	button_space(x, y, w, h);
	TCHAR text[] = _T("�ǻ�Ա");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void button_showmember(int x, int y, int w, int h)
{
	button_space(x, y, w, h);
	TCHAR text[] = _T("��Ա");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void button_showhonor(int x, int y, int w, int h)
{
	button_space(x, y, w, h);
	TCHAR text[] = _T("���");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void background()
{
	IMAGE img;
	initgraph(600,400, EW_SHOWCONSOLE);
	fillrectangle(0,0,600,400);
}

void member_menu()
{
	background();
	button_showpeople(150,25,300,100);
	button_showmember(150, 150, 300, 100);
	button_showhonor(150, 275, 300, 100);
}

void tool_menu()
{
	background();
	button_showbookdetails(150, 66, 300, 100);
	button_showpay(150, 232, 300, 100);
}

void deal_pay()
{
	int i = 0, buyerid, flag;
	book* c[2];
	book c1("111", "Time", "Sofia", "UT", 25);
	book c2("222", "Art", "Victoria", "HKU", 30);
	layfolk b1("Tom", 1, "shanghai", 0);
	honoured_guest b2("Jerry", 2, 0.6, "hongkong", 0);
	member b3("Lily", 3, 5, "London", 0);
	buyer* b[3] = { &b1,&b2,&b3 };
	c[0] = &c1;
	c[1] = &c2;
	cout << "��������Ϣ��" << endl;
	for (i = 0; i < 3; i++)
		b[i]->display();
	cout << "�����빺���˱�ţ�" << endl;
	cin >> buyerid;
	flag = 0;
	for (i = 0; i < 3; i++)
		if (b[i]->getid() == buyerid)
		{
			flag = 1;
			break;
		}
	if (!flag)
	{
		cout << "��Ų����ڣ�" << endl;
	}
	else
	{
		b[i]->setpay(c[0]->getprice());
		b[i]->setpay(c[1]->getprice());
		cout << "��������Ҫ���ѣ�" << b[i]->getpay() << endl;
		cout << "����������СƱ��"<<endl;
		ofstream f;
		f.open("ticket.txt", ios::out);
		f << "***************************" << endl;
		f << "���˵���" << endl;
		f << "���ѣ�" << b[i]->getpay() << "Ԫ��" << endl;
		f << "***************************" << endl;
		f.close();
	}
}


void deal_membermenu()
{
	while (true)
	{
		ExMessage m;
		if (peekmessage(&m, EM_MOUSE))
		{
			switch (m.message)
			{
			case(WM_LBUTTONDOWN): 
			{
				if (m.x >= 150 && m.x <= 450 && m.y >= 25 && m.y <= 125)//��ͨ��
				{
					tool_menu();
					if (m.x >= 150 && m.x <= 450 && m.y >= 66 && m.y <= 166)
						display_book();
					if (m.x >= 150 && m.x <= 450 && m.y >= 232 && m.y <= 332)
						deal_pay();
				}
				if (m.x >= 150 && m.x <= 450 && m.y >= 150 && m.y <= 250)//��Ա
				{
					tool_menu();
					if (m.x >= 150 && m.x <= 450 && m.y >= 66 && m.y <= 166)
						display_book();
					if (m.x >= 150 && m.x <= 450 && m.y >= 232 && m.y <= 332)
						deal_pay();
				}
				if (m.x >= 150 && m.x <= 450 && m.y >= 275 && m.y <= 375)//���
				{
					tool_menu();
					if (m.x >= 150 && m.x <= 450 && m.y >= 66 && m.y <= 166)
						display_book();
					if (m.x >= 150 && m.x <= 450 && m.y >= 232 && m.y <= 332)
						deal_pay();
				}
			}
			default:
				break;
			}
		}
	}
}

int main()
{
	menu();
loop:
	int pw;
	cin >> pw;
	if (password(pw))
	{
		cout << "��¼�ɹ���" << endl;
		member_menu();
		loop1:
		deal_membermenu();
		goto loop1;
	}
	else
	{
		cout << "����������������룺" << endl;
		goto loop;
	}
	return 0;
}