/*
 * File:   Object.hpp
 * Author: juan.garibotti
 *
 * Created on 24 de febrero de 2014, 17:52
 */

#ifndef OBJECT_HPP
#define	OBJECT_HPP

#include <vector>
#include <string>
#include "Face.hpp"
#include "Vertex.hpp"

namespace obj
{
    struct Object
    {
        std::vector< VertexCoordinates > m_coordinatesList;
        std::vector< TextureCoordinates > m_textureList;
        std::vector< Normal > m_normalList;
        std::vector< Face > m_faceList;

        Object() = default;
        Object( std::string const& i_filename );
    };
}

#endif	/* OBJECT_HPP */

