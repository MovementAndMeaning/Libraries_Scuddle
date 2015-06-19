//--------------------------------------------------------------------------------------------------
//
//  File:       ScuddleSkeleton.cpp
//
//  Project:    Scuddle
//
//  Contains:   The class definition for Skeleton objects.
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
//  Created:    2015-06-19
//
//--------------------------------------------------------------------------------------------------

#include "ScuddleSkeleton.h"

#include <vector>

#if defined(__APPLE__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunknown-pragmas"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#endif // defined(__APPLE__)
/*! @file
 @brief The class definition for Skeleton objects. */
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

/*! @brief The number of fixed attributes that can be swapped. */
static const size_t kNumFixedAttributes = 5;

#if defined(__APPLE__)
# pragma mark Global constants and variables
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Local functions
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Class methods
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Constructors and Destructors
#endif // defined(__APPLE__)

Skeleton::Skeleton(void) :
    _marked(false)
{
    setAttributes(kNumCalculatedAngles);
} // Skeleton::Skeleton

Skeleton::Skeleton(const Skeleton & other) :
    _flow(other._flow), _height(other._height), _space(other._space), _time(other._time),
    _weight(other._weight), _marked(false)
{
    for (size_t ii = 0, imax = other._angles.size(); imax > ii; ++ii)
    {
        _angles.push_back(other._angles[ii]);
        _quadrants.push_back(other._quadrants[ii]);
    }
} // Skeleton::Skeleton

Skeleton::~Skeleton(void)
{
} // Skeleton::~Skeleton

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

void Skeleton::determineQuadrants(void)
{
    // Calculate the quadrants:
    _quadrants[kLeftShoulderToElbow] = MapAngleToQuadrant(_angles[kLeftShoulderToElbow],
                                                               90, 1, 180, 2, 270, 1, 4);
    _quadrants[kLeftShoulderToElbow] = MapAngleToQuadrant(_angles[kLeftShoulderToElbow],
                                                               90, 1, 180, 2, 270, 1, 4);
    _quadrants[kRightShoulderToElbow] = MapAngleToQuadrant(_angles[kRightShoulderToElbow],
                                                                90, 2, 180, 1, 270, 4, 1);
    _quadrants[kLeftElbowToWrist] = MapAngleToQuadrant(_angles[kLeftElbowToWrist], 45, 1,
                                                            90, 2, 135, 1, 4);
    _quadrants[kRightElbowToWrist] = MapAngleToQuadrant(_angles[kRightElbowToWrist], 45,
                                                             2, 90, 1, 135, 4, 1);
    _quadrants[kLeftHipToKnee] = MapAngleToQuadrant(_angles[kLeftHipToKnee], 90, 4, 180,
                                                         1, 270, 2, 1);
    _quadrants[kRightHipToKnee] = MapAngleToQuadrant(_angles[kRightHipToKnee], 90, 1, 180,
                                                          4, 270, 1, 2);
    _quadrants[kLeftKneeToFoot] = MapAngleToQuadrant(_angles[kLeftKneeToFoot], 45, 4, 90,
                                                          1, 135, 2, 1);
    _quadrants[kRightKneeToFoot] = MapAngleToQuadrant(_angles[kRightKneeToFoot], 45, 1,
                                                           90, 4, 135, 1, 2);
    _quadrantScore = 0;
    for (size_t ii = 0, imax = _quadrants.size(); imax > ii; ++ii)
    {
        _quadrantScore += _quadrants[ii];
    }
} // Skeleton::determineQuadrants

realType Skeleton::getAngleAsDegrees(const size_t index)
const
{
    realType result;
    
    if (index < _angles.size())
    {
        result = RadiansToDegrees(_angles[index]);
    }
    else
    {
        result = RadiansToDegrees(RandomAngle(360));
    }
    return result;
} // Skeleton::getAngleAsDegrees

glm::quat Skeleton::getAngleAsQuaternion(const size_t index)
const
{
    realType angle;
    
    if (index < _angles.size())
    {
        angle = _angles[index];
    }
    else
    {
        angle = RandomAngle(360);
    }
    return glm::quat_cast(glm::rotate(glm::mat4(1), angle, glm::vec3(0, 0, 1)));
} // Skeleton::getAngleAsQuaternion

size_t Skeleton::getNumAngles(void)
const
{
    return _angles.size();
} // Skeleton::getNumAngles

