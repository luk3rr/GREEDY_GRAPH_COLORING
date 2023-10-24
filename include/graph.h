/*
* Filename: graph.h
* Created on: September 13, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include <cstdio>
#include <cstddef>
#include <cstdint>

#include <cmath>
#include <memory>

#include "edge.h"
#include "vertex.h"

#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "shell_sort.h"

namespace geom
{
    class Graph
    {
        private:
            Vector<Vertex> m_vertices; // Each vector position is the vertex ID
            std::size_t m_numEdges; // number of edges in this graph
            char m_sortAlgorithm; // The algorithm used for sort the vertex in the vector

        public:
            /**
             * @param numVertices Number of vertices in the graph
             * @param numEdges Number of edges in the graph
             **/
            Graph(std::size_t numVertices, std::size_t numEdges);

            /**
             * @param numVertices Number of vertices in the graph
             */
            Graph(std::size_t numVertices);

            ~Graph();

            /**
             * @brief Set the algorithm whetever used for sort the vertices
             * @brief sortAlgorithm char indicating the algorithm
             *        b = bubble sort
             *        s = selection sort
             *        i = insertion sort
             *        q = quicksort
             *        m = mergesort
             *        p = heapsort
             *        y = custom algorithm
             **/
            void SetSortAlgorithm(char sortAlgorithm);

            /**
             * @brief Adds a vertex to the graph
             * @param vertex New vertex to be added to the graph
             **/
            void AddVertex(Vertex vertex);

            /**
             * @brief Adds a edge
             * @param vertexID ID of the vertex that will receive a neighbor
             * @param neighborID ID of the neighbor
             **/
            void AddEdge(std::size_t vertexID, std::size_t neighborID);

            /**
             * @brief Add a color for a specified vertex
             * @param vertexID ID of the vertex that will receive a color
             * @param color The new color
             **/
            void AddVertexColor(std::size_t vertexID, uint16_t color);

            /**
             * @brief Sort the vector of the vertices
             **/
            void SortVertices();
    };
}

#endif // GRAPH_H_
