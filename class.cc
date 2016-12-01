#include <iostream>
#include <string>
#include <vector>
using namespace std;

class employee {

protected:
	long id_;
	string name_;
	
	public:
	
	employee(long id, string name) : id_(id), name_(name) {}
	
	long get_id() const {
	return id_;
	}
	
	string get_name() const {
	return name_;
	}
	
	virtual void print() const {
	cout << "id: " << id_ << "; name: " << name_ << endl; 
	}
};

class manager: public employee {
	
	long level_;
	
	public:
	
	manager(long id, string name, long level) : employee(id, name), level_(level) {}
	
	void print() const {
		cout << "level: " << level_ << "; ";
		employee::print();
	} 
};

void fire(employee& e) {
	cout << "U ARE FIRED U LIL BITCH ";
	e.print();
}

int main() {
	employee e1(1, "balo balo");
	e1.print();

	manager m1(2, "woof woof", 1);
	m1.print();
	
	cout << "printing from vector with employees" << endl;
	vector<employee*>employees;
	employees.push_back(&e1);
	employees.push_back(&m1);
	for (vector<employee*>::iterator it = employees.begin(); it != employees.end(); it++) {
	(*it) -> print();
	}
	
	cout << "printing manager from employee variable" << endl;
	employee e2 = m1;
	e2.print();
	
	cout << "printing manager form employee reference" << endl;
	employee& e3 = m1;
	e3.print();	
	
	fire(m1);
	fire(e1);
	return 0;
}
