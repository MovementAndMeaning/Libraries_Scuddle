//--------------------------------------------------------------------------------------------------
//
//  File:       ScuddleBody.cpp
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

#include <iostream>
#include <vector>

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

typedef std::vector<Body *> BodyVector;

/*! @brief The initial position of the left elbow for new Body objects. */
static const Coordinate2D lLeftElbow(90, 140);

/*! @brief The initial position of the left foot for new Body objects. */
static const Coordinate2D lLeftFoot(70, 290);

/*! @brief The initial position of the left side of the hips for new Body objects. */
static const Coordinate2D lLeftHip(120, 220);

/*! @brief The initial position of the left knee for new Body objects. */
static const Coordinate2D lLeftKnee(120, 280);

/*! @brief The initial position of the left shoulder for new Body objects. */
static const Coordinate2D lLeftShoulder(110, 100);

/*! @brief The initial position of the left wrist for new Body objects. */
static const Coordinate2D lLeftWrist(110, 200);

/*! @brief The initial position of the neck for new Body objects. */
static const Coordinate2D lNeck(155, 110);

/*! @brief The initial position of the right elbow for new Body objects. */
static const Coordinate2D lRightElbow(230, 145);

/*! @brief The initial position of the right foot for new Body objects. */
static const Coordinate2D lRightFoot(190, 340);

/*! @brief The initial position of the right side of the hips for new Body objects. */
static const Coordinate2D lRightHip(190, 220);

/*! @brief The initial position of the right knee for new Body objects. */
static const Coordinate2D lRightKnee(190, 280);

/*! @brief The initial position of the right shoulder for new Body objects. */
static const Coordinate2D lRightShoulder(200, 100);

/*! @brief The initial position of the right wrist for new Body objects. */
static const Coordinate2D lRightWrist(260, 120);

/*! @brief The initial position of the 'tail' for new Body objects. */
static const Coordinate2D lTail(155, 210);

/*! @brief The number of selections to present when finished. */
static const int kFinalSelectionCount = 5;

/*! @brief The number of iterations to perform. */
static const int kIterationCount = 5;

/*! @brief The number of Body objects to generate. */
static const int kPopulationSize = 200; // MUST BE EVEN!!!

/*! @brief The fraction of the set of Body objects that are to be mutated. */
static const realType kMutationFraction = 0.10;

/*! @brief The fraction of the set of Body objects that are selected. */
static const realType kSelectionFraction = 0.20;

/*! @brief The set of Body objects that are worked on. */
static BodyVector lPopulation;

/*! @brief The set of Body objects that have been selected. */
static BodyVector lSelection;

#if defined(__APPLE__)
# pragma mark Global constants and variables
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Local functions
#endif // defined(__APPLE__)

/*! @brief Update the fitness value for the Body objects. */
static void calculateFitnessValues(void)
{
#if defined(PRINT_VALUES_)
    std::cout << "Calculating fitness." << std::endl;
#endif // defined(PRINT_VALUES_)
    for (BodyVector::iterator walker(lPopulation.begin()); lPopulation.end() != walker; ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            aBody->updateFitness();
#if defined(PRINT_VALUES_)
            std::cout << " Fitness score = " << aBody->getFitnessScore() << std::endl;
#endif // defined(PRINT_VALUES_)
        }
    }
} // calculateFitnessValues

/*! @brief Release the objects that were created earlier. */
static void cleanup(void)
{
#if defined(PRINT_VALUES_)
    std::cout << "Cleaning up." << std::endl;
#endif // defined(PRINT_VALUES_)
    for (BodyVector::iterator walker(lPopulation.begin()); lPopulation.end() != walker; ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            delete aBody;
        }
    }
    lPopulation.clear();
    lSelection.clear();
} // cleanup

