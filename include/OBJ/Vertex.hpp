/*
 * File:   newClass.hpp
 * Author: juan.garibotti
 *
 * Created on 24 de febrero de 2014, 18:13
 */

#ifndef OBJ_VERTEX_HPP
#define	OBJ_VERTEX_HPP

#include <array>

namespace obj
{
    struct VertexCoordinates
    {
        std::array<float,4> m_data;
    };

    struct TextureCoordinates
    {
        std::array<float,3> m_data;
    };

    struct Normal
    {
        std::array<float,3> m_data;
    };

}

#endif	/* OBJ_VERTEX_HPP */

