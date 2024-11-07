
FROM debian:bullseye-slim

RUN \
  apt-get update && \
  apt-get install -y python3 python3-pip man-db && \
  python3 -m pip install --upgrade pip setuptools && \
  python3 -m pip install norminette c_formatter_42 && \
  apt-get install -y git libreadline-dev make gcc valgrind
