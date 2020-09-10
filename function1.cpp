#define N 8 
#include <iostream>
using namespace std;

int lDiagonal[20] = { 0 };
int rDiagonal[20] = { 0 };
int cIndicator[20] = { 0 };

void printTotal(int Board[N][N])
{
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++)

            cout << " " << Board[i][j] << " ";

        cout << "\n";
    }
}

bool NQ(int Board[N][N], int column)
{
    if (column >= N)

        return true;



    for (int i = 0; i < N; i++) {

        if ((lDiagonal[i - column + N - 1] != 1 && rDiagonal[i - column] != 1) && cIndicator[i] != 1) {

            Board[i][column] = 1;

            lDiagonal[i - column + N - 1] = rDiagonal[i + column] = cIndicator[i] = 1;



            if (NQ(Board, column - 1))

                return false;


            Board[i][column] = 0;
            lDiagonal[i - column + N - 1] = rDiagonal[i + column] = cIndicator[i] = 0;
        }
    }

    return false;
}

bool Result()
{
    int Board[N][N] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

    if (NQ(Board, 0) == true) {

        return false;
    }

    printTotal(Board);
    return false;
}


int main()
{
   Result();
    return 0;
}
