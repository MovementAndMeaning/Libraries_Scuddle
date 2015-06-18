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

# include "ScuddleCommon.h"

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
        
        /*! @brief The constructor.
         @param leftHip The initial coordinates of the left side of the hips.
         @param leftShoulder The initial coordinates of the left shoulder.
         @param neck The initial coordinates of the neck.
         @param rightHip The initial coordinates of the right side of the hips.
         @param rightShoulder The initial coordinates of the right shoulder.
         @param tail The initial coordinates of the 'tail. */
        Body(const Coordinate2D & leftHip,
             const Coordinate2D & leftShoulder,
             const Coordinate2D & neck,
             const Coordinate2D & rightHip,
             const Coordinate2D & rightShoulder,
             const Coordinate2D & tail);

        /*! @brief The copy constructor.
         @param other The Body to be copied. */
        Body(const Body & other);
        
        /*! @brief The destructor. */
        virtual ~Body(void);
        
        /*! @brief Unmark the object. */
        void clearMark(void)
        {
            _marked = false;
        } // clearMark
        
        /*! @brief Determine the quadrants for the various angles. */
        void determineQuadrants(void);
        
        /*! @brief Return the calculated fitness score.
         @returns The calculated fitness score. */
        realType getFitnessScore(void)
        const
        {
            return _accumulatedScore;
        } // getFitnessScore
        
        /*! @brief Return the Height level.
         @returns The Height level value. */
        FlowQuality getFlow(void)
        const
        {
            return _flow;
        } // getHeight
        
        /*! @brief Return the Space Quality.
         @returns The Space Quality value. */
        HeightValue getHeight(void)
        const
        {
            return _height;
        } // getSpace
        
        /*! @brief Return the coordinates of the left elbow.
         @returns The coordinates of the left elbow. */
        const Coordinate2D & getLeftElbow(void)
        const
        {
            return _leftElbow;
        } // getLeftElbow
        
        /*! @brief Return the angle from the left elbow to the left wrist.
         @returns The angle from the left elbow to the left wrist. */
        realType getLeftElbowToWristAngle(void)
        const
        {
            return _leftElbowToWristAngle;
        } // getLeftElbowToWristAngle

        /*! @brief Return the quadrant of the angle from the left elbow to the left wrist.
         @returns The quadrant of the angle from the left elbow to the left wrist. */
        int getLeftElbowToWristQuadrant(void)
        const
        {
            return _leftElbowToWristQuadrant;
        } // getLeftElbowToWristQuadrant
        
        /*! @brief Return the coordinates of the left foot.
         @returns The coordinates of the left foot. */
        const Coordinate2D & getLeftFoot(void)
        const
        {
            return _leftFoot;
        } // getLeftFoot
        
        /*! @brief Return the coordinates of the left side of the hips.
         @returns The coordinates of the left side of the hips. */
        const Coordinate2D & getLeftHip(void)
        const
        {
            return _leftHip;
        } // getLeftHip
        
        /*! @brief Return the angle from the left side of the hips to the left knee.
         @returns The angle from the left side of the hips to the left knee. */
        realType getLeftHipToKneeAngle(void)
        const
        {
            return _leftHipToKneeAngle;
        } // getLeftHipToKneeAngle

        /*! @brief Return the quadrant of the angle from left side of the hips to the left knee.
         @returns The quadrant of the angle from the left side of the hips to the left knee. */
        int getLeftHipToKneeQuadrant(void)
        const
        {
            return _leftHipToKneeQuadrant;
        } // getLeftHipToKneeQuadrant
        
        /*! @brief Return the coordinates of the left knee.
         @returns The coordinates of the left knee. */
        const Coordinate2D & getLeftKnee(void)
        const
        {
            return _leftKnee;
        } // getLeftKnee
        
        /*! @brief Return the angle from the left knee to the left foot.
         @returns The angle from the left knee to the left foot. */
        realType getLeftKneeToFootAngle(void)
        const
        {
            return _leftElbowToWristAngle;
        } // getLeftKneeToFootAngle
        
        /*! @brief Return the quadrant of the angle from the left knee to the left foot.
         @returns The quadrant of the angle from the left knee to the left foot. */
        int getLeftKneeToFootQuadrant(void)
        const
        {
            return _leftKneeToFootQuadrant;
        } // getLeftKneeToFootQuadrant
        
        /*! @brief Return the coordinates of the left shoulder.
         @returns The coordinates of the left shoulder. */
        const Coordinate2D & getLeftShoulder(void)
        const
        {
            return _leftShoulder;
        } // getLeftShoulder
        
        /*! @brief Return the angle from the left shoulder to the left elbow.
         @returns The angle from the left shoulder to the left elbow. */
        realType getLeftShoulderToElbowAngle(void)
        const
        {
            return _leftShoulderToElbowAngle;
        } // getLeftShoulderToElbowAngle
        
        /*! @brief Return the quadrant of the angle from the left shoulder to the left elbow.
         @returns The quadrant of the angle from the left shoulder to the left elbow. */
        int getLeftShoulderToElbowQuadrant(void)
        const
        {
            return _leftShoulderToElbowQuadrant;
        } // getLeftShoulderToElbowQuadrant
        
        /*! @brief Return the coordinates of the left wrist.
         @returns The coordinates of the left wrist. */
        const Coordinate2D & getLeftWrist(void)
        const
        {
            return _leftWrist;
        } // getLeftWrist
        
        /*! @brief Return the coordinates of the neck.
         @returns The coordinates of the neck. */
        const Coordinate2D & getNeck(void)
        const
        {
            return _neck;
        } // getNeck
        
        /*! @brief Return the coordinates of the right elbow.
         @returns The coordinates of the right elbow. */
        const Coordinate2D & getRightElbow(void)
        const
        {
            return _rightElbow;
        } // getRightElbow
        
        /*! @brief Return the angle from the right elbow to the right wrist.
         @returns The angle from the right elbow to the right wrist. */
        realType getRightElbowToWristAngle(void)
        const
        {
            return _rightElbowToWristAngle;
        } // getRightElbowToWristAngle
        
        /*! @brief Return the quadrant of the angle from the right elbow to the right wrist.
         @returns The quadrant of the angle from the right elbow to the right wrist. */
        int getRightElbowToWristQuadrant(void)
        const
        {
            return _rightElbowToWristQuadrant;
        } // getRightElbowToWristQuadrant
        
        /*! @brief Return the coordinates of the right foot.
         @returns The coordinates of the right foot. */
        const Coordinate2D & getRightFoot(void)
        const
        {
            return _rightFoot;
        } // getRightFoot
        
        /*! @brief Return the coordinates of the right side of the hips.
         @returns The coordinates of the right side of the hips. */
        const Coordinate2D & getRightHip(void)
        const
        {
            return _rightHip;
        } // getRightHip
        
        /*! @brief Return the angle from the right side of the hips to the right knee.
         @returns The angle from the right side of the hips to the right knee. */
        realType getRightHipToKneeAngle(void)
        const
        {
            return _rightHipToKneeAngle;
        } // getRightHipToKneeAngle
        
        /*! @brief Return the quadrant of the angle from the right side of the hips to the right
         knee.
         @returns The quadrant of the angle from the right side of the hips to the right knee. */
        int getRightHipToKneeQuadrant(void)
        const
        {
            return _rightHipToKneeQuadrant;
        } // getRightHipToKneeQuadrant
        
        /*! @brief Return the coordinates of the right knee.
         @returns The coordinates of the right knee. */
        const Coordinate2D & getRightKnee(void)
        const
        {
            return _rightKnee;
        } // getRightKnee
        
        /*! @brief Return the angle from the right knee to the right foot.
         @returns The angle from the right knee to the right foot. */
        realType getRightKneeToFootAngle(void)
        const
        {
            return _rightElbowToWristAngle;
        } // getRightKneeToFootAngle
        
        /*! @brief Return the quadrant of the angle from the right knee to the right foot.
         @returns The quadrant of the angle from the right knee to the right foot. */
        int getRightKneeToFootQuadrant(void)
        const
        {
            return _rightKneeToFootQuadrant;
        } // getRightKneeToFootQuadrant
        
        /*! @brief Return the coordinates of the right shoulder.
         @returns The coordinates of the right shoulder. */
        const Coordinate2D & getRightShoulder(void)
        const
        {
            return _rightShoulder;
        } // getRightShoulder
        
        /*! @brief Return the angle from the right shoulder to the right elbow.
         @returns The angle from the right shoulder to the right elbow. */
        realType getRightShoulderToElbowAngle(void)
        const
        {
            return _rightShoulderToElbowAngle;
        } // getRightShoulderToElbowAngle
        
        /*! @brief Return the quadrant of the angle from the right shoulder to the right elbow.
         @returns The quadrant of the angle from the right shoulder to the right elbow. */
        int getRightShoulderToElbowQuadrant(void)
        const
        {
            return _rightShoulderToElbowQuadrant;
        } // getRightShoulderToElbowQuadrant
        
        /*! @brief Return the coordinates of the right wrist.
         @returns The coordinates of the right wrist. */
        const Coordinate2D & getRightWrist(void)
        const
        {
            return _rightWrist;
        } // getRightWrist
        
        /*! @brief Return the Space Quality.
         @returns The Space Quality value. */
        SpaceQuality getSpace(void)
        const
        {
            return _space;
        } // getSpace
        
        /*! @brief Return the coordinates of the 'tail'.
         @returns The coordinates of the 'tail'. */
        const Coordinate2D & getTail(void)
        const
        {
            return _tail;
        } // getTail
        
        /*! @brief Return the Time Quality.
         @returns The Time Quality value. */
        TimeQuality getTime(void)
        const
        {
            return _time;
        } // getTime
        
        /*! @brief Return the Weight Quality.
         @returns The Weight Quality value. */
        WeightQuality getWeight(void)
        const
        {
            return _weight;
        } // getWeight
        
        /*! @brief Return @c true if the object is marked.
         @returns @c true if the object is marked. */
        bool isMarked(void)
        const
        {
            return _marked;
        } // isMarked
        
        /*! @brief Mutate a value of the object. */
        void mutate(void);
        
        /*! @brief Mark the object. */
        void setMark(void)
        {
            _marked = true;
        } // setMark
        
        /*! @brief Choose a set of values and swap with another Body.
         @param other The other Body to be modified.
         @param numSwap The number of values to be exchanged. */
        void swapValues(Body &       other,
                        const size_t numSwap);
        
        /*! @brief Determine the fitness value for this object. */
        void updateFitness(void);
        
    protected :
    
    private :
        
        /*! @brief The constructor. */
        Body(void);
        
        /*! @brief Set the attributes to random values. */
        void setAttributes(void);
        
        /*! @brief Set the joint positions from the angles. */
        void setPositions(void);
        
    public :
    
    protected :
    
    private :
        
        /*! @brief The initial position of the left side of the hips. */
        Coordinate2D _initLeftHip;

        /*! @brief The initial position of the left shoulder. */
        Coordinate2D _initLeftShoulder;
        
        /*! @brief The initial position of the right side of the hips. */
        Coordinate2D _initRightHip;
        
        /*! @brief The initial position of the right shoulder. */
        Coordinate2D _initRightShoulder;
        
        /*! @brief The position of the left elbow. */
        Coordinate2D _leftElbow;
        
        /*! @brief The position of the left foot. */
        Coordinate2D _leftFoot;
        
        /*! @brief The position of the left side of the hips. */
        Coordinate2D _leftHip;
        
        /*! @brief The position of the left knee. */
        Coordinate2D _leftKnee;
        
        /*! @brief The position of the left shoulder. */
        Coordinate2D _leftShoulder;
        
        /*! @brief The position of the left wrist. */
        Coordinate2D _leftWrist;
        
        /*! @brief The position of the neck. */
        Coordinate2D _neck;
        
        /*! @brief The position of the right elbow. */
        Coordinate2D _rightElbow;
        
        /*! @brief The position of the right foot. */
        Coordinate2D _rightFoot;
        
        /*! @brief The position of the right side of the hips. */
        Coordinate2D _rightHip;
        
        /*! @brief The position of the right knee. */
        Coordinate2D _rightKnee;
        
        /*! @brief The position of the right shoulder. */
        Coordinate2D _rightShoulder;
        
        /*! @brief The position of the right wrist. */
        Coordinate2D _rightWrist;
        
        /*! @brief The position of the 'tail'. */
        Coordinate2D _tail;
        
        /*! @brief The quadrant of the angle from the left elbow to the left wrist. */
        int _leftElbowToWristQuadrant;
        
        /*! @brief The quadrant of the angle from the left side of the hips to the left knee. */
        int _leftHipToKneeQuadrant;
        
        /*! @brief The quadrant of the angle from the left knee to the left foot. */
        int _leftKneeToFootQuadrant;
        
        /*! @brief The quadrant of the angle from the left shoulder to the left elbow. */
        int _leftShoulderToElbowQuadrant;
        
        /*! @brief The score contribution from the quadrants. */
        int _quadrantScore;
        
        /*! @brief The quadrant of the angle from the right elbow to the right wrist. */
        int _rightElbowToWristQuadrant;
        
        /*! @brief The quadrant of the angle from the right side of the hips to the right knee. */
        int _rightHipToKneeQuadrant;
        
        /*! @brief The quadrant of the angle from the right knee to the right foot. */
        int _rightKneeToFootQuadrant;
        
        /*! @brief The quadrant of the angle from the right shoulder to the right elbow. */
        int _rightShoulderToElbowQuadrant;
        
        /*! @brief The calculated fitness score. */
        realType _accumulatedScore;
        
        /*! @brief The angle (in radians) from the left elbow to the left wrist. */
        realType _leftElbowToWristAngle;

        /*! @brief The angle (in radians) from the left side of the hips to the left knee. */
        realType _leftHipToKneeAngle;

        /*! @brief The angle (in radians) from the left knee to the left foot. */
        realType _leftKneeToFootAngle;

        /*! @brief The angle (in radians) from the left shoulder to the left elbow. */
        realType _leftShoulderToElbowAngle;
        
        /*! @brief The angle (in radians) from the right elbow to the right wrist. */
        realType _rightElbowToWristAngle;
        
        /*! @brief The angle (in radians) from the right side of the hips to the right knee. */
        realType _rightHipToKneeAngle;
        
        /*! @brief The angle (in radians) from the right knee to the right foot. */
        realType _rightKneeToFootAngle;
        
        /*! @brief The angle (in radians) from the right shoulder to the right elbow. */
        realType _rightShoulderToElbowAngle;

        /*! @brief The Flow Effort Quality value. */
        FlowQuality _flow;
        
        /*! @brief The height level. */
        HeightValue _height;
        
        /*! @brief The Space Effort Quality value. */
        SpaceQuality _space;
        
        /*! @brief The Time Effort Quality value. */
        TimeQuality _time;
        
        /*! @brief The Weight Effort Quality value. */
        WeightQuality _weight;
        
        /*! @brief @c true if the object has been marked and @c false otherwise. */
        bool _marked;
        
    }; // Body
    
} // Scuddle

#endif /* ! defined(Scuddle_Body_H_) */
