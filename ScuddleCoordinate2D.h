//--------------------------------------------------------------------------------------------------
//
//  File:       ScuddleCoordinate2D.h
//
//  Project:    Scuddle
//
//  Contains:   The class declaration for objects representing two-dimensional coordinates.
//
//  Written by: Norman Jaffe
//
//  Copyright:  (c) 2015 by Simon Fraser University.
//
//              All rights reserved. Redistribution and use in source and binary forms, with or
//              without modification, are permitted provided that the following conditions are met:
//                * Redistributions of source code must retain the above copyright notice, this list
//                  of conditions and the following disclaimer.
//                * Redistributions in binary form must reproduce the above copyright notice, this
//                  list of conditions and the following disclaimer in the documentation and / or
//                  other materials provided with the distribution.
//                * Neither the name of the copyright holders nor the names of its contributors may
//                  be used to endorse or promote products derived from this software without
//                  specific prior written permission.
//
//              THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//              EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//              OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//              SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//              INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//              TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//              BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//              CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//              ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//              DAMAGE.
//
//  Created:    2015-06-16
//
//--------------------------------------------------------------------------------------------------

#if (! defined(Scuddle_Coordinate2D_H_))
# define Scuddle_Coordinate2D_H_ /* Header guard */

# include "ScuddleDataTypes.h"

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The class declaration for objects representing two-dimensional coordinates. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

namespace Scuddle
{
    /*! @brief A coordinate in two-dimensional space. */
    class Coordinate2D
    {
    public :
        
        /*! @brief The constructor.
         @param initX The initial horizontal coordinate.
         @param initY The initial vertical coordinate. */
        Coordinate2D(const float initX = 0,
                     const float initY = 0);
        
        /*! @brief The copy constructor.
         @param source The other object that is used to construct the new object. */
        Coordinate2D(const Coordinate2D & source);
        
        /*! @brief The destructor. */
        virtual ~Coordinate2D(void);
        
        /*! @brief The assignment operator.
         @param source The other object that is used to modify this object. */
        inline Coordinate2D & operator =(const Coordinate2D & source)
        {
            _x = source._x;
            _y = source._y;
            return *this;
        } // operator =

    protected :
    
    private :
    
    public :
    
    protected :
    
    private :
        
        /*! @brief The horizontal position. */
        float _x;
        
        /*! @brief The vertical position. */
        float _y;
        
# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunused-private-field"
# endif // defined(__APPLE__)
        /*! @brief Filler to pad to alignment boundary */
        char _filler[4];
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)
        
    }; // Coordinate2D

} // Scuddle

#endif /* ! defined(Scuddle_Coordinate2D_H_) */