void Skeleton::mutate(void)
{
    realType newAngleValue = RandomAngle(360);
    size_t   imax = _angles.size();
    
    if (1 < imax)
    {
        size_t whichAngle = RandUnsignedInRange(imax - 1);
        
        _angles[whichAngle] = newAngleValue;
    }
    else if (1 == imax)
    {
        _angles[0] = newAngleValue;
    }
} // Skeleton::mutate

void Skeleton::setAttributes(const size_t numAngles)
{
    for (size_t ii = 0; numAngles > ii; ++ii)
    {
        _quadrants.push_back(-1);
    }
    _angles.resize(numAngles);
    _angles[kLeftShoulderToElbow] = RandomAngle(360);
    _angles[kLeftElbowToWrist] = RandomAngle(180);
    _angles[kRightShoulderToElbow] = RandomAngle(360);
    _angles[kRightElbowToWrist] = RandomAngle(180);
    _angles[kLeftHipToKnee] = RandomAngle(360);
    _angles[kLeftKneeToFoot] = RandomAngle(180);
    _angles[kRightHipToKnee] = RandomAngle(360);
    _angles[kRightKneeToFoot] = RandomAngle(180);
    _flow = ((0.5 <= RandRealInRange(0, 1)) ? kFlowBound : kFlowFree);
    _space = ((0.5 <= RandRealInRange(0, 1)) ? kSpaceDirect : kSpaceIndirect);
    _time = ((0.5 <= RandRealInRange(0, 1)) ? kTimeSudden : kTimeSustained);
    _weight = ((0.5 <= RandRealInRange(0, 1)) ? kWeightStrong : kWeightLight);
    realType aNumb = RandRealInRange(0, 1);
    
    if (0.8 <= aNumb)
    {
        _height = kHeightHigh;
    }
    else if (0.6 <= aNumb)
    {
        _height = kHeightMidHigh;
    }
    else if (0.4 <= aNumb)
    {
        _height = kHeightMiddle;
    }
    else if (0.2 <= aNumb)
    {
        _height = kHeightMidLow;
    }
    else
    {
        _height = kHeightLow;
    }
} // Skeleton::setAttributes

void Skeleton::swapValues(Skeleton &   other,
                          const size_t numSwap)
{
    size_t imax = std::min(_angles.size(), other._angles.size());
    size_t numAttributes = kNumFixedAttributes + imax;
    size_t realSwap;
    
    if (numAttributes < numSwap)
    {
        realSwap = numAttributes;
    }
    else
    {
        realSwap = numSwap;
    }
    // Collect a set of indices to swap.
    std::vector<size_t> indices;
    
    for (bool tryAgain = true; tryAgain; )
    {
        size_t anIndex = RandUnsignedInRange(numAttributes - 1);
        
        tryAgain = false;
        for (std::vector<size_t>::iterator walker(indices.begin()); indices.end() != walker;
             ++walker)
        {
            if (anIndex == *walker)
            {
                tryAgain = true;
                break;
            }
            
        }
        if (! tryAgain)
        {
            indices.push_back(anIndex);
            if (realSwap > indices.size())
            {
                tryAgain = true;
            }
        }
    }
    for (std::vector<size_t>::iterator walker(indices.begin()); indices.end() != walker; ++walker)
    {
        size_t anIndex = *walker;
        
        switch (anIndex)
        {
            case 0 :
                std::swap(_weight, other._weight);
                break;
                
            case 1 :
                std::swap(_space, other._space);
                break;
                
            case 2 :
                std::swap(_time, other._time);
                break;
                
            case 3 :
                std::swap(_flow, other._flow);
                break;
                
            case 4 : // This is (kNumAttributes - 1).
                std::swap(_height, other._height);
                break;
                
            default :
                // Angles -
                anIndex -= kNumFixedAttributes;
                if (imax > anIndex)
                {
                    std::swap(_angles[anIndex], other._angles[anIndex]);
                }
                break;
                
        }
    }
} // Skeleton::swapValues

