/*
 * File:   Object.cpp
 * Author: juan.garibotti
 *
 * Created on 24 de febrero de 2014, 17:52
 */

#include "Object.hpp"

#include <fstream>
#include <sstream>

namespace obj
{
    char const k_linePrefix[][3] =
    {
        "#",    // Comment
        "v",    // Coordinates
        "vt",   // Texture coordinates
        "vn",   // Normal
        "vp",   // Ignored
        "f"     // Face
    };

    enum LinePrefix
    {
        Comment = 0,
        Coords,
        TexCoords,
        NormalDirection,
        RESERVEDvn,
        FaceDefinition
    };

    typedef std::vector< std::string > TokenList;

    Object::Object( std::string const& i_filename )
    {
        // Break file into tokens, separated by line
        std::vector< TokenList > lineTokens;
        {
            std::ifstream objFile ( i_filename );
            std::string line;

            while ( std::getline( objFile, line ) )
            {
                lineTokens.push_back( TokenList() );
                std::stringstream lineStream ( line );
                std::string token;
                while ( lineStream >> token )
                {
                    lineTokens.back().push_back( token );
                }
            }
        }

        // We now don't need to worry about whitespace or line ends
        // To process each line:
        // - Identify what kind of line it is
        // - Push it into the appropriate list in the model

        for ( auto const& line : lineTokens )
        {
            if ( line.front() == k_linePrefix[ Comment ] )
            {
                continue;
            }
            else if ( line.front() == k_linePrefix[ Coords ] )
            {
                // Make sure we have the right number of components
                if ( line.size() == 4 || line.size() == 5 )
                {
                    float coords[4] = { 0.0f, 0.0f, 0.0f, 1.0f }; // wCoord defaults to 1.0f
                    for ( auto coord ( line.begin()+1 ), end ( line.end() ); coord != end; ++coord )
                    {
                        coords[ coord-line.begin()-1 ] = std::stof( *coord );
                    }
                    m_coordinatesList.push_back( VertexCoordinates( { coords[0], coords[1], coords[2], coords[3] } ) );
                }
            }
            else if ( line.front() == k_linePrefix[ TexCoords ] )
            {
                // Make sure we have the right number of components
                if ( line.size() == 3 || line.size() == 4 )
                {
                    float texCoords[3] = { 0.0f }; // wTexCoord defaults to 0.0f
                    for ( auto texCoord ( line.begin()+1 ), end ( line.end() ); texCoord != end; ++texCoord )
                    {
                        texCoords[ texCoord-line.begin()-1 ] = std::stof( *texCoord );
                    }
                    m_textureList.push_back( TextureCoordinates( { texCoords[0], texCoords[1], texCoords[2] } ) );
                }
            }
            else if ( line.front() == k_linePrefix[ NormalDirection ] )
            {
                // Make sure we have the right number of components
                if ( line.size() == 4 )
                {
                    float normal[3] = { 0.0f };
                    for ( auto normalComp ( line.begin()+1 ), end ( line.end() ); normalComp != end; ++normalComp )
                    {
                        normal[ normalComp-line.begin()-1 ] = std::stof( *normalComp );
                    }
                    m_normalList.push_back( Normal( { normal[0], normal[1], normal[2] } ) );
                }
            }
            else if ( line.front() == k_linePrefix[ FaceDefinition ] )
            {
                // We assume triangles
                if ( line.size() == 4 )
                {
                    int coordinates[3] = { 0 };
                    int texture[3] = { 0 };
                    int normal[3] = { 0 };

                    for ( auto comp ( line.begin()+1 ), end ( line.end() ); comp != end; ++comp )
                    {
                        int const firstSlash ( (int)( (*comp).find( '/', 0 ) ) );
                        if ( firstSlash != (int)std::string::npos )
                        {
                            coordinates[ comp - line.begin() - 1 ] = std::stoi( (*comp).substr( 0, (long long unsigned int)firstSlash ) );
                            int const secondSlash ( (int)( (*comp).find( '/', (long long unsigned int)firstSlash+1 ) ) );
                            if ( secondSlash != (int)std::string::npos )
                            {
                                if ( secondSlash - firstSlash > 1 )
                                {
                                    texture[ comp - line.begin() - 1 ] = std::stoi( (*comp).substr( (long long unsigned int)firstSlash+1, (long long unsigned int)( secondSlash-firstSlash ) ) );
                                }
                                normal[ comp - line.begin() - 1 ] = std::stoi( (*comp).substr( (long long unsigned int)secondSlash+1 ) );
                            }
                            else
                            {
                                texture[ comp - line.begin() - 1 ] = std::stoi( (*comp).substr( (long long unsigned int)firstSlash+1 ) );
                            }

                        }
                        else
                        {
                            coordinates[ comp - line.begin() - 1 ] = std::stoi( *comp );
                        }
                    }

                    m_faceList.push_back( Face( { coordinates[0], coordinates[1], coordinates[2],
                                                  texture[0], texture[1], texture[2],
                                                  normal[0], normal[1], normal[2] } ) );
                }
            }
        }
    }
}
