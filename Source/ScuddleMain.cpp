//--------------------------------------------------------------------------------------------------
//
//  File:       ScuddleMain.cpp
//
//  Project:    Scuddle
//
//  Contains:   The main application for Scuddle.
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
#include "ScuddleSkeleton.h"

#include <iostream>
#if MAC_OR_LINUX_
# include <sys/time.h>
#else // ! MAC_OR_LINUX_
# include <sys/timeb.h>
#endif // ! MAC_OR_LINUX_

#if defined(__APPLE__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunknown-pragmas"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#endif // defined(__APPLE__)
/*! @file
 @brief The main application for Scuddle. */
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

#define PRINT_VALUES_ /* Print out values of interest. */

#if defined(USE_SKELETON_)
/*! @brief A sequence of Skeleton objects. */
typedef std::vector<Skeleton *> SkeletonVector;
#else // ! defined(USE_SKELETON_)
/*! @brief A sequence of Body objects. */
typedef std::vector<Body *> BodyVector;
#endif // ! defined(USE_SKELETON_)

#if defined(USE_SKELETON_)
/*! @brief A sequence of indices of Skeleton objects. */
typedef std::vector<int> IndexVector;
#endif // defined(USE_SKELETON_)

#if defined(GENERATE_POSITIONS_)
/*! @brief The initial position of the left side of the hips for new Body objects. */
static const Coordinate2D kLeftHip(120, 220);
#endif // defined(GENERATE_POSITIONS_)

#if defined(GENERATE_POSITIONS_)
/*! @brief The initial position of the left shoulder for new Body objects. */
static const Coordinate2D kLeftShoulder(110, 100);
#endif // defined(GENERATE_POSITIONS_)

#if defined(GENERATE_POSITIONS_)
/*! @brief The initial position of the neck for new Body objects. */
static const Coordinate2D kNeck(155, 110);
#endif // defined(GENERATE_POSITIONS_)

#if defined(GENERATE_POSITIONS_)
/*! @brief The initial position of the right side of the hips for new Body objects. */
static const Coordinate2D kRightHip(190, 220);
#endif // defined(GENERATE_POSITIONS_)

#if defined(GENERATE_POSITIONS_)
/*! @brief The initial position of the right shoulder for new Body objects. */
static const Coordinate2D kRightShoulder(200, 100);
#endif // defined(GENERATE_POSITIONS_)

#if defined(GENERATE_POSITIONS_)
/*! @brief The initial position of the 'tail' for new Body objects. */
static const Coordinate2D kTail(155, 210);
#endif // defined(GENERATE_POSITIONS_)

/*! @brief The number of selections to present when finished. */
static const int kFinalSelectionSize = 5;

/*! @brief The number of iterations to perform. */
static const int kIterationCount = 5;

/*! @brief The fraction of the set of Body objects that are to be mutated. */
static const realType kMutationFraction = static_cast<realType>(0.10);

/*! @brief The fraction of the set of Body objects that are selected. */
static const realType kSelectionFraction = static_cast<realType>(0.20);

#if (! defined(CROSSOVER_FRACTION_))
/*! @brief The number of attributes to swap. */
static const size_t kCrossoverCount = 2;
#endif // ! defined(CROSSOVER_FRACTION_)

#if defined(USE_SKELETON_)
/*! @brief The number of angles in each Skeleton. */
static const size_t kNumDisplayedAngles = 31;
#endif // defined(USE_SKELETON_)

#if defined(USE_SKELETON_)
static const size_t kNumQuaternionsPerRow = 3;
#endif // defined(USE_SKELETON_)

/*! @brief The number of Body objects to generate. */
static const size_t kPopulationSize = 200; // MUST BE EVEN!!!

#if defined(USE_SKELETON_)
static SkeletonVector * lPopulation = nullptr;
#else // ! defined(USE_SKELETON_)
/*! @brief The set of Body objects that are worked on. */
static BodyVector * lPopulation = nullptr;
#endif // ! defined(USE_SKELETON_)

#if defined(USE_SKELETON_)
/*! @brief The set of Skeleton objects that have been selected. */
static SkeletonVector * lSelection = nullptr;
#else // ! defined(USE_SKELETON_)
/*! @brief The set of Body objects that have been selected. */
static BodyVector * lSelection = nullptr;
#endif // ! defined(USE_SKELETON_)

#if defined(USE_SKELETON_)
static IndexVector * lIndices = nullptr;
#endif // ! defined(USE_SKELETON_)

