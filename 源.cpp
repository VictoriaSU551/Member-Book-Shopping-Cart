#include<iostream>
#include<string>
#include <graphics.h>	
#include<easyx.h>
#include<fstream>
using namespace std;

//类1：购买者（基类）
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

//类2：会员
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
		cout << "购书人姓名：" << name << endl;
		cout << "购书人编号：" << buyerID << endl;
		cout << "购书人为会员，级别：" << leaguer_grade << endl;
		cout << "地址：" << address << endl;
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
			cout << "级别错误！" << endl;
			break;
		}

	}
};

//类3：贵宾
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
		cout << "购书人姓名：" << name << endl;
		cout << "购书人编号:" << buyerID << endl;
		cout << "购书人为贵宾!折扣率为:" << discount_rate  << endl;
		cout << "地址:" << address << endl;
		cout << endl;
	}

	void setpay(double p)
	{
		pay = pay + (1 - discount_rate) * p;
	}
};

//类4：普通人
class layfolk :public buyer
{
public:
	layfolk(string n, int b, string a, double p) :buyer(n, b, a, p)
	{}
	void display()
	{
		cout << "购书人姓名：" << name << endl;
		cout << "购书人编号：" << buyerID << endl;
		cout << "购书人为普通人!" << endl;
		cout << "地址：" << address << endl;
		cout << endl;
	}

	void setpay(double p)
	{
		pay = pay + p;
	}
};

//类5：书
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
		cout << "书号：" << book_ID << endl;
		cout << "书名：" << book_name << endl;
		cout << "作者：" << author << endl;
		cout << "出版社：" << publishing << endl;
		cout << "定价：" << price << endl;
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
	cout << "      欢迎光临本书店      " << endl;
	cout << " *************************" << endl;
	cout << "请输入四位密码。" << endl;
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
	cout << "           图书           " << endl;
	cout << "**************************" << endl;
	int i = 0;
	book* c[2];
	book c1("111", "Time", "Jenny", "UT", 25);
	book c2("222", "Art", "Victoria", "HKU", 30);
	c[0] = &c1;
	c[1] = &c2;
	cout << "图书信息：" << endl;
	for (i = 0; i < 2; i++)
		c[i]->display();
	cout << "**************************" << endl;
}

void button_word(int tx, int ty, TCHAR text)
{
	settextstyle(100,100, _T("黑体"));
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
	TCHAR text[] = _T("显示图书信息");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void button_showpay(int x, int y, int w, int h)
{
	button_space(x, y, w, h);
	TCHAR text[] = _T("结账");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void button_showpeople(int x, int y, int w, int h)
{
	button_space(x, y, w, h);
	TCHAR text[] = _T("非会员");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void button_showmember(int x, int y, int w, int h)
{
	button_space(x, y, w, h);
	TCHAR text[] = _T("会员");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void button_showhonor(int x, int y, int w, int h)
{
	button_space(x, y, w, h);
	TCHAR text[] = _T("贵宾");
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
	cout << "购书人信息：" << endl;
	for (i = 0; i < 3; i++)
		b[i]->display();
	cout << "请输入购书人编号：" << endl;
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
		cout << "编号不存在！" << endl;
	}
	else
	{
		b[i]->setpay(c[0]->getprice());
		b[i]->setpay(c[1]->getprice());
		cout << "购书人需要付费：" << b[i]->getpay() << endl;
		cout << "已生成消费小票！"<<endl;
		ofstream f;
		f.open("ticket.txt", ios::out);
		f << "***************************" << endl;
		f << "总账单：" << endl;
		f << "消费：" << b[i]->getpay() << "元！" << endl;
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
				if (m.x >= 150 && m.x <= 450 && m.y >= 25 && m.y <= 125)//普通人
				{
					tool_menu();
					if (m.x >= 150 && m.x <= 450 && m.y >= 66 && m.y <= 166)
						display_book();
					if (m.x >= 150 && m.x <= 450 && m.y >= 232 && m.y <= 332)
						deal_pay();
				}
				if (m.x >= 150 && m.x <= 450 && m.y >= 150 && m.y <= 250)//会员
				{
					tool_menu();
					if (m.x >= 150 && m.x <= 450 && m.y >= 66 && m.y <= 166)
						display_book();
					if (m.x >= 150 && m.x <= 450 && m.y >= 232 && m.y <= 332)
						deal_pay();
				}
				if (m.x >= 150 && m.x <= 450 && m.y >= 275 && m.y <= 375)//贵宾
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
		cout << "登录成功！" << endl;
		member_menu();
		loop1:
		deal_membermenu();
		goto loop1;
	}
	else
	{
		cout << "密码错误，请重新输入：" << endl;
		goto loop;
	}
	return 0;
}