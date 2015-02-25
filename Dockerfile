FROM 32bit/ubuntu:14.04
MAINTAINER Simon Hartcher "simon@simonhartcher.com"
ENV HOSTNAME nubotsvm
ENV TERM linux

RUN apt-get update 

# Build dependencies
RUN apt-get -y install git-core 
RUN apt-get -y install cmake 
RUN apt-get -y install ninja-build 
RUN apt-get -y install bibtool 
RUN apt-get -y install libgoogle-perftools-dev 
RUN apt-get -y install libmatheval-dev
RUN apt-get -y install libboost-dev
RUN apt-get -y install software-properties-common
RUN apt-get -y install build-essential

# zeromq
RUN add-apt-repository ppa:chris-lea/zeromq
RUN apt-get -y install libzmq3-dev

# Install and configure icecream
RUN apt-get -y install icecc
RUN sed -i -e '/ICECC_SCHEDULER_HOST=/ s/="[a-zA-Z0-9]+/="10.1.0.80"/' /etc/icecc/icecc.conf
ENV PATH /usr/lib/icecc/bin:$PATH

# Download and install cppformat
WORKDIR /tmp
RUN git clone https://github.com/cppformat/cppformat
WORKDIR /tmp/cppformat
RUN cmake . -GNinja 
RUN ninja
RUN cp libformat.a /usr/local/lib
RUN cp format.h /usr/local/include

# NUClear dependencies
RUN apt-get -y install libprotobuf-dev
RUN apt-get -y install libespeak-dev
RUN apt-get -y install librtaudio-dev
RUN apt-get -y install libncurses5-dev
RUN apt-get -y install libjpeg-turbo8-dev
RUN apt-get -y install libfftw3-dev
RUN apt-get -y install libaubio-dev
RUN apt-get -y install libsndfile-dev
RUN apt-get -y install libyaml-cpp-dev
RUN apt-get -y install protobuf-compiler

# NUClear 
WORKDIR /nubots
RUN git clone -b OldDSL --single-branch https://github.com/fastcode/nuclear NUClear
WORKDIR /nubots/NUClear/build
RUN cmake .. -GNinja -DNUCLEAR_BUILD_TESTS=OFF
RUN ninja 
RUN ninja install

RUN apt-get -y install libblas-dev
RUN apt-get -y install liblapack-dev
RUN apt-get -y install libffi-dev

# armadillo
RUN add-apt-repository ppa:comp-phys/stable
RUN apt-get -y install libarmadillo-dev



# You need to mount your local code directory to the container
# Eg: docker run -t -i -v /local/path/:/nubots/NUbots /bin/bash
VOLUME /nubots/NUbots
WORKDIR /nubots/NUbots
