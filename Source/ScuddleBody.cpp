//--------------------------------------------------------------------------------------------------
//
//  File:       ScuddleBody.cpp
//
//  Project:    Scuddle
//
//  Contains:   The class definition for Body objects.
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

#include "ScuddleBody.h"

#if defined(__APPLE__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunknown-pragmas"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#endif // defined(__APPLE__)
/*! @file
 @brief The class definition for Body objects. */
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

#if defined(GENERATE_POSITIONS_)
/*! @brief The maximum amount to perturb a coordinate. */
static const realType kPerturbation = 5;
#endif // defined(GENERATE_POSITIONS_)

#if defined(GENERATE_POSITIONS_)
/*! @brief The joint radius */
static const realType kJointRadius = 60;
#endif // defined(GENERATE_POSITIONS_)

/*! @brief The initial fitness coefficient for Bartenieff contralateral configurations. */
static const realType kInitialBartenieffContralateral = static_cast<realType>(1.3);

/*! @brief The initial fitness coefficient for Bartenieff distal configurations. */
static const realType kInitialBartenieffDistal = static_cast<realType>(0.4);

/*! @brief The initial fitness coefficient for Bartenieff homolateral configurations. */
static const realType kInitialBartenieffHomolateral = static_cast<realType>(0.5);

/*! @brief The initial fitness coefficient for Bartenieff homologous configurations. */
static const realType kInitialBartenieffHomologous = static_cast<realType>(0.4);

/*! @brief The initial fitness coefficient for Bartenieff medial configurations. */
static const realType kInitialBartenieffMedial = static_cast<realType>(0.7);

/*! @brief The initial fitness coefficient for high Effort configurations. */
static const realType kInitialEffortHigh = static_cast<realType>(1.4);

/*! @brief The initial fitness coefficient for low Effort configurations. */
static const realType kInitialEffortLow = static_cast<realType>(0.6);

/*! @brief The initial fitness coefficient for medium Effort configurations. */
static const realType kInitialEffortMedium = static_cast<realType>(1.2);

/*! @brief The initial fitness coefficient for fully extended leg configurations. */
static const realType kInitialFullyExtendedLeg = static_cast<realType>(1.1);

/*! @brief The initial fitness coefficient for lower leg extended configurations. */
static const realType kInitialLowerLegExtended = static_cast<realType>(1.3);

/*! @brief The initial fitness coefficient for unextended leg configurations. */
static const realType kInitialUnextendedLegs = static_cast<realType>(0.3);

/*! @brief The maximum fitness coefficient for Bartenieff contralateral configurations. */
static const realType kMaximumBartenieffContralateral = static_cast<realType>(10);

/*! @brief The maximum fitness coefficient for Bartenieff distal configurations. */
static const realType kMaximumBartenieffDistal = static_cast<realType>(10);

/*! @brief The maximum fitness coefficient for Bartenieff homolateral configurations. */
static const realType kMaximumBartenieffHomolateral = static_cast<realType>(10);

/*! @brief The maximum fitness coefficient for Bartenieff homologous configurations. */
static const realType kMaximumBartenieffHomologous = static_cast<realType>(10);

/*! @brief The maximum fitness coefficient for Bartenieff medial configurations. */
static const realType kMaximumBartenieffMedial = static_cast<realType>(10);

/*! @brief The maximum fitness coefficient for high Effort configurations. */
static const realType kMaximumEffortHigh = static_cast<realType>(10);

/*! @brief The maximum fitness coefficient for low Effort configurations. */
static const realType kMaximumEffortLow = static_cast<realType>(10);

/*! @brief The maximum fitness coefficient for medium Effort configurations. */
static const realType kMaximumEffortMedium = static_cast<realType>(10);

/*! @brief The maximum fitness coefficient for fully extemded leg configurations. */
static const realType kMaximumFullyExtendedLeg = static_cast<realType>(10);

/*! @brief The maximum fitness coefficient for lower leg extemded configurations. */
static const realType kMaximumLowerLegExtended = static_cast<realType>(10);

/*! @brief The maximum fitness coefficient for unextended leg configurations. */
static const realType kMaximumUnextendedLegs = static_cast<realType>(10);

