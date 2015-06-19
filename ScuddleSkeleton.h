//--------------------------------------------------------------------------------------------------
//
//  File:       ScuddleSkeleton.h
//
//  Project:    Scuddle
//
//  Contains:   The class declaration for Skeleton objects.
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

#if (! defined(Scuddle_Skeleton_H_))
# define Scuddle_Skeleton_H_ /* Header guard */

# include "ScuddleCommon.h"

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wdocumentation"
#  pragma clang diagnostic ignored "-Wshadow"
# endif // defined(__APPLE__)
# include <glm/glm.hpp>
# include <glm/gtc/quaternion.hpp>
# include <glm/gtc/matrix_transform.hpp>
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 @brief The class declaration for Skeleton objects. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

namespace Scuddle
{
    
    /*! @brief The Scuddle Skeleton structure. */
    class Skeleton
    {
    public :
        
        /*! @brief The constructor.
         @param numAngles The number of angles to be processed. */
        Skeleton(const size_t numAngles);
        
        /*! @brief The copy constructor.
         @param other The Body to be copied. */
        Skeleton(const Skeleton & other);
        
        /*! @brief The destructor. */
        virtual ~Skeleton(void);
        
        /*! @brief Unmark the object. */
        void clearMark(void)
        {
            _marked = false;
        } // clearMark
        
        /*! @brief Return a specific angle (in degrees).
         @param index The index of the angle to be returned.
         @returns The specified angle, in degrees. */
        realType getAngleAsDegrees(const size_t index)
        const;
        
        /*! @brief Return a specific angle as a quaternion.
         @param index The index of the angle to be returned.
         @returns The specified angle as a quaternion. */
        glm::quat getAngleAsQuaternion(const size_t index)
        const;

        /*! @brief Return the calculated fitness score.
         @returns The calculated fitness score. */
        realType getFitnessScore(void)
        const
        {
            return _accumulatedScore;
        } // getFitnessScore
        
        /*! @brief Return the Flow Quality.
         @returns The Flow Quality value. */
        FlowQuality getFlow(void)
        const
        {
            return _flow;
        } // getFlow
        
        /*! @brief Return the Height level.
         @returns The Height level value. */
        HeightValue getHeight(void)
        const
        {
            return _height;
        } // getHeight
        
        /*! @brief Return the number of angles.
         @returns The number of angles. */
        size_t getNumAngles(void)
        const;
        
        /*! @brief Return the Space Quality.
         @returns The Space Quality value. */
        SpaceQuality getSpace(void)
        const
        {
            return _space;
        } // getSpace
        
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
        void swapValues(Skeleton &   other,
                        const size_t numSwap);
        
        /*! @brief Determine the fitness value for this object. */
        void updateFitness(void);
        
    protected :
    
    private :
        
        /*! @brief The constructor. */
        Skeleton(void);
        
        /*! @brief Set the attributes to random values.
         @param numAngles The number of angles to be set up. */
        void setAttributes(const size_t numAngles);
        
    public :
    
    protected :
    
    private :
        
        /*! @brief The calculated fitness score. */
        realType _accumulatedScore;
        
        /*! @brief The angles (in radians) to be worked with. */
        std::vector<realType> _angles;

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
        
    }; // Skeleton
    
} // Scuddle

#endif /* ! defined(Scuddle_Skeleton_H_) */
