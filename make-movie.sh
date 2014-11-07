#!/bin/bash

cd frames

echo "Flipping images.."
mogrify -flip -format jpg frame_*.ppm

echo "Cleaning up ppm frames.."
rm -rf *.ppm

cd ..

echo "Creating movie.."
# ffmpeg -f image2 -i frames/frame_%4d.jpg output.mp4
ffmpeg -f image2 -i frames/frame_%4d.jpg -i audio.mp3 -strict -2 -shortest output.mp4

echo "Final cleanup"
rm -rf frames/*.jpg