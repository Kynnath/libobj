/* 
 * File:   Face.hpp
 * Author: juan.garibotti
 *
 * Created on 24 de febrero de 2014, 18:20
 */

#ifndef FACE_HPP
#define	FACE_HPP

namespace obj
{
    
    struct Face 
    {
        int m_coordinates[3];
        int m_texture[3];
        int m_normal[3];
    };

}

#endif	/* FACE_HPP */