#if defined(__APPLE__)
# pragma mark Global constants and variables
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Local functions
#endif // defined(__APPLE__)

static double getMillisecondsSinceEpoch(void)
{
    double result;
#if MAC_OR_LINUX_
    struct timeval tv;
#else // ! MAC_OR_LINUX_
    struct _timeb  tt;
#endif // ! MAC_OR_LINUX_
    
#if MAC_OR_LINUX_
    gettimeofday(&tv, nullptr);
    result = (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
#else // ! MAC_OR_LINUX_
    _ftime_s(&tt);
    result = (tt.time * 1000.0) + tt.millitm;
#endif // ! MAC_OR_LINUX_
    return result;
} // getMillisecondsSinceEpoch

/*! @brief Update the fitness value for the Body objects. */
static void calculateFitnessValues(void)
{
#if defined(PRINT_VALUES_)
    std::cout << "Calculating fitness." << std::endl;
#endif // defined(PRINT_VALUES_)
#if defined(USE_SKELETON_)
    for (SkeletonVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
         ++walker)
    {
        Skeleton * aSkeleton = *walker;
        
        if (aSkeleton)
        {
            aSkeleton->updateFitness();
        }
    }
#else // ! defined(USE_SKELETON_)
    for (BodyVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker; ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            aBody->updateFitness();
        }
    }
#endif // ! defined(USE_SKELETON_)
} // calculateFitnessValues

/*! @brief Release the objects that were created earlier. */
static void cleanup(void)
{
#if defined(PRINT_VALUES_)
    std::cout << "Cleaning up." << std::endl;
#endif // defined(PRINT_VALUES_)
#if defined(USE_SKELETON_)
    for (SkeletonVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
         ++walker)
    {
        Skeleton * aSkeleton = *walker;
        
        if (aSkeleton)
        {
            delete aSkeleton;
        }
    }
#else // ! defined(USE_SKELETON_)
    for (BodyVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker; ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            delete aBody;
        }
    }
#endif // ! defined(USE_SKELETON_)
    lPopulation->clear();
    lSelection->clear();
    delete lPopulation;
    lPopulation = nullptr;
    delete lSelection;
    lSelection = nullptr;
#if defined(USE_SKELETON_)
    delete lIndices;
    lIndices = nullptr;
#endif // defined(USE_SKELETON_)
} // cleanup

#if defined(USE_SKELETON_)
/*! @brief Generate the mapping information for the quaternion outputs. */
static void createMapForAngles(void)
{
    // DANGER!! DANGER!!
    // Changing the CMU skeleton structure will break this!
    for (size_t ii = 0; kNumDisplayedAngles > ii; ++ii)
    {
        int dispIndex;
        
        switch (ii)
        {
            case 2 :
                dispIndex = Skeleton::kLeftHipToKnee;
                break;
                
            case 3 :
                dispIndex = Skeleton::kLeftKneeToFoot;
                break;
                
            case 8 :
                dispIndex = Skeleton::kRightHipToKnee;
                break;
                
            case 9 :
                dispIndex = Skeleton::kRightKneeToFoot;
                break;
                
            case 21 :
                dispIndex = Skeleton::kLeftShoulderToElbow;
                break;
                
            case 22 :
                dispIndex = Skeleton::kLeftElbowToWrist;
                break;
                
            case 30 :
                dispIndex = Skeleton::kRightShoulderToElbow;
                break;
                
            case 31 :
                dispIndex = Skeleton::kRightElbowToWrist;
                break;
                
            default :
                dispIndex = -1;
                break;
                
        }
        lIndices->push_back(dispIndex);
    }
} // createMapForAngles
#endif // defined(USE_SKELETON_)

#if defined(USE_SKELETON_)
/*! @brief Print the parameters of a Skeleton object.
 @param aSkeleton The Skeleton object to be printed. */
static void printSkeleton(Skeleton & aSkeleton)
{
    for (size_t ii = 0, imax = lIndices->size(), jj = 0; imax > ii; ++ii, ++jj)
    {
        int       dispIndex = (*lIndices)[ii];
        glm::quat aQuat;
        
        if (0 <= dispIndex)
        {
            aQuat = aSkeleton.getAngleAsQuaternion(static_cast<size_t>(dispIndex));
        }
        else
        {
            aQuat = glm::quat_cast(glm::rotate(glm::mat4(1), static_cast<realType>(0),
                                               glm::vec3(0, 0, 1)));
        }
        if (0 < ii)
        {
            if (kNumQuaternionsPerRow <= jj)
            {
                std::cout << "," << std::endl << " ";
                jj = 0;
            }
            else
            {
                std::cout << ", ";
            }
        }
        else
        {
            std::cout << " ";
        }
        std::cout << "[" << aQuat.x << "," << aQuat.y << "," << aQuat.z << aQuat.w << "," << "]";
    }
    std::cout << std::endl;
} // printSkeleton
#else // ! defined(USE_SKELETON_)
/*! @brief Print the parameters of a Body object.
 @param aBody The Body object to be printed. */
