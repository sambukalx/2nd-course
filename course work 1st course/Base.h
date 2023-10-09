#ifndef Base_h
#define Base_h
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Base {
private:
	int ready;
	string name;
	Base* root;
	vector <Base*> arr_slave;
public:
	Base(Base* root, string obj_name = "name");
	void set_name(string obj_name);
	string get_name();
	void output();
	void def(Base* ptr);
	Base* get_ptr();
	Base* find(string name_f);
	void set_ready(int readyy);
	void set_ready_tree();
	void output_ready(string tab);
	Base* find_ptr(string way);
	Base* find_name(string name);
};
#endif