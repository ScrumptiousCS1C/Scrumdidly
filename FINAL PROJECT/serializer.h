#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QMap>
#include "vector.h"
#include "Shape.h"
#include "parser.h"

extern const QMap<ShapeNames, std::string> INPUT_SHAPE_NAMES;

void serializer(std::string fileName, scrumptious::Vector<Shape<int>*> myShapes);

#endif // SERIALIZER_H
