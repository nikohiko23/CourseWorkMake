FROM ubuntu:20.04

RUN apt update && apt install -y g++ make build-essential

COPY . /mybuild
WORKDIR /mybuild


RUN chmod +x build.sh && ./build.sh

CMD ["./bin/mybuild"]