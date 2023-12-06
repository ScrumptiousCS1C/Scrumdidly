#include "vector.h"

int main(){

	std::unique_ptr<scrumptious::Vector<int>> v = std::make_unique<scrumptious::Vector<int>>();	

	// Test push_back
	std::cout << "Testing push_back\n";

	v->push_back(1);
	v->push_back(2);
	v->push_back(3);
	v->push_back(4);
	v->push_back(5);

	// Test Contents of vector
	std::cout << "Vector v contents\n";
	std::cout << *v;

	// Test copy constructor 

	std::unique_ptr<scrumptious::Vector<int>> v2 = std::make_unique<scrumptious::Vector<int>>(*v); 

	std::cout << "Testing copy constructor\n" << *v2 << "\n";
	
	// Test assignment operator
	std::unique_ptr<scrumptious::Vector<int>> v3 = std::make_unique<scrumptious::Vector<int>>();

	*v3 = *v2;

	// Test contents of v3
	std::cout << "Testing assignment operator\n" << *v3 << "\n";

	// Test size
	std::cout << "Testing size\n" << v->sizeOf() << "\n";

	// Test move constructor
	std::unique_ptr<scrumptious::Vector<int>> v4 = std::make_unique<scrumptious::Vector<int>>(std::move(*v3));

	// Test contents of v4
	std::cout << "Testing move constructor\n" << *v4 << "\n";
	
	// Test size
	std::cout << "Testing size\n" << v4->sizeOf() << "\n";

	// test iterators
	std::cout << "Testing iterators\n" << v->begin() << " " << v->end() << "\n";
	// Test insert 
	v->insert(v->begin(), 10);

	std::cout << "Testing insert\n" << *v << "\n";
	
	// test insert
	v->insert(v->end(), 13);

	std::cout << "Testing insert\n" << *v << "\n";

	// test reserve/resize 
	v->resize(20);

	std::cout << "Testing resize\n" << v->sizeOf() << "\n";

	std::cout << *v << "\n";

	// test get_iterator 
	std::cout << "Testing get_iterator\n" << v->get_iterator(2) << "\n";
	
	// test erase
	std::cout << "Erasing memory address: " << v->erase(v->get_iterator(2)) << "\n";

	std::cout << "Testing erase\n" << *v << "\n";
	
	// test insert before
	v->insert(v->get_iterator(2), 15);

	std::cout << "Testing insert before\n" << *v << "\n";

	// test insert after

	v->insert(v->get_iterator(3), 16);

	std::cout << "Testing insert after\n" << *v << "\n";

	return 0;
}
