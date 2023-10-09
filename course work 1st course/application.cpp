#include "application.h"
application::application(Base* ptr) :Base(ptr) {}
int application::start() {
	output();
	if (tree) {
		Base* ptr = this;
		string cmd;
		while (cin >> cmd && cmd !=
			"END") {
			string way;
			cin >> way;
			cout << endl;
			if (cmd == "SET") {
				Base* newptr = ptr->find_ptr(way);
				if (newptr != nullptr) {
					ptr = newptr;
					cout << "Object is set: " << ptr->get_name();
				}
				else {
					cout << "Object is not found: " << get_name() << " "
						<< way;
				}
			}
			else {
				if (cmd == "FIND") {
					Base* f_ptr = ptr->find_ptr(way);
					cout << way;
					if (f_ptr != nullptr) {
						cout << " Object name: " << f_ptr ->
							get_name();
					}
					else { cout << " Object is not found"; }
				}
			}
		}
	}
	else { cout << endl << error; }
	return 1;
}
void
application::build_tree() {
	string main, head, sub;
	Base* ptr;
	int number = 0;
	cin >> main;
	this->set_name(main);
	while (true) {
		cin >> head;
		if (head == "endtree") break;
		cin >> sub >> number;
		if (ptr != nullptr) {
			switch (number) {
			case 1:
				new node(ptr, sub);
				break;
			case 2:
				new node2(ptr, sub);
				break;
			case 3:
				new node3(ptr, sub);
				break;
			case 4:
				new node4(ptr, sub);
				break;
			case 5:
				new node5(ptr, sub);
				break;
			case 6:
				new node6(ptr, sub);
				break;
			default:
				break;
			}
		}
		else {
			this->tree = false;
			this->error = "The head object " + head + " is not found";
			return;
		}
	}
}