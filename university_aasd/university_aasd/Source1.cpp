#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class student {
public:
	string name,
		group;
	vector <int> points;
	student() {
		name = "";
		group = "";
		vector <int> points;
	};
	student(const string& name_new, const string& group_new) {
		name = name_new;
		group = group_new;
		vector <int> points;
	}
	void add_point() {
		int point;
		cin >> point;
		points.push_back(point);
		cout << "done" << '\n';
	}
	void information() {
		cout << "name : " << name << '\n' << "group : " << group << '\n';
	}
	void points_print() {
		if (points.size() == 0) {
			cout << "Data not exist \n";
		}
		for (const auto& s : points) {
			cout << s << ' ';
		}
		cout << '\n';
	}
	void average() {
		int size,
			sum = 0;
		double average;
		size = points.size();
		for (const auto& s : points) {
			sum += s;
		}
		average = (sum / size);
		cout << "average point: " << average << '\n';
	}
	void sorting_bubble() {
		int size = points.size();
		int i = 0;
		int buf;
		char swap_cnt = 0;
		while (i < size)
		{
			if (i + 1 != size && points[i] > points[i + 1])
			{
				buf = points[i];
				points[i] = points[i + 1];
				points[i + 1] = buf;
				swap_cnt = 1;
			}
			i++;
			if (i == size && swap_cnt == 1)
			{
				swap_cnt = 0;
				i = 0;
			}
		}
	}
	void sorting_insert() {
		int temp, item;
		int size = points.size();
		for (int counter = 1; counter < size; counter++)
		{
			temp = points[counter];
			item = counter - 1;
			while (item >= 0 && points[item] > temp)
			{
				points[item + 1] = points[item];
				points[item] = temp;
				item--;
			}
		}

	}
	void sorting_shell() {
		int i, j, step;
		int n = points.size();
		int tmp;
		for (step = n / 2; step > 0; step /= 2)
			for (i = step; i < n; i++)
			{
				tmp = points[i];
				for (j = i; j >= step; j -= step)
				{
					if (tmp < points[j - step])
						points[j] = points[j - step];
					else
						break;
				}
				points[j] = tmp;
			}
	}
	void quick_sort()
	{
		sort(begin(points), end(points));
		/*
		int pivot; // разрешающий элемент
		int l_hold = left; //левая граница
		int r_hold = right; // правая граница
		pivot = numbers[left];
		while (left < right) // пока границы не сомкнутся
		{
			while ((numbers[right] >= pivot) && (left < right))
				right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
			if (left != right) // если границы не сомкнулись
			{
				numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
				left++; // сдвигаем левую границу вправо
			}
			while ((numbers[left] <= pivot) && (left < right))
				left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
			if (left != right) // если границы не сомкнулись
			{
				numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
				right--; // сдвигаем правую границу вправо
			}
		}
		numbers[left] = pivot; // ставим разрешающий элемент на место
		pivot = left;
		left = l_hold;
		right = r_hold;
		if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
			quickSort(numbers, left, pivot - 1);
		if (right > pivot)
			quickSort(numbers, pivot + 1, right);
			*/
	}
};
int main() {
	int nums_operation;
	student first = { "name", "group" };
	cout << "Enter the number of operations\n";
	cin >> nums_operation;
	for (int i = 0; i < nums_operation; ++i) {
		cout << "select operation: \n add_points \n print_points \n print_information \n average_point \n sorting_bubble \n sorting_inserted \n sorting_shell \n quick_sort \n exit \n";
		string select;
		cin >> select;
		if (select == "print_points") {
			first.points_print();
		}
		else if (select == "add_points") {

			first.add_point();
		}
		else if (select == "print_information") {
			first.information();
		}
		else if (select == "average_point") {
			first.average();
		}
		else if (select == "sorting_bubble") {
			first.sorting_bubble();
			cout << "done\n";
		}
		else if (select == "sorting_insert") {
			first.sorting_insert();
			cout << "done\n";
		}
		else if (select == "sorting_shell") {
			first.sorting_shell();
			cout << "done \n";
		}
		else if (select == "quick_sort") {
			first.quick_sort();
			//cout << "this is a first note";
			cout << "done\n";
		}
	}
}