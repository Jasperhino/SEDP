#include <fstream>
#include <iterator>
#include <algorithm>
#include <iostream>

// Implement your code here
struct TokenIterator
{
    // Note: the second constructor parameter passed in main represents the characters that constitute separators
};


//
// Do not change the code below (except as noted)
//


// Note: if you compiler does not support std::forward_iterator yet, just replace "std::forward_iterator" with "typename"
template<std::forward_iterator T>
void test(T first, T last)
{
    const auto minmax = std::minmax_element(first, last, [](const auto& a, const auto& b) {return size(a) < size(b); });
    std::cout << "shortest: " << *minmax.first << "\n";
    std::cout << "longest: " << *minmax.second << std::endl;
}


auto readFile(const auto& filename)
{
    auto file = std::ifstream{};
    file.exceptions(std::ios::failbit | std::ios::badbit);
    file.open("text.txt", std::ios::binary | std::ios::ate);

    auto content = std::string(file.tellg(), '\0');
    file.seekg(0);
    file.read(content.data(), content.size());

    return content;
}


int main(int argc, char* argv[])
{
    const auto content = readFile("text.txt");
    test(TokenIterator(content, " \n"), TokenIterator());
}