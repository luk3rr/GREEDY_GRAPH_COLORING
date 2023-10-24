/*
* Filename: vertex.h
* Created on: June  5, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef VERTEX_H_
#define VERTEX_H_

#include <cstddef>
#include <cstdint>

#include <cmath>
#include <memory>

#include "edge.h"
#include "vector.h"

namespace geom
{
    class Vertex
    {
        private:
            std::size_t m_id; // Vertex ID
            uint16_t m_color;

            Vector<std::shared_ptr<Edge>> m_adjList; // Adjacency list

        public:
            Vertex();

            /**
             * @brief Constructor overload
             * @param id Vertex ID
             */
            Vertex(std::size_t m_id);

            ~Vertex();

            // Overload operators
            bool operator==(const Vertex &other) const;
            bool operator<=(const Vertex &other) const;
            bool operator>=(const Vertex &other) const;
            bool operator<(const Vertex &other) const;
            bool operator>(const Vertex &other) const;

            /**
             * @brief Set the vertex color
             * @param color New color
             **/
            void SetColor(uint16_t color);

            /**
             * @return Color of the vertex
             **/
            uint16_t GetColor();

            /**
             * @return Value of the vertex degree
             */
            uint32_t GetDegree();

            /**
             * @return Value of the vertex ID
             */
            std::size_t GetID();

            /**
             * @return Address of the adjacency list of this vertex
             */
            Vector<std::shared_ptr<Edge>>* GetAdjacencyList();

            /**
             * @brief Compare the vertices using they color
             **/
            struct CompareVertex
            {
                bool operator()(const Vertex v1, const Vertex v2) const
                {
                    return v1.m_color < v2.m_color;
                }
            };
    };
}

#endif // VERTEX_H_
