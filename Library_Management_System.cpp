#include"Library_Management_System.h"
istream& operator>>(istream& in, Book& obj) {
	in >> obj.num >> obj.title >> obj.authur >> obj.press >> obj.isbn_num >> obj.pages >> obj.price;
	return in;
}
void Library::show() {
	cout << "ͼ�������Ϣ��\n" << endl;
	cout << "ͼ������ƣ�" << name << endl;
	cout << "ͼ��ܵ�ַ��" << address << endl;
	cout << "ͼ��ݲ�������" << book_num << endl;
	cout << "ͼ���Ա������" << staff_num << endl;
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
		cout << "�ļ���ʧ�ܣ�" << endl;
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