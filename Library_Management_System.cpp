#include"Library_Management_System.h"
istream& operator>>(istream& in, Book& obj) {
	in >> obj.num >> obj.title >> obj.authur >> obj.press >> obj.isbn_num >> obj.pages >> obj.price;
	return in;
}
void Library::show() {
	cout << "图书馆总信息：\n" << endl;
	cout << "图书馆名称：" << name << endl;
	cout << "图书管地址：" << address << endl;
	cout << "图书馆藏书量：" << book_num << endl;
	cout << "图书馆员工数：" << staff_num << endl;
}
void add_book(Library obj) {
	obj.book_num++;
}
void add_staff(Library obj) {
	obj.staff_num++;
}
void WriteFile() {

}
void ReadFile(Book b[]) {
	ifstream fp("Books.txt");
	if (fp.is_open()) {
		for (int i = 0; i < 6; i++) {
			fp >> b[i];
		}
		fp.close();
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

}
int main() {
	Library library("Library of Xi'an University of Technology", "Xi'an", 0, 0);
	Book* books = new Book[MAX];
	Reader* readers = new Reader[MAX];
	Admin* admins = new Admin[MAX];
	ReadFile(books);
	for (int i = 0; i < 6; i++) {
		books[i].show();
	}
	Release(books, readers, admins);
	return 0;
}