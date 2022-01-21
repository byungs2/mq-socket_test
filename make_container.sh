#!/bin/bash
sudo docker run --gpus all -it --name mq_test -v /home/byunghun/workspace/mq_test:/home/workspace -e GST_DEBUG=2 nn_rebuild:1.0 /bin/bash
