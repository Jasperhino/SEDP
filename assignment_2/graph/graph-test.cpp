
#include <iostream>
#include <numeric>

#include <Graph.h>
#include <GraphFactory.h>

void test()
{
    auto g1 = GraphFactory::createLinearGraph(5, 0);
    std::cout << *g1 << std::endl;

    auto g2 = GraphFactory::createLinearGraph(5, 4);
    std::cout << *g2 << std::endl;

    g1->merge(std::move(g2));
    std::cout << *g1 << std::endl;

    auto g3 = GraphFactory::createTree(10, 9);
    std::cout << *g3 << std::endl;

    g1->merge(std::move(g3));
    std::cout << *g1 << std::endl;

    auto g4 = GraphFactory::createRandomGraph(123);
    auto g5 = GraphFactory::createRandomGraph(42);
    g4->merge(std::move(g5));
}

int main(int argc, char *argv[])
{
    test();
    printMemoryUsage();
    test();
    printMemoryUsage();
}
