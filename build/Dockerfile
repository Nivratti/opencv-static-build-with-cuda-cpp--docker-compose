FROM ubuntu:18.04

# Update the system so that the public apt repositry locations are visible
RUN apt update -y && apt upgrade -y

# -------------------------------------------------
# | Install g++ 7.5 and other necessary libraries |
# -------------------------------------------------
RUN apt install -y build-essential cmake git 

#     libgtk-3-dev \
#     libavcodec-dev libavformat-dev libswscale-dev \
#     libgstreamer-plugins-base1.0-dev libgstreamer1.0-dev


# ---------------------------
# | Install open cv version 4.5.5|
# ---------------------------

## If static linking then remove libpng system package otherwise opencv will not install it use systems shared library and it will cause issue in cmake
## build for library 'opencv_imgcodecs' --- more info -- libpng installed by apt install libgtk-3-dev
RUN apt remove libpng-dev

RUN cd && mkdir opencv_build && cd opencv_build && git clone --progress --verbose https://github.com/opencv/opencv.git && git clone --progress --verbose https://github.com/opencv/opencv_contrib.git && cd ~/opencv_build/opencv && git checkout --progress tags/4.5.5 && \
    cd ~/opencv_build/opencv_contrib && git checkout --progress tags/4.5.5 && \
    mkdir ~/opencv_build/opencv/build && cd ~/opencv_build/opencv/build
	
# BUILD_SHARED_LIBS=OFF -- for building static files
# WITH_OPENCL=OFF -- turn off unused package from build
# And turn off all Video I/O utils -- from -WITH_V4L to -DWITH_1394
RUN cd ~/opencv_build/opencv/build && \
    cmake -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D BUILD_SHARED_LIBS=OFF \
    -D BUILD_ZLIB=ON \
    -D WITH_OPENCL=OFF \
    -D WITH_V4L=OFF -DWITH_FFMPEG=OFF -DWITH_GSTREAMER=OFF \
    -D WITH_MSMF=OFF -DWITH_DSHOW=OFF -DWITH_AVFOUNDATION=OFF -DWITH_1394=OFF \
    -D OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib/modules ..

RUN cd ~/opencv_build/opencv/build && \
    make -j5 && make install 

# -------------------------------------------------
# | remove build files after setup                |
# -------------------------------------------------
RUN rm -rf ~/opencv_build

RUN ls


