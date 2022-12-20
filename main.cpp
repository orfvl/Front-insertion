#include <list>
#include <vector>
#include <random>
#include <benchmark/benchmark.h>

static void bm_vec(benchmark::State &state) {
    for (auto _ : state)
    {
        state.PauseTiming();
        // std::mt19937 rng;
        // rng.seed(std::random_device()());
        // std::uniform_int_distribution<int> dist(0,255);
        std::vector<int> v ;
        benchmark::DoNotOptimize(v.data());
        v.reserve(1);
        //v.reserve(state.range(0));
        state.ResumeTiming();
        for (int i = 0; i < state.range(0); i++)
        {
            v.insert(v.begin(), 1);
        }
        benchmark::ClobberMemory();
    }
}

BENCHMARK(bm_vec)
//->RangeMultiplier(2)->Range(8, 8<<10)->DenseRange(1000,100000,1000);
->DenseRange(20,2000,20);
// static void bm_vec_rev(benchmark::State &state) {
//     for (auto _ : state)
//     {
//         state.PauseTiming();
//         std::vector<int> v;
//         benchmark::DoNotOptimize(v.data());
//         state.ResumeTiming();
//         for (int i = 0; i < state.range(0); i++)
//         {
//             v.push_back(0);
//         }
//         std::reverse(v.begin(), v.end());
//         benchmark::ClobberMemory();
//     }
// }


// BENCHMARK(bm_vec_rev)->RangeMultiplier(2)->Range(8, 8<<15);


static void bm_list(benchmark::State &state) {
    
    for (auto _ : state)
    {
        state.PauseTiming();
        std::list<int> v ;
        benchmark::DoNotOptimize(v.front());
        state.ResumeTiming();
        for (int i = 0; i < state.range(0); i++)
        {
            v.insert(v.begin(), 1);
        }
        
    }
}

BENCHMARK(bm_list)->DenseRange(20,2000,20);
//->RangeMultiplier(2)->Range(8, 8 << 10) ->DenseRange(1000,100000,1000);


BENCHMARK_MAIN();
