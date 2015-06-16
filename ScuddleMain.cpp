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

static const Coordinate2D lLeftElbow(90, 140);
static const Coordinate2D lLeftFoot(70, 290);
static const Coordinate2D lLeftHip(120, 220);
static const Coordinate2D lLeftKnee(120, 280);
static const Coordinate2D lLeftShoulder(110, 100);
static const Coordinate2D lLeftWrist(110, 200);

static const Coordinate2D lNeck(155, 110);

static const Coordinate2D lRightElbow(230, 145);
static const Coordinate2D lRightFoot(190, 340);
static const Coordinate2D lRightHip(190, 220);
static const Coordinate2D lRightKnee(190, 280);
static const Coordinate2D lRightShoulder(200, 100);
static const Coordinate2D lRightWrist(260, 120);

static const Coordinate2D lTail(155, 210);

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
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
} // main

#if 0

//Polar Coordinate to change the joint angle
public float radius = 60;
public float radius1 = 90;
public float radius2 = 40;

//New joint angle
public float angle1, angle2, angle3, angle4, angle5, angle6, angle7, angle8, angle9;

//Offset shoulder location for aesthetic in drawing
public float random1, random2, random3, random4, random5, random6, random7, random8;

//map joint angles to quadrants 1-4
float[] map1;
float[] map2;
float[] map3;
float[] map4;
float[] map5;
float[] map6;
float[] map7;
float[] map8;


public float Weight = 0;
public float Space = 0;
public float Time = 0;
public float Flow = 0;
public float Height = 0;

public float chooseArray = 0;
public int chooseArray2 = 0;
public int chooseArray3 = 0;
public int chooseIndex1 = 0;
public int chooseIndex2 = 0;
public float sumOfArrayIndexes = 0;

int pop = 200;

ArrayList StoreDataA;
ArrayList HoldData;
ArrayList StoreDataB;
float[] scorePosition;
float[] scoreAccumulate;
float[] scoreFinal;

// SETUP ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void setup(){
    size (400,440);
    background (50);
    fill(255);
    smooth();
    rect(10,10,380, 390);
    noStroke ();
    font = loadFont("AgencyFB-Reg-28.vlw");
    textFont(font);
    
    StoreDataA = new ArrayList();
    StoreDataB = new ArrayList();
    scorePosition = new float[pop];
    scoreAccumulate = new float[pop];
    scoreFinal = new float[pop];
    map1 = new float[pop];
    map2 = new float[pop];
    map3 = new float[pop];
    map4 = new float[pop];
    map5 = new float[pop];
    map6 = new float[pop];
    map7 = new float[pop];
    map8 = new float[pop];
    
}

// DRAW +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void draw(){
//    frameRate(.5);
//    //Allows for playing and pausing the looping playback
//    if(startMovie==true && StoreDataA.size()!=0){
//        if(i<6){
//            background (50);
//            fill(255);
//            rect(10,10,380, 390);
    
            Body position = (Body)StoreDataB.get(i);
            //Body position = (Body)StoreDataA.get(i);
            position.drawBody();
            
//            fill(0);
//            text("Score: " + nf(scoreFinal[i], 2, 2), 180, 35);
//            text("Number: " + i, 300, 35);
//            //saveFrame();
//            i++;
//        } else{
//            i=0;
//        }
//    }
}

// GENERATE ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void generate()
{
    
    //generate population
    println("Generate,");
    for( int a = 0; a < pop; a++)
    {
        
        position = new Body(WristLeftX, WristLeftY, ElbowLeftX, ElbowLeftY, ShoulderLeftX, ShoulderLeftY, WristRightX, WristRightY, ElblowRightX, ElblowRightY, ShoulderRightX, ShoulderRightY, HipLeftX, HipLeftY, KneeLeftX, KneeLeftY, FootLeftX, FootLeftY, HipRightX, HipRightY, KneeRightX, KneeRightY, FootRightX, FootRightY, NeckX, NeckY, TailX, TailY, angle1, angle2, angle3, angle4, angle5, angle6, angle7, angle8, angle9, Weight, Space, Time, Flow, Height);
        position.makeNew();
        
        StoreDataA.add(position);
        
        //print data
        print(position.angle1 + ",");
        print(position.angle2 + ",");
        print(position.angle3 + ",");
        print(position.angle4 + ",");
        print(position.angle5 + ",");
        print(position.angle6 + ",");
        print(position.angle7 + ",");
        print(position.angle8 + ",");
        print(position.angle9 + ",");
        print(position.Weight + ",");
        print(position.Space + ",");
        print(position.Time + ",");
        print(position.Flow + ",");
        println(position.Height);
    }
}

