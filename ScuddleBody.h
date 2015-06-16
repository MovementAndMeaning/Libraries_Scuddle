//--------------------------------------------------------------------------------------------------
//
//  File:       ScuddleBody.h
//
//  Project:    Scuddle
//
//  Contains:   The class declaration for Body objects.
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

#if (! defined(Scuddle_Body_H_))
# define Scuddle_Body_H_ /* Header guard */

# include "ScuddleCoordinate2D.h"

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The class declaration for Body objects. */

/*! @namespace Scuddle
 @brief The classes that implement the Scuddle framework. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

namespace Scuddle
{
    
    /*! @brief The Scuddle Body structure. */
    class Body
    {
    public :
        
        /*! @brief The constructor. */
        Body(void);
        
        /*! @brief The destructor. */
        virtual ~Body(void);
        
    protected :
    
    private :
        
    public :
    
    protected :
    
    private :
        
        Coordinate2D _leftElbow;
        Coordinate2D _leftFoot;
        Coordinate2D _leftHips;
        Coordinate2D _leftKnee;
        Coordinate2D _leftShoulder;
        Coordinate2D _leftWrist;
        Coordinate2D _neck;
        Coordinate2D _rightElbow;
        Coordinate2D _rightFoot;
        Coordinate2D _rightHips;
        Coordinate2D _rightKnee;
        Coordinate2D _rightShoulder;
        Coordinate2D _rightWrist;
        Coordinate2D _tail;
        
# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunused-private-field"
# endif // defined(__APPLE__)
        /*! @brief Filler to pad to alignment boundary */
        char _filler[4];
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)
        
    }; // Body
    
} // Scuddle

#endif /* ! defined(Scuddle_Body_H_) */

#if 0
float WristLeftX, WristLeftY, ElbowLeftX, ElbowLeftY, ShoulderLeftX, ShoulderLeftY, WristRightX, WristRightY, ElbowRightX, ElbowRightY, ShoulderRightX, ShoulderRightY, HipsLeftX, HipsLeftY, KneeLeftX, KneeLeftY, FootLeftX, FootLeftY, HipsRightX, HipsRightY, KneeRightX, KneeRightY, FootRightX, FootRightY, NeckX, NeckY, TailX, TailY;
float angle1,angle2, angle3, angle4, angle5, angle6, angle7, angle8, angle9;
float Weight, Space, Time, Flow, Height;
float modShoulderLeftX, modShoulderLeftY, modShoulderRightX, modShoulderRightY, modHipsLeftX, modHipsLeftY, modHipsRightX, modHipsRightY;
#endif//0