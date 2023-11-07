#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void parser()
{
    string temp;
    ifstream shapesFile("shapes.txt");
    while (shapesFile)
    {
        getline(shapesFile, temp, ':');

        if (temp == "ShapeId")
        { // ShapeId: # [int, unique]
            // shapesFile >> ShapeID;
        } else if (temp == "ShapeType")
        { // ShapeType: Line, Polyline, Polygon, Rectangle, Square[rectangle, l=w], Ellipse, Circle[ellipse, a=b], Text
            // getline(shapesFile, ShapeType, '\n');
        } else if (temp == "ShapeDimensions")
        {

        } else if (temp == "PenColor")
        { // PenColor: white, black, red, green, blue, cyan, magenta, yellow, gray [Qt::GlobalColor enum]

        } else if (temp == "PenWidth")
        { // PenWidth: 0 - 20 [int]
            // shapesFile >> PenWidth;
        } else if (temp == "PenStyle")
        { // PenStyle: NoPen, SolidLine, DashLine, DotLine, DashDotLine, DashDotDotLine [Qt::PenStyle enum]

        } else if (temp == "PenCapStyle")
        { // PenCapStyle: FlatCap, SquareCap, RoundCap [Qt::PenCapStyle enum]

        } else if (temp == "PenJoinStyle")
        { // PenJoinStyle: MiterJoin, BevelJoin, RoundJoin [Qt::PenJoinStyle enum]

        } else if (temp == "BrushColor")
        { // BrushColor: white, black, red, green, blue, cyan, magenta, yellow, gray [Qt::GlobalColor enum]

        } else if (temp == "BrushStyle")
        { // BrushStyle: SolidPattern, HorPattern, VerPattern, NoBrush [Qt::BrushStyle enum]

        } else if (temp == "TextString")
        { // TextString: text to be displayed [string]

        } else if (temp == "TextColor")
        { // TextColor: white, black, red, green, blue, cyan, magenta, yellow, gray [Qt::GlobalColor enum]

        } else if (temp == "TextAlignment")
        { // TextAlignment: AlignLeft, AlignRight, AlignTop, AlignBottom, AlignCenter [Qt::AlignmentFlag enum]

        } else if (temp == "TextPointSize")
        { // TextPointSize: -1 to 50 [int]
            // shapesFile >> TextPointSize;
        } else if (temp == "TextFontFamily")
        { // TextFontFamily: Comic Sans MS, Courier, Helvetica, Times [string]

        } else if (temp == "TextFontStyle")
        { // TextFontStyle: StyleNormal, StyleItalic, StyleOblique [QFont::Style enum]

        } else if (temp == "TextFontWeight")
        { // TextFontWeight: Thin, Light, Normal, Bold [QFont::Weight enum]

        }
    }
}
