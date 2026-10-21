#include <cstdint>
#include <iostream>
#include <limits>
#include <string>

#include "input.h"

double Fraction(double x) {
  return x - static_cast<int>(x);
}

int CharToNum(char x) {
  return x - '0';
}

bool Is2Digits(int x) {
  return (x >= 10 && x <= 99) || (x >= -99 && x <= -10);
}

bool IsInRange(int a, int b, int num) {
  return (a <= num && num <= b) || (b <= num && num <= a);
}

bool IsEqual(int a, int b, int c) {
  return a == b && b == c;
}

int Abs(int x) {
  if (x < 0) {
    return -x;
  }
  return x;
}

bool Is35(int x) {
  if (x % 15 == 0) {
    return false;
  }
  return x % 3 == 0 || x % 5 == 0;
}

int Max3(int x, int y, int z) {
  int max = x;
  if (y > max) {
    max = y;
  }
  if (z > max) {
    max = z;
  }
  return max;
}

int Sum2(int x, int y) {
  int sum = x + y;
  if (sum >= 10 && sum <= 19) {
    return 20;
  }
  return sum;
}

std::string Day(int x) {
  switch (x) {
    case 1:
      return "понедельник";
    case 2:
      return "вторник";
    case 3:
      return "среда";
    case 4:
      return "четверг";
    case 5:
      return "пятница";
    case 6:
      return "суббота";
    case 7:
      return "воскресенье";
    default:
      return "это не день недели";
  }
}

std::string ListNums(int x) {
  std::string result;
  for (int i = 0; i <= x; ++i) {
    result += std::to_string(i) + " ";
  }
  return result;
}

std::string Chet(int x) {
  std::string result;
  for (int i = 0; i <= x; i += 2) {
    result += std::to_string(i) + " ";
  }
  return result;
}

int NumLen(int64_t x) {
  int length = 0;
  do {
    x /= 10;
    ++length;
  } while (x != 0);
  return length;
}

void Square(int x) {
  for (int i = 0; i < x; ++i) {
    std::cout << std::string(x, '*') << "\n";
  }
}

void RightTriangle(int x) {
  for (int i = 1; i <= x; ++i) {
    std::cout << std::string(x - i, ' ') << std::string(i, '*') << "\n";
  }
}

int FindFirst(int arr[], int size, int x) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

int MaxAbs(int arr[], int size) {
  int result = arr[0];
  for (int i = 1; i < size; ++i) {
    if (Abs(arr[i]) > Abs(result)) {
      result = arr[i];
    }
  }
  return result;
}

int* Add(int arr[], int size, int ins[], int ins_size, int pos) {
  int* result = new int[size + ins_size];
  for (int i = 0; i < pos; ++i) {
    result[i] = arr[i];
  }
  for (int i = 0; i < ins_size; ++i) {
    result[pos + i] = ins[i];
  }
  for (int i = pos; i < size; ++i) {
    result[ins_size + i] = arr[i];
  }
  return result;
}

int* ReverseBack(int arr[], int size) {
  int* result = new int[size];
  for (int i = 0; i < size; ++i) {
    result[i] = arr[size - 1 - i];
  }
  return result;
}

int* FindAll(int arr[], int size, int x, int& count) {
  int* result = new int[size];
  count = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) {
      result[count] = i;
      ++count;
    }
  }
  return result;
}

void PrintArray(int arr[], int size) {
  std::cout << "[";
  for (int i = 0; i < size; ++i) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << arr[i];
  }
  std::cout << "]\n";
}

void RunFraction() {
  double x = ReadValue<double>("x = ", kMinValue, kMaxValue);
  std::cout << "Результат: " << Fraction(x) << "\n";
}

void RunCharToNum() {
  char x = ReadValue<char>("x = ", '0', '9');
  std::cout << "Результат: " << CharToNum(x) << "\n";
}

void RunIs2Digits() {
  int x = ReadValue<int>("x = ", kMinValue, kMaxValue);
  std::cout << "Результат: " << Is2Digits(x) << "\n";
}

void RunIsInRange() {
  int a = ReadValue<int>("a = ", kMinValue, kMaxValue);
  int b = ReadValue<int>("b = ", kMinValue, kMaxValue);
  int num = ReadValue<int>("num = ", kMinValue, kMaxValue);
  std::cout << "Результат: " << IsInRange(a, b, num) << "\n";
}

void RunIsEqual() {
  int a = ReadValue<int>("a = ", kMinValue, kMaxValue);
  int b = ReadValue<int>("b = ", kMinValue, kMaxValue);
  int c = ReadValue<int>("c = ", kMinValue, kMaxValue);
  std::cout << "Результат: " << IsEqual(a, b, c) << "\n";
}

void RunAbs() {
  int x = ReadValue<int>("x = ", kMinValue, kMaxValue);
  std::cout << "Результат: " << Abs(x) << "\n";
}

void RunIs35() {
  int x = ReadValue<int>("x = ", kMinValue, kMaxValue);
  std::cout << "Результат: " << Is35(x) << "\n";
}

void RunMax3() {
  int x = ReadValue<int>("x = ", kMinValue, kMaxValue);
  int y = ReadValue<int>("y = ", kMinValue, kMaxValue);
  int z = ReadValue<int>("z = ", kMinValue, kMaxValue);
  std::cout << "Результат: " << Max3(x, y, z) << "\n";
}

