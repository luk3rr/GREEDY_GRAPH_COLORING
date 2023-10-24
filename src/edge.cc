/*
* Filename: edge.cc
* Created on: September 17, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "edge.h"

namespace geom {
    Edge::Edge(uint32_t sideA, uint32_t sideB)
    {
        this->m_vertices = std::make_pair(sideA, sideB);
    }

    Edge::Edge(const Edge &other)
    {
        this->m_vertices = other.m_vertices;
    }

    Edge::~Edge() { }

    Edge &Edge::operator=(const Edge &other)
    {
        if (this != &other)
        {
            this->m_vertices = other.m_vertices;
        }

        return *this;
    }

    bool Edge::operator<(const Edge &other)
    {
        // TODO: Implement this
        std::cerr << "Oh no! This function is not implemented. Please do not call it" << std::endl;
        return false;
    }
    std::pair<std::size_t, std::size_t> Edge::GetVertices()
    {
        return this->m_vertices;
    }
}
