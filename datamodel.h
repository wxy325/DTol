#ifndef DATAMODEL_H
#define DATAMODEL_H
#include <string>
#include <vector>
class Shape;
//class std::string;
class DataModel
{
public:
    static DataModel* shareDataModel();
    void sendMessage(std::string message);
    ~DataModel();
private:
    DataModel();
    std::vector<Shape*> allShapes;
};

#endif // DATAMODEL_H
