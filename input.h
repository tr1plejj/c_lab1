#ifndef LAB1_INPUT_H_
#define LAB1_INPUT_H_

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

inline constexpr int kMinValue = -1000000000;
inline constexpr int kMaxValue = 1000000000;
inline constexpr int kMaxCount = 100;

template <typename T>
T ReadValue(const std::string& prompt, T min, T max) {
  while (true) {
    std::cout << prompt;
    std::string line;
    if (!std::getline(std::cin, line)) {
      std::exit(0);
    }
    std::istringstream stream(line);
    T value;
    std::string extra;
    if (stream >> value && !(stream >> extra) && value >= min &&
        value <= max) {
      return value;
    }
    std::cout << "Ошибка: введите значение от " << min << " до " << max
              << "\n";
  }
}

inline int* ReadArray(const std::string& name, int size) {
  int* arr = new int[size];
  for (int i = 0; i < size; ++i) {
    std::string prompt = name + "[" + std::to_string(i) + "] = ";
    arr[i] = ReadValue<int>(prompt, kMinValue, kMaxValue);
  }
  return arr;
}

#endif  // LAB1_INPUT_H_
