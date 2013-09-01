/*
 * File:   OBJReader.hpp
 * Author: JoPe
 *
 * Created on 30 de agosto de 2013, 22:24
 */

#ifndef OBJREADER_HPP
#define	OBJREADER_HPP

#include <string>

namespace obj
{
    class OBJReader {
    public:
        OBJReader();

        void Parse( std::string const& i_fileName );

    private:
        std::string m_fileName;

    };
}
#endif	/* OBJREADER_HPP */

