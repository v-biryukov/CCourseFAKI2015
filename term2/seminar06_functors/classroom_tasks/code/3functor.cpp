#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector;


class GetDivisible 
{
private:
    int mDivisor;
    vector<int> mNumbers;
public:

    GetDivisible(int divisor) : mDivisor(divisor) 
    {
    }

    const GetDivisible& operator()(const vector<int>& v) 
    {
        for (int i = 0; i < v.size(); ++i) 
        {
            if (v[i] % mDivisor == 0) 
                mNumbers.push_back(v[i]);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& stream, const GetDivisible& right);
};

std::ostream& operator<<(std::ostream& stream, const GetDivisible& right) 
{
    for (int i = 0; i < right.mNumbers.size(); ++i)
        cout << right.mNumbers[i] << " ";
    return stream;
}



int main() 
{
    auto gd2 = GetDivisible(2);

    cout << gd2({5, 2, 41, 65, 32, 50}) << endl;
    cout << gd2({5, 3, 2, 4, 1, 6}) << endl;

    cout << GetDivisible(5)({5, 2, 41, 65, 32, 50}) << endl;;
}