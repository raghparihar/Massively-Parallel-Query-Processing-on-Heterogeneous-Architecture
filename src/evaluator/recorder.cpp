#include "evaluator/recorder.h"

namespace ursus {
namespace evaluator {

/**
 * @brief Return the singleton recorder instance
 */
Recorder& Recorder::GetInstance(){
  static Recorder recorder;
  return recorder;
}

void Recorder::TimeRecordStart(){
  cudaEventCreate(&start_event);
  cudaEventCreate(&stop_event);
  cudaEventRecord(start_event, 0);
}

float Recorder::TimeRecordEnd(){
  cudaEventRecord(stop_event, 0) ;
  cudaEventSynchronize(stop_event) ;
  cudaEventElapsedTime(&elapsed_time, start_event, stop_event);
  return elapsed_time;
}


} // End of evaluator namespace
} // End of ursus namespace