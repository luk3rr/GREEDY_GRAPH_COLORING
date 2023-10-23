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
            uint32_t m_constructionYear; // Year in which the edge construction was completed
            uint32_t m_crossingTime; // Traversal time (cost) of the edge
            uint32_t m_buildCost; // Construction cost of the edge
            bool m_inTree; //Indicates whether the edge is part of the cut or not (is in the MST or not)

        public:
            Edge(uint32_t sideA, uint32_t sideB);
            Edge(uint32_t sideA, uint32_t sideB, uint32_t constructionYear,
                 uint32_t crossingTime, uint32_t buildCost);

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
             * @brief Set a new year in which the edge construction was completed
             **/
            void SetConstructionYear(uint32_t newYear);

            /**
             * @brief Set a new traversal time (cost) of the edge
             **/
            void SetCrossingTime(uint32_t newCrossingTime);

            /**
             * @brief Set a new Construction cost of the edge
             **/
            void SetBuildCost(uint32_t newBuildCost);

            /**
             * @brief Set whether the edge is in the Minimum Spanning Tree (MST) or not
             **/
            void SetInMST(bool isInTree);

            /**
             * @return Year in which the edge construction was completed
             **/
            uint32_t GetConstructionYear();

            /**
             * @return Traversal time (cost) of the edge
             **/
            uint32_t GetCrossingTime();

            /**
             * @return Construction cost of the edge
             **/
            uint32_t GetBuildCost();

            /**
             * @param info Type of the info
             * @return A specified cost, according the info parameter
             **/
            uint32_t GetSpecifiedCost(Defs::EDGE_INFO info) const;

            /**
             * @return std::pair<a, b>, where a, b are the vertices ID
             **/
            std::pair<std::size_t, std::size_t> GetVertices();

            /**
             * @return A boolean indicating whether the edge is in the MST.
             **/
            bool IsInMST();

            struct CompareEdges
            {
                Defs::EDGE_INFO m_edgeInfo;

                CompareEdges(Defs::EDGE_INFO info = Defs::EDGE_INFO::COST) : m_edgeInfo(info) { }

                bool operator()(const std::shared_ptr<Edge> e1, const std::shared_ptr<Edge> e2) const
                {
                    return e1->GetSpecifiedCost(m_edgeInfo) < e2->GetSpecifiedCost(m_edgeInfo);
                }
            };
    };


}

#endif // EDGE_H_