// MAP +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void mapAngles(){
    print("Mapping");
    //Map angles into quadrants for scoring purposes
    for(int i = 0; i < StoreDataA.size(); i++){
        Body position = (Body)StoreDataA.get(i);
        
        if ((position.angle1) < 90){
            map1[i]=1;
        }        else if((position.angle1) > 90 && (position.angle1) <180){
            map1[i]= 2;
        }          else if ((position.angle1) > 180 && (position.angle1) < 270){
            map1[i]= 1;
        }            else{
            map1[i]=4;
        }
        
        if ((position.angle2) < 45){
            map2[i]=1;
        }        else if((position.angle2) > 45 && (position.angle2) <90){
            map2[i]= 2;
        }          else if ((position.angle2) > 90 && (position.angle2) < 135){
            map2[i]= 1;
        }            else{
            map2[i]=4;
        }
        
        if ((position.angle3) < 90){
            map3[i]=2;
        }        else if((position.angle3) > 90 && (position.angle3) <180){
            map3[i]= 1;
        }          else if ((position.angle3) > 180 && (position.angle3) < 270){
            map3[i]= 4;
        }            else{
            map3[i]=1;
        }
        
        if ((position.angle4) < 45){
            map4[i]=2;
        }        else if((position.angle4) > 45 && (position.angle4) <90){
            map4[i]= 1;
        }          else if ((position.angle4) > 90 && (position.angle4) < 135){
            map4[i]= 4;
        }            else{
            map4[i]=1;
        }
        
        if ((position.angle5) < 90){
            map5[i]=4;
        }        else if((position.angle5) > 90 && (position.angle5) <180){
            map5[i]= 1;
        }          else if ((position.angle5) > 180 && (position.angle5) < 270){
            map5[i]= 2;
        }            else{
            map5[i]=1;
        }
        
        if ((position.angle6) < 45){
            map6[i]=4;
        }        else if((position.angle6) > 45 && (position.angle6) <90){
            map6[i]= 1;
        }          else if ((position.angle6) > 90 && (position.angle6) < 135){
            map6[i]= 2;
        }            else{
            map6[i]=1;
        }
        
        if ((position.angle7) < 90){
            map7[i]=1;
        }        else if((position.angle7) > 90 && (position.angle7) <180){
            map7[i]= 4;
        }          else if ((position.angle7) > 180 && (position.angle7) < 270){
            map7[i]= 1;
        }            else{
            map7[i]=2;
        }
        
        
        if ((position.angle8) < 45){
            map8[i]=1;
        }        else if((position.angle8) > 45 && (position.angle8) <90){
            map8[i]= 4;
        }          else if ((position.angle8) > 90 && (position.angle8) < 135){
            map8[i]= 1;
        }            else{
            map8[i]=2;
        }
        
        //Sum of quadrants values to depict score
        scorePosition[i] = map1[i] + map2[i] + map3[i] + map4[i] + map5[i] + map6[i] + map7[i] + map8[i];
        //Print data
        print(i + ", Angle Sum," + scorePosition[i] + ",");
        print("map1" + map1[i] + ",");
        print("map2" + map2[i] + ",");
        print("map3" + map3[i] + ",");
        print("map4" + map4[i] + ",");
        print("map5" + map5[i] + ",");
        print("map6" + map6[i] + ",");
        print("map7" + map7[i] + ",");
        println("map8" + map8[i] + ",");
    }
}

