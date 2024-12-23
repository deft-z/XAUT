#include<iostream>
#include<string>
#include<fstream>
#define MAX_P 10
#define MAX 100
using namespace std;
class Library {
	string name;
	string address;
	int book_num;
	int staff_num;
public:
	Library(string n,string adr,int bn,int sn)
		:name(n),address(adr),book_num(bn),staff_num(sn){}
	void show();
	friend void add_book(Library obj);
	friend void add_staff(Library obj);
};
class Book {
	int num;//���
	string title;//����
	string authur;//����
	string press;//������
	string isbn_num;//ISBN
	int pages;//ҳ��
	float price;//�۸�
public:
	Book() {
		num = 0;
		pages = 0;
		price = 0;
	}
	inline void show() {
		cout << num << " " << title << " " << authur << " "
			<< press << " " << isbn_num << " " << pages << " "
			<< price << endl;
	}
	friend istream& operator>>(istream& in, Book& obj);
};
class People {
	string name;
	int age;
	string sex;
public:
	People(){}
	People(string na,string s,int a):name(na),sex(s),age(a){}
};

class Reader :public People {
	int id;
	string password;
	string Tele;//��ϵ�绰
	Book* borrow;//����ͼ��
public:
	Reader() {
		borrow = new Book[MAX_P];
	}
	Reader(string na, string s, int a, int i, string pa, string te) :People(na, s, a), id(i), password(pa), Tele(te) {
		borrow = new Book[MAX_P];
	}
	~Reader() {
		delete []borrow;
	}
	void borrow_book();
	void return_book();
	void search_book();
};

class Admin :public People {
	int admin_id;
	string admin_password;
	string Position;//ְλ
	int wook_age;//����
public:
	Admin(){}
	Admin(string na, string s, int a, int id, string pa, string po, int wa)
		:People(na, s, a), admin_id(id), admin_password(pa), Position(po), wook_age(wa) {}
	void add_book();
	void remove_book();
	void updata_book();
	void register_reader();
	void unregister_reader();
	void search_book();
};