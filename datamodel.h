#ifndef DATAMODEL_H
#define DATAMODEL_H
#include <string>
#include <vector>
#include <QPainter>

class Shape;
//class std::string;
class DataModel
{
public:
    static DataModel* shareDataModel();
    void sendMessage(std::string message);
    ~DataModel();

    void drawAllShape(QPainter& painter);
    void addShape(Shape* shape);    //shape需使用动态内存分配

private:
    DataModel();
    std::vector<Shape*> allShapes;
};

#endif // DATAMODEL_H
