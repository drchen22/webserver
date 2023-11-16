#pragma once

class noncopyable {
public:
    noncopyable() = default;
    ~noncopyable() = default;

    noncopyable(const noncopyable&) = delete;
    noncopyable& operator=(const noncopyable&) = delete;
};

// class noncopyable {
//  protected:
//   noncopyable() {}
//   ~noncopyable() {}

//  private:
//   noncopyable(const noncopyable&);
//   const noncopyable& operator=(const noncopyable&);
// };