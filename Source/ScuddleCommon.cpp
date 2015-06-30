//--------------------------------------------------------------------------------------------------
//
//  File:       ScuddleCommon.cpp
//
//  Project:    Scuddle
//
//  Contains:   The declarations of global functions used in Scuddle.
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

#include "ScuddleCommon.h"

#if defined(__APPLE__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunknown-pragmas"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#endif // defined(__APPLE__)
/*! @file
 @brief The declarations of global functions used in Scuddle. */
#if defined(__APPLE__)
# pragma clang diagnostic pop
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Namespace references
#endif // defined(__APPLE__)

using namespace Scuddle;

#if defined(__APPLE__)
# pragma mark Private structures, constants and variables
#endif // defined(__APPLE__)

/*! @brief The clip range for the random number generator - must be less than the output range of
 the rand() function. */
static const int kModulus = 1000;

/*! @brief @c true if the value for PI has been set and @c false otherwise. */
static bool lPiSet = false;

/*! @brief @c true if the random number generator has been seeded and @c false otherwise. */
static bool lRandomSeeded = false;

/*! @brief The value of PI. */
static realType lPi = static_cast<realType>(3.14159265);

#if defined(__APPLE__)
# pragma mark Global constants and variables
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Local functions
#endif // defined(__APPLE__)

/*! @brief Seed the random number generator. */
static void initRandom(void)
{
    if (! lRandomSeeded)
    {
#if defined(__APPLE__)
        sranddev();
#else // ! defined(__APPLE__)
        srand(clock());
#endif // ! defined(__APPLE__)
        lRandomSeeded = true;
    }
} // initRandom

#if defined(__APPLE__)
# pragma mark Class methods
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Constructors and Destructors
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)

realType Scuddle::DegreesToRadians(const realType inAngle)
{
    if (! lPiSet)
    {
        lPi = (4 * static_cast<realType>(atan2(1, 1)));
        lPiSet = true;
    }
    return (lPi * inAngle / 180);
} // Scuddle::DegreesToRadians

int Scuddle::MapAngleToQuadrant(const realType angle,
                                const realType firstAngle,
                                const int      firstQuadrant,
                                const realType secondAngle,
                                const int      secondQuadrant,
                                const realType thirdAngle,
                                const int      thirdQuadrant,
                                const int      fourthQuadrant)
{
    int      result;
    realType asDegrees = RadiansToDegrees(angle) - gEpsilon;
    
    if (firstAngle >= asDegrees)
    {
        result = firstQuadrant;
    }
    else if (secondAngle >= asDegrees)
    {
        result = secondQuadrant;
    }
    else if (thirdAngle >= asDegrees)
    {
        result = thirdQuadrant;
    }
    else
    {
        result = fourthQuadrant;
    }
    return result;
} // Scuddle::MapAngleToQuadrant

realType Scuddle::MapFlowToReal(const FlowQuality aValue)
{
    realType result;
    
    switch (aValue)
    {
        case kFlowFree :
            result = 0;
            break;
            
        case kFlowBound :
            result = 1;
            break;
            
    }
    return result;
} // Scuddle::MapSpaceToReal

realType Scuddle::MapHeightToReal(const HeightValue aValue)
{
    realType result;
    
    switch (aValue)
    {
        case kHeightLow :
            result = 0;
            break;
            
        case kHeightMidLow :
            result = 1;
            break;
            
        case kHeightMiddle :
            result = 2;
            break;
            
        case kHeightMidHigh :
            result = 3;
            break;
            
        case kHeightHigh :
            result = 4;
            break;
            
    }
    return result;
} // Scuddle::MapHeightToReal

FlowQuality Scuddle::MapRealToFlow(const realType aValue)
{
    FlowQuality result;
    
    if (ReallyClose(aValue, 1))
    {
        result = kFlowBound;
    }
    else
    {
        result = kFlowFree;
    }
    return result;
} // Scuddle::MapRealToSpace

HeightValue Scuddle::MapRealToHeight(const realType aValue)
{
    HeightValue result;
    
    if (ReallyClose(aValue, 4))
    {
        result = kHeightHigh;
    }
    else if (ReallyClose(aValue, 3))
    {
        result = kHeightMidHigh;
    }
    else if (ReallyClose(aValue, 2))
    {
        result = kHeightMiddle;
    }
    else if (ReallyClose(aValue, 1))
    {
        result = kHeightMidLow;
    }
    else
    {
        result = kHeightLow;
    }
    return result;
} // Scuddle::MapRealToHeight

SpaceQuality Scuddle::MapRealToSpace(const realType aValue)
{
    SpaceQuality result;
    
    if (ReallyClose(aValue, 1))
    {
        result = kSpaceDirect;
    }
    else
    {
        result = kSpaceIndirect;
    }
    return result;
} // Scuddle::MapRealToSpace

TimeQuality Scuddle::MapRealToTime(const realType aValue)
{
    TimeQuality result;
    
    if (ReallyClose(aValue, 1))
    {
        result = kTimeSudden;
    }
    else
    {
        result = kTimeSustained;
    }
    return result;
} // Scuddle::MapRealToTime

WeightQuality Scuddle::MapRealToWeight(const realType aValue)
{
    WeightQuality result;
    
    if (ReallyClose(aValue, 1))
    {
        result = kWeightStrong;
    }
    else
    {
        result = kWeightLight;
    }
    return result;
} // Scuddle::MapRealToWeight

realType Scuddle::MapSpaceToReal(const SpaceQuality aValue)
{
    realType result;
    
    switch (aValue)
    {
        case kSpaceIndirect :
            result = 0;
            break;
            
        case kSpaceDirect :
            result = 1;
            break;
            
    }
    return result;
} // Scuddle::MapSpaceToReal

realType Scuddle::MapTimeToReal(const TimeQuality aValue)
{
    realType result;
    
    switch (aValue)
    {
        case kTimeSustained :
            result = 0;
            break;
            
        case kTimeSudden :
            result = 1;
            break;
            
    }
    return result;
} // Scuddle::MapTimeToReal

realType Scuddle::MapWeightToReal(const WeightQuality aValue)
{
    realType result;
    
    switch (aValue)
    {
        case kWeightLight :
            result = 0;
            break;
            
        case kWeightStrong :
            result = 1;
            break;
            
    }
    return result;
} // Scuddle::MapWeightToReal

realType Scuddle::RadiansToDegrees(const realType inAngle)
{
    if (! lPiSet)
    {
        lPi = (4 * static_cast<realType>(atan2(1, 1)));
        lPiSet = true;
    }
    return (180 * inAngle / lPi);
} // Scuddle::RadiansToDegrees

realType Scuddle::RandomAngle(const realType maxAngle)
{
    return DegreesToRadians(RandRealInRange(0, maxAngle));
} // Scuddle::RandomAngle

realType Scuddle::RandRealInRange(const realType lowValue,
                                  const realType highValue)
{
    realType randNumb;

    initRandom();
    randNumb = (static_cast<realType>(rand() % kModulus) / (kModulus - 1));
    return (lowValue + (randNumb * (highValue - lowValue)));
} // Scuddle::RandRealInRange

size_t Scuddle::RandUnsignedInRange(const size_t highValue)
{
    initRandom();
    return static_cast<size_t>(static_cast<size_t>(rand() / kModulus) % (highValue + 1));
} // Scuddle::RandUnsignedInRange

bool Scuddle::ReallyClose(const realType firstValue,
                          const realType secondValue)
{
    return (std::abs(firstValue - secondValue) < gEpsilon);
} // Scuddle::ReallyClose