/*! @brief Create a set of Body objects to work with. */
static void generateBodies(void)
{
#if defined(PRINT_VALUES_)
    std::cout << "Generating " << kPopulationSize << " objects." << std::endl;
#endif // defined(PRINT_VALUES_)
    for (int ii = 0; kPopulationSize > ii; ++ii)
    {
        Body * aBody = new Body(lLeftElbow, lLeftFoot, lLeftHip, lLeftKnee, lLeftShoulder,
                                lLeftWrist, lNeck, lRightElbow, lRightFoot, lRightHip, lRightKnee,
                                lRightShoulder, lRightWrist, lTail);
        
        lPopulation.push_back(aBody);
#if defined(PRINT_VALUES_)
        std::cout << RadiansToDegrees(aBody->getLeftShoulderToElbowAngle()) << "," <<
                    RadiansToDegrees(aBody->getLeftElbowToWristAngle()) << "," <<
                    RadiansToDegrees(aBody->getRightShoulderToElbowAngle()) << "," <<
                    RadiansToDegrees(aBody->getRightElbowToWristAngle()) << "," <<
                    RadiansToDegrees(aBody->getLeftHipToKneeAngle()) << "," <<
                    RadiansToDegrees(aBody->getLeftKneeToFootAngle()) << "," <<
                    RadiansToDegrees(aBody->getRightHipToKneeAngle()) << "," <<
                    RadiansToDegrees(aBody->getRightKneeToFootAngle()) << "," <<
                    MapWeightToReal(aBody->getWeight()) << "," <<
                    MapSpaceToReal(aBody->getSpace()) << "," <<
                    MapTimeToReal(aBody->getTime()) << "," << MapFlowToReal(aBody->getFlow()) <<
                    std::endl;
#endif // defined(PRINT_VALUES_)
    }
} // generateBodies

/*! @brief Update the quadrant information for the Body objects. */
static void mapQuadrants(void)
{
#if defined(PRINT_VALUES_)
    std::cout << "Mapping quadrants." << std::endl;
#endif // defined(PRINT_VALUES_)
    for (BodyVector::iterator walker(lPopulation.begin()); lPopulation.end() != walker; ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            aBody->determineQuadrants();
        }
    }
} // mapQuadrants

/*! @brief Make the selections for this iteration. */
static void makeSelection(void)
{
#if defined(PRINT_VALUES_)
    std::cout << "Making selection." << std::endl;
#endif // defined(PRINT_VALUES_)
    realType sumOfScore = 0;
    
    for (BodyVector::iterator walker(lPopulation.begin()); lPopulation.end() != walker; ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            sumOfScore += aBody->getFitnessScore();
        }
    }
    lSelection.clear();
    for (size_t ii = 0, imax = static_cast<size_t>(lPopulation.size() * kSelectionFraction);
         imax > ii; )
    {
        realType sumOfArrayIndices = 0;
        realType chooseArray = RandInRange(0, sumOfScore);
        
        for (BodyVector::iterator walker(lPopulation.begin()); lPopulation.end() != walker;
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
                    lSelection.push_back(aBody);
                    ++ii;
                }
                else
                {
                    sumOfArrayIndices += score;
                }
            }
        }
    }
} // makeSelection

/*! @brief Generate a new set of objects, using the selected parents. */
static void doCrossovers(void)
{
#if defined(PRINT_VALUES_)
    std::cout << "Doing crossover." << std::endl;
#endif // defined(PRINT_VALUES_)
    bool keepGoing;
    
    // We have an initial population, from the previous generation, and we will create two new
    // 'children' for each parent pair.
    // Remove all the objects that are not propagating forward, which are unmarked - the selection
    // vector has pointers to the marked ones.
    do
    {
        keepGoing = false;
        for (BodyVector::iterator walker(lPopulation.begin()); lPopulation.end() != walker;
             ++walker)
        {
            Body * aBody = *walker;
            
            if (aBody && (! aBody->isMarked()))
            {
                lPopulation.erase(walker);
                keepGoing = true;
                break;
            }
            
        }
    }
    while (keepGoing);
    // Clear the marks!
    for (BodyVector::iterator walker(lPopulation.begin()); lPopulation.end() != walker;
         ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            aBody->clearMark();
        }
    }
    for (keepGoing = true; keepGoing; )
    {
        // Pick two 'parent' objects:
        size_t popSize = lPopulation.size() - 1;
        size_t firstChoice = RandInRange(0, popSize);
        size_t secondChoice;
        
        for ( ; ; )
        {
            secondChoice = RandInRange(0, popSize);
            if (firstChoice != secondChoice)
            {
                break;
            }
            
        }
        Body * firstParent = lPopulation[firstChoice];
        Body * secondParent = lPopulation[secondChoice];
        
        if (firstParent && secondParent)
        {
            Body * firstChild = new Body(*firstParent);
            Body * secondChild = new Body(*secondParent);
            
            // Crossover an attribute:
            lPopulation.push_back(firstChild);
            lPopulation.push_back(secondChild);
            firstChild->swapValues(*secondChild, 2);
            if (kPopulationSize <= lPopulation.size())
            {
                keepGoing = false;
            }
        }
    }
} // doCrossovers