static void printBody(Body & aBody)
{
    std::cout << RadiansToDegrees(aBody.getLeftShoulderToElbowAngle()) << "," <<
                RadiansToDegrees(aBody.getLeftElbowToWristAngle()) << "," <<
                RadiansToDegrees(aBody.getRightShoulderToElbowAngle()) << "," <<
                RadiansToDegrees(aBody.getRightElbowToWristAngle()) << "," <<
                RadiansToDegrees(aBody.getLeftHipToKneeAngle()) << "," <<
                RadiansToDegrees(aBody.getLeftKneeToFootAngle()) << "," <<
                RadiansToDegrees(aBody.getRightHipToKneeAngle()) << "," <<
                RadiansToDegrees(aBody.getRightKneeToFootAngle()) << "," <<
                MapWeightToReal(aBody.getWeight()) << "," << MapSpaceToReal(aBody.getSpace()) <<
                "," << MapTimeToReal(aBody.getTime()) << "," << MapFlowToReal(aBody.getFlow()) <<
                std::endl;
} // printBody
#endif // ! defined(USE_SKELETON_)

#if defined(USE_SKELETON_)
/*! @brief Create a set of Skeleton objects to work with.
 @param numSkeletons The number of Skeleton objects to create. */
static void generateSkeletons(const size_t numSkeletons)
{
# if defined(PRINT_VALUES_)
    std::cout << "Generating " << numSkeletons << " objects." << std::endl;
# endif // defined(PRINT_VALUES_)
    for (size_t ii = 0; numSkeletons > ii; ++ii)
    {
        Skeleton * aSkeleton = new Skeleton;
        
        lPopulation->push_back(aSkeleton);
# if defined(PRINT_VALUES_)
        if (0 < lIndices->size())
        {
            if (0 < ii)
            {
                std::cout << std::endl;
            }
            printSkeleton(*aSkeleton);
        }
# endif // defined(PRINT_VALUES_)
    }
} // generateSkeletons
#else // ! defined(USE_SKELETON_)
/*! @brief Create a set of Body objects to work with.
 @param numBodies The number of Body objects to create. */
static void generateBodies(const size_t numBodies)
{
# if defined(PRINT_VALUES_)
    std::cout << "Generating " << numBodies << " objects." << std::endl;
# endif // defined(PRINT_VALUES_)
    for (size_t ii = 0; numBodies > ii; ++ii)
    {
# if defined(GENERATE_POSITIONS_)
        Body * aBody = new Body(kLeftHip, kLeftShoulder, kNeck, kRightHip, kRightShoulder, kTail);
# else // ! defined(GENERATE_POSITIONS_)
        Body * aBody = new Body;
# endif // ! defined(GENERATE_POSITIONS_)
        
        lPopulation->push_back(aBody);
# if defined(PRINT_VALUES_)
        printBody(*aBody);
# endif // defined(PRINT_VALUES_)
    }
} // generateBodies
#endif // ! defined(USE_SKELETON_)

/*! @brief Make the selections for this iteration. */
static void makeSelection(void)
{
#if defined(PRINT_VALUES_)
    std::cout << "Making selection." << std::endl;
#endif // defined(PRINT_VALUES_)
    realType sumOfScore = 0;
    
#if defined(USE_SKELETON_)
    for (SkeletonVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
         ++walker)
    {
        Skeleton * aSkeleton = *walker;
        
        if (aSkeleton)
        {
            sumOfScore += aSkeleton->getFitnessScore();
        }
    }
#else // ! defined(USE_SKELETON_)
    for (BodyVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker; ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            sumOfScore += aBody->getFitnessScore();
        }
    }
