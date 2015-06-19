//--------------------------------------------------------------------------------------------------
//
//  File:       ScuddleCommon.h
//
//  Project:    Scuddle
//
//  Contains:   The definitions of global functions used in Scuddle.
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
//  Created:    2015-06-17
//
//--------------------------------------------------------------------------------------------------

#if (! defined(Scuddle_Common_H_))
# define Scuddle_Common_H_ /* Header guard */

# include "ScuddleDataTypes.h"

# include <limits>
# include <vector>

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The definitions of global functions used in Scuddle. */

/*! @namespace Scuddle
 @brief The classes that implement the Scuddle framework. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

namespace Scuddle
{

    /*! @brief Convert an angle in degrees to radians.
     @param inAngle The angle specified in degrees.
     @returns The angle as radians. */
    realType DegreesToRadians(const realType inAngle);
    
    /*! @brief Convert a Flow Quality value into a floating-point number.
     @param aValue The value to be converted.
     @returns The Flow Quality value as a floating-point number. */
    realType MapFlowToReal(const FlowQuality aValue);
    
    /*! @brief Convert a Height level value into a floating-point number.
     @param aValue The value to be converted.
     @returns The Height level value as a floating-point number. */
    realType MapHeightToReal(const HeightValue aValue);
    
    /*! @brief Convert a floating-point number into a Flow Quality value.
     @param aValue The value to be converted.
     @returns The floating-point number as a Flow Quality value. */
    FlowQuality MapRealToFlow(const realType aValue);
    
    /*! @brief Convert a floating-point number into a Height level value.
     @param aValue The value to be converted.
     @returns The floating-point number as a Height level value. */
    HeightValue MapRealToHeight(const realType aValue);
    
    /*! @brief Convert a floating-point number into a Space Quality value.
     @param aValue The value to be converted.
     @returns The floating-point number as a Space Quality value. */
    SpaceQuality MapRealToSpace(const realType aValue);
    
    /*! @brief Convert a floating-point number into a Time Quality value.
     @param aValue The value to be converted.
     @returns The floating-point number as a Time Quality value. */
    TimeQuality MapRealToTime(const realType aValue);
    
    /*! @brief Convert a floating-point number into a Weight Quality value.
     @param aValue The value to be converted.
     @returns The floating-point number as a Weight Quality value. */
    WeightQuality MapRealToWeight(const realType aValue);
    
    /*! @brief Convert a Space Quality value into a floating-point number.
     @param aValue The value to be converted.
     @returns The Space Quality value as a floating-point number. */
    realType MapSpaceToReal(const SpaceQuality aValue);
    
    /*! @brief Convert a Time Quality value into a floating-point number.
     @param aValue The value to be converted.
     @returns The Time Quality value as a floating-point number. */
    realType MapTimeToReal(const TimeQuality aValue);
    
    /*! @brief Convert a Weight Quality value into a floating-point number.
     @param aValue The value to be converted.
     @returns The Weight Quality value as a floating-point number. */
    realType MapWeightToReal(const WeightQuality aValue);
    
    /*! @brief Convert an angle in radians to degrees.
     @param inAngle The angle specified in radians.
     @returns The angle as degrees. */
    realType RadiansToDegrees(const realType inAngle);

    /*! @brief Return a uniformly distributed random angle in the range 0..maxAngle, as radians.
     @param maxAngle The upper bound for the output, in degrees.
     @returns A uniformly distributed random angle in the range 0..maxAngle. */
    realType RandomAngle(const realType maxAngle);
    
    /*! @brief Return a uniformly distributed random number in the range lowValue..highValue.
     @param lowValue The lower bound for the output.
     @param highValue The upper bound for the output.
     @returns A uniformly distributed random number in the range lowValue..highValue. */
    realType RandRealInRange(const realType lowValue,
                             const realType highValue);

    /*! @brief Return a uniformly distributed random number in the range 0..highValue.
     @param highValue The upper bound for the output.
     @returns A uniformly distributed random number in the range 0..highValue. */
    size_t RandUnsignedInRange(const size_t highValue);

    /*! @brief Compare two floating-point numbers and determine if they are very close in value.
     @param firstValue The first value to compare.
     @param secondValue The second value to compare.
     @returns @c true if the two values are within epsilon of each other and @c false otherwise. */
    bool ReallyClose(const realType firstValue,
                     const realType secondValue);

    /*! @brief The comparison threshold used for conversion from floating-point numbers. */
    const realType gEpsilon = std::numeric_limits<realType>::epsilon();

} // Scuddle

#endif /* ! defined(Scuddle_Common_H_) */
