# browspot
High-level library that helps you to work with PrimeSense and Kinect sensors.

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/50450204fb704350bd9ea7a3861b36f8)](https://www.codacy.com/app/vagiz.d/browspot-kinect-library?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=vduseev/browspot-kinect-library&amp;utm_campaign=Badge_Grade) 
[![CircleCI](https://circleci.com/gh/vduseev/browspot-kinect-library/tree/master.svg?style=shield)](https://circleci.com/gh/vduseev/browspot-kinect-library/tree/master)

## Project deprication note
Unfortunately, PrimeSense and Kinect structured lights sensors are not manufactured anymore, and there are better options on the market. Also with PrimeSense's acquisition by Apple the OpenNI library upon which ***browspot*** is built has stopped it's evolution. These days it continuous to be maintained by [Structure.io](structure.io) company for backward compatibility. 

Thus, further ***browspot*** development lost it's practical sense. This repository exists as a showcase of some programming techniques and ideas employed during initial development:

* Working with OpenNI API
* Designing higher level API
* Isolating actual sensor interaction library from GUI
* Implementing GUI control panel with QT

## Futher plans

* Add comments explaining larger methods
* Add architecture overview
* Add reasoning behind choosing Qt framework as a foundation
* Add a list of most interesting moments in the code
  - signal-slot usage
  - Qt debug output system
  - ...
* Replace tabs with spaces
