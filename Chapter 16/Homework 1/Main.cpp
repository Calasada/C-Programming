#include <iostream>
using namespace std;

void moveDisks(int, int, int, int, int**, int);
void move(int**, int, int, int);
void print(int**);

int dim = 3;

int main() {
  int** matrix = new int*[dim];
  for (int i = 0; i < dim; i++) {
    matrix[i] = new int[3];
  }
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        matrix[i][j] = i + 1;
      } else {
        matrix[i][j] = 0;
      }
    }
  }

  print(matrix);

  moveDisks(dim, 1, 3, 2, matrix, dim);

  print(matrix);
  system("pause");
  return 0;
}

void moveDisks(int count, int baseNeedle, int destNeedle, int interNeedle,
               int** matrix, int l) {
  if (count > 0) {
    moveDisks(count - 1, baseNeedle, interNeedle, destNeedle, matrix, l);
    cout << "Move disk " << count << " from " << baseNeedle << " to "
         << destNeedle << "." << endl;
    move(matrix, baseNeedle, destNeedle, l);
    print(matrix);
    moveDisks(count - 1, interNeedle, destNeedle, baseNeedle, matrix, l);
  }
}

void move(int** matrix, int original_column, int new_column, int l) {
  for (int i = 0; i < l; i++) {
    if (matrix[i][original_column - 1] > 0) {
      for (int j = 0; j <= l; j++) {
        if (j == l) {
          matrix[j - 1][new_column - 1] = matrix[i][original_column - 1];
        } else if (matrix[j][new_column - 1] > 0) {
          matrix[j - 1][new_column - 1] = matrix[i][original_column - 1];
          break;
        }
      }
      matrix[i][original_column - 1] = 0;
      break;
    }
  }
}

void print(int** matrix) {
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < 3; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}
