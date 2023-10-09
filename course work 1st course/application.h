#ifndef application_h
#define application_h
#include "node.h"
#include "Base.h"
class application : public
	Base {
private:
	string error;
	bool tree = true;
public:
	application(Base* ptr);
	int start();
	void build_tree();
};
#endif
