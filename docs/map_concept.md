# Concept of how map might work

## Abstract
We need to have an accurate maritime map with accurate coordinates.
Existing libraries are not open-source, which might present future issues.
Hence making our own implementation is both a future "investment", and a
large undertaking.

## Theory
The map is served on a static blue background via basic GLSL shaders,
with a generated grid representing land and a collection of coordinates.
Of which clicking a certain point in a grid would return a valid coordinate.
There are 3 ways to achieve the grid systems

### Runtime generation
This is probably the easiest the program, but doing so in a consistant
and quick matter on embedded systems might be cause of an issue in where the
system is too weak to actually produce the map.


### Compiletime generation
This is trickier to implement but might achieve better results for embedded systems.
However, the issue of displaying the map from compilation is a sticking point.
In anycase we do this, should we do it via JSON, binary format, or SQLite?

### Network based serving
Just no.

click handling can be done with `MouseArea` in QML, so we could link that to a C++ class
that can handle clicking.
