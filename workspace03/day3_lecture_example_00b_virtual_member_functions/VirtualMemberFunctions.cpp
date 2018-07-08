#include <iostream>

class PolymorphicBase {
public:
	virtual void doit() {
		std::cout << "PolymorphicBase::doit\n";
	}
	virtual ~PolymorphicBase() = default;
};

class Implementor: public PolymorphicBase {
public:
	void doit() {
		std::cout << "Implementor::doit\n";
	}
};

void callDoItByValue(PolymorphicBase base) {
	base.doit();
}

void callDoItByReference(PolymorphicBase & base) {
	base.doit();
}


int main() {
	Implementor implementor{};
	callDoItByValue(implementor); //Object slicing
	callDoItByReference(implementor);
}
