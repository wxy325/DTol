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
    :allShapes(Vector<Shape*>())
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
