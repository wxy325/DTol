#include "datamodel.h"
#include <stdlib.h>
#include <String>

static DataModel* s_DataModel;
using namespace std;
DataModel::DataModel()
{

}

DataModel* DataModel::shareDataModel()
{
    if (s_DataModel == NULL)
    {
        s_DataModel = new DataModel();
    }
    return s_DataModel;
}

void DataModel::sendMessage(string message)
{
    //发送消息
}
