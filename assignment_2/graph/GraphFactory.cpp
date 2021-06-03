
#include <GraphFactory.h>

#include <random>
#include <set>
#include <array>

#include <Graph.h>
#include <map>
#include <list>
#include <memory>

std::unique_ptr<Graph> GraphFactory::createLinearGraph(std::int32_t numVertices, std::int32_t idOffset)
{
    auto graph = std::make_unique<Graph>();
    for (auto i = std::int32_t{0}; i < numVertices; ++i)
    {
        graph->addVertex(std::make_unique<Vertex>(i + idOffset));
    }
    for (auto i = std::int32_t{1}; i < numVertices; ++i)
    {
        graph->addEdge(std::make_unique<Edge>(graph->vertices()[i - 1], graph->vertices()[i], 1));
    }
    return graph;
}

std::unique_ptr<Graph> GraphFactory::createCircularGraph(std::int32_t numVertices, std::int32_t idOffset)
{
    auto graph = createLinearGraph(numVertices, idOffset);
    graph->addEdge(std::make_unique<Edge>(graph->vertices().back(), graph->vertices().front(), 1));
    return graph;
}

std::unique_ptr<Graph> GraphFactory::createTree(std::int32_t numChildren, std::int32_t idOffset)
{
    auto graph = std::make_unique<Graph>();
    graph->addVertex(std::make_unique<Vertex>(idOffset));
    for (auto i = std::int32_t{0}; i < numChildren; ++i)
    {
        graph->addVertex(std::make_unique<Vertex>(idOffset + i + 1));
        graph->addEdge(std::make_unique<Edge>(graph->vertices().front(), graph->vertices().back(), 1));
    }
    return graph;
}

std::unique_ptr<Graph> GraphFactory::createRandomGraph(std::int32_t numVertices, std::int32_t idOffset)
{
    // Edge id for the purpose of creating a map/set
    using EdgeId = std::pair<std::int32_t, std::int32_t>;
    auto makeId = [](std::shared_ptr<Edge> edge)
    { return std::make_pair(edge->v0()->id(), edge->v1()->id()); };

    auto graph = std::make_unique<Graph>();
    auto prng = std::mt19937{42}; // fixed seed

    // generate vertices
    auto vertexIds = std::set<std::int32_t>{};
    for (auto i = std::int32_t{0}; i < numVertices; ++i)
    {
        auto id = std::int32_t{0};
        do
        {
            id = prng() % std::numeric_limits<std::int32_t>::max();
        } while (vertexIds.find(id) != vertexIds.end());

        vertexIds.insert(id);
        graph->addVertex(std::make_unique<Vertex>(id));
    }

    // generate edges
    auto vertexIdList = std::vector<std::int32_t>{vertexIds.begin(), vertexIds.end()};
    auto edgeSet = std::set<EdgeId>{};
    for (const auto &v0 : graph->vertices())
    {
        for (auto i = std::size_t{0}; i < 3; ++i)
        {
            const auto &v1 = graph->vertices()[prng() % vertexIdList.size()];
            if (v0 != v1)
            {
                auto edge = std::make_shared<Edge>(v0, v1, 1);
                if (edgeSet.find(makeId(edge)) == edgeSet.end())
                {
                    edgeSet.insert(makeId(edge));
                    graph->addEdge(edge);
                }
            }
        }
    }

    return graph;
}
