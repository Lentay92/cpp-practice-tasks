#include <vector>
#include <iostream>

// Add an edge to an undirected graph's incidence matrix given as array of arrays
template <typename IncedenceMatrix, typename VertexId1, typename VertexId2>
void add_edge(IncedenceMatrix& B, VertexId1&& u, VertexId2&& v)
{
    for (std::size_t i = 0; i < B.size(); ++i)
    {
        if (i == std::forward<VertexId1>(u) || i == std::forward<VertexId1>(v))
            B[i].emplace_back(1);
        else
            B[i].emplace_back(0);
    }

}

void add_edge_test()
{
    std::vector<std::vector<std::size_t>> incidenceMatrix = { {1, 0, 0}, {1, 1, 1}, {0, 1, 0}, {0, 0, 1} };
    std::size_t vertexId1 = 0;
    std::size_t vertexId2 = 2;

    add_edge(incidenceMatrix, vertexId1, vertexId2);
    for (std::size_t i = 0; i < incidenceMatrix.size(); i++)
    {
        std::cout << '\n';
        for (std::size_t j = 0; j < incidenceMatrix[i].size(); j++)
            std::cout << ' ' << incidenceMatrix[i][j];
    }
}

// Enumeration of the edges of the adjacency matrix of an undirected graph given as array of arrays
template <typename AdjacencyMatrix, typename Visitor>
void enumarate_edges(AdjacencyMatrix const& A, Visitor&& visitor)
{
    for (std::size_t u = 1; u < A.size(); ++u)
        for (std::size_t v = 0; v <= u - 1; ++v)
            if (A[u][v] == 1)
                visitor(u, v);
}


// Converting adjacency matrix to incidence matrix
template <typename AdjacencyMatrix, typename IncidenceMatrix>
void transform_graph(AdjacencyMatrix const& A, IncidenceMatrix& B)
{
    enumarate_edges(A, [&B](size_t u, size_t v)
        {
            add_edge(B, u, v);
        });

}

void transform_graph_test()
{
    std::vector<std::vector<std::size_t>> adjacencyMatrix =
    {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}
    };

    std::vector<std::vector<std::size_t>> incidenceMatrix(4);

    transform_graph(adjacencyMatrix, incidenceMatrix);

    for (std::size_t i = 0; i < incidenceMatrix.size(); i++)
    {
        std::cout << '\n';
        for (std::size_t j = 0; j < incidenceMatrix[i].size(); j++)
            std::cout << ' ' << incidenceMatrix[i][j];
    }

}

int main()
{
    transform_graph_test();
}
