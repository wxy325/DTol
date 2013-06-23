#ifndef DATAMODEL_H
#define DATAMODEL_H

class DataModel
{
public:
    static DataModel* shareDataModel();
private:
    DataModel();

};

#endif // DATAMODEL_H
