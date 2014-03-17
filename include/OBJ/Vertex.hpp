/* 
 * File:   newClass.hpp
 * Author: juan.garibotti
 *
 * Created on 24 de febrero de 2014, 18:13
 */

#ifndef VERTEX_HPP
#define	VERTEX_HPP

namespace obj
{
    struct VertexCoordinates
    {
        float m_data[4];
    };
    
    struct TextureCoordinates
    {
        float m_data[3];      
    };
    
    struct Normal
    {
        float m_data[3];
    };
    
}

#endif	/* VERTEX_HPP */

