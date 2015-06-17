//--------------------------------------------------------------------------------------------------
//
//  File:       ScuddleDataTypes.h
//
//  Project:    Scuddle
//
//  Contains:   The common type definitions for Scuddle.
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

#if (! defined(Scuddle_DataTypes_H_))
# define Scuddle_DataTypes_H_ /* Header guard */

# include <complex>

namespace Scuddle
{
    /*! @brief Flow Effort Qualities. */
    enum FlowQuality
    {
        /*! @brief 'Free' flow. */
        kFlowFree,
        
        /*! @brief 'Bound' flow. */
        kFlowBound
        
    }; // FlowQuality
    
    /*! @brief Height values. */
    enum HeightValue
    {
        /*! @brief 'Low' height. */
        kHeightLow,
        
        /*! @brief 'Mid-Low' height. */
        kHeightMidLow,
        
        /*! @brief 'Middle' height. */
        kHeightMiddle,
        
        /*! @brief 'Mid-High' height. */
        kHeightMidHigh,
        
        /*! @brief 'High' height. */
        kHeightHigh
        
    }; // HeightValue
    
    /*! @brief Space Effort Qualities. */
    enum SpaceQuality
    {
        /*! @brief 'Indirect' space. */
        kSpaceIndirect,
        
        /*! @brief 'Direct' space. */
        kSpaceDirect
        
    }; // SpaceQuality
    
    /*! @brief Time Effort Qualities. */
    enum TimeQuality
    {
        /*! @brief 'Sustained' time. */
        kTimeSustained,
        
        /*! @brief 'Sudden' time. */
        kTimeSudden
        
    }; // TimeQuality
    
    /*! @brief Weight Effort Qualities. */
    enum WeightQuality
    {
        /*! @brief 'Light' weight. */
        kWeightLight,
        
        /*! @brief 'Strong' weight. */
        kWeightStrong
        
    }; // WeightQuality
    
    /*! @brief The floating-point data type to use. */
    typedef double realType;
    
    /*! @brief The two-dimensional coordinate data type. */
    typedef std::complex<realType> Coordinate2D;
    
} // Scuddle

#endif // ! defined(Scuddle_DataTypes_H_)
