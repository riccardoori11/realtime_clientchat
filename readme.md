High-performance WebSocket server in C++ using µWebSockets that handles 12,000 connections over 30 seconds (400/sec arrival rate) with zero failures, achieving a p95 latency of 17ms and p99 of 59ms at 159 messages/sec throughput.


Run it using
cmake -B build && cmake --build build && ./build/server



Metrics
Completed 12,000
Failed 0
Success rate 100%

Latency Percentile Value (session length in ms)
Min     0.9
Median  6.0
Mean    8.0
p95     17.3
p99     58.6
Max     216.4

Throughput
Messages sent   12,000
Send rate       159/sec



