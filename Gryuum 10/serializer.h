#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QMap>
#include "vector.h"
#include "Shape.h"

enum ShapeNames
{
    LINE      = 1,
    POLYLINE  = 2,
    POLYGON   = 3,
    RECTANGLE = 4,
    SQUARE    = 5,
    ELLIPSE   = 6,
    CIRCLE    = 7,
    TEXT      = 8,
};

extern const QMap<ShapeNames, std::string> INPUT_SHAPE_NAMES;

scrumptious::Vector<Shape<int>*> LoadFile();

#endif // SERIALIZER_H