/*! @brief The minimum fitness coefficient for Bartenieff contralateral configurations. */
static const realType kMinimumBartenieffContralateral = static_cast<realType>(0);

/*! @brief The minimum fitness coefficient for Bartenieff distal configurations. */
static const realType kMinimumBartenieffDistal = static_cast<realType>(0);

/*! @brief The minimum fitness coefficient for Bartenieff homolateral configurations. */
static const realType kMinimumBartenieffHomolateral = static_cast<realType>(0);

/*! @brief The minimum fitness coefficient for Bartenieff homologous configurations. */
static const realType kMinimumBartenieffHomologous = static_cast<realType>(0);

/*! @brief The minimum fitness coefficient for Bartenieff medial configurations. */
static const realType kMinimumBartenieffMedial = static_cast<realType>(0);

/*! @brief The minimum fitness coefficient for high Effort configurations. */
static const realType kMinimumEffortHigh = static_cast<realType>(0);

/*! @brief The minimum fitness coefficient for low Effort configurations. */
static const realType kMinimumEffortLow = static_cast<realType>(0);

/*! @brief The minimum fitness coefficient for medium Effort configurations. */
static const realType kMinimumEffortMedium = static_cast<realType>(0);

/*! @brief The minimum fitness coefficient for fully extended leg configurations. */
static const realType kMinimumFullyExtendedLeg = static_cast<realType>(0);

/*! @brief The minimum fitness coefficient for lower leg extended configurations. */
static const realType kMinimumLowerLegExtended = static_cast<realType>(0);

/*! @brief The minimum fitness coefficient for unextended leg configurations. */
static const realType kMinimumUnextendedLegs = static_cast<realType>(0);

/*! @brief The number of angles that can be mutated. */
static const size_t kNumAngles = 8;

/*! @brief The number of attributes that can be swapped. */
static const size_t kNumAttributes = 13;

#if defined(__APPLE__)
# pragma mark Global constants and variables
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Class variables
#endif // defined(__APPLE__)

ConstrainedRealValue Body::bartenieffContralateral(kMinimumBartenieffContralateral,
                                                   kMaximumBartenieffContralateral,
                                                   kInitialBartenieffContralateral);

ConstrainedRealValue Body::bartenieffDistal(kMinimumBartenieffDistal, kMaximumBartenieffDistal,
                                            kInitialBartenieffDistal);

ConstrainedRealValue Body::bartenieffHomolateral(kMinimumBartenieffHomolateral,
                                                 kMaximumBartenieffHomolateral,
                                                 kInitialBartenieffHomolateral);

ConstrainedRealValue Body::bartenieffHomologous(kMinimumBartenieffHomologous,
                                                kMaximumBartenieffHomologous,
                                                kInitialBartenieffHomologous);

ConstrainedRealValue Body::bartenieffMedial(kMinimumBartenieffMedial, kMaximumBartenieffMedial,
                                            kInitialBartenieffMedial);

ConstrainedRealValue Body::effortHigh(kMinimumEffortHigh, kMaximumEffortHigh, kInitialEffortHigh);

ConstrainedRealValue Body::effortLow(kMinimumEffortLow, kMaximumEffortLow, kInitialEffortLow);

ConstrainedRealValue Body::effortMedium(kMinimumEffortMedium, kMaximumEffortMedium,
                                        kInitialEffortMedium);

ConstrainedRealValue Body::fullyExtendedLeg(kMinimumFullyExtendedLeg, kMaximumFullyExtendedLeg,
                                            kInitialFullyExtendedLeg);

ConstrainedRealValue Body::lowerLegExtended(kMinimumLowerLegExtended, kMaximumLowerLegExtended,
                                            kInitialLowerLegExtended);

ConstrainedRealValue Body::unextendedLegs(kMinimumUnextendedLegs, kMaximumUnextendedLegs,
                                          kInitialUnextendedLegs);

#if defined(__APPLE__)
# pragma mark Local functions
#endif // defined(__APPLE__)

