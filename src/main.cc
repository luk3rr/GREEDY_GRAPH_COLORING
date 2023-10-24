/*
* Filename: main.cc
* Created on: September 13, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include "graph.h"

int main(int argc, char *argv[])
{
    std::size_t numVertices;
    char sortAlgorithm;

    scanf("%c %zu", &sortAlgorithm, &numVertices);

    geom::Graph graph(numVertices);

    // Create vertices
    for (std::size_t i = 0; i < numVertices; i++)
    {
        // Vertex is created with ID i
        graph.AddVertex(geom::Vertex(i));
    }

    // Add neighbors for each vertex
    std::size_t numNeighbor, neighborID;
    for (std::size_t i = 0; i < numVertices; i++)
    {
        scanf("%zu", &numNeighbor);

        for (std::size_t j = 0; j < numNeighbor; j++)
        {
            scanf("%zu", &neighborID);
            graph.AddEdge(i, neighborID); // Vertex i has neighbor "neighborID"
        }
    }

    // Set the color for each vertex
    uint16_t vertexColor;
    for (std::size_t i = 0; i < numVertices; i++)
    {
        scanf("%hu", &vertexColor);
        graph.AddVertexColor(i, vertexColor);
    }

    graph.SetSortAlgorithm('b');
    graph.SortVertices();

    graph.SetSortAlgorithm('s');
    graph.SortVertices();

    graph.SetSortAlgorithm('i');
    graph.SortVertices();

    graph.SetSortAlgorithm('q');
    graph.SortVertices();

    graph.SetSortAlgorithm('m');
    graph.SortVertices();

    graph.SetSortAlgorithm('p');
    graph.SortVertices();


    graph.SetSortAlgorithm('y');
    graph.SortVertices();

    return EXIT_SUCCESS;
}
