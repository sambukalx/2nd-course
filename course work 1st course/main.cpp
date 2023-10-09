#include "main.h"
int main() {
	application a(nullptr);
	a.build_tree();
	return a.start();}