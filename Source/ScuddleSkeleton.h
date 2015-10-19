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
        
        /*! @brief The constructor. */
        Skeleton(void);
        
        /*! @brief The copy constructor.
         @param other The Skeleton to be copied. */
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
        
        /*! @brief Get the current Bartenieff contralateral fitness parameter.
         @returns The current Bartenieff contralateral fitness parameter. */
        inline static realType getBartenieffContralateral(void)
        {
            return gBartenieffContralateral;
        } // getBartenieffContralateral
        
        /*! @brief Get the current Bartenieff distal fitness parameter.
         @returns The current Bartenieff distal fitness parameter. */
        inline static realType getBartenieffDistal(void)
        {
            return gBartenieffDistal;
        } // getBartenieffDistal
        
        /*! @brief Get the current Bartenieff homolateral fitness parameter.
         @returns The current Bartenieff homolateral fitness parameter. */
        inline static realType getBartenieffHomolateral(void)
        {
            return gBartenieffHomolateral;
        } // getBartenieffHomolateral
        
        /*! @brief Get the current Bartenieff homologous fitness parameter.
         @returns The current Bartenieff homologous fitness parameter. */
        inline static realType getBartenieffHomologous(void)
        {
            return gBartenieffHomologous;
        } // getBartenieffHomologous
        
        /*! @brief Get the current Bartenieff medial fitness parameter.
         @returns The current Bartenieff medial fitness parameter. */
        inline static realType getBartenieffMedial(void)
        {
            return gBartenieffMedial;
        } // getBartenieffMedial
        
        /*! @brief Get the current high Effort fitness parameter.
         @returns The current high Effort fitness parameter. */
        inline static realType getEffortHigh(void)
        {
            return gEffortHigh;
        } // getEffortHigh
        
        /*! @brief Get the current low Effort fitness parameter.
         @returns The current low Effort fitness parameter. */
        inline static realType getEffortLow(void)
        {
            return gEffortLow;
        } // getEffortLow
        
        /*! @brief Get the current medium Effort fitness parameter.
         @returns The current medium Effort fitness parameter. */
        inline static realType getEffortMedium(void)
        {
            return gEffortMedium;
        } // getEffortMedium
        
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
        
        /*! @brief Get the current unextended legs fitness parameter.
         @returns The current unextended legs fitness parameter. */
        inline static realType getUnextendedLegs(void)
        {
            return gUnextendedLegs;
        } // getUnextendedLegs
        
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
        
        /*! @brief Reset the fitness parameters to their initial settings. */
        static void resetParameters(void);
        
        /*! @brief Change the Bartenieff contralateral fitness parameter.
         @param newParameter The new Bartenieff contralateral fitness parameter. */
        static void setBartenieffContralateral(const realType newParameter);
        
        /*! @brief Change the Bartenieff distal fitness parameter.
         @param newParameter The new Bartenieff distal fitness parameter. */
        static void setBartenieffDistal(const realType newParameter);
        
        /*! @brief Change the Bartenieff homolateral fitness parameter.
         @param newParameter The new homolateral contralateral fitness parameter. */
        static void setBartenieffHomolateral(const realType newParameter);
        
        /*! @brief Change the Bartenieff homologous fitness parameter.
         @param newParameter The new Bartenieff homologous fitness parameter. */
        static void setBartenieffHomologous(const realType newParameter);
        
        /*! @brief Change the Bartenieff medial fitness parameter.
         @param newParameter The new Bartenieff medial fitness parameter. */
        static void setBartenieffMedial(const realType newParameter);
        
        /*! @brief Change the high Effort fitness parameter.
         @param newParameter The new high Effort fitness parameter. */
        static void setEffortHigh(const realType newParameter);
        
        /*! @brief Change the low Effort fitness parameter.
         @param newParameter The new low Effort fitness parameter. */
        static void setEffortLow(const realType newParameter);
        
        /*! @brief Change the medium Effort fitness parameter.
         @param newParameter The new medium Effort fitness parameter. */
        static void setEffortMedium(const realType newParameter);
        
        /*! @brief Mark the object. */
        void setMark(void)
        {
            _marked = true;
        } // setMark
        
        /*! @brief Change the unextended legs fitness parameter.
         @param newParameter The new unextended legs fitness parameter. */
        static void setUnextendedLegs(const realType newParameter);
        
