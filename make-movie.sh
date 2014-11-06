#!/bin/bash

cd frames

mogrify -flip -format jpg frame_*.ppm

rm -rf *.ppm

cd ..

# ffmpeg -f image2 -i frames/frame_%4d.jpg output.mp4
ffmpeg -f image2 -i frames/frame_%4d.jpg -i audio.mp4 -strict -2 -shortest output.mp4

rm -rf frames/*.jpg