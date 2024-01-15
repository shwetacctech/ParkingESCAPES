#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TrafficJam.h"
#include "OpenGLWindow.h"
#include <Point3D.h>
#include <Car.h>

class TrafficJam : public QMainWindow
{
    Q_OBJECT

public:
    TrafficJam(QWidget *parent = nullptr);//Constructor
    ~TrafficJam(); //Destructor
    void setupUi(); //sets the ui 

private slots:
    void readOBJ(); //reads obj file of car
    void sceneStatic(); //renders static scene of cars
    void UpperMove(); //moves the car to upper i.e +y direction
    void DownMove(); //moves the car to lower i.e -y direction
    void LeftMove(); //moves the car to left direction i.e, -x
    void RightMove(); //moves the car to right direction i.e, +x
    void selectCar(); //select a specific car from dropdown
    void stop();//stops the game
    


private:
   //UI objects of QT 
    OpenGLWindow* mRenderer;
    QWidget* mCentralWidget;
    QVBoxLayout* mVerticalLayout;
    QHBoxLayout* mHorizontalLayout;
    QPushButton* mStart_button;
    QPushButton* mTop_button;
    QPushButton* mDown_button;
    QPushButton* mStop_button;
    QPushButton* mSelect_button;
    QMenu* mDropdownMenu;
    QAction* mCar1;
    QAction* mCar2;
    QAction* mCar3;
    QAction* mCar4;
    QAction* mCar5;
    QAction* mCar6;
    QAction* mCar7;
    QAction* mCar8;
    std::vector<Point3D> mPoints;
    std::vector<Point3D> mNewPoints;
    std::vector<Point3D> mTranslatedPoints ;
    std::vector<Car> mCarContainer;                          
    std::vector<float> mObjVertices;
    std::vector<float> mObjColors;
    QVector<GLfloat> mVertices;
    QVector<GLfloat> mColors;
    int mCar_no = 0;
    bool mMovable=true;
    bool mRightMove=true;
    bool mForwardMove = true;
    bool mLeftMove = true;
    bool mStartFlag = true;
    bool mSetFlag;
private:
    void addVerticesColor(); //to add Vertices along with color in mVertices and mColors to further render in OpenGLWindow
    void addVertices(); //to add Vertices in mVertices to further render in OpenGLWindow
    void bbox_creator();
    void readTxt();
    void isMovable();
    void isMovableAroundBoundaryY();
    void isMovableAroundBoundaryX();
};
