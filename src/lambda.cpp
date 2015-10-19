#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

/*
 * $ echo "1 2 3" | ./a.out
 * $ 3 6 9 
 */
int main() {
    std::for_each(std::istream_iterator<int>(std::cin), \
            std::istream_iterator<int>(), \
            std::cout << (boost::lambda::_1 * 3) << " ");
}


