#include<iostream>
#include<fstream>
#include<string>

using namespace std;
struct grocery {
	string name;
	int item_id;
	int price;
};
void add(grocery s[], int size);
void display(grocery s[], int size);
void search(grocery s[], int size,int id);
void update(grocery s[], int size,int id);
void purchase(grocery s[], int size,int id);
void bill(grocery s[], int size);
void del(grocery s[], int size, int id);

int main() {
	int size;
	cout << "enter the size";
	cin >> size;
	grocery* s = new grocery[size];
	int choice;
	do {
		cout << "1.add items";
		cout << endl;
		cout << "2.display items";
		cout << endl;
		cout<<"3.search item";
		cout << endl;
		cout << "4.update item";
		cout << endl;
		cout << "5.purchase items";
		cout << endl;
		cout << "6.total bill";
		cout << endl;
		cout << "7.delete item";
		cout << endl;
		cout << "8.exit";
		cout << endl;
		cout << "enter  your choice= ";
		cin >> choice;
		if (choice == 1) {
			add(s, size);
		}
		else if (choice == 2) {
			display(s, size);
		}
		else if (choice == 3) {
			int id;
			cout << "enter id of item you want to search";
			cin >> id;
			cout << endl;
			search(s, size, id);
		}
		else if (choice == 4) {
			int id;
			cout << "enter id of item you want to update";
			cin >> id;
			cout << endl;
			update(s, size, id);
		}
		else if (choice == 5) {
			int id;
			cout << "enter id of item you want to puchase";
			cin >> id;
			cout << endl;
			purchase(s, size, id);
		}
		else if (choice == 6) {
			bill( s,  size);
		}
		else if (choice == 7) {
			int id;
			cout << "enter id of item you want to delete";
			cin >> id;
			cout << endl;
			del(s, size, id);

		}
		else if (choice == 8) {
			cout << "you are exited from the menu";
			cout << endl;
		}
		else {
			cout << "invalid option";
			cout << endl;
		}


	} while (choice != 8);
}
void add(grocery s[], int size) {
	ofstream file("student.txt");
	for (int i = 0; i < size; i++) {
		cout << "enter name of the product: ";
		cin >> s[i].name;
		cout << endl;
		cout << "enter item id= ";
		cin >> s[i].item_id;
		cout << endl;
		cout << "enter price= ";
		cin >> s[i].price;
		cout << endl;
		file << s[i].name << " " << s[i].item_id << " " << s[i].price << endl;

	}
	file.close();

}
void display(grocery s[], int size) {
	ifstream  file2("student.txt");
	for (int i = 0; i < size; i++) {
		file2 >> s[i].name >> s[i].item_id >> s[i].price;
		cout << endl;
		cout << s[i].name << " " << s[i].item_id << " " << s[i].price << endl;
	}
	file2.close();
}
void search(grocery s[], int size, int id) {
	ifstream file2("student.txt");
	for (int i = 0; i < size; i++) {
		file2 >> s[i].name >> s[i].item_id >> s[i].price;
		if (s[i].item_id == id) {
			cout << "item exists!";
			cout << endl;
		}
	}
	file2.close();
}
void update(grocery s[], int size, int id) {
	ifstream file2("student.txt");
	for (int i = 0; i < size; i++) {
		file2 >> s[i].name >> s[i].item_id >> s[i].price;
		if (s[i].item_id == id) {
			s[i].item_id = 344;
			cout << "this item id is updated= " << s[i].item_id;
		}
	}
	file2.close();
}
void purchase(grocery s[], int size, int id) {
	ifstream file2("student.txt");
	for (int i = 0; i < size; i++) {
		file2 >> s[i].name >> s[i].item_id >> s[i].price;
		if (s[i].item_id == id) {
			cout << "you purchased this item"<<s[i].name;

		}
	}
	file2.close();
}
void bill(grocery s[], int size) {
	ifstream file2("student.txt");
	int sum = 0;
	for (int i = 0; i < size; i++) {
		file2 >> s[i].name >> s[i].item_id >> s[i].price;
		sum = sum + s[i].price;
	}
	cout << "your total bill= " << sum;
	cout << endl;
	file2.close();
}

void del(grocery s[], int size, int id) {
	ifstream file2("student.txt");
	ofstream temp("temp.txt");
	for (int i = 0; i < size; i++) {
		file2 >> s[i].name >> s[i].item_id >> s[i].price;
		if (s[i].item_id == id) {
			cout << "this item is deleted";
			cout << endl;
		}
		else {
			temp << s[i].name << " " << s[i].item_id << " " << s[i].price << endl;
		}


	}
	file2.close();
	temp.close();
	remove("student.txt");
	rename("student.txt", "temp.txt");
}
