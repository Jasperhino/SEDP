
#pragma once

#include <cstdint>
#include <memory>

class Graph;

/*
 * @class GraphFactory
 */
class GraphFactory
{
public:
    static std::unique_ptr<Graph> createLinearGraph(std::int32_t numVertices, std::int32_t idOffset = 0);
    static std::unique_ptr<Graph> createCircularGraph(std::int32_t numVertices, std::int32_t idOffset = 0);
    static std::unique_ptr<Graph> createTree(std::int32_t numChildren, std::int32_t idOffset = 0);
    static std::unique_ptr<Graph> createRandomGraph(std::int32_t numVertices, std::int32_t idOffset = 0);
};