#ifndef WEKTOR_H_
#define WEKTOR_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


template<class T>
class Wektor{
private:
	T* item;
	int maxSize;
	int actualSize;
	void allocNew();
public:
	Wektor();
	Wektor(int size);
	~Wektor();
	Wektor(const Wektor& wektor);
	void PushBack(const T& itemToPush);
	void Insert(int iterator, const T& itemToPush);
	void Delete(int iterator);
	void Erase();
	int Size() const;
	T& operator[](int i) const;
	class Iterator;
	friend class Iterator;
	class Iterator{
		Wektor& wektor;
		int index;
	public:
		Iterator(Wektor& wek) : wektor(wek), index(0){}
		Iterator(Wektor& wek, bool) : wektor(wek), index(wektor.actualSize){}
		T operator*() const { return wektor.item[index]; }
		T operator++(){ return wektor.item[++index]; }
		T operator++(int){ return wektor.item[index++]; }
		Iterator& operator+=(int amount){
			index += amount;
			return *this;
		}
		bool operator==(const Iterator& iter) const{
			return index == iter.index;
		}
		bool operator!=(const Iterator& iter) const{
			return index != iter.index;
		}
	};
	Iterator begin(){ return Iterator(*this); }
	Iterator end(){ return Iterator(*this, true); }

};


template<class T>
Wektor<T>::Wektor(){
	maxSize = 3;
	actualSize = 0;
	item = new T[maxSize];
}

template<class T>
Wektor<T>::Wektor(int size){
	maxSize = size;
	actualSize = 0;
	item = new T[maxSize];
}

template<class T>
Wektor<T>::~Wektor(){
	delete[] item;
}

template<class T>
Wektor<T>::Wektor(const Wektor& wektor){
	//Nie potrzebne
}

template<class T>
void Wektor<T>::PushBack(const T& itemToPush){
	if (actualSize + 1 > maxSize)
		allocNew();
	item[actualSize] = itemToPush;
	actualSize++;
}

template<class T>
T& Wektor<T>::operator[](int i) const{
	return item[i];
}

template<class T>
void Wektor<T>::allocNew(){
	maxSize = actualSize * 2;
	T* temp = new T[maxSize];
	for (int i = 0; i < actualSize; i++)
	{
		temp[i] = item[i];
	}
	delete[] item;
	item = temp;
}

template<class T>
int Wektor<T>::Size() const{
	return actualSize;
}

template<class T>
void Wektor<T>::Insert(int iterator, const T& itemToPush){
	if (actualSize + 1 > maxSize)
		allocNew();
	for (int i = (actualSize - 1); i >= (iterator - 1); i--)
	{
		item[i + 1] = item[i];
	}
	item[iterator - 1] = itemToPush;
	actualSize++;
}

template<class T>
void Wektor<T>::Delete(int iterator){
	for (int i = iterator; i < actualSize; i++)
	{
		item[i - 1] = item[i];
	}
	actualSize--;
}

template<class T>
void Wektor<T>::Erase(){
	delete[] item;
	item = new T[maxSize];
	actualSize = 0;
}


#endif