#if defined(GENERATE_POSITIONS_)
static Coordinate2D generateRandomPerturbation(void)
{
    Coordinate2D result(RandRealInRange(- kPerturbation, kPerturbation),
                        RandRealInRange(- kPerturbation, kPerturbation));

    return result;
} // generateRandomPerturbation
#endif // defined(GENERATE_POSITIONS_)

#if defined(__APPLE__)
# pragma mark Class methods
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Constructors and Destructors
#endif // defined(__APPLE__)

#if defined(GENERATE_POSITIONS_)
Body::Body(const Coordinate2D & leftHip,
           const Coordinate2D & leftShoulder,
           const Coordinate2D & neck,
           const Coordinate2D & rightHip,
           const Coordinate2D & rightShoulder,
           const Coordinate2D & tail) :
    _initLeftHip(leftHip), _initLeftShoulder(leftShoulder), _initRightHip(rightHip),
    _initRightShoulder(rightShoulder), _neck(neck), _tail(tail), _marked(false)
{
    setAttributes();
    setPositions();
} // Body::Body
#endif // defined(GENERATE_POSITIONS_)

# if (! defined(GENERATE_POSITIONS_))
Body::Body(void) :
    _marked(false)
{
    setAttributes();
} // Body::Body
#endif // ! defined(GENERATE_POSITIONS_))

#if defined(GENERATE_POSITIONS_)
Body::Body(const Body & other) :
    _initLeftHip(other._initLeftHip), _initLeftShoulder(other._initLeftShoulder),
    _initRightHip(other._initRightHip), _initRightShoulder(other._initRightShoulder),
    _neck(other._neck), _tail(other._tail), _leftElbowToWristAngle(other._leftElbowToWristAngle),
    _leftHipToKneeAngle(other._leftHipToKneeAngle),
    _leftKneeToFootAngle(other._leftKneeToFootAngle),
    _leftShoulderToElbowAngle(other._leftShoulderToElbowAngle),
    _rightElbowToWristAngle(other._rightElbowToWristAngle),
    _rightHipToKneeAngle(other._rightHipToKneeAngle),
    _rightKneeToFootAngle(other._rightKneeToFootAngle),
    _rightShoulderToElbowAngle(other._rightShoulderToElbowAngle), _flow(other._flow),
    _height(other._height), _space(other._space), _time(other._time), _weight(other._weight),
    _marked(false)
{
    setPositions();
} // Body::Body
#else // ! defined(GENERATE_POSITIONS_)
Body::Body(const Body & other) :
    _leftElbowToWristAngle(other._leftElbowToWristAngle),
    _leftHipToKneeAngle(other._leftHipToKneeAngle),
    _leftKneeToFootAngle(other._leftKneeToFootAngle),
    _leftShoulderToElbowAngle(other._leftShoulderToElbowAngle),
    _rightElbowToWristAngle(other._rightElbowToWristAngle),
    _rightHipToKneeAngle(other._rightHipToKneeAngle),
    _rightKneeToFootAngle(other._rightKneeToFootAngle),
    _rightShoulderToElbowAngle(other._rightShoulderToElbowAngle), _flow(other._flow),
    _height(other._height), _space(other._space), _time(other._time), _weight(other._weight),
    _marked(false)
{
} // Body::Body
#endif // ! defined(GENERATE_POSITIONS_)

Body::~Body(void)
{
} // Body::~Body

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

void Body::determineQuadrants(void)
{
    // Calculate the quadrants:
    _leftShoulderToElbowQuadrant = MapAngleToQuadrant(_leftShoulderToElbowAngle, 90, 1, 180, 2, 270,
                                                      1, 4);
    _rightShoulderToElbowQuadrant = MapAngleToQuadrant(_rightShoulderToElbowAngle, 90, 2, 180, 1,
                                                       270, 4, 1);
    _leftElbowToWristQuadrant = MapAngleToQuadrant(_leftElbowToWristAngle, 45, 1, 90, 2, 135, 1, 4);
    _rightElbowToWristQuadrant = MapAngleToQuadrant(_rightElbowToWristAngle, 45, 2, 90, 1, 135, 4,
                                                    1);
    _leftHipToKneeQuadrant = MapAngleToQuadrant(_leftHipToKneeAngle, 90, 4, 180, 1, 270, 2, 1);
    _rightHipToKneeQuadrant = MapAngleToQuadrant(_rightHipToKneeAngle, 90, 1, 180, 4, 270, 1, 2);
    _leftKneeToFootQuadrant = MapAngleToQuadrant(_leftKneeToFootAngle, 45, 4, 90, 1, 135, 2, 1);
    _rightKneeToFootQuadrant = MapAngleToQuadrant(_rightKneeToFootAngle, 45, 1, 90, 4, 135, 1, 2);
    _quadrantScore = _leftShoulderToElbowQuadrant + _rightShoulderToElbowQuadrant +
                        _leftElbowToWristQuadrant + _rightElbowToWristQuadrant +
                        _leftHipToKneeQuadrant + _rightHipToKneeQuadrant + _leftKneeToFootQuadrant +
                        _rightKneeToFootQuadrant;
} // Body::determineQuadrants

