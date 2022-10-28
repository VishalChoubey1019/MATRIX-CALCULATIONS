#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3, m = 3;
    double a[n][m];
    double c[n][m];
    double d[n][m];
    bool b = 0;

    cout << "Enter the numbers of your matrix \n";

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0 && !b)
                b = 1;
        }

    string trans = "tan";
    cout << "\nIf you want the transpose of the given matrix then type 'yes' \n";
    cin >> trans;
    if (trans == "yes" || trans == "Yes")
    {
        // Computing transpose of the matrix
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                c[j][i] = a[i][j];
                d[j][i] = a[i][j];
            }

        // Printing the transpose
        cout << "\nTranspose of Matrix: " << endl;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << " " << c[i][j];
            }
            cout << endl;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            {
                c[i][j] = (a[(i + 1)][(j + 1)] * a[(i + 2)][(j + 2)]) - (a[(i + 2)][(j + 1)] * a[(i + 1)][(j + 2)]);
            }
            else if (i == 1 && j == 2)
            {
                c[i][j] = (a[(i + 1)][(j + 1)] * a[(i + 2)][(j + 2) % 3]) - (a[(i + 2)][(j + 1)] * a[(i + 1)][(j + 2) % 3]);
            }
            else if (i == 1 && j == 3)
            {
                c[i][j] = (a[(i + 1)][(j + 1) % 3] * a[(i + 2)][(j + 2) % 3]) - (a[(i + 2)][(j + 1) % 3] * a[(i + 1)][(j + 2) % 3]);
            }
            else if (i == 2 && j == 1)
            {
                c[i][j] = (a[(i + 1)][(j + 1)] * a[(i + 2) % 3][(j + 2)]) - (a[(i + 2) % 3][(j + 1)] * a[(i + 1)][(j + 2)]);
            }
            else if (i == 2 && j == 2)
            {
                c[i][j] = (a[(i + 1)][(j + 1)] * a[(i + 2) % 3][(j + 2) % 3]) - (a[(i + 2) % 3][(j + 1)] * a[(i + 1)][(j + 2) % 3]);
            }
            else if (i == 2 && j == 3)
            {
                c[i][j] = (a[(i + 1)][(j + 1) % 3] * a[(i + 2) % 3][(j + 2) % 3]) - (a[(i + 2) % 3][(j + 1) % 3] * a[(i + 1)][(j + 2) % 3]);
            }
            else if (i == 3 && j == 1)
            {
                c[i][j] = (a[(i + 1) % 3][(j + 1)] * a[(i + 2) % 3][(j + 2)]) - (a[(i + 2) % 3][(j + 1)] * a[(i + 1) % 3][(j + 2)]);
            }
            else if (i == 3 && j == 2)
            {
                c[i][j] = (a[(i + 1) % 3][(j + 1)] * a[(i + 2) % 3][(j + 2) % 3]) - (a[(i + 2) % 3][(j + 1)] * a[(i + 1) % 3][(j + 2) % 3]);
            }
            else if (i == 3 && j == 3)
            {
                c[i][j] = (a[(i + 1) % 3][(j + 1) % 3] * a[(i + 2) % 3][(j + 2) % 3]) - (a[(i + 2) % 3][(j + 1) % 3] * a[(i + 1) % 3][(j + 2) % 3]);
            }
        }
    }

    cout << "\n\n";

    double det = a[1][1] * c[1][1] + a[1][2] * c[1][2] + a[1][3] * c[1][3];

    string dete = "det";
    string adj = "adj";
    string inv = "inv";
    string ran = "rank";
    string ortho = "ort";
    string sub = "subt";

    cout << "If you want the determinant of the given matrix then type 'yes' \n";
    cin >> dete;
    if (dete == "yes" || dete == "Yes")
        if (det == 0)
            cout << "DETERMINANT= " << det << ", Inverse Does Not Exist. \n\n";

        else
        {
            if (dete == "yes" || dete == "Yes")
                cout << "DETERMINANT:  " << det << " \n\n";

            cout << "\nIf you want the adjoint of the given matrix then type 'yes' \n";
            cin >> adj;
            if (adj == "yes" || adj == "Yes")
            {
                cout << "ADJOINT: \n\n";
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= m; j++)
                        cout << (c[j][i]) << "   ";
                    cout << "\n\n";
                }
            }

            cout << "\nIf you want the inverse of the given matrix then type 'yes' \n";
            cin >> inv;
            if (inv == "yes" || inv == "Yes")
            {
                cout << "\n\nINVERSE OF THE MATRIX: \n\n";
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= m; j++)
                        cout << setprecision(3) << double(c[j][i] / det) << "   ";

                    cout << "\n\n";
                }
            }
            cout << "\nIf you want to know if the matrix is orthogonal then type 'yes' \n";
            cin >> ortho;
            if (ortho == "yes" || ortho == "Yes")
            {
                int flag = 1;
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= m; j++)
                    {
                        if (d[i][j] != (c[i][j] / det))
                            flag = 0;
                    }
                }
                if (flag)
                    cout << "\n Matrix is Orthogonal";
                else
                    cout << "\nMatrix is not orthogonal";
            }
        }

    cout << "\nIf you want the rank of the given matrix then type 'yes' \n";
    cin >> ran;
    if (ran == "yes" || ran == "Yes")
    {
        if (det != 0)
            cout << "Rank = 3\n";

        else if (c[3][3] != 0 || a[3][1] != 0 || a[1][1] != 0 || a[1][3] != 0)
            cout << "Rank = 2\n";

        else if (b)
            cout << "Rank = 1\n";

        else
            cout << "Rank = 0\n";
    }

    cout << "\nIf you want the subtraction of those matrixes then type 'yes' \n";
    cin >> sub;
    if (sub == "yes" || sub == "Yes")
    {
        int m1[3][3], m2[3][3], i, j, m3[3][3];
        cout << "\n Enter First Matrix Elements : \n";
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                cout << " ";
                cin >> m1[i][j];
            }
        }
        cout << "\n Enter Second Matrix Elements : \n";
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                cout << " ";
                cin >> m2[i][j];
            }
        }
        cout << "\n Difference of Two Matrices : \n\n";
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                m3[i][j] = m1[i][j] - m2[i][j];
            }
        }
        for (i = 0; i < 3; i++)
        {
            cout << " ";
            for (j = 0; j < 3; j++)
            {
                cout << m3[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    cout << "\nIf you want the addition of those matrixes then type 'yes' \n";
    cin >> sub;
    if (sub == "yes" || sub == "Yes")
    {
        int m1[3][3], m2[3][3], i, j, m3[3][3];
        cout << "\n Enter First Matrix Elements : \n";
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                cout << " ";
                cin >> m1[i][j];
            }
        }
        cout << "\n Enter Second Matrix Elements : \n";
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                cout << " ";
                cin >> m2[i][j];
            }
        }
        cout << "\n Addition of Two Matrices : \n\n";
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                m3[i][j] = m1[i][j] + m2[i][j];
            }
        }
        for (i = 0; i < 3; i++)
        {
            cout << " ";
            for (j = 0; j < 3; j++)
            {
                cout << m3[i][j] << "\t";
            }
            cout << "\n";
        }
    }
    return 0;
}

/*

11    12    13

21    22    23

31    32    33

*/
