DataSeriesPod (Arduino-DataSeriesPod)
=======================================

A Simple Arduino Data Logging Library.

## DataSeriesPod
This library provides basic functionality for recording and processing data values. It is typically used for preprocessing and data reduction of frequently arriving sensor data. 

## Key features

* Clean API
* Lightweight (small memory footprint)
* No additional dependencies (except Arduino.h)
* Numerically stable mean value computation 

### Constructor

* `DataSeriesPod(string)`
  Creates a new instance of this class taking a name string as the single argument.

### Methods

* `update(double)`
  Records the passed value. By passing NaN the call is without effect. 
  
* `restart()`
  All data recorded so far is discarded to start over. Typically used after consuming the wanted characteristic values of the recording. The passed name is the only property conserved.

### Getters

* `getSampleSize()`
  Returns the number of samples recorded since the last `restart()`.

* `getAverageValue()`
  Returns the arithmetic mean of all values recorded.

* `getMinimumValue()`
  Returns the smallest value recorded.

* `getMaximumValue()`
  Returns the largest value recorded.

* `getRange()`
  Returns the difference between the smallest and largest value recorded.

* `getCentralValue()`
  Returns the mid-range in the data set. This is the arithmetic mean of the maximum and minimum of all recorded values.

* `getFirstValue()`
  Returns the first value recorded following a `restart()`.

* `getMostRecentValue()`
  Returns the most recent value recorded.

* `getDuration()`
  Returns the duration in milliseconds between the recordings of the first and the most recent value.

* `getName()`
  Returns the name string as provided during creation of the object.

### Setters

* `setName(String)`
  Sets a new name string for the object.

### Notes

All getters return NaN for values which are (yet) undefined.

All variables are declared as double. However on the Uno and other ATMEGA based boards this is exactly the same as the float, with no gain in precision. On the Arduino Due, doubles have 8-byte (64 bit) precision.

The data set recorded during the object's life cycle is never accessible; moreover it is not even stored internally. Only the selected characteristic values are accessible through getters.

The arithmetic mean is computed in a numerically stable way. For details see https://diego.assencio.com/?index=c34d06f4f4de2375658ed41f70177d59

### Usage

Consult the provided examples which show the use of this class.

