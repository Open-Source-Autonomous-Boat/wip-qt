#include <QRunnable>
#pragma once

template<typename T>
class CleanJob: public QRunnable {
public:
  CleanJob(T *local_object): object(local_object) {};
  void run() override {
    delete this->object;
  };
private:
  T *object;
};