// FITNESS +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void fitness(){
    float percentageBartenieff = 0;
    float percentageEffort = 0;
    float percentageHeight = 0;
    
    println("Fitness,");
    
    //Emphasizing contralateral positions that are not fully distal or medial in extension
    //Emphasizing efforts that are not fully fighting or indulging
    //Emphasizing heights that are 'in-between', not fully jumping, standing or sitting
    for(int i = 0; i < StoreDataA.size(); i++){
        Body position = (Body)StoreDataA.get(i);
        
        //Fitness Function
        //distal
        if ((scorePosition[i] == 8) && ((map1[i] == map2[i]) && (map3[i] == map4[i]) && (map5[i] == map6[i]) && (map7[i] == map8[i]))) {
            percentageBartenieff = 0.4;
        }
        //medial
        else if ((scorePosition[i] == 12) && ((map1[i] == map2[i]) && (map3[i] == map4[i]) && (map5[i] == map6[i]) && (map7[i] == map8[i]))) {
            percentageBartenieff = 0.7;
        }
        //homolateral
        else if ((((abs(position.angle1 - position.angle5) > 30) && (abs(position.angle2 - position.angle6) > 30))) || (((abs(position.angle3 - position.angle7) > 30) && (abs(position.angle4 - position.angle8) > 30)))){
            percentageBartenieff = 0.5;
        }
        //contralateral
        else if ((((abs(position.angle1 - position.angle7) > 30) && (abs(position.angle2 - position.angle8) > 30))) || (((abs(position.angle3 - position.angle5) > 30) && (abs(position.angle4 - position.angle6) > 30)))){
            percentageBartenieff = 1.3;
        }
        
        //homologous
        else if (((map1[i] == map3[i]) && (map2[i] == map4[i])) || ((map5[i] == map7[i]) && (map6[i] == map8[i]))){
            percentageBartenieff = 0.4;
        }
        
        //laban
        if (((Weight==1) && (Space==1) && (Time==1) && (Flow == 1)) || ((Weight==2) && (Space==2) && (Time==2) && (Flow == 2))){
            percentageEffort = 0.6;
        }
        else if (((Weight==Space) && (Time==Flow)) || ((Weight==Time) && (Space==Flow)) || ((Weight==Flow) && (Space==Time))){
            percentageEffort = 1.2;
        }
        else{
            percentageEffort = 1.4;
        }
        
        
        //height
        if ((Height == 0) || (Height == 2) || (Height == 4)){
            //make another variable so can track which height is picked
            scorePosition[i] = scorePosition[i] + 1;
        }
        
        else{
            scorePosition[i] = scorePosition[i] + 3;
        }
        
        if ((Height == 1) || (Height == 2) || (Height == 3)){
            
            //one leg is fully extended
            if ((map5[i] == 1) || (map5[i] == 2) || (map7[i] == 1) || (map7[i] == 2) && (map6[i] == 1) || (map6[i] == 2) || (map8[i] == 1) || (map8[i] == 2)){
                percentageHeight = 1.1;
            }
            
            // only the lower leg is extended
            else if((map6[i] == 1) || (map6[i] == 2) || (map8[i] == 1) || (map8[i] == 2)){
                percentageHeight = 1.3;
            }
            
            // no leg is extended - cannot jump without legs in a crouch!
            else{
                percentageHeight = 0.3;
            }
        }  //close height
        
        //Accumulate + Modify score
        scoreAccumulate[i] = (percentageBartenieff + percentageEffort + percentageHeight) * scorePosition[i];
        
        //print modifiers and final score
        // print(i+ " Bartenieff " + percentageBartenieff + ",");
        // print(" Laban " + percentageEffort + ",");
        // print(" Height " + percentageHeight + ",");
        print(" FinalScore, " + scoreAccumulate[i] + ", ");
    }
}

// SELECTION +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void selection(){
    println("Selection,");
    float sumOfScore = 0;
    int index = 0;
    
    //Calculate sum of scores in array
    for(int a = 0; a < pop; a++){
        sumOfScore = sumOfScore + scoreAccumulate[a];
    }
    
    //Likelihood proportional to fitness
    for(int k = 0; k < (pop/5); k++){
        sumOfArrayIndexes = 0;
        chooseArray = (random(0,sumOfScore));
        
        for(int f = 0; f < pop; f++){
            Body position = (Body)StoreDataA.get(f);
            
            if ((chooseArray > sumOfArrayIndexes) && (chooseArray < (sumOfArrayIndexes + scoreAccumulate[f]))){
                scoreFinal[index] = scoreAccumulate[f];
                sumOfArrayIndexes = sumOfArrayIndexes + scoreAccumulate[f];
                StoreDataB.add(position);
                index = index + 1;
                print(k + " " + scoreAccumulate[f] + ", ");
            }
            
            else{
                sumOfArrayIndexes = sumOfArrayIndexes + scoreAccumulate[f];
            }
        }
    }
}

