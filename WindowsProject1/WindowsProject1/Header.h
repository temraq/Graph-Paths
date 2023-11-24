#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100;

class Stack {
public:
	int edg[MAX_SIZE]; //стек представл€ет собой массив неких вершин
	int top = 0; //верх стека = размер стека минус 1
	void push(int e);
	void pushwhole(Stack St);
	void pop();
	void clean();
	void print();
	bool isEmpty();
	int back();
	int* out();
};

class Graph {

protected: int n;

public:
	Graph();

	virtual void addgr(int Matrix[100][100], int m) = 0; //функци€ ввода всего графа

	int* Search(int vn, int vk);

	virtual bool adjac(int v, int j) = 0; //виртуальна€ функци€ нахождени€ смежных вершин в графе
};

class Graph1 : public Graph { //производный класс
public:

	int ind;
	Graph1* next; //указатель на следующий 
	Graph1* arr[MAX_SIZE]; //одномерный массив списков. кажда€ €чейка массива содержит список (указатель на первый узел списка, который в свою очередь содержит указатель на второй и т.д...)
	Graph1* temp; 

	void push(int x, Graph1* graph);
	void addgr(int Matrix[100][100], int m);
	bool adjac(int v, int j);

};

