#include <iostream>

using namespace std;

class LowerTriangular
{
private:
    int *A;
    int n;

public:
    LowerTriangular()
    {
        n=2;
        A = new int[2*(2+1)/2];

    }
    LowerTriangular()
    {
        this -> n=n;
        A = new int[n*(n+1)/2];

    }
    ~LowerTriangular()
    {
        delete []A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void LowerTriangular::Set(int i, int j, int x)
{
    if (i >= j){
        A[i*(i-1)/2+(j-1)]=x;
    }
}

int LowerTriangular::Get(int i, int j)
{
    if (i >= j)
        return A[i*(i-1)/2+j-1];
    return 0;
}

void LowerTriangular::Display()
{
    for(int i=0; i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i>=j)
                cout<<A[i*(i-1)/2+j-1]<<" ";
            else
                cout<<"0 ";
        }
    }
}

int main()
{
    
}