void crossover(){
    int q = 0;
    float hold = 0;
    println("CrossOver");
    
    // 2-point crossover regenerates population until reaches original size (pop/2 because 2 new individuals produced for each breeding)
    for(int c = 0; c < (pop/2); c++){
        
        //choose the array # out of the arraylist (and out of the 40 lists selected)
        chooseArray2 = (round(random(0,39)));
        chooseArray3 = (round(random(0,39)));
        
        // chooses the index # out of the array (only 42 elements long)
        chooseIndex1 = (round(random(29, 42)));
        chooseIndex2 = (round(random(29, 42)));
        
        //Print data
        println(c + "  Array1 " + chooseArray2 + "  Array2 " + chooseArray3 + "  Index1 " + chooseIndex1 + " Index2 " + chooseIndex2);
        
        //Get data from index location and extract into arrays
        Body position = (Body)StoreDataA.get(chooseArray2);
        Body position1 = (Body)StoreDataA.get(chooseArray3);
        
        if (chooseIndex1 < chooseIndex2){
            if (chooseIndex1 == 29){
                hold = position.angle1;
                position.angle1 = position1.angle1;
                position1.angle1 = hold;
            } else if (chooseIndex1 == 30){
                hold = position.angle2;
                position.angle2 = position1.angle2;
                position1.angle2 = hold;
            } else if (chooseIndex1 == 31){
                hold = position.angle3;
                position.angle3 = position1.angle3;
                position1.angle3 = hold;
            } else if (chooseIndex1 == 32){
                hold = position.angle4;
                position.angle4 = position1.angle4;
                position1.angle4 = hold;
            } else if (chooseIndex1 == 33){
                hold = position.angle5;
                position.angle5 = position1.angle5;
                position1.angle5 = hold;
            } else if (chooseIndex1 == 34){
                hold = position.angle6;
                position.angle6 = position1.angle6;
                position1.angle6 = hold;
            } else if (chooseIndex1 == 35){
                hold = position.angle7;
                position.angle7 = position1.angle7;
                position1.angle7 = hold;
            } else if (chooseIndex1 == 36){
                hold = position.angle8;
                position.angle8 = position1.angle8;
                position1.angle8 = hold;
            } else if (chooseIndex1 == 37){
                hold = position.angle9;
                position.angle9 = position1.angle9;
                position1.angle9 = hold;
            } else if (chooseIndex1 == 38){
                hold = position.Weight;
                position.Weight = position1.Weight;
                position1.Weight = hold;
            } else if (chooseIndex1 == 39){
                hold = position.Space;
                position.Space = position1.Space;
                position1.Space = hold;
            } else if (chooseIndex1 == 40){
                hold = position.Time;
                position.Time = position1.Time;
                position1.Time = hold;
            } else if (chooseIndex1 == 41){
                hold = position.Flow;
                position.Flow = position1.Flow;
                position1.Flow = hold;
            } else {
                hold = position.Height;
                position.Height = position1.Height;
                position1.Height = hold;
            }}
        
        else{
            if (chooseIndex2 == 29){
                hold = position.angle1;
                position.angle1 = position1.angle1;
                position1.angle1 = hold;
            } else if (chooseIndex2 == 30){
                hold = position.angle2;
                position.angle2 = position1.angle2;
                position1.angle2 = hold;
            } else if (chooseIndex2 == 31){
                hold = position.angle3;
                position.angle3 = position1.angle3;
                position1.angle3 = hold;
            } else if (chooseIndex2 == 32){
                hold = position.angle4;
                position.angle4 = position1.angle4;
                position1.angle4 = hold;
            } else if (chooseIndex2 == 33){
                hold = position.angle5;
                position.angle5 = position1.angle5;
                position1.angle5 = hold;
            } else if (chooseIndex2 == 34){
                hold = position.angle6;
                position.angle6 = position1.angle6;
                position1.angle6 = hold;
            } else if (chooseIndex2 == 35){
                hold = position.angle7;
                position.angle7 = position1.angle7;
                position1.angle7 = hold;
            } else if (chooseIndex2 == 36){
                hold = position.angle8;
                position.angle8 = position1.angle8;
                position1.angle8 = hold;
            } else if (chooseIndex2 == 37){
                hold = position.angle9;
                position.angle9 = position1.angle9;
                position1.angle9 = hold;
            } else if (chooseIndex2 == 38){
                hold = position.Weight;
                position.Weight = position1.Weight;
                position1.Weight = hold;
            } else if (chooseIndex2 == 39){
                hold = position.Space;
                position.Space = position1.Space;
                position1.Space = hold;
            } else if (chooseIndex2 == 40){
                hold = position.Time;
                position.Time = position1.Time;
                position1.Time = hold;
            } else if (chooseIndex2 == 41){
                hold = position.Flow;
                position.Flow = position1.Flow;
                position1.Flow = hold;
            } else {
                hold = position.Height;
                position.Height = position1.Height;
                position1.Height = hold;
            }}
    }}