void Skeleton::updateFitness(void)
{
    realType critAngle = DegreesToRadians(30);
    realType percentageBartenieff;
    realType percentageEffort = 0;
    realType percentageHeight = 0;
    
    determineQuadrants();
    if ((8 == _quadrantScore) &&
        ((_quadrants[kLeftShoulderToElbow] == _quadrants[kLeftElbowToWrist]) &&
         (_quadrants[kRightShoulderToElbow] == _quadrants[kRightElbowToWrist]) &&
         (_quadrants[kLeftHipToKnee] == _quadrants[kLeftKneeToFoot]) &&
         (_quadrants[kRightHipToKnee] == _quadrants[kRightKneeToFoot])))
    {
        // Distal
        percentageBartenieff = static_cast<realType>(0.4);
    }
    else if ((12 == _quadrantScore) &&
             ((_quadrants[kLeftShoulderToElbow] == _quadrants[kLeftElbowToWrist]) &&
              (_quadrants[kRightShoulderToElbow] == _quadrants[kRightElbowToWrist]) &&
              (_quadrants[kLeftHipToKnee] == _quadrants[kLeftKneeToFoot]) &&
              (_quadrants[kRightHipToKnee] == _quadrants[kRightKneeToFoot])))
    {
        // Medial
        percentageBartenieff = static_cast<realType>(0.7);
    }
    else if ((((std::abs(_angles[kLeftShoulderToElbow] - _angles[kLeftHipToKnee]) > critAngle) &&
               (std::abs(_angles[kLeftElbowToWrist] - _angles[kLeftKneeToFoot]) > critAngle))) ||
             (((std::abs(_angles[kRightShoulderToElbow] - _angles[kRightHipToKnee]) > critAngle) &&
               (std::abs(_angles[kRightElbowToWrist] - _angles[kRightKneeToFoot]) > critAngle))))
    {
        // Homolateral
        percentageBartenieff = static_cast<realType>(0.5);
    }
    else if ((((std::abs(_angles[kLeftShoulderToElbow] - _angles[kRightHipToKnee]) > critAngle) &&
               (std::abs(_angles[kLeftElbowToWrist] - _angles[kRightKneeToFoot]) > critAngle))) ||
             (((std::abs(_angles[kRightShoulderToElbow] - _angles[kLeftHipToKnee]) > critAngle) &&
               (std::abs(_angles[kRightElbowToWrist] - _angles[kLeftKneeToFoot]) > critAngle))))
    {
        // Contralateral
        percentageBartenieff = static_cast<realType>(1.3);
    }
    else if (((_quadrants[kLeftShoulderToElbow] == _quadrants[kRightShoulderToElbow]) &&
              (_quadrants[kLeftElbowToWrist] == _quadrants[kRightElbowToWrist])) ||
             ((_quadrants[kLeftHipToKnee] == _quadrants[kRightHipToKnee]) &&
              (_quadrants[kLeftKneeToFoot] == _quadrants[kRightKneeToFoot])))
    {
        // Homologous
        percentageBartenieff = static_cast<realType>(0.4);
    }
    else
    {
        percentageBartenieff = 0.0;
    }
    // Laban
    if (((kWeightLight == _weight) && (kSpaceIndirect == _space) && (kTimeSustained == _time) &&
         (kFlowFree == _flow)) || ((kWeightStrong == _weight) && (kSpaceDirect == _space) &&
                                   (kTimeSudden == _time) && (kFlowBound == _flow)))
    {
        percentageEffort = static_cast<realType>(0.6);
    }
    else if ((ReallyClose(MapWeightToReal(_weight), MapSpaceToReal(_space)) &&
              ReallyClose(MapTimeToReal(_time), MapFlowToReal(_flow))) ||
             (ReallyClose(MapWeightToReal(_weight), MapTimeToReal(_time)) &&
              ReallyClose(MapSpaceToReal(_space), MapFlowToReal(_flow))) ||
             (ReallyClose(MapWeightToReal(_weight), MapFlowToReal(_flow)) &&
              ReallyClose(MapSpaceToReal(_space), MapTimeToReal(_time))))
    {
        percentageEffort = static_cast<realType>(1.2);
    }
    else
    {
        percentageEffort = static_cast<realType>(1.4);
    }
    // Height
    if ((kHeightLow == _height) || (kHeightMiddle == _height) || (kHeightHigh == _height))
    {
        // Make another variable so can track which height is picked
        _quadrantScore = _quadrantScore + 1;
    }
    else
    {
        _quadrantScore = _quadrantScore + 3;
    }
    if ((kHeightMidLow == _height) || (kHeightMiddle == _height) || (kHeightMidHigh == _height))
    {
        {
            // No leg is extended - cannot jump without legs in a crouch!
            percentageHeight = static_cast<realType>(0.3);
        }
    }
    _accumulatedScore = ((percentageBartenieff + percentageEffort + percentageHeight) *
                         _quadrantScore);
} // Skeleton::updateFitness

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)
