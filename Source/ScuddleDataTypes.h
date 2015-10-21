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

# if (! defined(MAC_OR_LINUX_))
/*! @brief @c TRUE if non-Windows, @c FALSE if Windows. */
#  define MAC_OR_LINUX_ (defined(__APPLE__) || defined(__linux__))
# endif // ! defined(MAC_OR_LINUX_)

# define USE_SKELETON_ /* Use Skeleton rather than Body. */
//# define GENERATE_POSITIONS_ /* Generate coordinates as well as angles. */
//# define USE_FRACTION_FOR_CROSSOVER_ /* Use a fraction for crossovers. */

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
    typedef float realType;

# if (! defined(USE_SKELETON_))
#  if defined(GENERATE_POSITIONS_)
    /*! @brief The two-dimensional coordinate data type. */
    typedef std::complex<realType> Coordinate2D;
#  endif // defined(GENERATE_POSITIONS_)
# endif // ! defined(USE_SKELETON_)

    /*! @brief The generalized constrained value class template. */
    template<typename Type> class ConstrainedValue
    {
    public :
        /*! @brief The constructor.
         @param minValue The lowest acceptable value.
         @param maxValue The highest acceptable value.
         @param defaultValue The initial (default) value which is also the 'reset' value. */
        ConstrainedValue(const Type minValue,
                         const Type maxValue,
                         const Type defaultValue) :
            _defaultValue(defaultValue), _maxValue(maxValue), _minValue(minValue)
        {
            if (minValue >= maxValue)
            {
                throw 42;
            }
            
            setValue(_defaultValue);
        } // ContrainedValue
        
        /*! @brief Return the range of acceptable values.
         @param minValue The lowest acceptable value.
         @param maxValue The highest acceptable value. */
        inline void getRange(Type & minValue,
                             Type & maxValue)
        const
        {
            minValue = _minValue;
            maxValue = _maxValue;
        } // getRange
        
        /*! @brief Return the current value.
         @returns The current value. */
        inline Type getValue(void)
        const
        {
            return _currentValue;
        } // getValue
        
        /*! @brief Sets the current value to the default value. */
        inline void resetValue(void)
        {
            setValue(_defaultValue);
        } // resetValue
        
        /*! @brief Sets the current value to a value in the range of acceptable values.
         @param newValue The value to be used. */
        void setValue(const Type newValue)
        {
            _currentValue = ((_minValue > newValue) ? _minValue :
                             ((_maxValue < newValue) ? _maxValue : newValue));
        } // setValue
        
    protected :
        
    private :
        
    public :
        
    protected :
        
    private :
        
        /*! @brief The current value. */
        Type _currentValue;
        
        /*! @brief The default value. */
        Type _defaultValue;
        
        /*! @brief The highest acceptable value. */
        Type _maxValue;
        
        /*! @brief The lowest acceptable value. */
        Type _minValue;
        
    }; // ConstrainedValue
    
    /*! @brief The constrained real value type. */
    typedef ConstrainedValue<realType> ConstrainedRealValue;
    
    /*! @brief The constrained unsigned value type. */
    typedef ConstrainedValue<size_t> ConstrainedUnsignedValue;
    
} // Scuddle

#endif // ! defined(Scuddle_DataTypes_H_)