void mutate(){
    int chooseArrayMutate = 0;
    int chooseIndexMutate = 0;
    int mutateValueMedial = 0;
    int mutateValueDistal = 0;
    println("Mutate!!!");
    
    //Mutate 10% of second generation
    //Selections joint angles, efforts and height - DOES NOT change coordinates directly
    for( int n = 0; n < (pop/10); n++){
        
        //choose random Array in generationA to mutate
        chooseArrayMutate = round(random(0, StoreDataA.size()));
        //retreive Array from arraylist
        Body position3 = (Body)StoreDataA.get(chooseArrayMutate);
        //choose random index in array (between angles 1-9) to mutate
        chooseIndexMutate = round(random(0, 8));
        //choose new random value for mutation :: Medial = shoulders/ hips (with 360 rotation) :: Distal = elbows/ knees (with 180 hinge)
        mutateValueMedial = round(random(0, 360));
        mutateValueDistal = round(random(0, 180));
        
        
        
        print(n + " Array Number: " + chooseArrayMutate + " Index Value " + chooseIndexMutate + " Mutate Value: " + mutateValueMedial + " " + mutateValueDistal);
        // println("chooseIndexMutate: " + chooseIndexMutate);
        
        //     for(int i=1; i<11; i++){
        if (chooseIndexMutate == 29){
            print(" Old Mutate: " + position3.angle1);
            position3.angle1 = mutateValueMedial;
            println(" New Mutate: " + position3.angle1);
        }
        
        else if (chooseIndexMutate == 30){
            print(" Old Mutate: " + position3.angle2);
            position3.angle2 = mutateValueDistal;
            println(" New Mutate: " + position3.angle2);
        }
        else if (chooseIndexMutate == 31){
            print(" Old Mutate: " + position3.angle3);
            position3.angle3 = mutateValueMedial;
            println(" New Mutate: " + position3.angle3);
        }
        else if (chooseIndexMutate == 32){
            print(" Old Mutate: " + position3.angle4);
            position3.angle4 = mutateValueDistal;
            println(" New Mutate: " + position3.angle4);
        }
        else if (chooseIndexMutate == 33){
            print(" Old Mutate: " + position3.angle5);
            position3.angle5 = mutateValueMedial;
            println(" New Mutate: " + position3.angle5);
        }
        else if (chooseIndexMutate == 34){
            print(" Old Mutate: " + position3.angle6);
            position3.angle6 = mutateValueDistal;
            println(" New Mutate: " + position3.angle6);
        }
        else if (chooseIndexMutate == 35){
            print(" Old Mutate: " + position3.angle7);
            position3.angle7 = mutateValueMedial;
            println(" New Mutate: " + position3.angle7);
        }
        else {
            print(" Old Mutate: " + position3.angle8);
            position3.angle8 = mutateValueDistal;
            println(" New Mutate: " + position3.angle8);
        } } }

void selectionFinal()
{
    float sumOfScore = 0;
    int index = 0;
    
    //Final Selection of individuals with likelihood proportional to their fitness
    for(int gm = 0; gm < pop; gm++){
        sumOfScore = sumOfScore + scoreAccumulate[gm];
        // println("SumScore: " + sumOfScore);
    }
    
    for(int kk = 0; kk < (pop/40); kk++){
        sumOfArrayIndexes = 0;
        chooseArray = (random(0,sumOfScore));
        
        for(int ff = 0; ff < pop; ff++){
            Body position = (Body)StoreDataA.get(ff);
            
            if ((chooseArray > sumOfArrayIndexes) && (chooseArray < (sumOfArrayIndexes + scoreAccumulate[ff]))){
                scoreFinal[index] = scoreAccumulate[ff];
                sumOfArrayIndexes = sumOfArrayIndexes + scoreAccumulate[ff];
                StoreDataB.add(kk, position);
                index = index + 1;
                
                println("Final Selection: ");
                print(position.angle1 + ",");
                print(position.angle2 + ",");
                print(position.angle3 + ",");
                print(position.angle4 + ",");
                print(position.angle5 + ",");
                print(position.angle6 + ",");
                print(position.angle7 + ",");
                print(position.angle8 + ",");
                print(position.angle9 + ",");
                print(position.Weight + ",");
                print(position.Space + ",");
                print(position.Time + ",");
                print(position.Flow + ",");
                println(position.Height);
            }
            
            else{
                sumOfArrayIndexes = sumOfArrayIndexes + scoreAccumulate[ff];
            }
        }}}

void button()
{
    
    //Runs GA
    
    generate();
    
    for(int k = 0; k < 5; k++)
    {
        mapAngles();
        fitness();
        selection();
        crossover();
        mutate();
    }
    selectionFinal();
}
#endif//0