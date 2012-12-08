// Persistence of Vision Ray Tracer Scene Description File
// File: ?.pov
// Vers: 3.1
// Desc: Basic Scene Example
// Date: mm/dd/yy
// Auth: ?[esp]
//

#version 3.1

#include "colors.inc"

global_settings
{
  assumed_gamma 1.0
//  hf_gray_16
}

camera
{
  location  <1, 4, 1>
  look_at   <1, 0, 1>
}

background {color White}

light_source
{
  0*x // light's position (translated below)
  color red 1.0  green 1.0  blue 1.0  // light's color
  translate <30, 30, 30>
}

#declare hf_four=
height_field
{
  tga "e:\temp\images\four.tga"
  texture {pigment { color Red }  finish {specular 1} }
  smooth
  water_level 0.8
  scale 3
}