void Body::mutate(void)
{
    // There are eight angles that can be mutated - pick one!
    realType distalValue = RandomAngle(180);
    realType medialValue = RandomAngle(360);
    size_t   whichAngle = RandUnsignedInRange(kNumAngles - 1);
    
    switch (whichAngle)
    {
        case 0 :
            _leftShoulderToElbowAngle = medialValue;
            break;
            
        case 1 :
            _leftElbowToWristAngle = distalValue;
            break;
            
        case 2 :
            _rightShoulderToElbowAngle = medialValue;
            break;
            
        case 3 :
            _rightElbowToWristAngle = distalValue;
            break;
            
        case 4 :
            _leftHipToKneeAngle = medialValue;
            break;
            
        case 5 :
            _leftKneeToFootAngle = distalValue;
            break;
            
        case 6 :
            _rightHipToKneeAngle = medialValue;
            break;
            
        case 7 : // This is (kNumAngles - 1).
            _rightKneeToFootAngle = distalValue;
            break;
            
        default :
            // Should NEVER get here!!!
            break;
            
    }
#if defined(GENERATE_POSITIONS_)
    setPositions();
#endif // defined(GENERATE_POSITIONS_)
} // Body::mutate

void Body::resetParameters(void)
{
    bartenieffContralateral.resetValue();
    bartenieffDistal.resetValue();
    bartenieffHomolateral.resetValue();
    bartenieffHomologous.resetValue();
    bartenieffMedial.resetValue();
    effortHigh.resetValue();
    effortLow.resetValue();
    effortMedium.resetValue();
    fullyExtendedLeg.resetValue();
    lowerLegExtended.resetValue();
    unextendedLegs.resetValue();
} // Body::resetParameters

void Body::setAttributes(void)
{
    // Generate random angles for joints: shoulder and hip locations affect elbow and knees.
    _leftShoulderToElbowAngle = RandomAngle(360);
    _leftElbowToWristAngle = RandomAngle(180);
    _rightShoulderToElbowAngle = RandomAngle(360);
    _rightElbowToWristAngle = RandomAngle(180);
    _leftHipToKneeAngle = RandomAngle(360);
    _leftKneeToFootAngle = RandomAngle(180);
    _rightHipToKneeAngle = RandomAngle(360);
    _rightKneeToFootAngle = RandomAngle(180);
    
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
} // Body::setAttributes

#if defined(GENERATE_POSITIONS_)
void Body::setPositions(void)
{
    _leftElbow = _initLeftShoulder + std::polar(kJointRadius, _leftShoulderToElbowAngle);
    _leftWrist = _leftElbow + std::polar(kJointRadius, _leftElbowToWristAngle);
    _leftShoulder = _initLeftShoulder + generateRandomPerturbation();
    _rightElbow = _initRightShoulder + std::polar(kJointRadius, _rightShoulderToElbowAngle);
    _rightWrist = _rightElbow + std::polar(kJointRadius, _rightElbowToWristAngle);
    _rightShoulder = _initRightShoulder + generateRandomPerturbation();
    _leftKnee = _initLeftHip + std::polar(kJointRadius, _leftHipToKneeAngle);
    _leftFoot = _leftKnee + std::polar(kJointRadius, _leftKneeToFootAngle);
    _leftHip = _initLeftHip + generateRandomPerturbation();
    _rightKnee = _initRightHip + std::polar(kJointRadius, _rightHipToKneeAngle);
    _rightFoot = _rightKnee + std::polar(kJointRadius, _rightKneeToFootAngle);
    _rightHip = _initRightHip + generateRandomPerturbation();
    realType centre = _leftHip.real() + (std::abs(_rightHip.real() - _leftHip.real()) / 2);
    
    _neck.real(centre);
    _tail.real(centre);
} // Body::setPositions
#endif // defined(GENERATE_POSITIONS_)

