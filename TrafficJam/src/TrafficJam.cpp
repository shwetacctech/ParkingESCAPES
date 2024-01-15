#include "stdafx.h"
#include "BBOX.h"
#include "TrafficJam.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <Transformations.h>
#include <CollisionDetection.h>

TrafficJam::TrafficJam(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    connect(mStart_button, &QPushButton::clicked, this, &TrafficJam::sceneStatic);
    connect(mTop_button, &QPushButton::clicked, this, &TrafficJam::UpperMove);
    connect(mDown_button, &QPushButton::clicked, this, &TrafficJam::DownMove);
    connect(mStop_button, &QPushButton::clicked, this, &TrafficJam::stop);
    connect(mSelect_button, &QPushButton::clicked, this, &TrafficJam::selectCar);
    connect(mRenderer, SIGNAL(shapeUpdate()), mRenderer, SLOT(update()));
}
TrafficJam::~TrafficJam()
{
}
void TrafficJam::setupUi()
{

    resize(944, 895);
    mCentralWidget = new QWidget(this);
    mCentralWidget->setObjectName("centralWidget");

    // Vertical layout to hold the renderer widget
    mVerticalLayout = new QVBoxLayout(mCentralWidget);
    mVerticalLayout->setSpacing(6);
    mVerticalLayout->setContentsMargins(11, 11, 11, 11);
    mVerticalLayout->setObjectName("mVerticalLayout");

    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setObjectName("openGLWidget");
    mVerticalLayout->addWidget(mRenderer, 3);

    // Horizontal layout to hold the buttons
    mHorizontalLayout = new QHBoxLayout();
    mHorizontalLayout->setSpacing(6);
    mHorizontalLayout->setContentsMargins(11, 11, 11, 11);

    mStart_button = new QPushButton("Start", mCentralWidget);
    mStart_button->setObjectName("mStart_button");
    mHorizontalLayout->addWidget(mStart_button);

    mTop_button = new QPushButton("FORWARD", mCentralWidget);
    mTop_button->setObjectName("mTop_button");
    mHorizontalLayout->addWidget(mTop_button);

    mDown_button = new QPushButton("BACKWARD", mCentralWidget);
    mDown_button->setObjectName("mDown_button");
    mHorizontalLayout->addWidget(mDown_button);

    mSelect_button = new QPushButton("SELECT", mCentralWidget);
    mSelect_button->setObjectName("pushButton");
    mHorizontalLayout->addWidget(mSelect_button);

    mDropdownMenu = new QMenu(mSelect_button);
    mCar1 = mDropdownMenu->addAction("Car1");
    mCar2 = mDropdownMenu->addAction("Car2");
    mCar3 = mDropdownMenu->addAction("Car3");
    mCar4 = mDropdownMenu->addAction("Car4");
    mCar5 = mDropdownMenu->addAction("Car5");
    mCar6 = mDropdownMenu->addAction("Car6");
    mCar7 = mDropdownMenu->addAction("Car7");
    mCar8 = mDropdownMenu->addAction("Car8");

    mStop_button = new QPushButton("STOP", mCentralWidget);
    mStop_button->setObjectName("pushButton");
    mHorizontalLayout->addWidget(mStop_button);

    mVerticalLayout->addLayout(mHorizontalLayout);
    setCentralWidget(mCentralWidget);


    QMetaObject::connectSlotsByName(this);
} 
void TrafficJam::sceneStatic() {
    if (mStartFlag == true) {
        readOBJ();
        readTxt();
        std::vector<Point3D> mCarPoints;
        std::vector<float> mCarColors;
        for (int i = 0; i < mPoints.size(); i++) {
            Point3D P(mPoints[i].X() - 30, mPoints[i].Y() + 50, mPoints[i].Z());
            mCarPoints.push_back(P);

        }
        for (int i = 0; i < mObjColors.size(); i+=3) {
            mCarColors.push_back(1.0);
            mCarColors.push_back(1.0);
            mCarColors.push_back(0.0);
            
        }
        Car c1(mCarPoints, mCarColors, true);
        mCarContainer.push_back(c1);
        mCarPoints.clear();
        mCarColors.clear();
        for (int i = 0; i < mPoints.size(); i++) {
            Point3D P(mPoints[i].X(), mPoints[i].Y() + 50, mPoints[i].Z());;
            mCarPoints.push_back(P);

        }
        for (int i = 0; i < mObjColors.size(); i+=3) {
            mCarColors.push_back(0);
            mCarColors.push_back(1);
            mCarColors.push_back(1);

        }
        Car c2(mCarPoints, mCarColors, true);
        mCarContainer.push_back(c2);
        mCarPoints.clear();
        mCarColors.clear();

        for (int i = 0; i < mNewPoints.size(); i++) {
            Point3D P(mNewPoints[i].X() + 30, mNewPoints[i].Y() + 40, mNewPoints[i].Z() + 12);;
            mCarPoints.push_back(P);

        }
        for (int i = 0; i < mObjColors.size(); i+=3) {
           // mCarColors.push_back(mObjColors[i]);
            mCarColors.push_back(0);
            mCarColors.push_back(1);
            mCarColors.push_back(1);

        }
        Car c3(mCarPoints, mCarColors, false);
        mCarContainer.push_back(c3);
        mCarPoints.clear();
        mCarColors.clear();
        for (int i = 0; i < mPoints.size(); i++) {
            Point3D P(mPoints[i].X() - 30, mPoints[i].Y(), mPoints[i].Z());;
            mCarPoints.push_back(P);

        }
        for (int i = 0; i < mObjColors.size(); i+=3) {
            mCarColors.push_back(1);
            mCarColors.push_back(1);
            mCarColors.push_back(1);


        }
        Car c4(mCarPoints, mCarColors, true);
        mCarContainer.push_back(c4);
        mCarPoints.clear();
        mCarColors.clear();
        for (int i = 0; i < mPoints.size(); i++) {
            Point3D P(mPoints[i].X(), mPoints[i].Y(), mPoints[i].Z());;
            mCarPoints.push_back(P);

        }
        for (int i = 0; i < mObjColors.size(); i += 3) {
            mCarColors.push_back(0);
            mCarColors.push_back(1);
            mCarColors.push_back(1);

        }

        Car c5(mCarPoints, mCarColors, true);
        mCarContainer.push_back(c5);
        mCarPoints.clear();
        mCarColors.clear();
        for (int i = 0; i < mPoints.size(); i++) {
            Point3D P(mPoints[i].X() + 30, mPoints[i].Y(), mPoints[i].Z());;
            mCarPoints.push_back(P);

        }
        for (int i = 0; i < mObjColors.size(); i++) {
            mCarColors.push_back(0);
            mCarColors.push_back(1);
            mCarColors.push_back(1);


        }
        Car c6(mCarPoints, mCarColors, true);
        mCarContainer.push_back(c6);
        mCarPoints.clear();
        mCarColors.clear();
        for (int i = 0; i < mNewPoints.size(); i++) {
            Point3D P(mNewPoints[i].X() + 30, mNewPoints[i].Y() + 70, mNewPoints[i].Z() + 12);
            mCarPoints.push_back(P);

        }
        for (int i = 0; i < mObjColors.size(); i++) {
            mCarColors.push_back(1);
            mCarColors.push_back(1);
            mCarColors.push_back(1);

        }
        Car c7(mCarPoints, mCarColors, false);
        mCarContainer.push_back(c7);
        mCarPoints.clear();
        mCarColors.clear();
        for (int i = 0; i < mNewPoints.size(); i++) {
            Point3D P(mNewPoints[i].X(), mNewPoints[i].Y() + 40, mNewPoints[i].Z() + 12);
            mCarPoints.push_back(P);

        }
        for (int i = 0; i < mObjColors.size(); i++) {
            mCarColors.push_back(1);
            mCarColors.push_back(0);
            mCarColors.push_back(0);
            
        }
        Car c8(mCarPoints, mCarColors, false);
        mCarContainer.push_back(c8);
        mCarPoints.clear();
        mCarColors.clear();
        addVerticesColor();

        mObjVertices.clear();
        mObjColors.clear();

        mRenderer->setVectorOfLines(mVertices);
        mRenderer->setColorOfLines(mColors);
        mStartFlag = false;
    }
}
void TrafficJam::readTxt() {
      std::ifstream inputFile("D:\\Shweta_Workplace\\TrafficJam\\Output.txt"); // Open the input file

        // Check if the file is opened successfully
        if (!inputFile.is_open()) {
            std::cout << "Error opening the file!" << std::endl;
            
        }

        std::string line;
        
        double x, y, z;
        // Read the file line by line and print each line
        while (inputFile >> x >> y >> z) {
            Point3D p1(x, y, z);
            mNewPoints.push_back(p1);
        }

        // Close the file
        inputFile.close();
 
}
void TrafficJam::readOBJ() {
    
    std::string filePath = "D:\\Shweta_Workplace\\TrafficJam\\TrafficJam\\Resources\\11497_Car_v2.obj";
    std::ifstream dataFile;
    dataFile.open(filePath);
    if (!dataFile.is_open()) {
        std::cout << "File not exit" << std::endl;
        return;
    }
    
    std::string line;
    while (std::getline(dataFile, line)) {
        std::istringstream iss(line);
        std::string token;
        iss >> token;
        if (token == "v") {
            float x, y, z;
            iss >> x >> y >> z;
            mObjVertices.push_back(x *0.1);
            mObjVertices.push_back(y * 0.1);
            mObjVertices.push_back(z * 0.1);
            Point3D p(x * 0.1, y * 0.1, z * 0.1);
            mPoints.push_back(p);
            mObjColors.push_back(1.0);
            mObjColors.push_back(1.0);
            mObjColors.push_back(1.0);
        
        }  
    }
    
}
void TrafficJam::LeftMove() {
    if (mCarContainer[mCar_no].getAlignment() == false) {
        Transformations tf;
        mTranslatedPoints = tf.translate_X_Left(mCarContainer[mCar_no].getVertices());
        isMovableAroundBoundaryX();
        if (mSetFlag) {
            mCarContainer[mCar_no].setVertices(mTranslatedPoints);
            addVertices();
            mRenderer->setVectorOfLines(mVertices);
        }
        isMovable();
        if (mMovable) {
            mVertices.clear();
            addVertices();
            mRenderer->setVectorOfLines(mVertices);
        }
        else {
            mTranslatedPoints = tf.translate_X_Right(mCarContainer[mCar_no].getVertices());
            isMovableAroundBoundaryX();
            if (mSetFlag) {
                mCarContainer[mCar_no].setVertices(mTranslatedPoints);
                mVertices.clear();
                addVertices();
                mRenderer->setVectorOfLines(mVertices);
            }
        }
    }   
   
}
void TrafficJam::RightMove() {
    if (mCarContainer[mCar_no].getAlignment() == false) {
        Transformations tf;
        mTranslatedPoints = tf.translate_X_Right(mCarContainer[mCar_no].getVertices());
        isMovableAroundBoundaryX();
        if (mSetFlag) {
            mCarContainer[mCar_no].setVertices(mTranslatedPoints);
            mVertices.clear();
            addVertices();
            mRenderer->setVectorOfLines(mVertices);
        }
        isMovable();
        if (mMovable) {
            mVertices.clear();
            addVertices();
            mRenderer->setVectorOfLines(mVertices);
        }
        else {
            mTranslatedPoints = tf.translate_X_Left(mCarContainer[mCar_no].getVertices());
            isMovableAroundBoundaryX();
            if (mSetFlag) {
                mCarContainer[mCar_no].setVertices(mTranslatedPoints);
                addVertices();
                mRenderer->setVectorOfLines(mVertices);
            }
        }
    }
}
void TrafficJam::UpperMove() {
    
    if (mCarContainer[mCar_no].getAlignment()) {
        Transformations tf;
        mTranslatedPoints = tf.translate_Y_UP(mCarContainer[mCar_no].getVertices());
        isMovableAroundBoundaryY();
        if (mSetFlag) {
            mCarContainer[mCar_no].setVertices(mTranslatedPoints);
            addVertices();
            mRenderer->setVectorOfLines(mVertices);
        }
        isMovable();
        if (mMovable) {
            mVertices.clear();
            addVertices();
            mRenderer->setVectorOfLines(mVertices);
        }
        else {
            mTranslatedPoints = tf.translate_Y_Down(mCarContainer[mCar_no].getVertices());
            isMovableAroundBoundaryY();
            if (mSetFlag) {
                mCarContainer[mCar_no].setVertices(mTranslatedPoints);
                mVertices.clear();
                addVertices();
                mRenderer->setVectorOfLines(mVertices);
            }
        }
    }
    
    else {
        if (mLeftMove == false) {
            LeftMove();
        }LeftMove();
        
    }
    
}
void TrafficJam::DownMove() {
    if (mCarContainer[mCar_no].getAlignment()) {
        Transformations tf;
        mTranslatedPoints = tf.translate_Y_Down(mCarContainer[mCar_no].getVertices());
        isMovableAroundBoundaryY();
        if (mSetFlag) {
            mCarContainer[mCar_no].setVertices(mTranslatedPoints);
            mVertices.clear();
            addVertices();
            mRenderer->setVectorOfLines(mVertices);
        }
        isMovable();
        if (mMovable) {
            mVertices.clear();
            addVertices();
            mRenderer->setVectorOfLines(mVertices);
        }
        else {
            mTranslatedPoints = tf.translate_Y_UP(mCarContainer[mCar_no].getVertices());
            isMovableAroundBoundaryY();
            if (mSetFlag) {
                mCarContainer[mCar_no].setVertices(mTranslatedPoints);
                mVertices.clear();
                addVertices();
                mRenderer->setVectorOfLines(mVertices);
            }
        }
        
    }
    else {
        if (mRightMove == false) {
            RightMove();

        }RightMove();
    }
        
}
void TrafficJam::stop() {
    mPoints.clear();
    mCarContainer.clear();
    mVertices.clear();
    mColors.clear();
    mRenderer->setVectorOfLines(mVertices);
    mRenderer->setColorOfLines(mColors);
    mStartFlag = true;
}
void TrafficJam::selectCar() {
    QPoint pos = mSelect_button->mapToGlobal(QPoint(0, mSelect_button->height()));

    connect(mCar1, &QAction::triggered, this, [=]() {
        mCar_no = 0;

        });
    connect(mCar2, &QAction::triggered, this, [=]() {
        mCar_no = 1;
        });

    connect(mCar3, &QAction::triggered, this, [=]() {
        mCar_no = 2;
        });
    connect(mCar4, &QAction::triggered, this, [=]() {
        mCar_no = 3;
        });
    connect(mCar5, &QAction::triggered, this, [=]() {
        mCar_no = 4;
        });
    connect(mCar6, &QAction::triggered, this, [=]() {
        mCar_no = 5;
        });
    connect(mCar7, &QAction::triggered, this, [=]() {
        mCar_no = 6;
        });
    connect(mCar8, &QAction::triggered, this, [=]() {
        mCar_no = 7;
        });


    mDropdownMenu->exec(pos);
    
    //mRenderer->fetchData(mCarContainer);
    //mCar_no = mRenderer->getCarNo();

}
void TrafficJam::addVertices() {
    for (int i = 0; i < mCarContainer.size(); i++) {
        std::vector<Point3D> carVertices = mCarContainer[i].getVertices();
        std::vector<float> carColors = mCarContainer[i].getColors();
        for (int j = 0; j < carVertices.size(); j++) {
            mVertices << carVertices[j].X() << carVertices[j].Y() << carVertices[j].Z();
        }
        mVertices << -50 << 65 << 0;
        mVertices << -50 << -20 << 0;
        mVertices << -50 << 65 << 0;
        mVertices << 60 << 65 << 0;
        mVertices << 60 << 65 << 0;
        mVertices << 60 << -20 << 0;

    }
}
void TrafficJam::addVerticesColor() {
    for (int i = 0; i < mCarContainer.size(); i++) {
        std::vector<Point3D> carVertices = mCarContainer[i].getVertices();
        std::vector<float> carColors = mCarContainer[i].getColors();
        for (int j = 0; j < carVertices.size(); j+=3) {
            mVertices << carVertices[j].X() << carVertices[j].Y() << carVertices[j].Z();
            mVertices << carVertices[j+1].X() << carVertices[j+1].Y() << carVertices[j+1].Z();
            mVertices << carVertices[j+2].X() << carVertices[j+2].Y() << carVertices[j+2].Z();
            mVertices << carVertices[j].X() << carVertices[j].Y() << carVertices[j].Z();
        }
        mVertices << -50 << 65 << 0;
        mVertices << -50 << -20 << 0;
        mVertices << -50 << 65 << 0;
        mVertices << 60 << 65 << 0;
        mVertices << 60 << 65 << 0;
        mVertices << 60 << -20 << 0;
        
        for (int k=0;k<carColors.size();k+=3) {
            mColors << carColors[i]<<carColors[i+1]<<carColors[i+2];
        }
        mColors << 1 << 1 << 1;
        mColors << 1 << 1 << 1;
        mColors << 1 << 1 << 1;
        mColors << 1 << 1 << 1;
        mColors << 1 << 1 << 1;
        mColors << 1 << 1 << 1;
       // bbox_creator();
    }
}
void TrafficJam::bbox_creator() {
    BBOX bb;
    double maX = bb.max_X(mCarContainer[0].getVertices());
    double maY = bb.max_Y(mCarContainer[0].getVertices());
    double maZ = bb.max_Z(mCarContainer[0].getVertices());
    double miX = bb.min_X(mCarContainer[0].getVertices());
    double miY = bb.min_Y(mCarContainer[0].getVertices());
    double miZ = bb.min_Z(mCarContainer[0].getVertices());
    //lower
    mVertices << miX << miY  << miZ ;
    mVertices << maX<< miY  << miZ ;
    mVertices << maX << miY << maZ ;
    mVertices << miX << miY << maZ ;
    mVertices << miX<< miY  << miZ ;
    mVertices << miX << miY << miZ;

    //upper
    mVertices << miX  << maY  << miZ ;
    mVertices << maX << maY  << miZ ;
    mVertices << maX << maY  << maZ ;
    mVertices << miX  << maY  << maZ ;
    mVertices << miX  << maY  << miZ ;

    //Remaining sides
    mVertices << miX << maY  << maZ ;
    mVertices << miX  << miY  << maZ ;
    mVertices << maX << miY  << maZ ;
    mVertices << maX  << maY  << maZ ;
    mVertices << maX  << maY  << miZ ;
    mVertices << maX  << miY  << miZ ;
    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;

    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;

    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;
    mColors << 1.0f << 0.0f << 0.0f;

}
void TrafficJam::isMovable() {
    CollisionDetection collide(mCar_no, mCarContainer);
    mMovable = collide.isMovable();
}
void TrafficJam::isMovableAroundBoundaryY() {
    for (int i = 0; i < mTranslatedPoints.size(); i++) {
        if (( mTranslatedPoints[i].Y() < 59.5)) {
            mSetFlag = true;
        }
        else {
            mSetFlag = false;
        }
    }
}
void TrafficJam::isMovableAroundBoundaryX() {
    for (int i = 0; i < mTranslatedPoints.size(); i++) {
        if( (-45<(mTranslatedPoints[i].X())) && ((mTranslatedPoints[i].X())<42.5)){
            mSetFlag = true;
        }
        else {
            mSetFlag = false;
        }
    }
}