#endif // ! defined(USE_SKELETON_)
    lSelection->clear();
    for (size_t ii = 0, imax = static_cast<size_t>(lPopulation->size() * kSelectionFraction);
         imax > ii; )
    {
        realType sumOfArrayIndices = 0;
        realType chooseArray = RandRealInRange(0, sumOfScore);
        
#if defined(USE_SKELETON_)
        for (SkeletonVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
             ++walker)
        {
            Skeleton * aSkeleton = *walker;
            
            if (aSkeleton && (! aSkeleton->isMarked()))
            {
                realType score = aSkeleton->getFitnessScore();
                
                if ((chooseArray > sumOfArrayIndices) &&
                    (chooseArray < (sumOfArrayIndices + score)))
                {
                    aSkeleton->setMark();
                    sumOfArrayIndices += score;
                    lSelection->push_back(aSkeleton);
                    ++ii;
                }
                else
                {
                    sumOfArrayIndices += score;
                }
            }
        }
#else // ! defined(USE_SKELETON_)
        for (BodyVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
             ++walker)
        {
            Body * aBody = *walker;
            
            if (aBody && (! aBody->isMarked()))
            {
                realType score = aBody->getFitnessScore();
                
                if ((chooseArray > sumOfArrayIndices) &&
                    (chooseArray < (sumOfArrayIndices + score)))
                {
                    aBody->setMark();
                    sumOfArrayIndices += score;
                    lSelection->push_back(aBody);
                    ++ii;
                }
                else
                {
                    sumOfArrayIndices += score;
                }
            }
        }
#endif // ! defined(USE_SKELETON_)
    }
} // makeSelection

/*! @brief Generate a new set of objects, using the selected parents. */
#if defined(CROSSOVER_FRACTION_)
static void doCrossovers(const realType crossoverFraction)
#else // ! defined(CROSSOVER_FRACTION_)
static void doCrossovers(const size_t crossoverCount)
#endif // ! defined(CROSSOVER_FRACTION_)
{
#if defined(PRINT_VALUES_)
    std::cout << "Doing crossovers." << std::endl;
#endif // defined(PRINT_VALUES_)
    // We have an initial population, from the previous generation, and we will create two new
    // 'children' for each parent pair.
    // Remove all the objects that are not propagating forward, which are unmarked - the selection
    // vector has pointers to the marked ones.
#if defined(USE_SKELETON_)
    for (SkeletonVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
         ++walker)
    {
        Skeleton * aSkeleton = *walker;
        
        if (aSkeleton && (! aSkeleton->isMarked()))
        {
            delete aSkeleton;
        }
    }
#else // ! defined(USE_SKELETON_)
    for (BodyVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
         ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody && (! aBody->isMarked()))
        {
            delete aBody;
        }
    }
#endif // ! defined(USE_SKELETON_)
    *lPopulation = *lSelection;
    // Clear the marks!
#if defined(USE_SKELETON_)
    for (SkeletonVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
         ++walker)
    {
        Skeleton * aSkeleton = *walker;
        
        if (aSkeleton)
        {
            aSkeleton->clearMark();
        }
    }
#else // ! defined(USE_SKELETON_)
    for (BodyVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
         ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            aBody->clearMark();
        }
    }
#endif // ! defined(USE_SKELETON_)
    for (bool keepGoing = true; keepGoing; )
    {
        // Pick two 'parent' objects:
        size_t popSize = lPopulation->size();
        size_t firstChoice = RandUnsignedInRange(popSize - 1);
        size_t secondChoice;
        
        for ( ; ; )
        {
            secondChoice = RandUnsignedInRange(popSize - 1);
            if (firstChoice != secondChoice)
            {
                break;
            }
            
        }
#if defined(USE_SKELETON_)
        Skeleton * firstParent = (*lPopulation)[firstChoice];
        Skeleton * secondParent = (*lPopulation)[secondChoice];
#else // ! defined(USE_SKELETON_)
        Body *     firstParent = (*lPopulation)[firstChoice];
        Body *     secondParent = (*lPopulation)[secondChoice];
#endif // ! defined(USE_SKELETON_)
        
        if (firstParent && secondParent)
        {
#if defined(USE_SKELETON_)
            Skeleton * firstChild = new Skeleton(*firstParent);
            Skeleton * secondChild = new Skeleton(*secondParent);
#else // ! defined(USE_SKELETON_)
            Body *     firstChild = new Body(*firstParent);
            Body *     secondChild = new Body(*secondParent);
#endif // ! defined(USE_SKELETON_)
            
            // Crossover attributes:
            lPopulation->push_back(firstChild);
            lPopulation->push_back(secondChild);
#if defined(CROSSOVER_FRACTION_)
            firstChild->swapValues(*secondChild, crossoverFraction);
#else // ! defined(CROSSOVER_FRACTION_)
            firstChild->swapValues(*secondChild, crossoverCount);
#endif // ! defined(CROSSOVER_FRACTION_)
            if (kPopulationSize <= lPopulation->size())
            {
                keepGoing = false;
            }
        }
    }
} // doCrossovers

