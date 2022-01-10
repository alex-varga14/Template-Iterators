#include <iostream>
#include <assert.h>
#include <cstring>
#include "StringClass.h"

using namespace std;

template <class T> //declare template class
class Vector 
{
    public: 

    class VectIter
	{
		friend class Vector; //declare Vector class a friend, gives access
		private:
			Vector *v; // points to a vector object of type T
			int index;    // represents the subscript number of the vector's
						  // array.
		public:
			VectIter(Vector& x);
		 
			T & operator++();
			//increments the iterator's indes and return the 
			//value of the element at the index position.

			T & operator++(int);
			//returns the value of the element at the index
			//position, then increments the index. 

			T & operator--();
			//decrements the iterator index, and return the
			//the value of the element at the index.

			T & operator--(int);
			//returns the value of the element at the index
			//position, then decrements the index.
			
			T & operator *();
			//returns the value of the element at the current index position.
    };

	Vector(int sz); 
	~Vector();

	T & operator[](int i);
	//returns existing value in the ith element of 
	//array or sets a new value to  the ith element in array. 
	  
	void ascending_sort();
	//sorts the vector values in ascending order. 
	  
	private:
	  T *array;               // points to the first element of an array of T
	  int size;               // size of array
	  void swap(T &, T &); // swaps the values of two elements in array
	public:
};

template <class T>
T & Vector<T>::VectIter::operator *()
{
  return v -> array[index];
}

template <class T>
Vector<T>::VectIter::VectIter(Vector& x)
{
  v = &x;
  index = 0;
}

template <class T>
T& Vector<T>::VectIter::operator--(int)
{
	if(index < 0) index = v->size-1;
	return v->array[index--];
}

template <class T>
T& Vector<T>::VectIter::operator++(int)
{
	if(index > v->size-1) index = 0;
	return v->array[index++];
}

template <class T>
T& Vector<T>::VectIter::operator--()
{
	if(index > v->size-1) index = v->size-1;
	if(index <= 0) index = v->size;
	return v->array[--index];
}

template <class T>
T& Vector<T>::VectIter::operator++()//prefix operator
{
	if(index >= v->size-1) index = -1;
	return v->array[++index];
}

template <class T>
void Vector<T>::swap(T &a,T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
T& Vector<T>::operator [] (int i)
{
  return array[i];
}

template <class T>
void Vector<T>::ascending_sort()
{
	for(int i=0; i< size-1; i++)
		for(int j=i+1; j < size; j++)
			if(array[i] > array[j])
				swap(array[i], array[j]);
}
template <>
void Vector<StringClass>::ascending_sort() //specialized ascending_sort template function for StringClass objects
{
	for(int i=0; i< size-1; i++)
		for(int j=i+1; j < size; j++)
			if(strcmp(array[i].c_str(), array[j].c_str()) > 0)
				swap(array[i], array[j]);
}
template <>
void Vector<const char*>::ascending_sort()//specialized ascending_sort template function for const char* types
{
	for(int i=0; i< size-1; i++)
		for(int j=i+1; j < size; j++)
			if(strcmp(array[i], array[j]) > 0)
				swap(array[i], array[j]);
}

template <class T>
Vector<T>::Vector(int sz)
{
  size=sz;
  array = new T[sz];
  assert (array != NULL);
}

template <class T>
Vector<T>::~Vector()
{
  delete [] array;
  array = NULL;
}
//Testing
int main()
{
	Vector<int> x(3);
	x[0] = 123;
	x[1] = -124;
	x[2] = 1;

	Vector<int>::VectIter iter(x);

	cout << "\nFirst element of vector x contains: " << *iter; 
	cout << "\nTesting an <int> Vector: " << endl;
	
	cout << "\n\nTesting sort";
	x.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iter++;
	
	cout << "\n\nTesting Prefix --:";
	for (int i=0; i<3 ; i++)
		cout << endl << --iter;
	
	cout << "\n\nTesting Prefix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << ++iter;	
	
	cout << "\n\nTesting Postfix --";
	for (int i=0; i<3 ; i++)
		cout << endl << iter--;

	cout << endl;

	cout << "Testing a <StringClass> Vector: " << endl;
	Vector<StringClass> y(3);
	y[0] = "Bar";
	y[1] = "Foo";
	y[2] = "All";;

	Vector<StringClass>::VectIter iters(y);
	
	cout << "\n\nTesting sort";
	y.ascending_sort();

	for (int i=0; i<3 ; i++)
		cout << endl << iters++;

	cout << "\n\nTesting Prefix --:";
	for (int i=0; i<3 ; i++)
		cout << endl << --iters;
	
	cout << "\n\nTesting Prefix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << ++iters;
	
	cout << "\n\nTesting Postfix --";
	for (int i=0; i<3 ; i++)
		cout << endl << iters--;
	
	cout << endl; cout << "Testing a <char *> Vector: " << endl;
	Vector<const char*> z(3);
	z[0] = "Orange";
	z[1] = "Pear";
	z[2] = "Apple";;
	
	Vector<const char*>::VectIter iterchar(z);
	
	cout << "\n\nTesting sort";
	z.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iterchar++;
	cout << "\nPrgram Terminated Successfully." << endl;
	return 0;
}