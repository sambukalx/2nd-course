#include "Base.h"
Base::Base(Base* root, string
	obj_name) {
	name = obj_name;
	this->root = root;
	if (root != nullptr) { root->arr_slave.push_back(this); }
}
int a(0), b(0);
void Base::output() {
	if (root == nullptr) {
		cout << "Object tree" << endl;
		cout << name;
	}
	if (arr_slave.size() > 0) {
		for (int i = 0; i < arr_slave.size();
			i++) {
			cout << endl << " ";
			if (a != 0) {
				for (int j = 0; j < b; j++) cout << " ";
			}
			a++;
			b++;
			cout << arr_slave[i]->get_name();
			arr_slave[i]->output();
			a--;
			b--;
		}
	}
}
Base* Base::get_ptr() { return root; }
void Base::set_name(string obj_name) { name = obj_name; }
void Base::def(Base* ptr) {
	if (root != nullptr && ptr != nullptr) {
		for (int i = 0; i < (root->arr_slave.size());
			i++) {
			if (root->arr_slave[i]->name == name) {
				root->arr_slave.erase(root->arr_slave.begin() + i);
				break;
			}
		}
		root = ptr;
		root->arr_slave.push_back(this);
	}
}
string Base::get_name() { return name; }
Base* Base::find(string
	name_f) {
	Base* obj;
	if (name_f == name) return this;
	for (int i = 0; i < arr_slave.size();
		i++) {
		obj = arr_slave[i] ->
			find(name_f); if (obj != nullptr)
			return obj;
	}
	return nullptr;
}
void Base::output_ready(string tab) {
	ready != 0 ? cout << get_name() << " is ready" : cout << get_name() << " is not
		ready";
		if (arr_slave.size() !=
			0) {
			tab += " ";
			for (int i = 0; i < arr_slave.size();
				i++) {
				Base* ptr = arr_slave[i];
				cout << endl << tab;
				ptr->output_ready(tab);
			}
		}
}
void Base::set_ready_tree() {
	string name;
	int readyy;
	while (cin >> name >>
		readyy) {
		if (find(name) !=
			nullptr) {
			find(name)->set_ready(readyy);
		}
	}
}
Base* Base::find_ptr(string way) {
	if (way.empty()) return nullptr;
	if (way[0] == '.' && way.size() == 1) return this;
	Base* ptr = this;
	if (way[0] == '/') {
		while (ptr->get_ptr()) { ptr = ptr->get_ptr(); }
		if (way.size() == 1) return ptr;
		if (way[1] == '/') {
			way.erase(0, 2);
			return ptr->find(way);
		}
		way.erase(0, 1);
	}
	int s = way.find('/');
	string f_name;
	if (s == -1) { f_name = way; }
	else { f_name = way.substr(0, s); }
	for (auto sub : ptr->arr_slave) {
		if (sub->get_name() ==
			f_name) {
			if (s == -
				1) {
				return sub;
			}
			else {
				way.erase(0, s + 1);
				return sub->find_name(way);
			}
		}
	}
	return nullptr;
}
Base* Base::find_name(string
	name_) {
	if (name_ == name) {
		return
			this;
	}
	for (int i = 0; i < arr_slave.size(); i++) {
		if (arr_slave[i]->get_name() == name_) { return arr_slave[i]; }
	}
	return nullptr;
}
void Base::set_ready(int
	readyy) {
	if (readyy == 0) {
		ready = 0;
		for (int
			iset_ready(0);
	}
}
else {
	= 0; i < arr_slave.size(); i++) {
			arr_slave[i] ->
				Base* ptr = this->root;
			while (ptr != nullptr) {
				if (ptr->ready ==
					0) {
					ready = 0;
					return;
				}
				ptr = ptr->root;
			}
			ready = readyy;
		}
		}