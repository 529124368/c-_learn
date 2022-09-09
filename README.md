# c-_learn
c++学习

安装静态库
vcpkg install drogon:x86-windows-static   


c++ 名词学习

1. 委托构造函数
2. trailing return type
3. 前置参数
4. asan 内存泄露分析

汇编学习nasm

1. nasm -felf64 function.asm -o function.obj   linux下编译64位
2. nasm -fwin64 function.asm -o function.obj   win下编译64位


https://qiita.com/funawo06/items/cfa25fc642cce2e1ce8f


docker 
FROM elasticsearch:7.16.2

RUN chmod 777 /tmp
COPY ./data/ /tmp
RUN cd /tmp
RUN chown -R 1000:0 /usr/share/elasticsearch/
RUN echo 'discovery.type: single-node' >> config/elasticsearch.yml
RUN apt-get update \
    && apt-get install procps -y \
    && apt-get install httping -y \
    && sh /usr/local/bin/docker-entrypoint.sh elasticsearch -d \
    && while ! httping -qc1 http://localhost:9200 ; do sleep 1 ; done \
    && sh /tmp/preload.sh \
    && apt-get clean


curl -H 'Content-Type: application/x-ndjson' -XPOST 'localhost:9200/shakespeare/_bulk?pretty' --data-binary @shakespeare.json

version: '3.8'
services:
  es02:
      container_name: es02
      build: ./es
      environment:
        - xpack.security.enabled=false
        - discovery.type=single-node
        - xpack.ml.enabled=false
      ulimits:
        memlock:
          soft: -1
          hard: -1
      volumes:
        - ./es/data:/tmp
      ports:
        - 9200:9200

  kibana:
      container_name: kibana-ts
      image: docker.elastic.co/kibana/kibana:7.16.2
      ports:
        - 5601:5601
      environment:
        - ELASTICSEARCH_HOSTS=http://es02:9200

