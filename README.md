# AnomalyDetectionCpp

[![DOI](https://zenodo.org/badge/195661645.svg)](https://zenodo.org/badge/latestdoi/195661645)

## Current methods for anomaly detection

* Three-sigma rule.
* Median absolute deviation.

## Build

```
mkdir build
cd build
cmake ..
make
```

## Usage

* Three-sigma rule (global mean/variance):
    ```
    ./AnomalyDetectionCpp example.csv tsg
    ```
    
* Three-sigma rule (rolling mean/variance):
    ```
    ./AnomalyDetectionCpp example.csv tsr 15
    ```

* Median absolute deviation:
    ```
    ./AnomalyDetectionCpp example.csv mad
    ```
