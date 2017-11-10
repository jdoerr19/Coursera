//
//  greatestCommonDiv.cpp
//  Week2
//
//  Created by Joshua Doerr on 11/7/17.
//  Copyright © 2017 Josh. All rights reserved.
//

#include <iostream>

int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}

int gcd_fast(int a, int b)
{
    static int gcd = 0;
    int largerNum;
    int smallerNum;
    
    if (a > b)
    {
        largerNum = a;
        smallerNum = b;
    }
    else
    {
        largerNum = b;
        smallerNum = a;
    }

    int remainder = largerNum % smallerNum;
    
    if (remainder == 0)
    {
        gcd = smallerNum;
    }
    else
    {
        gcd_fast(smallerNum, remainder);
    }

    return gcd;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    //std::cout << gcd_naive(a, b) << std::endl;
    std::cout << gcd_fast(a, b) << std::endl;
    
    return 0;
}