# if defined(USE_FRACTION_FOR_CROSSOVER_)
        /*! @brief Choose a set of values and swap with another Body.
         @param other The other Body to be modified.
         @param fraction The fraction of the values to be exchanged. */
        void swapValues(Skeleton &     other,
                        const realType fraction);
# else // ! defined(USE_FRACTION_FOR_CROSSOVER_)
        /*! @brief Choose a set of values and swap with another Body.
         @param other The other Body to be modified.
         @param numSwap The number of values to be exchanged. */
        void swapValues(Skeleton &   other,
                        const size_t numSwap);
# endif // ! defined(USE_FRACTION_FOR_CROSSOVER_)
        
        /*! @brief Determine the fitness value for this object. */
        void updateFitness(void);
        
        protected :
        
        private :
        
        /*! @brief Determine the quadrants for the various angles. */
        void determineQuadrants(void);
        
        /*! @brief Set the attributes to random values.
         @param numAngles The number of angles to be set up. */
        void setAttributes(const size_t numAngles);
        
        public :
        
        /*! @brief The number of angles in each Skeleton. */
        static const size_t kNumCalculatedAngles = 8;
        
        /*! @brief The 'meaning' of the individual angles within the Skeleton object. */
        enum AngleIndices
        {
            /*! @brief The angle from the left side of the hip to the left knee. */
            kLeftHipToKnee,
            
            /*! @brief The angle from the left knee to the left foot. */
            kLeftKneeToFoot,
            
            /*! @brief The angle from the right side of the hip to the right knee. */
            kRightHipToKnee,
            
            /*! @brief The angle from the right knee to the right foot. */
            kRightKneeToFoot,
            
            /*! @brief The angle from the left shoulder to the left elbow. */
            kLeftShoulderToElbow,
            
            /*! @brief The angle from the left elbow to the left wrist. */
            kLeftElbowToWrist,
            
            /*! @brief The angle from the right shoulder to the right elbow. */
            kRightShoulderToElbow,
            
            /*! @brief The angle from the right elbow to the right wrist. */
            kRightElbowToWrist
            
        }; // AngleIndices
        
        protected :
        
        private :
        
        /*! @brief The fitness coefficient for Bartenieff contralateral configurations. */
        static realType gBartenieffContralateral;
        
        /*! @brief The fitness coefficient for Bartenieff distal configurations. */
        static realType gBartenieffDistal;
        
        /*! @brief The fitness coefficient for Bartenieff homolateral configurations. */
        static realType gBartenieffHomolateral;
        
        /*! @brief The fitness coefficient for Bartenieff homologous configurations. */
        static realType gBartenieffHomologous;
        
        /*! @brief The fitness coefficient for Bartenieff medial configurations. */
        static realType gBartenieffMedial;
        
        /*! @brief The fitness coefficient for high Effort configurations. */
        static realType gEffortHigh;
        
        /*! @brief The fitness coefficient for low Effort configurations. */
        static realType gEffortLow;
        
        /*! @brief The fitness coefficient for medium Effort configurations. */
        static realType gEffortMedium;
        
        /*! @brief The fitness coefficient for unextended leg configurations. */
        static realType gUnextendedLegs;
        
        /*! @brief The angles (in radians) to be worked with. */
        std::vector<realType> _angles;
        
        /*! @brief The quadrants corresponding to the angles being worked with. */
        std::vector<int> _quadrants;
        
        /*! @brief The calculated fitness score. */
        realType _accumulatedScore;
        
        /*! @brief The score contribution from the quadrants. */
        int _quadrantScore;
        
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
