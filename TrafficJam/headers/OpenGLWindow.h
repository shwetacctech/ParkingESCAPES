#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;
class QOpenGLPaintDevice;

class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
public:
    OpenGLWindow(const QColor& background, QMainWindow* parent);
    ~OpenGLWindow();

    void setVectorOfLines(QVector<GLfloat>& vertices);
    void setColorOfLines(QVector<GLfloat>& colors);
    void updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors);
    
protected:
    void paintGL() override;
    void initializeGL() override;

private slots:
    void shaderWatcher();
 
private:
    void reset();
    void mouseMoveEvent(QMouseEvent* event);
    void zoomIn();
    void zoomOut();
    void wheelEvent(QWheelEvent* event);
    QString readShader(QString filepath);
    
private:
    bool mAnimating = false;
    int mFlag = 0;
    QOpenGLContext* mContext = nullptr;
    QOpenGLPaintDevice* mDevice = nullptr;

    QOpenGLShader* mVshader = nullptr;
    QOpenGLShader* mFshader = nullptr;
    QOpenGLShaderProgram* mProgram = nullptr;

    QList<QVector3D> mVertices;
    QList<QVector3D> mNormals;
    QOpenGLBuffer mVbo;
    int mVertexAttr;
    int mNormalAttr;
    int mMatrixUniform;
    QColor mBackground;
    QMetaObject::Connection mContextWatchConnection;


    QVector<GLfloat> mVertice;
    QVector<GLfloat> mColor;

    GLint mPosAttr = 0;
    GLint mColAttr = 0;
    GLint mPosAttr1 = 0;
    GLint mColAttr1 = 0;
    GLint mMatrixUniform_ = 0;

    QQuaternion mRotationAngle;
    QPoint mLastPos;
    float mScaleFactor=5;
    QFileSystemWatcher* mShaderWatcher;
    QPoint mMousePos;
    
};


