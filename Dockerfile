# Base image
FROM ubuntu:18.04

ENV DEBIAN_FRONTEND noninteractive

# Setting the work directory
WORKDIR /root

# Installing the necessary apt repositories
RUN apt-get update -y && \
    apt-get install -y apt-utils && \
    apt-get install -y build-essential \
        libncurses-dev \
        libgl-dev \
        libglu-dev \
        libglib2.0-dev \
        libsm-dev \
        libxrender-dev \
        libfontconfig1-dev \
        libxext-dev \
        xz-utils \
        curl \
        cmake \
        python \
        vim \
        wget \
        git \
        tar

# Downloading and unzipping LLVM 9.0.0 binaries
RUN \
    wget http://releases.llvm.org/9.0.0/clang%2bllvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz && \
    tar -xvf clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz && \
    mv clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04 clang_9.0.0 && \
    rm clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz

# Adding LLVM binaries to the PATH environment variable
ENV PATH="/root/clang_9.0.0/bin:$PATH"
ENV LD_LIBRARY_PATH="/root/clang_9.0.0/lib:$LD_LIBRARY_PATH"

# Cloning and installing the pLiner repo
RUN \
    git clone https://github.com/llnl/pLiner.git && \
    cd pLiner/clang-tool && \
    wget https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp && \
    mkdir build; cd build && \
    cmake .. && \
    make clean && \
    make && \
    make install

# Adding pLiner to the PATH environment variable
ENV PATH="/root/pLiner/clang-tool/build:$PATH"

# Running tests to check whether the tool install was successful
RUN \
    cd $HOME/pLiner/tests && \
    ./test.sh
