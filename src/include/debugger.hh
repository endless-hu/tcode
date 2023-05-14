#pragma once

// #ifdef LOGGER

#include <ctime>
#include <string>
#include <vector>

using cstr = const char *;

static constexpr cstr PastLastSlash(cstr a, cstr b) {
  return *a == '\0'  ? b
         : *b == '/' ? PastLastSlash(a + 1, a + 1)
                     : PastLastSlash(a + 1, b);
}

static constexpr cstr PastLastSlash(cstr a) { return PastLastSlash(a, a); }

#define __SHORT_FILE__                            \
  ({                                              \
    constexpr cstr sf__{PastLastSlash(__FILE__)}; \
    sf__;                                         \
  })

#define LOG_LOG_TIME_FORMAT "%Y-%m-%d %H:%M:%S"
#define LOG_OUTPUT_STREAM stdout

// Output log message header in this format: [type] [file:line:function] time -
// ex: [ERROR] [somefile.cpp:123:doSome()] 2008/07/06 10:00:00 -
inline void OutputLogHeader(const char *file, int line, const char *func) {
  time_t t = ::time(nullptr);
  tm *curTime = localtime(&t);  // NOLINT
  char time_str[32];            // FIXME
  ::strftime(time_str, 32, LOG_LOG_TIME_FORMAT, curTime);
  // PAVLO: DO NOT CHANGE THIS
  ::fprintf(LOG_OUTPUT_STREAM, "%s [%s:%d:%s] - ", time_str, file, line, func);
}

#define LOG_INFO(...)                                      \
  OutputLogHeader(__SHORT_FILE__, __LINE__, __FUNCTION__); \
  ::fprintf(LOG_OUTPUT_STREAM, __VA_ARGS__);               \
  fprintf(LOG_OUTPUT_STREAM, "\n");                        \
  ::fflush(stdout)

// #endif
