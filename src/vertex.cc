/*
* Filename: vertex.cc
* Created on: June  5, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "vertex.h"
#include <cstdint>

namespace geom
{
    Vertex::Vertex()
    {
        this->m_id = 0;
    }

    Vertex::Vertex(std::size_t id)
    {
        this->m_id = id;
    }

    Vertex::~Vertex() { }

    bool Vertex::operator==(const Vertex &vertex) const
    {
        return (this->m_id == vertex.m_id);
    }

    bool Vertex::operator<=(const Vertex &vertex) const
    {
        //return (this->m_cost <= vertex.m_cost);
        return false;
    }

    bool Vertex::operator>=(const Vertex &vertex) const
    {
        //return (this->m_cost >= vertex.m_cost);
        return false;
    }

    bool Vertex::operator<(const Vertex &other) const
    {
        //return (this->m_cost < other.m_cost);
        return false;
    }

    bool Vertex::operator>(const Vertex &other) const
    {
        //return (this->m_cost > other.m_cost);
        return false;
    }

    void Vertex::SetColor(uint16_t color)
    {
        this->m_color = color;
    }

    uint16_t Vertex::GetColor()
    {
        return m_color;
    }

    uint32_t Vertex::GetDegree()
    {
        return this->m_adjList.Size();
    }

    std::size_t Vertex::GetID()
    {
        return this->m_id;
    }

    Vector<std::shared_ptr<Edge>>* Vertex::GetAdjacencyList()
    {
        return &m_adjList;
    }
}
