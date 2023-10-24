/*
* Filename: edge.h
* Created on: September 17, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef EDGE_H_
#define EDGE_H_

#include <cstddef>
#include <cstdint>
#include <cmath>

#include <memory>
#include <iostream>

#include "definitions.h"

namespace geom
{
    class Edge
    {
        private:
            std::pair<std::size_t, std::size_t> m_vertices; // Store vertices ID

        public:
            Edge(uint32_t sideA, uint32_t sideB);

            ~Edge();

            /**
             * @brief Copy constructor
             */
            Edge(const Edge &other);

            /**
             * @brief Copy assignment operator
             **/
            Edge &operator=(const Edge &other);

            /**
             * @brief Overload operator <
             **/
            bool operator<(const Edge &other);

            /**
             * @return std::pair<a, b>, where a, b are the vertices ID
             **/
            std::pair<std::size_t, std::size_t> GetVertices();
    };
}

#endif // EDGE_H_
