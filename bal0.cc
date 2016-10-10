#include<iostream>
#include<cmath> 
using namespace std;


class balo {

	double x_;
	double y_;
public:
	balo() {	
	cout <<"default cntr..." << endl;
	x_ = 0.0;
	y_ = 0.0;


}

	double get_x() {
	return x_;
}
	double get_y() {
	return y_;
}
	void set_x(double x) {
	x_=x;
}
	void set_y(double y) {
	y_=y; 
}
 
	void add(balo other){
	//x_ = x_ + other.x_;
	x_ += other.x_;	
	y_ += other.y_;

}
	void sub(balo other) {
	x_ -= other.x_;
	y_ -= other.y_;

}
	double dist(balo other) {
	double dx = x_ - other.x_;
	double dy = y_ - other.y_;

	return sqrt(dx*dx + dy*dy);

}

};


int main() {
	
	balo b1, b2;
	cout <<b1.get_x() << ", "<< b1.get_y() << endl;
	cout <<b2.get_x() << ", "<< b2.get_y() << endl;

	
	//b1.x_ = 10;
	b1.set_x(10.0);
	b1.set_y(20.0);

	cout << b1.get_x() << ", "<< b1.get_y() << endl;
		
	b2.set_x(11.0);
	b2.set_y(22.0);
	cout << b2.get_x() << ", "<< b2.get_y() << endl;

	cout <<b1.get_x() << ", "<< b1.get_y() << endl;
	b1.add(b2);
	cout <<b1.get_x() << ", "<< b1.get_y() << endl;
	
	cout <<b1.get_x() << ", "<< b1.get_y() << endl;
	b1.sub(b2);
	cout <<b1.get_x() << ", "<< b1.get_y() << endl;	

	cout <<b1.get_x() << ", "<< b1.get_y() << endl;
	b1.dist(b2);
	cout <<b1.get_x() << ", "<< b1.get_y() << endl;

	
	
	return 0;
}
