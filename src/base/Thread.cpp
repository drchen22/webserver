#include "base/Thread.h"
#include "base/CurrentThread.h"
#include <assert.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <thread>






Thread::Thread(const ThreadFunc &func, const std::string &name)
    : func_(func), name_(name) {
        thread_ = std::jthread(func_);
        if (thread_.joinable()) {
            thread_.join();
        }
        
    }

Thread::~Thread() {
    if (thread_.joinable()) {
        thread_.detach();
    }

}

void Thread::setDefaultName() {
  if (name_.empty()) {
    name_ = "Default Thread";
  }
}