/*! @brief Mutate some of the objects. */
static void doMutate(void)
{
#if defined(PRINT_VALUES_)
    std::cout << "Doing mutations." << std::endl;
#endif // defined(PRINT_VALUES_)
    // Mark the objects to be mutated:
    for (size_t ii = 0, imax = static_cast<size_t>(kMutationFraction * lPopulation.size());
         imax > ii;)
    {
        Body * aBody = lPopulation[ii];
        
        if (aBody && (! aBody->isMarked()))
        {
            aBody->setMark();
            ++ii;
        }
    }
    for (BodyVector::iterator walker(lPopulation.begin()); lPopulation.end() != walker; ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody && aBody->isMarked())
        {
            aBody->mutate();
        }
    }
} // doMutate

/*! @brief Make the final selections. */
static void makeFinalSelection(void)
{
    realType sumOfScore = 0;
    
    for (BodyVector::iterator walker(lPopulation.begin()); lPopulation.end() != walker;
         ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            sumOfScore += aBody->getFitnessScore();
        }
    }
    lSelection.clear();
    lSelection.resize(kFinalSelectionCount);
    for (size_t ii = 0, imax = kFinalSelectionCount; imax > ii; ++ii)
    {
        realType sumOfArrayIndices = 0;
        realType chooseArray = RandInRange(0, sumOfScore);
        
        for (BodyVector::iterator walker(lPopulation.begin()); lPopulation.end() != walker;
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
                    lSelection[ii] = aBody;
                }
                else
                {
                    sumOfArrayIndices += score;
                }
            }
        }
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
int main(int            argc,
         const char * * argv)
{
    generateBodies();
    for (int kk = 0; kIterationCount > kk; ++kk)
    {
        mapQuadrants();
        calculateFitnessValues();
        makeSelection();
        doCrossovers();
        doMutate();
    }
    makeFinalSelection();
#if defined(PRINT_VALUES_)
    for (BodyVector::iterator walker(lSelection.begin()); lSelection.end() != walker;
         ++walker)
    {
        Body * aBody = *walker;
        
        if (aBody)
        {
            std::cout << "Final Selection: " <<
                        RadiansToDegrees(aBody->getLeftShoulderToElbowAngle()) << "," <<
                        RadiansToDegrees(aBody->getLeftElbowToWristAngle()) << "," <<
                        RadiansToDegrees(aBody->getRightShoulderToElbowAngle()) << "," <<
                        RadiansToDegrees(aBody->getRightElbowToWristAngle()) << "," <<
                        RadiansToDegrees(aBody->getLeftHipToKneeAngle()) << "," <<
                        RadiansToDegrees(aBody->getLeftKneeToFootAngle()) << "," <<
                        RadiansToDegrees(aBody->getRightHipToKneeAngle()) << "," <<
                        RadiansToDegrees(aBody->getRightKneeToFootAngle()) << "," <<
                        MapWeightToReal(aBody->getWeight()) << "," <<
                        MapSpaceToReal(aBody->getSpace()) << "," <<
                        MapTimeToReal(aBody->getTime()) << "," <<
                        MapFlowToReal(aBody->getFlow()) << "," <<
                        MapHeightToReal(aBody->getHeight()) << std::endl;
        }
    }
#endif // defined(PRINT_VALUES_)
    cleanup();
    return 0;
} // main
