/* Copyright (c) 2017-2021, Hans Erik Thrane */

#pragma once

#include <flatbuffers/flatbuffers.h>

#include <chrono>
#include <fstream>
#include <string_view>

#include "roq/api.h"

namespace roq {
namespace samples {
namespace import {

class Processor final {
 public:
  explicit Processor(const std::string_view &path);

  Processor(Processor &&) = default;
  Processor(const Processor &) = delete;

  ~Processor();

  void dispatch();

 protected:
  MessageInfo create_message_info(std::chrono::nanoseconds timestamp_utc);

  template <typename T>
  void process(const T &value, std::chrono::nanoseconds timestamp);

 private:
  uint64_t seqno_ = 0;
  flatbuffers::FlatBufferBuilder builder_;
  std::ofstream file_;
};

}  // namespace import
}  // namespace samples
}  // namespace roq
