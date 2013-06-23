#ifndef DATAMODEL_H
#define DATAMODEL_H
#include <string>
//class std::string;
class DataModel
{
public:
    static DataModel* shareDataModel();
    void sendMessage(std::string message);
private:
    DataModel();
};

#endif // DATAMODEL_H