void RunSum2() {
  int x = ReadValue<int>("x = ", kMinValue, kMaxValue);
  int y = ReadValue<int>("y = ", kMinValue, kMaxValue);
  std::cout << "Результат: " << Sum2(x, y) << "\n";
}

void RunDay() {
  int x = ReadValue<int>("x = ", kMinValue, kMaxValue);
  std::cout << "Результат: " << Day(x) << "\n";
}

void RunListNums() {
  int x = ReadValue<int>("x = ", 0, kMaxCount);
  std::cout << "Результат: " << ListNums(x) << "\n";
}

void RunChet() {
  int x = ReadValue<int>("x = ", 0, kMaxCount);
  std::cout << "Результат: " << Chet(x) << "\n";
}

void RunNumLen() {
  int64_t min = std::numeric_limits<int64_t>::min();
  int64_t max = std::numeric_limits<int64_t>::max();
  int64_t x = ReadValue<int64_t>("x = ", min, max);
  std::cout << "Результат: " << NumLen(x) << "\n";
}

void RunSquare() {
  int x = ReadValue<int>("x = ", 1, kMaxCount);
  Square(x);
}

void RunRightTriangle() {
  int x = ReadValue<int>("x = ", 1, kMaxCount);
  RightTriangle(x);
}

void RunFindFirst() {
  int size = ReadValue<int>("Размер arr: ", 1, kMaxCount);
  int* arr = ReadArray("arr", size);
  int x = ReadValue<int>("x = ", kMinValue, kMaxValue);
  std::cout << "Результат: " << FindFirst(arr, size, x) << "\n";
  delete[] arr;
}

void RunMaxAbs() {
  int size = ReadValue<int>("Размер arr: ", 1, kMaxCount);
  int* arr = ReadArray("arr", size);
  std::cout << "Результат: " << MaxAbs(arr, size) << "\n";
  delete[] arr;
}

void RunAdd() {
  int size = ReadValue<int>("Размер arr: ", 1, kMaxCount);
  int* arr = ReadArray("arr", size);
  int ins_size = ReadValue<int>("Размер ins: ", 1, kMaxCount);
  int* ins = ReadArray("ins", ins_size);
  int pos = ReadValue<int>("pos = ", 0, size);
  int* result = Add(arr, size, ins, ins_size, pos);
  std::cout << "Результат: ";
  PrintArray(result, size + ins_size);
  delete[] arr;
  delete[] ins;
  delete[] result;
}

void RunReverseBack() {
  int size = ReadValue<int>("Размер arr: ", 1, kMaxCount);
  int* arr = ReadArray("arr", size);
  int* result = ReverseBack(arr, size);
  std::cout << "Результат: ";
  PrintArray(result, size);
  delete[] arr;
  delete[] result;
}

void RunFindAll() {
  int size = ReadValue<int>("Размер arr: ", 1, kMaxCount);
  int* arr = ReadArray("arr", size);
  int x = ReadValue<int>("x = ", kMinValue, kMaxValue);
  int count = 0;
  int* result = FindAll(arr, size, x, count);
  std::cout << "Результат: ";
  PrintArray(result, count);
  delete[] arr;
  delete[] result;
}

void PrintMenu() {
  std::cout << R"(Лабораторная работа №1
Задание 1. Методы          Задание 2. Условия
  11 - Дробная часть         21 - Модуль числа
  13 - Букву в число         23 - Тридцать пять
  15 - Двузначное            25 - Тройной максимум
  17 - Диапазон              27 - Двойная сумма
  19 - Равенство             29 - День недели
Задание 3. Циклы           Задание 4. Массивы
  31 - Числа подряд          41 - Поиск первого значения
  33 - Четные числа          43 - Поиск максимального
  35 - Длина числа           45 - Добавление массива в массив
  37 - Квадрат               47 - Возвратный реверс
  39 - Правый треугольник    49 - Все вхождения
0 - Выход
)";
}

int main() {
  std::cout << std::boolalpha;
  std::cout.precision(10);
  PrintMenu();
  while (true) {
    std::cout << "\n";
    int task = ReadValue<int>("Номер задачи: ", 0, 49);
    switch (task) {
      case 0:
        return 0;
      case 11:
        RunFraction();
        break;
      case 13:
        RunCharToNum();
        break;
      case 15:
        RunIs2Digits();
        break;
      case 17:
        RunIsInRange();
        break;
      case 19:
        RunIsEqual();
        break;
      case 21:
        RunAbs();
        break;
      case 23:
        RunIs35();
        break;
      case 25:
        RunMax3();
        break;
      case 27:
        RunSum2();
        break;
      case 29:
        RunDay();
        break;
      case 31:
        RunListNums();
        break;
      case 33:
        RunChet();
        break;
      case 35:
        RunNumLen();
        break;
      case 37:
        RunSquare();
        break;
      case 39:
        RunRightTriangle();
        break;
      case 41:
        RunFindFirst();
        break;
      case 43:
        RunMaxAbs();
        break;
      case 45:
        RunAdd();
        break;
      case 47:
        RunReverseBack();
        break;
      case 49:
        RunFindAll();
        break;
      default:
        std::cout << "Такой задачи нет\n";
        break;
    }
  }
}
