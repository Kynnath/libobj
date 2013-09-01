/*
 * File:   OBJReader.cpp
 * Author: JoPe
 *
 * Created on 30 de agosto de 2013, 22:24
 */

#include "OBJReader.hpp"

#include <fstream>

namespace obj
{
    OBJReader::OBJReader()
    : m_fileName ()
    {}

    void OBJReader::Parse( std::string const& i_fileName )
    {
        m_fileName = i_fileName;

        std::fstream objFile ( m_fileName );


    }
}