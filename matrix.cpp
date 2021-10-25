#include <iostream>

using namespace std;
class Matrix
{
private:
    int height;
    int** matrix;
public:
    void make_matrix(int n)
    {
       height = n;
       matrix = new int*[height];
       for (int i = 0; i < height; i++)
       {
           matrix[i] = new int[height];
           for (int j = 0; j < height; j++)
           {
               matrix[i][j] = 100;
           }
       }
    }
    void is_matrix_symetric()
    {
       int matrix2[height-1][height-1];
       for (int i = 0; i < height; i++)
       {
           for (int j = 0; j < height; j++)
           {
                matrix2[height-1-j][i] = matrix[i][j];
           }
       }

       for (int i = 0; i < height; i++)
       {
           for (int j = 0; j < height; j++)
           {
                if (matrix2[i][j]!=matrix2[j][i]){
                    cout <<"matrix is not symetric";
                    delete[] matrix2;
                    return;
                }
           }
       }
       delete[] matrix2;
       cout <<"matrix is symetric";
       return;
    }
    void print()
    {
       for (int i = 0; i < height; i++)
       {
           for (int j = 0; j < height; j++)
           {
                cout << matrix[i][j] << " ";
           }
           cout << endl;
       }
    }
};
int main()
{
        int n;
        cout << "Size of the marix?" << endl;
        cin >> n;
        Matrix m;
        m.make_matrix(n);
        m.print();
        m.is_matrix_symetric();
}
