/*
 * File:   Face.hpp
 * Author: juan.garibotti
 *
 * Created on 24 de febrero de 2014, 18:20
 */

#ifndef FACE_HPP
#define	FACE_HPP

#include <array>

namespace obj
{

    struct Face
    {
        std::array<int,3> m_coordinates;
        std::array<int,3> m_texture;
        std::array<int,3> m_normal;
    };

}

#endif	/* FACE_HPP */

