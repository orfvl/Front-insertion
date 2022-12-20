# Front-insertion
Benchmarking insertion into the front of containers in C++ using google benchmark

To run benchmark create build directory, in build directory run `cmake ..` `cmake --build .` and then run `./main --benchmark_out="test_data.json" --benchmark_format=json`

To plot results run `python plotdata.py`