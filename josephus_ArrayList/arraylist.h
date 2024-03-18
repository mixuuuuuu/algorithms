#pragma once
#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include<iostream>

template<typename T>
class ArrayList {
private:
	T* m_list;
	int m_maxsize; //�ռ��С
	int m_curlen;  //ʵ�ʱ�
	int m_position;
public:
	ArrayList(const int size);
	~ArrayList();
	void clear(); //��ձ�
	int length(); //����ʵ�ʱ�
	bool isEmpty(); //���Ƿ��
	bool appendValue(const T value); //�ڱ�β���Ԫ��
	bool insertValue(const int p, const T value); //��ָ��λ�ò���Ԫ��
	bool deleteValue(const int p); //ɾ��Ԫ��
	bool getValue(const int p, T& value); //����ָ��Ԫ������
	bool getValuePos(int& p, const T value); //����valueԪ�����ݵ�λ��
	void printList(); //��ӡ��Ԫ��
};

template<typename T>
ArrayList<T>::ArrayList(const int size) {
	this->m_maxsize = size;
	this->m_list = new T[size];
	this->m_curlen = this->m_position = 0;
}

template<typename T>
ArrayList<T>::~ArrayList() {
	delete[] this->m_list;
}

template<typename T>
void ArrayList<T>::clear() {
	for (int i = 0;i < this->m_curlen;i++) {
		m_list[i] = 0;
	}
	this->m_curlen = 0;
}

template<typename T>
int ArrayList<T>::length() {
	return this->m_curlen;
}

template<typename T>
bool ArrayList<T>::isEmpty() {
	if (this->m_curlen == 0) {
		return true;
	}
	else return false;
}

template<typename T>
bool ArrayList<T>::appendValue(const T value) {
	if (this->m_curlen >= this->m_maxsize) {
		std::cerr << "The List is overflow" << std::endl; //�Ƿ��пռ�
		return false;
	}
	this->m_list[m_curlen] = value;
	this->m_curlen++;
	return true;
}

template<typename T>
bool ArrayList<T>::insertValue(const int p, const T value) {
	if (this->m_curlen >= this->m_maxsize - 1) {
		std::cerr << "The list is overflow" << std::endl; //�Ƿ��пռ�
		return false;
	}
	if (p<0 || p>(this->m_curlen - 1)) {
		std::cerr << "Insertion point is illegal" << std::endl;
		return false;
	}
	for (int i = this->m_curlen;i > p; i--) {
		this->m_list[i] = this->m_list[i - 1];
	}
	this->m_list[p] = value;
	this->m_curlen++;
	return true;
}

template<typename T>
bool ArrayList<T>::deleteValue(const int p) {
	if (this->m_curlen <= 0) {
		std::cerr << "No element to delete" << std::endl;
		return false;
	}
	if (p<0 || p>(this->m_curlen - 1)) {
		std::cerr << "deletion is illegal" << std::endl;
		return false;
	}
	for (int i = p;i < this->m_curlen;i++) {
		this->m_list[i] = this->m_list[i + 1];
	}
	this->m_curlen--;
	return true;
}

template<typename T>
bool ArrayList<T>::getValue(const int p, T& value) {
	if (p<0 || p>(this->m_maxsize - 1)) {
		std::cerr << "position is illegal" << std::endl;
		return false;
	}
	value = this->m_list[p];
	return true;
}

template<typename T>
bool ArrayList<T>::getValuePos(int& p, const T value) {
	for (int i = 0;i < this->m_curlen;i++) {
		if (value == m_list[i]) {
			p = i;
			return true;
		}
	}
	return false;
}

template<typename T>
void ArrayList<T>::printList() {
	if (this->m_curlen == 0) {
		std::cout << "The list is empty" << std::endl;
	}
	for (int i = 0;i < this->m_curlen;i++) {
		std::cout << this->m_list[i] << ' ';
	}
	std::cout << std::endl;
}

#endif // !ARRAYLIST_H
