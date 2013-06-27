#include "datamodel.h"
#include <stdlib.h>
#include <String>
#include "shape.h"

static DataModel* s_DataModel;
using namespace std;

DataModel* DataModel::shareDataModel()
{
    if (s_DataModel == NULL)
    {
        s_DataModel = new DataModel();
    }
    return s_DataModel;
}

DataModel::DataModel()
    :allShapes(vector<Shape*>())
{

}


void DataModel::sendMessage(string message)
{
    //发送消息
}

DataModel::~DataModel()
{
    for (int i = 0; i < this->allShapes.size(); i++)
    {
        if (allShapes[i])
        {
            delete allShapes[i];
        }
    }
}

//Shape
void DataModel::drawAllShape(QPainter& painter)
{
    for (int i = 0; i < this->allShapes.size(); i++)
    {
        Shape* shape = this->allShapes[i];
        shape->draw(painter);
    }
}

void DataModel::addShape(Shape* shape)
{
    this->allShapes.push_back(shape);
}
