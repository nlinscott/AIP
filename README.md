Android Image Processor
=====================

Uses C++ and OpenCV to save different sized images when developing for Android.

Android Image Processor CLI

  I recently started working with android and found out that in order
  to develop for all screen sizes, we have to have several different sized
  images included with the project. Of course, I probably wont be using too many
  images, if someone needs to use some, this tool can create the sizes they want for their project.
  
  I decided to make this because i was sick of going into Microsoft paint and resizing an image 4 or 5 times to accomodate each resolution in Android. This program will do it in one step.


SYNTAX:

    *its a Command Line Interface. Deal with it.

  Enter in an image name and the dimensions you want for that image.

Example:

  > AIP exampleImage.jpg 320x210 1000x1000 10x10 
  
Notes:
  
  Currently, it has only been tested with .jpg files. Im sure it will work with most file types since OpenCV is so versitle. 
  
  Since this is meant to be used in Android development, it only outputs .PNG files. This can be changed by whoever wants to compile this themselves. For simplicity reasons and proff of concept, it only outputs .PNG images.