#if defined(USE_FRACTION_FOR_CROSSOVER_)
void Body::swapValues(Body &         other,
                      const realType fraction)
#else // ! defined(USE_FRACTION_FOR_CROSSOVER_)
void Body::swapValues(Body &       other,
                      const size_t numSwap)
#endif // ! defined(USE_FRACTION_FOR_CROSSOVER_)
{
    // We have 13 values that we can work with.
    size_t realSwap;
#if defined(USE_FRACTION_FOR_CROSSOVER_)
    size_t numSwap = static_cast<size_t>(kNumAttributes * fraction);
#endif // ! defined(USE_FRACTION_FOR_CROSSOVER_)
    
    if (kNumAttributes < numSwap)
    {
        realSwap = kNumAttributes;
    }
    else
    {
        realSwap = numSwap;
    }
    // Collect a set of indices to swap.
    std::vector<size_t> indices;
    
    for (bool tryAgain = true; tryAgain; )
    {
        size_t anIndex = RandUnsignedInRange(kNumAttributes - 1);
        
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
        switch (*walker)
        {
            case 0 :
                std::swap(_leftShoulderToElbowAngle, other._leftShoulderToElbowAngle);
                break;
                
            case 1 :
                std::swap(_leftElbowToWristAngle, other._leftElbowToWristAngle);
                break;
                
            case 2 :
                std::swap(_rightShoulderToElbowAngle, other._rightShoulderToElbowAngle);
                break;
                
            case 3 :
                std::swap(_rightElbowToWristAngle, other._rightElbowToWristAngle);
                break;
                
            case 4 :
                std::swap(_leftHipToKneeAngle, other._leftHipToKneeAngle);
                break;
                
            case 5 :
                std::swap(_leftKneeToFootAngle, other._leftKneeToFootAngle);
                break;
                
            case 6 :
                std::swap(_rightHipToKneeAngle, other._rightHipToKneeAngle);
                break;
                
            case 7 :
                std::swap(_rightKneeToFootAngle, other._rightKneeToFootAngle);
                break;
                
            case 8 :
                std::swap(_weight, other._weight);
                break;
                
            case 9 :
                std::swap(_space, other._space);
                break;
                
            case 10 :
                std::swap(_time, other._time);
                break;
                
            case 11 :
                std::swap(_flow, other._flow);
                break;
                
            case 12 : // This is (kNumAttributes - 1).
                std::swap(_height, other._height);
                break;
                
            default :
                // Should NEVER get here!!!
                break;
                
        }
    }
#if defined(GENERATE_POSITIONS_)
    setPositions();
    other.setPositions();
#endif // defined(GENERATE_POSITIONS_)
} // Body::swapValues

