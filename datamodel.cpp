#include "datamodel.h"
#include <stdlib.h>
static DataModel* s_DataModel;
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
