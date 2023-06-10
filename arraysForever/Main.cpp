#include<iostream>
#include<cstdlib>
#include<ctime>

int main() {
	system("chcp 1251>nul");
	
	//Задание "Подготовка массива
	const int rows = 10, cols = 10;
	int mx[rows][cols];
	//вывод и заполнение массива
	srand(time(NULL));
	for (int i = 0; i < rows; i++) {//цикл i, перебирающий ряды в массиве
		for (int j = 0; j < cols; j++) {//цикл j, перебирающий(колонки) элементы рядов
			mx[i][j] = rand() % 100;//[0...100)
			std::cout << mx[i][j] << '\t';
		}
		std::cout << std::endl;
    }
	std::cout << std::endl;

	//Задача1. Суммы всех рядов массива
	std::cout << "Задача 1\nСуммы всех рядов массива:\n";
	int row_sum;
	for (int i = 0; i < rows; i++) {
		row_sum = 0;//обнуление суммы перед каждым новым рядом
		for (int j = 0; j < cols; j++)//цикл j, перебирающий элементы текущего ряда
			row_sum += mx[i][j];
		std::cout << "Ряд №" << i << ": " << row_sum << std::endl;
	}
	std::cout << std::endl;

	//Задача 2. Сортировка выбранного ряда
	std::cout << "Задача 2.\nВведите номер ряда (0 - 9)\n";
	int n;
	std::cin >> n;
	for (int i = cols - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (mx[n][j] > mx[n][j + 1])
				std::swap(mx[n][j], mx[n][j + 1]);
	std::cout << "Итоговый массив:\n";
	for (int i = 0; i < rows; i++) {//цикл i, перебирающий ряды в массиве
		for (int j = 0; j < cols; j++) //цикл j, перебирающий(колонки) элементы рядов
			std::cout << mx[i][j] << '\t';
		if (i == n)
			std::cout << "<- отсортированный ряд";
		std::cout << std::endl;
	}

	return 0;
}