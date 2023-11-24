#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100;

class Stack {
public:
	int edg[MAX_SIZE]; //���� ������������ ����� ������ ����� ������
	int top = 0; //���� ����� = ������ ����� ����� 1
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

	virtual void addgr(int Matrix[100][100], int m) = 0; //������� ����� ����� �����

	int* Search(int vn, int vk);

	virtual bool adjac(int v, int j) = 0; //����������� ������� ���������� ������� ������ � �����
};

class Graph1 : public Graph { //����������� �����
public:

	int ind;
	Graph1* next; //��������� �� ��������� 
	Graph1* arr[MAX_SIZE]; //���������� ������ �������. ������ ������ ������� �������� ������ (��������� �� ������ ���� ������, ������� � ���� ������� �������� ��������� �� ������ � �.�...)
	Graph1* temp; 

	void push(int x, Graph1* graph);
	void addgr(int Matrix[100][100], int m);
	bool adjac(int v, int j);

};

