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

Body::Body(void) :
    _leftElbow(), _leftFoot(), _leftHips(), _leftKnee(), _leftShoulder(), _leftWrist(), _neck(),
    _rightElbow(), _rightFoot(), _rightHips(), _rightKnee(), _rightShoulder(), _rightWrist(),
    _tail()
{
} // Body::Body

Body::~Body(void)
{
} // Body::~Body

#if defined(__APPLE__)
# pragma mark Actions and Accessors
#endif // defined(__APPLE__)

#if defined(__APPLE__)
# pragma mark Global functions
#endif // defined(__APPLE__)












#if 0
Body(float WristLeftX, float WristLeftY, float ElbowLeftX, float ElbowLeftY, float ShoulderLeftX, float ShoulderLeftY, float WristRightX, float WristRightY, float ElbowRightX, float ElbowRightY, float ShoulderRightX, float ShoulderRightY, float HipsLeftX, float HipsLeftY, float KneeLeftX, float KneeLeftY, float FootLeftX, float FootLeftY, float HipsRightX, float HipsRightY, float KneeRightX, float KneeRightY, float FootRightX, float FootRightY, float NeckX, float NeckY, float TailX, float TailY, float angle1, float angle2, float angle3, float angle4, float angle5, float angle6, float angle7, float angle8, float angle9, float Weight, float Space, float Time, float Flow, float Height)
{
    this.WristLeftX = WristLeftX;
    this.WristLeftY = WristLeftY;
    this.ElbowLeftX = ElbowLeftX;
    this.ElbowLeftY = ElbowLeftY;
    this.ShoulderLeftX = ShoulderLeftX;
    this.ShoulderLeftY = ShoulderLeftY;
    this.WristRightX = WristRightX;
    this.WristRightY = WristRightY;
    this.ElbowRightX = ElbowRightX;
    this.ElbowRightY = ElbowRightY;
    this.ShoulderRightX = ShoulderRightX;
    this.ShoulderRightY = ShoulderRightY;
    this.HipsLeftX = HipsLeftX;
    this.HipsLeftY = HipsLeftY;
    this.KneeLeftX = KneeLeftX;
    this.KneeLeftY = KneeLeftY;
    this.FootLeftX = FootLeftX;
    this.FootLeftY = FootLeftY;
    this.HipsRightX = HipsRightX;
    this.HipsRightY = HipsRightY;
    this.KneeRightX = KneeRightX;
    this.KneeRightY = KneeRightY;
    this.FootRightX = FootRightX;
    this.FootRightY = FootRightY;
    this.NeckX = NeckX;
    this.NeckY = NeckY;
    this.TailX = TailX;
    this.TailY = TailY;
    
    this.angle1 = angle1;
    this.angle2 = angle2;
    this.angle3 = angle3;
    this.angle4 = angle4;
    this.angle5 = angle5;
    this.angle6 = angle6;
    this.angle7 = angle7;
    this.angle8 = angle8;
    this.angle9 = angle9;

    this.Weight = Weight;
    this.Space = Space;
    this.Time = Time;
    this.Flow = Flow;
    this.Height = Height;
}

// combine ^^^ with vvv

void makeNew()
{
    float NewJoint1x, NewJoint1y, NewJoint2x, NewJoint2y, NewJoint3x, NewJoint3y, NewJoint4x, NewJoint4y, NewJoint5x, NewJoint5y, NewJoint6x, NewJoint6y, NewJoint7x, NewJoint7y, NewJoint8x, NewJoint8y;
    
    //Offset shoulder+hip location for aesthetic in drawing
    modShoulderLeftX = (random(-5, 5) + ShoulderLeftX);
    modShoulderLeftY = (random(-5, 5) + ShoulderLeftY);
    modShoulderRightX = (random(-5, 5) + ShoulderRightX);
    modShoulderRightY = (random(-5, 5) + ShoulderRightY);
    modHipsLeftX = (random(-5, 5) + HipsLeftX);
    modHipsLeftY = (random(-5, 5) + HipsLeftY);
    modHipsRightX = (random(-5, 5) + HipsRightX);
    modHipsRightY = (random(-5,5) + HipsRightY);
    
    //generate random angles for joints: shoulder and hip locations affect elbow and knees
    angle1 = random(0,360);
    angle2 = random(0,180);
    angle3 = random(0,360);
    angle4 = random(0,180);
    angle5 = random(0,360);
    angle6 = random(0,180);
    angle7 = random(0,360);
    angle8 = random(0,180);
    angle9 = random(0,180);
    
    //LArm
    //create polar coordinates to adjust elbow and wrist locations
    NewJoint1x = (cos(angle1) * radius);
    NewJoint1y = (sin(angle1) * radius);
    NewJoint2x = (cos(angle2) * radius);
    NewJoint2y = (sin(angle2) * radius);
    ElbowLeftX = ShoulderLeftX + NewJoint1x;
    ElbowLeftY = ShoulderLeftY + NewJoint1y;
    WristLeftX = ElbowLeftX + NewJoint2x;
    WristLeftY = ElbowLeftY + NewJoint2y;
    ShoulderLeftX = modShoulderLeftX;
    ShoulderLeftY = modShoulderLeftY;
    
    //RArm
    //create polar coordinate to adjust elbow and wrist locations
    NewJoint3x = (cos(angle3) * radius);
    NewJoint3y = (sin(angle3) * radius);
    NewJoint4x = (cos(angle4) * radius);
    NewJoint4y = (sin(angle4) * radius);
    ElbowRightX = ShoulderRightX + NewJoint3x;
    ElbowRightY = ShoulderRightY + NewJoint3y;
    WristRightX = ElbowRightX + NewJoint4x;
    WristRightY = ElbowRightY + NewJoint4y;
    ShoulderRightX = modShoulderRightX;
    ShoulderRightY = modShoulderRightY;
    
    //LLeg
    //create polar coordinate to adjust elbow and wrist locations
    NewJoint5x = (cos(angle5) * radius);
    NewJoint5y = (sin(angle5) * radius);
    NewJoint6x = (cos(angle6) * radius);
    NewJoint6y = (sin(angle6) * radius);
    KneeLeftX = HipsLeftX + NewJoint5x;
    KneeLeftY = HipsLeftY + NewJoint5y;
    FootLeftX = KneeLeftX + NewJoint6x;
    FootLeftY = KneeLeftY + NewJoint6y;
    HipsLeftX = modHipsLeftX;
    HipsLeftY = modHipsLeftY;
    
    //RLeg
    //create polar coordinate to adjust elbow and wrist locations
    NewJoint7x = (cos(angle7) * radius);
    NewJoint7y = (sin(angle7) * radius);
    NewJoint8x = (cos(angle8) * radius);
    NewJoint8y = (sin(angle8) * radius);
    KneeRightX = HipsRightX + NewJoint7x;
    KneeRightY = HipsRightY + NewJoint7y;
    FootRightX = KneeRightX + NewJoint8x;
    FootRightY = KneeRightY + NewJoint8y;
    
    
    //Spine
    //by controlling the curve a chest can be implied
    NeckX = abs(HipsRightX - HipsLeftX) / 2 + HipsLeftX;
    TailX = (abs(HipsRightX - HipsLeftX) / 2) + HipsLeftX;
    
    Weight = round(random(0, 1)); //(random(0.1, 0.2) * 100)
    Space = round(random(0, 1));
    Time = round(random(0, 1));
    Flow = round(random(0, 1));
    Height = round(random(0, 4));
}

