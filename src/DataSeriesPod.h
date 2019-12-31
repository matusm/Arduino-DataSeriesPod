#ifndef DATASERIESPOD_H_INCLUDED
#define DATASERIESPOD_H_INCLUDED
#include "Arduino.h"

class DataSeriesPod{
  
private:
  String name;
  unsigned long sampleSize;
  double averageValue;
  double firstValue;
  double mostRecentValue;
  double maximumValue;
  double minimumValue;
  unsigned long firstValueTimestamp;
  unsigned long mostRecentValueTimestamp;
  
public:
  // ctor
  DataSeriesPod();
  DataSeriesPod(String);
  // methods
  void restart();
  void update(double);
  String toString();
  // getters
  String getName();
  unsigned long getSampleSize();
  double getAverageValue();
  double getFirstValue();
  double getMostRecentValue();
  double getMaximumValue();
  double getMinimumValue();
  double getRange();
  double getCentralValue();
  unsigned long getDuration();
  // setter
  void setName(String);
};

#endif
