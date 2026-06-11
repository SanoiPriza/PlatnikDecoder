#include <array>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>


const int KEY_SIZE = 17;
const int SEGMENT_SIZE = 8;

int find(const char *str, char c) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == c) {
      return i;
    }
  }
  return -1;
}

void swap(char in[], int a) {
  int segments = SEGMENT_SIZE / a;
  for (int j = 0; j < segments; ++j) {
    int s = j * 2 * a;
    for (int i = 0; i < a; i++) {
      std::swap(in[i + s], in[i + s + a]);
    }
  }
}

void clear_screen() {
#ifdef _WIN32
  std::system("cls");
#else
  std::system("clear");
#endif
}

int main() {
  const char k[] = "lmnopqrstuvwxyz{";
  std::array<int, 24> order = {0, 1, 2, 3, 4, 0, 3, 5, 2, 1, 5, 4,
                               3, 6, 6, 2, 4, 2, 2, 4, 3, 2, 7, 7};
  std::array<std::string, 8> pkey;

  while (true) {
    std::cout << "1. Dekodowanie" << std::endl;
    std::cout << "2. Wyjscie" << std::endl;

    int choice;
    std::cin >> choice;

    if (std::cin.fail()) {
      if (std::cin.eof()) {
        break;
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      clear_screen();
      std::cout << "Niepoprawny wybor opcji." << std::endl;
      continue;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 2) {
      std::string answer;
      std::cout << "Czy na pewno chcesz opuscic program? (T/N): ";
      if (!(std::cin >> answer)) {
        break;
      }
      if (answer == "T" || answer == "t") {
        break;
      } else {
        clear_screen();
        continue;
      }
    } else if (choice == 1) {
      clear_screen();
      std::string input;
      std::cout << "Podaj zaszyfrowane haslo: ";
      if (!(std::cin >> input)) {
        break;
      }

      if (input.empty()) {
        std::cout << "Blad: Haslo nie moze byc puste." << std::endl
                  << std::endl;
        continue;
      }
      if (input.length() % 2 != 0) {
        std::cout << "Blad: Dlugosc zaszyfrowanego hasla musi byc parzysta."
                  << std::endl
                  << std::endl;
        continue;
      }
      if (input.length() > 48) {
        std::cout << "Blad: Zaszyfrowane haslo jest za dlugie (maksymalnie 48 "
                     "znakow)."
                  << std::endl
                  << std::endl;
        continue;
      }

      bool valid_chars = true;
      for (char c : input) {
        if (find(k, c) == -1) {
          valid_chars = false;
          break;
        }
      }
      if (!valid_chars) {
        std::cout << "Blad: Haslo zawiera niepoprawne znaki." << std::endl
                  << std::endl;
        continue;
      }

      for (int i = 0; i < 8; i++) {
        pkey[i] = k;
      }

      swap(&pkey[0][0], 8);
      swap(&pkey[1][0], 4);
      swap(&pkey[1][0], 1);
      swap(&pkey[2][0], 8);
      swap(&pkey[2][0], 1);
      swap(&pkey[3][0], 1);
      swap(&pkey[4][0], 4);
      swap(&pkey[5][0], 2);
      swap(&pkey[6][0], 2);
      swap(&pkey[6][0], 1);
      swap(&pkey[7][0], 4);
      swap(&pkey[7][0], 2);
      swap(&pkey[7][0], 1);

      std::cout << "Odszyfrowane haslo: ";
      for (int i = 0, j = 0; i < input.length(); i = (++j) * 2) {
        int a = find(pkey[order[j]].c_str(), input[i]);
        int b = find(pkey[order[j]].c_str(), input[i + 1]);
        std::cout << static_cast<char>(a + 16 * b);
      }
      std::cout << std::endl << std::endl;
    } else {
      clear_screen();
      std::cout << "Niepoprawny wybor opcji." << std::endl;
    }
  }

  return 0;
}
