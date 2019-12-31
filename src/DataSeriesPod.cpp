#include "DataSeriesPod.h"
#include "Arduino.h"

DataSeriesPod::DataSeriesPod(){
  setName("<name not specified>");
  restart();
}

DataSeriesPod::DataSeriesPod(String id){
  setName(id);
  restart();
}

void DataSeriesPod::restart(){
  averageValue = NAN;
  maximumValue =  NAN;
  minimumValue =  NAN;
  firstValue = NAN;
  mostRecentValue = NAN;
  sampleSize = 0;
  firstValueTimestamp = millis();
  mostRecentValueTimestamp = firstValueTimestamp;
}

void DataSeriesPod::update(double value){
  if(isnan(value)) return;
  if(sampleSize >= 4294967294UL) return;
  sampleSize++;
  if (sampleSize == 1){
    firstValue = value;
    averageValue = value;
    maximumValue = value;
    minimumValue = value;
    firstValueTimestamp=millis();
  }
  mostRecentValueTimestamp=millis();
  mostRecentValue = value;
  averageValue += (value - averageValue) / (double)sampleSize;
  if(value > maximumValue)
    maximumValue = value;
  if(value < minimumValue)
    minimumValue = value;
}

String DataSeriesPod::toString(){
  String retStr = getName();
  retStr += String(" : ");
  if(sampleSize < 0){
    retStr += String("no data yet");
    return retStr;
  }
  retStr += String(getAverageValue(), 3);
  retStr += String(" +/- ");
  retStr += String(getRange()/(double)2, 3);
  return retStr;
}

double DataSeriesPod::getAverageValue(){
  return averageValue;
}

double DataSeriesPod::getMaximumValue(){
  return maximumValue;
}

double DataSeriesPod::getMinimumValue(){
  return minimumValue;
}

double DataSeriesPod::getFirstValue(){
  return firstValue;
}

double DataSeriesPod::getMostRecentValue(){
  return mostRecentValue;
}

double DataSeriesPod::getRange(){
  return maximumValue - minimumValue;
}

double DataSeriesPod::getCentralValue(){
  return (maximumValue + minimumValue) / (double)2.0;
}

unsigned long DataSeriesPod::getSampleSize(){
  return sampleSize;
}

String DataSeriesPod::getName(){
  return name;
}

unsigned long DataSeriesPod::getDuration(){
  return mostRecentValueTimestamp - firstValueTimestamp;
}

void DataSeriesPod::setName(String id){
  name = id;
  name.trim();
}
