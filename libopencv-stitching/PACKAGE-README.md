# libopencv-stitching - A C++ library

This is a `build2` package for the [`<UPSTREAM-NAME>`](https://<UPSTREAM-URL>)
C++ library. It provides <SUMMARY-OF-FUNCTIONALITY>.


## Usage

To start using `libopencv-stitching` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-stitching ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libopencv-stitching%lib{<TARGET>}
```


## Importable targets

This package provides the following importable targets:

```
lib{<TARGET>}
```

<DESCRIPTION-OF-IMPORTABLE-TARGETS>


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libopencv_stitching.<VARIABLE> ?= false
```

<DESCRIPTION-OF-CONFIG-VARIABLES>
