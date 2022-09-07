#ifndef TRACE_FILTER_H
#define TRACE_FILTER_H

struct TraceFilter {
    bool is_filter_on;
    bool is_filter_by_pid;
    int pid; // pid to trace
};

#endif /* TRACE_FILTER_H */