#pragma once

#include <thread>
#include <sys/syscall.h>
#include <unistd.h>
#include <functional>
#include <memory>
#include <string>
#include "noncopyable.h"

class Thread : noncopyable {
public:
    typedef std::function<void()> ThreadFunc;
    explicit Thread(const ThreadFunc&, const std::string& name = std::string());

  ~Thread();

    
  const std::string& name() const { return name_; }

 private:
  void setDefaultName();
  std::jthread thread_ {};
  ThreadFunc func_;
  std::string name_;
};