/*! @brief Mutate some of the objects. */
static void doMutations(const realType mutationFraction)
{
#if defined(PRINT_VALUES_)
    std::cout << "Doing mutations." << std::endl;
#endif // defined(PRINT_VALUES_)
    // Mark the objects to be mutated:
    for (size_t ii = 0, jmax = lPopulation->size(),
         imax = static_cast<size_t>(mutationFraction * jmax); imax > ii;)
    {
        size_t jj = RandUnsignedInRange(jmax - 1);
#if defined(USE_SKELETON_)
        Skeleton * aSkeleton = (*lPopulation)[jj];
#else // ! defined(USE_SKELETON_)
        Body *     aBody = (*lPopulation)[jj];
#endif // ! defined(USE_SKELETON_)
        
#if defined(USE_SKELETON_)
        if (aSkeleton && (! aSkeleton->isMarked()))
        {
            aSkeleton->setMark();
            ++ii;
        }
#else // ! defined(USE_SKELETON_)
        if (aBody && (! aBody->isMarked()))
        {
            aBody->setMark();
            ++ii;
        }
#endif // ! defined(USE_SKELETON_)
    }
#if defined(USE_SKELETON_)
    for (SkeletonVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
         ++walker)
    {
        Skeleton * aSkeleton = *walker;
        
        if (aSkeleton && aSkeleton->isMarked())
        {
            aSkeleton->mutate();
            aSkeleton->clearMark();
        }
    }
#else // ! defined(USE_SKELETON_)
    for (BodyVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker; ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody && aBody->isMarked())
        {
            aBody->mutate();
            aBody->clearMark();
        }
    }
#endif // ! defined(USE_SKELETON_)
} // doMutations

/*! @brief Make the final selections. */
static void makeFinalSelection(const size_t selectionSize)
{
#if defined(PRINT_VALUES_)
    std::cout << "Making final selection." << std::endl;
#endif // defined(PRINT_VALUES_)
    realType sumOfScore = 0;
    
#if defined(USE_SKELETON_)
    for (SkeletonVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
         ++walker)
    {
        Skeleton * aSkeleton = *walker;
        
        if (aSkeleton)
        {
            sumOfScore += aSkeleton->getFitnessScore();
        }
    }
#else // ! defined(USE_SKELETON_)
    for (BodyVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
         ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            sumOfScore += aBody->getFitnessScore();
        }
    }
#endif // ! defined(USE_SKELETON_)
    lSelection->clear();
    lSelection->resize(selectionSize);
    for (size_t ii = 0, imax = selectionSize; imax > ii; )
    {
        realType sumOfArrayIndices = 0;
        realType chooseArray = RandRealInRange(0, sumOfScore);
        
#if defined(USE_SKELETON_)
        for (SkeletonVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
             ++walker)
        {
            Skeleton * aSkeleton = *walker;
            
            if (aSkeleton)
            {
                realType score = aSkeleton->getFitnessScore();
                
                if ((chooseArray > sumOfArrayIndices) &&
                    (chooseArray < (sumOfArrayIndices + score)))
                {
                    sumOfArrayIndices += score;
                    (*lSelection)[ii] = aSkeleton;
                    ++ii;
                }
                else
                {
                    sumOfArrayIndices += score;
                }
            }
        }
#else // ! defined(USE_SKELETON_)
        for (BodyVector::iterator walker(lPopulation->begin()); lPopulation->end() != walker;
             ++walker)
        {
            Body * aBody = *walker;
            
            if (aBody)
            {
                realType score = aBody->getFitnessScore();
                
                if ((chooseArray > sumOfArrayIndices) &&
                    (chooseArray < (sumOfArrayIndices + score)))
                {
                    sumOfArrayIndices += score;
                    (*lSelection)[ii] = aBody;
                    ++ii;
                }
                else
                {
                    sumOfArrayIndices += score;
                }
            }
        }
#endif // ! defined(USE_SKELETON_)
    }
} // makeFinalSelection

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

/*! @brief The entry point for calculating the movement parameter vectors.
 
 Standard output will receive a list of the movement parameter vectors.
 @param argc The number of arguments in 'argv'.
 @param argv The arguments to be used with the application.
 @returns @c 0 on a successful test and @c 1 on failure. */
