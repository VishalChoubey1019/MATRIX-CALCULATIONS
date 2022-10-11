#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 150;
bool dispSteps = false;
void Input(float arr[][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter (" << i + 1 << "," << j + 1 << ") entry ";
            cin >> arr[i][j];
        }
        cout << i + 1 << "th row done \n";
    }
}
void Display(float arr[][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(10) << arr[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
}
void Interchange(float arr[][MAX], int r1, int r2, int col)		// r1 is to be swapped with r2
{
    float temp[MAX];
    for (int i = 0; i < col; i++)
    {
        temp[i] = arr[r1][i];
        arr[r1][i] = arr[r2][i];
        arr[r2][i] = temp[i];
    }
}
void Scaling(float arr[], float scale, int col)			// col is the length of 1d array
{
    for (int i = 0; i < col; i++)
    {
        arr[i] = arr[i] * scale;
    }
}
void pivot(float arr[][MAX], int row, int col, int& pivot_row, int& C_col)
{
    do
    {
        for (int i = pivot_row; i < row; i++)
        {
            if (arr[i][C_col] != 0)
            {
                pivot_row = i;
                return;
            }
        }
        C_col++;
    } while (C_col < (col));
}
void RoundOff(float arr[][MAX], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((arr[i][j] > -0.99999 && arr[i][j] < 0) || (arr[i][j] < 0.999 && arr[i][j] > 0))
                arr[i][j] = 0;
        }
    }
}
void toEchelonForm(float arr[][MAX], int row, int col)
{
    float scaling_arr[MAX];
    int C_col = 0;
    int pivot_row = 0;
    int safe = 0;
    int C_row = 0;
    int pivot_col_done = 0;
    int g = 0;
    do
    {
        pivot(arr, row, col, pivot_row, C_col);
        if (pivot_row != C_row)
        {
            Interchange(arr, C_row, pivot_row, col);

        }
        safe = C_row;
        if (C_col == col)
            break;
        do
        {
            C_row = (pivot_row + 1);
            while (arr[C_row][C_col] == 0)
            {
                C_row++;
            }
            if (C_row >= row)
            {
                break;
            }
            pivot_row = safe;
            float scale = (-(arr[(C_row)][C_col] / arr[pivot_row][C_col]));
            // Initiallizing scaling row
            for (int i = 0; i < col; i++)
            {
                scaling_arr[i] = arr[pivot_row][i];
            }
            Scaling(scaling_arr, scale, col);
            for (int i = 0; i < col; i++)
            {
                arr[C_row][i] = arr[C_row][i] + scaling_arr[i];
            }
            C_row++;
            RoundOff(arr, row, col);
            if (dispSteps){
                Display(arr, row, col);
            }
        } while (C_row < row);
        pivot_col_done++;
        C_col++;
        C_row = pivot_col_done;
        pivot_row = pivot_col_done;
        if (dispSteps){
            Display(arr, row, col);
        }
    } while (C_col < (col));
}
void toReducedEchelonMatrix(float arr[][MAX], int row, int col)
{
    toEchelonForm(arr, row, col);
    cout << "\nNow converting to reduced echelon form ";
    cout << "\n==============================\n";
    int C_row = (row - 1), C_col = 0, piv_row = 0, desti_row = 0;
    float scale = 0.0, scaling_arr[MAX];
    do
    {
        while (arr[C_row][C_col] == 0)
        {
            C_col++;
        }
        piv_row = C_row;
        if (C_col == col)
        {
            C_row--;
            C_col = 0;
            continue;
        }
        scale = 1 / arr[C_row][C_col];
        for (int i = C_col; i <= col; i++)
        {
            if (arr[C_row][i] != 0)
                arr[C_row][i] = arr[C_row][i] * scale;

        }
        // round_off the pivot to 1;
        if (arr[C_row][C_col] > 0.999 && arr[C_row][C_col] < 1)
        {
            arr[C_row][C_col] = 1;
        }
        desti_row = piv_row - 1;
        for (int i = 0; i < col; i++)
        {
            scaling_arr[i] = arr[piv_row][i];
        }
        while (desti_row >= 0)
        {
            scale = -1 * (arr[desti_row][C_col]);
            for (int i = 0; i <= col; i++)
                arr[desti_row][i] = (arr[desti_row][i]) + (scale * scaling_arr[i]);
            desti_row--;
        }
        if (dispSteps){
            Display(arr, row, col);
        }
        C_row--;
        C_col = 0;

    } while (C_row >= 0);
}
int main()
{
    float MAT[MAX][MAX] = {};
    int row = 0, col = -1;
    while (row < 1 || col < 1)
    {
        cout << "Enter number of rows ";
        cin >> row;
        cout << "Enter number of columns ";
        cin >> col;

    }
    cout << "\n------------------\n";
    cout << "\nDo you want the program to display steps: (Y/N)\n";
    string steps;
    cin >> steps;
    for (char & step : steps){
        step = tolower(step);
    }
    if (steps[0] == 'y')    dispSteps = true;
    Input(MAT, row, col);
    cout << "Following matrix will be converted to reduced echelon matrix\n";
    Display(MAT, row, col);
    toReducedEchelonMatrix(MAT, row, col);
    Display(MAT, row, col);
    return 0;
}
