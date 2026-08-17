#include <iostream>

using namespace std;


//"&" (and) operator returns 1 only if both operands are 1 else its 0.

// '|' (or) operator return 1 if either of the operands or both of them are 1 else its 0.

// '^' (XOR) operator return 1 if only one of the operand is 1 else its 0.

// '~' (complement) operator changes 0 to 1 and 1 to 0

// '>>' (right shift) operator 

// '<<' (left shift)

int main()
{
    // '&' operator
    int a= 12, b =25;
    cout << (a&b) << "\n";

    // '|' operator

    int x = 3, c = 40;
    cout << (x | c) << "\n";

    // '^' operator

    int y = 20, z = 23;
    cout << (y ^ z) << "\n";

    return 0;
}