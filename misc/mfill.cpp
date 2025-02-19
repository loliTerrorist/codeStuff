#include <iostream>
#include <cstring>
using namespace std;

int** New2DArray(int rows, int cols);
void SpiralFill(int** mat, int rows, int cols);
void ZigzagFill(int** mat, int rows, int cols);
void DiagonalFill(int** mat, int rows, int cols);
void Display2DArray(int** mat, int rows, int cols);
void Delete2DArray(int** mat, int rows);

int main()
{
    char mode; //mode should be A, B, or C
    int rows, cols;
    cin >> mode;
    cin >> rows >> cols;
    
    int** mat = New2DArray(rows, cols);
    
    if (mode == 'A') 
    {
        SpiralFill(mat, rows, cols);
    }
    else if (mode == 'B')
    {
        ZigzagFill(mat, rows, cols);
    }
    else if (mode == 'C')
    {
        DiagonalFill(mat, rows, cols);
    }
    
    Display2DArray( mat, rows, cols);

    Delete2DArray(mat, rows);

    return 0;
}
int** New2DArray(int rows, int cols) 
{
    int** mat = new int*[rows];
    for (int i = 0; i < rows; i++) 
    {
        mat[i] = new int[cols];
    }
    return mat;
}

void SpiralFill(int** mat, int rows, int cols)
{
    int value = 1, top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    while (top <= bottom && left <= right) 
    {
        for (int i = left; i <= right; i++) // Top row
            mat[top][i] = value++;
        top++;

        for (int i = top; i <= bottom; i++) // Right column
            mat[i][right] = value++;
        right--;

        if (top <= bottom) 
        { // Bottom row
            for (int i = right; i >= left; i--)
                mat[bottom][i] = value++;
            bottom--;
        }

        if (left <= right) 
        { // Left column
            for (int i = bottom; i >= top; i--)
                mat[i][left] = value++;
            left++;
        }
    }
}

void ZigzagFill(int** mat, int rows, int cols)
{
    int value = 1;
    for (int i = 0; i < rows; i++) 
    {
        if (i % 2 == 0) 
        { // Left to right for even rows
            for (int j = 0; j < cols; j++)
                mat[i][j] = value++;
        } 
        else 
        { // Right to left for odd rows
            for (int j = cols - 1; j >= 0; j--)
                mat[i][j] = value++;
        }
    }
}

void DiagonalFill(int** mat, int rows, int cols)
{
    int value = 1;
    for (int d = 0; d < rows + cols - 1; d++) 
    {
        int row = (d < cols) ? 0 : (d - cols + 1);
        int col = (d < cols) ? d : (cols - 1);
        while (row < rows && col >= 0)
            mat[row++][col--] = value++;
    }
}

void Display2DArray(int** mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
void Delete2DArray(int** mat, int rows)
{
    for (int i = 0; i < rows; i++)
        delete [] mat[i];
    delete []mat;
}
