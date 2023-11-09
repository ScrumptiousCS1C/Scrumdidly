// vector.h
//
// About:
//*************************************************************************************************
// A templated vector class to be used as a container for objects in the 2D modeler
// Designed to be compatible with Qt 6.6 QPaint related objects
//
// Vector exists within namespace scrumptious
//
// Vector supports the following basic operations: 
// constructors for one or more arguments, default 
// constructors, copy constructor, copy assignment, move constructor, 
// move assignment and destructor. Vector also supports a basic iterator 
// member type and member function begin() and end() operations
//
// Extra Credit [+2 Pts]: Write a custom selection_sort algorithm and two 
// custom comparison functions compare_shape_perimeter, 
// compare_shape_area. All functions are templated. The comparison 
// functions are called via a function pointer passed to selection_sort. 
// This allows the algorithm to sort shapes by perimeter and area 
// respectively. Selection_sort must sort a vector of shapes by id
// (default) or alternatively via custom comparison functions.
//
//************************************************************************************************* 
//
//
// Created By: Spencer Glenn
// Date: 11/5/2023
// Class: CS1C
// Prof: John Kath
//
//*************************************************************************************************

#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <iostream>
#include <limits>

namespace scrumptious{
	template <class T>
	class Vector{
		// a templated vector class to serve as a container for Qt objects
		private:
			//*************************************************************************
			// private data members
			//_________________________________________________________________________
			int size;  // current size of vector
			T* vector; // pointer to dynamic array
			int space; // nummber of elements plus number of free slots
			//*************************************************************************
		public:
			//*************************************************************************
			// Default Constructor
			//_________________________________________________________________________
			// Pre: None
			// Post: Creates a vector with a default size of 0 and space of 0
			//*************************************************************************
			Vector() : size{0}, vector{nullptr}, space{0} {} // inline MIL
			//*************************************************************************
			// Overloaded Constructor (alternate constructor)
			//_________________________________________________________________________
			// Pre: None
			// Post: Creates a vector of size `n` and space `n`
			//*************************************************************************
			explicit Vector(int n) : size{n}, vector{new T[n]}, space{n} {
				for(int i = 0; i < size; i++){
					vector[i] = T(0); // initialize templated elements to default value
				}
			}
			//*************************************************************************
			// Copy Constructor
			//_________________________________________________________________________
			// Pre: a vector object is passed in
			// Post: Creates a deep copy of the vector object passed in
			//*************************************************************************
			Vector(const T &v) : size{v.size}, vector{new T[v.size]}, space{v.space} {
				for(int i = 0; i < size; i++){
					vector[i] = v.vector[i]; // copy each element of the vector
				}
			} 
			//*************************************************************************
			// Copy Assignment operator
			//_________________________________________________________________________
			// Pre: a vector object is passed in
			// Post: creates a new object based on the vector object passed in
			//*************************************************************************
			Vector &operator=(const T &v){
				
				T *temp = new T[v.size]; // create a new vector
				for(int i = 0; i < v.size; i++){
					temp[i] = v.vector[i]; // copy each element of the vector
				}
				delete[] vector; // delete the old vector
				vector = temp; // assign the new vector to the old vector
				size = v.size; // assign the new size to the old size
				space = v.space; // assign the new space to the old space
				return *this; // return the new vector
			}
			//*************************************************************************
			// Deconstructor
			//_________________________________________________________________________
			// Pre: None
			// Post: Deletes the vector object
			//*************************************************************************
			~Vector() {delete[] vector;} // delete the vector
			//*************************************************************************
			// access reference operator
			//_________________________________________________________________________
			// Pre: an index is passed in
			// Post: returns a reference to the element at the index passed in
			//*************************************************************************
			T &operator[](int n) {return vector[n];} // access reference operator
			//*************************************************************************
			// const access reference operator
			//_________________________________________________________________________
			// Pre: an index is passed in
			// Post: returns a const reference to the element at the index passed in
			//*************************************************************************
			const T &operator[](int n) const {return vector[n];} // const access reference operator
			//*************************************************************************
			// size function
			//_________________________________________________________________________
			// Pre: None
			// Post: returns the size of the vector
			//*************************************************************************
			int sizeOf() const {return size;} // size function
			//*************************************************************************
			// capacity function
			//_________________________________________________________________________
			// Pre: None
			// Post: returns the capacity of the vector
			//*************************************************************************
			int capacity() const {return space;} // capacity function
			//*************************************************************************
			// resize function
			//_________________________________________________________________________
			// Pre: a new size is passed in
			// Post: resizes (grows) the vector to the new size passed in
			//*************************************************************************
			void resize(int newSize){
				
				reserve(newSize); // reserve space for the new size

				for(int i = size; i < newSize; i++){
					vector[i] = T(0); // initialize the new elements to default value
				}
				size = newSize; // assign the new size to the old size
			}
			//*************************************************************************
			// push_back function
			//_________________________________________________________________________
			// Pre: a new element is passed in
			// Post: adds the new element to the end of the vector; increases size by 1
			//*************************************************************************
			void push_back(T newElement){
				// increases vector size by one; initialize the new element with `newElement`
				if(space == 0){
					reserve(8); // reserve space for 8 elements
				}
				else if(size == space){
					reserve(2 * space); // reserve space for 2 * space elements
				}
				vector[size] = newElement; // initialize the new element with `newElement`
				size++; // increase the size by 1
			}
			//*************************************************************************
			// reserve function
			//_________________________________________________________________________
			// Pre: a new allocation is passed in
			// Post: reserves space for the new allocation passed in
			//*************************************************************************
			void reserve(int newAlloc){
				
				if(newAlloc < 0) { // exception handling for negative allocation
					throw std::invalid_argument("New allocation size cannot be negative");
				}

				if(newAlloc > std::numeric_limits<int>::max()){ // exception handling for overflow
					throw std::overflow_error("New allocation size is too large");
				}

				if(newAlloc > size){
					T* temp;
					try{ // exception handling for bad_alloc
						temp = new T[newAlloc]; // create a temporary array of size `newAlloc`
					} catch (std::bad_alloc &ba) {
						std::cerr << "bad_alloc caught: " << ba.what() << '\n';
						return;
					}
					// copy old elements
					for(int i = 0; i < size; i++){
						temp[i] = vector[i]; // copy each element of the vector
					}

					// deallocate old space
					delete[] vector; // delete the old vector
					size = newAlloc; // assign the new size to the old size
					vector = temp; // assign the new vector to the old vector
				}
					
				
			}
			//*************************************************************************
			// Iterator functions
			//*************************************************************************
			using iterator = T*;
			using const_iterator = const T*;
			//*************************************************************************
			// begin function
			//_________________________________________________________________________
			// Pre: None
			// Post: returns an iterator to the first element of the vector
			//*************************************************************************
			iterator begin() {
				if(size == 0){
					return nullptr;
				}	
				return &vector[0]; // return an iterator to the first element
			}
			//*************************************************************************
			// const begin function
			//_________________________________________________________________________
			// Pre: None
			// Post: returns a const iterator to the first element of the vector 
			//*************************************************************************
			const_iterator begin() const {
				if(size == 0){
					return nullptr;
				}	
				return &vector[0]; // return a const iterator to the first element
			}
			//*************************************************************************
			// end function
			//_________________________________________________________________________
			// Pre: None
			// Post: returns an iterator to one beyond the last element of the vector
			//*************************************************************************
			iterator end() {
				if(size == 0){
					return nullptr;
				}	
				return &vector[size]; // return an iterator to the last element
			}
			//*************************************************************************
			// const end function
			//_________________________________________________________________________
			// Pre: None
			// Post: returns a const iterator to one beyond the last element of the vector
			//*************************************************************************
			const_iterator end() const {
				if(size == 0){
					return nullptr;
				}	
				return &vector[size]; // return a const iterator to the last element
			}
			//*************************************************************************
			// insert function
			//_________________________________________________________________________
			// Pre: an iterator and a new element are passed in
			// Post: inserts the new element at the iterator position
			//*************************************************************************
			iterator insert(iterator p, const T &v){
				if(p < vector || p > vector + space){
					throw std::out_of_range("Iterator out of range"); // exception handling for out of range iterator
				}
				// insert a new element v before p
				// make sure we have space
				if (space == size){
					reserve(size == 0 ? 8 : 2 * space); // reserve space for 2 * size elements if size > 0
				}

				// the place to put the value
				int index = p - vector; // convert iterator to index
				// copy element one position to the right
				for(int i = size; i > index; i--){
					vector[i] = vector[i - 1]; // copy element one position to the right
				}
				// insert the new value at position p
				vector[index] = v; // insert the new value at position p
				size++; // increase the size by 1
				// return a pointer to the newly inserted element
				return vector + index; // return a pointer to the newly inserted element
			}
			//*************************************************************************
			// erase function
			//_________________________________________________________________________
			// Pre: an iterator is passed in
			// Post: erases the element at the iterator position
			//*************************************************************************
			iterator erase(iterator p){
				// remove element pointed to by p
				// copy element one position to the left
				// return a pointer to the element pointed to by p
				if(p == end()){
					return p;
				}
				for(iterator pos = p + 1; pos != end(); ++pos){
					*(pos - 1) = *pos; // copy element one position to the left
				}
				delete (end() - 1); // delete the last element
				--size; // decrease the size by 1
				return p; // return a pointer to the element pointed to by p
			}
			//*************************************************************************
	};
}

#endif // VECTOR_H
