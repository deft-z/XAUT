#include"Library_Management_System.h"
istream& operator>>(istream& in, Book& obj) {
	in >> obj.num >> obj.title >> obj.authur >> obj.press >> obj.isbn_num >> obj.pages >> obj.price;
	return in;
}
istream& operator>>(istream& in, Reader& obj) {
	in >> obj.id >> obj.password >> obj.name >> obj.age >> obj.sex >> obj.Tele;
	return in;
}
istream& operator>>(istream& in, Admin& obj) {
	in >> obj.admin_id >> obj.admin_password >> obj.name >> obj.age >> obj.sex >> obj.Position >> obj.wook_age;
	return in;
}
void Library::show() {
	cout << "图书馆总信息：\n" << endl;
	cout << "图书馆名称：" << name << endl;
	cout << "图书管地址：" << address << endl;
	cout << "图书馆藏书量：" << book_num << endl;
	cout << "图书馆员工数：" << staff_num << endl;
}
void add_book(Library* obj) {
	obj->book_num++;
}
void add_staff(Library* obj) {
	obj->book_num++;
}
void WriteFile() {

}
void ReadFile(Book b[],Reader r[],Admin a[]) {
	ifstream fbp("Books.txt");
	if (fbp.is_open()) {
		for (int i = 0; !fbp.eof(); i++) {
			fbp >> b[i];
			add_book(&library);
		}
		fbp.close();
	}
	else {
		cout << "文件打开失败！" << endl;
	}
	ifstream frp("Reader.txt");
	if (frp.is_open()) {
		for (int i = 0; !frp.eof(); i++) {
			frp >> r[i];
		}
		frp.close();
	}
	else {
		cout << "文件打开失败！" << endl;
	}
	ifstream fap("Admin.txt");
	if (fap.is_open()) {
		for (int i = 0; !fap.eof(); i++) {
			fap >> a[i];
			add_staff(&library);
		}
		fap.close();
	}
	else {
		cout << "文件打开失败！" << endl;
	}
}
void Release(Book* b, Reader* r, Admin* a) {
	delete[]b;
	delete[]r;
	delete[]a;
}
void Menu() {
	cout << "_________________________________________________________________" << endl;
	cout << "--------------------------图书馆管理系统-------------------------" << endl;
}
int main() {
	Book* books = new Book[MAX];
	Reader* readers = new Reader[MAX];
	Admin* admins = new Admin[MAX];
	ReadFile(books,readers,admins);
	/*for (int i = 0; i < library.get_bookn(); i++) {
		books[i].show();
	}*/
	Release(books, readers, admins);
	return 0;
}