void Body::updateFitness(void)
{
    realType critAngle = DegreesToRadians(30);
    realType bartenieffFactor;
    realType effortFactor;
    realType heightFactor;
    
    determineQuadrants();
    if ((8 == _quadrantScore) &&
        ((_leftShoulderToElbowQuadrant == _leftElbowToWristQuadrant) &&
         (_rightShoulderToElbowQuadrant == _rightElbowToWristQuadrant) &&
         (_leftHipToKneeQuadrant == _leftKneeToFootQuadrant) &&
         (_rightHipToKneeQuadrant == _rightKneeToFootQuadrant)))
    {
        // Distal
        bartenieffFactor = bartenieffDistal.getValue();
    }
    else if ((12 == _quadrantScore) &&
             ((_leftShoulderToElbowQuadrant == _leftElbowToWristQuadrant) &&
              (_rightShoulderToElbowQuadrant == _rightElbowToWristQuadrant) &&
              (_leftHipToKneeQuadrant == _leftKneeToFootQuadrant) &&
              (_rightHipToKneeQuadrant == _rightKneeToFootQuadrant)))
    {
        // Medial
        bartenieffFactor = bartenieffMedial.getValue();
    }
    else if ((((std::abs(_leftShoulderToElbowAngle - _leftHipToKneeAngle) > critAngle) &&
               (std::abs(_leftElbowToWristAngle - _leftKneeToFootAngle) > critAngle))) ||
             (((std::abs(_rightShoulderToElbowAngle - _rightHipToKneeAngle) > critAngle) &&
               (std::abs(_rightElbowToWristAngle - _rightKneeToFootAngle) > critAngle))))
    {
        // Homolateral
        bartenieffFactor = bartenieffHomolateral.getValue();
    }
    else if ((((std::abs(_leftShoulderToElbowAngle - _rightHipToKneeAngle) > critAngle) &&
               (std::abs(_leftElbowToWristAngle - _rightKneeToFootAngle) > critAngle))) ||
             (((std::abs(_rightShoulderToElbowAngle - _leftHipToKneeAngle) > critAngle) &&
               (std::abs(_rightElbowToWristAngle - _leftKneeToFootAngle) > critAngle))))
    {
        // Contralateral
        bartenieffFactor = bartenieffContralateral.getValue();
    }
    else if (((_leftShoulderToElbowQuadrant == _rightShoulderToElbowQuadrant) &&
              (_leftElbowToWristQuadrant == _rightElbowToWristQuadrant)) ||
             ((_leftHipToKneeQuadrant == _rightHipToKneeQuadrant) &&
              (_leftKneeToFootQuadrant == _rightKneeToFootQuadrant)))
    {
        // Homologous
        bartenieffFactor = bartenieffHomologous.getValue();
    }
    else
    {
        bartenieffFactor = 0.0;
    }
    // Laban
    if (((kWeightLight == _weight) && (kSpaceIndirect == _space) && (kTimeSustained == _time) &&
         (kFlowFree == _flow)) || ((kWeightStrong == _weight) && (kSpaceDirect == _space) &&
                                   (kTimeSudden == _time) && (kFlowBound == _flow)))
    {
        effortFactor = effortLow.getValue();
    }
    else if ((ReallyClose(MapWeightToReal(_weight), MapSpaceToReal(_space)) &&
              ReallyClose(MapTimeToReal(_time), MapFlowToReal(_flow))) ||
             (ReallyClose(MapWeightToReal(_weight), MapTimeToReal(_time)) &&
              ReallyClose(MapSpaceToReal(_space), MapFlowToReal(_flow))) ||
             (ReallyClose(MapWeightToReal(_weight), MapFlowToReal(_flow)) &&
              ReallyClose(MapSpaceToReal(_space), MapTimeToReal(_time))))
    {
        effortFactor = effortMedium.getValue();
    }
    else
    {
        effortFactor = effortHigh.getValue();
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
        if ((1 == _leftHipToKneeQuadrant) || (2 == _leftHipToKneeQuadrant) ||
            (1 == _rightHipToKneeQuadrant) || ((2 == _rightHipToKneeQuadrant) &&
            (1 == _leftKneeToFootQuadrant)) || (2 == _leftKneeToFootQuadrant) ||
            (1 == _rightKneeToFootQuadrant) || (2 == _rightKneeToFootQuadrant))
        {
            // One leg is fully extended
            heightFactor = fullyExtendedLeg.getValue();
        }
        
        else if ((1 == _leftKneeToFootQuadrant) || (2 == _leftKneeToFootQuadrant) ||
                 (1 == _rightKneeToFootQuadrant) || (2 == _rightKneeToFootQuadrant))
        {
            // Only the lower leg is extended
            heightFactor = lowerLegExtended.getValue();
        }
        else
        {
            // No leg is extended - cannot jump without legs in a crouch!
            heightFactor = unextendedLegs.getValue();
        }
    }
    _accumulatedScore = ((bartenieffFactor + effortFactor + heightFactor) * _quadrantScore);
} // Body::updateFitness

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)
