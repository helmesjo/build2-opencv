# build2-opencv - <SUMMARY>

This is a `build2` package reporitory for [`build2-opencv`](https://<UPSTREAM-URL>),
a <SUMMARY-OF-FUNCTIONALITY>.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`build2-opencv` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](<PACKAGE>/PACKAGE-README.md) file.

The development setup for `build2-opencv` uses the standard `bdep`-based workflow.
For example:

```
git clone .../build2-opencv.git
cd build2-opencv

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
