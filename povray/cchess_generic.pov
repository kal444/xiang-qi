// Persistence of Vision Ray Tracer Scene Description File
// File: cchess_generic.pov
// Vers: 3.1
// Desc: Generic Chinese Chess Pieces 
// Date: 01/20/1999 
// Auth: Ke Huang

#version 3.1;

// ==== Standard POV-Ray Includes ====
#include "colors.inc"	// Standard Color definitions
#include "textures.inc"	// Standard Texture definitions
#include "woods.inc"    // wooden textures
#include "stones.inc"
#include "golds.inc"
#include "metals.inc"

global_settings
{
  assumed_gamma 1.0
}

camera
{
  location <-26,25,-9>
  look_at <-26,0,-9>
  translate 35*x
  //location  <0, 7, 0>
  //look_at   <0, 0, 0>
}

light_source
{
  0 // light's position (translated below)
  color red 1.0  green 1.0  blue 1.0  // light's color
  translate <0, 10, 10>
}

background { White }

#declare Clen = 4;
#declare CRad = 2.8;
#declare SRad = 3;
#declare IpCS = 1.077; // =sqrt(SRad^2-CRad^2)
#declare blackColor = color rgb<0,0.1,0>;
#declare redColor = color rgb<1,0,0>;
#declare pblack1 = "e:\temp\cchess\black-1.tga"
#declare pblack2 = "e:\temp\cchess\black-2.tga"
#declare pblack3 = "e:\temp\cchess\black-3.tga"
#declare pblack4 = "e:\temp\cchess\black-4.tga"
#declare pblack5 = "e:\temp\cchess\black-5.tga"
#declare pblack6 = "e:\temp\cchess\black-6.tga"
#declare pblack7 = "e:\temp\cchess\black-7.tga"
#declare pred1 = "e:\temp\cchess\red-1.tga"
#declare pred2 = "e:\temp\cchess\red-2.tga"
#declare pred3 = "e:\temp\cchess\red-3.tga"
#declare pred4 = "e:\temp\cchess\red-4.tga"
#declare pred5 = "e:\temp\cchess\red-5.tga"
#declare pred6 = "e:\temp\cchess\red-6.tga"
#declare pred7 = "e:\temp\cchess\red-7.tga"

#macro Make_Chess_Piece(SideName, PieceName, SetTexture)
difference
{
  difference
  {
    difference
    {
      difference
      {
        sphere { <0,0,0>, SRad }
        cylinder { <0,IpCS,0>, <0,Clen,0>, CRad }
      }
      cylinder { <0,-Clen,0>, <0,-IpCS,0>, CRad }
    }
    torus { CRad-0.4, 0.15 translate IpCS*y pigment {color SideName} }
  }
  difference
  {  
    height_field
    {
      tga PieceName //the char in the center.
      smooth
      water_level 0.8
      scale 3
      translate <-1.4,-1.5,-1.4>
    }
    box { 0, <3,3,10> translate <-1.4,-2.0,-1.4> }
    texture {pigment {color SideName}} // color of the char in the center.
  }
  texture {SetTexture}
}
#end

#declare setTexture = texture {T_Wood35}

#declare CChessPB1 = object {Make_Chess_Piece(blackColor, pblack1, setTexture)}
#declare CChessPB2 = object {Make_Chess_Piece(blackColor, pblack2, setTexture)}
#declare CChessPB3 = object {Make_Chess_Piece(blackColor, pblack3, setTexture)}
#declare CChessPB4 = object {Make_Chess_Piece(blackColor, pblack4, setTexture)}
#declare CChessPB5 = object {Make_Chess_Piece(blackColor, pblack5, setTexture)}
#declare CChessPB6 = object {Make_Chess_Piece(blackColor, pblack6, setTexture)}
#declare CChessPB7 = object {Make_Chess_Piece(blackColor, pblack7, setTexture)}
#declare CChessPR1 = object {Make_Chess_Piece(redColor, pred1, setTexture)}
#declare CChessPR2 = object {Make_Chess_Piece(redColor, pred2, setTexture)}
#declare CChessPR3 = object {Make_Chess_Piece(redColor, pred3, setTexture)}
#declare CChessPR4 = object {Make_Chess_Piece(redColor, pred4, setTexture)}
#declare CChessPR5 = object {Make_Chess_Piece(redColor, pred5, setTexture)}
#declare CChessPR6 = object {Make_Chess_Piece(redColor, pred6, setTexture)}
#declare CChessPR7 = object {Make_Chess_Piece(redColor, pred7, setTexture)}

#declare col=0;
#declare row=0;
object {CChessPB2 translate <col,0,row>}
#declare row=row-6;
object {CChessPB7 translate <col,0,row>}
#declare row=row-6;
object {CChessPB6 translate <col,0,row>}
#declare row=row-6;
object {CChessPB5 translate <col,0,row>}
#declare row=row-6;
#declare col=col+6;
#declare row=0;
object {CChessPB1 translate <col,0,row>}
#declare row=row-6;
object {CChessPB2 translate <col,0,row>}
#declare row=row-6;
object {CChessPB3 translate <col,0,row>}
#declare row=row-6;
object {CChessPB4 translate <col,0,row>}
#declare row=row-6;
#declare col=col+6;
#declare row=0;
object {CChessPR1 translate <col,0,row>}
#declare row=row-6;
object {CChessPR2 translate <col,0,row>}
#declare row=row-6;
object {CChessPR3 translate <col,0,row>}
#declare row=row-6;
object {CChessPR4 translate <col,0,row>}
#declare row=row-6;
#declare col=col+6;
#declare row=0;
object {CChessPR2 translate <col,0,row>}
#declare row=row-6;
object {CChessPR7 translate <col,0,row>}
#declare row=row-6;
object {CChessPR6 translate <col,0,row>}
#declare row=row-6;
object {CChessPR5 translate <col,0,row>}
