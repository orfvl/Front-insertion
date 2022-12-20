# Front-insertion
Benchmarking insertion into the front of containers in C++ using google benchmark

To run benchmark create build directory, in build directory run `cmake ..` `cmake --build .` and then run `./main --benchmark_out="test_data.json" --benchmark_format=json`

To plot results run `python plotdata.py`

One can see the disered result that for small number of insertions vector is faster.

On a good day when my system was not noise a got the following result: 
![alt text](https://github.com/orfvl/Front-insertion/blob/main/container_insert_front_good.png "good results")

Normally it looks like this:
![alt text](https://github.com/orfvl/Front-insertion/blob/main/container_insert_front.png"normal results")

