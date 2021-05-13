
#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <chrono>


int main(int /*argc*/, char * /*argv*/[]) {
    // Input

    auto line = std::string("");
    std::vector<std::string> lines;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            continue;
        }

        const auto size = line.size();
        lines.push_back(std::move(line));
        line.reserve(size);
    }

    // const auto start = std::chrono::high_resolution_clock::now();

    // Todo: Implement algorithm to sort palindromes to the front of the list

    std::partition(lines.begin(), lines.end(), [](auto const &l) {
       return std::equal(l.begin(), l.begin() + l.size() / 2, l.rbegin());
    });

    // const auto end = std::chrono::high_resolution_clock::now();
    // const auto duration = end - start;
    // std::cout << std::dec << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << std::endl;

    std::cout << "Sorted by palindromity" << std::endl << std::endl;

    for (const auto &s : lines) {
        std::cout << s << std::endl;
    }

    return 0;
}