void drawBody(void)
{
    //    noFill();
    //    stroke(75);
    
    //LArm
    //    strokeWeight(4);
    //    line(modShoulderLeftX, modShoulderLeftY, ElbowLeftX, ElbowLeftY);
    //    line(ElbowLeftX, ElbowLeftY, WristLeftX, WristLeftY);
    //    strokeWeight(1);
    //    ellipse(WristLeftX, WristLeftY, 10,10);
    
    //RArm
    //    strokeWeight(4);
    //    line(modShoulderRightX, modShoulderRightY, ElbowRightX, ElbowRightY);
    //    line(ElbowRightX, ElbowRightY, WristRightX, WristRightY);
    //    strokeWeight(1);
    //    ellipse(WristRightX, WristRightY, 10,10);
    
    //    //LLeg
    //    line(modHipsLeftX, modHipsLeftY, KneeLeftX, KneeLeftY);
    //    line(KneeLeftX, KneeLeftY, FootLeftX, FootLeftY);
    
    //    //RLeg
    //    line(modHipsRightX, modHipsRightY, KneeRightX, KneeRightY);
    //    line(KneeRightX, KneeRightY, FootRightX, FootRightY);
    
    //    strokeWeight(2);
    //    stroke(0);
    
    //    beginShape();
    //    vertex ((random(-15, 15)+NeckX),(random(-15, 15)+ NeckY));
    //    bezierVertex((random(-15, 15)+ NeckX), (random(-15, 15)+ NeckY), (random(-15, 15)+ TailX), (random(-15, 15)+ TailY),(random(-15, 15)+ TailX),(random(-15, 15)+ TailY));
    //    endShape();
    
    //shoulder
    //    beginShape();
    //    vertex ((random(-15, 15)+ShoulderLeftX),(random(-15, 15)+ ShoulderLeftY));
    //    bezierVertex((random(-15, 15)+ ShoulderLeftX), (random(-15, 15)+ ShoulderLeftY), (random(-15, 15)+ ShoulderRightX), (random(-15, 15)+ ShoulderRightY),(random(-15, 15)+ ShoulderRightX),(random(-15, 15)+ ShoulderRightY));
    //    endShape();
    
    //hips
    //    beginShape();
    //    vertex ((random(-15, 15)+HipsLeftX),(random(-15, 15)+ HipsLeftY));
    //    bezierVertex((random(-15, 15)+ HipsLeftX), (random(-15, 15)+ HipsLeftY), (random(-15, 15)+ HipsRightX), (random(-15, 15)+ HipsRightY),(random(-15, 15)+ HipsRightX),(random(-15, 15)+ HipsRightY));
    //    endShape();
    
    //    fill(0);
    //    if (Weight == 1){
    //        Weight1 = "Strong";
    //    }
    //    else{
    //        Weight1 = "Light";
    //    }
    //
    //    if (Space == 1){
    //        Space1 = "Direct";
    //    }
    //    else{
    //        Space1 = "Indirect";
    //    }
    //
    //    if (Time == 1){
    //        Time1 = "Sudden";
    //    }
    //    else{
    //        Time1 = "Sustained";
    //    }
    //
    //    if (Flow == 1){
    //        Flow1 = "Bound";
    //    }
    //    else{
    //        Flow1 = "Free";
    //    }
    //
    //    if (Height == 0){
    //        Height1 = "Low";
    //    }
    //    else if (Height == 1){
    //        Height1 = "Mid-Low";
    //    }
    //    else if (Height == 2){
    //        Height1 = "Middle";
    //    }
    //    else if (Height == 3){
    //        Height1 = "Mid-High";
    //    }
    //    else{
    //        Height1 = "High";
    //    }
    
}
}
#endif//0