#ifndef TRACE_FILTER_H
#define TRACE_FILTER_H

struct TraceFilter {
    bool is_filter_on;
    bool is_filter_by_pid;
    int pid; // pid to trace
    GHashTable *is_pid_on_trace_list;
};

#endif /* TRACE_FILTER_H */