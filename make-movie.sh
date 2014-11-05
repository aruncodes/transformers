#!/bin/bash

cd frames

mogrify -flip -format jpg frame_*.ppm

cd ..

ffmpeg -f image2 -i frames/frame_%4d.jpg output.mpg