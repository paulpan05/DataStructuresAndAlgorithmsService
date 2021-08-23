FROM fedora
RUN yum install -y yum-utils wget tar unzip zip
RUN yum-config-manager --add-repo https://rpm.releases.hashicorp.com/fedora/hashicorp.repo
RUN yum install -y gcc-c++ pulseaudio-libs-devel libuuid-devel libcurl-devel zlib-devel openssl-devel cmake git \
  terraform postgresql-devel doxygen c-ares-devel graphviz dia brotli-devel jsoncpp-devel xmlto

RUN git clone --recurse-submodules -j8 https://github.com/an-tao/drogon
WORKDIR /drogon
RUN mkdir build
WORKDIR /drogon/build
RUN cmake ..
RUN make && make install
WORKDIR /
RUN rm -r drogon

RUN arch=$(uname -m); curl https://awscli.amazonaws.com/awscli-exe-linux-${arch}.zip -o awscliv2.zip
RUN unzip awscliv2.zip
RUN ./aws/install
RUN rm awscliv2.zip
RUN rm -r aws

RUN git clone --recurse-submodules -j8 https://github.com/aws/aws-sdk-cpp.git
WORKDIR /aws-sdk-cpp
RUN mkdir build
WORKDIR /aws-sdk-cpp/build
RUN CXXFLAGS="-Wno-error=nonnull" cmake .. -DBUILD_ONLY="s3;sns" -DCMAKE_BUILD_TYPE=Release
RUN make && make install
WORKDIR /
RUN rm -r aws-sdk-cpp
