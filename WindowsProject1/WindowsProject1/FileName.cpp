#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100;

void Stack:: push(int e) { //��������� ������ ���� �������
		edg[top] = e;
		top++;
	}
void Stack:: pushwhole(Stack St) { //�������� � ���� ��� ������� �� ������� �����
		for (int i = 0; i < St.top; i++) { //���� � ������ ����� �� ���������� �������
			this->push(St.edg[i]); //�������� � ���� ���� ������� �� ������� �����
		}
	};

void Stack:: pop() { //������� ������ ���� �������
	edg[top] = 0;
	top--;
};
		
void Stack:: clean() { //������� ��� ���������� �����
	delete[]edg;

};

void Stack:: print() { //������� �� ����� ���� ����
	for (int i = 0; i < top; i++) {
		cout << edg[i] << endl;
	}
};

bool Stack:: isEmpty() { //�������� ������� �����
	if (edg[top] == 0) {
		return 1;
	}
	else
		return 0;
};

int Stack:: back() {
	return edg[top]; //���������� ������� �������
};

int* Stack:: out() {
	return edg; //���������� ���� ���� (��� ������� � �����)
};

//_____________________________________________________________________
Graph::Graph() {
	cin >> n;
};


int* Graph:: Search(int vn, int vk) {
	vector <int> M; //������ ����� 
	for (int i = 0; i < n; i++) M.push_back(0);
	int ks = 0; //������ �����
	int L = 0; //��� �������� ������
	Stack St; //���������� ���� ��� ���������� ��������� DFS
	Stack out; //���� � ����� 
	St.push(vn); //������� � ���� ��������� �������
	int len_min = 0; //����������� ����� = -1

	while (ks >= 0) { //���� ���� �� ����
		int v = St.back();
		int Pr = 0;

		int j;
		for (j = L; j < n; j++) {
			if (adjac(v, j) == 1 && j != vn) {
				if (j == vk) {
					St.push(vk);
					out.pushwhole(St); //��������� � ���� ��������� ���� 
					if (len_min > St.top || len_min == 0) len_min = St.top;
					St.pop();
				}
				else {
					if (M[j] == 0) { //���� ������� �����
						Pr = 1; //
						break;
					}
				}
			}
		}
		if (Pr == 1) {
			ks += 1;
			St.push(j);
			L = 0;
			M[j] = 1;
		}
		else {
			L = v + 1; //��������� ���������� ������� + 1
			M[v] = 0;
			ks -= 1;
			St.pop();
		}
	}
	return out.out();
};

//__________________________________________________________________________

void Graph1:: push(int x, Graph1* graph) {
		Graph1* temp = new Graph1(); //������� ����� ����, �������� ��������� �� ����
		if (graph->next == NULL) { //���� ��������� �� ��������� ���� ����
			temp->ind = x; //����������� ������
			graph->next = temp; 
		}
		else push(x, graph->next);
	}

void Graph1:: addgr(int Matrix[100][100], int m) {
		for (int i = 0; i < m; i++) {
			temp = arr[i]; //������ ���� � ������
			for (int j = 0; j < m; j++) { 
				
				temp->push(Matrix[i][j], temp);
			}
		}
		n = m;

	}

bool Graph1:: adjac(int v, int j) { //�������� ���������
		Graph1* temp = arr[v]; //������� ���� - ��������������� ������ ���� ������ ������ ������� �������
		for (int i = 0; i < n; i++) { 
			if (temp->ind == j) //���������, ������������ �� ������� � ��������� ������ 
				return 1;
			else temp = temp->next;

		}
		return 0;

};