#if (! defined(__APPLE__))
# pragma warning(push)
# pragma warning(disable: 4100)
#endif // ! defined(__APPLE__)
int main(int            argc,
         const char * * argv)
{
#if defined(__APPLE__)
# pragma unused(argc, argv)
#endif // defined(__APPLE__)
    double timeBeforeFitness;
    double timeBeforeSelection;
    double timeBeforeCrossovers;
    double timeBeforeMutations;
    double timeBeforeFinalSelection;
    double timeAfterFinalSelection;
    double timeAfterMutations;
    double fitnessTime = 0;
    double selectionTime = 0;
    double crossoverTime = 0;
    double mutationTime = 0;
    double iterationTime = 0;
    double finalSelectionTime;
    
#if defined(USE_SKELETON_)
    lPopulation = new SkeletonVector;
    lSelection = new SkeletonVector;
    lIndices = new IndexVector;
    generateSkeletons(kPopulationSize);
    createMapForAngles();
#else // ! defined(USE_SKELETON_)
    lPopulation = new BodyVector;
    lSelection = new BodyVector;
    generateBodies(kPopulationSize);
#endif // ! defined(USE_SKELETON_)
    for (int kk = 0; kIterationCount > kk; ++kk)
    {
        timeBeforeFitness = getMillisecondsSinceEpoch();
        calculateFitnessValues();
        timeBeforeSelection = getMillisecondsSinceEpoch();
        makeSelection();
        timeBeforeCrossovers = getMillisecondsSinceEpoch();
#if defined(CROSSOVER_FRACTION_)
        doCrossovers(CROSSOVER_FRACTION_);
#else // ! defined(CROSSOVER_FRACTION_)
        doCrossovers(kCrossoverCount);
#endif // ! defined(CROSSOVER_FRACTION_)
        timeBeforeMutations = getMillisecondsSinceEpoch();
        doMutations(kMutationFraction);
        timeAfterMutations = getMillisecondsSinceEpoch();
        fitnessTime += (timeBeforeSelection - timeBeforeFitness);
        selectionTime += (timeBeforeCrossovers - timeBeforeSelection);
        crossoverTime += (timeBeforeMutations - timeBeforeCrossovers);
        mutationTime += (timeAfterMutations - timeBeforeMutations);
        iterationTime += (timeAfterMutations - timeBeforeFitness);
    }
    calculateFitnessValues();
    timeBeforeFinalSelection = getMillisecondsSinceEpoch();
    makeFinalSelection(kFinalSelectionSize);
    timeAfterFinalSelection = getMillisecondsSinceEpoch();
#if defined(PRINT_VALUES_)
# if defined(USE_SKELETON_)
    for (SkeletonVector::iterator walker(lSelection->begin()); lSelection->end() != walker;
         ++walker)
    {
        Skeleton * aSkeleton = *walker;
        
        if (aSkeleton)
        {
            std::cout << "Final Selection:" << std::endl;
            printSkeleton(*aSkeleton);
        }
    }
# else // ! defined(USE_SKELETON_)
    for (BodyVector::iterator walker(lSelection->begin()); lSelection->end() != walker;
         ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            std::cout << "Final Selection: ";
            printBody(*aBody);
        }
    }
# endif // ! defined(USE_SKELETON_)
#endif // defined(PRINT_VALUES_)
    finalSelectionTime = (timeAfterFinalSelection - timeBeforeFinalSelection);
    std::cerr << "Final selection time: " << finalSelectionTime << " msec" << std::endl;
    std::cerr << "Fitness time: " << fitnessTime << " (" << (fitnessTime / kIterationCount) <<
                ") msec" << std::endl;
    std::cerr << "Selection time: " << selectionTime << " (" << (selectionTime / kIterationCount) <<
                ") msec" << std::endl;
    std::cerr << "Crossover time: " << crossoverTime << " (" << (crossoverTime / kIterationCount) <<
                ") msec" << std::endl;
    std::cerr << "Mutation time: " << mutationTime << " (" << (mutationTime / kIterationCount) <<
                ") msec" << std::endl;
    std::cerr << "Iteration time: " << iterationTime << " (" << (iterationTime / kIterationCount) <<
                ") msec" << std::endl;
    cleanup();
    return 0;
} // main
#if (! defined(__APPLE__))
# pragma warning(pop)
#endif // ! defined(__APPLE__)
