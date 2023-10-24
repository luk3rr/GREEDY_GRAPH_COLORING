/*
* Filename: graph.cc
* Created on: September 13, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "graph.h"
#include "bubble_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "selection_sort.h"
#include "vertex.h"
#include <cstddef>
#include <cstdint>
#include <iostream>

namespace geom
{
    Graph::Graph(std::size_t numVertices, std::size_t numEdges)
    {
        // Resizes the adjacency list and matrix according to the number of vertices in the
        // graph
        this->m_vertices.Resize(numVertices);
        this->m_numEdges = numEdges;
    }

    Graph::Graph(std::size_t numVertices)
    {
        // Resizes the adjacency list and matrix according to the number of vertices in the
        // graph
        this->m_vertices.Resize(numVertices);
    }

    Graph::~Graph() { }

    void Graph::SetSortAlgorithm(char sortAlgorithm)
    {
        this->m_sortAlgorithm = sortAlgorithm;
    }

    void Graph::AddVertex(Vertex newVertex)
    {
        this->m_vertices[newVertex.GetID()] = newVertex;
    }

    void Graph::AddEdge(std::size_t vertexID, std::size_t neighborID)
    {
        // Create a ptr for the edge
        std::shared_ptr<Edge> edge = std::make_shared<Edge>(vertexID, neighborID);

        // Add the edge to the neighbor list of vertexID
        this->m_vertices[vertexID].GetAdjacencyList()->PushBack(edge);

        // Add the same edge to the neighbor list of neighborID
        this->m_vertices[neighborID].GetAdjacencyList()->PushBack(edge);
    }

    void Graph::AddVertexColor(std::size_t vertexID, uint16_t color)
    {
        this->m_vertices[vertexID].SetColor(color);
    }

    void Graph::SortVertices()
    {
        switch (this->m_sortAlgorithm)
        {
            case 'b':
                sort::Bubble(this->m_vertices, Vertex::CompareVertex());
                break;
            case 's':
                sort::Selection(this->m_vertices, Vertex::CompareVertex());
                break;
            case 'i':
                sort::Insertion(this->m_vertices, Vertex::CompareVertex());
                break;
            case 'q':
                sort::Quick(this->m_vertices, Vertex::CompareVertex());
                break;
            case 'm':
                sort::Merge(this->m_vertices, Vertex::CompareVertex());
                break;
            case 'p':
                sort::Heap(this->m_vertices, Vertex::CompareVertex());
                break;
            case 'y':
                sort::Shell(this->m_vertices, Vertex::CompareVertex());
                break;
            default:
                std::cerr << "Unknown sort algorithm :(" << std::endl;
                break;
        }

        if (Defs::DEBUG)
        {
            std::cout << "\n<------------------------->\n" << std::endl;
            std::cout << "BEGIN DEBUG SORT VERTICES METHOD" << std::endl;
            std::cout << "\t SORT METHOD: " << this->m_sortAlgorithm << std::endl;

            for (std::size_t i = 0; i < this->m_vertices.Size(); i++)
            {
                std::cout << "ID: " << this->m_vertices[i].GetID() << " COLOR: " << this->m_vertices[i].GetColor() << std::endl;
            }

            std::cout << "END DEBUG SORT VERTICES METHOD" << std::endl;
            std::cout << "\n<------------------------->\n" << std::endl;
        }
    }
}
