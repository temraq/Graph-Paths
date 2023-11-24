#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100;

void Stack:: push(int e) { //добавляет наверх одну вершину
		edg[top] = e;
		top++;
	}
void Stack:: pushwhole(Stack St) { //добавить в стек все вершины из другого стека
		for (int i = 0; i < St.top; i++) { //пока в другом стеке не закончатся вершины
			this->push(St.edg[i]); //добавить в этот стек вершину из другого стека
		}
	};

void Stack:: pop() { //удаляет сверху одну вершину
	edg[top] = 0;
	top--;
};
		
void Stack:: clean() { //удаляет все содержимое стека
	delete[]edg;

};

void Stack:: print() { //выводит на экран весь стек
	for (int i = 0; i < top; i++) {
		cout << edg[i] << endl;
	}
};

bool Stack:: isEmpty() { //проверка пустоты стека
	if (edg[top] == 0) {
		return 1;
	}
	else
		return 0;
};

int Stack:: back() {
	return edg[top]; //возвращает верхнюю вершину
};

int* Stack:: out() {
	return edg; //возвращает весь стек (все вершины в стеке)
};

//_____________________________________________________________________
Graph::Graph() {
	cin >> n;
};


int* Graph:: Search(int vn, int vk) {
	vector <int> M; //вектор меток 
	for (int i = 0; i < n; i++) M.push_back(0);
	int ks = 0; //размер стека
	int L = 0; //для перебора вершин
	Stack St; //переменный стек для выполнения алгоритма DFS
	Stack out; //стек с путем 
	St.push(vn); //добавим в стек стартовую вершину
	int len_min = 0; //минимальная длина = -1

	while (ks >= 0) { //пока стек не пуст
		int v = St.back();
		int Pr = 0;

		int j;
		for (j = L; j < n; j++) {
			if (adjac(v, j) == 1 && j != vn) {
				if (j == vk) {
					St.push(vk);
					out.pushwhole(St); //добавляем в путь собранный стек 
					if (len_min > St.top || len_min == 0) len_min = St.top;
					St.pop();
				}
				else {
					if (M[j] == 0) { //если вершина белая
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
			L = v + 1; //последняя пройденная вершина + 1
			M[v] = 0;
			ks -= 1;
			St.pop();
		}
	}
	return out.out();
};

//__________________________________________________________________________

void Graph1:: push(int x, Graph1* graph) {
		Graph1* temp = new Graph1(); //создаем новый узел, получаем указатель на него
		if (graph->next == NULL) { //если указатель на следующий узел пуст
			temp->ind = x; //присваиваем данные
			graph->next = temp; 
		}
		else push(x, graph->next);
	}

void Graph1:: addgr(int Matrix[100][100], int m) {
		for (int i = 0; i < m; i++) {
			temp = arr[i]; //первый узел в ячейке
			for (int j = 0; j < m; j++) { 
				
				temp->push(Matrix[i][j], temp);
			}
		}
		n = m;

	}

bool Graph1:: adjac(int v, int j) { //проверка смежности
		Graph1* temp = arr[v]; //текущий узел - соответствующий первый узел нужной ячейки массива списков
		for (int i = 0; i < n; i++) { 
			if (temp->ind == j) //проверяем, присутствует ли элемент в выбранном списке 
				return 1;
			else temp = temp->next;

		}
		return 0;

};

