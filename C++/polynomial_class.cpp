#include <bits/stdc++.h>
using namespace std;

class poly
{
private:
public:
    int *data;
    int degree;
    poly(int s)
    {
        degree = s;
        data = new int[s + 1];
        for (int i = 0; i <= degree; i++)
        {
            data[i] = 0;
        }
    }

    void print()
    {
        for (int i = 0; i < degree; i++)
        {
            cout << data[i] << "x^" << i << " + ";
        }

        cout << data[degree] << "x^" << degree << endl;
    }

    void set(int i, int c)
    {
        data[i] = c;
    }

    poly(poly const &a)
    {
        this->data = new int[a.degree];
        for (int i = 0; i <= a.degree; i++)
        {
            data[i] = a.data[i];
        }

        this->degree = a.degree;
    }
    poly operator=(poly const &a)
    {
        this->data = new int[a.degree];
        for (int i = 0; i <= a.degree; i++)
        {
            data[i] = a.data[i];
        }

        this->degree = a.degree;
    }

    poly operator+(poly const &b)
    {

        poly c(b.degree);

        for (int i = 0; i <= c.degree; i++)
        {
            c.data[i] = data[i] + b.data[i];
        }

        c.degree = b.degree;
        return c;
    }

    poly operator*(poly const &b)
    {

        poly c(b.degree + this->degree);

        for (int i = 0; i <= c.degree; i++)
        {
            for (int j = 0; j <= this->degree; j++)
            {
                c.data[i + j] += (data[i] * b.data[j]);
            }
        }

        c.degree = b.degree + this->degree;
        return c;
    }
};

int main()
{
    poly a(1);
    a.set(0, 2);
    a.set(1, 2);

    poly b = a;

    b.set(0, 1);
    b.set(1, 3);

    a.print();
    b.print();

    poly c = a * b;
    c.print();

    return 0;
}
